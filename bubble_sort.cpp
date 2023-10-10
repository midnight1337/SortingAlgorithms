/*
Bubble Sort - sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order.

Time complexity: O(N^2)
Algorithm is easy to implement and understood, but it's very slow at large data sets.

Traverse from left and compare adjacent elements and the higher one is placed at right side. 
In this way, the largest element is moved to the rightmost end at first. 
This process is then continued to find the second largest and place it and so on until the data is sorted.

Detailed explenation:
1.Start outter loop with iterator (i), it indicates how many times we should loop through sorting
2.Start in inner loop with iterator (j), it indicates first element to begin with, ...
compare with adjacent element on the right, if compared element is smaller then swap them
3.Increment inner iterator (j) which indicates next element to begin with, ...
compare it with adjacent element on the right, repeat till last element of an array
4.Increment outter iterator (i), repeat all steps
*/
#include <iostream>


class BubbleSort
{
    private:
        int arr[5] = {3,1,2,7,0};
        int arr_size = sizeof(arr) / sizeof(*(arr + 0));

    public:
        BubbleSort() = default;
        void do_bubble_sort();
        void print_arr();
};


void BubbleSort::do_bubble_sort()
{
    for (int i = 0; i < arr_size - 1; i++)
    {
        for (int j = 0; j < arr_size - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int smaller_value = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = smaller_value;
            }
        }
    }
}

void BubbleSort::print_arr()
{
    for (int i = 0; i < arr_size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    BubbleSort bubble_sort = BubbleSort();
    bubble_sort.print_arr();
    bubble_sort.do_bubble_sort();
    bubble_sort.print_arr();

    return 0;
}
