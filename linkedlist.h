#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/// @brief a simple struct which consists pointers to the next and previous node and pointer to the data
typedef struct _node
{
    struct _node *prev;
    struct _node *next;

    void *data;
} LinkedList_t;

/// @brief Creates and allocates memory for a single list node
/// @return a pointer to the created node
LinkedList_t *LinkedList_make(void);

/// @brief finds the first element in the list
/// @param list a node of the list
/// @return a pointer to the found node
LinkedList_t *LinkedList_first(LinkedList_t *list);

/// @brief finds the last element in the list
/// @param list a node of the list
/// @return a pointer to the found node
LinkedList_t *LinkedList_last(LinkedList_t *list);

/// @brief checks if the list is cyclic
/// @param list a node of the list
/// @return 0, if isn't cyclic. 1, if is cyclic
int LinkedList_isCyclic(LinkedList_t *const list);

/// @brief counts the size of list
/// @param list a node of the list
/// @return the size of the list or -1 if the list is cyclic
int LinkedList_size(LinkedList_t *list);

/// @brief searches for a node relative to the "list" parameter, which is "index" in order
/// @param list a node of the list
/// @param index an order number
/// @return a pointer to the found node
LinkedList_t *LinkedList_findRelative(LinkedList_t *list, const int index);

/// @brief searches for the node relative to the beginning of the list that is in the order "pos"
/// @param list a node of the list
/// @param index an order number
/// @return a pointer to the found node
LinkedList_t *LinkedList_findAbsolute(LinkedList_t *list, const int index);

/// @brief searches for a node relative to the "list" parameter that is in the order "index"
/// @param list a node of the list
/// @param index an order number
/// @return a pointer to the inserted node
LinkedList_t *LinkedList_insertRelative(LinkedList_t *list, const int index);

/// @brief inserts a node relative to the beginning of the list that is in the order "index"
/// @param list a node of the list
/// @param index an order number
/// @return a pointer to the inserted node
LinkedList_t *LinkedList_insertAbsolute(LinkedList_t *list, const int index);

/// @brief inserts a node at the end of the list
/// @param list a node of the list
/// @return a pointer to the inserted node
LinkedList_t *LinkedList_pushBack(LinkedList_t *list);

/// @brief inserts a node at the beginning of the list
/// @param list a node of the list
/// @return a pointer to the inserted node
LinkedList_t *LinkedList_pushFront(LinkedList_t *list);

/// @brief erases the node relative to the "list" parameter that is in "index" order
/// @param list a node of the list
/// @param index an order number
/// @return 0, if success. 1, if didn't find the element by index
int LinkedList_eraseRelative(LinkedList_t *list, const int index);

/// @brief erases the node relative to the beginning of the list that is in the order "index"
/// @param list a node of the list
/// @param index an order number
/// @return 0, if success. 1, if didn't find the element by index
int LinkedList_eraseAbsolute(LinkedList_t *list, const int index);

/// @brief erases all nodes in the list
/// @param list a node of the list
void LinkedList_eraseAll(LinkedList_t *list);

#endif // LINKED_LIST_H