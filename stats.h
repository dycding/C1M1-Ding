/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief Macros, declarations and documentations for the c1m1 assignment 
 *
 *
 *
 * @author Yuchen Ding
 * @date 06/13/2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Prints the statistics of an array
 *
 * This function takes the statistical results
 * (minimum, maximum, mean, and median) on the given array
 * as inputs and prints out those values to the screen
 * 
 * @param min The minimum value of the array
 * @param max The maximum value of the array
 * @param mean The mean of the array
 * @param median The median of the array
 *
 * @return void
 */
void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char median);


/**
 * @brief Print the array to the screen
 *
 * This function takes an array of data and a length
 * as inputs and prints the array to the screen
 *
 * @param arr The array of data
 * @param len The length of the array
 *
 * @return void
 */
void print_array(unsigned char* arr, unsigned int len);


/**
 * @brief Find the median of a given array
 * 
 * This function takes an array of data and a length
 * as inputs and returns the median value
 *
 * @param arr The array of data
 * @param len The length of the array
 *
 * @return The median of a given array
 */
unsigned char find_median(unsigned char* arr, unsigned int len);


/**
 * @brief Find the mean of a given array
 *
 * This function takes an array of data and a length
 * as inputs and returns the mean value
 *
 * @param arr The array of data
 * @param len The length of the array
 *
 * @return The mean of a given array
 */
unsigned char find_mean(unsigned char* arr, unsigned int len);


/**
 * @brief Find the maximum value of a given array
 *
 * This function takes an array of data and a length
 * as inputs and returns the maximum value
 *
 * @param arr The array of data
 * @param len The length of the array
 *
 * @return The maximum of a given array
 */
unsigned char find_maximum(unsigned char* arr, unsigned int len);


/**
 * @brief Find the minimum value of a given array
 *
 * This function takes an array of data and a length
 * as inputs and returns the minimum value
 *
 * @param arr The array of data
 * @param len The length of the array
 *
 * @return The minimum of a given array
 */
unsigned char find_minimum(unsigned char* arr, unsigned int len);


/**
 * @brief Sort the array in descending order
 *
 * This function takes an array of data and a length
 * as inputs and returns the sorted array with data from largest to smallest
 *
 * @param arr The array of data
 * @param len The length of the array
 *
 * @return void
 */
void sort_array(unsigned char* arr, unsigned int len);

#endif /* __STATS_H__ */
