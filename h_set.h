// ********************************************************************
// CPSC2620 Spring 2016
// File Name: set.h
// Purpose: A class template for set where data in each node has a 
// unique value and more nodes may be added assuming it's  
// value is unique.
// in order to create Node objects with its own data and pointers
// Created on: Mar 26, 2016
// Author: Michael Wynnychuk
// ********************************************************************
#ifndef SET_H
#define SET_H
#include<iostream>
using namespace std;

//template<typename T>
class Set 
{
  public :
	  Set();  // default constructor
	  ~Set(); // destructor (deletes all "new" variables)
   void deallocate(); // helper function for the destructor
 
   // Accessor methods  
   // bool empty() const;  // returns true if the queue is empty
   //ostream & operator<<(ostream & out, const Queue & q);
   // int size();   // returns the number of values in the queue
   bool find(int) const;
   void traverse(void(*f)(int& value)) const;

   // Modifier methods
   int add(int);
   void insert(Node*, int);
   Set& get(int val) const;
   
  private:
   class Node // nested class
   {
      friend class Set; // let set have access to the private data
      public :
     Node(int item = 0, Node* node=nullptr) : data(item), rightPtr(node), leftPtr(node) {}
	
     private :
      int data;
      Node* leftPtr;
	  Node* rightPtr;
   };
   Node* rootPtr;
};
#include "./cc_Set.cc"
#endif
   
      
   
   
