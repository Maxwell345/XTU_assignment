#include <stdio.h>
int check[108];
int main()
{
	int T,i,j,left,right;
	int n,k,s,res;
	int a[10007];
	int f[10007];
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;++i) scanf("%d",&a[i]);
		for(j=1;j<=k;++j) scanf("%d",&check[j]);
		f[0]=0;
		for(i=1;i<=n;++i) f[i]=f[i-1]+a[i];
		for(j=1;j<=k;++j){
			s=check[j];
			res=0;
			left=right=1;
			while(left<=n){
				while(f[right]-f[left-1]<s&&right<n) ++right;
				if(f[right]-f[left-1]==s) res++;
				++left;
			}
			printf("%d\n",res);
		}
	}
	return 0;
}
