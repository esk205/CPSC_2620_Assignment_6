// ********************************************************************
// CPSC2620 Spring 2016
// File Name: textStats.cc
// Purpose: Program that uses recursion and set and maps
// Created on: Mar 24, 2016
// Author: Michael Wynnychuk
// ********************************************************************
#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;

int charCount(string&, char);
typedef set<char> Aset;
typedef map<const char, int> AMap;

int main()
{
   // set and map are only used here
   Aset set1;
   Amap map1;
   string sentence, letter;
   int counter = 0;
    
   cout << "Enter a sentence: "; // prompt the user to enter a sentence
   getline(cin, sentence); // input entire sentence into string

   // 4 for loops. Non-nested
   for(int i = 0; sentence.size() != 0; i++) // one letter per iteration 
   {
	  letter = sentence.back(); // get the last character in sentence
      counter = charCount(sentence, letter); // check repeats of the character in sentence
	  if (letter == ' ')
	  {
		  map1.insert(make_pair("<space>", counter))
	  }
	  else {
		  map1.insert(make_pair(letter, counter));
	  } 
   }
   for (auto mapItem : map1) { // display all counted letters and how many there are
	   cout << mapItem.first << ": " << mapItem.second << end;
   }
   return 0;
}
int charCount(string& s, char c)
{
   string letter; // used as a temporary variable
   // look at string and find the character
   if(s.empty()) // nothing left to compare
   {
      return 0;
   }
   // true if character matches last character
   else if(c == s.back()) 
   {
      s.pop_back(); // delete the last character
      letter = s; // copy s character into letter
      return charCount(letter, c) + 1; 
   }
   else // c != s.back()
   {
      s.pop_back();
      letter = s;
      return 0 + charCount(letter, c);
   }
   return;
}


