#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Merge function used in Timsort
void merge(vector<int>& arr, int l, int m, int r) {
    int len1 = m - l + 1;
    int len2 = r - m;
    vector<int> left(len1), right(len2);

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < len2; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < len1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < len2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Insertion sort used in Timsort
void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Timsort function
void timsort(vector<int>& arr) {
    int n = arr.size();
    const int RUN = 32;
    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, min((i + RUN - 1), (n - 1)));

    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            if (mid < right)
                merge(arr, left, mid, right);
        }
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

        // Sort the numbers using Timsort
        timsort(numbers);

        // Record the ending time
        auto stop = high_resolution_clock::now();

        // Calculate the execution time in seconds
        auto duration_seconds = duration<double>(stop - start).count();

        // Get the dataset name
        string datasetName = getDatasetName(fileName);

        // Write the results to the output CSV file
        outputFile << datasetName << ","
                   << "Timsort," << numbers.size() << "," << fixed << setprecision(6) << duration_seconds << endl;
    }

    // Close the output CSV file
    outputFile.close();

    cout << "Output has been appended to output.csv" << endl;

    return 0;
}
