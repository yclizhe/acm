#include <iostream>
#include <cstring>
using namespace std;
#define Min(a,b) (a)>(b)?(b):(a)
int main() {
	int n,m;
	int A[101];
	int C[101];
	char B[1000];
	while(cin >> n >> m) {


		memset(A,0,sizeof(A));
		memset(C,0,sizeof(C));
		memset(B,0,sizeof(B));
		for(int i=1; i<n+1; i++)
			cin >> A[i];
		for(int i=1; i<n+1; i++)
			cin >> C[i];
		int num = 1;
		for(int i=1; i<n+1; i++)
			for(int k=1;k==k; k=k*2){
				if(C[i]-k*4+1<=0) {
					B[num++] = A[i] * k;
					if(C[i]-k*2+1 != 0)
                        B[num++] = A[i] * (C[i]-k*2+1);
					break;
				}
				B[num++] = A[i] *k;
			}


        char ** dp = new char* [num];
		if(!(n&&m))
			break;
			for(int i=0; i<num; i++) {
                dp[i] = new char[m+1];
                memset(dp[i],0,m+1);
			}
		for(int i=0; i<n+1; i++)
			dp[i][0] = 1;

		for(int i=1; i<=num-1; i++)
			for(int j=1; j<m+1; j++) {
				int mk = Min(1,j/B[i]);
				for(int k=0; k<=mk; k++) {
					dp[i][j] |= dp[i-1][j-k*B[i]];
					if(dp[i][j])
						break;
				}

			}
		int count = 0;
		for(int j=1; j<m+1; j++)
			count += dp[num-1][j];
		cout << count << endl;

		for(int i=0; i<num; i++)
            delete[] dp[i] ;
	}
	return 0;
}

