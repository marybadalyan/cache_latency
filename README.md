# Access Time Measurement Program

This program measures the access time for different stride sizes in a linked list. The primary goal is to assess how the time to access elements changes with varying stride sizes in a linked list data structure.

## Description

The program creates a linked list of nodes, where each node points to the next node, and the nodes are accessed in a loop with different stride values. The stride value determines the "step size" between nodes accessed in each iteration. By varying the stride size, we can observe the impact on the time taken to traverse the entire list.

The program runs multiple trials and reports the total time taken to access all elements for each stride size. The results are presented in a tabular format, showing the stride size and corresponding access time in milliseconds.

## Features

- **Stride Sizes**: The program tests different stride sizes ranging from 1 to 1024, incrementing by factors of 4.
- **Access Time Measurement**: It measures the total time taken to access all elements of the linked list for each stride size.
- **Formatted Output**: The results are printed in a clean and structured table format with clear row separators.
- **Performance Evaluation**: Useful for evaluating the effect of memory access patterns on performance.

## Build & Run
To clone and run this project, you'll need Git and CMake installed on your computer. From your command line:

# Clone this repository
```$ git clone https://github.com/marybadalyan/cache_latency```

# Go into the repository
```$ cd cache_latency```

# Generate the build files
```$ cmake -DCMAKE_BUILD_TYPE=Release -S . -B build```

# Build the project
```$ cmake --build build --config Release```

Then, run the executable generated in the build directory. Clone the repository:

Performance Benchmark
### Sample Output

```
Access Time Measurements
+------------+------------------+
|   Stride   | Total Time (ms)  |
+------------+------------------+
|          1 |              340 |
+------------+------------------+
|          4 |              316 |
+------------+------------------+
|         16 |              780 |
+------------+------------------+
|         64 |              952 |
+------------+------------------+
|        256 |             1721 |
+------------+------------------+
|       1024 |             3023 |
+------------+------------------+
```

## Explanation of the Output

- **Stride**: This represents the "step size" used to traverse the linked list. A stride of `1` means accessing each element sequentially, while larger strides jump over elements.
- **Total Time (ms)**: The time, in milliseconds, taken to traverse the entire linked list with the given stride size.

## How It Works

1. **Linked List Setup**: The program creates a vector of nodes. Each node points to the next node in the list, with the nodes linked according to the current stride size.
2. **Access Loop**: The program accesses all the elements in the list, starting from the first node and following the links. The access pattern depends on the stride.
3. **Time Measurement**: The time taken to access all nodes for each stride is measured using `chrono`. The program runs the access loop for multiple trials to get a stable measurement.
4. **Formatted Output**: The results are printed in a tabular format, where each row corresponds to a stride size and the time taken for that stride.

# Conclusion
This program provides valuable insight into how different stride sizes affect memory access time when traversing a linked list. By experimenting with various stride values, you can observe the impact of memory access patterns on performance. Understanding these access patterns is important for optimizing code, especially when working with large datasets or memory-intensive applications.
