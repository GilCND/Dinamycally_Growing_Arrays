#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <fstream> 
#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
#include <chrono>  // for high_resolution_clock
/*
Programmer: Felipe SG.
Date: 01/02/2021
Details:
Research and write a C++ program to create a custom, class-based implementation of a Stack.
Using an array-based storage mechanism.
Implement their most common operations (push, pop, peek, etc…).
Use industry standard naming conventions when implementing the operations.
The array implementation of the Stack will need to automatically grow once nearing
capacity and shrink once capacity is returned. Use standard techniques for array growth/management.
Load the structure using the data from each of the supplied files and compare their load times.
Are there noticeable differences?
What about when popping items off the stack from each of the structures?
*/


using namespace std;
	// allocated on heap
int numberOfLines = 0;
string nameOfFile;

class Stack {
	int top;

public:
	int size = 5;					// no longer const
	int* arrayP = new int[size];
	

	Stack() { top = -1; }
	int Counter(string fileName);
	void loadFile(string name);
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
	void menu1();
	int menu2();
	int menu3();
	void display();
	string fileName(int i);
};
class Stack s;

int Counter(string fileName) {
	string unUsed;
	int numLines = 0;
	ifstream file(fileName);
	//count how many lines does the file have
	if (file.is_open())
	{
		while (getline(file, unUsed))
		{
			++numLines;
		}
		file.close();	
	}
	return numLines;
}
void loadFile(string name) {

	// check the size of the file.
	numberOfLines = Counter(nameOfFile);
	if (s.size < numberOfLines)
	{
		s.size = numberOfLines;
		// create new bigger array.
		int* tempP = new int[s.size];
		for (int i = 0; i <= s.size; i++)
		{
			// copy values to new array.
			tempP[i] = s.arrayP[i];
		}
		// free old array memory.
		// now a points to new array
		s.arrayP = tempP;
	}
	if (s.size > numberOfLines)
	{
		numberOfLines = s.size;
		// create new bigger array.
		int* tempP = new int[s.size];
		for (int i = 0; i <= s.size; i++)
		{
			// copy values to new array.
			tempP[i] = s.arrayP[i];
		}
		// free old array memory.
		// now a points to new array
		s.arrayP = tempP;
	}
	// Record start time
	auto begin = chrono::high_resolution_clock::now();
	// Portion of code to be timed
	cin.clear();

	ifstream file(nameOfFile);
	numberOfLines = Counter(nameOfFile);
	for (int i = 0; i < numberOfLines; i++)
	{
		file >> s.arrayP[i];
		cout << "# " << s.arrayP[i] << " ";
	}
	file.close();
	auto end = chrono::high_resolution_clock::now();
	// Record end time
	//print recorded time
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);

	cout << "Lines Loaded: " << numberOfLines << endl;
}
bool Stack::push(int x)
{
	numberOfLines++;
	
	int* tempP = new int[numberOfLines];
	for (int i = 0; i < numberOfLines; i++)
	{
		// copy values to new array.
		tempP[i+1] = s.arrayP[i];
	}
	// free old array memory.
	// now a points to new array
	s.arrayP = tempP;

	
	if (0 > (numberOfLines - 1)) {
		cout << "Overflow";
		return false;
	}
	else {
		s.arrayP[0] = x;
		cout << x << " Was pushed into the stack\n";
		return true;
	}
}
int Stack::pop()
{
	int x = s.arrayP[0];
	numberOfLines--;
	int* tempP2 = new int[numberOfLines];
	for (int i = 0; i <= numberOfLines; i++)
	{
		// copy values to new array.
		tempP2[i] = s.arrayP[i+1];
	}
	// free old array memory.
	// now a points to new array
	s.arrayP = tempP2;
	return x;
}
int Stack::peek()
{
	int x = s.arrayP[0];
	return x;
}
bool Stack::isEmpty()
{
	return (top < 0);
}
int menu3()
{
	int option = 0;
	cout << "All Files were loaded" << endl;
	cout << "Please select one of the options below" << endl;
	cout << "--------------------------------------" << endl;
	cout << "What action would you like to perform?" << endl;
	cout << "(1) Push" << endl;
	cout << "(2) Pop" << endl;
	cout << "(3) Peek" << endl;
	cout << "(4) Load another file" << endl;
	cout << "(5) Exit" << endl;
	cin >> option;
	system("CLS");
	return option;
}
int menu2()
{
	int option = 0;
	cout << "Welcome to Assignment 3 - Stacks" << endl;
	cout << "Please select one of the options below" << endl;
	cout << "--------------------------------------" << endl;
	cout << "What file should I load for you?" << endl;
	cout << "(1) Data1000.txt" << endl;
	cout << "(2) Data10000.txt" << endl;
	cout << "(3) Data100000.txt" << endl;
	cout << "(4) Data1000000.txt" << endl;
	cout << "(5) Exit" << endl;
	cin >> option;
	system("CLS");
	return option;
}
void menu1()
{
	int option = 0;
	cout << "Welcome to Assignment 3 - Stacks" << endl;
	cout << "Please select one of the options below" << endl;
	cout << "--------------------------------------" << endl;
	cout << "(1) Load From File" << endl;
	cout << "(2) Exit" << endl;
	cin >> option;
	system("CLS");
	if (option == 1) 
	{
	}
	else
	{
		exit(0);
	}
	cin.clear();
}
void display() 
{
	for (int i = 0; i < numberOfLines; i++)
	{
		cout << "# " << s.arrayP[i] << " ";
	}
}
string fileName(int i)
{
	switch (i)
	{
	case 1:
		nameOfFile = "Data1000.txt";
		break;
	case 2:
		nameOfFile = "Data10000.txt";
		break;
	case 3:
		nameOfFile = "Data100000.txt";
		break;
	case 4:
		nameOfFile = "Data1000000.txt";
		break;
	case 5:
		exit(0);
		break;
	default:
		break;
	}

	return nameOfFile;
	
}

// Driver program to test above functions
int main()
{	
	int newData = 0;
	string temp1;
	int menuOption = 0;
	menu1();
	menuOption = menu2();
	temp1 = fileName(menuOption);
	loadFile(temp1);
	while (menuOption != 5)
	{
		menuOption = menu3();
		switch (menuOption)
		{
		case 1:
			//push
			cout << "Tell me the integer that you want me to add on top of the stack: ";
			cin >> newData;
			s.push(newData);
			display();
			break;
		case 2:
			//pop
			cout << "The number: " << s.pop() << " Was removed from the top." << endl;
			display();
			break;
		case 3:
			//peek
			cout << "The number: " << s.peek() << " Is on top of the stack" << endl;
			break;
		case 4:
			//load another file	
			menuOption = menu2();
			temp1 = fileName(menuOption);
			loadFile(temp1);
			break;
		case 5:
			exit(0);
			break;
		default:
			break;
		}
	}
	return 0;
}

