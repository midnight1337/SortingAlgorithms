/*
Quick sort - recursive algorithm based on 'divide and conquer' assumption, bigger problems are divided into smallers.
As recursive algorithm it has to contain base condition that breaks further recursive calls, in quick sort there is if statement which checks if there is single element in array.
Algorithm uses a pivot, which helps to divide array into two parts called partitions, one for smaller numbers than pivot and one for larger numbers than pivot.
Algorithm uses a limit, which helps to sort partitions into smaller and larger numbers than pivot, number at left side of limit are considered as smaller than pivot.
If element at the right side of limit, is larger than pivot, then do nothing and increment iterator that points at array numbers in a for loop,
If it's smaller, then increment limit and swap number under limit with number under pointer iterator.
At the end swap pivot with first element on the right from limit - this is place where pivot is placed to divide array into smaller and larger partitions.
Array is now kinda sorted with one element on it's place.
After partitioning, each of partition divided by pivot is passed as argument to quicksort function again so recursion happens. 
Sorting is done when passed array contains only one element - we can check it by comparing indexes, if start >= stop.

limit  i              pivot  3 < 5  limit   i          pivot    1 < 5    limit   i       pivot   7 > 5   limit     i    pivot   ......
    |  3, 1, 7, 2, 0,  5              3  |  1, 7, 2, 0,  5                3, 1 | 7, 2, 0,  5             3, 1 | 7, 2, 0,  5

Time complexity (average case): O(N*log(N))
*/
#include <iostream>


class MergeSort
{
    public:
        MergeSort() = default;
        void merge_sort(int* array, int start, int stop);
        int partition(int* array, int start, int stop);
};

void MergeSort::merge_sort(int* array, int start, int stop)
{
    if (start >= stop) {return;}

    int pivot = partition(array, start, stop);

    merge_sort(array, start, pivot - 1);
    merge_sort(array, pivot + 1, stop);
}

int MergeSort::partition(int* array, int start, int stop)
{
    int pivot = stop;
    int limit = start - 1;

    for (int i = start; i < stop; i++)
    {
        if (array[i] < array[stop])
        {
            limit++;
            std::swap(array[i], array[limit]);
        }
    }

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

    MergeSort sort = MergeSort();

    sort.merge_sort(array, start, stop);

    print(array, array_size);

    return 0;
}
