# Sorting Algorithms and Performance Analysis

## Project Overview
This repository contains the implementation and analysis of various sorting algorithms as part of a research paper and project for the **MPI (Mathematical and Programming Insights)** course in the first year of the Computer Science program. The aim was to explore the theoretical and experimental performance of sorting algorithms across diverse scenarios, enhancing understanding of their strengths and weaknesses.

## Key Features
- **Sorting Algorithms Implemented:**
  - Bubble Sort
  - Insertion Sort
  - Selection Sort
  - Quick Sort
  - Heap Sort
  - Merge Sort
  - Radix Sort
- **Data Generation:**
  - Scripts for generating datasets of different sizes and characteristics:
    - Random elements
    - Almost sorted elements
    - Reverse sorted elements
- **Performance Analysis:**
  - Execution time recorded for each algorithm across datasets of varying sizes.
  - Results stored in CSV files for detailed comparative analysis.
  - Includes visualizations such as performance graphs.

## Repository Structure
- **`algorithms/`:** Contains the C++ implementation of sorting algorithms.
- **`datasets/`:** Pre-generated datasets categorized by size and type for testing.
- **`results/`:** CSV files with execution times recorded for all algorithms.
- **`Sorting_Algorithms.pdf`:** A comprehensive paper detailing:
  - Theoretical foundations
  - Experiment methodologies
  - Performance results and conclusions

## Paper Abstract
This paper explores the performance of sorting algorithms covered in the **MPI course**, analyzing them both theoretically and experimentally. It investigates the time complexity and execution times of algorithms such as Bubble Sort, Insertion Sort, Selection Sort, Quick Sort, Heap Sort, Radix Sort, and Merge Sort, providing insights into their suitability for different dataset types.

### Results Highlights
- **Radix Sort** consistently outperformed other algorithms for large datasets due to its linear time complexity.
- **Quick Sort** demonstrated efficient average-case performance across various dataset sizes.
- Simple algorithms like **Bubble Sort** and **Insertion Sort** proved inefficient for larger datasets.

## How to Use
1. **Clone the Repository:**
   ```bash
   git clone https://github.com/yourusername/Sorting-Algorithms.git
