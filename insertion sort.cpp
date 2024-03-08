#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Function to perform insertion sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    // Open the file
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Read elements from the file into a vector
    vector<int> numbers;
    string line;
    while (getline(inputFile, line)) {
        int num;
        stringstream ss(line);
        while (ss >> num) {
            numbers.push_back(num);
        }
    }
    inputFile.close();

    // Display the unsorted elements
    cout << "Unsorted elements:" << endl;
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Perform insertion sort
    insertionSort(numbers);

    // Display the sorted elements
    cout << "Sorted elements:" << endl;
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
