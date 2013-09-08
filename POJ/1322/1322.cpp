#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int main() {
	int C,N,M;
	while(cin>>C && C!=0 && cin>>N>>M){
		if(N&1 && N>1001)
			N = 1001;
		else if (!(N&1) && N>1001)
			N = 1000;
		if(M>C || M>N) {
			cout << "0.000" << endl;
			continue;
		}
		double dp[1002][110];
		memset(dp, 0, sizeof(dp));

		dp[0][0] = 1;
		for(int i=1; i<N+1; i++)
			for(int j=0; j<=C&&j<=i; j++) {
                if((i+j)%2!=0) {
                    dp[i][j] = 0;
                    continue;
                    }
				if(j!=0){
                    double p = double(C-j+1) / C;
                    dp[i][j] += dp[i-1][j-1]*p;
				}

				if(j!=C) {
                    double p = double(j+1) / C;
                    dp[i][j] += dp[i-1][j+1]*p;
				}

			}

		cout << fixed;
		cout << setprecision(3) << dp[N][M] << endl;
	}

	return 0;
}

