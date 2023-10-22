/*
Quick sort - It works on the principle of Divide and Conquer based on the idea of breaking down a list into several sub-lists,
until each sublist consists of a single element in a manner that results into a sorted list.

Algorithm uses a pivot, which helps to divide array into two parts called partitions, one for smaller numbers than pivot and one for larger numbers than pivot.
Algorithm uses a limit, which helps to sort partitions into smaller and larger numbers than pivot, number at left side of limit are considered as smaller than pivot.

Partitioning:
1.If element at the right side of limit, is larger than pivot, then do nothing, increment iterator that points at array number,
If it's smaller, then increment limit and swap number under limit with number under pointer iterator.

2.After loop swap element under pivot with first element on the right from limit
(this is place where pivot is placed, with that array is 'divided' into smaller elements and larger elements than pivot)

3.After partitioning, each of partition divided by pivot is passed as argument to quicksort function again so recursion happens. 
Sorting is done when passed array contains only one element.

limit  i              pivot  3 < 5  limit   i          pivot    1 < 5    limit   i       pivot   7 > 5   limit     i    pivot   ......
    |  3, 1, 7, 2, 0,  5              3  |  1, 7, 2, 0,  5                3, 1 | 7, 2, 0,  5             3, 1 | 7, 2, 0,  5

Time complexity (average case): O(N*log(N))
*/
#include <iostream>


class QuickSort
{
    public:
        QuickSort() = default;
        void quick_sort(int* array, int start, int stop);
        int partition(int* array, int start, int stop);
};

void QuickSort::quick_sort(int* array, int start, int stop)
{
    //Base condition
    if (start >= stop) {return;}

    //Get pivot index
    int pivot = partition(array, start, stop);

    //Call the same method till condition met
    quick_sort(array, start, pivot - 1);
    quick_sort(array, pivot + 1, stop);
}

int QuickSort::partition(int* array, int start, int stop)
{
    //Create indexes of temporary pivot and limit
    int pivot = stop;
    int limit = start - 1;

    //Loop over array and determine where limit should be placed
    for (int i = start; i < stop; i++)
    {
        if (array[i] < array[stop])
        {
            limit++;
            std::swap(array[i], array[limit]);
        }
    }

    //Swap pivot with limit and return current pivot index
    limit++;
    std::swap(array[limit], array[stop]);
    
    return limit;
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
    int start = 0;
    int stop = array_size - 1;

    QuickSort sort = QuickSort();

    sort.quick_sort(array, start, stop);

    print(array, array_size);

    return 0;
}
