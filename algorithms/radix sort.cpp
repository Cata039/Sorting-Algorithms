#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Get the maximum element from the array
int getMax(vector<int>& arr) {
    int max = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting sort of arr[] based on the digit represented by exp.
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n), count(10, 0);

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix sort
void radixSort(vector<int>& arr) {
    int max = getMax(arr);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

string getDatasetName(const string& fileName) {
    if (fileName.find("random") != string::npos) {
        return "random";
    } else if (fileName.find("almost") != string::npos) {
        return "almost";
    } else if (fileName.find("reverse") != string::npos) {
        return "reverse";
    }
    return "";
}

int main() {
    // Define dataset file names
    vector<string> fileNames = {"random_1000.txt", "random_10000.txt", "random_100000.txt",
                                "almost_1000.txt", "almost_10000.txt", "almost_100000.txt",
                                "reverse_1000.txt", "reverse_10000.txt", "reverse_100000.txt"};

    // Open the output CSV file in append mode
    ofstream outputFile("output.csv", ios::app);
    if (!outputFile) {
        cerr << "Failed to open output file." << endl;
        return 1;
    }

    // Iterate through each dataset
    for (const string& fileName : fileNames) {
        // Open the input file
        ifstream inputFile(fileName);
        if (!inputFile) {
            cerr << "Failed to open input file: " << fileName << endl;
            return 1;
        }

        // Read the numbers from the file
        vector<int> numbers;
        int num;
        while (inputFile >> num) {
            numbers.push_back(num);
        }
        inputFile.close(); // Close the input file

        // Record the starting time
        auto start = high_resolution_clock::now();

        // Sort the numbers using radix sort
        radixSort(numbers);

        // Record the ending time
        auto stop = high_resolution_clock::now();

        // Calculate the execution time in seconds
        auto duration_seconds = duration<double>(stop - start).count();

        // Get the dataset name
        string datasetName = getDatasetName(fileName);

        // Write the results to the output CSV file
        outputFile << datasetName << ","
                   << "Radix Sort," << numbers.size() << "," << fixed << setprecision(6) << duration_seconds << endl;
    }

    // Close the output CSV file
    outputFile.close();

    cout << "Output has been appended to output_1000.csv" << endl;

    return 0;
}
