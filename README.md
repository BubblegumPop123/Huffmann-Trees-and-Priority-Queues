# Huffmann-Trees-and-Priority-Queues
### Project Description and Guide

This project implements Huffman Coding for file compression. It includes reading a file, calculating the frequency of characters, building a Huffman Tree, generating Huffman codes for each character, and calculating the compression ratio. Below is a detailed description of the project file, along with instructions on how to compile and run the code.

### File Description

1. **huffman.cpp**
   - This file contains the implementation of the Huffman Coding algorithm. It reads the input file, calculates character frequencies, builds a Huffman Tree, generates Huffman codes for each character, and calculates the compression ratio.

### Compilation and Execution Guide

#### Prerequisites

- A C++ compiler (e.g., `g++`)

#### Steps to Compile and Run

1. **huffman.cpp**

   To compile and run `huffman.cpp`, use the following commands:

   ```sh
   g++ -o huffman huffman.cpp
   ./huffman
   ```

2. **Execution**

   When you run the program, it will prompt you to enter the filename to be compressed. Ensure that the file is in the same directory as the compiled program or provide the correct path to the file.

   ```sh
   Enter the filename to be compressed: example.txt
   ```

3. **Output**

   The program will output the frequency of each character, its corresponding Huffman code, and the calculated compression ratio.

### Example Output

```
Enter the filename to be compressed: example.txt
Character    Frequency    Huffman Code
a            10           110
b            15           111
c            30           10
...

Average Bit rate : 2.35
Compression Ratio : 3.40
```

### Benchmarking

The project does not include explicit benchmarking code, but you can measure the execution time and performance by using appropriate tools or adding timing code around key sections of the program. The compression ratio provides a measure of how effectively the Huffman Coding algorithm compresses the input file.

This guide should help understand, compile, run, and test the Huffman Coding project effectively. For any issues or further details, please refer to the provided comments and documentation within the code.
