
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
#define N 6050
using namespace std;
typedef struct
{
				int id, next;
}node;

stack<int>Stack;
node edge[N];
int n, t, head[1050];
bool instack[1050];
int idex, lnc, LOW[1050],DFN[1050], du[1050], id[1050];

void addedge(int a, int b)
{
				edge[t].id = b;
				edge[t].next = head[a];
				head[a] = t++;
}

void tarjan(int cur)
{
					int to;
			 
					instack[cur] = true;
					Stack.push(cur);
					LOW[cur] = DFN[cur] = idex++;
			 
					for(int e = head[cur]; e != -1; e = edge[e].next)
					{
												to = edge[e].id;
											if(!DFN[to]){
																tarjan(to);
																LOW[cur] = min(LOW[cur], LOW[to]);
											}else if(instack[to]){
																LOW[cur] = min(LOW[cur], DFN[to]);
											}
					}
				 
					if(LOW[cur] == DFN[cur])
					{
											do{
															to = Stack.top();
															Stack.pop();
															instack[to] = false;
															id[to] = lnc;
											}while(to != cur);
											lnc++;
					}
}

bool topsort()
{
						int to, tot, goal;
						memset(du, 0, sizeof(du));
						for(int i = 1; i <= n; i++)
						{
											for(int e = head[i]; e != -1; e = edge[e].next)
											{
																to = edge[e].id;
																if(id[i] != id[to])
																			du[id[to]]++;
											}
						}
			 
						while(1)
						{
											tot = 0; goal = 0;
											for(int i = 1; i < lnc; i++)
											{
																	if(du[i] == 0)
																	{
																						tot++;
																						goal = i;
																	}
											}
											if(tot == 0) break;
											if(tot > 1) return false;
											du[goal] = INF;
											for(int i = 1; i <= n; i++)
											{
																	if(id[i] == goal)
																	{
																						for(int e = head[i]; e != -1; e = edge[e].next)
																						{
																												to = edge[e].id;
																												du[id[to]]--;
																						}
																	}
											}
						}
						return true;
}

int main()
{
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		#endif
		int a, b;
		int T, m;
		scanf("%d", &T);
		while(T--)
		{
						t = 0; idex = 1; lnc = 1;
						scanf("%d%d", &n, &m);
						memset(id, 0, sizeof(id));
						memset(LOW, 0, sizeof(LOW));
						memset(DFN, 0, sizeof(DFN));
						memset(head, -1, sizeof(head));
						memset(instack, false, sizeof(instack));
						 
						for(int i = 0; i < m; i++)
						{
											scanf("%d%d", &a, &b);
											addedge(a, b);
						}
						for(int i = 1; i <= n; i++)
										if(!LOW[i])
													tarjan(i);
						if(topsort())
									printf("Yes\n");
						else
									printf("No\n");
		}
		return 0;
}





		 要你判断一个有向图是否满足任意两点(a, b）都有路径可达（可以是从a到b， 也可以从b到a）....

		 我们用Tarjan算法进行缩点操作之后， 缩点之后这个图就变成了一棵树， 入度为0的块就是这棵树的根， 这棵树

只能为单链， 不能有分叉(若有分叉， 则必定不能满足任意两点都可达) ， 也就是拓扑排序的过程中某一个环节不能出现

多个入度为0的点~