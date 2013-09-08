// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
#include "stdlib.h"

int main(int argc, char* argv[])
{
	char * ch = (char *)malloc(sizeof(char)*10);
	cin >> ch;
	cout << atoi(ch);

	return 0;
}
