/*
Selection sort - is a sorting algorithm that works by repeatedly selecting a lowest number from unordered part of the array during current iteration,
and moving it into a sorted part of the array.

Algorithm uses a outter loop that indicates hold element, and inner loop that loops over array to find minimum element. At the end it swaps them.
We assume that everything on the 'left' side from outter iterator, is sorted part of array, hence every new loop begins, we have one lement less to compare.

Time complexity: O(N^2)
*/
#include <iostream>


class SelectionSort
{
    public:
        SelectionSort() = default;
        void selection_sort(int* array, int array_size);
};


void SelectionSort::selection_sort(int* array, int array_size)
{
    for (int i = 0; i < array_size - 1; i++)
   {
        int min_value_index = i;

        for (int j = i + 1; j < array_size - 1; j++)
        {
            if (array[j] < array[min_value_index])
            {
                min_value_index = j;
            }
        }
        std::swap(array[i], array[min_value_index]);
    }
}


void print(int* array, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "" << std::endl;
}


int main()
{
    int array[] = {3, 1, 6, 2, 7, 0, 5, 4, 8, 9};
    int array_size = sizeof(array) / sizeof(array[0]);

    SelectionSort sort = SelectionSort();

    sort.selection_sort(array, array_size);

    print(array, array_size);

    return 0;
}
