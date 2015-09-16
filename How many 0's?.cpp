
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
#define N ***
using namespace std;
long long getcnt(long long num)
{
					if(num == -1)
							return 0;
					long long tot, base;
					tot = 1;
					tot += num / 10;
					base = 100;
					while(num / base)
					{
									if(num % base / (base / 10) >= 1)
											tot +=(num / base) * (base / 10);
									else                 
											tot +=(num / base - 1) * (base / 10) + (num % (base / 10) + 1);
									base *= 10;
					}
					return tot;
}

int main()
{
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		#endif
		long long n, m;
		while(~scanf("%lld%lld", &n, &m))
		{
							if(n == -1 && m == -1)
										break;
							printf("%lld\n", getcnt(m) - getcnt(n - 1));
		}
		return 0;
}




