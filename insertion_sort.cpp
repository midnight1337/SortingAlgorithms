/*
Insertion Sort - sorting algorithm that works by virtually dividing colletion into sorted and unsorted part,
first element from unsorted part is compared with last element from sorted part.

Time complexity: average case:O(N^2), best case O(N)
Memory complexity: O(1)

We assume that first element dereferenced by [i] from collection is our first element in sorted part,
In first iteration we compare [i + 1] element (unsorted part) with [i] element (sorted part).
If compared element from unsorted part is smaller then we swap them, so element [i] is now in unsorted part and [i + 1] element is in sorted part,
We check in a continous loop if that swapped element which is now in sorted part is smaller than any other from that part, and we swap them if it is.
At new iteration we increment i, which points into next element in an array and steps are repeated.
Algorithm works in a [N - 1] range.

Detailed explenation:
1.Start iteration loop (i), it indicates how many times we should loop through collection, It ends at N - 1 because we can't access N element of an array.
2.Create local variable (j) that will help track variables from sorted part.

3.Enter while loop,
If last element from sorted part is larger than first element from unsorted part, then swap them, and decrement j.
Check if that new last sorted element is larger than previous one in sorted part, if so swap them <-> continue in a while loop till the end of loop.

4.Increment (i) and repeat
*/
#include <iostream>


class InsertionSort
{
    public:
        InsertionSort() = default;
        void insertion_sort(int* array, int array_size);
};


void InsertionSort::insertion_sort(int* array, int array_size)
{
    for(int i = 0; i < array_size - 1; i++)
    {
        int j = i;
        
        while(array[j] > array[j + 1] && j >= 0)
        {
            std::swap(array[j], array[j + 1]);
            j--;
        }    
    }
}


void print(int* array, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        std::cout << array[i] << " ";
    }
}


int main()
{
    int array[] = {3, 1, 2, 7, 0, 5};
    int array_size = sizeof(array) / sizeof(array[0]);

    InsertionSort sort = InsertionSort();

    sort.insertion_sort(array, array_size);

    print(array, array_size);

    return 0;
}
