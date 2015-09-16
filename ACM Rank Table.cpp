
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
#define N 1050
using namespace std;
typedef struct node
{
					int id, tot, cost;
					bool operator < (const node &o) const{
											if(tot == o.tot)
											{
																if(cost == o.cost)
																			return id < o.id;
																return cost < o.cost;
											}
											return tot > o.tot;
					}
}node;

typedef struct subm
{
				int tid, p, t, can;
				bool operator < (const subm &o) const{
									return t < o.t;     
				}
}subm;

node team[N];
subm subs[N];

int reject[N][25], flag[N][25];
int main()
{
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		#endif
		int n, m;
		while(~scanf("%d%d", &n, &m))
		{
							memset(flag, 0, sizeof(flag));
							memset(reject, 0, sizeof(reject));
			 
							for(int i = 1; i <= n; i++)
							{
												team[i].id = i;
												team[i].tot = team[i].cost = 0;
							}
			 
							for(int i = 0; i < m; i++)
										scanf("%d%d%d%d", &subs[i].tid, &subs[i].p, &subs[i].t, &subs[i].can);
							sort(subs, subs + m);
			 
							for(int i = 0; i < m; i++)
							{
												if(flag[subs[i].tid][subs[i].p]) continue;
												if(subs[i].can){
																	team[subs[i].tid].tot++;
																	team[subs[i].tid].cost += reject[subs[i].tid][subs[i].p] * 20 * 60 + subs[i].t;
																	flag[subs[i].tid][subs[i].p] = 1;
												}else{
																	reject[subs[i].tid][subs[i].p]++;
												}
							}
							sort(team + 1, team + n + 1);
							for(int i = 1; i < n; i++)
										printf("%d ", team[i].id);
							printf("%d\n", team[n].id);
		}
		return 0;
}





		这是一道要求模拟ACM比赛排名的题目..

		这里重温一下ACM的计分规则吧 = =

		一道题的花费时间等于从比赛开始的时间直到AC这道题的时间 加上 罚时(AC这道题之前提交的次数 * 20分钟)

		然后排名首先是按照解决问题的数量来排名(解出题多的优先), 若两队解出题的数目相等， 则按照解出题目的总花费时间

		来进行排名(花费时间少的优先), 若花费时间也是相等的则就按照队伍的编号排名(编号小的优先)

		这道题给出的每组提交数据时间不一定是递增的， 所以一开始要将提交数据按照时间来一次升序排列(这样做的目的是为了防止

		计算因为在AC之后的WA所造成的罚时， 因为有可能一个队伍AC了某道题目之后再次提交该道题目)


		A完这道题之后去网上搜了搜其他大牛的代码， 发现自己的代码和他们的还是有很大的差距， 时间复杂度以及空间复杂度上

		还有很大的提升空间， 加油吧  = =