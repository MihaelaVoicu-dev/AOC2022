// Day5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Container.h"
#include "Command.h"

using namespace std;

void getInput(const string& fileName, vector<Container>& containers, vector<Command>& commands)
{
	ifstream input;
	input.open(fileName);
	string line;
	vector<string> containersLines;
	do
	{
		getline(input, line);
		if (line.size() > 0)
			containersLines.push_back(line);
	} while (line.size() != 0);
	int numbersOfContainers = 0;
	int tripleSpaceIndex = 0;
	do {
		tripleSpaceIndex = containersLines[containersLines.size() - 1].find("   ", tripleSpaceIndex + 1);
		numbersOfContainers++;
	} while (tripleSpaceIndex != string::npos);
	containers.resize(numbersOfContainers, Container(""));
	for (int lineIndex = containersLines.size() - 2; lineIndex >= 0; lineIndex--)
	{
		for (int containersIndex = 0; containersIndex < numbersOfContainers; containersIndex++)
			if (containersLines[lineIndex][containersIndex * 4 + 1] != ' ')
				containers[containersIndex].append(string(1, containersLines[lineIndex][containersIndex * 4 + 1]));
	}

	while (getline(input, line)) {
		int quantityFirstPosition = line.find(" ") + 1;
		int quantityLastPosition = line.find(" ", quantityFirstPosition);
		int quantity = stoi(line.substr(quantityFirstPosition, quantityLastPosition - quantityFirstPosition));
		int fromFirstPosition = line.find(" ", quantityLastPosition + 1) + 1;
		int fromLastPosition = line.find(" ", fromFirstPosition);
		int from = stoi(line.substr(fromFirstPosition, fromLastPosition - fromFirstPosition));
		int whereToFirstPosition = line.find(" ", fromLastPosition + 1) + 1;
		int whereTo = stoi(line.substr(whereToFirstPosition));
		commands.push_back({ quantity,from,whereTo });
	}
	input.close();
};

void processMoves2(vector<Container>& containers, vector<Command>& commands)
{
	for (auto& command : commands)
	{
		containers[command.whereTo - 1].append(containers[command.from - 1].takeLastElements(command.quantity));
	}
};
void processMoves(vector<Container>& containers, vector<Command>& commands)
{
	for (auto& command : commands)
	{
		containers[command.whereTo - 1].append(containers[command.from - 1].takeLastElementsReversed(command.quantity));
	}
};
void getOutputPart1(string fileName, vector<Container>& containers)
{
	ofstream output;
	output.open(fileName);
	for (auto& container : containers) {
		output << container.takeLastElementsReversed(1);
	}
};
void getOutputPart2(string fileName, vector<Container>& containers)
{
	ofstream output;
	output.open(fileName);
	for (auto& container : containers) {
		output << container.takeLastElementsReversed(1);
	}
};
int main()
{
	vector<Container> containers;
	vector<Command> commands;
	getInput("input.in", containers, commands);
	processMoves(containers, commands);
	getOutputPart1("output.out", containers);
	getOutputPart2("output2.out", containers);




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
