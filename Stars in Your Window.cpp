#include "cstdio"

#include "cstring"
#include "cmath"
#include "algorithm"
#include "iostream"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "map"
#define lson root<<1
#define rson root<<1|1
#define LL   long long
using namespace std;
typedef struct Line
{
			long long  x,y,rank;
			bool operator<(const Line &o)const{
						 return y<o.y;
			}
}Line;
typedef struct
{
			long long s,e,maxx,rank;     //用maxx存区域[s,e]中最大的亮度值，rank既是懒标记,又是该区间的亮度值；
}node;

node tree[30050<<2];
Line line[30050];
long long  n,w,h,posx[30050];

void buildtree(LL root,LL s,LL e)
{
			 tree[root].s=s;
			 tree[root].e=e;
			 tree[root].maxx=tree[root].rank=0;
			 if(s==e)
						return ;
			 LL mid((s+e)>>1);
			 buildtree(lson,s,mid);
			 buildtree(rson,mid+1,e);
}

void pushdown(LL root)
{
			 if(tree[root].rank){
							tree[lson].maxx+=tree[root].rank;
							tree[lson].rank+=tree[root].rank;
							tree[rson].maxx+=tree[root].rank;
							tree[rson].rank+=tree[root].rank;
							tree[root].rank=0;
			 }
}

void update(LL root,LL s,LL e,LL rank)
{
				if(s<=tree[root].s&&tree[root].e<=e){
									tree[root].rank+=rank;
									tree[root].maxx+=rank;
									return ;
				}
				pushdown(root);
				LL mid((tree[root].s+tree[root].e)>>1);
				if(s<=mid)
							 update(lson,s,e,rank);
				if(mid<e)
							 update(rson,s,e,rank);
				tree[root].maxx=max(tree[lson].maxx,tree[rson].maxx);
}

int main()
{
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		#endif
		long long i,j,x,y,rank,t,k;
		while(~scanf("%lld%lld%lld",&n,&w,&h))
		{
					 long long ans(0);
					 map<LL,LL>pos;
					 for(i=t=0;i<n;i++){
								scanf("%lld%lld%lld",&x,&y,&rank);
								line[i].x=x;line[i].y=y;  line[i].rank=rank;
								posx[t++]=x;
								posx[t++]=x+w;
					 }
					 sort(posx,posx+t);
					 sort(line,line+n);
					 t=unique(posx,posx+t)-posx;
					 for(i=0;i<t;i++)
								 pos.insert(make_pair(posx[i],i));   //因为坐标的范围太大，所以离散化一下(映射)；
					 buildtree(1,0,t-1);
					 for(i=j=0;i<n;i++)
					 {
										update(1,pos[line[i].x],pos[line[i].x+w]-1,line[i].rank);           //算左不算右，所以右极限要减1；
										while(j<=i&&line[i].y-line[j].y>=h){                                //算上不算下，所以当最下方的星星和刚插入的星星高度值大于等于h时，把最下方的星星移除；
													 update(1,pos[line[j].x],pos[line[j].x+w]-1,-line[j].rank);
													 j++;
										}
										ans=max(ans,tree[1].maxx);                  //这时的tree[1].maxx储存的是最上方星星和最下方星星的高度差在合法范围内的整个x轴的最大亮度值，和ans比较，若大于则并更新；
					 }
					 printf("%lld\n",ans);
		}
					 return 0;
}

		 实际就是求矩形并的最大rank值，只不过“Note, the stars which are right on the edge of the window does not count.”这句话要注意一下，就是说若星星在矩形边框上的话，只能算矩形的左右其中一边，上下其中一边，这里特殊处理一下。