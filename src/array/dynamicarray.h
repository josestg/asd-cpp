#ifndef ASD_CPP_DYNAMICARRAY_H
#define ASD_CPP_DYNAMICARRAY_H

#include <string>

// DynamicArray is similar to Array, but the size if dynamic.
/**
 * DynamicArray is similar to Array, but the size is dynamic. The size of
 * DynamicArray can grow as needed.
 *
 * This implementation uses a simple algorithm to grow the size, which is by
 * creating a new array with a size that is twice larger when the array is
 * full.
 */
typedef struct
{
    /** The first address of the array. */
    int *started_addr;

    /** The length of the array. */
    int length;

    /** The maximum capacity of the array. */
    int max_capacity;
} DynamicArray;

namespace dynamic_array
{
    /**
     * Creates a new DynamicArray header. The DynamicArray header is just
     * information about the array, and no items are stored in the array
     * itself.
     *
     * @param initial_capacity The initial capacity of the array.
     * @return A pointer to the new DynamicArray header.
     */
    DynamicArray *make(int initial_capacity);

    /**
     * Deallocates the DynamicArray.
     *
     * @param darr The DynamicArray to deallocate.
     */
    void del(DynamicArray *darr);

    /**
     * Checks if the given index is still within the range of the DynamicArray.
     *
     * @param darr The DynamicArray to check the index for.
     * @param index The index to check.
     * @return True if the index is out of range, false otherwise.
     */
    bool is_index_out_of_range(DynamicArray *darr, int index);

    /**
     * Gets a stored value at a given index in the DynamicArray. If the index
     * is out of range, an error will be thrown.
     *
     * @param darr The DynamicArray to get the value from.
     * @param index The index to get the value from.
     * @return The value at the given index.
     */
    int get(DynamicArray *darr, int index);

    /**
     * Adds a new value into the DynamicArray. If the DynamicArray is full, a
     * new array is created internally with a size that is twice as large, and
     * the value is copied to the new larger array.
     *
     * @param darr The DynamicArray to add the value to.
     * @param value The value to add to the DynamicArray.
     */
    void add(DynamicArray *darr, int value);

    /**
     * Returns the length of the DynamicArray.
     *
     * @param darr The DynamicArray to get the length of.
     * @return The length of the DynamicArray.
     */
    int len(DynamicArray *darr);

    /**
     * Returns the maximum available space to store values in the DynamicArray.
     *
     * @param darr The DynamicArray to get the capacity of.
     * @return The capacity of the DynamicArray.
     */
    int cap(DynamicArray *darr);

    /**
     * Returns the string representation of the DynamicArray.
     *
     * @param darr The DynamicArray to get the string representation of.
     * @return The string representation of the DynamicArray
     */
    std::string str(DynamicArray *darr);
}
#endif // ASD_CPP_DYNAMICARRAY_H
