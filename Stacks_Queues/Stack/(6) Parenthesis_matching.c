#include<stdio.h>

void push(char *s,int*,char);
char pop(char* s, int*);
int isempty(int);				// takes top as parameter
int match(char *);

int main()
{
	char expr[10];
  	printf("Enter the expression\n");
  	scanf("%s",expr);
  	int result=match(expr);
  	if(result)
  	{
   		printf("Matching is correct\n");
   	}
 	else
 	{
   		printf("Matching failed\n");
    }
}


int match(char *expr)
{
    int i,top;
    char s[10]; // stack
	char ch,x;
    i=0;
    top=-1;
	
	while(expr[i]!='\0')
    {
       ch=expr[i];
       switch(ch)
       {
        	case '(':
          	case '{':
           	case '[':	push(s,&top,ch);
                     	break;

           	case ')':	if(!isempty(top))
                    	{
                      		x = pop(s,&top);
                      		if(x=='(')
                      		{
                        		break;
                        	}
                      		else
                      		{
                        		return 0;//mismatch of parenthesis
                        	}
                    	}	
                    	else
                    	{
                      		return 0;//extra closing parenthesis
                      	}

           	case '}':	if(!isempty(top))
                    	{
                      		x = pop(s,&top);
                      		if(x=='{')
                      		{
                        		break;
                        	}
                      		else
                      		{
                        		return 0;//mismatch of parenthesis
                        	}
                    	}	
                    	else
                    	{
                      		return 0;//extra closing parenthesis
                      	}

           	case ']':	if(!isempty(top))
                    	{
                      		x = pop(s,&top);
                      		if(x=='[')
                      		{
                        		break;
                        	}
                      		else
                      		{
                        		return 0;//mismatch of parenthesis
                        	}
                    	}	
                    	else
                    	{
                      		return 0;//extra closing parenthesis
                      }

        }//end switch
    	i++;
    }//end while
    if(isempty(top))
    {
    	return 1;
    }
    return 0;//extra opening parenthesis
}    
 
    
void push(char *s,int *t,char x)
{
	++*t;//increment top
  	s[*t]=x;
}

char pop(char *s, int *t)
{
   	char x;
    x=s[*t];
    --*t;//decrement top
    return x;
}
 
int isempty(int top)
{
   	if(top==-1)
   	{
    	return 1;
    }
    return 0;
}










