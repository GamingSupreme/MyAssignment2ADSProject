#include <iostream>
#include <string>
#include <chrono> 
#include <fstream> 
#include <windows.h> 

using namespace std;

void bubbleSort(int arr[], int arraySize, int order)
{
	bool sorted = false;
	while (!sorted) //loop while not sorted
	{
		//assume sorted until proven otherwise
		sorted = true;
		if (order == 0)
		{
			for (int i = 0; i <= arraySize - 1 - 1; i++)
			{
				//check if current arr[i] value is bigger then arr[i+1]
				if (arr[i] > arr[i + 1])
				{
					//MySwap(arr, i, i + 1);
					swap(arr[i], arr[i + 1]);
					sorted = false;
					//any swap wasnt a clean run
				}
			}
		}
		else if (order == 1)
		{
			for (int i = 0; i <= arraySize - 1 - 1; i++)
			{
				//check if current arr[i] value is bigger then arr[i+1]
				if (arr[i] < arr[i + 1])
				{
					//MySwap(arr, i, i + 1);
					swap(arr[i], arr[i + 1]);
					sorted = false;
				}
			}
		}
	}
}

int partition(int a[], int low, int high, int order)
{
	//can decide pivot selection in different ways e.g, median of index, random, high's value
	//we'll use the value in the array at low index's position
	int pivot = a[low];
	int i = low, j = high;
	//loop until i and j cross paths
	if (order == 0)
	{
		while (i < j)
		{
			//i loks for value in array which is BIGGER then pivot value
			//moving right
			do
			{
				i++;
			} while (a[i] <= pivot);//stop loop once calue in a[i] > pivot

			//j looks for value in array which is SMALLER then pivot value
			do
			{
				j--;
			} while (a[j] > pivot);
			//IF i and j havent crossed path we can assume weve found
			//a value bigger with i and a value smaller with j, so swap them
			if (i < j)
				swap(a[i], a[j]);
		}
	}
	else if (order == 1)
	{
		while (i < j)
		{
			//i loks for value in array which is BIGGER then pivot value
			//moving right
			do
			{
				i++;
			} while (a[i] >= pivot);//stop loop once calue in a[i] > pivot

			//j looks for value in array which is SMALLER then pivot value
			do
			{
				j--;
			} while (a[j] < pivot);
			//IF i and j havent crossed path we can assume weve found
			//a value bigger with i and a value smaller with j, so swap them
			if (i < j)
				swap(a[i], a[j]);
		}
	}
	//once done, swap pivot value with wherever j ended up
	swap(a[low], a[j]);
	//return j so new quicksorts can partition
	//one left of j and one right of j
	return j;
}


void quickSort(int a[], int low, int high, int order)
{
	if (low < high)
	{
		int partitionIndex = partition(a, low, high, order);
		quickSort(a, low, partitionIndex, order);
		quickSort(a, partitionIndex + 1, high, order);
	}
}

void main()
{
	ifstream readFile;
	readFile.open("input-a1q1.txt");
	int order;
	readFile >> order;
	int complexity;
	readFile >> complexity;
	int numberOfNumbers;
	readFile >> numberOfNumbers;

	if ((order != 1 && order != 0) || (complexity != 1 && complexity != 0))
	{
		cout << "Neither a 0 or 1 are in the first and or second row, please fix this and run again";
		return;
	}

	if (numberOfNumbers < 0)
	{
		cout << "The in the third row is negative, please change to positive and try again";
		return;
	}


	int* arr = new int[numberOfNumbers];
	for (int i = 0; i < numberOfNumbers; i++)
	{
		readFile >> arr[i];
		if (i < (numberOfNumbers - 1))
		{
			if (readFile.eof())
			{
				cout << "there were less numbers in row four then specified, please put in the right amount and try again" << endl;
				return;
			}
		}
	}
	
	if (complexity == 0)
	{
		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		quickSort(arr, 0, numberOfNumbers, order);
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		ofstream  writeFile;
		writeFile.open("output-a1q1.txt");
		writeFile << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << endl;
		for (int i = 0; i < numberOfNumbers; i++)
		{
			writeFile << arr[i];
			writeFile << " ";
		}
		delete[] arr;
	}

	else if (complexity == 1)
	{
		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		bubbleSort(arr, numberOfNumbers, order);
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		ofstream  writeFile;
		writeFile.open("output-a1q1.txt");
		writeFile << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << endl;
		for (int i = 0; i < numberOfNumbers; i++)
		{
			writeFile << arr[i];
			writeFile << " ";
		}
		delete[] arr;
	}



	system("pause");
}