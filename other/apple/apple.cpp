// apple.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "math.h"
using namespace std;


int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	double *r = (double *)malloc(sizeof(double)*n);
	for(int i=0;i<n;i++)
	{
		double a,b;
		cin >> a >> b;
		r[i] = sqrt(2*(a-b)/9.8);
	}
	for(int j=0;j<n;j++)
	{
		printf("%.2f\n",r[j]);
	}
	return 0;
}
