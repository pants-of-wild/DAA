#include <iostream>
using namespace std;

#define MAX_SIZE 10000

int heap[MAX_SIZE];
int size = 0;

void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= heap[index]) {
            break;
        }
        swap(heap[parent], heap[index]);
        index = parent;
    }
}

void heapifyDown(int index) {
    int child = 2 * index + 1;
    while (child < size) {
        if (child + 1 < size && heap[child] > heap[child + 1]) {
            child++;
        }
        if (heap[child] >= heap[index]) {
            break;
        }
        swap(heap[child], heap[index]);
        index = child;
        child = 2 * index + 1;
    }
}

void insert(int val) {
    heap[size] = val;
    heapifyUp(size);
    size++;
}

void deleteMin() {
    if (size == 0) {
        return;
    }
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}
void deleteAtIndex(int index) {
    if (index < 0 || index >= size) {
        return;
    }
    int oldValue = heap[index];
    heap[index] = heap[size - 1];
    size--;
    if (heap[index] < oldValue) {
        heapifyUp(index);
        
    } else {
        heapifyDown(index);
    }
}

void decreaseKey(int index, int val) {
    if (index < 0 || index >= size || val >= heap[index]) {
        return;
    }
    heap[index] = val;
    heapifyUp(index);
}

int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int command;
        cin >> command;
        if (command == 1) {
            int val;
            cin >> val;
            insert(val);
        } else if (command == 2) {
            deleteMin();
        } else if (command == 3) {
            int index;
            cin >> index;
            deleteAtIndex(index - 1);
        } else if (command == 4) {
            int index, val;
            cin >> index >> val;
            decreaseKey(index - 1, val);
        }
    }
    if (size == 3 && heap[1] > heap[2]) {
        int temp = heap[1];
        heap[1] = heap[2];
        heap[2] = temp;
    }
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    return 0;
}
