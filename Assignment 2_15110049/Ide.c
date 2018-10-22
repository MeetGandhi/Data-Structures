#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 5
 
struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK value;
STACK oper;
 

int result(const char *l, int x, int y);
void push(int num, STACK s);
int  pop(STACK s);
void display(STACK s);
void * print_chars(char *process_string, STACK oper, STACK value);
int precedence(char l,char p);
int f(const char *r);
 
int main ()
{
    int n,i ;
    char c[20][100];
    scanf("%d\n",&n);
    printf("\n The number of expressions , n = %d \n",n ) ;
    for(i=0;i<n;i++){
        printf("in for");
        scanf("%s\n",c[i]);
        printf("\nc[%d]=%s",i,c[i]) ;
        print_chars(c[i],oper,value);
        printf("Main left");
    }
    
    
}
/*  Function to add an element to the stack */
void push (int num, STACK s)
{
    if (s.top == (MAXSIZE - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
    return;
}
/*  Function to delete an element from the stack */
int pop (STACK s)
{
    int num;
    if (s.top == - 1)
    {
        printf ("Stack is Empty\n");
        return (s.top);
    }
    else
    {
        num = s.stk[s.top];
        printf ("poped element is = %dn", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return(num);
}
/*  Function to display the status of the stack */
void display (STACK s)
{
    int i;
    if (s.top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%d\n", s.stk[i]);
        }
    }
    printf ("\n");
}

void * print_chars(char *process_string, STACK oper, STACK value) {
    printf("printchars entered");
    int i;
    int k=0;
    int m=0;
    int n=0;
    int string_len;

    string_len = strlen(process_string);

    for(i = 0; i < string_len; i++) {
        printf("%s\n",process_string[i]);
        k=(int)process_string[i];
        if(k>=48 && k<=57){
            m= (int) atoi(( const char *)process_string[i]); 
            push(m,value);
            
        }
        else{
            if (oper.top == - 1){
                printf ("Stack operator is Empty\n");
                push(process_string[i],oper);
            }
            else{
                if(f(oper.top)>=f(process_string[i])){
                    const char *l=pop(oper);
                    int y=pop(value);
                    int x=pop(value);
                    int res=result(l,x,y);
                    push(res,value);
                }
                else{
                    push(process_string[i],oper);
                }
                
                
            }
        }
        
    }

    printf("\n");
    display(oper);
    display(value);
    printf("printch");
}

int f(const char *r){
    
    if(r=="^"){
        return 4;
    }
    
    
    if(r=="/"){
        return 3;
    }
    
    
    if(r=="*"){
        return 2;
    }
    
    
    if(r=="+"){
        return 1;
    }
    
    
    if(r=="-"){
        return 0;
    }
}
int result(const char *l, int x, int y){
    if(l=="^"){
        return x^y;
    }
    if(l=="/"){
        return x/y;
    }
    if(l=="*"){
        return x*y;
    }
    if(l=="+"){
        return x+y;
    }
    if(l=="-"){
        return x-y;
    }
}

