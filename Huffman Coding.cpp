#include <iostream>
#include <algorithm>
using namespace std;

struct MinHeapNode {
    char data;
    unsigned freq;
    MinHeapNode* left, *right;
    MinHeapNode(char data, unsigned freq) {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct MinHeap {
    MinHeapNode** array;
    int capacity;
    int size;
    MinHeap(int capacity) {
        this->capacity = capacity;
        size = 0;
        array = new MinHeapNode* [capacity];
    }
    void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
        MinHeapNode* t = *a;
        *a = *b;
        *b = t;
    }
    void minHeapify(int idx) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        if (left < size && array[left]->freq < array[smallest]->freq)
            smallest = left;
        if (right < size && array[right]->freq < array[smallest]->freq)
            smallest = right;
        if (smallest != idx) {
            swapMinHeapNode(&array[idx], &array[smallest]);
            minHeapify(smallest);
        }
    }
    bool isSizeOne() {
        return (size == 1);
    }
    MinHeapNode* extractMin() {
        MinHeapNode* temp = array[0];
        array[0] = array[size - 1];
        size--;
        minHeapify(0);
        return temp;
    }
    void insertMinHeap(MinHeapNode* minHeapNode) {
        size++;
        int i = size - 1;
        while (i && minHeapNode->freq < array[(i - 1) / 2]->freq) {
            array[i] = array[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        array[i] = minHeapNode;
    }
};

void printCodes(MinHeapNode* root, string str) {
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size) {

    MinHeap* minHeap = new MinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->insertMinHeap(new MinHeapNode(data[i], freq[i]));

    while (!minHeap->isSizeOne()) {
        MinHeapNode* left = minHeap->extractMin();
        MinHeapNode* right = minHeap->extractMin();
        MinHeapNode* top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap->insertMinHeap(top);
    }

    printCodes(minHeap->array[0], "");
}

int main() {
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 45, 13, 12, 16, 9, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}
