#ifndef ASD_CPP_SINGLY_LINKED_LIST_H
#define ASD_CPP_SINGLY_LINKED_LIST_H

#include <string>

typedef struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;
} SinglyLinkedListNode;

typedef struct
{
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;
    int size;
} SinglyLinkedList;

namespace sll
{
    SinglyLinkedList *make();
    SinglyLinkedList *clone(SinglyLinkedList *l);
    int addHead(SinglyLinkedList *l, int data);
    int addTail(SinglyLinkedList *l, int data);
    int delHead(SinglyLinkedList *l);
    int delTail(SinglyLinkedList *l);
    int get(SinglyLinkedList *l, int index);
    bool empty(SinglyLinkedList *l);
    int len(SinglyLinkedList *l);
    std::string str(SinglyLinkedList *l);
    bool delete_when_only_one_element(SinglyLinkedList *l, int *data);
}

#endif