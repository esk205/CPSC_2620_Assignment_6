// ********************************************************************
// CPSC2620 Spring 2016
// File Name: testSort.cc
// Purpose: 
// Created on: Mar 21, 2016
// Author: anvik
// Notes: 
// ********************************************************************

#include <iostream>
#include <iomanip>
#include "sort.h"

using namespace std;

int main(int argc, char **argv) {

	unsigned t0, t1, num, max;

	// The size of the list to sort
	cout << "Enter n: ";
	cin >> num;

	// The maximum random value in the list
	cout << "Enter max value: ";
	cin >> max;

	// Flag for outputting the sorted lists
	bool output = false;

	// Output decimal values to 2 places
	cout << setprecision(2) << fixed;

	// Create the list of random values to sort
	vector<int> v;
	for (int i = 0; i < num; i++)
		v.push_back(rand() % max);

	// Test merge sort
	vector<int> m(num);
	copy(v.begin(), v.end(), m.begin());
	t0 = clock();
	msort(m, m.begin(), m.end());
	t1 = clock();
	double mTime = ((t1 - t0) * 1.0) / CLOCKS_PER_SEC;
	cout << "Merge sort time: " << mTime << endl;

	if (output) {
		for (int i : m)
			cout << i << " ";
		cout << endl;
	}

	// Test quicksort
	vector<int> n(num);
	copy(v.begin(), v.end(), n.begin());
	t0 = clock();
	qsort(n, n.begin(), n.end());
	t1 = clock();
	double qTime = ((t1 - t0) * 1.0) / CLOCKS_PER_SEC;
	cout << "Quicksort time: " << qTime << endl;

	if (output) {
		for (int i : n)
			cout << i << " ";
		cout << endl;
	}

	// Test introspective quicksort
	vector<int> o(num);
	copy(v.begin(), v.end(), o.begin());
	t0 = clock();
	qsort2(o, o.begin(), o.end());
	t1 = clock();
	qTime = ((t1 - t0) * 1.0) / CLOCKS_PER_SEC;
	cout << "Quicksort (introspective) time: " << qTime << endl;

	if (output) {
		for (int i : o)
			cout << i << " ";
		cout << endl;
	}

	// Test heapsort
	vector<int> p(num);
	copy(v.begin(), v.end(), p.begin());
	t0 = clock();
	hsort(p);
	t1 = clock();
	qTime = ((t1 - t0) * 1.0) / CLOCKS_PER_SEC;
	cout << "Heapsort time: " << qTime << endl;

	if (output) {
		for (int i : p)
			cout << i << " ";
		cout << endl;
	}
}

