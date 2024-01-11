#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H

#include "atUtility.h"
#include "Array.h"

/**
 * @brief Serach in an array for a specific value and return the index
 * ! If the value is not found, the function returns 0
 * 
 * @tparam size 
 * @tparam value 
 * @param a Array with any datatype
 * @param v Value to search for
 * @return int 
 */
template <size_t size, typename value>
auto indexOf(Array<value, size> &a, value v) -> int
{
    for (auto i = 0; i < size; i++)
    {
        if (a.at(i) == v)
            return i;
    }
    return 0; // -1 is not working for all datatypes (e.g. bool)
}

#endif // ARRAYUTILS_H