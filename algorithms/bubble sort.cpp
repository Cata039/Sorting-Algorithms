#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    // Open the input file
    ifstream inputFile("reverse_100000.txt");
    if (!inputFile) {
        cerr << "Failed to open input file." << endl;
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

    // Sort the numbers using bubble sort
    bubbleSort(numbers);

    // Record the ending time
    auto stop = high_resolution_clock::now();

    // Calculate the execution time in seconds
    auto duration_seconds = duration<double>(stop - start).count();

    // Read the existing data from the CSV file
    vector<string> csvData;
    ifstream csvFile("output.csv");
    if (csvFile) {
        string line;
        while (getline(csvFile, line)) {
            csvData.push_back(line);
        }
        csvFile.close(); // Close the CSV file
    }

    // Update the execution time in the CSV data
    bool updated = false;
    for (auto& data : csvData) {
        if (data.find("Bubble Sort") != string::npos) {
            data = "Bubble Sort," + to_string(numbers.size()) + "," + to_string(duration_seconds);
            updated = true;
            break;
        }
    }

    // If the data wasn't updated, add it to the CSV data
    if (!updated) {
        csvData.push_back("Bubble Sort," + to_string(numbers.size()) + "," + to_string(duration_seconds));
    }

    // Write the updated data back to the CSV file
    ofstream outputFile("output_100000.csv");
    if (!outputFile) {
        cerr << "Failed to open output file." << endl;
        return 1;
    }
    for (const string& data : csvData) {
        outputFile << data << endl;
    }
    outputFile.close();

    return 0;
}
