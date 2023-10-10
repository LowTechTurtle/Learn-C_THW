#include<lcthw/list.h>
#include<lcthw/dbg.h>

List *List_create()
{
	List *ptr = calloc(1, sizeof(List));
	check_mem(ptr);
	return ptr;
error:
	return NULL;
}

void List_destroy(List *list)
{
	check(list != NULL, "A NULL pointer was given to List_destroy");
	LIST_FOREACH(list, first, next, cur){
		if (cur -> prev) {
			free(cur -> prev);
		}
	}
	free(list -> last);
	free(list);
error:
	return;
}

void List_clear(List *list)
{
	check(list != NULL, "A NULL pointer was given to List_clear");
	LIST_FOREACH(list, first, next, cur) {
		free(cur -> value);
	}
error:
	return;
}

void List_clear_destroy(List *list)
{
//	List_clear(list);
	List_destroy(list);
}

void List_push(List *list, void *value)
{
	check(list != NULL, "A NULL pointer for List* was given to List_push");
	check(value != NULL, "A NULL pointer for value* was given to List_push");
	ListNode *node = calloc(1, sizeof(ListNode));
	check_mem(node);
	node -> value = value;
	
	if (list -> last == NULL) {
		list -> first = node;
		list -> last = node;
	} else {
		list -> last -> next = node;
		node -> prev = list -> last;
		list -> last = node;
	}

	list -> count++;

error:
	return;
}

void *List_pop(List *list)
{
	check(list != NULL, "A NULL pointer was given to List_pop");
	ListNode *node = list -> last;
	return node != NULL ? List_remove(list, node) : NULL;
error:
	return NULL;
}

void List_unshift(List *list, void *value)
{
	check(list != NULL, "A NULL pointer was given to List_unshift");
	ListNode *node = calloc(1, sizeof(ListNode));
	check_mem(node);

	node -> value = value;
	if (list -> first == NULL) {
		list -> first = node;
		list -> last = node;
	} else {
		node -> next = list -> first;
		list -> first -> prev = node;
		list -> first = node;
	}

	list -> count++;
error:
	return;
}

void *List_shift(List *list)
{
	check(list != NULL, "A NULL pointer was given to List_shift");
	ListNode *node = list -> first;
	return node != NULL ? List_remove(list, node) : NULL;
error:
	return NULL;
}

void *List_remove(List *list, ListNode *node)
{
	void *result = NULL;
	check(list != NULL, "A NULL pointer was given to List_remove");
	check(list -> first && list -> last, "List is empty");
	check(node, "node can't be NULL");

	if (node == list -> first && node == list -> last) {
		list -> first = NULL;
		list -> last = NULL;
	} else if (node == list -> first) {
		list -> first = node -> next;
		check(list -> first != NULL, "Invalid list, somehow got a first that is NULL");
		list -> first -> prev = NULL;
	} else if (node == list -> last) {
		list -> last = node -> prev;
		check(list -> last != NULL, "Invalid list, somehow got a last that is NULL");
		list -> last -> next = NULL;
	} else {
		ListNode *after = node -> next;
		ListNode *before = node -> prev;
		after -> prev = before;
		before -> next = after;
	}
	list -> count--;
	result = node -> value;
	free(node);
	
error:
	return result;
}

void List_cat(List *from, List *to)
{
	check(from -> last != NULL && from -> first != NULL, "Empty list");
	if (to -> last == NULL && to -> first == NULL) {
		to = from;
		to -> count = from -> count;
	} else {
		to -> count += from -> count;
		to -> last -> next = from -> first;
		from -> first -> prev = to -> last;
		to -> last = from -> last;
	}
	free(from);
error:
	return;
}
void List_append(List *from, List *to)
{
	ListNode *node = from -> first;
	for (node = from -> first; node != NULL; node = node -> next) {
		ListNode *_node = calloc(1, sizeof(ListNode));
		check_mem(_node);
		to -> last -> next = _node;
		_node -> prev = to -> last;
		to -> last = _node;
		_node -> value = node -> value;
		to -> count += 1;
	}
error:
	return;
}
