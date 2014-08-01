#define SUCCESS 1

template <typename T>
int mergesort(T * list, const int numElements)
{
	// If our list has 0 or 1 elements, return (i.e. already sorted)
	if(numElements < 2)
		return SUCCESS;

	// We need to 'divide and conquer' our list
	// Calculate the number of elements we'll need in each of our two smaller lists
	int numInBottom = (int)ceil((double)numElements/2.0);	// Any way to do this better with ints?
	int numInTop = numElements - numInBottom;

	// Run merge sort on both
	mergesort<T>(list, numInBottom);	// Bottom list
	mergesort<T>(list + numInBottom, numInTop);		// Top list

	// Merge the results
	merge<T>(list, list+numInBottom, numInBottom, numInTop);

	return SUCCESS;
}

// Merges two sorted lists into one. Places the result at the start of the 'bottom' list.
// After returning successfully, the 'bottom' list has (numInBottom + numInTop) elements.
// Assumes parameters 'bottom' and 'top' are pre-sorted.
template <typename T>
int merge(T * bottom, T * top, const int numInBottom, const int numInTop)
{
	// Indexers for bottom and top lists
	int bIndex = 0, tIndex = 0;

	// Create a new collection to store our result temporarily
	T * result = new T[numInBottom+numInTop];

	while((bIndex < numInBottom) && (tIndex < numInTop))
	{
		// Find which of our current pair of elements should be put into our result next
		if(bottom[bIndex] < top[tIndex])
			result[(bIndex++)+tIndex] = bottom[bIndex];
		else
			result[bIndex+(tIndex++)] = top[tIndex];
	}

	// At this point one of the lists is empty.
	// Concatenate what's left of the other one onto the end of our result.
	if(bIndex < numInBottom)
		memcpy(result + (bIndex+tIndex), bottom + bIndex, sizeof(T)*(numInBottom - bIndex));
	else
		memcpy(result + (bIndex+tIndex), top + tIndex, sizeof(T)*(numInTop - tIndex));

	// Copy our result back to the original list
	memcpy(bottom, result, sizeof(T)*(numInTop+numInBottom));

	// Deallocate our dynamically-allocated memory
	delete [] result;

	return SUCCESS;
}




/*合併排序*/

#include <vector>

template<typename IT, typename VT> void insert1(IT begin, IT end, const VT &v)
{
  	using ::std::swap;
  	while (begin+1!=end && *(begin+1)<v) {
  		swap(*begin, *(begin+1));
  		++begin;
  	}
  	swap(*begin, v);
}
  
  
template<typename IT> void merge1(IT begin, IT begin_right, IT end)
{
  	for(;begin<begin_right; ++begin) {
  		if(*begin_right < *begin) {
  			typename std::iterator_traits<IT>::value_type v;
  			using ::std::swap;
  			swap(v, *begin);
  			swap(*begin, *begin_right);
  			insert1(begin_right, end, v);
  		}
  	}
}
  
template<typename IT> void mergesort1(IT begin, IT end)
{
  	size_t size(end-begin);
  	if(size<2) return;
  
  	IT begin_right=begin+size/2;
  
  	mergesort1(begin, begin_right);
  	mergesort1(begin_right, end);
  	merge1(begin, begin_right, end);
}
  
 
template<typename T> void print(const T &data)
{
  	std::cout<<" "<<data;
}

/*end 合併排序*/
