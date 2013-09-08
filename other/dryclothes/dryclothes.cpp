// dryclothes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;


int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	int *r = (int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		int hh,cc;
		cin >> hh >> cc;
		int *h = (int *)malloc(sizeof(int)*hh);
		int *c = (int *)malloc(sizeof(int)*cc);
		for(int j=0;j<hh;j++)
		{
			int jj;
			cin >> jj;
			h[j] = jj;
		}
		for(int k=0;k<cc;k++)
		{
			int kk;
			cin >> kk;
			c[k] = kk;
		}
		for(int y=0;y<cc-1;y++)
			for(int z=0;z<cc-(y+1);z++)
			{
				if(c[z]<c[z+1])
				{
					int temp;
					temp = c[z];
					c[z] = c[z+1];
					c[z+1] = temp;
				}
			}
		int flag = 0;
		for(int ccc=0;ccc<cc;ccc++)
		{
			flag = 0;
			for(int hhh=0;hhh<hh;hhh++)
			{
				if(h[hhh]>=c[ccc])
				{
					h[hhh] = 0;
					flag = 1;
					break;
				}
			}
			if(flag == 0) break;
		}
		r[i] = flag;
	}
	for(int x=0;x<n;x++)
	{
		if(r[x]==0)
			cout << "Poor Louty :(" << endl;
		else 
			cout << "Lucky Louty :)" << endl;
	}
	return 0;
}
