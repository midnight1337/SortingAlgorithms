/*
Bubble Sort - sorting algorithm that works by repeatedly swapping the adjacent items if they are in the wrong order.
Algorithm is easy to implement and understood, but it's very slow at large data sets.

Time complexity: O(N^2)


Traverse from left and compare first one with adjacent item, if first item is larger then swap them.
In this way, the largest item is moved to the rightmost end at first. 
This process is then continued to find the second largest item, process repeats until the data is sorted.

Detailed explenation:
1.Start outter loop with iterator (i), it indicates how many times we should loop through array items

2.Start in inner loop with iterator (j), it indicates first item to begin with and compare with next one,
It works in range (0, array_size- 1 - i), -1 because we don't need to compare last item with last item,
-i because every time i increments, we have one item less to compare, as most large item goes at the end of array in every loop.
Compare first item with adjacent item on the right, if compared item is smaller then swap them

3.Increment inner iterator (j) which indicates next item to begin with,
compare it with adjacent item on the right, repeat till last item of an array

4.Increment outter iterator (i), repeat all steps
*/
#include <iostream>


class BubbleSort
{
    public:
        BubbleSort() = default;
        void bubble_sort(int* array, int array_size);
};


void BubbleSort::bubble_sort(int* array, int array_size)
{
    for (int i = 0; i < array_size - 1; i++)
    {
        for (int j = 0; j < array_size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int smaller_value = array[j + 1];
                array[j + 1] = array[j];
                array[j] = smaller_value;
            }
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

    BubbleSort sort = BubbleSort();

    sort.bubble_sort(array, array_size);

    print(array, array_size);

    return 0;
}
