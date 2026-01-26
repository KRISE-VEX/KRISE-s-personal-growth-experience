#include<stdio.h>
#include <stdlib.h>
struct lian 
{
    int a;
    struct lian *next;
};
#define len sizeof(struct lian)
struct lian *insert(struct lian *head)
{
    struct lian *p0,*p1;
    int n;
    p0 = (struct lian *)malloc(len);
    while(~scanf("%d",&n))
    {
        if(n==-1) break;
        if(head==NULL)
        {
            head = p0;
            head->a = n;
        }
        else 
        {
           p0 = (struct lian *)malloc(len);
           p0->a = n;
           p1 = head;
           head = p0;
           p0->next = p1;
        }
    }
    return head;
}
struct lian *del(struct lian *head)
{
    int n;scanf("%d",&n);
    struct lian *p1,*p2;
    p1 = head,p2 = head;
    while(p1->a!=n&&p1->next!=NULL)
    {
        p2 = p1;
        p1=p1->next;
    }
    if(p1->a==n)
    {
    p2->next = p1->next;
    free(p1);
    }
    return head;
}
void list(struct lian *head)
{
    struct lian *p2;
    p2 = head;
    while(p2->next!=NULL)
    {
        printf("%d ",p2->a);
        p2 = p2->next;
    }
    printf("%d",p2->a);
}
int main()
{
    struct lian *head = NULL;
    head = insert(head);
    head = del(head);
    list(head);
    
}
