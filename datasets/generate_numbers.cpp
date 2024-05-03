#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>

// Function to generate random numbers and write them to a file
void generateRandomNumbers(int count, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file '" << filename << "' for writing." << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 10000);

    for (int i = 0; i < count; ++i) {
        outFile << dist(gen) << std::endl;
    }

    outFile.close();
}

// Function to generate almost sorted numbers and write them to a file
void generateAlmostSortedNumbers(int count, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file '" << filename << "' for writing." << std::endl;
        return;
    }

    std::vector<int> numbers(count);
    std::iota(numbers.begin(), numbers.end(), 1); // Fill with 1, 2, 3, ..., count

    // Shuffle a portion of the numbers to make them almost sorted
    int shuffleSize = count / 10; // Shuffle 10% of the numbers
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(numbers.begin(), numbers.begin() + shuffleSize, gen);

    // Write numbers to the file
    for (int num : numbers) {
        outFile << num << std::endl;
    }

    outFile.close();
}

// Function to generate reverse sorted numbers and write them to a file
void generateReverseSortedNumbers(int count, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file '" << filename << "' for writing." << std::endl;
        return;
    }

    // Write numbers in reverse order
    for (int i = count; i >= 1; --i) {
        outFile << i << std::endl;
    }

    outFile.close();
}

int main() {
    const int count_100 = 10;
    generateRandomNumbers(count_100, "random_10.txt");
    generateAlmostSortedNumbers(count_100, "almost_10.txt");
    generateReverseSortedNumbers(count_100, "reverse_10.txt");

    std::cout << "Random numbers generated and saved to 'random_10.txt'." << std::endl;
    std::cout << "Almost sorted numbers generated and saved to 'almost_10.txt'." << std::endl;
    std::cout << "Reverse sorted numbers generated and saved to 'reverse_10.txt'." << std::endl;

    const int count_100 = 100;
    generateRandomNumbers(count_100, "random_100.txt");
    generateAlmostSortedNumbers(count_100, "almost_100.txt");
    generateReverseSortedNumbers(count_100, "reverse_100.txt");

    std::cout << "Random numbers generated and saved to 'random_100.txt'." << std::endl;
    std::cout << "Almost sorted numbers generated and saved to 'almost_100.txt'." << std::endl;
    std::cout << "Reverse sorted numbers generated and saved to 'reverse_100.txt'." << std::endl;

    /*const int count_500 = 500;
    generateRandomNumbers(count_500, "random_500.txt");
    generateAlmostSortedNumbers(count_500, "almost_500.txt");
    generateReverseSortedNumbers(count_500, "reverse_500.txt");

    std::cout << "Random numbers generated and saved to 'random_500.txt'." << std::endl;
    std::cout << "Almost sorted numbers generated and saved to 'almost_500.txt'." << std::endl;
    std::cout << "Reverse sorted numbers generated and saved to 'reverse_500.txt'." << std::endl;*/

    const int count_1000 = 1000;
    generateRandomNumbers(count_1000, "random_1000.txt");
    generateAlmostSortedNumbers(count_1000, "almost_1000.txt");
    generateReverseSortedNumbers(count_1000, "reverse_1000.txt");

    std::cout << "Random numbers generated and saved to 'random_1000.txt'." << std::endl;
    std::cout << "Almost sorted numbers generated and saved to 'almost_1000.txt'." << std::endl;
    std::cout << "Reverse sorted numbers generated and saved to 'reverse_1000.txt'." << std::endl;

    /*const int count_5000 = 5000;
    generateRandomNumbers(count_5000, "random_5000.txt");
    generateAlmostSortedNumbers(count_5000, "almost_5000.txt");
    generateReverseSortedNumbers(count_5000, "reverse_5000.txt");

    std::cout << "Random numbers generated and saved to 'random_5000.txt'." << std::endl;
    std::cout << "Almost sorted numbers generated and saved to 'almost_5000.txt'." << std::endl;
    std::cout << "Reverse sorted numbers generated and saved to 'reverse_5000.txt'." << std::endl;*/

    const int count_10000 = 10000;
    generateRandomNumbers(count_10000, "random_10000.txt");
    generateAlmostSortedNumbers(count_10000, "almost_10000.txt");
    generateReverseSortedNumbers(count_10000, "reverse_10000.txt");

    std::cout << "Random numbers generated and saved to 'random_10000.txt'." << std::endl;
    std::cout << "Almost sorted numbers generated and saved to 'almost_10000.txt'." << std::endl;
    std::cout << "Reverse sorted numbers generated and saved to 'reverse_10000.txt'." << std::endl;

    const int count_10000 = 100000;
    generateRandomNumbers(count_10000, "random_100000.txt");
    generateAlmostSortedNumbers(count_10000, "almost_100000.txt");
    generateReverseSortedNumbers(count_10000, "reverse_100000.txt");

    std::cout << "Random numbers generated and saved to 'random_100000.txt'." << std::endl;
    std::cout << "Almost sorted numbers generated and saved to 'almost_100000.txt'." << std::endl;
    std::cout << "Reverse sorted numbers generated and saved to 'reverse_100000.txt'." << std::endl;

    return 0;
}
