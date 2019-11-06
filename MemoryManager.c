#include <stdio.h>
#include <stdlib.h>

/**
 * Compares two numbers and returns a positive integer, 0 or 
 * a negative integer if the first number is greater than, equal to
 * or less than the second number.
 * Assumes the numbers are of the type int.
 * Used when invoking the quicksort function.  
 */
int compare (const void * a, const void * b)
{
   return (*(int*)a - *(int*)b);
}


/**
 * Takes in an array of integers and the number of elements in the array 
 * as arguments.
 * Then it will sort and return the median of the sorted array. 
 * To keep things simple, it always returns
 * the element at index arr_size/2 even though the 
 * array size is even.
 */
int return_median(int *arr, int size)
{
   qsort(arr, size, sizeof(int), compare);
   return arr[size/2];
}


/**
 * Takes in a random number and maps it to the
 * range [100000 - 120000)
 */
int get_iteration_count(int rand)
{
    return (rand % 20000) + 100000;     
}

/**
 * Takes in a random number and maps it to the 
 * range [1000 - 1500)
 */
int get_arr_size(int rand)
{
    return (rand % 500) + 1000;
}


/**
 * This is the method that you need to implement.
 * Implement the following steps in the given order.
 *
 *  1. Generate the number of iterations
 *      - Generate a random number. Map it to the range [100000 - 120000) using the 
 *      utility function 'get_iteration_count'.
 */


/*
 * 2. For each iteration:
 *      2.a Generate an array size - Generate a random number and map it to the range [1000 - 1500) using
 *          the utility function 'get_arr_size'.
 * 
 *      2.b Allocate memory for the array in the heap.
 *
 *      2.c Populate the array with random numbers.
 *
 *      2.d Get the median of the array using the function 'return_median'.
 *
 *      2.e Check if the median is divisible by 13.
 *
 *      2.f Return the number of medians that were divisible by 13.
 *
 */
int get_running_count()
{
    // TODO: Implement this method.
	int iteration = 0;
	int size = 0;
	int *array = NULL;
    int median = 0;
	int count = 0;
    int target = 13;

	iteration = get_iteration_count(rand());
	printf("[MemoryManager] Number of Iterations: %d\n", iteration); // print target size

	for (int i = 0; i < iteration; i++) {
		//use the random number generator to compute the size of the array that must be allocated
		//The array size should be between 1000(inclusive) and 1500(exclusive).
		size = get_arr_size(rand());
		//The array should be allocated in the heap
		array = (int *)malloc(sizeof(int) * size);
		
		// If it is a dynamically allocated array, you cannot find its size at run-time
		// Here you see the dangers of C : a ptr just points to memory and has no way of knowing
		// what supposed size is.You can just increment and increment and the OS might complain 
		// eventually, or you crash your program, or corrupt other ones.You should always specify 
		// the size, and check bounds yourself!
	//	printf("Length Target: %d", ??????); // print array length
	//	printf("\n");
			
		// use the random number generator to populate each element of the array
		for (int i = 0; i < size; i++) {
			array[i] = rand();
		}

		//This array is then sorted so that the numbers are in ascending order	
		//The median element of the array is retrieved.
		median = return_median(array, size);

		//Next, you must check if this median element is divisible by 13. If it is, you must increment the
		//running count of such values by 1.
		if (median % 13 == 0) {
				count++;
		}
		// Free array for reuse, no deconstructors ranin C
		free(array);
	}

	
	// Return the number of medians that were divisible by 13
	return count;
}
