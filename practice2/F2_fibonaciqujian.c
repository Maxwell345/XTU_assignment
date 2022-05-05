#include <stdio.h>
int qread()
{  
    register int x,flag;
    x=0;flag=1;
    register char c=getchar();
    
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*flag;
}
int maxWithRange(int *arr,int from,int to)
{
	int ans,j;
	ans=0;
	for(j=from;j<=to;++j){
		if(ans<arr[j]) ans=arr[j];
	}
	return ans;
}
int main() {
	int T,n,i,res;
	int a[10008];
	int dp[10008]; 
	T=qread();
	while(T>0){
		T--;
		n=qread();
		for(i=1;i<=n;++i){
			a[i]=qread();
			dp[i]=2;
		}
		for(i=3;i<=n;++i){
			if(a[i]==a[i-1]+a[i-2]) dp[i]=dp[i-1]+1;
		}
		res=maxWithRange(dp,1,n);
		printf("%d\n",res);
	}
}



