#ifndef _list_algos_h
#define _list_algos_h

#include<lcthw/list.h>

typedef int (*List_compare)(char* word1, char* word2);

int List_bubble_sort(List* words, List_compare comp);

List *merge(List* left, List* right);
List *List_merge_sort(List *words, List_compare comp);
#endif
