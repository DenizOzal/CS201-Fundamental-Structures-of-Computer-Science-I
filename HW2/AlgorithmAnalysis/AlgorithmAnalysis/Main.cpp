#include "AlgorithmAnalysis.h"
#include <ctime>
#include <iostream>
#include <chrono>
using namespace std;

int main(){
	
	// AlgorithmAnalysis object
	AlgorithmAnalysis obj;

	// Index 0 for Linear Search Recursive
	int const index = 0;

	// Changing size in every programm running 10, 100, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 10000, 100000, 1000000, 10000000, 100000000 respectively
	// Linear Search Recursive does not work after size exceeding 4300
	int const size = 100000;

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
	// Testing Linear Iterative
	cout << "Testing Stage for Linear Search Iterative:\n" ;
	
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
	return 0;
}