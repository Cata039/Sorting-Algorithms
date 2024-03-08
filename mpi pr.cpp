/**#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Function to perform insertion sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    // Open the file
    ifstream inputFile("input.txt");
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

    // Display the unsorted elements
    cout << "Unsorted elements:" << endl;
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Perform insertion sort
    insertionSort(numbers);

    // Display the sorted elements
    cout << "Sorted elements:" << endl;
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/



/**#include <iostream>
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
}*/




/**#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

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

    // Sort the numbers using merge sort
    mergeSort(numbers, 0, numbers.size() - 1);

    // Display sorted numbers
    cout << "Sorted numbers: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
*/




/**#include <iostream>
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
*/




/**#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Function to partition the array and return the partitioning index
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform quick sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    // Sort the numbers using quick sort
    quickSort(numbers, 0, numbers.size() - 1);

    // Display sorted numbers
    cout << "Sorted numbers: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
*/



/*#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

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
        }
        else {
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

    // Sort the numbers using Timsort
    timsort(numbers);

    // Display sorted numbers
    cout << "Sorted numbers: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}*/


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono> // For timing

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
        }
        else {
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

int main() {
    vector<int> sizes = {100, 1000, 10000};
    for (int size : sizes) {
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

        // Resize the vector to the required size
        numbers.resize(size);

        // Measure execution time
        auto start = high_resolution_clock::now();
        // Sort the numbers using Timsort
        timsort(numbers);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        // Display execution time
        cout << "Execution time for " << size << " elements: " << duration.count() << " microseconds" << endl;
    }
    return 0;
}

