#include <stdio.h>
#include <string.h>
int main()
{
	char s[105],order[10];
	char c,d;
	int i,start,end,cnt;
	while(scanf("%s",s)!=EOF){
		cnt=1;
		while(scanf("%s",order)!=EOF){
			if(strcmp(order,"END")==0){
				printf("\n");
				break;
			}
			if(strcmp(order,"S")==0){
				scanf("%d%d",&start,&end);
				scanf(" %c",&c);
				if(start<1) start=1;
				if(end>strlen(s)) end=strlen(s);
				for(i=start-1;i<end&&s[i]!='\0';i++){
					s[i]=c;
				}
				printf("%d:%s\n",cnt++,s);
			}
			if(strcmp(order,"T")==0){
				scanf(" %c %c",&c,&d);
				for(i=0;s[i];i++){
					if(s[i]==c) s[i]=d;
				}
				printf("%d:%s\n",cnt++,s);
			}
		}
	}
	return 0;
}
