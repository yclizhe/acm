// letter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int check1(char ch[],char c)
{
	int flag = 0;
	for(int k=0;k<26;k++)
	{
		if(ch[k] == c || c == ch[k] - 32)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

int check2(char ch[],char c)
{
	int flag = 0;
	for(int k=0;k<26;k++)
	{
		if(ch[k] == c || c == ch[k] + 32)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	int * r = (int *)malloc(sizeof(int)*n);
	char ch[26];
	for(int i=0;i<n;i++)
	{
		for(int t=0;t<26;t++)
			ch[t] = ' '; 
		char * c = (char *)malloc(sizeof(char)*100);
		cin >> c;
		int count = 0;
		for(int j=0;j<strlen(c);j++)
		{
			if((c[j]>='A'&&c[j]<='Z'))
			{
				if(check1(ch,c[j])==0)
				{
					ch[count] = c[j];
					count++;
				}
			}
			if((c[j]>='a'&&c[j]<='z'))
			{
				if(check2(ch,c[j])==0)
				{
					ch[count] = c[j];
					count++;
				}
			}
		}
		r[i] = count;
	}
	for(int y=0;y<n;y++)
		cout << r[y] << endl;
	return 0;
}
