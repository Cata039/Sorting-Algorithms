#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to get the maximum element from an array
int getMax(vector<int>& arr) {
    int max = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort based on a significant digit (d)
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n, 0);
    vector<int> count(10, 0);

    // Store count of occurrences in count[]
    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to the current digit
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// Function to perform radix sort
void radixSort(vector<int>& arr) {
    int max = getMax(arr);

    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
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

    // Sort the numbers using radix sort
    radixSort(numbers);

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
    outputFile << "Radix Sort," << numbers.size() << "," << duration_ms << endl;
    outputFile.close();

    return 0;
}
