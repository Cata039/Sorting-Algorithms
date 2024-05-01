#include "random.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void generateRandomNumbers() {
    // Seed for random number generation
    srand(time(nullptr));

    // Open a file for writing
    std::ofstream outFile("random_numbers.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return;
    }

    // Generate and write 1000 random numbers to the file
    for(int i = 0; i < 1000; ++i) {
        outFile << rand() << std::endl;
    }

    // Close the file
    outFile.close();

    std::cout << "Random numbers generated and saved to 'random_numbers.txt'." << std::endl;
}
