// Copyright (c) 2025 Atri Sarker All rights reserved.
// .
// Created By: Atri S
// Date: May 22, 2025
// Program that generates a random list of random numbers.
// It then displays the smallest value in the list. [using a function]

#include <array>
#include <cstdio>
#include <iostream>
#include <random>

// Function that returns the smallest value in an array of integers
template <size_t N>
int FindMinValue(std::array<int, N> targetList) {
    // Initialize a variable to hold the smallest number
    int currentSmallestValue = targetList[0];
    // Loop through every number in the array
    for (int number : targetList) {
        // Check if the number is smaller than the current smallest value
        if (number < currentSmallestValue) {
            // If so, the number becomes the new current smallest value
            currentSmallestValue = number;
        }
    }
    // Return the value that survived
    return currentSmallestValue;
}

int main() {
    // DECLARE CONSTANTS
    const int MAX_ARRAY_SIZE = 10;
    const int MIN_NUM = 0;
    const int MAX_NUM = 100;
    // Initialize an empty array
    std::array<int, MAX_ARRAY_SIZE> listOfInt;
    // RANDOM SEED
    std::random_device seed;
    // MERSENNE TWISTER
    std::mt19937 mt(seed());
    // Distribution that will return a random number between
    // MIN_NUM AND MAX_NUM [INCLUSIVE] when called with the mersenne twister.
    std::uniform_int_distribution<int> GenerateRandNum(MIN_NUM, MAX_NUM);
    // Fill the list up with random numbers
    for (int index = 0; index < MAX_ARRAY_SIZE; index++) {
        // Generate a random integer between MIN_NUM AND MAX_NUM
        int randomNumber = GenerateRandNum(mt);
        // Place the random number inside the array
        listOfInt[index] = randomNumber;
        // Display the list operation
        printf("%i added to the list at position %i.\n", randomNumber, index);
    }

    // Call FindMinValue()
    int smallestValue = FindMinValue(listOfInt);
    // Display the min value
    printf("\nThe min value is %i\n", smallestValue);
}
