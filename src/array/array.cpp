#include "array.h"

namespace arrays
{
    Array *make(int length)
    {
        Array *arr = (Array *)malloc(sizeof(Array));
        int *started_addr = (int *)malloc(sizeof(int) * length);

        arr->length = length;
        arr->started_addr = started_addr;

        fill(arr, 0);
        return arr;
    }

    bool is_index_out_of_range(Array *arr, int index)
    {
        return (*(arr->started_addr) + index) >= (*(arr->started_addr) + arr->length);
    }

    int set(Array *arr, int index, int value)
    {
        if (is_index_out_of_range(arr, index))
            throw std::invalid_argument("index out of range");

        *(arr->started_addr + index) = value;
        return index;
    }

    int get(Array *arr, int index)
    {
        if (is_index_out_of_range(arr, index))
            throw std::invalid_argument("index out of range");
        return *(arr->started_addr + index);
    }

    void del(Array *arr)
    {
        std::free(arr->started_addr);
        std::free(arr);
    }

    int len(Array *arr) { return arr->length; }

    void fill(Array *arr, int value)
    {
        for (int index = 0; index < len(arr); index++)
        {
            set(arr, index, value);
        }
    }

    std::string str(Array *arr)
    {
        std::string s = "[";

        int last_index = len(arr) - 1;
        for (int index = 0; index < last_index; index++)
        {
            int value = get(arr, index);
            s += std::to_string(value) + " ";
        }

        if (last_index > 0)
        {
            int value = get(arr, last_index);
            s += std::to_string(value);
        }

        s += "]";
        return s;
    }
}