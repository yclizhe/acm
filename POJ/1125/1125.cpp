#include <iostream>
using namespace std;
int d[105][105];

#define MAX 1000000

int main() {
   while(1) {
         int N;
        cin >> N;
        if(N==0)
            break;
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
              if(i==j)
                  d[i][j] = 0;
              else
                d[i][j] = MAX;
        for(int i=1; i<=N; i++) {
            int n,a,b;
            cin >> n;
            if(n==0)
                continue;
            for(int j=0; j<n; j++) {
                cin >> a >> b;
                d[i][a] = b;
            }
        }

        for(int k=1; k<=N; k++)
            for(int i=1; i<=N; i++)
                for(int j=1; j<=N; j++)
                    if(d[i][k]+d[k][j] < d[i][j])
                        d[i][j] = d[i][k] + d[k][j];

        //poj 1125
        //floyd算法后，第i行最大值表示以节点i为根的树的最大深度
        //也就是以i开始的最终传播时间
        int min = MAX, minid = -1;
        for(int i=1; i<=N; i++) {
           int max = 0;
           for(int j=1; j<=N; j++) {
             if(d[i][j]==MAX) {
                max = MAX;
                break;
            }
            else
                max = max>d[i][j]?max:d[i][j];
           }
          if(max < min) {
            min = max;
            minid = i;
          }
        }
        if(min == MAX)
            cout << "disjoint" << endl;
        else
            cout << minid << " " << min <<endl;

   }
}
