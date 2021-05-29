// Deniz Semih Özal
// 21802414
// Version: 10/04/2021
// All solutions and test stages are in the same class
#include <ctime>
#include <iostream>
#include <chrono>
#include <math.h>
using namespace std;
#pragma once
class AlgorithmAnalysis
{
public:
	int linearSearchIterative(int* arr, int N, int value);
	int linearSearchRecursive(int* arr, int N, int index, int value);
	int binarySearch(int* arr, int N, int value);
	int jumpSearch(int* arr, int N, int value);
};

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
int main() {

	// AlgorithmAnalysis object
	AlgorithmAnalysis obj;

	// Index 0 for Linear Search Recursive
	int const index = 0;

	// Changing size in every programm running 10, 100, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 10000, 100000, 1000000, 10000000, 100000000 respectively
	// Linear Search Recursive does not work after size exceeding 4300
	int const size = 1000;

	// Creating dynamically allocated array
	int* array = new int[size];

	// Sorted array with desired size in ascending order
	for (int i = 0; i < size; i++) {
		array[i] = (i * 10) + (rand() % (((i + 1) * 10) - (i * 10) + 1));
	}
	// First Item
	int key_low = array[0];

	// Middle Item
	int key_mid = array[size / 2];

	// Last Item
	int key_end = array[size - 1];

	// Item that is not available
	int key_wrong = -1;
	cout << endl;
	cout << endl;

	cout << "******************************\n";
	// Testing Linear Search Iterative
	cout << "Testing Stage for Linear Search Iterative:\n";

	// Array with Size
	cout << "Array with Size " << size << "\n";

	//Declare necessary variables
	std::chrono::time_point< std::chrono::system_clock > startTime;
	std::chrono::duration< double, milli > elapsedTime;
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.linearSearchIterative(array, size, key_low);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key Begin: " << key_low << "\n";

	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.linearSearchIterative(array, size, key_mid);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key Mid: " << key_mid << "\n";


	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.linearSearchIterative(array, size, key_end);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key End: " << key_end << "\n";

	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.linearSearchIterative(array, size, key_wrong);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key not available: " << key_wrong << "\n\n";

	// Testing Linear Search Recursive
	cout << "Testing Stage for Linear Search recursive:\n";

	// Array with Size
	cout << "Array with Size " << size << "\n";

	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.linearSearchRecursive(array, size, index, key_low);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key Begin: " << key_low << "\n";

	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.linearSearchRecursive(array, size, index, key_mid);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key Mid: " << key_mid << "\n";


	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.linearSearchRecursive(array, size, index, key_end);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key End: " << key_end << "\n";

	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.linearSearchRecursive(array, size, index, key_wrong);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key not available: " << key_wrong << "\n\n";


	// Testing Binary Search
	cout << "Testing Stage for Binary Search:\n";

	// Array with Size
	cout << "Array with Size " << size << "\n";

	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.binarySearch(array, size, key_low);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key Begin: " << key_low << "\n";

	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.binarySearch(array, size, key_mid);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key Mid: " << key_mid << "\n";


	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.binarySearch(array, size, key_end);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key End: " << key_end << "\n";

	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.binarySearch(array, size, key_wrong);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key not available: " << key_wrong << "\n\n";



	// Testing Jump Search
	cout << "Testing Stage for Jump Search:\n";

	// Array with Size
	cout << "Array with Size " << size << "\n";

	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.jumpSearch(array, size, key_low);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key Begin: " << key_low << "\n";

	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.jumpSearch(array, size, key_mid);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key Mid: " << key_mid << "\n";


	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.jumpSearch(array, size, key_end);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key End: " << key_end << "\n";

	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	obj.jumpSearch(array, size, key_wrong);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	cout << "Key not available: " << key_wrong << "\n\n";

	delete[] array;
	cout << "******************************\n";
	return 0;
}
