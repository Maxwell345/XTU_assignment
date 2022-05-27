#include<iostream>
#include<stdlib.h>
using namespace std;
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
int my_abs(int x)
{
    return x>=0?x:-x;
}
int GetHeight(BST a){
    if(!a)  return 0;
    return (my_maxd(GetHeight(a->left),GetHeight(a->right))+1);
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
bool balance(BST p)
{
	if(!p) return true;
	if(my_abs(GetHeight(p->left)-GetHeight(p->right)) > 1) return false;
	return balance(p->left)&&balance(p->right);
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
        n=qread();
        BST root;
        root=NULL;
        for(i=0;i<n;i++){
            b=qread();
            root=InsertBST(root,b);
        }  
        if(balance(root)) printf("Yes\n");
        else              printf("No\n");
        FreeTree(root);
    }
    return 0;
}
