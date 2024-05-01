#include "reverse.h"
#include <iostream>
#include <fstream>

void generateReverseSortedNumbers() {
    // Open a file for writing
    std::ofstream outFile("reverse_sorted_numbers.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return;
    }

    // Generate and write 1000 reverse sorted elements to the file
    for(int i = 1000; i > 0; --i) {
        outFile << i << std::endl;
    }

    // Close the file
    outFile.close();

    std::cout << "Reverse sorted numbers generated and saved to 'reverse_sorted_numbers.txt'." << std::endl;
}
