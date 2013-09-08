// id card.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "math.h"
using namespace std;

int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	int *r = (int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		char * ch = (char *)malloc(sizeof(char)*18);
		cin >> ch;
		int sum = 0;
		for(int j=0;j<17;j++)
		{
			sum = sum + (ch[j]-'0')*pow(2,17-j);
		}
		int y = sum % 11;
		switch(y)
		{
		case 0:
			{
				if(ch[17]=='1')
					r[i] = 1;
				else 
					r[i] = 0;
				break;
			}
			case 1:
			{
				if(ch[17]=='0')
					r[i] = 1;
				else 
					r[i] = 0;
				break;
			}
			case 2:
			{
				if(ch[17]=='x')
					r[i] = 1;
				else 
					r[i] = 0;
				break;
			}
			case 3:
			{
				if(ch[17]=='9')
					r[i] = 1;
				else 
					r[i] = 0;
				break;
			}
			case 4:
			{
				if(ch[17]=='8')
					r[i] = 1;
				else 
					r[i] = 0;
				break;
			}
			case 5:
			{
				if(ch[17]=='7')
					r[i] = 1;
				else 
					r[i] = 0;
				break;
			}
			case 6:
			{
				if(ch[17]=='6')
					r[i] = 1;
				else 
					r[i] = 0;
				break;
			}
			case 7:
			{
				if(ch[17]=='5')
					r[i] = 1;
				else 
					r[i] = 0;
				break;
			}
			case 8:
			{
				if(ch[17]=='4')
					r[i] = 1;
				else 
					r[i] = 0;
				break;
			}
			case 9:
			{
				if(ch[17]=='3')
					r[i] = 1;
				else 
					r[i] = 0;
				break;
			}
			case 10:
			{
				if(ch[17]=='2')
					r[i] = 1;
				else 
					r[i] = 0;
				break;
			}
		}
	}
	for(int k=0;k<n;k++)
	{
		if(r[k]==1)
			cout << "Legal" << endl;
		else 
			cout << "Illegal" << endl;
	}
	return 0;
}
