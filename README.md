# Doubly Linked List
### Functions are supported:

Creating a node:
```
LinkedList_t* LinkedList_make(void);
```
Searching:
```
LinkedList_t* LinkedList_first(const LinkedList_t *list);
LinkedList_t* LinkedList_last(const LinkedList_t *list);

LinkedList_t* LinkedList_findRelative(const LinkedList_t* list, const int index);
LinkedList_t* LinkedList_findAbsolute(const LinkedList_t* list, const int index);
```
Inserting:
```
LinkedList_t* LinkedList_insertRelative(LinkedList_t* list, const int index);
LinkedList_t* LinkedList_insertAbsolute(LinkedList_t* list, const int index);
LinkedList_t* LinkedList_pushBack(LinkedList_t* list);
LinkedList_t* LinkedList_pushFront(LinkedList_t* list);
```
Erasing:
```
int LinkedList_eraseRelative(LinkedList_t* list, const int index);
int LinkedList_eraseAbsolute(LinkedList_t* list, const int index);
void LinkedList_eraseAll(LinkedList_t* list);
```
Utils:
```
LinkedList_isCyclic(const LinkedList_t * const list);
LinkedList_size(const LinkedList_t* list);
```

## License
The Unlicense
