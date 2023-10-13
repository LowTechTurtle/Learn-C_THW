#ifndef _list_h
#define _list_h

#include<lcthw/list.h>

#define Stack List
#define Stack_create() List_create()
#define Stack_destroy(A) List_destroy((A))
#define Stack_push(A, B) List_push((A), (B))
#define Stack_peek(A) ((A) -> last -> value)
#define Stack_count(A) List_count((A))
#define STACK_FOREACH(A, B) LIST_FOREACH((A), last, prev, (B))
#define Stack_pop(A) List_pop((A))

#endif
