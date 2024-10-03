#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Heap {
public:
    vector<int> arr; // Heap array
    int s;           // Size of the heap (next insertion point)

    // Constructor
    Heap() : s(1) { 
        arr.resize(100); // Resize to handle up to 100 elements
    }

    // Max heap insertion
    void maxHeapInsertion(int data) {
        int nodeIndex = s;
        arr[nodeIndex] = data;
        s++;  // Increment heap size
        
        // Heapify up to maintain the max-heap property
        while (nodeIndex > 1) {
            int parent = nodeIndex / 2;
            if (arr[parent] < arr[nodeIndex]) {
                swap(arr[parent], arr[nodeIndex]);
                nodeIndex = parent;  // Move up to the parent node
            } else {
                break;  // No more swaps needed, max-heap property satisfied
            }
        }
        return;
    }

    // Print heap
    void print() {
        for (int i = 1; i < s; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Max heap deletion (correct logic for internal swap)
    void maxHeapDeletion() {
        if (s == 1) { // Heap is empty
            cout << "Heap is empty, no deletion performed." << endl;
            return;
        }

        // Step 1: Move the last element to the root and reduce the size
        arr[1] = arr[s - 1];
        s--;  // Reduce heap size (logical size)

        // Step 2: Heapify down the root element to restore max-heap property
        int i = 1;
        while (i < s) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            int largest = i;

            // Check if left child exists and is greater than current element
            if (leftIndex < s && arr[leftIndex] > arr[largest]) {
                largest = leftIndex;
            }

            // Check if right child exists and is greater than largest found so far
            if (rightIndex < s && arr[rightIndex] > arr[largest]) {
                largest = rightIndex;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest; // Continue heapifying down
            } else {
                break;  // Heap is now valid
            }
        }
    }
};

// Corrected heapify function for fixing individual nodes
void heapify(vector<int> &arr, int n, int size) {
    int largest = n;
    int leftNode = 2 * n;
    int rightNode = 2 * n + 1;

    // Check if left child exists and is greater than current element
    if (leftNode < size && arr[leftNode] > arr[largest]) {
        largest = leftNode;
    }

    // Check if right child exists and is greater than largest found so far
    if (rightNode < size && arr[rightNode] > arr[largest]) {
        largest = rightNode;
    }

    // If largest is not the parent node, swap and heapify further
    if (largest != n) {
        swap(arr[n], arr[largest]);
        heapify(arr, largest, size); // Recursively heapify the affected sub-tree
    }
}

// Function to build a max-heap from an unsorted array
void buildHeap(vector<int> &arr, int size) {
    for (int i = size / 2; i >= 1; i--) {
        heapify(arr, i, size);
    }
}

int main() {
    Heap p;  // Create a Heap object
    int data;

    // Input numbers until -1 is entered
    // Example input: 10 20 30 40 50 -1
    while (true) {
        cout << "Enter number to insert (-1 to stop): " << endl;
        cin >> data;
        if (data == -1) break;
        p.maxHeapInsertion(data);  // Max heap insertion
    }
    
    cout << "Max Heap after Insertion: " << endl;
    p.print();
    
    // Uncomment the following to test heap deletion
    // cout << "After deletion from Max Heap: " << endl;
    // p.maxHeapDeletion();
    // p.print();

    // Call buildHeap to ensure the array satisfies heap property
    buildHeap(p.arr, p.s - 1);  // The size is p.s - 1 (since heap is 1-indexed)
    cout << "Heap after buildHeap: " << endl;
    p.print();

    return 0;
}
