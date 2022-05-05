#include <stdio.h>
#include <string.h>
int width[12];
void polydraw(char ch,int repeat)
{
	int q=repeat;
	while(q--){
		putchar(ch);
	}
}
int main()
{
	int T,row,col;
	int i,j,length;
	int repeat,leftspace,rightspace;
	char align[12];
	char text[12][12][25];
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&row,&col);getchar();
		for(j=0;j<col;++j) scanf("%c",&align[j]);
		for(i=0;i<row;++i){
			for(j=0;j<col;++j){
				scanf("%s",text[i][j]);
			}
		}
		for(j=0;j<col;++j){
			width[j]=0;
			for(i=0;i<row;++i){
				length=strlen(text[i][j]);
				if(length>width[j]) width[j]=length;
			}
			width[j]+=2;
		}
		for(i=0;i<row;++i){
			//draw a cutline
			for(j=0;j<col;++j){
				putchar('+');
				polydraw('-',width[j]);
			}
			printf("+\n");
			//write a row
			for(j=0;j<col;++j){
				putchar('|');
				length=strlen(text[i][j]);
				if(align[j]=='l')      leftspace=1;
				else if(align[j]=='r') leftspace=width[j]-length-1;
				else                   leftspace=(width[j]-length)/2;
				rightspace=width[j]-length-leftspace;
				polydraw(' ',leftspace);printf("%s",text[i][j]);polydraw(' ',rightspace);
			}
			printf("|\n");
		}
		for(j=0;j<col;++j){
			putchar('+');
			polydraw('-',width[j]);
		}
		printf("+\n");
	}
	return 0;
}
