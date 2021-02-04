#include<stdio.h>
#include<stdlib.h>

//merge 2  doubly LL


struct node
{
   int data;
   struct node *prev;
   struct node *next;
};

void insert_head(struct node**, int);	//
void insert_tail(struct node **, int);	//
void delete_node(struct node**, int);
void insert_pos(struct node **,int ,int);	//
void delete_pos(struct node**, int); 	//	
void display(struct node*);		//
void delete_last(struct node **);	//
void delete_first(struct node **);	//
void insert_order(struct node **,int);
int main()
{
  	struct node *head;
  	head=NULL;
  	int x,ch,pos;
  	while(1)
  	{
    	display(head);
    	printf("\n1..Insert Head..\n");
	    printf("2..Insert Tail.\n");
	    printf("3..Delete First..\n");
	    printf("4..Delete Last..\n");
	    printf("5..Delete node..\n");
	    printf("6..Delete at position\n");
	    printf("7..Insert at position\n");
	    printf("8..Insert in ascending order\n");
	    scanf("%d",&ch);
    	switch(ch)
    	{
         	case 1:	printf("Enter the value..\n");
               		scanf("%d",&x);
               		insert_head(&head,x);
               		break;
	        case 2: printf("Enter the value..\n");
	               	scanf("%d",&x);
	               	insert_tail(&head,x);
	               	break;
	        case 3:	delete_first(&head);
	                break;
	        case 4:	delete_last(&head);
	               	break;
	        case 5: printf("Enter the value..\n");
	               	scanf("%d",&x);
	               	delete_node(&head,x);
	               	break;
	        case 6: 	printf("Enter the position..\n");
	               	scanf("%d",&x);
	               	delete_pos(&head,x);
	               	break;
	        case 7: printf("Enter the value and position..\n");
	               	scanf("%d %d",&x,&pos);
	               	insert_pos(&head,x,pos);
	               	break;
	        case 8: printf("Enter value : ");
	        		scanf("%d",&x);
	        		insert_order(&head,x);
	        		break;

		    case 9: exit(0);
	    }
  	}
}

 void insert_pos(struct node **p, int x, int pos)
 {
	 
	struct node *q, *temp; 
	int i=1;
	 
	temp=(struct node*)malloc(sizeof(struct node));
	temp->next=temp->prev=NULL;
	temp->data=x; 
	q=*p; //copy head into q;
	 
	//move until the position is found 
	while((i<pos)&&(q->next!=NULL))
	{
		 q=q->next;
		 i++;
	}	 
	 
	if(i==pos)//position found
    {
        if(q->prev==NULL)//first position	
    	{
			temp->next=q;
			q->prev=temp;
			*p=temp;
    	}
        else //somewhere in middle
	  	{
			q->prev->next=temp;
			temp->prev=q->prev;
			temp->next=q;
			q->prev=temp;
	  	}	
	}	
	else if (i==pos-1)//last position , q is at the last node
	{
	 	q->next=temp;
	 	temp->prev =q;
	}	 
	else
	{
		printf("Invalid Position\n\n");
	}
}

 

void delete_pos(struct node **p, int pos)
{
	struct node *q;
	q=*p; // copy head into q;
	int i=1;
	//move forward until the position is found
	while((q!=NULL )&& (i<pos) )
	{
		q=q->next;
		i++;
	}
	if(q!=NULL)//position found
	{
	   	if((q->prev==NULL)&&(q->next==NULL))//only one node
	   	{
			*p=NULL;
		}
	   	else if(q->prev==NULL )//first position
	   	{
			*p=q->next;
			(*p)->prev=NULL;
	   	}
	   	else if (q->next==NULL) //last position
	   	{
			q->prev->next=NULL;
		}
	   	else //somewhere in the middle position
        {
			q->prev->next =q->next;
			q->next->prev=q->prev;
	   	}	
  		free(q);
	}
	else //q==NULL, end of the list
	{
	   printf("Invalid Position\n");
	}
	
}	

void insert_head(struct node **p, int x)
{
	struct node *temp;
	
	//create a node
	
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=temp->prev=NULL;
	
	if(*p==NULL)//check if it is the first node
	  *p=temp; // copy address of new node into head
	else
	{
    	temp->next=*p;  //link the new node to the first node
		(*p)->prev=temp;
		*p=temp; //copy temp into head
	}	
}	

void insert_tail(struct node **p, int x)
{
	
	struct node *temp, *q;
	//create a node
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=temp->prev=NULL;
	
	if(*p==NULL)//check if it is the first node
	{
		*p=temp;// copy address of new node into head
	}
	else
	{
		q=*p;
		//move forward till the last node is reached
        while(q->next!=NULL)
        {
	  		q=q->next;
	  	}
		//link the new node to last node
	    q->next=temp; 
	    temp->prev=q; 
	}
}	
	
void display(struct node *p)
{
    if(p==NULL)
	{
		printf("Empty List\n");
	}
	else
	{
	while(p!=NULL) // display each node 
	{
		printf("%d<->",p->data);
        p=p->next;
    }
	printf("\n");
	}	
}
	
void delete_first(struct node **p)
{
	struct node *q;	
	q=*p;	
		//if it is the only node in the list
	if(q->next==NULL)
	{
		*p=NULL;
	}
	else  //list contains more than one node
	{
		*p=q->next; // make head to point to next node
		(*p)->prev=NULL; //copy NULL into prev field
	}
	free(q);
} 		
	
void delete_last(struct node **p)  
{
	struct node *q;	
	q=*p;	
	//if it is the only node
	if(q->next==NULL)
	{
		*p=NULL;
	}
	else
	{
	    //go to the last node
		while(q->next!=NULL)
		{
			q=q->next;
		}	
		q->prev->next = NULL; //make previous field of last but one node as NULL
	}
    free(q);		
}			

void delete_node(struct node **p, int x)	
{
	struct node *q;
	q=*p;
	//move until the node is found
	while((q!=NULL)&&(q->data!=x))
	{
		q=q->next;
	}
	if(q!=NULL)//node found
	{
		if((q->prev==NULL)&&(q->next==NULL))//only one node
		{
			*p=NULL;
		}
		else if(q->prev==NULL )  //first node
		{
			*p=q->next;
			(*p)->prev=NULL;
		}
		else if( q->next==NULL)//last node
		{
			 q->prev->next=NULL ;
		}
		else //some where in middle
		{
			q->prev->next=q->next;
			q->next->prev=q->prev;
		}
		free(q);
	}
	else //q==NULL
	{
		printf("Node not found");
	}
}		
	
void insert_order(struct node **p,int x)
{
	struct node *new, *temp; 
	new=(struct node*)malloc(sizeof(struct node));
	new->next=new->prev=NULL;
	new->data=x; 
	temp = *p;
	if(temp == NULL)
	{
		*p = new;
	}
	else
	{
		while((x > temp->data) && (temp->next!=NULL))
		{
			temp = temp->next;
		}
		if(temp->prev == NULL)	//1st posn
		{
			new->next = temp;
			temp->prev = new;
			*p = new; 
		}
		else if(temp->next == NULL && temp->data<x)	// end
		{
			temp->next = new;
			new->prev = temp;
		}
		else	// middle
		{
			temp->prev->next = new;
			temp->prev = new;
			new->next = temp;
			new->prev = temp->prev;
		}
	}
}
	
	
	
	
	
	
	
		
		
		
		
		
		
		

	
	
	

	  
	  
	
	
	
	
	
	


