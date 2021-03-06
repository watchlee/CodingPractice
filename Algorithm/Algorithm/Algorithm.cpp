// Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include<random>

#include "sorting.h"
using namespace std;
using namespace std::chrono;
#define SHOW_RESULT

void timer_record(int);

//TIMER
static high_resolution_clock::time_point start;// = high_resolution_clock::now();
static high_resolution_clock::time_point stop;// = high_resolution_clock::now();
void timer_record(int option) {
	switch (option) {
		case 1:
			start = high_resolution_clock::now();
			break;
		case 2:
			stop = high_resolution_clock::now();
			duration<double> time_span = duration_cast<duration<double>>(stop - start);
			cout << "Times :\t" << time_span.count() << "\tseconds"<<endl;
			break;
	}
}

//--------------------------------------------------------------------------------//


void printArray(vector<int> array) {
	for ( vector<int>::iterator iter = array.begin(); iter!=array.end(); ++iter )
		cout << *iter << " ";
	cout << endl;
}



//reference book C++ Primer
vector<int> get_randVec()
{
	// because engines and distributions retain state, they usually should be
	// defined as static so that new numbers are generated on each call
	// using time(0), which returns time can cause the program get different sequence each time
	static default_random_engine e(time(0));
	uniform_int_distribution<unsigned> n(0, 20);
	unsigned int times = n(e);
	static uniform_int_distribution<int> u(-10000, 10000);
	vector<int> ret;
	for (size_t i = 0; i < times; ++i)
		ret.push_back(u(e));
	return ret;
}

//using STL to shuffle the vector
void Shuffle(vector<int>& array) {
	random_shuffle(array.begin(), array.end());
	cout << "After shuffled" << endl;
	printArray(array);
}

void mergeSortWay(std::vector<int> array) {
	//using call by reference to process array by the called function
	Shuffle(array);
	cout << "mergeSort result" << endl;
	timer_record(1);
	mergeSort(array, 0, array.size());

	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}

void quickSortWay(std::vector<int> array) {
	Shuffle(array);
	cout << "quickSort result" << endl;
	//quickSort(array, 0, array.size() - 1);
	timer_record(1);
	quickSort2(array, 0, array.size() );
	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}

void ShellSortWay(std::vector<int> array) {
	Shuffle(array);
	cout << "shellsort result" << endl;
	//quickSort(array, 0, array.size() - 1);
	timer_record(1);
	shellSort(array);
	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}

void InsertionSortWay(std::vector<int> array) {
	Shuffle(array);
	cout << "InsertionSort result" << endl;
	//quickSort(array, 0, array.size() - 1);
	timer_record(1);
	insertionSort(array);
	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}

void SelectionSortWay(std::vector<int> array) {
	Shuffle(array);
	cout << "selection sort result" << endl;
	//quickSort(array, 0, array.size() - 1);
	timer_record(1);
	selectionSort(array);
	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}

/* example
void algorithmWay(std::vector<int> array ) {
	cout << "xxxx sort result" << endl;
	timer_record(1);
	timer_record(2);
#ifdef SHOW_RESULT
	printArray(array);
	fgetc(stdin);
#endif
}
*/


void BubbleSortWay(std::vector<int> array) {
	Shuffle(array);
	cout << "bubble sort result" << endl;
	//quickSort(array, 0, array.size() - 1);
	timer_record(1);
	bubbleSort(array);
	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}



void Sorting_run() {
	
	vector<int> array = get_randVec();
	cout << "Original Order: " << endl;
	printArray(array);
	cout << endl;

	BubbleSortWay(array);

	SelectionSortWay(array);

	ShellSortWay(array);

	InsertionSortWay( array);

	mergeSortWay(array);

	quickSortWay(array);
}
int main()
{

	/*Todo:
		1.Replace <int> to T
		2.Added feature StdRandom.shuffle 
	*/
	
	
	Sorting_run();
	cout << "Done" << endl;
	fgetc(stdin);
    return 0;
}

