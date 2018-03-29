// Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;


void printArray(vector<int> array) {
	for (int count = 0; count < array.size(); count++)
		cout << array[count] << " ";
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



int main()
{
	vector<int> array;
	array.push_back(-1);
	array.push_back(9);
	array.push_back(4);
	array.push_back(55);
	array.push_back(12);

	insertionSort(array);
	selectionSort(array);
    return 0;
}

