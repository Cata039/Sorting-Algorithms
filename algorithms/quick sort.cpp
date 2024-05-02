#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
    ifstream inputFile("reverse_100000.txt"); // Open the input file
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

    // Record the starting time
    auto start = high_resolution_clock::now();

    // Sort the numbers using quick sort
    quickSort(numbers, 0, numbers.size() - 1);

    // Record the ending time
    auto stop = high_resolution_clock::now();

    // Calculate the execution time in milliseconds
    auto duration_ms = duration_cast<milliseconds>(stop - start).count() / 1000.0;

    // Write the results to the output CSV file
    ofstream outputFile("output_100000.csv", ios::app);
    if (!outputFile) {
        cerr << "Failed to open output file." << endl;
        return 1;
    }
    // Write the execution time without a header
    outputFile << "Quick Sort," << numbers.size() << "," << duration_ms << endl;
    outputFile.close();

    return 0;
}
