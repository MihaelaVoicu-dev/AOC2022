// Day7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include<string>

using namespace std;

vector<string> split(string s, string delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	string token;
	vector<string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}

void getInput(const string& fileName)
{
	ifstream input;
	input.open(fileName);
	string line;
	vector<string> commandsLines;
	std::unordered_map<std::string, uint64_t> directories;
	do
	{
		while (getline(input, line, (const char)'\n $')) {
			if (line.size() > 0)
				commandsLines.push_back(line);
		}
	} while (line.size() != 0);
}

int main()
{
	getInput("input.in");
	//cod neterminat
	//de adaugat in systemPath calea de cautare parinte( stringul "..") si de recalculare a size-ului
	//parcurgerea cu verificare pentru fiecare command in parte if (stringDupaDelimitare=" ..")cu apelul functiilor din system path 
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
