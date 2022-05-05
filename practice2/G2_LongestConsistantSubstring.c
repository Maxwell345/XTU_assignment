#include <stdio.h>
int dp[1006];
void my_fillarr(int *array,int value,int head,char *str)
{
	int pos;
	for(pos=head;str[pos];++pos) array[pos]=value;
}
int my_getmax(int *arr,char *size)
{
	int j,res;
	res=0;
	for(j=0;size[j]!='\0';++j){
		if(arr[j]>res) res=dp[j];
	}
	return res;
}
int main()
{
	char s[1005];
	int i,ans;
	while(scanf("%s",s)!=EOF){
		my_fillarr(dp,1,0,s);
		for(i=1;s[i]!='\0';++i)
		{
			if(s[i]==s[i-1]+1) dp[i]=dp[i-1]+1;
		}
		ans=my_getmax(dp,s);
		printf("%d\n",ans);
	}
	return 0;
}
