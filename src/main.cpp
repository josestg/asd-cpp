#include "list/singly_linked_list.h"

#include <iostream>

int main()
{
    SinglyLinkedList *l = sll::make();

    std::cout << "empty: " << sll::empty(l) << std::endl;
    std::cout << "len  : " << sll::len(l) << std::endl;
    std::cout << "str  : " << sll::str(l) << std::endl;

    for (int i = 5; i > 0; i--)
        sll::addTail(l, i);

    std::cout << "-- After addTail --" << std::endl;
    std::cout << "empty: " << sll::empty(l) << std::endl;
    std::cout << "len  : " << sll::len(l) << std::endl;
    std::cout << "str  : " << sll::str(l) << std::endl;

    for (int i = 6; i <= 10; i++)
        sll::addHead(l, i);

    std::cout << "-- After addHead --" << std::endl;
    std::cout << "empty: " << sll::empty(l) << std::endl;
    std::cout << "len  : " << sll::len(l) << std::endl;
    std::cout << "str  : " << sll::str(l) << std::endl;

    for (int i = 0; i < sll::len(l); i++)
    {
        std::cout << "data at index: " << i << " is: " << sll::get(l, i) << std::endl;
    }

    SinglyLinkedList *clone1 = sll::clone(l);
    SinglyLinkedList *clone2 = sll::clone(l);
    SinglyLinkedList *clone3 = sll::clone(l);

    std::cout << "-- Clone 1 --" << std::endl;
    std::cout << "empty: " << sll::empty(clone1) << std::endl;
    std::cout << "len  : " << sll::len(clone1) << std::endl;
    std::cout << "str  : " << sll::str(clone1) << std::endl;

    std::cout << "-- Clone 2 --" << std::endl;
    std::cout << "empty: " << sll::empty(clone2) << std::endl;
    std::cout << "len  : " << sll::len(clone2) << std::endl;
    std::cout << "str  : " << sll::str(clone2) << std::endl;

    std::cout << "-- Clone 3 --" << std::endl;
    std::cout << "empty: " << sll::empty(clone3) << std::endl;
    std::cout << "len  : " << sll::len(clone3) << std::endl;
    std::cout << "str  : " << sll::str(clone3) << std::endl;

    while (!sll::empty(clone1))
    {
        std::cout << "Clone 1 -- delHead: " << sll::delHead(clone1) << std::endl;
    }

    std::cout << "-- Clone 1 After delHead --" << std::endl;
    std::cout << "empty: " << sll::empty(clone1) << std::endl;
    std::cout << "len  : " << sll::len(clone1) << std::endl;
    std::cout << "str  : " << sll::str(clone1) << std::endl;

    while (!sll::empty(clone2))
    {
        std::cout << "Clone 2 -- delTail: " << sll::delTail(clone2) << std::endl;
    }

    std::cout << "-- Clone 2 After delTail --" << std::endl;
    std::cout << "empty: " << sll::empty(clone2) << std::endl;
    std::cout << "len  : " << sll::len(clone2) << std::endl;
    std::cout << "str  : " << sll::str(clone2) << std::endl;

    while (!sll::empty(clone3))
    {
        if (sll::len(clone3) % 2 == 0)
        {
            std::cout << "Clone 3 -- delTail: " << sll::delTail(clone3) << std::endl;
        }
        else
        {
            std::cout << "Clone 3 -- delHead: " << sll::delHead(clone3) << std::endl;
        }
    }

    std::cout << "-- Clone 3 After delTail when length is even and detHead when length is odd --" << std::endl;
    std::cout << "empty: " << sll::empty(clone3) << std::endl;
    std::cout << "len  : " << sll::len(clone3) << std::endl;
    std::cout << "str  : " << sll::str(clone3) << std::endl;

    return 0;
}