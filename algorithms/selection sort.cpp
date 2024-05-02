#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(arr[i], arr[min_index]);
        }
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

    // Sort the numbers using selection sort
    selectionSort(numbers);

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
    outputFile << "Selection Sort," << numbers.size() << "," << duration_ms << endl;
    outputFile.close();

    return 0;
}
