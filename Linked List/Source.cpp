#include <iostream>
#include <string>
#include <chrono> 
#include <fstream>
#include "List.h"

using namespace std;

void main()
{
	List listFront;
	List listEnd;

	ifstream readFile;
	readFile.open("input-a1q1.txt");
	int numberOfNumbersInList;
	readFile >> numberOfNumbersInList;

	std::chrono::steady_clock::time_point beginFrontInsert = std::chrono::steady_clock::now();
	for (int i = 0; i < numberOfNumbersInList; i++)
	{
		listFront.insertAtFront(rand());
	}
	std::chrono::steady_clock::time_point endFrontInsert = std::chrono::steady_clock::now();

	std::chrono::steady_clock::time_point beginEndInsert = std::chrono::steady_clock::now();
	for (int i = 0; i < numberOfNumbersInList; i++)
	{
		listEnd.insertAtEnd(rand());
	}
	std::chrono::steady_clock::time_point endEndInsert = std::chrono::steady_clock::now();

	std::chrono::steady_clock::time_point beginFrontDelete = std::chrono::steady_clock::now();
	for (int i = 0; i < numberOfNumbersInList; i++)
	{
		listFront.deleteAtFront();
	}
	std::chrono::steady_clock::time_point endFrontDelete = std::chrono::steady_clock::now();

	std::chrono::steady_clock::time_point beginEndDelete = std::chrono::steady_clock::now();
	for (int i = 0; i < numberOfNumbersInList; i++)
	{
		listEnd.deleteAtEnd();
	}
	std::chrono::steady_clock::time_point endEndDelete = std::chrono::steady_clock::now();


	ofstream  writeFile;
	writeFile.open("output-a1q1.txt");
	writeFile << std::chrono::duration_cast<std::chrono::milliseconds>(endFrontInsert - beginFrontInsert).count() << endl;
	writeFile << std::chrono::duration_cast<std::chrono::milliseconds>(endEndInsert - beginEndInsert).count() << endl;
	writeFile << std::chrono::duration_cast<std::chrono::milliseconds>(endFrontDelete - beginFrontDelete).count() << endl;
	writeFile << std::chrono::duration_cast<std::chrono::milliseconds>(endEndDelete - beginEndDelete).count() << endl;

	system("pause");
}