/*
Quick sort - it's based on 'divide and conquer' assumption, bigger problems are divided into smallers.
It uses a pivot which helps us to create two sub-problems, one for smaller numbers han pivot and one for larger numbers than pivot.
Divided parts are called partitions, each partition is called as a recursion till single element lasts as unsorted partition.
*/
#include <iostream>
using namespace std;


int partition(int* array, int start, int stop)
{
    // Determine pivot value as last value in collection
    int pivot = array[stop];

    // limit is an index that is placed as border to value, which is about to be swapped in a for loop. [limit | value_1, value_2]
    int limit = (start - 1);

    for (int j = start; j <= stop; j++)
    {
        if (array[j] < pivot)
        {
            limit++;
            swap(array[limit], array[j]);
        }
    }

    // limit + 1, because we need to swap a value to the right of limit
    swap(array[limit + 1], array[stop]);

    // return a current pivot index
    return (limit + 1);
}

void quicksort(int* array, int start, int stop)
{
    // if start index is greater or equals stop index, then there is only single element in array to be sorted, hence sorting for that case is done
    if (start >= stop)
    {
        return;
    }

    int pivot_index = partition(array, start, stop);

    quicksort(array, start, pivot_index - 1);
    quicksort(array, pivot_index + 1, stop);
}

int main()
{
    int array[] = {1,2,4,3};
    int array_size = sizeof(array) / sizeof(array[0]);
    int start = 0;
    int stop = array_size - 1;

    quicksort(array, start, stop);

    cout << "Sorted Array\n";
    for (int i = 0; i < array_size; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}
