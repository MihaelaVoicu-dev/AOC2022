// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include<string>

using namespace std;

void getInput(const string& fileName, vector<string>& instructions)
{
	ifstream input;
	input.open(fileName);
	string line;
	while (getline(input, line)) {
		instructions.push_back(line);
	}

}



int processInstructions(vector<string>& instructions)
{
	int signalStrengthTotal = 0;
	int registerX = 1, cycle = 0;
	for (auto instruction : instructions) {
		string instructionType = "";
		for (int i = 0; i < 4; i++)
		{
			instructionType = instructionType + instruction[i];
		}
		if (instructionType == "addx")
		{
			cycle++;
			if ((cycle % 40 == 20) && cycle <= 220) {
				signalStrengthTotal += cycle * registerX;
			}
			string addNumber = "";
			addNumber = instruction.substr(instruction.find(' ') + 1);
			signed int number;
			cycle++;
			number = stoi(addNumber);
			if ((cycle % 40 == 20) && cycle <= 220) {
				signalStrengthTotal += cycle * registerX;
			}
			registerX = registerX + number;
		}
		else {
			cycle++;
			if ((cycle % 40 == 20) && cycle <= 220) {
				signalStrengthTotal += cycle * registerX;
			}
		}
	}
	cout << signalStrengthTotal;
	return signalStrengthTotal;

}
void processInstructionsPart2(vector<string>& instructions)
{
	int signalStrengthTotal = 0;
	int registerX = 1, cycle = 1;
	int crt = 0;
	ofstream fileOut;
	fileOut.open("output.out");
	for (auto instruction : instructions) {


		string instructionType = "";
		for (int i = 0; i < 4; i++)
		{
			instructionType = instructionType + instruction[i];
		}
		if (instructionType == "addx")
		{
			crt = cycle - 1;
			if (abs(registerX - crt) <= 1) {
				if (crt == 40) {
					crt = 0;
					cycle = 1;
					if (abs(registerX - crt) <= 1) {
						fileOut << endl << "#";
					}
					else
					{
						fileOut << endl << ".";
					}
				}
				else {
					fileOut << "#";
				}
			}
			else
			{
				if (crt == 40) {
					crt = 0;
					cycle = 1;
					if (abs(registerX - crt) <= 1) {
						fileOut << endl << "#";
					}
					else
					{
						fileOut << endl << ".";
					}
				}
				else {
					fileOut << ".";
				}
			}
			cycle++;
			string addNumber = "";
			addNumber = instruction.substr(instruction.find(' ') + 1);
			signed int number;
			crt = cycle - 1;
			number = stoi(addNumber);
			if (abs(registerX - crt) <= 1) {
				if (crt == 40) {
					crt = 0;
					cycle = 1;
					if (abs(registerX - crt) <= 1) {
						fileOut << endl << "#";
					}
					else
					{
						fileOut << endl << ".";
					}
				}
				else {
					fileOut << "#";
				}
			}
			else
			{
				if (crt == 40) {
					crt = 0;
					cycle = 1;
					if (abs(registerX - crt) <= 1) {
						fileOut << endl << "#";
					}
					else
					{
						fileOut << endl << ".";
					}
				}
				else {
					fileOut << ".";
				}
			}
			cycle++;
			registerX = registerX + number;
		}
		else {
			crt = cycle - 1;
			if (abs(registerX - crt) <= 1) {
				if (crt == 40) {
					crt = 0;
					cycle = 1;
					if (abs(registerX - crt) <= 1) {
						fileOut << endl << "#";
					}
					else
					{
						fileOut << endl << ".";
					}
				}
				else {
					fileOut << "#";
				}
			}
			else
			{
				if (crt == 40) {
					crt = 0;
					cycle = 1;
					if (abs(registerX - crt) <= 1) {
						fileOut << endl << "#";
					}
					else
					{
						fileOut << endl << ".";
					}
					
				}
				else {
					fileOut << ".";
				}
			}
			cycle++;

		}
	}
}
int main()
{
	vector<string> instructions;
	getInput("input.in", instructions);
	processInstructions(instructions);
	processInstructionsPart2(instructions);
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
