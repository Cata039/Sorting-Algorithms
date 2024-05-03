#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
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
vector<string> fileNames = {"random_10.txt","random_100.txt", "random_1000.txt","random_10000.txt","random_100000.txt",
                                "almost_10.txt", "almost_100.txt", "almost_1000.txt","almost_10000.txt","almost_100000.txt",
                                "reverse_10.txt", "reverse_100.txt", "reverse_1000.txt","reverse_10000.txt","reverse_100000.txt"};

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

        // Sort the numbers using heap sort
        heapSort(numbers);

        // Record the ending time
        auto stop = high_resolution_clock::now();

        // Calculate the execution time in seconds
        auto duration_seconds = duration<double>(stop - start).count();

        // Get the dataset name
        string datasetName = getDatasetName(fileName);

        // Write the results to the output CSV file
        outputFile << datasetName << ","
                   << "Heap Sort," << numbers.size() << "," << fixed << setprecision(6) << duration_seconds << endl;
    }

    // Close the output CSV file
    outputFile.close();

    cout << "Output has been appended to output.csv" << endl;

    return 0;
}
