// 1056.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
void reverse(char * c)
{
	for(int i=0;i<(strlen(c)-1)/2;i++)
	{
		char t;
		t = c[i];
		c[i] = c[strlen(c)-1-i];
		c[strlen(c)-1-i] = t;
	}
}


int main(int argc, char* argv[])
{

	int n;
	cin >> n;
	char** r = (char **)malloc(sizeof(char*)*n);
	for(int i=0;i<n;i++)
	{
		r[i] = (char*)malloc(sizeof(char)*200);
		int m;
		cin >> m;
		char ** ch = (char **)malloc(sizeof(char*)*m);
		for(int j=0;j<m;j++)
		{
			ch[j] = (char*)malloc(sizeof(char)*20);
			cin >> ch[j];
			reverse(ch[j]);
			if(j!=0)
			{
				r[i] = strcat(strcat(r[i]," "),ch[j]);
			}
			else 
				r[i] = ch[j];
		}
	
	}
	for(int t=0;t<n;t++)
	{
		cout << "." << r[t] << endl;
	}
	return 0;
}
