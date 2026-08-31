g# FL-cs3360-HW2

## Overview
This project consists of two problems related to server failures and restoration times, implemented in C++. Each problem simulates different scenarios involving server operations.

## Problem 1: Server Failure Generation
- **File**: `generator.cpp`
- **Description**: This program generates failure times for a single server based on a specified Mean Time Between Failures (MTBF). It simulates server failures and the associated restoration times.

## Problem 2: System Failure Simulation
- **File**: `simulation.cpp`
- **Description**: This program simulates two servers and calculates the time until the whole computing system fails, which occurs when both servers are undergoing restoration simultaneously. It runs multiple simulations and computes the average failure time.

## Compilation Instructions
To compile the programs, you can use Xcode or run the following commands in the terminal:

1. Navigate to the respective problem directory:
   - For Problem 1:
     ```bash
     cd /path/to/FL-cs3360-HW2/Problem1
     ```
   - For Problem 2:
     ```bash
     cd /path/to/FL-cs3360-HW2/Problem2
     ```

2. Compile using g++:
   - For Problem 1:
     ```bash
     g++ generator.cpp -o generator
     ```
   - For Problem 2:
     ```bash
     g++ simulation.cpp -o simulation
     ```

## Running the Programs
After compilation, run the programs with the following commands:

- For Problem 1:
  ```bash
  ./generator
- For Problem 2:
  ```bash
  ./simulation
