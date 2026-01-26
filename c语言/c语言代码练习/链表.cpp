#include<stdio.h>
#include<stdlib.h>
struct lian
{
	int a;
	struct lian *next;
};
struct lian *add(struct lian *head)
{
	struct lian *p1=NULL,*p2=NULL;
	p1 = (struct lian *)malloc(sizeof(struct lian));
	int n;
	while(~scanf("%d",&n))
	{
		if(n==-1) break;
		if(head==NULL) 
		{
			head = p1;
			head->a = n;
			p1->next=NULL;
		}
		else 
		{
			p1 = (struct lian *)malloc(sizeof(struct lian));
			p1->a = n;
			p2 = head;
			head = p1;
			head->next=p2;
		}
	}
	return head;
}
struct lian *del(struct lian *head)
{
	int n;scanf("%d",&n);
	struct lian *p1 = head,*p2=head;
	while(p1->a!=n&&p1->next!=NULL)	
	{
		p2 = p1;
		p1=p1->next;
	}
	if(p1->a==n)
	{
		p2->next=p1->next;
		free(p1);
	}
	return head;
}
void list(struct lian *head)
{
	struct lian *p1 = head,*p2= head;
	while(p1!=NULL)
	{
		printf("%d ",p1->a);
		p1=p1->next;
	}	
}
int main()
{
	struct lian *head = NULL;
	head=add(head);
	head = del(head);
	list(head);
 } 
