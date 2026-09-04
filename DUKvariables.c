#include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 typedef struct node {char data; struct node *left, *right;} BT;
 BT* makeNode(char data) { BT *t = (BT *) malloc(sizeof(BT));
 t->data = data; t->left=t->right=NULL;
 return t;}
 void inOrder(BT *t)
 { if (t) { inOrder(t->left);
 printf("%5d", t->data);
 inOrder(t->right);} };

BT * insert(BT *t, char data)
 {
 if(!t) return makeNode(data);
 if (t->data>data) t->left = insert(t->left, data);
 if (t->data<data) t->right = insert(t->right, data);
 return t;
 }

int search(BT *t, char data)
 { if(!t) return 0;
 if (t->data == data) return 1;
 if (t->data>data) return search(t->left, data);
 return search(t->right, data);
 }

int findmin(BT* t)
 {
 if(!t)return NULL;
 if(t->left == NULL) return t->data;
 return findmin(t->left);
 }

BT* Delete(BT* t,char data)
 {
 if(!t)
 {
 return NULL;
 }
 if(t->data == data)
 {
 if(!t->right && !t->left){
 return NULL;}
 if(!t->right)
 {return t->left;}
 if(!t->left)
 {return t->right;}
 t->data=findmin(t->right);
 t->right=Delete(t->right,t->data);
 return t;
 }
 if(t->data > data)
 {t->left=Delete(t->left,data);}
 if(t->data < data)
 {
 t->right=Delete(t->right,data);}
 return t;
 }

int main()
 {
 BT *t=NULL;char str[50];int i=0;
 printf("Enter the string sequence:");
 scanf("%s",str);
 if(str[i]!='D' ){printf("Not in the sequence!!");return 0; }
 while(str[i])
 {
 if(str[i]=='D')
 {
 t=insert(t,str[++i]);i++;
 }
 else if(str[i]=='U')
 {
 i++;
 if(str[i]!='D' && str[i]!='U' && str[i]!='K')
 {
 if(search(t,str[i])) i++;
 else {printf("Not in the sequence!!");return 0;}
 }
 else {printf("Not in the sequence!!");return 0;}
 }
 else if(str[i]=='K')
 {
 i=i+1;
 if(str[i]!='D' && str[i]!='U' && str[i]!='K')
 {t=Delete(t,str[i]);i++;}
 }
 }
 printf("In the sequence");
 return 0;
 }