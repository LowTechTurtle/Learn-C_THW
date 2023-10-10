#include<lcthw/dbg.h>
#include<lcthw/list_algos.h>
#include<lcthw/list.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef int (*List_compare)(char* word1, char* word2);

int len(List *words) 
{
	ListNode *node = words -> first;
	int i = 0;
	while (node != NULL){
		node = node -> next;
		i += 1;
	}
	return i;
}
int List_bubble_sort(List *words, List_compare comp)
{
	char *tem;
	if (words -> first == NULL && words -> last == NULL) {
		return 0;
	} else if (words -> first == words -> last) {
		return 0;
	} else if ( words -> first != NULL && words -> last != NULL && words -> first != words -> last) {
		int i;
		ListNode *node;
		int count = 0;
		for (i = 1, node = words -> first; node -> next!= NULL; node = node -> next, i++) {
			if (comp(node -> value, node -> next -> value) < 0) {
				tem = node -> value;
				node -> value = node -> next -> value;
				node -> next -> value = tem;
				count = 1;
			}
		}
		if (count == 0) {
			return 0;
		}
		int j;
		count = 0;
		while (1) {
			i = i -1;
			for (j = 0, node = words -> first; j < i; j++, node = node -> next) {
				if (comp(node -> value, node -> next -> value) < 0) {
					tem = node -> value;
					node -> value = node -> next -> value;
					node -> next -> value = tem;
					count = 1;
				}
			}
				if (count == 0) {
					return 0;
				}
				count = 0;
		}
	} else {
		sentinel("Invalid structure of double linked list");
	}
	ListNode *node;
	for (node = words -> first; node != NULL; node = node -> next){
		printf("%s\n", (char*)node -> value);
	}
	return 0;
error:
	return -1;
}
List *dupe(List *words, char* option) 
{
	if (strcmp(option, "full") == 0) {
		List *dupe = List_create();
		ListNode *node;
		for(node = words -> first; node != NULL; node = node -> next) {
			char tem[50];
			strcpy(tem, (char *)node ->value);
			List_push(dupe, tem);
			}
		return dupe;
	} else if (strcmp(option, "head") == 0) {
		List *dupe = List_create();
		ListNode *node = words -> first;
		int i;
		int length = len(words);
		for (i = 0; i < length/2; i++) {
			char tem[50];
			strcpy(tem, (char* )node->value);
			List_push(dupe, tem);
			node = node -> next;
		} 
		return dupe;
	} else if (strcmp(option, "tail") == 0) {
		int i;
		int length = len(words);
		List *dupe = List_create();
		ListNode *node = words -> first;
		for (i = 0; i < length/2; i++) {
			node = node -> next;
		} 
		for (i = length/2; i < length; i++) {
			char tem[50];
			strcpy(tem, (char* )node->value);
			List_push(dupe, tem);
			node = node -> next;
		}
		return dupe;
	} else {
		sentinel("error in strcpy");
	}
	return NULL;
error:
	return NULL;
}
List *merge(List* left, List* right);
List *List_merge_sort(List *words, List_compare comp) 
{
	if (words -> first == NULL && words -> last == NULL) {
		return NULL;
	} else if (words -> first == words -> last) {
		return words;
	} else if ( words -> first != NULL && words -> last != NULL && words -> first != words -> last) {
		List *left = dupe(words, "head");
		List *right = dupe(words, "tail");
		List *sort_left = List_merge_sort(left, comp);
		List *sort_right = List_merge_sort(right, comp);
		if (len(sort_left) >= 2) {
			List_destroy(sort_left);
		}
		if (len(sort_right) >=2) {
			List_destroy(sort_right);
		}
		return merge(left, right);
	}
	return NULL;
}

List *merge(List* left, List* right)
{
	List *result = List_create();
	if (left -> first == NULL) {
		ListNode *node;
		for (node = right -> first; node != NULL; node = node -> next) {
			char tem[50];
			strcpy(tem, (char *)node -> value);
			List_push(result, tem);
		}
		if (left != NULL) {
			List_destroy(left);
		}
		if (right != NULL) {
			List_destroy(right);
		}
		return result;
	} else if (right -> first == NULL) {
		ListNode *node;
		for (node = left -> first; node != NULL; node = node -> next) {
			char tem[50];
			strcpy(tem, (char *)node -> value);
			List_push(result, tem);
		}
		if (left != NULL) {
			List_destroy(left);
		}
		if (right != NULL) {
			List_destroy(right);
		}
		return result;
	} else {
		ListNode *nodel;
		ListNode *noder;
		nodel = left -> first;
		noder = right -> first;
		while (nodel != NULL && noder != NULL) {
			if (strcmp((char *)nodel -> value, (char *)noder -> value) < 0) {
				char tem[50];
				strcpy(tem, (char*)nodel -> value);
				List_push(result, tem);
				nodel = nodel -> next;
			} else {
				char tem[50];
				strcpy(tem, (char*)noder -> value);
				List_push(result, tem);
				noder = noder -> next;
			}
		}
		if (nodel == NULL) {
			ListNode *node;
			for (node = right -> first; node != NULL; node = node -> next) {
				char tem[50];
				strcpy(tem, (char *)node -> value);
				List_push(result, tem);
			}
			if (left != NULL) {
				List_destroy(left);
			}
			if (right != NULL) {
				List_destroy(right);
			}
			return result;
		} else if (noder == NULL) {
			ListNode *node;
			for (node = left -> first; node != NULL; node = node -> next) {
				char tem[50];
				strcpy(tem, (char *)node -> value);
				List_push(result, tem);
			}
			if (left != NULL) {
				List_destroy(left);
			}
			if (right != NULL) {
				List_destroy(right);
			}
			return result;
		}

	}
	return NULL;
}
