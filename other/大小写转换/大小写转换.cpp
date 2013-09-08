// ´óĞ¡Ğ´×ª»».cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;


int main(int argc, char* argv[])
{
	char * str = (char *)malloc(sizeof(char)*20);;
	cin >> str;
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]>='A' && str[i] <='Z')
			str[i] = str[i]+32;
		cout << str[i];
	}
	cout << endl;
	return 0;
}
