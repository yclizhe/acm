// coin1021.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;


int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	int * c = (int *)malloc(sizeof(int)*n);
	for(int ii=0;ii<n;ii++)
		c[ii] = 0;
	int op;
	cin >> op;
	int * r = (int *)malloc(sizeof(int)*op);
	for(int o=0;o<op;o++)
		r[o] = -1;
	for(int i=0;i<op;i++)
	{
		int a,b;
		cin >> a >> b;
		switch(a)
		{
			case 1:
			{
				c[b-1] = c[b-1]^1;
				break;
			}
			case 2:
			{
				int count = 0;
				for(int j=0;j<n;j++)
				{
					if(c[j] == 0) count++;
					if(count==b)
					{
						r[i] = j+1;
						break;
					}
				}
				if(count<b)
				{
					r[i] = 0;
				}
				break;
			}
			default:
				break;
		}
	}
	for(int t=0;t<op;t++)
	{
		if(r[t]==0)
			cout << "NO" << endl;
		else if(r[t]!=-1)
			cout << r[t] << endl;
	}
	return 0;
}
