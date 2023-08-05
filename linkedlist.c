#include "linkedlist.h"
#include <malloc.h>
#include <string.h>

static void LinkedList_connectTwoNodes(LinkedList_t *const first, LinkedList_t *const second)
{
    if (first)
        first->next = second;
    if (second)
        second->prev = first;
}

LinkedList_t *LinkedList_make(void)
{
    LinkedList_t *ptr = (LinkedList_t *)calloc(1, sizeof(LinkedList_t));
    return ptr;
}

LinkedList_t *LinkedList_last(LinkedList_t *list)
{
    if (list == NULL)
        return NULL;

    while (list->next)
        list = list->next;

    return list;
}

LinkedList_t *LinkedList_first(LinkedList_t *list)
{
    if (list == NULL)
        return NULL;

    while (list->prev)
        list = list->prev;

    return list;
}

int LinkedList_isCyclic(LinkedList_t *const list)
{
    LinkedList_t *current_node = list;
    if (current_node == NULL)
        return 0;

    while (current_node->next)
    {
        current_node = current_node->next;

        if (current_node == list)
            return 1;
    }

    return 0;
}

LinkedList_t *LinkedList_findRelative(LinkedList_t *list, const int index)
{
    if (index < 0)
        return NULL;

    if (list == NULL)
        return NULL;

    for (int i = 0; i < index; ++i)
    {
        if (list->next == NULL)
            return NULL;

        list = list->next;
    }

    return list;
}

LinkedList_t *LinkedList_findAbsolute(LinkedList_t *list, const int index)
{
    if (index < 0)
        return NULL;

    if (LinkedList_isCyclic(list))
        return NULL;

    list = LinkedList_first(list);
    return LinkedList_findRelative(list, index);
}

LinkedList_t *LinkedList_insertRelative(LinkedList_t *list, const int index)
{
    if (index < 0)
        return NULL;

    LinkedList_t *new_node = LinkedList_make();
    if (new_node == NULL)
        return NULL;

    LinkedList_t *next_node = LinkedList_findRelative(list, index);
    if (next_node == NULL)
    {
        free(new_node);
        return NULL;
    }

    LinkedList_t *prev_node = next_node->prev;

    LinkedList_connectTwoNodes(prev_node, new_node);
    LinkedList_connectTwoNodes(new_node, next_node);

    return new_node;
}

LinkedList_t *LinkedList_insertAbsolute(LinkedList_t *list, const int index)
{
    if (index < 0)
        return NULL;

    if (LinkedList_isCyclic(list))
        return NULL;

    list = LinkedList_first(list);
    return LinkedList_insertRelative(list, index);
}

int LinkedList_size(LinkedList_t *list)
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

LinkedList_t *LinkedList_pushBack(LinkedList_t *list)
{
    LinkedList_t *new_node = LinkedList_make();
    if (new_node == NULL)
        return NULL;

    list = LinkedList_last(list);
    if (list)
        LinkedList_connectTwoNodes(list, new_node);

    return new_node;
}

LinkedList_t *LinkedList_pushFront(LinkedList_t *list)
{
    LinkedList_t *new_node = LinkedList_make();
    if (new_node == NULL)
        return NULL;

    list = LinkedList_first(list);
    if (list)
        LinkedList_connectTwoNodes(new_node, list);

    return new_node;
}

int LinkedList_eraseRelative(LinkedList_t *list, const int index)
{
    list = LinkedList_findRelative(list, index);
    if (list == NULL)
        return 1;

    LinkedList_t *prev_node = list->prev;
    LinkedList_t *next_node = list->next;

    LinkedList_connectTwoNodes(prev_node, next_node);

    free(list);
    return 0;
}

int LinkedList_eraseAbsolute(LinkedList_t *list, const int index)
{
    list = LinkedList_first(list);
    return LinkedList_eraseRelative(list, index);
}

void LinkedList_eraseAll(LinkedList_t *list)
{
    list = LinkedList_first(list);
    while (list)
    {
        LinkedList_t *erase_node = list;
        list = list->next;
        free(erase_node);
    }
}
