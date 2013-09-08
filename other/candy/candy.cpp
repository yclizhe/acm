// candy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int check(int x,int n,long int a[])
{
	int count = 1;
	long int max = a[x];
	for(int i=x;i<n;i++)
	{
		if(a[i]>max)
		{
			max = a[i];
			count++;
		}
	}
	return count;
}

int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	int * r = (int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		int s;
		cin >> s;
		long int * can = (long int *)malloc(sizeof(long int)*s);
		for(int j=0;j<s;j++)
		{
			cin >> can[j];
		}
		int max = 0;
		for(int k=0;k<s;k++)
		{
			if(check(k,s,can)>=max)
			{
				max = check(k,s,can);
			}
			else
				break;
		}
		r[i] = max;
	}
	for(int p=0;p<n;p++)
	{
		cout << r[p] << endl;
	}
	return 0;
}
