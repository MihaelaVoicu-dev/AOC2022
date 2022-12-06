// Day6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning (disable : 4996)
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cassert>
#include <set>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void getInput(const char* fileName, string& buffer) {
	char c;
	FILE* input;
	input = fopen(fileName, "r");

	if (input)
	{
		while (feof(input) == 0)
		{
			do {
				c = getc(input);
				if (c != '\n') {
					buffer.push_back(c);
				}
			} while (c != EOF);

		}
	}
	fclose(input);
}

bool check_Unique(string& string) {
	set<char> mySet;
	int counter = 0;
	for (char& c : string) {
		mySet.insert(c);
		counter++;
	}
	if (mySet.size() != counter) {
		return false;
	}
	else
	{
		return true;
	}
}

int searchFirstMarkerIndex(string& buffer, int temporaryDimension)
{
	string temporaryBuffer;
	int verificare;
	bool ok = true;
	for (int i = temporaryDimension; i < buffer.length(); i++)
	{
		for (int k = i; k >= i - temporaryDimension; k--)
		{
			temporaryBuffer.push_back(buffer[k]);// ne facem un sir temporar pentru a facilita verificarea
		  //doar initializarea cu valori aici
		}
		if (check_Unique(temporaryBuffer)) {
			return i + 1;
		}
		else {
			temporaryBuffer.erase();
		}
	}
}

int main()
{
	string buffer;
	int index;
	getInput("input.in", buffer);
	index = searchFirstMarkerIndex(buffer, 3);//part1
	index = searchFirstMarkerIndex(buffer, 13);//part2
	cout << index;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
