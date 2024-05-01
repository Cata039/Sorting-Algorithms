#include "almost.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void generateAlmostSortedNumbers() {
    // Seed for random number generation
    srand(time(nullptr));

    // Open a file for writing
    std::ofstream outFile("almost_sorted_numbers.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return;
    }

    int prev = rand() % 100; // Starting value
    outFile << prev << std::endl;

    // Generate and write 1000 almost sorted elements to the file
    for(int i = 1; i < 1000; ++i) {
        int offset = rand() % 10 - 5; // Generate an offset of -5 to +5
        prev += offset;
        outFile << prev << std::endl;
    }

    // Close the file
    outFile.close();

    std::cout << "Almost sorted numbers generated and saved to 'almost_sorted_numbers.txt'." << std::endl;
}
