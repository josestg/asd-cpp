#ifndef ASD_CPP_ARRAY_H
#define ASD_CPP_ARRAY_H
#include <string>

/**
 * Array is a contiguous block of memory. This means that to implement an
 * array, we just need to know the location of the first address in memory,
 * and then we can use pointer arithmetic and the index to access the next
 * item in the array. However, this also means that we can access any
 * address, which is dangerous! To solve this, we need a `length` to limit
 * how far we can go to the next item in a contiguous block of memory.
 */
typedef struct
{
    /**
     * Holds the first address, or in terms of the array, this will be the
     * first index (index-0).
     */
    int *started_addr;

    /** The length of the array. */
    int length;
} Array;

namespace arrays
{
    /**
     * Creates a new Array header. The Array header is just information about
     * the array, and no items are stored in the array itself.
     *
     * @param length The length of the array to create.
     * @return A pointer to the new Array header.
     */
    Array *make(int length);

    /**
     * Returns the length of the given array.
     *
     * @param arr The array to get the length of.
     * @return The length of the array.
     */
    int len(Array *arr);

    /**
     * Sets a given value at a given index in the array. If the index is out
     * of range, an error will be thrown.
     *
     * @param arr The array to set the value in.
     * @param index The index to set the value at.
     * @param value The value to set at the given index.
     * @return The value that was set at the given index.
     */
    int set(Array *arr, int index, int value);

    /**
     * Gets a stored value at a given index in the array. If the index is out
     * of range, an error will be thrown.
     *
     * @param arr The array to get the value from.
     * @param index The index to get the value from.
     * @return The value at the given index.
     */
    int get(Array *arr, int index);

    /**
     * Fills all slots in the array with the same value.
     *
     * @param arr The array to fill with the given value.
     * @param value The value to fill the array with.
     */
    void fill(Array *arr, int value);

    /**
     * Deallocates the array.
     *
     * @param arr The array to deallocate.
     */
    void del(Array *arr);

    /**
     * Checks if the given index is still within the range of the array.
     *
     * @param arr The array to check the index for.
     * @param index The index to check.
     * @return True if the index is out of range, false otherwise.
     */
    bool is_index_out_of_range(Array *arr, int index);

    /**
     * Returns the string representation of the array.
     *
     * @param arr The array to get the string representation of.
     * @return The string representation of the array.
     */
    std::string str(Array *arr);
}

#endif // ASD_CPP_ARRAY_H