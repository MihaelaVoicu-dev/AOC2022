// Day8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning (disable : 4996)
#include <iostream>
#include <fstream>
#include<vector>
#include<string>

using namespace std;
const int length = 99;
int getPart1(const string& fileName)
{
	ifstream input;
	input.open(fileName);
	string line;
	int trees[length][length];
	char element;
	int elementInteger;
	int i = 0;
	while (getline(input, line)) {
		for (int j = 0; j < length; ++j) {
			element = line[j];
			elementInteger = element - '0';
			trees[i][j] = elementInteger;
		}
		i++;
	}
	input.close();
	/*for (int k = 0; k < length; k++) {
		for (int l = 0; l < length; l++) {
			cout << trees[k][l] << " "  ;
		}
		cout << endl;
	}*/
	int numberOfVisibleTrees = 0;
	for (int row = 0; row < length; ++row) {
		for (int colomn = 0; colomn < length; ++colomn) {
			//jos 
			bool verify = true;
			int value = trees[row][colomn];
			int rowDown = row + 1;
			while (rowDown < length) {
				if (trees[rowDown][colomn] >= value) {
					verify = false;
					break;
				}
				rowDown++;
			}
			if (verify) {
				numberOfVisibleTrees++;
				verify = false;
			}
			else
			{
				//sus
				verify = true;
				int rowUp = row - 1;
				while (rowUp >= 0) {
					if (trees[rowUp][colomn] >= value) {
						verify = false;
						break;
					}
					rowUp--;
				}
				if (verify) {
					numberOfVisibleTrees++;
					verify = false;
				}
				else {
					//dreapta
					verify = true;
					int columnRight = colomn + 1;
					while (columnRight < length) {
						if (trees[row][columnRight] >= value) {
							verify = false;
							break;
						}
						columnRight++;
					}
					if (verify) {
						numberOfVisibleTrees++;
						verify = false;
					}
					else
					{

						//stanga
						verify = true;

						int columnLeft = colomn - 1;
						while (columnLeft >= 0) {
							if (trees[row][columnLeft] >= value) {
								verify = false;
								break;
							}
							columnLeft--;
						}
						if (verify) {
							numberOfVisibleTrees++;
							verify = false;
						}
					}
				}
			}
		}
	}
	return numberOfVisibleTrees;
};


int getPart2(const string& fileName)
{
	ifstream input;
	input.open(fileName);
	string line;
	int trees[length][length];
	char element;
	int elementInteger;
	int i = 0;
	while (getline(input, line)) {
		for (int j = 0; j < length; ++j) {
			element = line[j];
			elementInteger = element - '0';
			trees[i][j] = elementInteger;
		}
		i++;
	}
	input.close();
	/*for (int k = 0; k < length; k++) {
		for (int l = 0; l < length; l++) {
			cout << trees[k][l] << " "  ;
		}
		cout << endl;
	}*/
	int numberOfVisibleTrees = 0;
	int previousMax = 0;
	int m, n;
	for (int row = 0; row < length; ++row) {
		for (int colomn = 0; colomn < length; ++colomn) {
			//jos 
			int sumUp = 0, sumDown = 0, sumLeft = 0, sumRight = 0;
			int scenicScore = 0;
			int value = trees[row][colomn];
			int rowDown = row + 1;
			while (rowDown < length) {
				int b = trees[rowDown][colomn];
				if (trees[rowDown][colomn] < value) {
					sumDown++;
				}
				else if (trees[rowDown][colomn] >= value) {
					sumDown++;
					break;
				}
				rowDown++;
			}
			//sus
			int rowUp = row - 1;
			while (rowUp >= 0) {
				int c = trees[rowUp][colomn];
				if (trees[rowUp][colomn] < value) {
					sumUp++;

				}
				else if (trees[rowUp][colomn] >= value) {
					sumUp++;
					break;

				}
				rowUp--;
			}
			//dreapta
			int columnRight = colomn + 1;
			while (columnRight < length) {
				int d = trees[row][columnRight];
				if (trees[row][columnRight] < value) {
					sumRight++;

				}
				else if (trees[row][columnRight] >= value) {
					sumRight++;
					break;
				}
				columnRight++;

			}

			//stanga
			int columnLeft = colomn - 1;
			while (columnLeft >= 0) {
				if (trees[row][columnLeft] < value) {
					sumLeft++;
				}
				else if (trees[row][columnLeft] >= value) {
					sumLeft++;
					break;
				}
				columnLeft--;
			}

			scenicScore = sumDown * sumUp * sumRight * sumLeft;
			if (scenicScore > previousMax)
			{
				m = colomn;
				n = row;
				previousMax = scenicScore;
				scenicScore = 0;
			}
		}
	}
	return previousMax;
};

int main() {
	int x;
	x = getPart1("input.in");
	cout << x << endl;
	int y;
	y = getPart2("input.in");
	cout << y;
	return 0;
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
