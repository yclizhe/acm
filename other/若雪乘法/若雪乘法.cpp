// ��ѩ�˷�.cpp : Defines the entry point for the console application.
//
/*Description

crackerwang����ڸ���СֶŮ��ѩ���˷���ҵ��һ����һ��ĳ˷���ACM�е��ᷳ����������Ͼ֮�࣬crackerwang�����������Լ��ĳ˷�����������Ϊ����ѩ�˷������ڡ���ѩ�˷����У�A*B����ΪA�е�ÿλ���ֺ�B��ÿλ���ֵĳ˻�֮�ͣ�����123*45�Ľ��Ϊ��1*4 + 1*5 + 2*4 + 2*5 + 3*4 + 3*5 = 54�� crackerwang��������СֶŮ��ÿ�θ���������������Χ��[1, 1,000,000,000]�У������ѩ�ܹ�������ȷ�����crackerwang�ʹ�Ӧ����ȥ���ֹ�Happy���������������ڻ�����Сѧ����ѩ��˵̫�����ˣ�������ѩ�����ڸ�λ��û��У�ӵ�ACMer��ϣ�����ܹ������������������ܹ�����������������
Input
��1�У� ��������A��B���ÿո����,A=B=0���������

Output
��1�У� һ��������ͨ������ѩ�˷����õ���A*B��ֵ��
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
