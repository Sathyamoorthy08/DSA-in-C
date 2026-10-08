#include<stdio.h>

typedef struct node{
 int val,count;
 struct node *next;
 }Node;

Node* createNode(int val)
 {
 Node* tem = (Node*)malloc(sizeof(Node));
 tem->val = val;
 tem->count = 1;
 tem->next = NULL;
 return tem;
 }

Node* insert(Node* list,int val)
 {
 if(!list)
 return createNode(val);
 if(val<list->val)
 {
 Node* tem = createNode(val);
 tem->next = list;
 return tem;
 }
 if(list->val == val)
 {
 list->count++;
 return list;
 }
 Node* head = list;

 while(list->next && list->next->val<val)
 {
 list = list->next;
 }
 if(list->next && list->next->val == val)
 list->next->count++;
 else
 {
 Node* tem = createNode(val);
 tem->next = list->next;
 list->next = tem;
 }
 return head;
 }

Node* delete(Node* list,int val)
 {
 if(!list)return list;
 if(list->val == val)
 {
 if(list->count >1)
 {
 list->count--;
 return list;
 }
 else return list->next;
 }
 Node* head = list;
 while(list->next && list->next->val<val)
 {
 list = list->next;
 }
 if(list->next->val == val)
 {
 if(list->next->count >1)
 {
 list->next->count--;
 }
 else{
 list->next = list->next->next;
 }
 }
 return head;
 }

Node* reset(Node* list)
 {
 return NULL;
 }

Node* clear(Node* list,int val)
 {
 if(!list)return list;
 if(list->val == val)
 {
 return list->next;
 }
 Node* head = list;
 while(list->next && list->next->val<val)
 {
 list = list->next;
 }
 if(list->next->val == val)
 {
 list->next = list->next->next;
 }
 return head;
 }

void dispFrequency(Node* list,int val)
 {

 while(list)
 {
 if(list->val == val)
 {
 printf("%d frequency = %d",val,list->count);
 return;
 }
 list = list->next;
 }
 printf("%d frequency = 0",val);printf("\n");
 }

int totalNodes(Node* list)
 {
 int count=0;
 while(list)
 {
 count++;
 list = list->next;
 }
 return count;
 }

int totalValues(Node* list)
 {
 int count=0;
 while(list)
 {
 count+=list->count;
 list = list->next;
 }
 return count;
 }

void display(Node* list)
 {
 while(list)
 {
 printf("(%d,%d) ",list->val,list->count);
 list = list->next;
 }
 printf("\n");
 }
 void dispChoice()
 {

 printf("\n");
 printf("1.Create List && insert 10 values\n2.Insert One value\n");
 printf("3.Delete One value\n4.Reset\n");
 printf("5.Clear\n6.Display Frequency\n");
 printf("7.Total Nodes Available\n8.Total Values Available\n");
 printf("9.Display List\n10.Quit\n");
 }
 int main()
 {
 Node* list = NULL;
 int choice=10;
 dispChoice();
 printf("Enter your choice:");
 scanf("%d",&choice);
 while(1)
 {
 if(choice == 1)
 {
 list = NULL;
 for(int i=0;i<10;i++)
 {
 list = insert(list,rand()%100);
 }
 printf("\nList Created!!\n");
 }
 else if(choice == 2)
 {
 int val;
 printf("Enter the value to be inserted:");
 scanf("%d",&val);
 list = insert(list,val);
 printf("\nValue Inserted!!\n");
 }
 else if(choice == 3)
 {
 int val;
 printf("Enter the value to be deleted:");
 scanf("%d",&val);
 list = delete(list,val);
 printf("\nValue Deleted!!\n");
 }
 else if(choice == 4)
 {
 list = reset(list);
 printf("\nList cleared!!\n");
 }
 else if(choice == 5)
 {
 int val;
 printf("Enter the value to be cleared:");
 scanf("%d",&val);
 list = clear(list,val);
 printf("\nValue cleared!!\n");
 }
 else if(choice == 6){
 int val;
 printf("Enter the value whose Frequency is needed:");
 scanf("%d",&val);
 dispFrequency(list,val);
 }
 else if(choice == 7){printf("\nTotal Nodes = %d\n",totalNodes(list));}
 else if(choice == 8){printf("\nTotal Values = %d\n",totalValues(list));}
 else if(choice == 9){printf("\nList:\n");display(list);}
 else if(choice == 10){printf("Bye!!Bye!!");return 0;}
 dispChoice();
 printf("Enter your choice:");
 scanf("%d",&choice);
 }
 return 0;
 }
 /*printf("Total Nodes = %d\nTotal Values = %d",totalNodes(list),totalValues(list));

if(!list->next)
 {
 if(list->val > val){
 Node* tem = createNode(val);
 tem->next = list;
 return tem;
 }
 else if(list->val == val){
 list->count++;return list;
 }
 else{
 list->next = createNode(val);
 return list;
 }
 }*/