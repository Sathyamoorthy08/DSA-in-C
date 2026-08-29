#include <stdio.h>
 #include <stdlib.h>
 #include<stdbool.h>

typedef struct Node {
 int data;int col;
 struct Node *next;
 }Node;

typedef struct Head {
 int data;
 struct Head *nH;
 struct Node *val;
 }Head;

Node* makeNode(int val,int col)
 {
 Node* t=(Node*)malloc(sizeof(Node));
 t->data=val;t->col=col;
 t->next=NULL;
 return t;
 }
 Head* makeHead(int val)
 {
 Head* h = (Head*)malloc(sizeof(Head));
 h->data = val;
 h->nH=NULL;
 h->val=NULL;
 return h;
 }
 Head* insertHead(Head* h)
 {
 if(!h) return makeHead(0);
 Head* temp=h;int index=1;
 while(temp->nH)
 {
 index++;
 temp=temp->nH;
 }
 temp->nH=makeHead(index);
 return h;
 }

void printH(Head* h)
 {
 if(!h)return;
 Head* temH=h;Node* n=temH->val;
 while(n->next){
 printf("%5d",n->data);n=n->next;}
 printf("%5d",n->data);printf("\n");
 while(temH->nH)
 {
 printf("\n");
 temH=temH->nH;
 n=temH->val;
 if(!n) break;

 while(n->next)
 {
 printf("%5d",n->data);n=n->next;
 }
 printf("%5d",n->data);
 printf("\n");

 }
 }

Head* insertNode(Head* h,int row,int val,int col)
 {
 if(!h){ Node* n=makeNode(val,0);
 h=insertHead(h);h=insertNode(h,0,val,0);
 }
 else{
 int cur=0;Head* tem=h;
 while(cur<row && tem->nH )
 {
 tem=tem->nH;
 cur++;
 }
 if(cur == row)
 {
 if(!(tem->val)) tem->val=makeNode(val,col);
 else {
 Node* temp=tem->val;
 while(temp->next)
 {
 temp=temp->next;
 }
 temp->next=makeNode(val,col);
 }
 }
 }
 return h;
 }

void printSparse(Head* h,int row,int col)
 {
 Head* tem=h;
 for(int i=0;i<row;i++)
 {
 Node* n=tem->val;
 for(int j=0;j<col;j++)
 {
 if(n->col != j)
 printf("%5d",0);
 else {
 printf("%5d",n->data);
 if(n->next)n=n->next;
 }
 }
 printf("\n\n");
 tem=tem->nH;
 }
 }

int main()
 {
 Head* h1=NULL;
 int row=rand()%10+1;
 int col=rand()%10+1;
 int mat[10][10];
 for(int i=0;i<row;i++)
 {
 for(int j=0;j<col;j++)
 {
 mat[i][j]=(rand()%100) * (rand()%2) ;
 }
 }
 for(int i=0;i<row;i++)
 {
 h1=insertHead(h1);
 for(int j=0;j<col;j++)
 {
 if(mat[i][j]!=0)
 h1=insertNode(h1,i,mat[i][j],j);
 }
 }
 printf("\nRow:%d\nCol:%d\n\n",row,col);
 printf("\n\nJagged Array:\n");
 printH(h1);
 printf("\n\nSparsed Array:\n");
 printSparse(h1,row,col);
 return 0;
 }