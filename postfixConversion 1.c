#include<stdio.h>
#define MAX_SIZE 20
typedef enum{FALSE,TRUE}Bool;
typedef struct{char val[MAX_SIZE];int top}Stack;
int contains(char ch)
{
    int i=0;char arr[]={'+','-','*','/','%','^'};
    while(arr[i])
    {
        if(arr[i]==ch) return 1;
        i++;
    }
    return 0;
}
Stack createStack()
{
    Stack s;s.top=0;
    return s;
}
Bool isEmpty(Stack s)
{
    return(s.top==0);
}
Bool isFull(Stack s)
{
    return s.top==MAX_SIZE -1;
}
Bool push(Stack *s,char val)
{
    if(isFull(*s))  return FALSE;
    s->top=s->top+1;
    s->val[s->top]=val;
    return TRUE;
}
Bool pop(Stack *s,char *va)
{
    if(isEmpty(*s)) return FALSE;
    *va=(*s).val[(s->top)];
    s->top=s->top-1;
    return TRUE;
}
int peek(Stack s)
{
    if(isEmpty(s)) return -9999;return s.val[s.top];
}
int main()
{
    char arr[100];int i=0;Stack s;s=createStack();char val;
    printf("Enter the string:");
    scanf("%s",arr);
    while(arr[i])
    {
        if((arr[i]>='a' && arr[i]<='z') || (arr[i]>='A'&& arr[i]<='Z')|| (arr[i]>='0'&&arr[i]<='9'))
        {
            printf("%c",arr[i]);
        }
        else if(arr[i]=='(')
        {
            i++;
            continue;
        }
        else if(arr[i]==')')
        {
            pop(&s,&val);
            printf("%c",val);
        }
        else if(contains(arr[i])&&!contains(arr[i+1]))
                {
                    push(&s,arr[i]);
                }
                else{printf("%c%c",arr[i],arr[++i]);}
        i++;
    }
    while(pop(&s,&val))
        printf("%c",val);
    return 0;
}
