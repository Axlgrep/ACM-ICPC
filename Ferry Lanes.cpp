#include "cstdio"
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
#define LINF 0x7f7f7f7f7f7f7f7f
#define Prime 999983
#define N 1000500
using namespace std;
int dp[2][N];
int nc[N], sc[N], opc[N];
int spos, slnc, epos, elnc;

int main()
{
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		#endif
		int n, tmp, minn;
		int costn, costs;
		while(scanf("%d", &n) && n)
		{
							scanf("%d%d%d%d", &spos, &slnc, &epos, &elnc);
							for(int i = 0; i < n; i++)
										scanf("%d", nc + i);
							for(int i = 0; i <= n; i++)
										scanf("%d", opc + i);
							for(int i = 0; i < n; i++)
										scanf("%d", sc + i);
							if(slnc > elnc)
							{
												tmp = slnc; slnc = elnc; elnc = tmp;
												tmp = spos; spos = epos; epos = tmp;
							}
							dp[spos][slnc] = 0;
			 
							minn = opc[slnc];
							costn = costs = 0;
							for(int i = slnc; i > 0; i--)
							{
												costn += nc[i - 1];
												costs += sc[i - 1];
												minn =min(minn, costn + costs + opc[i - 1]);
							}
							dp[!spos][slnc] = minn;
			 
							for(int i = slnc + 1; i <= n; i++)
							{
													dp[0][i] = min(dp[0][i - 1] + nc[i - 1], dp[1][i - 1] + sc[i - 1] + opc[i]);
													dp[1][i] = min(dp[1][i - 1] + sc[i - 1], dp[0][i - 1] + nc[i - 1] + opc[i]);
							}
			 
							minn = opc[elnc];
							costn = costs = 0;
							for(int i = elnc; i < n; i++)
							{
													costn += nc[i];
													costs += sc[i];
													minn = min(minn, costn + costs + opc[i + 1]);
							}   
							dp[epos][elnc] = min(dp[epos][elnc], dp[!epos][elnc] + minn);
			 
							printf("%d\n", dp[epos][elnc]);
		}
		return 0;
}//DP 1094ms
