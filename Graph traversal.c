#include<stdio.h>
 #include<stdlib.h>
 #define MAX 25
 typedef enum{FALSE,TRUE}Bool;
 typedef struct{char val[MAX];int top}Stack;
 typedef struct{
 char val[MAX];
 int rear,front;
 }Q;
 Bool init(Q *q)
 {
 q->rear=q->front=0;
 return 1;
 }
 Bool isEmpty(Q q)
 {
 return q.rear==q.front;
 }
 Bool isFull(Q q)
 {
 return ((q.rear + 1)%MAX ==q.front);
 }
 Bool insert(Q *q,char v)
 {
 if(isFull(*q)) return 0;
 q->rear=(q->rear+1)%MAX;
 q->val[q->rear]=v;
 return 1;
 }
 Bool delete(Q *q,char *v)
 {
 if(isEmpty(*q)) return 0;
 q->front=(q->front+1)%MAX;
 *v=q->val[q->front];
 return 1;
 }
 typedef struct node
 {
 int vertex; struct node* next;
 }Node;

Node* createVertex(int val)
 {
 Node* tem = (Node*)malloc(sizeof(Node));
 tem->vertex = val;
 tem->next = NULL;
 return tem;
 }

void printLL(Node* ll)
 {
 while(ll)
 {
 printf("%5d",ll->vertex);
 ll = ll->next;
 }
 }

void dispMatrix(int size,int graph[size][size])
 {
 for(int i=0;i<size;i++)
 {
 for(int j=0;j<size;j++)
 {
 printf("%5d",graph[i][j]);
 }
 printf("\n");
 }
 }

Node* Listinsert(Node* list,int val)
 {
 if(!list) return createVertex(val);
 Node* head = list;
 while(list->next)
 list = list->next;
 list->next = createVertex(val);
 return head;
 }

void AdjList(int size,int graph[size][size],Node* list[size])
 {
 for(int i=0; i<size; i++)
 {
 for(int j=0;j<size;j++){
 if(graph[i][j] == 1){
 list[i] = Listinsert(list[i],j);
 }
 }
 }
 }

void printAdjacent(int size,int graph[size][size],int vertex)
 {
 for(int i=0; i<size; i++)
 {
 if(graph[vertex][i] == 1)
 {
 printf(" V%d",i);
 }
 }
 printf("\n");
 }

void dispList(int size,Node* list[size])
 {
 for(int i=0;i<size;i++)
 {
 printf("Vertex %d->",i);
 printLL(list[i]);
 printf("\n");
 }
 }

void dfs(int size,int graph[size][size],int src,int mark[size])
 {
 mark[src] = 1;
 printf("%5d",src);
 for(int i=0;i<size;i++)
 {
 if(mark[i] == 0 && graph[src][i] == 1)
 {
 dfs(size,graph,i,mark);
 }
 }
 }

void Ldfs1(int size,Node* list[size],int src,int mark[size])
 {
 printf("%5d",src);
 mark[src] = 1;
 if(list[src])
 {
 Node* tem = list[src];
 while(tem){
 if(mark[tem->vertex] == 0){
 Ldfs1(size,list,tem->vertex,mark);break;}
 else tem = tem->next;
 }
 }
 else{
 for(int i=0;i<size;i++)
 if(mark[i] == 0)
 Ldfs1(size,list,i,mark);
 }
 }
 void LDFS(int size,Node* list[size],int src,int mark[size])
 {
 Ldfs1(size,list,src,mark);
 for(int i=0;i<size;i++)
 if(mark[i] == 0)
 Ldfs1(size,list,i,mark);
 }

void bfs(int size,int graph[size][size],int src,int mark[size])
 {
 Q q ;
 init(&q);insert(&q,src);
 while(!isEmpty(q))
 {
 int val;
 delete(&q,&val);
 printf("%5d",val);mark[val] = 1;
 for(int i=0;i<size;i++)
 {
 if(mark[i] == 0 && graph[val][i]==1){
 insert(&q,i);mark[i]=1;}
 }
 }
 }

void Lbfs(int size,Node* list[size],int src,int mark[size])
 {
 for(int i=0;i<size;i++)
 {
 Node* tem = list[i];
 while(tem)
 {
 if(mark[tem->vertex]==0)
 {
 printf("%5d",tem->vertex);
 mark[tem->vertex] = 1;
 tem = tem->next;
 }
 }
 }
 }

void resetMark(int size,int mark[size])
 {
 for(int i=0;i<size;i++){
 mark[i]=0;}
 }

void ReachK(int size,int graph[size][size],int src,int mark[size],int k)
 {
 Q q ;
 init(&q);insert(&q,src);
 while(!isEmpty(q) && k > 0)
 {
 int val;
 delete(&q,&val);
 printf("%5d",val);
 mark[val] = 1;
 for(int i=0;i<size;i++)
 {
 if(mark[i] == 0 && graph[val][i]==1){
 insert(&q,i);mark[i]=1;}
 }
 k--;
 }
 while(!isEmpty(q))
 {
 int val=0;
 delete(&q,&val);
 printf("%5d",val);
 }
 }

int main()
 {
 int size1 = 6;
 int g1[6][6]={{0,1,0,0,1,1},{1,0,1,1,0,0},{0,1,0,1,0,0},{0,1,1,0,1,0},{1,0,0,1,0,0},{1,0,0,0,0,0}};
 int mark[6] = {0};
 Node* lg1[6] = {NULL};

 //printAdjacent(s1,g1,2);
 //dispMatrix(s1,g1);
 AdjList(size1,g1,lg1);
 dispList(size1,lg1);
 /*LDFS(size1,lg1,2,mark);
 printf("\nBFS:");
 resetMark(size1,mark);
 bfs(size1,g1,2,mark);resetMark(size1,mark);
 printf("\nLBFS");
 Lbfs(size1,lg1,2,mark);*/
 resetMark(size1,mark);
 ReachK(size1,g1,4,mark,1);
 return 0;
 }