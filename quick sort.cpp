#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Function to partition the array and return the partitioning index
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform quick sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    ifstream inputFile("input.txt"); // Open the input file
    if (!inputFile) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    vector<int> numbers;
    int num;
    string line;

    // Read the numbers from the file
    while (getline(inputFile, line)) {
        istringstream iss(line);
        while (iss >> num) {
            numbers.push_back(num);
        }
    }
    inputFile.close(); // Close the input file

    // Display unsorted numbers
    cout << "Unsorted numbers: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    // Sort the numbers using quick sort
    quickSort(numbers, 0, numbers.size() - 1);

    // Display sorted numbers
    cout << "Sorted numbers: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
