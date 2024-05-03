#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
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

        // Sort the numbers using insertion sort
        insertionSort(numbers);

        // Record the ending time
        auto stop = high_resolution_clock::now();

        // Calculate the execution time in seconds
        auto duration_seconds = duration<double>(stop - start).count();

        // Get the dataset name
        string datasetName = getDatasetName(fileName);

        // Write the results to the output CSV file
        outputFile << datasetName << ","
                   << "Insertion Sort," << numbers.size() << "," << fixed << setprecision(6) << duration_seconds << endl;
    }

    // Close the output CSV file
    outputFile.close();

    cout << "Output has been appended to output.csv" << endl;

    return 0;
}
