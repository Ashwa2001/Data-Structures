#include<stdlib.h>
#include<stdio.h>
struct node
{
  int data;
  struct node *next;
};

struct stack
{
	 struct node *top;
};

 void push(struct stack*, int);
 int pop(struct stack*);
 void display(struct stack);
 int main()
{
  
  struct stack s;
  int ch,k,x;

  s.top=NULL;
  
  while(1)
  {
    display(s);
    printf("\n1..push");
    printf("\n2..pop");
    printf("\n3..display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the value..");
              scanf("%d",&x);
              push(&s,x);
              break;
       case 2:k=pop(&s);
              if(k>=0)
                printf("element popped=%d\n",k);
              break;
        case 4:exit(0); 
   }
  }
 }

    void push(struct stack *p , int x)
    {      
           struct node *temp;
           temp=(struct node*)malloc(sizeof(struct node));
		        temp->data=x;
           temp->next=p->top;
           p->top=temp;
     }

     int pop(struct stack *p)
     {
          int x;
         struct node *q;
         if(p->top==NULL)
          {
            printf("Empty Stack\n");
             return -1;
           }
          else
           {
              q=p->top;
               x=q->data;
              p->top=q->next;
              free(q);
               return(x);
            }
      }


      

     void display(struct stack s)
     {
		 struct node *p;
         if(s.top==NULL)
           printf("Empty Stack\n");
         else
          {
			 p=s.top;
            while(p!=NULL)
            {
              printf("%d->",p->data);
              p=p->next;
             }
           }
      }
     

   

