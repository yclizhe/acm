#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#define INF 1<<31
int getNext(int* m, int M, int x) {
	int r;
	if(m[x]!=INF)
		r = x + m[x];
	else
		r = x;
	if(r>M+1)
		r = M+1;
	return r;

}
int main() {
	int N;
	double ** dp;
	int * m;
	cin >> N;
	while(N--) {
		int M,T;
		cin >> M >> T;
		dp =  new double* [M+2];
		m = new int[M+3];
		memset(m,0,4*(M+3));
		for(int i=0; i<=M+1; i++) {
			dp[i] = new double[T+1];
			memset(dp[i],0,8*(T+1));
			if(i>0 && i<M+1) {
                m[i] = INF;
                int x;
                if(cin >> x)
                    m[i] = x;
                else {
                    cin.clear();
                    cin.ignore();
                }

			}
		}

		dp[0][0] = 1;
		m[M+2] = -1;
			for(int j=0; j<=T; j++) 
				for(int i=0; i<=M; i++){
                        if(m[i+1] == INF)
                               dp[getNext(m,M,i+1)][j+2] += dp[i][j]*0.5;
                        else
                                dp[getNext(m,M,i+1)][j+1] += dp[i][j]*0.5;
                        if(m[i+2] == INF)
                               dp[getNext(m,M,i+2)][j+2] += dp[i][j]*0.5;
				       else
                            dp[getNext(m,M,i+2)][j+1] += dp[i][j]*0.5;
				
			}
		double re = 0;
		for(int i=0; i<=T; i++)
			re += dp[M+1][i];

        if(re > 0.5)
            cout << fixed << setprecision(4) << "Bet for. " << re << endl;
        else if (re < 0.5)
            cout << fixed << setprecision(4) << "Bet against. " << re << endl;
		else
            cout << fixed << setprecision(4) << "Push. " << re << endl;
	}
}

