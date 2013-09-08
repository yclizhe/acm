// 若雪乘法.cpp : Defines the entry point for the console application.
//
/*Description

crackerwang最近在辅导小侄女若雪做乘法作业，一遍又一遍的乘法让ACM感到厌烦，于是在闲暇之余，crackerwang决定来定义自己的乘法，并且命名为“若雪乘法”。在“若雪乘法”中，A*B定义为A中的每位数字和B中每位数字的乘积之和，比如123*45的结果为，1*4 + 1*5 + 2*4 + 2*5 + 3*4 + 3*5 = 54。 crackerwang决定考考小侄女，每次给她两个整数，范围在[1, 1,000,000,000]中，如果若雪能够给出正确结果，crackerwang就答应带她去欢乐谷Happy。但是这个问题对于还在上小学的若雪来说太困难了，于是若雪求助于各位还没进校队的ACMer，希望你能够帮助她，聪明的你能够帮她解决这个问题吗？
Input
第1行： 两个整数A和B，用空格隔开,A=B=0输入结束。

Output
第1行： 一个整数，通过“若雪乘法”得到的A*B的值。
Sampe Input
123 45
0 0
Sample Output

54   */



#include "stdafx.h"
#include "iostream"
using namespace std;
int aa[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int bb[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void f(long a,long b,int &counta,int &countb)
{
	counta = 0;
	countb = 0;
	while(a!=0)
	{	
		aa[counta] = a%10;
		a = (a-a%10)/10;
		counta++;
	}
	while(b!=0)
	{	
		bb[countb] = b%10;
		b = (b-b%10)/10;
		countb++;
	}
}



int main(int argc, char* argv[])
{
	int r[6] = {0,0,0,0,0,0};
	int count = 0;
	while(true)
	{
		long a = 100;
		long b = 100;
		cin >> a >> b;
		if(a==0&&b==0) break;
		int counta = 0;
		int countb = 0;
		f(a,b,counta,countb);
		count++;
		for(int j=0;j<counta;j++)
			for(int k=0;k<countb;k++)
			{
				r[count-1] = r[count-1] + aa[j]*bb[k];
			}

	}
	for(int t=0;t<count;t++)
		cout << r[t] << endl;
	return 0;
}
