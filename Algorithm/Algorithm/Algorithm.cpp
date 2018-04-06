// Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;


void printArray(vector<int> array) {
	for ( vector<int>::iterator iter = array.begin(); iter!=array.end(); ++iter )
		cout << *iter << " ";
	cout << endl;
}

void shellSort(vector<int> array) {
	cout << "Shell Sort result" << endl;
	//Stuck	
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

	printArray(array);
	fgetc(stdin);
}

void insertionSort(vector<int> array) {
	cout << "InsertionSort result" << endl;
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

	printArray(array);
	fgetc(stdin);
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
	mergeSort(array, 0, array.size());
	printArray(array);
	fgetc(stdin);

}

int min(int x, int y) {
	return x < y ? x : y;
}

void mergeSort_iteration(vector<int> array) {
	cout << "mergeSort iteration result" << endl;

	int start1, end1, start2, end2;
	vector<int> temp;
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

	printArray(array);
	fgetc(stdin);
}

void selectionSort(vector<int> array) {

	cout << "selectionSort result" << endl;
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

	printArray(array);
	fgetc(stdin);
}

void gen_rand(vector<int> &array) {
	srand( (int)time(0));
	int times = rand() % 100+1;
	for (int count = 0; count < times; count++)
		array.push_back(rand() % 20000 - 10000);
}


int main()
{
	/*Todo:
		Replace <int> to T
	*/
	vector<int> array;
	gen_rand(array);
	
	high_resolution_clock::time_point start = high_resolution_clock::now();
	bool flag = true;
	if (flag)
	{
		insertionSort(array);
		shellSort(array);
		selectionSort(array);
		mergeSortWay(array);
		mergeSort_iteration(array);
	}
	high_resolution_clock::time_point stop = high_resolution_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(stop - start);
	cout << "Times :\t" << time_span.count() << "\tseconds"<<endl;
	cout << "Done" << endl;
	fgetc(stdin);
    return 0;
}

