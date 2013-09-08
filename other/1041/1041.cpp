// 1041.cpp : Defines the entry point for the console application.
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
		r[i] = 0;
		int C,N;
		cin >> C >> N;
		int * w = (int *)malloc(sizeof(int)*N);
		for(int j=0;j<N;j++)
		{
			cin >> w[j];
		}
		for(int ii=0;ii<N-1;ii++)
			for(int jj=0;jj<N-1-ii;jj++)
			{
				if(w[jj]>w[jj+1])
				{
					int temp;
					temp = w[jj];
					w[jj] = w[jj+1];
					w[jj+1] = temp;
				}
			}
		int sum = 0;
		for(int t=0;t<N;t++)
		{
			if((sum+w[t])<=C)
				sum = sum + w[t];
			else 
				break;
		}
		r[i] = sum;
	}
	for(int x=0;x<n;x++)
		cout << r[x] << endl;
	return 0;
}
