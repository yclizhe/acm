    #include <cstring>  
    #include <string>  
    #include <cstdio>  
    #include <algorithm>  
    #include <queue>  
    #include <cmath>  
    #include <vector>  
    #include <cstdlib>  
    #include <iostream>  
      
    using namespace std;  
    const int INF=100000000;  
    int main()  
    {  
       int m,t,n;  
       int ins[60];     //保存每个格子的指令  
       double dp[60][60];  
       char str[5];  
       cin>>n;  
       while(n--)  
       {  
           cin>>m>>t;  
           ins[0]=0;   //起点指令  
           ins[m+1]=0;   //终点指令  
           ins[m+2]=-1;   //超过终点时回到终点  
           for(int i=1;i<=m;i++)  
           if(scanf("%d",&ins[i])==0)  
           {  
               scanf("%s",str);  
               ins[i]=INF;  
           }  
           memset(dp,0,sizeof(dp));  
           dp[0][0]=1.0;  
           for(int j=0;j<=t;j++)  
           for(int i=0;i<=m;i++)  
           {  
               //抛一次硬币后，可能走一格，也可能走两格  
               if(ins[i+1]==INF)       //若下一格指令为L，失去一次抛硬币机会，更新dp[i+1][j+2]  
               dp[i+1][j+2]+=dp[i][j]*0.5;  
               else  
               dp[i+1+ins[i+1]][j+1]+=dp[i][j]*0.5;  
               if(ins[i+2]==INF)      //若下两格指令为L，失去一次抛硬币机会，更新dp[i+2][j+2]  
               dp[i+2][j+2]+=dp[i][j]*0.5;  
               else  
               dp[i+2+ins[i+2]][j+1]+=dp[i][j]*0.5;  
           }  
           for(int i=0;i<t;i++)  
           dp[m+1][t]+=dp[m+1][i];  
           if(dp[m+1][t]==0.5)  
           printf("Push. 0.5000\n");  
           else if(dp[m+1][t]>0.5)  
           printf("Bet for. %.4f\n",dp[m+1][t]);  
           else  
           printf("Bet against. %.4f\n",dp[m+1][t]);  
       }  
       return 0;  
    }  
