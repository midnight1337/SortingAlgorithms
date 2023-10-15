/*
Insertion Sort - sorting algorithm that works by virtually dividing colletion into sorted and unsorted part,
first element from unsorted part is compared with right element from sorted part.

Time complexity: average case:O(N^2), best case O(N)
Memory complexity: O(1)

We assume that first element dereferenced by [i] from collection is our first element in sorted part,
In first iteration we compare [i + 1] element with [i] element as we assume the first one is from ordered part and next one unordered.
If compared element from unordered part is smaller then we swap them, so element [i] is now in unordered part and [i + 1] element is in ordered part,
We check in a continous loop if that swapped element which is now in ordered part is smaller than any other from that part, and we swap them if it is.
Algorithm works in a [N - 1] range

Detailed explenation:
1.Start iteration loop (i), it indicates how many times we should loop through collection, It ends at N - 1 because we can't access N element of an array.
2.Create local variable (j) that will help track variables from sorted part.
3.Enter while loop,
if last element from ordered part is larger than first element in unordered part, then swap them and decrement j,
check if that new last sorted element is larger than previous one, if so swap them <-> continue in a while loop till the end of loop.
4.Increment (i) and repeat
*/
#include <iostream>


class InsertionSort
{
    private:
        int m_array[5] = {3,1,2,7,0};
        int m_array_size = sizeof(m_array) / sizeof(*(m_array + 0));

    public:
        InsertionSort() = default;
        void insertion_sort();
        void print_array();
};


void InsertionSort::insertion_sort()
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
    InsertionSort sort = InsertionSort();
    
    sort.print_array();

    sort.insertion_sort();

    sort.print_array();

    return 0;
}