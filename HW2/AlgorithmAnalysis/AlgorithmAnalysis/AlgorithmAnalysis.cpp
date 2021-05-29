#include "AlgorithmAnalysis.h"
#include <math.h>
#include <algorithm>
#include <iostream>
// 1
int AlgorithmAnalysis::linearSearchIterative(int* arr, int N, int value) {
	for (int i = 0; i < N; i++) {
		if (arr[i] == value)
			return i;
	}
	return -1;
}

// 2
int AlgorithmAnalysis::linearSearchRecursive(int* arr, int N, int index, int value) {
	// Base Case
	if (index == N) {
		return -1;
	}
	// Check the value
	if (arr[index] == value) {
		return index;
	}
	return linearSearchRecursive(arr, N, index + 1, value);
}


// 3
int AlgorithmAnalysis::binarySearch(int* arr, int N, int value) {
	int low = 0, high = N - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] < value)
			low = mid + 1;
		else if (arr[mid] > value)
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}

// 4
int AlgorithmAnalysis::jumpSearch(int* arr, int N, int value) {
	int prev = 0;
	int current = sqrt(N);

	while (arr[std::min(current, N) - 1] < value) {
		prev = current;
		current += sqrt(N);
		if (prev >= N)
			return -1;
	}

	while (arr[prev] < value) {
		prev++;
		if (prev == std::min(current, N))
			return -1;
	}

	if (arr[prev] == value)
		return prev;
	return -1;
}