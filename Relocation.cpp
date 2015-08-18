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
#define N 10 
using namespace std;
int c1, c2, n, ans, w[N];
int dp1[1<<N], dp2[1<<N];

int getwei(int state)
{
     int tot(0);
     for(int i = 0; i < n; i++)
            if(state & (1<<i))
                 tot += w[i];
     return tot;
}

void DP()
{
     int tot;
     dp1[0] = dp2[0] = 0;
     ans = INF;
     for(int i = 0; i < (1<<n); i++)
     {
           tot = getwei(i);
           if(tot <= c1)
                  dp1[i] = 1;
           else
                  for(int j = 0; j < i; j++)
                         dp1[i] = min(dp1[i], dp1[i ^ j] + dp1[j]);

           if(tot <= c2)
                  dp2[i] = 1;
           else
                  for(int j = 0; j < i; j++)
                         dp2[i] = min(dp2[i], dp2[i ^ j] + dp2[j]);
     }
     for(int i = 0; i < (1<<n); i++)
        for(int j = 0; j < (1<<n); j++)
              if( (i | j) == (1<<n) - 1)
                      ans = min(ans, max(dp1[i], dp2[j]));
}

int main()
{
   //#ifndef ONLINE_JUDGE
   //freopen("input.txt","r",stdin);
   //#endif
   int T, t(1);
   scanf("%d", &T);
   while(T--)
   {
       scanf("%d%d%d", &n, &c1, &c2);
       for(int i = 0; i < n; i++)
             scanf("%d", w + i);
      
       memset(dp1, 9999, sizeof(dp1));
       memset(dp2, 9999, sizeof(dp2));

       DP();
       printf("Scenario #%d:\n%d\n\n",t++, ans);       
   }
   return 0;
}

