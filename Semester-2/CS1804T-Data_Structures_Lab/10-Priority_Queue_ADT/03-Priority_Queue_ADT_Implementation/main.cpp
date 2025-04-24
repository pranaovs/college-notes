#include <iostream>
#include <vector>

using namespace std;

class maxheap {
    vector<int> heap = {0};  // 1-based indexing: index 0 is a placeholder
    int cur;                 // cur is the next available index

public:
    maxheap() {
        cur = 1;           // Heap is empty when cur == 1
    }

    void heapifyup() {
        int temp = cur - 1;  // new element is at cur-1
        while (temp > 1 && heap[temp / 2] < heap[temp]) {
            // Swap the current element with its parent
            int temp1 = heap[temp];
            heap[temp] = heap[temp / 2];
            heap[temp / 2] = temp1;
            temp = temp / 2;
        }
    }

    void heapifydown() {
        int index = 1;  // start at the root
        while (index * 2 < cur) {  // while there is at least a left child
            int left = index * 2;
            int right = left + 1;
            int maxIndex = left;  // assume left child is larger

            // If right child exists and is greater than left child, update maxIndex
            if (right < cur && heap[right] > heap[left]) {
                maxIndex = right;
            }
            
            // If the current node is larger than the larger child, break
            if (heap[index] >= heap[maxIndex]) {
                break;
            }

            // Swap current node with the larger child
            int temp = heap[index];
            heap[index] = heap[maxIndex];
            heap[maxIndex] = temp;

            // Continue heapifying down from the swapped child index
            index = maxIndex;
        }
    }

    void insert(int value) {
        heap.push_back(value);
        cur++;
        heapifyup();
    }

    int del() {
        if (cur == 1) {
            cout << "The heap is empty" << endl;
            return -1;
        }
        int maxvalue = heap[1];         // store the max value (root)
        heap[1] = heap[cur - 1];          // move the last element to the root
        heap.pop_back();                  // remove the last element
        cur--;                          // decrease heap size
        heapifydown();                  // restore the heap property
        return maxvalue;
    }

    void display() {
        if (cur == 1) {
            cout << "Empty" << endl;
            return;
        }
        // Display elements from index 1 to cur - 1
        for (int i = 1; i < cur; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void search(int value) {
        for (int i = 1; i < cur; i++) {
            if (heap[i] == value) {
                cout << "The value " << value << " is found." << endl;
                return;
            }
        }
        cout << "Not found" << endl;
    }

    void sort() {
        vector<int> sorted;
        int originalCur = cur; 
        vector<int> originalHeap = heap; 

        // Repeatedly delete the max and store it
        while (cur > 1) {
            int maxVal = del();
            sorted.push_back(maxVal);
        }

        cout << "Sorted (descending order): ";
        for (int val : sorted) {
            cout << val << " ";
        }
        cout << endl;

        // Restore the original heap (if needed)
        heap = originalHeap;
        cur = originalCur;
    }
};

int main() {
    maxheap heap;
    int choice, value;
    
    while (true) {
        cout << "\n--- Priority Queue Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Sort (Heap Sort)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                heap.insert(value);
                break;
            case 2:
                value = heap.del();
                if (value != -1)
                    cout << "Deleted: " << value << endl;
                break;
            case 3:
                cout << "Heap elements: ";
                heap.display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                heap.search(value);
                break;
            case 5:
                heap.sort();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
