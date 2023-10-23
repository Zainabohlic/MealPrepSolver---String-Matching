# Meal Preparation Solver

## Table of Contents
1. [Introduction](#introduction)
2. [Algorithm](#algorithm)
3. [Running the Program](#running-the-program)
4. [Time and Space Complexity](#time-and-space-complexity)
5. [Test Cases](#test-cases)
6. [Conclusion](#conclusion)

## Introduction
This C++ program, named "Meal Preparation Solver," is designed to check if you have enough ingredients to prepare multiple dishes for a meal. Each dish consists of a list of required ingredients. The ingredients are grouped into sets, and you must determine if you can select n disjoint subarrays from a given list of ingredients, with each subarray corresponding to a group of ingredients required for a specific dish.

## Algorithm
The program follows the following algorithm to solve the problem:

1. Read the list of groups and the list of ingredients from an input file.
2. For each group of ingredients and each list of ingredients, check if it's possible to select n disjoint subarrays, where n is the number of groups.
3. Determine if the subarrays can be selected without using the same ingredient for multiple dishes.
4. Print "true" if it's possible to prepare all the dishes; otherwise, print "false."

## Running the Program
To run the program:

1. Compile the source code using a C++ compiler (e.g., g++).
2. Prepare an input file, "p1_input.txt," containing the list of groups and ingredients.
3. Run the compiled executable.
4. Choose the test case number (1-5) when prompted.
5. The program will display whether you can make the meal with the given ingredients.

## Time and Space Complexity
The time complexity of the program is O(N*M) in the worst case, where N is the total number of ingredients, and M is the number of groups or dishes. The program iterates over both lists to find matching subarrays.

The space complexity of the program is O(N+M) due to the data structures used for storing ingredients and groups.

## Test Cases
The program supports multiple test cases, and it can handle different numbers of dishes and ingredients. Here are the provided test cases:

1. Test case 1: Sample test case with a positive outcome.
2. Test case 2: Another positive test case.
3. Test case 3: A test case with insufficient ingredients.
4. Test case 4: A test case with overlapping ingredients.
5. Test case 5: A test case with missing ingredients.

## Conclusion
The "Meal Preparation Solver" program efficiently solves the problem of preparing multiple dishes while considering ingredient availability. By selecting the appropriate test case, you can determine if you have enough ingredients to prepare the desired meal. The algorithm is flexible and can handle various scenarios with ease.
