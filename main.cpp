#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>  // For formatting output

const int ARRAY_SIZE = 1024 * 256; // 256MB (~64 million elements)
const int NUM_TRIALS = 1000;

struct Node {
    Node* next;
};

void measure_access_time(int stride) {
    std::vector<Node> array(ARRAY_SIZE);

    // Link nodes with the given stride to prevent linear prefetching
    for (int i = 0; i < ARRAY_SIZE - stride; i += stride) {
        array[i].next = &array[i + stride];
    }

    // Manually close the loop to prevent out-of-bounds access
    array[ARRAY_SIZE - stride].next = &array[0];

    Node* current = &array[0];

    // Dummy variable to prevent compiler optimization
    volatile long long checksum = 0;

    auto start = std::chrono::steady_clock::now();

    // Repeat the loop multiple times for better timing resolution
    for (int trial = 0; trial < NUM_TRIALS; ++trial) {
        for (int i = 0; i < ARRAY_SIZE; ++i) {  // Iterate over all elements
            current = current->next;
            checksum += reinterpret_cast<long long>(current);  // Using the pointer to update checksum
        }
    }

    auto end = std::chrono::steady_clock::now();

    // Convert the duration from nanoseconds to milliseconds
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Printing the results in a compact table with stride and time side by side
    std::cout << "| " << std::setw(10) << stride << " | " << std::setw(16) << duration.count() << " |" << std::endl;
}

int main() {
    std::cout << "Access Time Measurements\n";
    
    // Print the header for the table
    std::cout << "+------------+------------------+" << std::endl;
    std::cout << "|   Stride   | Total Time (ms)  |" << std::endl;
    std::cout << "+------------+------------------+" << std::endl;

    // Loop through strides and print results in a compact way
    for (int stride = 1; stride <= 1024; stride *= 4) {
        measure_access_time(stride);
        std::cout << "+------------+------------------+" << std::endl;  // Row divider
    }

    return 0;
}
