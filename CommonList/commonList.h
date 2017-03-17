#ifndef __COMMON_LIST__
#define __COMMON_LIST__

#define IF_INVALID_RETURN_NOVALUE(cond) if (cond) { return; }
#define IF_INVALID_RETURN_CODE(cond, code) if (cond) { return code; }

typedef enum {
    EN_RETURN_SUCC = 0,
    EN_RETURN_LIST_EMPTY
} EN_RETURN_CODE;

typedef struct ListHead {
    struct ListHead* prev;
    struct ListHead* next;
} TListHead;

#define OFF_SET_OF(type, member)        ((char*)&(((type*)0)->member))
#define CONTAINER_OF(ptr, type, member) (type*)((char*)ptr - OFF_SET_OF(type, member))
#define ListGetEntry(ptr, type, member) CONTAINER_OF(ptr, type, member)

#define InitListHead(ptr) do { \
    TListHead* list = (TListHead*)ptr;  \
    list->prev = list;  \
    list->next = list;  \
} while (false)

int ListEmpty(TListHead* ptr) {
    return ptr->next == ptr;
}

void ListAdd(TListHead* ptNew, TListHead* pPrev, TListHead* pNext) {
    pNext->prev = ptNew;
    ptNew->next = pNext;
    ptNew->prev = pPrev;
    pPrev->next = ptNew;
}

void ListAddTail(TListHead* head, TListHead* ptNew) {
   ListAdd(ptNew, head->prev, head);
}

void ListAddHead(TListHead* head, TListHead* ptNew) {
   ListAdd(ptNew, head, head->next);
}

EN_RETURN_CODE ListDel(TListHead* pNode) {
    if (ListEmpty(pNode)) {
        return EN_RETURN_LIST_EMPTY;
    }

    pNode->prev->next = pNode->next;
    pNode->next->prev = pNode->prev;
    delete pNode;
    return EN_RETURN_SUCC;
}

#endif
