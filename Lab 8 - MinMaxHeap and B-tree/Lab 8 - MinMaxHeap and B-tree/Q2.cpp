#include <iostream>
#include <vector>
using namespace std;

// -------------------------------
// INSERTION & DELETION for MAX-HEAP
// -------------------------------

// Function to restore Max-Heap property after insertion
void heapifyUpMax(vector<int>& heap, int index) {
    // While the node is not the root and its parent is smaller
    while (index > 0) {
        int parent = (index - 1) / 2; // Get parent index
        if (heap[index] > heap[parent]) {
            // Swap current node with parent if it's greater
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;

            // Move up to parent index
            index = parent;
        } else {
            break; // If already in correct position, stop
        }
    }
}

// Insert a value into Max-Heap
void insertMaxHeap(vector<int>& heap, int value) {
    heap.push_back(value);                 // Add new value at the end
    heapifyUpMax(heap, heap.size() - 1);   // Restore heap property
}

// Function to restore Max-Heap after deletion (heapify-down)
void heapifyDownMax(vector<int>& heap, int index) {
    int size = heap.size();

    while (2 * index + 1 < size) { // While at least left child exists
        int left = 2 * index + 1;      // Left child index
        int right = 2 * index + 2;     // Right child index
        int largest = index;           // Assume current node is largest

        if (left < size && heap[left] > heap[largest]) {
            largest = left; // Update if left child is larger
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right; // Update if right child is larger
        }

        if (largest != index) {
            // Swap with larger child and continue
            int temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;
            index = largest;
        } else {
            break; // No more swaps needed
        }
    }
}

// Delete max (root) from Max-Heap
void deleteMax(vector<int>& heap) {
    if (heap.empty()) return;            // Do nothing if heap is empty

    heap[0] = heap.back();               // Replace root with last element
    heap.pop_back();                     // Remove last element
    heapifyDownMax(heap, 0);             // Restore heap property
}

// Function to restore Min-Heap after insertion
void heapifyUpMin(vector<int>& heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;    // Get parent index
        if (heap[index] < heap[parent]) {
            // Swap if current is smaller than parent
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;

            index = parent; // Move up to parent
        } else {
            break; // Heap property restored
        }
    }
}

// Insert a value into Min-Heap
void insertMinHeap(vector<int>& heap, int value) {
    heap.push_back(value);                // Add new value at the end
    heapifyUpMin(heap, heap.size() - 1);  // Restore heap property
}

// Function to restore Min-Heap after deletion (heapify-down)
void heapifyDownMin(vector<int>& heap, int index) {
    int size = heap.size();

    while (2 * index + 1 < size) { // While left child exists
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left; // Update if left is smaller
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right; // Update if right is smaller
        }

        if (smallest != index) {
            // Swap with smaller child
            int temp = heap[index];
            heap[index] = heap[smallest];
            heap[smallest] = temp;

            index = smallest; // Continue downward
        } else {
            break; // Heap property restored
        }
    }
}

// Delete min (root) from Min-Heap
void deleteMin(vector<int>& heap) {
    if (heap.empty()) return;

    heap[0] = heap.back();               // Replace root with last
    heap.pop_back();                     // Remove last
    heapifyDownMin(heap, 0);             // Restore heap property
}

// Print elements of heap
void printHeap(const vector<int>& heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Initial values to insert
    vector<int> values = {30, 10, 20, 50, 40};

    // max heap
    vector<int> maxHeap;
    for (int v : values) insertMaxHeap(maxHeap, v);
    cout << "Max-Heap after insertions: ";
    printHeap(maxHeap);
    deleteMax(maxHeap);
    cout << "Max-Heap after deleting root: ";
    printHeap(maxHeap);

    // min heap
    vector<int> minHeap;
    for (int v : values) insertMinHeap(minHeap, v);
    cout << "Min-Heap after insertions: ";
    printHeap(minHeap);
    deleteMin(minHeap);
    cout << "Min-Heap after deleting root: ";
    printHeap(minHeap);

    return 0;
}
