
//program to check if the string is of the form xCy
//x is a string consisting of characters a and b
//y is a string which is the reverse of x
#include<stdio.h>
#include<stdlib.h>
struct stack
{
	char s[10];
 	int top;
};
 
void push(struct stack*, char);
char pop(struct stack *);
int check(char*);

int main()
{
 	int r;
 	char t[100];
	printf("Enter the string to check..\n");
 	scanf("%s",t);
  	r=check(t);
  	if(r)
  	{
   		printf("\nString is of the form xCy");
   	}
    else 
    {
   		printf("\nNot in the form xCY");
	}
}

 	
int check(char t[])
{
	struct stack s;//stack of characters
	char x;
	int i=0;
	
	s.top=-1;
    //push all the chacters till C is encountered
    //into the stack
	while(t[i]!='C')
	{
	    push(&s, t[i]);
	    i++;
	}
	i++;
        //read the remaining characters and
        //pop the characters from the stack
        //compare with the character read in the string
	while(t[i]!='\0')
	{
		x=pop(&s); 
		if(x!=t[i])
		{
		   return 0;
		}
		i++;
	}
	return 1;
}
	
	
void push(struct stack *p, char x)
{
   	p->top++;
   	p->s[p->top]=x;
}

char pop(struct stack  *p)
{
    char  x;
    x=p->s[p->top];
    p->top--;
    return x;
}




















