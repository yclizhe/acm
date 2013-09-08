#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int len1, len2;
int dp[1005][1005];//  dp[i][j] 表示 s1[0...i-1]变换到  s2[0...j-1] 的最短编辑距离 
char s1[1005], s2[1005];

inline int min(int a, int b)
{
    return a < b ? a : b;
}

inline int max(int a, int b)
{
    return a > b ? a : b;
}

void init()
{
    memset(dp, 0, sizeof(dp));
    int tmp = max(len1, len2);
    for(int i = 1; i <= tmp; ++i)  // 注意初始化 
    {
        dp[i][0] = dp[0][i] = i;
    }
}

int DP()
{
    for(int i = 0; i < len1; ++i)
        for(int j = 0; j < len2; ++j)
        {
            if(s1[i] == s2[j])
                dp[i+1][j+1] = min(min(dp[i+1][j]+1, dp[i][j+1]+1), dp[i][j]);
            else 
                dp[i+1][j+1] = min(min(dp[i+1][j]+1, dp[i][j+1]+1), dp[i][j]+1); 
        }
    return dp[len1][len2];
}

int main()
{
    while(cin >> len1 >> s1)
    {
        cin >> len2 >> s2;
        init();
        cout << DP() << endl;
    }
    return 0;
}
