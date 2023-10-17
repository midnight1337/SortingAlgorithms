/*
Quick sort - it's based on 'divide and conquer' assumption, bigger problems are divided into smallers.

Algorithm uses a pivot which helps us to divide array into two parts called partitions, one for smaller numbers than pivot and one for larger numbers than pivot.
After partitioning, each of partition is passed as argument to quicksort function again so recursion happens. Problem is solved when there is only one lement passed in an array.

Time complexity (average case): O(N*log(N))

1.First we check base condition, if start index is larger or equal than stop index, then there is only single element in an array, hence we assume it's sorted so we break from that recursive method call.
2.We call partition() method which returns pivot index that divides our array into two partitions, we pass array to sort, start and stop index.
3.In partition() method, we create pivot index variable which represents last element in an array (we still don't know where in an array we should put pivot)
We also create limit variable which represents some kind of border, first element to the right to limit is about to be swapped in further loop condition is true.
We enter for loop that iterates over array elements, iteration range is dependent on start and stop index.
If current element is smaller than pivot, then we increment limit at first then and swap that current element with a element pointed by limit index, loop continues.
At the end we increment limit once again to swap first element to the right of limit with pivot, then our pivot is at the middle of array, hence we divided it in smaller and larger partitions.
4.Pivot index is returned to a caller, then there are called recursively quicksort methods again, one with array in range 0 to pivot, and another with array in range pivot to last element.
*/
#include <iostream>


class QuickSort
{
    public:
        QuickSort() = default;
        int partition(int* array, int start, int stop);
        void quick_sort(int* array, int start, int stop);
};

void QuickSort::quick_sort(int* array, int start, int stop)
{
    if (start >= stop) {return;}

    int pivot = partition(array, start, stop);

    quick_sort(array, start, pivot - 1);
    quick_sort(array, pivot + 1, stop);
}

int QuickSort::partition(int* array, int start, int stop)
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

    QuickSort sort = QuickSort();

    sort.quick_sort(array, start, stop);

    print(array, array_size);

    return 0;
}
