#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void heapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void build_min_heap(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heap_sort(vector<int>& arr) {
    int n = arr.size();

    build_min_heap(arr);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> input;

    // Read input integers from binary file
    ifstream file("1.txt", ios::binary);

    if (file.is_open()) {
        int num;
        while (file.read((char*)&num, sizeof(num))) {
            input.push_back(num);
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
        return 0;
    }

    // Print input integers
    cout << "Input integers: ";
    print_vector(input);

    // Build min heap
    build_min_heap(input);

    // Print min heap
    cout << "Min-heap: ";
    print_vector(input);

    // Heap sort
    heap_sort(input);

    // Print sorted integers
    cout << "Sorted integers: ";
    print_vector(input);

    return 0;
}
