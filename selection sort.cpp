#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

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

    // Sort the numbers using selection sort
    selectionSort(numbers);

    // Display sorted numbers
    cout << "Sorted numbers: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
