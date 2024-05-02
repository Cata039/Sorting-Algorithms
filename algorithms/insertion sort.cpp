#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to perform insertion sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    // Open the file
    ifstream inputFile("reverse_100000.txt");
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

    // Record the starting time
    auto start = high_resolution_clock::now();

    // Perform insertion sort
    insertionSort(numbers);

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
    outputFile << "Insertion Sort," << numbers.size() << "," << duration_ms << endl;
    outputFile.close();

    return 0;
}
