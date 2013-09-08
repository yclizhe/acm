#include <iostream>
#include <cstring>
using namespace std;
#define Min(a,b) (a)>(b)?(b):(a)
int rows[6];
int rowN;
int N;
bool visited[35];
int solution[6][35];
double ans;
int main() {
	while(cin >> rowN) {
		ans = 0;
		memset(rows,0,sizeof(rows));
		memset(visited,0,sizeof(visited));
		memset(solution,0,sizeof(solution));
		if(rowN == 0)
			break;
		N = 0;
		for(int i=0; i<rowN; i++) {
			cin >> rows[i];
			N += rows[i];
		}
		ans = 1;
		for(int i=1; i<=N; i++)
			ans *= i;
		double ans2 = 1;
		for(int i=0; i<rowN; i++)
            for(int j=0; j<rows[i]; j++) {
				int t = 0;
				for(int k=i+1; k<rowN; k++)
                    if(j<rows[k])
                        t++;
				ans2 *= (double)(t+rows[i]-1-j+1);
			}
		unsigned int re;
		if(ans-ans2 < 1)
			re = 1;
		else {
		ans = ans / ans2;
		re = (unsigned int)(ans-0);
		}
		cout << re << endl;
	}
}

