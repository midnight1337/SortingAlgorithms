/*
Insertion Sort - sorting algorithm that works by virtually dividing colletion into sorted and unsorted part,
first element from unsorted part is compared with right element from sorted part.

Time complexity: average case:O(N^2), best case O(N)
Memory complexity: O(1)

We assume that first element from collection is our first element in sorted part,
In first iteration we compare i+1 element with i element as we said the first one is ordered.
We swap elements and start another iteration with i+1, again we compare next unordered value
with last ordered value, and we do it again as soon as it is larger than any element from sorted part.

Detailed explenation:
1.Start iteration loop (i), it indicates how many times we should loop through collection,
It ends at N - 1 because we can't access N element of an array.
2.Create local variable that will help track variables from sorted part.
3.Enter while loop if first unordered element is larger than last ordered element,
Swap them, decrement local variable that helps tracing sroted part and repeat whole step.
*/
#include <iostream>


class InsertionSort
{
    private:
        int m_array[5] = {3,1,2,7,0};
        int m_array_size = sizeof(m_array) / sizeof(*(m_array + 0));

    public:
        InsertionSort() = default;
        void do_insertion_sort();
        void print_array();
};


void InsertionSort::do_insertion_sort()
{
    for(int i = 0; i < m_array_size - 1; i++)
    {
        int j = i;
        
        while(m_array[j + 1] < m_array[j] && j >= 0)
        {
            int hold_value = m_array[j];
            m_array[j] = m_array[j + 1];
            m_array[j + 1] = hold_value;
            j--;
        }    
    }
}

void InsertionSort::print_array()
{
    for (int i = 0; i < m_array_size; i++)
    {
        std::cout << m_array[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    InsertionSort insertion_sort = InsertionSort();
    
    insertion_sort.print_array();
    insertion_sort.do_insertion_sort();
    insertion_sort.print_array();

    return 0;
}