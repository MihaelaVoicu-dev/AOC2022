// Day9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<string>
#include <vector>

using namespace std;

vector<string> getInput(string fileName,vector<string> &motions) {
	ifstream input;
	input.open(fileName);
	string line;
	while (getline(input, line)) {
		motions.push_back(line);
	}
    return motions;
}
int  simulateSeriesOfMotion(vector<string> &motions) {
	pair <int, int> coordinatesH ;
	pair<int, int> coordinatesT;
	coordinatesH.first = 0;
	coordinatesH.second = 0;
	coordinatesT.first = 0;
	coordinatesT.second = 0;
	vector<pair<int, int>> positionVisited;
	for (auto motion : motions)
	{
		if (motion[0] == 'R')
		{
			int valueIndex = motion.find(" ") + 1;
			int value = motion[valueIndex]-'0';
			int index = 0;
			if (value == 1)
			{
				coordinatesH.second++;
				index++;
				if (!((coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second)
					|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second)))
				{
					coordinatesT.first = coordinatesH.first;
					coordinatesT.second = coordinatesH.second - 1;
					coordinatesT.first = coordinatesH.first;
					pair<int, int>addingValue;
					addingValue.first = coordinatesT.first;
					addingValue.second = coordinatesT.second;
					if (positionVisited.size() == 0)
					{
						positionVisited.push_back(addingValue);
					}
					bool isVisited = true;
					for (int i = 0; i < positionVisited.size(); i++)
					{

						if (coordinatesT.first == positionVisited[i].first && coordinatesT.second == positionVisited[i].second)
						{
							isVisited = false;
							break;
						}
					}
					if (isVisited)
					{
						positionVisited.push_back(addingValue);
					}
				}

			}
			while (index < value)
			{
				coordinatesH.second++;
				index++;
				if (!((coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second)
					|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second)))
				{
					coordinatesT.first = coordinatesH.first;
					coordinatesT.second = coordinatesH.second - 1;
					coordinatesT.first = coordinatesH.first;
					pair<int, int>addingValue;
					addingValue.first = coordinatesT.first;
					addingValue.second = coordinatesT.second;
					if(positionVisited.size() == 0)
					{
						positionVisited.push_back(addingValue);
					}
					bool isVisited = true;
					for (int i = 0; i < positionVisited.size(); i++)
					{

						if (coordinatesT.first == positionVisited[i].first && coordinatesT.second == positionVisited[i].second)
						{
						 isVisited = false;
						 break;
						}
					}
					if (isVisited)
					{
						positionVisited.push_back(addingValue);
					}
				}

			}
		}
		else if (motion[0] == 'L')
		{
			int valueIndex = motion.find(" ") + 1;
			int value = motion[valueIndex]-'0';
			int index = 0;
			if (value == 1)
			{
				coordinatesH.second--;
				index++;
				if (!((coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second)
					|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second)))
				{
					coordinatesT.first = coordinatesH.first;
					if (coordinatesH.second < 0)
					{
						coordinatesT.second = coordinatesH.second - 1;
					}
					else
					{
						coordinatesT.second = coordinatesH.second + 1;
					}
					pair<int, int>addingValue;
					addingValue.first = coordinatesT.first;
					addingValue.second = coordinatesT.second;
					if (positionVisited.size() == 0)
					{
						positionVisited.push_back(addingValue);
					}
					bool isVisited = true;
					for (int i = 0; i < positionVisited.size(); i++)
					{

						if (coordinatesT.first == positionVisited[i].first && coordinatesT.second == positionVisited[i].second)
						{

							isVisited = false;
							break;
						}
					}
					if (isVisited)
					{
						positionVisited.push_back(addingValue);
					}
				}
			}
			while (index < value)
			{
				coordinatesH.second--;
				index++;
				if (!((coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second)
					|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second)))
				{
					coordinatesT.first = coordinatesH.first;
					if (coordinatesH.second < 0)
					{
						coordinatesT.second = coordinatesH.second - 1;
					}
					else
					{
						coordinatesT.second = coordinatesH.second + 1;
					}
					pair<int, int>addingValue;
					addingValue.first = coordinatesT.first;
					addingValue.second = coordinatesT.second;
					if (positionVisited.size() == 0)
					{
						positionVisited.push_back(addingValue);
					}
					bool isVisited = true;
					for (int i = 0; i < positionVisited.size(); i++)
					{

						if (coordinatesT.first == positionVisited[i].first && coordinatesT.second == positionVisited[i].second)
						{

							isVisited = false;
							break;
						}
					}
					if (isVisited)
					{
						positionVisited.push_back(addingValue);
					}
				}
			}
		}
		else if (motion[0] == 'U')
		{
			int valueIndex = motion.find(" ") + 1;
			int value = motion[valueIndex] - '0';
			int index = 0;
			if (value == 1)
			{
				coordinatesH.first--;
				if (!((coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second)
					|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second)))
				{
					coordinatesT.second = coordinatesH.second;
					if (coordinatesH.first > 0)
					{
						coordinatesT.first = coordinatesH.second - 1;
					}
					else
					{
						coordinatesT.first = coordinatesH.first + 1;
					}
					pair<int, int>addingValue;
					addingValue.first = coordinatesT.first;
					addingValue.second = coordinatesT.second;
					if (positionVisited.size() == 0)
					{
						positionVisited.push_back(addingValue);
					}
					bool isVisited = true;
					for (int i = 0; i < positionVisited.size(); i++)
					{

						if (coordinatesT.first == positionVisited[i].first && coordinatesT.second == positionVisited[i].second)
						{

							isVisited = false;
							break;
						}
					}
					if (isVisited)
					{
						positionVisited.push_back(addingValue);
					}
					index++;
				}
			}
			while (index < value - 1)
			{
				coordinatesH.first--;
				if (!((coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second)
					|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second)))
				{
					coordinatesT.second = coordinatesH.second;
					if (coordinatesH.first > 0)
					{
						coordinatesT.first = coordinatesH.second - 1;
					}
					else
					{
						coordinatesT.first = coordinatesH.first + 1;
					}
					pair<int, int>addingValue;
					addingValue.first = coordinatesT.first;
					addingValue.second = coordinatesT.second;
					if (positionVisited.size() == 0)
					{
						positionVisited.push_back(addingValue);
					}
					bool isVisited = true;
					for (int i = 0; i < positionVisited.size(); i++)
					{

						if (coordinatesT.first == positionVisited[i].first && coordinatesT.second == positionVisited[i].second)
						{

							isVisited = false;
							break;
						}
					}
					if (isVisited)
					{
						positionVisited.push_back(addingValue);
					}
					index++;
				}
			}
		}
		else if (motion[0] == 'D')
		{
			int valueIndex = motion.find(" ") + 1;
			int value = motion[valueIndex] - '0';
			int index = 0;
			if (value == 1)
			{
					coordinatesH.first++;
					if (!((coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second)
						|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second - 1)
						|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second - 1)
						|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second - 1)
						|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second)
						|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second + 1)
						|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second + 1)
						|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second + 1)
						|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second)))
					{
						coordinatesT.second = coordinatesH.second;
						if (coordinatesH.first > 0)
						{
							coordinatesT.first = coordinatesH.first - 1;
						}
						else
						{
							coordinatesT.first = coordinatesH.first + 1;
						}
						pair<int, int>addingValue;
						addingValue.first = coordinatesT.first;
						addingValue.second = coordinatesT.second;
						if (positionVisited.size() == 0)
						{
							positionVisited.push_back(addingValue);
						}
						bool isVisited = true;
						for (int i = 0; i < positionVisited.size(); i++)
						{

							if (coordinatesT.first == positionVisited[i].first && coordinatesT.second == positionVisited[i].second)
							{

								isVisited = false;
								break;
							}
						}
						if (isVisited)
						{
							positionVisited.push_back(addingValue);
						}
						index++;
					}
				}

			while (index < value - 1)
			{
				coordinatesH.first++;
				if (!((coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second)
					|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second - 1)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second)
					|| (coordinatesT.first == coordinatesH.first + 1 && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first - 1 && coordinatesT.second == coordinatesH.second + 1)
					|| (coordinatesT.first == coordinatesH.first && coordinatesT.second == coordinatesH.second)))
				{
					coordinatesT.second = coordinatesH.second;
					if (coordinatesH.first > 0)
					{
						coordinatesT.first = coordinatesH.first - 1;
					}
					else
					{
						coordinatesT.first = coordinatesH.first + 1;
					}
					pair<int, int>addingValue;
					addingValue.first = coordinatesT.first;
					addingValue.second = coordinatesT.second;
					if (positionVisited.size() == 0)
					{
						positionVisited.push_back(addingValue);
					}
					bool isVisited = false;
					for (int i = 0; i < positionVisited.size(); i++)
					{

						if (coordinatesT.first == positionVisited[i].first && coordinatesT.second == positionVisited[i].second)
						{

							isVisited = true;
						}
					}
					if (isVisited)
					{
						positionVisited.push_back(addingValue);
					}
					index++;
				}
			}
		}
	

	}
	return positionVisited.size()+1;

}
int main()
{
	vector <string> motions;
	getInput("input.in", motions);
	cout<<simulateSeriesOfMotion(motions);

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
