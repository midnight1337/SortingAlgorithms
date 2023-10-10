/*
Bubble Sort - sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order.

Traverse from left and compare adjacent elements and the higher one is placed at right side. 
In this way, the largest element is moved to the rightmost end at first. 
This process is then continued to find the second largest and place it and so on until the data is sorted.

Detailed explenation:
1.Set outter iterator (i) to 0 as we'll use first element to compare with others
2.Start in inner loop (j) from left (index 0), compare adjacent element on the right (index 1), if compared element is smaller then swap them
3.Increment iterator as our first element has moved to the right (index 1)
4.Compare it again with next element
5.Repeat till last element of array
6.Increment outter iterator (i) and repeat all steps
*/
#include <iostream>

class BubbleSort
{
    private:
        int arr[10] = {3,1,2,7,0,9,4,5,8,6};
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
