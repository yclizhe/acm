// sqrt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "math.h"
using namespace std;
int a(int i,int n)
{
	switch(i)
	{
	case 0:
		{
			return floor(sqrt(n));
			break;
		}
	default:
		{
			return floor(k(i-1,n));
			break;
		}
	}
}
double  b(int i,int n)
{
	switch(i)
	{
	case 0:
		{
			return floor(sqrt(n));
			break;
		}
	default:
		{
			return a(i,n)*c(i-1,n)-b(i-1,n);
			break;
		}
	}
}

double c(int i,int n)
{
	switch(i)
	{
	case 0:
		{
			return n-b(0,n)*b(0,n);
			break;
		}
	default:
		{
			return (n-b(i,n)*b(i,n))/c(i-1,n);
			break;
		}
	}
}

double k(int i,int n)
{
	return (sqrt(n) + b(i,n))/c(i,n);
}

int main(int argc, char* argv[])
{

	return 0;
}
