// race.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;


int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	int * r = (int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		int m,f;
		cin >> m;
		cin >> f;
		int count = 0;
		int * sp = (int *)malloc(sizeof(int)*m);
		int * sl = (int *)malloc(sizeof(int)*m);
		double * t = (double *)malloc(sizeof(int)*m);
		for(int j=0;j<m;j++)
		{
			cin >> sp[j] >> sl[j];
			t[j] = (double)(f-sl[j])/sp[j];
			if(j>=1)
			{
				if(t[j]>t[0]) count++;
			}
		}
		r[i] = count;
		free(sp);
		free(sl);
	}
	for(int k=0;k<n;k++)
		cout << r[k] << endl;
	return 0;
}
