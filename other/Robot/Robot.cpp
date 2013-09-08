// Robot.cpp : Defines the entry point for the console application.
/*
Description

One day you saw a recruitment notice from the Robot-interested Group on BBS and you decided to have a try. In the robot exhibition on the recruiting day, you were attracted by a small lovely robot which could only move 1 or 2 meters a time. Then the teacher Fatty in the Robot-interested Group came to ask you an interesting question: how many different routes can the robot take to do an n-meter move?

Input

The first line contains a number m.
In the following m lines, each line contains a number n which is less than 46.

Output

The output should contain m lines. Each line indicates the amount of different routes for every n in the corresponding line in the input.

Sample Input

2
3
10
Sample Output
3
89  */


#include "stdafx.h"
#include "iostream"
using namespace std;

int f(int n)
{
	switch(n)
	{
		case 1:
		{
			return 1;
			break;
		}
		case 2:
		{
			return 2;
			break;
		}
		default:
		{	
			return f(n-1)+f(n-2);
			break;
		}
	}
}


int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	int * a = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int j=0;j<n;j++)
	{
		cout << f(a[j]) << endl;
	}

	return 0;
}
