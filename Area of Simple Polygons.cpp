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
#define Prime 999983
#define N 1050
using namespace std;
struct
{
			int l,r,len;
			int s,e,tag;
}tree[N<<2];

typedef struct Line
{
			int y,x1,x2,lnc;
			bool operator < (const struct Line &o) const{
							if(y == o.y)
									return lnc > o.lnc;
							return y < o.y;
			}
}Line;

Line line[N<<2];
int n,t,x[N<<2];
map<int,int>AtoB,BtoA;
void addline(int x1, int y1,int x2,int y2)
{
			 x[t++] = x1; x[t++] = x2;

			 line[n].x1   = x1;  line[n].x2 = x2;
			 line[n].lnc = 1;
			 line[n].y   = y1;
			 n++;

			 line[n].x1   = x1;  line[n].x2 = x2;
			 line[n].lnc = -1;
			 line[n].y   = y2;
			 n++;
}

void buildtree(int root,int s,int e)
{
				tree[root].s = s;
				tree[root].e = e;
				tree[root].l = AtoB[s];
				tree[root].r = AtoB[e];
				tree[root].len = tree[root].tag = 0;
				if(s + 1 == e)
						 return ;
				int mid((s + e)>>1);
				buildtree(lson, s, mid);
				buildtree(rson, mid, e);
}

void Insert(int root,int s,int e,int tag)
{
				 if(tree[root].s + 1 == tree[root].e){
										tree[root].tag +=tag;
										tree[root].len = tree[root].tag ? BtoA[tree[root].e] - BtoA[tree[root].s] : 0;
										return ;
				 }
				 int mid((tree[root].s + tree[root].e)>>1);
				 if(s < mid)
							 Insert(lson, s, e, tag);
				 if(mid < e)
							 Insert(rson, s, e, tag);
				 tree[root].len = tree[lson].len + tree[rson].len;
}

int main()
{
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		#endif
		int x1,y1,x2,y2,total;
		while(1)
		{
						AtoB.clear();
						BtoA.clear();
						total = n = t = 0;
						scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
						if(x1 == -1) break;
						addline(x1,y1,x2,y2);
						while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2) && x1 != -1)
										addline(x1,y1,x2,y2);
						sort(x, x + t);
						sort(line, line + n);
						t  = unique(x, x + t) - x;
						for(int i = 0; i < t; i++)
						{
										AtoB[x[i]] = i + 1;
										BtoA[i + 1] = x[i];
						}
						buildtree(1, 1, t);
						for(int i = 0; i < n; i++)
						{
										 if(i == 0){Insert(1, AtoB[line[i].x1], AtoB[line[i].x2], line[i].lnc); continue;}
										 total += (line[i].y - line[i - 1].y) * tree[1].len;
										 Insert(1, AtoB[line[i].x1], AtoB[line[i].x2], line[i].lnc);
						}
						printf("%d\n",total);
		}
		return 0;
}