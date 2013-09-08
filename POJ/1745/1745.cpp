#include <iostream>
#include <cstring>
#define MOD(a,k) ((a)%(k)<0?((a)%(k)+k):((a)%(k)))
int N,K;
bool dp[2][105];
int a[10005];
using namespace std;

int main()
{

    memset(dp,0,sizeof(dp));
    memset(a,0,sizeof(a));
    cin >> N >> K;
    for(int i=0; i<N; i++)
        cin >> a[i];
    dp[0][MOD(a[0],K)] = true;
	int current = 0,pre = 0;
    for(int i=1; i<N; i++)
        for(int j=0; j<K; j++) {
			current = i & 1;
			pre = (i-1) & 1;
            int cur = MOD(a[i],K);
            if(dp[pre][MOD(j+cur,K)] || dp[pre][MOD(j-cur,K)])
                dp[current][j] = true;
            else
                dp[current][j] = false;
    }
    if(dp[current][0])
        cout << "Divisible" << endl;
    else
        cout << "Not divisible" << endl;
    return 0;
}
