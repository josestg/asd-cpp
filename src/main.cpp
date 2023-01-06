#include "array/array.h"
#include <iostream>

int main()
{
    Array *arr = arrays::make(5);

    arrays::set(arr, 0, 1);
    arrays::set(arr, 1, 3);
    arrays::set(arr, 2, 4);
    arrays::set(arr, 3, 4);

    std::cout << arrays::str(arr) << std::endl;
    arrays::del(arr);

    return 0;
}