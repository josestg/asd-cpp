#include "array/dynamicarray.h"

#include <iostream>

int main()
{
    DynamicArray *darr = dynamic_array::make(1);

    dynamic_array::add(darr, 1);
    dynamic_array::add(darr, 1);
    dynamic_array::add(darr, 2);
    dynamic_array::add(darr, 3);
    dynamic_array::add(darr, 4);

    std::cout << dynamic_array::len(darr) << std::endl;
    std::cout << dynamic_array::cap(darr) << std::endl;
    std::cout << dynamic_array::str(darr) << std::endl;

    return 0;
}