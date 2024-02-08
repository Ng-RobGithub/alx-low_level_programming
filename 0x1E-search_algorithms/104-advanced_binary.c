#include "search_algos.h"

/**
 * advanced_binary_recursive - Recursive function to perform binary search
 * @array: Pointer to the first element of the array to search in
 * @left: Starting index of the subarray to search in
 * @right: Ending index of the subarray to search in
 * @value: Value to search for.
 *
 * Return:The index where value is located, or -1 if not found
 *
 * Description: Prints the [sub]array being searched after each change.
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	i = left + (right - left) / 2;
	if (array[i] == value && (i == left || array[i - 1] != value))
		return (i);
	if (array[i] >= value)
		return (advanced_binary_recursive(array, left, i, value));
	return (advanced_binary_recursive(array, i + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * using the Advanced Binary search algorithm
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array
 * @value: Value to search for.
 *
 * Return: The index where value is located, or -1 if not found
 *
 * Description: Prints the subarray being searched after each change.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
