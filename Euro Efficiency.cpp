#include "stdio.h"
#include "cmath"
#include "cstring"
#include "algorithm"
#include "iostream"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "map"
#define lson root<<1
#define rson root<<1|1
#define lowbit(i) i&(-i)
#define debug(x) cout<<#x<<"="<<x<<endl;
#define here cout<<endl<<"_______________here "<<endl;
#define INF 0x7f7f7f7f
#define Prime 999983
#define N 10500
using namespace std;
int main()
{
   //#ifndef ONLINE_JUDGE
   //freopen("input.txt","r",stdin);
   //#endif
   int T, face[6], dp[N], tot, maxx;
   scanf("%d", &T);
   while(T--)
   {
       maxx = 0; tot = 0;
       for(int i = 0; i < 6; i++)
             scanf("%d", face + i);
       memset(dp, 9999, sizeof(dp));
       dp[0] = 0;
       for(int i = 0; i < 6; i++)
            for(int j = face[i]; j < N; j++)
                  dp[j] = min(dp[j], dp[j - face[i]] + 1);
            
       for(int i = 0; i < 6; i++)
           for(int j = N - face[i] - 1; j >= 0; j--)
                  dp[j] = min(dp[j], dp[j + face[i]] + 1);
       
      for(int i = 1; i <= 100; i++)
      {
           maxx = max(maxx, dp[i]);
           tot += dp[i];
      }
      printf("%.2f %d\n", (tot * 1.0)/100, maxx);
    }
    return 0;
}
