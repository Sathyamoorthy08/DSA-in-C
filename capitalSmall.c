#include<stdio.h>
#define MAX 30
typedef enum{FALSE,TRUE}Bool;
typedef struct{
    char val[MAX];
    int rear,front;
}Q;
int contains(char *arr,char ch)
{
    int i=0;
    while(arr[i])
    {
        if(arr[i]==ch) return 1;
        i++;
    }
    return 0;
}
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
    if(isFull(*q))  return 0;
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
void print(Q q)
{
     printf("%c\n",q.val[q.front+1]);
}
int main()
{
    char arr[100];Q q1,q2;int i=0;char ch1,ch2;
    init(&q1);init(&q2);
    printf("Enter the string:");
    scanf("%s",arr);
    while(arr[i])
    {
        if((arr[i]>='a' && arr[i]<='z' )&& (contains(q2.val,(arr[i]-32))))
           insert(&q1,arr[i]);
        else if((arr[i]>='A'&& arr[i]<='Z'))
            insert(&q2,arr[i]);
        i++;
    }
    while(delete(&q1,&ch1))
    {
        delete(&q2,&ch2);
        if((ch1-32)!=ch2)
        {
            printf("The function call and return sequence is NOT followed!\n");
            return 0;
        }
    }
    if(!delete(&q2,&ch2))
        printf("The function call and return sequence is followed!!\n");
    else
        printf("The function call and return sequence is not followed!\n");
    return 0;
}
