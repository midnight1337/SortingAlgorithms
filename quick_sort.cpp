/*
Quick sort - it's based on 'divide and conquer' assumption, bigger problems are divided into smallers,
this way we'll get sorted data structer.
It uses a pivot which helps us to create two sub-problems, one for smaller numbers han pivot and one for larger numbers than pivot

Step by step:
1.Choose a pivot as last element of collection
1.1.Choose a limit as first element of collection - we don't know where our limit should be placed in order to divide collection into to sub-collections
1.2.Start loop condition to compare elements, iteration over N-1 because we don't compare pivot with pivot:
if first element to the right of limit is greater than pivot, number is on its place, proceed to next number
if first element to the right of limit is smaller than pivot, then swap that number with next one, increment limit index
At the end, swap pivot with first number to the right of limit index
We are sure that numbers at the left of pivot are smaller than pivot, and numbers at the right of pivot are larger than pivot
3.We use recursion to sort our two sub-divisions
3.1.Start at smaller sub-division, we use same steps as above, we choose pivot and limit from that collection of smaller numbers than main pivot
Repeat till one element is present
*/
#include <iostream>


class QuickSort
{
    private:
        int m_array[5] = {3,1,2,7,0};
        int m_array_size = sizeof(m_array) / sizeof(*(m_array + 0));

    public:
        QuickSort() = default;
        void do_quick_sort();
        void print_array();
};

void QuickSort::do_quick_sort()
{
    int pivot = m_array[m_array_size - 1];
    int limit = 0;
    
    for (int i = 0; i < m_array_size - 1; i++)
    {
        if (m_array[i] < pivot)
        {
            if (i != 0)
            {
                int hold_value = m_array[i + 1];
                m_array[i + 1] = m_array[i];
                m_array[i] = hold_value;
            }
        }
        limit++;
    }

    int hold_value = m_array[limit];
    m_array[limit] = pivot;
    m_array[m_array_size - 1] = hold_value;

}

void QuickSort::print_array()
{
    for (int i = 0; i < m_array_size; i++)
    {
        std::cout << m_array[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    QuickSort quick_sort = QuickSort();
    quick_sort.print_array();
    quick_sort.do_quick_sort();
    quick_sort.print_array();

    return 0;
}
