#ifndef _queue_h
#define _queue_h

#include<lcthw/list.h>

#define Queue List
#define Queue_create() List_create()
#define Queue_destroy(A) List_destroy((A))
#define Queue_send(A, B) List_unshift((A), (B))
#define Queue_recv(A) List_pop((A))
#define Queue_count(A) List_count((A))
#define QUEUE_FOREACH(A, B) LIST_FOREACH(A, first, next, B)
#define Queue_peek(A) ((A) -> last -> value)
#endif
