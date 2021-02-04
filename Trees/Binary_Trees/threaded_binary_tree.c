//program to implement a threaded binary search tree
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct tnode
{
 	int data;
  	struct tnode *left;
  	struct tnode *right;
  	bool lthread;
  	bool rthread;
};

struct tnode *insert(struct tnode *,int);
void inorder(struct tnode*);
struct tnode *inordersuccessor(struct tnode*);

void main()
{
  	struct tnode *root;
  	int ch,num,k;
  	root=NULL;
 	while(1)
 	{
    	printf("\n1.Insert");
      	printf("\n2..Inorder Traversal.");
      	printf("\n3.exit");
      	scanf("%d",&ch);
       	switch(ch)
       	{
         	case 1: printf("Enter the element");
                 	scanf("%d",&num);
                 	root=insert(root,num);
                 	break;
         
         	case 2: printf("Inorder traversal..\n");
               		inorder(root);
               		break;

         	case 3: exit(0);
       	}
    }
}    
    
struct tnode *insert(struct tnode *t, int x)
{
		
	struct tnode *curr, *temp;
		
	curr=t;
		
	temp=(struct tnode*)malloc*sizeof(struct tnode);
	temp->data=x;
	temp->left=temp->right=NULL;
	temp->llthread=temp->rthread=true;
		
	if(curr==NULL)
	{
		return temp;
	}
	//search for position to insert and break
	while(1)
	{
	   	if(x<curr->data)
	   	{
			if(curr->lthread==false)	//points to child node
			{
	        	curr=curr->left; //move left
	    	}
			else
			{
		    	break;
			}
		}
		else
	   	{
			if(curr->rthread==false)//points to child node
			{
			    curr=curr->right;  //move right;
			}
		 	else
		 	{
		    	break;
		 	}
	    }
	}
		
	if(x<curr->data)
	{
        temp->left=curr->left;
		temp->right=curr;
	    curr->left=temp;
		curr->lthread=false;
	}
	else
	{
		temp->right=curr->right;
	    temp->left=curr;
		curr->right=temp;
		curr->rthread=false;
	}
		
}
		   

			
			
			
			
			
			
			
			
		
		
		
		
		
	
	
	
	
	
  
 






















