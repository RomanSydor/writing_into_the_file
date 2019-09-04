#include "pch.h"
#include <iostream>
#include "fstream"
using namespace std;

float function(float x)
{
	return x * x;
}

int main() 
{
	int a, b, step, i, choose;
	int j = 0;
//start:
	cout << "Input first point: ";
	cin >> a;
	cout << "Input last point: ";
	cin >> b;
	cout << "Input step: ";
	cin >> step;
	cout << endl;

	ofstream result_out;
	result_out.open("Result.txt");
	if (!result_out.is_open())
	{
		cout << "File wasn't opened!" << endl;
	}
	else
	{
		cout << "File was opened, result has save!" << endl;
		for (i = a; i <= b; i += step)
		{
			j++;
			result_out << j << ") " << i << " * " << i << " = " << function(i) << endl;
		}
		result_out.close();
	}

	cout << "Do you want to see the result in console? (1 - yes; 2 - no)" << endl;
	cin >> choose;
	if (choose == 1)
	{
		ifstream result_in;
		result_in.open("Result.txt");
		if (!result_in.is_open())
		{
			cout << "File wasn't opened!" << endl;
		}
		else
		{
			char ch;
			cout << endl;
			while (result_in.get(ch))
			{
				cout << ch;
			}
			result_in.close();
		}
	}

	/*cout << "Do you want to repeat? (1 - yes; 2 - no)" << endl;
	cin >> choose;
	if (choose == 1) goto start;
	*/
	return 0;
}

