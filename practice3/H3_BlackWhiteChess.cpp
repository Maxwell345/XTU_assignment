#include <iostream>
using namespace std;
#define lim 65540
#define Rf 65535
const int Rp[17] = {15,15<<4,15<<8,15<<12,4369,4369<<1,4369<<2,4369<<3,
				  51,51<<1,51<<2,51<<4,51<<5,51<<6,51<<8,51<<9,51<<10};
int ans[lim];
int q[lim];
int my_Min(int x,int y)
{
	return x<y?x:y;
}
int My_Add(int x,int y)
{
    if (y == 0)
        return x;
    else
        return My_Add( x ^ y, (x & y) << 1);
}
void prime()
{
	int l = 1, r = 1,t,i;
	for (i = 0; i < lim; ++i) ans[i] = 1e9;
	q[1] = 0;
	ans[0] = 0;
	while(l <= r)
	{
		for (i = 0; i < (1<<4)+1; ++i)
		{
			t = q[l] ^ Rp[i];
			if (ans[t] == 1e9)
			{
				ans[t] = ans[q[l]] + 1;
				q[++r] = t;
			}
		}
		l=My_Add(l,1);
	}
}

int read()
{
	int res = 0,i;
	char s[18];
	scanf("%s", s);
	for (i = 0; i < 16; ++i)
		if(s[i] == '1') res = My_Add(res*2,1);
		else            res = res*2;
	return res;
}

int main()
{
	prime();
	int T,a,p;
	scanf("%d", &T);
	while(T--)
	{
		a = read();
		p = my_Min(ans[a],ans[a^Rf]);
		if(p < 1e9) printf("%d",p);
		else{
			putchar('-');
			putchar('1');
		}
		cout<<endl;
	}
	return 0;
}

