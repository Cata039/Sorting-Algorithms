#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

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
    ifstream inputFile("input.txt"); // Open the input file
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

    // Display unsorted numbers
    cout << "Unsorted numbers: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    // Sort the numbers using bubble sort
    bubbleSort(numbers);

    // Display sorted numbers
    cout << "Sorted numbers: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
