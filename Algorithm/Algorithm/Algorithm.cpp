// Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;


void printArray(vector<int> array) {
	for ( vector<int>::iterator iter = array.begin(); iter!=array.end(); ++iter )
		cout << *iter << " ";
	cout << endl;
}

void insertionSort(vector<int> array) {
	cout << "InsertionSort result" << endl;
	for (int UnsortedIndex = 1; UnsortedIndex < array.size(); UnsortedIndex++) {
		int temp = array[UnsortedIndex];
		int SortedIndex = 0;

		for (SortedIndex = UnsortedIndex; SortedIndex > 0 && array[SortedIndex- 1] > temp; SortedIndex--)
			array[SortedIndex] = array[SortedIndex - 1];
		array[SortedIndex] = temp;

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


void modify(vector<int> &array) {
	swap(array[0], array[1]);
}

int main()
{
	
	vector<int> array;
	array.push_back(-1);
	array.push_back(9);
	array.push_back(4);
	array.push_back(55);
	array.push_back(12);

	bool flag = true;
	if (flag)
	{
		insertionSort(array);
		selectionSort(array);
		mergeSortWay(array);
	}
	else {
		printArray(array);
		modify(array);
		printArray(array);
	}
	
	cout << "Done" << endl;
	fgetc(stdin);
    return 0;
}

