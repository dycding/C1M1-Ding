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
 * @file stats.c 
 * @brief Function implementations for c1m1 assignment
 *
 *
 *
 * @author Yuchen Ding
 * @date 06/13/2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char median;
  unsigned char mean;
  unsigned char min;
  unsigned char max;

  /* Statistics and Printing Functions Go Here */
  printf("Original Array:\n");
  print_array(test, SIZE);
  printf("\n***********************************************\n");
  median = find_median(test, SIZE);
  mean = find_mean(test, SIZE);
  min = find_minimum(test, SIZE);
  max = find_maximum(test, SIZE);
  print_statistics(min, max, mean, median);
  printf("\n***********************************************\n");
  sort_array(test, SIZE);
  printf("Sorted Array (Descending):\n");
  print_array(test, SIZE);
}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char median) {
	printf("Data Array Statistics:\n");
	printf("Median:     %d\n", median);
	printf("Mean:       %d\n", mean);
	printf("Minimum:    %d\n", min);
	printf("Maximum:    %d\n", max);

}

void print_array(unsigned char *arr, unsigned int len) {
	// Declare a variable 'lb' to allow print line change
	unsigned char lb = 0;
	for (unsigned int i = 0; i < len; i++) {
		// print a maximum of 10 data per line
		if (lb >= 10) {
			printf("\n");
			lb = 0;
		}
		printf("%d\t", *(arr + i));
		lb++;
	}
	printf("\n");

}

unsigned char find_median(unsigned char *arr, unsigned int len) {
	// Eventhough in the main() function, the array is already sorted
	// before the function find_median. But in general, the array has
	// to be sorted first. We can use the sort_array function.
	sort_array(arr, len);
	// If the array length is odd, take the middle data
	if (len % 2 == 1) {
		return *(arr + len / 2);
	} else {
		// If the array length is even, take the avarage of the middle two values 
		// declare a float type variable to avoid overflow and integer division
		float median = (*(arr + len / 2 - 1) + *(arr + len / 2)) / 2.0;
		// return the value as the nearest integer
		return (unsigned char)(median + 0.5);
	}

}

unsigned char find_mean(unsigned char *arr, unsigned int len) {
	// declare a float type variable to avoid overflow and integer division
	float mean = 0.0;
	for (unsigned int i = 0; i < len; i++) {
		mean += *(arr + i);
	}
	mean /= len;
	// since the mean of the array may not be an integer
	// we round it to the nearest integer
	return (unsigned char)(mean + 0.5);

}

unsigned char find_maximum(unsigned char *arr, unsigned int len) {
	// For a sorted array (descending), maximum will be the first data
	// In general, assume an unsorted array
	unsigned char max = 0;
	for (unsigned int i = 0; i < len; i++) {
		if (*(arr + i) > max) {
			max = *(arr + i);
		}
	}
	return max;
}

unsigned char find_minimum(unsigned char *arr, unsigned int len) {
	// For a sorted array (descending), minimum will be the last data
	// Ingeneral, assume an unsorted array
	// Initialize min to the maximum allowed value for unsigned char type
	unsigned char min = 255;
	for (unsigned int i = 0; i < len; i++) {
		if (*(arr + i) < min) {
			min = *(arr + i);
		}
	}
	return min;
}

void sort_array(unsigned char *arr, unsigned int len) {
	// Using bubble sort algorithm here
	// Though other more efficient sorting algorithms can be used
	for (unsigned int i = 0; i < len - 1; i++) {
		for (unsigned int j = 0; j < len - i - 1; j++) {
			if (*(arr + j) < *(arr + j + 1)) {
				unsigned char temp = *(arr + j + 1);
				*(arr + j + 1) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
}
