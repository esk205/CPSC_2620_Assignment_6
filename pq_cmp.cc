// ********************************************************************
// CPSC2620 Spring 2016
// File Name: pq_cmp.cc
// Purpose: 
// Created on: Mar 16, 2016
// Author: anvik
// Notes: 
// ********************************************************************

#include <iostream>
#include "pq.h"
#include "pqHeap.h"
#include <stdlib.h>
#include <iomanip>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
	unsigned t0, t1, size;
	boolean output = false;

	cout << "Enter size to test: ";
	cin >> size;

	// Create vector of random values
	vector<int> data;
	for (int i = 0; i < size; i++)
		data.push_back(rand());

	// Output decimal values to 2 decinal places
	cout << setprecision(2) << fixed;

	// Test linked list implementation
	PQ<int> q1;
	t0 = clock();
	for (int i = 0; i < size; i++)
		q1.push(data[i]);
	t1 = clock();
	float t = ((t1 - t0) * 1.0) / CLOCKS_PER_SEC;
	cout << "Linked List time: " << t << endl;

	if (output) {
		while (q1.empty() == false)
			cout << q1.pop() << " ";
		cout << endl;
	}

	// Test heap implementation
	PQHeap<int> q2;
	t0 = clock();
	for (int i = 0; i < size; i++)
		q2.push(data[i]);
	t1 = clock();
	cout << "Heap time: " << ((t1 - t0) * 1.0) / CLOCKS_PER_SEC << endl;

	if (output) {
		while (q2.empty() == false)
			cout << q2.pop() << " ";
		cout << endl;
	}

}

