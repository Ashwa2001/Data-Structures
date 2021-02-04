#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next,*prev;
}NODE;

typedef struct dlist
{
    NODE *head;
}DLIST;

void create(DLIST *pdl)
{
    NODE *p;NODE *temp;int wish;
    do{
        p=pdl->head;
        temp=(NODE*)malloc(sizeof(NODE));
        printf("enter the info");
        scanf("%d",&temp->info);
        if(p==NULL || temp->info<p->info)
        {
            temp->prev=NULL;
            temp->next=p;
            if(p!=NULL) 
            {
                p->prev=temp;
            }
            pdl->head=temp;
        }
        else
        {
            while(p->next!=NULL && p->next->info<temp->info)
            { 
                p=p->next;
            }
            temp->prev=p;
            temp->next=p->next;
            if(p->next!=NULL)
            {
                p->next->prev=temp;}
                p->next=temp;
            } 
            printf("do you want to add another\n");
            scanf("%d",&wish);
        }
        while(wish!=0);
}

void disp(DLIST *pdl)
{
    if(pdl->head==NULL)
    {
        printf("empty");
        return;
    }
    NODE *p=pdl->head;
    while(p!=NULL)
    {   
        printf("%d ",p->info);
        p=p->next;
    }
}

void merge(DLIST *pdl1,DLIST *pdl2,DLIST *pdl3)
{
    NODE *p,*q,*temp,*r;
    p=pdl1->head;
    q=pdl2->head;
    r=pdl3->head;
    while(p!=NULL && q!=NULL)
    { 
        temp=(NODE*)malloc(sizeof(NODE));
        if(p->info<q->info)                 // p is smaller
        {
            temp->info=p->info;
            p=p->next;
        }
        else
        {
            temp->info=q->info;
            q=q->next;   // q is smaller
        }
        r=pdl3->head;
        temp->next=NULL;
        if(r==NULL)
        {
            temp->prev=NULL;
            pdl3->head=temp;
        }
        else
        {
            while(r->next!=NULL)
            {
                r=r->next;
            } 
            temp->prev=r;
            r->next=temp;
        }
    }
    while(p!=NULL)
    {  
        temp=(NODE*)malloc(sizeof(NODE));
        temp->info=p->info;
        p=p->next;
        temp->next=NULL; 
        r=pdl3->head;
        if(r==NULL)
        {
            temp->prev=NULL;
            pdl3->head=temp;
        }
        else
        {
            while(r->next!=NULL)
            {
                r=r->next;
            }
            temp->prev=r;
            r->next=temp;
        }
    }
    while(q!=NULL)
    {
        temp=(NODE*)malloc(sizeof(NODE));
        temp->info=q->info;
        q=q->next;
        temp->next=NULL; 
        r=pdl3->head; 
        if(r==NULL)
        {
            temp->prev=NULL;
            pdl3->head=temp;
        }
        else
        {
            while(r->next!=NULL)
            {
                r=r->next;
            }
            temp->prev=r;
            r->next=temp;
        }
    }
}

void init(DLIST *pdl)
{
    pdl->head=NULL;
} 

main()
{
    DLIST ob1,ob2,ob3;
    init(&ob1);
    init(&ob2);
    init(&ob3);
    printf("list 1 creation\n"); 
    create(&ob1);
    disp(&ob1);
    printf("\n list 2 creation");
    create(&ob2);
    disp(&ob2);
    printf("\nmerging the two lists\n"); 
    merge(&ob1,&ob2,&ob3);
    printf("Merged result\n"); 
    disp(&ob3);
}
 
  
