// ********************************************************************
// CPSC2620 Spring 2016
// File Name: set.cc
// Purpose: Implementation of the class set
// Created on: Mar 30, 2016
// Author: Michael Wynnychuk
// ********************************************************************
#include<iostream>
#include "h_set.h"
using namespace std;

//template<typename T>
Set::Set() // Creates a set
{
	rootPtr->rightPtr = nullptr; // TailPtrs next pointer is now null.
	rootPtr->leftPtr  = nullptr;
}
// template<typename T>
Set::~Set() // Deletes the entire set.
{
	// deallocate(); // deletes the set excluding the dummy node.
	delete rootPtr; // deletes the dummy node 
	rootPtr = nullptr; // set headPtr to point to nullptr
}
void Set::deallocate()
{
	/*
	if (rootPtr = nullptr) // Executes unless Queue is empty
	{
		Node* tempPtr = rootPtr; // node pointer (acts like iterator)
		while (tempPtr != nullptr)// go through Queue and delete the nodes
		{
			if (tempPtr->Ptr == tailPtr)
			{
				tailPtr = tempPtr; // move tail pointer to 2nd from front position
				tempPtr = tempPtr->nextPtr; // point tempPtr to the next pointer
				tailPtr->nextPtr = nullptr; // set the front nodes nextPtr to null

				delete tempPtr; // advance the front object to the next
				tempPtr = headPtr; // reset tempPtr back to the start of the Queue	  
			}
			tempPtr = tempPtr->nextPtr; // move the tempPtr to the next node in the queue
		}
		tailPtr = headPtr; // point tailPtr back to headPtr
		delete tempPtr; // deletes the last node in the queue (except the dummy node)
	}
	*/
}
// Function name and type: add , int
// Purpose: Inserts a value into the set. If the value already
// exists then the set will not be changed.
// template<typename T>
int Set::add(int val)
{

}
// Function name and type: insert , void
// Purpose: Inserts a value into the set.
// Assuming that the value is not in the set already.
// Otherwise the value is not added.
// template<typename T>
void Set::insert(Node* ptr, int val)
{
	if (!rootPtr) // Value already exists
	{
		rootPtr = new Node(val);
	}
	else if (rootPtr->data >= rootPtr->data)
	{
		insert(rootPtr->leftPtr, rootPtr->data); // Add value to the set.
	}
	else
	{
		insert(rootPtr->rightPtr, rootPtr->rightPtr->data);
	}
}
// Function name and type: get , void
// Purpose: Returns a pointer to the value in the set, if it exists.
// Otherwise, it will return a null pointer.
// template<typename T>
Set* Set::get(Node* ptr) const
{
	if(find(ptr->data) == true)
	{
		return ptr->data;
	}
	else 
	{
		return nullptr;
	}	
}
// Function name and type: find , boolean
// Purpose: Searches the set for a given value that
// returns true if found, otherwise false.
// template<typename T>
bool Set::find(int val) const
{	
	
	return false;
}
// Function name and type: traverse , void
// Purpose: Calls the supplied function f on 
// the value of each node in the tree. The nodes
// are traversed in increasing order of the value
// template<typename T>
void Set::traverse(void(*f)(int& value)) const
{
	
}