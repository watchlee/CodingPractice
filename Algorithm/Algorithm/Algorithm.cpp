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
using namespace std;
using namespace std::chrono;
#define SHOW_RESULT

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

void shellSort(vector<int> array) {
	cout << "Shell Sort result" << endl;
	//Stuck	
	timer_record(1);
	int N = array.size();
	int h = 1;
	while (h < (N / 3))
		h = 3 * h + 1;
	while (h >= 1) {
		for (int i = h; i < N; i++) {
			for (int j = i; j >=h && array[j] < array[j - h]; j -= h) {
				int temp = array[j];
				array[j] = array[j - h];
				array[j - h] = temp;
			}
		}
		h = h / 3;
	}

	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif

}

void insertionSort(vector<int> array) {
	cout << "InsertionSort result" << endl;
	timer_record(1);
	for (int UnsortedIndex = 1; UnsortedIndex < array.size(); UnsortedIndex++) {
		int SortedIndex = 0;
		
		
		/*int temp = array[UnsortedIndex];
		for (SortedIndex = UnsortedIndex; SortedIndex > 0 && array[SortedIndex- 1] > temp; SortedIndex--)
			array[SortedIndex] = array[SortedIndex - 1];
		array[SortedIndex] = temp;
		*/

		for (SortedIndex = UnsortedIndex; SortedIndex > 0 && array[SortedIndex] < array[SortedIndex - 1]; SortedIndex--) {
			int temp = array[SortedIndex];
			array[SortedIndex] = array[SortedIndex - 1];
			array[SortedIndex - 1] = temp;
		}


	}

	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}

void merge(vector<int> &array, int start, int middle, int end) {
	//what the heck is it?
	if (array[middle - 1] <= array[middle])
		return;

	int i = start;
	int j = middle;
	int tempindex = 0;

	vector<int> temp;
	//merge two blocks to one
	while (i < middle && j < end) {
		//compare tow blocks, determine which block's element is small and put it into vector 
		temp.push_back(array[i] <= array[j] ? array[i++] : array[j++]);
		tempindex++;
	}

	//after combined, copy temp data to original array
	int temp_des = start + tempindex, temp_source = i;
	for (int times = 0; times < (middle - i); times++)
	{
		array[temp_des++] = array[temp_source++];
	}

	temp_des = start;
	for (int times = 0; times < tempindex; times++) {
		array[temp_des++] = temp[times];
	}


}

void mergeSort(vector<int> &array, int start, int end) {
	if ( ( end - start ) < 2) // while only one element need to sort, stop!
		return;
	//using divide and conquer algorithm to solve the probelm
	int middle = (start + end) / 2;
	//keep dividing until only one element
	mergeSort( array, start, middle);
	mergeSort(array, middle, end);
	merge(array, start, middle, end);
}

void mergeSortWay(vector<int> array) {
	//using call by reference to process array by the called function
	cout << "mergeSort result" << endl;
	timer_record(1);
	mergeSort(array, 0, array.size());

	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}

int min(int x, int y) {
	return x < y ? x : y;
}

void mergeSort_iteration(vector<int> array) {
	cout << "mergeSort iteration result" << endl;

	int start1, end1, start2, end2;
	vector<int> temp;
	timer_record(1);
	for (int times = 1; times < array.size(); times = 2 * times) {
		for (int offset = 0; offset < array.size(); offset += 2 * times) {
			start1 = offset;
			end1 = min(offset + times, array.size());
			start2 = end1;
			end2 = min(offset + (times * 2), array.size());
			while (start1 < end1 && start2 < end2)
				temp.push_back(array[start1] < array[start2] ? array[start1++] : array[start2++]);
			//put remain elements into temp array
			while (start1 < end1)
				temp.push_back(array[start1++]);
			while (start2 < end2)
				temp.push_back(array[start2++]);

		}
		//using vector::assign to copy temp array to array
		array.assign(temp.begin(), temp.end());
		temp.clear();
	}
	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}

void selectionSort(vector<int> array) {

	cout << "selectionSort result" << endl;
	timer_record(1);
	for (int i = 0; i < array.size(); i++) {
		int smallestIndex = i;
		for (int j = i; j < array.size(); j++) {
			if (array[smallestIndex] > array[j])
				smallestIndex = j;
		}

		int temp = array[i];
		array[i] = array[smallestIndex];
		array[smallestIndex] = temp;
	}

	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}

void bubbleSort(vector<int> array) {
	cout << "bubbleSort result" << endl;
	timer_record(1);
	for (int count = 0; count < array.size(); count++)
	{
		for (int count2 = 0; count2 < array.size()-count-1; count2++) {
			if (array[count2] > array[count2+1]) {
				int temp = array[count2];
				array[count2] = array[count2+1];
				array[count2 + 1] = temp;
			}
		}
	}
	timer_record(2);
#ifdef SHOW_RESULT
	printArray(array);
	fgetc(stdin);
#endif
}

void quickSort(vector<int> &array, int left, int right) {
	int i = left, j = right;
	int temp;
	int pivot = array[(left + right )/ 2];
	while (i <= j) {
		while (array[i] < pivot) i++;
		while (array[j] > pivot) j--;
		if (i <= j) {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (left < j)
		quickSort(array, left, j);
	if (i < right)
		quickSort(array, i, right);
}

int partition(vector<int>&array, int left, int right) {
	int i = left, j = right;
	int pivot = array[left];
	//why it can work? Due to pivot is temporary stored array[left]
	while (i < j) {
		while (i < j && array[--j] >= pivot);
		if (i < j) {
			array[i] = array[j];
		}
		while (i < j && array[++i] <= pivot);
		if (i < j)
			array[j] = array[i];
	}
	array[j] = pivot;
	return j;
}


void quickSort2(vector<int>&array, int left, int right) {
	if ((right- left) < 2)
		return;
	int pivotIndex = partition(array, left, right);
	quickSort2(array, left, pivotIndex);
	quickSort2(array, pivotIndex+1, right);
	
}

void quickSortWay(vector<int> array) {
	cout << "quickSort result" << endl;
	//quickSort(array, 0, array.size() - 1);
	quickSort2(array, 0, array.size() );
#ifdef SHOW_RESULT
	printArray(array);
	fgetc(stdin);
#endif
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
	printArray(array);
}
int main()
{

	/*Todo:
		1.Replace <int> to T
		2.Added feature StdRandom.shuffle 
	*/

	vector<int> array = get_randVec();
	cout << "Original Order: " << endl;
	printArray(array);

	bool flag = true;
	if (flag)
	{
		
		bubbleSort(array);
		insertionSort(array);
		shellSort(array);
		selectionSort(array);
		mergeSortWay(array);
		mergeSort_iteration(array);
		/*undone*/	
		quickSortWay(array);
	}

	cout << "Done" << endl;
	fgetc(stdin);
    return 0;
}

