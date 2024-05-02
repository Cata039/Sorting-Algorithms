#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
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

    // Sort the numbers using merge sort
    mergeSort(numbers, 0, numbers.size() - 1);

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
    outputFile << "Merge Sort," << numbers.size() << "," << duration_ms << endl;
    outputFile.close();

    return 0;
}
