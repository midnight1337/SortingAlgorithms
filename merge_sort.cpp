/*
Merge Sort - It works on the principle of Divide and Conquer based on the idea of breaking down a list into several sub-lists,
until each sublist consists of a single element and merging those sublists in a manner that results into a sorted list.

Merge sort is a recursive algorithm that continuously splits the array in half until it cannot be further divided i.e., 
the array has only one element left (an array with one element is always sorted). Then the sorted subarrays are merged into one sorted array.

1.Initially divide the array into two equal halves
2.These subarrays are further divided into two halves, until they become array of unit length that can no longer be divided (array of unit length is always sorted)
3.These sorted subarrays are compared and merged together, we get bigger sorted subarrays.
4.This merging process is continued until the sorted array is built from the smaller subarrays
*/
#include <iostream>

class MergeSort
{
    public:
        MergeSort() = default;
        void merge_sort(int* array, int start, int stop);
        void merge(int* array, int start, int middle, int stop);
        void fill_array(int* base_array, int* array_to_fill, int array_size, int start);
};

void MergeSort::merge_sort(int* array, int start, int stop)
{
    // Base condition
    if (start >= stop) {return;}
    
    // Determine middle of an base array
    int middle = (start + stop) / 2;

    // Call the same method till condition met
    merge_sort(array, start, middle);
    merge_sort(array, middle + 1, stop);

    // Merge arrays
    merge(array, start, middle, stop);
}

void MergeSort::merge(int* array, int start, int middle, int stop)
{
    //Initialise temporary left and right array, their border is at the middle of base array
    int l_array_size = middle - start + 1;
    int r_array_size = stop - middle;

    int l_array[l_array_size];
    int r_array[r_array_size];

    //Fill temporary arrays with base array elements
    fill_array(array, l_array, l_array_size, start);
    fill_array(array, r_array, r_array_size, middle + 1);

    //Create temporary variables that helps to merge arrays
    int i = 0;  // initial index of left array
    int j = 0;  // initial index of right array
    int k = start;  // initial index of merged sub arrays

    //Merge temporary arrays into base array
    while (i < l_array_size && j < r_array_size)
    {
        if (l_array[i] <= r_array[j])
        {
            array[k] = l_array[i];
            i++;
        }
        else {
            array[k] = r_array[j];    
            j++;
        }
        k++;
    }

    //If anything was left in temporary arrays (while loop might quit if one of arrays conditions was met)
    while (i < l_array_size)
    {
        array[k] = l_array[i];
        i++;
        k++;
    }

    while (j < r_array_size)
    {
        array[k] = r_array[j];
        j++;
        k++;
    }
}

void MergeSort::fill_array(int* base_array, int* array_to_fill, int array_size, int start)
{
    for (int i = 0; i < array_size; i++)
    {
        array_to_fill[i] = base_array[i + start];
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
    int array_size = sizeof(array) / sizeof(array[0]);  //6
    int start = 0;
    int stop = array_size - 1;  //5

    MergeSort sort = MergeSort();

    sort.merge_sort(array, start, stop);

    print(array, array_size);

    return 0;
}
