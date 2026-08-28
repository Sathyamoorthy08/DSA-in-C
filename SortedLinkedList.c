#include <stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
} NODE;
NODE* MakeNode(int data){
    NODE* l = (NODE*)malloc(sizeof(NODE));
    l->data=data;
    l->next=NULL;
    return l;
}
void dispAscend(NODE* l){
    if(!l) return;
    while(l){
        printf("%5d",l->data);
        l = l->next;
    }
    printf("\n");
}
void dispDescend(NODE* l){
    if(l)
    {
        dispDescend(l->next);printf("%5d",l->data);
    }
}
NODE* insort(NODE* l,int val){
    if(!l)return MakeNode(val);
    if(val<l->data){
        NODE* t = l;
        t = MakeNode(val);
        t->next = l;
        return t;}
    NODE* t = l;
    while(t->next && (t->next)->data<val){
         t = t->next;
    }
    NODE* tm = MakeNode(val);
    tm->next=t->next;
    t->next=tm;
    return l;
}
NODE* insertTail(NODE* l,int data){
    if(!l){return MakeNode(data);}
    NODE* t = l;
    while(t->next){
     t = t->next;
    }
    t->next = MakeNode(data);
    return l;
}
NODE* deleteVal(NODE* l,int val) {
    if(!l)return l;
    if((l->data)==val)return l->next;
    NODE* t = l;
    while(t->next) {
        if((t->next)->data==val){
            NODE* tm = t->next;
            t->next = (t->next)->next;
            free(tm);
            return l;
        }
        t=t->next;
    }
    return l;
}
int main()
{
    NODE* l = NULL;int n,val;
    printf("Enter the number of values:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the value:");
        scanf("%d",&val);
        l = insort(l,val);
    }
    printf("\nAscending order:");
    dispAscend(l);
    printf("\nDescending order:");
    dispDescend(l);
    printf("\nEnter the value to be deleted:");
    scanf("%d",&val);
    l=deleteVal(l,val);
    dispAscend(l);
    return 0;
}
