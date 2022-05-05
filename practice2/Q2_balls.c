#include <stdio.h>
#include <string.h>
void specialswap(char *array,int q)
{
	char temp;
	temp=array[q];
	array[q]=array[q+1];
	array[q+1]=temp;
}
void my_fill(int *s,int value,int begin,int end)
{
	int idx;
	for(idx=begin;idx<end;++idx) s[idx]=value;
}
int all_zeroes(int *arr,int size)
{
	int i;
	for(i=0;i<size;++i){
		if(arr[i]!=0) return 0;
	}
	return 1;
}
void choosecopy(char *dest,char *source,int *condition)
{
	int i=0,j=0;
	while(source[i]!='\0'){
		if(condition[i]) dest[j++]=source[i];
		++i;
	}
}
int main()
{
	int T,n,pos;
	int i,j,x;
	char balls[35];
	char tmp_str[35];
	int survived[35];
	scanf("%d",&T);
	while(T--){
		scanf("%s",balls);
		scanf("%d",&n);
		while(n--){
			scanf("%d",&pos);pos--;
			specialswap(balls,pos);
			strcpy(tmp_str,balls);
			for(i=0;i<35;++i) survived[i]=1;
			i=0;
			while(tmp_str[i]!='\0'){
                j=i;
                do{
                    ++j;
                }while(tmp_str[i]==tmp_str[j]);
                if(j-i>=3){
                	if((i<=pos&&pos<j)||(i<=pos+1&&pos+1<j))
					{
						my_fill(survived,0,i,j);
					}
				}
				i=j;
            }
			
			if(all_zeroes(survived,strlen(tmp_str))){
				printf("Over\n");
				break;
			}
			memset(balls,'\0',sizeof(balls));
			choosecopy(balls,tmp_str,survived);
			puts(balls);
		}
		putchar('\n');
	}
	return 0;
}
