#include "singly_linked_list.h"

namespace sll
{
    SinglyLinkedList *make()
    {
        SinglyLinkedList *l = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
        l->head = NULL;
        l->tail = NULL;
        l->size = 0;

        return l;
    }

    SinglyLinkedList *clone(SinglyLinkedList *l)
    {
        SinglyLinkedList *clone = make();
        SinglyLinkedListNode *cursor = l->head;

        while (cursor != NULL)
        {
            addTail(clone, cursor->data);
            cursor = cursor->next;
        }

        return clone;
    }

    int len(SinglyLinkedList *l)
    {
        return l->size;
    }

    bool empty(SinglyLinkedList *l)
    {
        return len(l) == 0 &&
               l->head == NULL &&
               l->tail == NULL;
    }

    int get(SinglyLinkedList *l, int index)
    {
        if (index < 0 || index > (len(l) - 1))
            throw std::invalid_argument("index is out of range");

        if (index == 0)
            return l->head->data;
        if (index == (len(l) - 1))
            return l->tail->data;

        SinglyLinkedListNode *cursor = l->head;
        int indexCursor = 0;
        while (indexCursor < index)
        {
            cursor = cursor->next;
            indexCursor++;
        }

        return cursor->data;
    }

    int addHead(SinglyLinkedList *l, int data)
    {
        SinglyLinkedListNode *node = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
        node->data = data;
        if (empty(l))
        {
            l->head = node;
            l->tail = node;
        }
        else
        {
            node->next = l->head;
            l->head = node;
        }

        l->size++;
        return len(l);
    }

    int addTail(SinglyLinkedList *l, int data)
    {
        SinglyLinkedListNode *node = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
        node->data = data;
        if (empty(l))
        {
            l->head = node;
            l->tail = node;
        }
        else
        {
            l->tail->next = node;
            l->tail = node;
        }

        l->size++;
        return len(l);
    }

    int delHead(SinglyLinkedList *l)
    {
        int data;
        if (delete_when_only_one_element(l, &data))
        {
            return data;
        }

        data = l->head->data;
        SinglyLinkedListNode *candidate = l->head;
        l->head = candidate->next;
        candidate->next = NULL;
        free(candidate);

        l->size--;
        return data;
    }

    int delTail(SinglyLinkedList *l)
    {

        int data;
        if (delete_when_only_one_element(l, &data))
        {
            return data;
        }

        data = l->tail->data;
        SinglyLinkedListNode *cursor = l->head;
        SinglyLinkedListNode *prevCursor = NULL;
        while (cursor->next != NULL)
        {
            prevCursor = cursor;
            cursor = cursor->next;
        }

        l->tail = prevCursor;
        prevCursor->next = NULL;
        free(cursor);

        l->size--;
        return data;
    }

    bool delete_when_only_one_element(SinglyLinkedList *l, int *data)
    {
        if (empty(l))
            throw std::runtime_error("list is empty");

        if (len(l) != 1)
            return false;

        *data = l->head->data;
        SinglyLinkedListNode *candidate = l->head;
        l->head = NULL;
        l->tail = NULL;
        l->size = 0;
        free(candidate);
        return true;
    }

    std::string str(SinglyLinkedList *l)
    {
        std::string s = "[";

        SinglyLinkedListNode *cursor = l->head;
        while (cursor != NULL)
        {
            int data = cursor->data;
            s += std::to_string(data);
            if (cursor->next != NULL)
                s += " ";

            cursor = cursor->next;
        }

        s += "]";
        return s;
    }
}
