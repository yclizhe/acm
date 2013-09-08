// 1006.cpp : Defines the entry point for the console application.
//

#include "iostream"
using namespace std;

int max(int a,int b ,int c ,int d)
{
	int m1,m2;
	if(a>b)
		m1 = a;
	else
		m1 = b;
	if(c>d)
		m2 = c;
	else
		m2 = d;
	if(m1>m2)
		return m1;
	else
		return m2;
}

int getMAXPATH(int i,int j,int m,int n,int ** a)
{
	if(a[i][j]==20000)
		return -1;
	else
	{
		if(a[i][j]<=a[i-1][j]&&a[i][j]<=a[i+1][j]&&a[i][j]<=a[i][j-1]&&a[i][j]<=a[i][j+1])
			return 0;
		else
		{
			int aa = 0; int bb = 0; int cc = 0; int dd = 0;
			if(a[i-1][j]<a[i][j])
				aa = getMAXPATH(i-1,j,m,n,a);
			if(a[i+1][j]<a[i][j])
				bb = getMAXPATH(i+1,j,m,n,a);
			if(a[i][j-1]<a[i][j])
				cc = getMAXPATH(i,j-1,m,n,a);
			if(a[i][j+1]<a[i][j])
				dd = getMAXPATH(i,j+1,m,n,a);
			return max(aa,bb,cc,dd)+1;
		}
	}
}



int main(int argc, char* argv[])
{
	int m ,n;
	cin >> m >> n;
	//int ** a = (int ** )malloc(sizeof(int *)*(m+2));
	int ** a = new int* [m+2] ;
	for(int ttt=0;ttt<m+2;ttt++)
	{
//		a[ttt] = (int *)malloc(sizeof(int)*(n+2));
		a[ttt] = new int[n+2];
	}
	for(int t=1;t<=m;t++)
	{
		for(int s=1;s<=n;s++)
		{
			cin >> a[t][s];
		}
	}
	for(int tt=0;tt<m+2;tt++)
	{
		a[tt][0] = 20000;
		a[tt][n+1] = 20000;
	}
	for(int ss=0;ss<n+2;ss++)
	{
		a[0][ss] = 20000;
		a[m+1][ss] = 20000;
	}
	int M = 0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(getMAXPATH(i,j,m,n,a)>M)
				M = getMAXPATH(i,j,m,n,a);
		}
		cout << M+1 << endl;
	return 0;
}
