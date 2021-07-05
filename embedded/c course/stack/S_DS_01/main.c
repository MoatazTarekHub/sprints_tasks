#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top=-1;
char stack[300]= {0};
void push(char u8data)
{
    if (top==(20-1))
    {

        printf("mfeeesh msa7a");

    }
    else
    {
        top++;
        stack[top]=u8data;
    }
}
char pull(void)
{
    if(top==(-1))
    {

        printf(" msa7a fadya mfeesh 7aga agbhalak");

    }
    else
    {
        int data= stack[top];
        top--;
        return data;
    }
}
void printStack(void)
{
    for(int i=0; i<=top; i++)
    {

        printf("%c",stack[i]);

    }


}

char*balancedparenthese(char*expression)
{

    int counter=-1;
    for (int i=0 ; i<strlen(expression); i++)
    {
        if ((expression[i]=='(')||(expression[i]=='{'))
        {
            push(expression[i]);
            counter++;
        }
        if ((expression[i]==')'))
        {
            if ((stack[counter]=='('))
            {
                push(expression[i]);
                counter--;
            }
            else
            {
                return "not balanced";
            }
        }
         if ((expression[i]=='}'))
        {
            if ((stack[counter]=='{'))
            {
                push(expression[i]);
                counter--;
            }
            else
            {
                return "not balanced";
            }
        }

     //printf("%c",expression[i]);
    }
     if (counter!=-1){
            return "not balanced";

        }
    return "balanced";

}
int main()
{
    char str[]="(({2*3}+5))";
    char *res=balancedparenthese(str);




   for(int i=0; i<strlen(res); i++)
    {
        printf("%c",res[i]);

    }

    //printStack();
    return 0;
}
