
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
#define N 505
using namespace std;
int Hash[N];

void Init()
{
					Hash['-'] = '0'; Hash['='] = '-';
					Hash['['] = 'P'; Hash[']'] = '['; Hash['\\'] = ']'; Hash[' '] = ' ';
					Hash[';'] = 'L'; Hash['\''] = ';'; Hash[','] = 'M'; Hash['.'] = ','; Hash['/'] = '.';
			 
					Hash['W'] = 'Q'; Hash['E'] = 'W'; Hash['R'] = 'E'; Hash['T'] = 'R'; Hash['Y'] = 'T';
					Hash['U'] = 'Y'; Hash['I'] = 'U'; Hash['O'] = 'I'; Hash['P'] = 'O'; Hash['S'] = 'A';
					Hash['D'] = 'S'; Hash['F'] = 'D'; Hash['G'] = 'F'; Hash['H'] = 'G'; Hash['J'] = 'H';
					Hash['K'] = 'J'; Hash['L'] = 'K'; Hash['X'] = 'Z'; Hash['C'] = 'X'; Hash['V'] = 'C';
					Hash['B'] = 'V'; Hash['N'] = 'B'; Hash['M'] = 'N';
			 
					Hash['0'] = '9'; Hash['1'] = '`'; Hash['2'] = '1'; Hash['3'] = '2'; Hash['4'] = '3';
					Hash['5'] = '4'; Hash['6'] = '5'; Hash['7'] = '6'; Hash['8'] = '7'; Hash['9'] = '8';
}
int main()
{
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		#endif
		Init();
		char arr[N];
		while(gets(arr))
		{
							for(int i = 0; arr[i] != 0; i++)
											printf("%c", Hash[arr[i]]);
							printf("\n");
		}
		return 0;
}




