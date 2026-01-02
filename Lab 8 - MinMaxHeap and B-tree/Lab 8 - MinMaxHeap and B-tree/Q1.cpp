#include <iostream>
#include <vector>
using namespace std;

// Function to make a subtree rooted at index i into a max heap
void maxHeapify(vector<int>& heap, int n, int i) {
    int largest = i;           // Initialize largest as root
    int left = 2 * i + 1;      // Left child index
    int right = 2 * i + 2;     // Right child index

    // If left child is larger than root
    if (left < n && heap[left] > heap[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && heap[right] > heap[largest])
        largest = right;

    // If largest is not root, swap and and do recursive to repeat max heap
    if (largest != i) {
        swap(heap[i], heap[largest]);
        maxHeapify(heap, n, largest);
    }
}

// Function to build Max-Heap
void buildMaxHeap(vector<int>& heap) {
    int n = heap.size();
    // Start from last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, n, i);
    }
}

// Function to heapify for Min-Heap
void minHeapify(vector<int>& heap, int n, int i) {
    int smallest = i;       // Initialize largest as root
    int left = 2 * i + 1;   // Left child index
    int right = 2 * i + 2;  // Right child index

    // Compare left child
    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    // Compare right child
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    // If smallest is not root, swap and and do recursive to repeat min heap
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

// Build Min-Heap 
void buildMinHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(heap, n, i);
    }
}

// Print a heap
void printHeap(const vector<int>& heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

// Perform Heap Sort for Max-Heap (Descending Order)
vector<int> heapSortDescending(vector<int> heap) {
    buildMaxHeap(heap);
    int n = heap.size();
    for (int i = n - 1; i > 0; i--) {
        swap(heap[0], heap[i]);        // Move max to end
        maxHeapify(heap, i, 0);        // Heapify remaining
    }
    return heap;
}

// Perform Heap Sort for Min-Heap (Ascending Order)
vector<int> heapSortAscending(vector<int> heap) {
    buildMinHeap(heap);
    int n = heap.size();
    for (int i = n - 1; i > 0; i--) {
        swap(heap[0], heap[i]);        // Move min to end
        minHeapify(heap, i, 0);        // Heapify remaining
    }
    return heap;
}

int main() {
    vector<int> values = {30, 10, 20, 50, 40}; // Initialize values

    vector<int> maxSorted = heapSortAscending(values);
    cout << "Max-Heap: ";
    printHeap(maxSorted);

    vector<int> minSorted = heapSortDescending(values);
    cout << "Min-Heap: ";
    printHeap(minSorted);

    return 0;
}
