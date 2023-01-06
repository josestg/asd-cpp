#include "dynamicarray.h"
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <string>

namespace dynamic_array
{
    DynamicArray *make(int initial_capacity)
    {
        if (initial_capacity < 1)
        {
            initial_capacity = 1;
        }

        auto *darr = (DynamicArray *)malloc(sizeof(DynamicArray));
        auto *started_addr = (int *)malloc(sizeof(int) * initial_capacity);

        darr->length = 0;
        darr->started_addr = started_addr;
        darr->max_capacity = initial_capacity;

        return darr;
    };

    void del(DynamicArray *darr)
    {
        std::free(darr->started_addr);
        std::free(darr);
    }

    bool is_index_out_of_range(DynamicArray *darr, int index)
    {
        return (*(darr->started_addr) + index) >= (*(darr->started_addr) + darr->length);
    }

    int get(DynamicArray *darr, int index)
    {
        if (is_index_out_of_range(darr, index))
            throw std::invalid_argument("index out of range");
        return *(darr->started_addr + index);
    }

    void add(DynamicArray *darr, int value)
    {
        if ((darr->length + 1) > darr->max_capacity)
        {
            // we don't have enough space, let's grow.
            DynamicArray *bigger_darr = make(2 * darr->max_capacity);
            memcpy(bigger_darr->started_addr, darr->started_addr, darr->length * sizeof(int));
            free(darr->started_addr);

            darr->started_addr = bigger_darr->started_addr;
            darr->max_capacity = bigger_darr->max_capacity;
        }

        *(darr->started_addr + darr->length) = value;
        darr->length++;
    }

    int len(DynamicArray *darr) { return darr->length; }

    int cap(DynamicArray *darr) { return darr->max_capacity; }

    std::string str(DynamicArray *darr)
    {
        std::string s = "[";

        int last_index = len(darr) - 1;
        for (int index = 0; index < last_index; index++)
        {
            int value = get(darr, index);
            s += std::to_string(value);
            s += " ";
        }

        if (last_index > 0)
        {
            int value = get(darr, last_index);
            s += std::to_string(value);
        }

        s += "]";
        return s;
    }
}
