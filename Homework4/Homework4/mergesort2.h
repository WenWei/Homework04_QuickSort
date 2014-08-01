#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif


#include "stdafx.h"
#include <math.h>

/*===================================
	MergeSort
====================================*/

/* left is the index of the leftmost element of the subarray; right is one
 * past the index of the rightmost element */
template<typename NumberType, typename ArrType>
void merge_helper(ArrType *input, NumberType left, NumberType right, ArrType *scratch)
{
    /* base case: one element */
    if(right == left + 1)
    {
        return;
    }
    else
    {
        NumberType i = 0;
        NumberType length = right - left;
        NumberType midpoint_distance = length/2;
        /* l and r are to the positions in the left and right subarrays */
        NumberType l = left, r = left + midpoint_distance;

        /* sort each subarray */
        merge_helper(input, left, left + midpoint_distance, scratch);
        merge_helper(input, left + midpoint_distance, right, scratch);

        /* merge the arrays together using scratch for temporary storage */ 
        for(i = 0; i < length; i++)
        {
            /* Check to see if any elements remain in the left array; if so,
             * we check if there are any elements left in the right array; if
             * so, we compare them.  Otherwise, we know that the merge must
             * use take the element from the left array */
            if(l < left + midpoint_distance && 
                    (r == right || min(input[l], input[r]) == input[l]))
            {
                scratch[i] = input[l];
                l++;
            }
            else
            {
                scratch[i] = input[r];
                r++;
            }
        }
        /* Copy the sorted subarray back to the input */
        for(i = left; i < right; i++)
        {
            input[i] = scratch[i - left];
        }
    }
}

/* mergesort returns true on success.  Note that in C++, you could also
 * replace malloc with new and if memory allocation fails, an exception will
 * be thrown.  If we don't allocate a scratch array here, what happens? 
 *
 * Elements are sorted in reverse order -- greatest to least */
template<typename NumberType, typename ArrType>
int mergesort2(ArrType *input, NumberType size)
{
    ArrType *scratch = (ArrType *)malloc((size) * sizeof(ArrType));
	//ArrType* scratch[]=new ArrType[sizeof(ArrType) * size];
    if(scratch != NULL)
    {
		NumberType start=0;
        merge_helper(input, start, size, scratch);
        free(scratch);
		//delete scratch;
        return 1;
    }
    else
    {
        return 0;
    }
}