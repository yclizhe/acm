// 123.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int f(int n,int k)
{

	double s = 1;
	double c = 1;
	int r = 1;
	for(int i=0;i<k;i++)
	{
		s = s * (n-k+1-i);
		c = c * (k-i);
	}
	
	return s/c;

}


int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	long * r = (long*)malloc(sizeof(long)*n);
	for(int i=0;i<n;i++)
	{
		int n,k;
		cin >> n >> k;
		r[i] = f(n,k);
	}
	for(int j=0;j<n;j++)
	{
		cout << r[j] << endl;
	}
	return 0;
}
