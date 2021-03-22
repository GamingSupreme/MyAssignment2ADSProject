#include <iostream>
#include <string>
#include <chrono> 
#include <fstream> 
#include <windows.h> 
#include <vector>

using namespace std;

void main()
{
	ifstream readFile;
	readFile.open("Test.txt");
	int order;
	readFile >> order;
	int complexity;
	readFile >> complexity;
	int numberOfNumbers;
	readFile >> numberOfNumbers;
	vector<int> nums;
	for (int i = 1; i <= numberOfNumbers; i++)
	{
		int temp;
		readFile >> temp;
		nums.push_back(temp);
	}
	cout << "order " << order << endl;
	cout << "complexity " << complexity << endl;
	cout << "Number of Numbers " << numberOfNumbers << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;

	system("pause");
}