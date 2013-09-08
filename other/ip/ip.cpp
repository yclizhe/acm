// ip.cpp : Defines the entry point for the console application.
//

#include "math.h"
#include "iostream"
using namespace std;

int count(char *c)
{
	int co = 0;
	int sum = 0;
	for(int i=0;i<strlen(c);i++)
	{
		if(c[i]>='0'&&c[i]<='9')
			co++;
	}
	if(co==0 || co>3) sum = 1000;
	for(int j=0;j<co;j++)
	{
		sum = sum + (c[j]-'0')*pow(10,co-j-1);
	}
	return sum;
}

int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	int * r = (int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		char * ch = (char *)malloc(sizeof(char)*15);
		cin >> ch;
		int flag = 1;
		char * ct[10];
		for(int y=0;y<10;y++)
			ct[y] = (char *)malloc(sizeof(char)*5);
		int co = 0;
		int cc = 0;
		for(int j=0;j<strlen(ch);j++)
		{
			if(ch[j]=='.')
			{
				
				co = 0;
				cc++;
			} 
			else
			{
				ct[cc][co] = ch[j];
				co++;
			}
		}
		for(int z=0;z<=cc;z++)
		{
			if(count(ct[z])>=0&&count(ct[z])<=255)
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if(cc>=4)
			flag = 0;
		r[i] = flag;
	}
	for(int k=0;k<n;k++)
	{
		if(r[k]==1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
