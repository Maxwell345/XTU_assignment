#include <stdio.h>
int lengthOfLastWord(char * s){
    int i,length,tail,flag=0;
    length=0;
    for(i=0;s[i];++i) ++length;
    for(i=length-1;i>=0;i--){
        if(s[i]!=' ')
        {
        	tail=i;
        	break;
		}
    }
    for(i=tail;i>=0;i--){
        if(s[i]==' ') return tail-i;
    }
    return tail-i;
}
int main()
{
	char text[30];
	int T,ans;
	scanf("%d",&T);
	while(T--){
		gets(text);
		ans=lengthOfLastWord(text);
		printf("%d\n",ans);
	}
}
