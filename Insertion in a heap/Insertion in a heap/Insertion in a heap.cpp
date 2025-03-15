/*Insertion in a Heap
A min-heap is a binary tree data structure that satisfies the heap property. Heap property refers to the specific ordering of elements in a binary heap. In a min heap, the value of any node is less than or equal to the values of its children.

The binary tree representing the heap is always complete. This means that the tree is completely filled at all levels except possibly the lowest, which is filled from left to right.

Min-heaps are often implemented using an array, where the children of the node at index i are located at indices 2i + 1 (left child) and 2i + 2 (right child). The parent of a node at index i is at index (i - 1) / 2.

Insertion in Min Heap
In a binary heap, the elements are stored in an array
To insert a new element, you add it at the end of the array (as the last leaf in the binary tree).
Then, you compare the new element with its parent and swap them if necessary until the heap property is restored.
The pseudo-code given below shows how the numbers are added to your heap and how your heap is updated once a number is added.

Task
You are given an integer N (representing the count of elements) and N integers
You need to add these N integers in your heap
You have to print the array after each insertion
Sample 1:
Input
5
5
4
3
2
1
Output
5
4 5
3 5 4
2 3 4 5
1 2 4 5 3 */
#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

class MinHeap
{
    int* harr;
    int capacity;
    int heap_size;

public:
    MinHeap(int capacity);  //Constructor

    void MinHeapify(int i);

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    void decreaseKey(int i, int new_val);

    void insertKey(int k);

    void printHeap();

};

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end 
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Fix the min heap property if it is violated 
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::printHeap()
{
    for (int i = 0; i < heap_size; i++)
        cout << harr[i] << " ";
    cout << endl;
}


int main() {
    int N;
    cin >> N;

    MinHeap h(N);


    for (int i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        h.insertKey(value);
        h.printHeap();
    }

    return 0;

}