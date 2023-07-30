#include "linkedlist.h"
#include <malloc.h>
#include <string.h>

LinkedList_t* LinkedList_make(void)
{
	LinkedList_t* ptr = (LinkedList_t*)calloc(1, sizeof(LinkedList_t));
	return ptr;
}

LinkedList_t* LinkedList_last(const LinkedList_t *list)
{
    while (list->next)
        list = list->next;

    return list;
}

LinkedList_t* LinkedList_first(const LinkedList_t *list)
{
    while (list->prev)
        list = list->prev;

    return list;
}

int LinkedList_isCyclic(const LinkedList_t * const list)
{
    LinkedList_t* current_node = list;
    while (current_node->next)
    {
        current_node = current_node->next;

        if (current_node == list)
            return 1;
    }

    return 0;
}

LinkedList_t* LinkedList_findRelative(const LinkedList_t* list, const int index)
{
    if (index < 0)
        return NULL;

    for (unsigned int i = 0; i < index; ++i)
    {
        if (list->next == NULL)
            return NULL;

        list = list->next;
    }

    return list;
}

LinkedList_t* LinkedList_findAbsolute(const LinkedList_t* list, const int index)
{
    if (index < 0)
        return NULL;

    if (LinkedList_isCyclic(list))
        return NULL;
    
    list = LinkedList_first(list);
    return LinkedList_findRelative(list, index);
}

LinkedList_t* LinkedList_insertRelative(LinkedList_t* list, const int index)
{
    if (index < 0)
        return NULL;

    LinkedList_t* new_node = LinkedList_make();
    if (new_node == NULL)
        return NULL;

    LinkedList_t* target_node = LinkedList_findRelative(list, index);
    if (target_node == NULL)
        return NULL;

    LinkedList_t* prev_node = target_node->prev;
    if (prev_node)
    {
        new_node->prev = prev_node;
        prev_node->next = new_node;
    }

    new_node->next = target_node;
    target_node->prev = new_node;

    return new_node;
}

LinkedList_t* LinkedList_insertAbsolute(LinkedList_t* list, const int index)
{
    if (index < 0)
        return NULL;

    if (LinkedList_isCyclic(list))
        return NULL;

    list = LinkedList_first(list);
    return LinkedList_insertRelative(list, index);
}

int LinkedList_size(const LinkedList_t* list)
{
    if (LinkedList_isCyclic(list))
        return -1;
    
    list = LinkedList_first(list);
    int count = 0;
    while (list)
    {
        ++count;
        list = list->next;
    }

    return count;
}

LinkedList_t* LinkedList_pushBack(LinkedList_t* list)
{
    LinkedList_t* new_node = LinkedList_make();
    if (new_node == NULL)
        return NULL;

    list = LinkedList_last(list);
    if (list == NULL)
        return NULL;

    list->next = new_node;
    new_node->prev = list;

    return new_node;
}

LinkedList_t* LinkedList_pushFront(LinkedList_t* list)
{
    LinkedList_t* new_node = LinkedList_make();
    if (new_node == NULL)
        return NULL;

    list = LinkedList_first(list);
    if (list == NULL)
        return NULL;

    new_node->next = list;
    list->prev = new_node;

    return new_node;
}

int LinkedList_eraseRelative(LinkedList_t* list, const int index)
{
    list = LinkedList_findRelative(list, index);
    if (list == NULL)
        return 1;

    LinkedList_t* prev_node = list->prev;
    LinkedList_t* next_node = list->next;

    if (prev_node)
        prev_node->next = next_node;

    if (next_node)
        next_node->prev = prev_node;

    free(list);
    return 0;
}

int LinkedList_eraseAbsolute(LinkedList_t* list, const int index)
{
    list = LinkedList_first(list);
    return LinkedList_eraseRelative(list, index);
}

void LinkedList_eraseAll(LinkedList_t* list)
{
    list = LinkedList_first(list);
    while (list)
    {
        list = list->next;
        free(list->prev);
    }
}
