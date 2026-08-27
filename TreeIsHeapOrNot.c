#include<stdio.h>
 #include<stdlib.h>
 #include<stdbool.h>

typedef struct bt{ int data; struct bt* right, *left; }BT;

/*BT* MakeNode(int val)
 {
 BT* t = (BT*)malloc(sizeof(BT));
 t->data=val;
 t->right=NULL;t->left=NULL;
 return t;
 }

BT* insert(BT* t,int val)
 {
 BT* node= MakeNode(val);
 while()
 }
 */

int isHeap(int* arr, int size)
 {
 for(int i=1;i<=size/2;i++)
 {
 if((arr[i] > arr[2*i] && arr[2*i]!=0) || (arr[i]>arr[2*i +1] && arr[2*i +1] !=0) ) return 0;
 }
 return 1;
 }

int main()
 {
 int heap[100],size=1,val;
 for(int i=0;i<100;i++)
 {
 heap[i]=0;
 }
 printf("Enter all the elements of the tree (-1 to end):\n");
 while(true)
 {
 scanf("%d",&val);
 if(val == -1) break;
 heap[size]=val;
 size++;
 }
 if(isHeap(heap,size))printf("It is a minHeap");
 else printf("Not a min heap");
 return 0;
 }