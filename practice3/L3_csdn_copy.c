#include<stdio.h>
#include<stdlib.h>
int max_num;
typedef struct Node * BST;
struct Node{
    int num;
    BST left;
    BST right;
};
int my_maxd(int x,int y)
{
	return x>y?x:y;
}
int my_abs(x)
{
	return x>=0?x:-x;
}
int GetHeight(BST a){
    if(!a)  return 0;
    int d,max_2,hl,hr;
    hl=GetHeight(a->left);
    hr=GetHeight(a->right);
    max_2=hl>hr?hl:hr;
    d=my_abs(hr-hl);
    max_num=my_maxd(max_num,d);
    return (my_maxd(hl,hr)+1);
}
BST InsertBST(BST a,int value){
    if(!a){
        a=(BST)malloc(sizeof(struct Node));
        a->num=value;
        a->left=a->right=NULL;
    }
    else{
        if(value>a->num)  a->right=InsertBST(a->right,value);
        else if(value<a->num)  a->left=InsertBST(a->left,value);
    }
    return a;
}
BST FreeTree(BST a){
    if(a){
        if(a->left==NULL && a->right==NULL){
            free(a);
            a=NULL;
            return NULL;
        }  
        a->left=FreeTree(a->left);
        a->right=FreeTree(a->right);
        free(a);
        a=NULL;
        return NULL;
    }
    else  return NULL;
}
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
int main(){
    int K,n,i,b;
    K=qread();
    while(K--){
        max_num=0;
        n=qread();
        BST root;
        root=NULL;
        for(i=0;i<n;i++){
            b=qread();
            root=InsertBST(root,b);
        }  
        GetHeight(root);
        printf("%d\n",max_num);
        FreeTree(root);
    }
    return 0;
}
