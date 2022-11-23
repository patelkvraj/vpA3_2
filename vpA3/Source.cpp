/*
AUTHOR: 
_______

	Vraj K Patel

TOTAL FILES THE PROGRAM CONTAINS: 
_________________________________
	
	Total files:	2 
		1) Source.cpp
		2) numbers.txt (This text file is selected by the user, so it can be different. But, there will be at least one text file)


ABOUT THE PROGRAM:
__________________
	
	Part - 2
		Created on	:	11/13/2022
		Title (Name):	Assignment 3 (Part 2)
		Description	:	A program that asks the user for a file name (Assume the file contains a series of numbers, each written on a separate line). 
									The program read the contents of the file into an array then display the following data:
										1) The lowest number in the array
										2) The highest number in the array
										3) The total of the numbers in the array
										4) The average of the numbers in the array
		Purpose		:	Read numbers from a file, and sort them in a particular manner.
		Challenges	:	-


REVISION HISTORY:		
_________________
	
	Date:				By:				Action: 
	-------------------------------------------
*	11/13/2022			VP				Created the program
*	11/14/2022			VP				Worked on code documentation 
*	11/15/2022			VP				Added "numbers.txt" file in this directory for streaming data. Worked on opening the file given by the user.
*	11/16/2022			VP				I created an array "string numbers[]" to hold the content from a text file. I Wrote code that read contents of
*										the file into the array. I displayed the contents on the terminal.
*	11/17/2022			VP				I declared five function prototypes. I shifted "file_name" variable before main function so that it can be used in readNumbers(). 
*										I defined readNumbers(). Edited the message (Prompted on the screen when the file does not open). Passed one more parameter to readNumbers().
*										Added a comment about readNumbers(). 
*	11/18/2022			VP				Edited the comment of the readNumbers(). I changed the numbers[] size. I changed to 9 instead of 4, on line 98. I called the getLowest(). 
*										I wrote the comment for getLowest(). I wrote the definition and body of getHighest(), getSum(), and getAverage(). Also, I added the comment for all
										three methods. 
	11/19/2022			VP				I converted regular for-loop(Print the content on the screen) to range based for-loop (line 103). I added a while loop, and it will repeat until the user 
										enters a valid file name. 
	Later "Revision History" are on github
*/

/* 
	WORK ON:	-
*/

#include <iostream>
#include <fstream>
using namespace std;

/* Function prototypes */
void readNumbers(ifstream&, int [], int);
int getLowest(int [], int);
int getHighest(int [], int);
int getSum(int [], int);
double getAverage(int [], int);

int main() {

	/* declaring variables */
	string file_name;	//	To hold the file name given by the user

	ifstream infile;										//	Declare an instance of ifstream class

	cout << "Hey, User!\n";

	/* The while loop will repeat until the user enters a valid file name */
	while (true) {
		cout << "Give the name of the file you want to stream data.";
		cout << "\n=> ";
		cin >> file_name;

		file_name += ".txt";	//	The string extention (.txt) is needed to open the file 

		infile.open(file_name);									//	Open a text file
		if (infile.fail()) {									//	To detect a failed attempt to open a file
			cout << "\nWarning: No such file exist.\n\n";
		}
		else {
			break;
		}
	}

	const int ARRAY_SIZE = 10;	//	To declare the size of an array
	int numbers[ARRAY_SIZE];	//	Create an array of type string, numbers, to hold content streamed from a file

	readNumbers(infile, numbers, ARRAY_SIZE);	//	Transfer the data from a file into an array

	/* Print the content of the file */
	cout << "\nThe content of the file: \n";
	for (int val : numbers) {
		cout << val << "\n";
	}

	cout << endl << "=> The lowest number: " <<  getLowest(numbers, ARRAY_SIZE);			// Give and print the lowest number from the array
	cout << endl << "=> The highest number: " << getHighest(numbers, ARRAY_SIZE);			// Give and print the highest number from the array
	cout << endl << "=> The total of the numbers: " << getSum(numbers, ARRAY_SIZE);			// Give and print the total of the numbers in the array
	cout << endl << "=> The average of the numbers: " << getAverage(numbers, ARRAY_SIZE);	// Give and print the total of the numbers in the array


	infile.close();	//	Close a text file

	cout << "\n\n\n";	//	To have some space at the end of the program

	return 0;	//	No return 
}	//	End of the main function


/*
***************************************************************************
Name	:		readNumbers()
Purpose	:		Read the content of a file into an array
Input	:		ifstream, int [], int
Output	:		N/A
***************************************************************************
*/
void readNumbers(ifstream &file, int array[], int array_size) {

	/* Read the contents of the file into an array */
	for (int i = 0; i < array_size; i++) {	//	convert into a range-based for loop
		file >> array[i];
	}
}	//	End of the readNumbers() function



/*
***************************************************************************
Name	:	getLowest()
Purpose	:	Give the lowest number from an array
Input	:	int [], int
Output	:	int 
***************************************************************************
*/
int getLowest(int array[], int array_size) {

	int least = 0;	//	A local variable to hold the lowest number

	/*	Determine the lowest number	*/
	for (int i = 0; i < array_size; i++) {
		if (array[i] < least) {
			least = array[i];
		}
	}
	return least;
}	//	End of the getLowest() function



/*
***************************************************************************
Name	:	getHighest()
Purpose	:	Give the highest number from an array
Input	:	int [], int
Output	:	int
***************************************************************************
*/
int getHighest(int array[], int array_size) {

	int highest = 0;	//	A local variable to hold the highest number

	/*	Determine the highest number	*/
	for (int i = 0; i < array_size; i++) {
		if (array[i] > highest) {
			highest = array[i];
		}
	}

	return highest;	
}	//	End of the getHighest() function



/*
***************************************************************************
Name	:	getSum()
Purpose	:	Give the total of the numbers in the array
Input	:	int [], int
Output	:	int
***************************************************************************
*/
int getSum(int array[], int array_size) {

	int total = 0;	//	A local variable to hold the total of the numbers in the array

	/*	Determine the total of the numbers in an array	*/
	for (int i = 0; i < array_size; i++) {
		total += array[i];
	}

	return total;	
}	//	End of the getSum() function



/*
***************************************************************************
Name	:	getAverage()
Purpose	:	Give the average of the numbers in the array
Input	:	int [], int
Output	:	int
***************************************************************************
*/
double getAverage(int array[], int array_size) {
	
	int total = 0;		//	A local variable to hold the total of the numbers in the array
	double average = 0;	//	A local variable to hold the average of the numbers in the array

	/*	Determine the total of the numbers in an array	*/
	for (int i = 0; i < array_size; i++) {
		total += array[i];
	}

	return total / 2.0;	//	Returns the average of the numbers
}	//	End of the getAverage() function
