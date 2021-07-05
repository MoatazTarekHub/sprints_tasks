#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
int top=-1;
char stack[300]= {0};
typedef char E_State_t;
#define E_OK                        1
#define Error                       2
#define E_EMPTY                     3
#define BALANCED                    1
#define NOTBALANCED                 0

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

uint8_t*balancedParentheses(uint8_t*expression)
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

void Testcase1(void)
{
    E_State_t Estate = Error;
    uint8_t Testarr[] = "{{}";

    uint8_t *Ptr = balancedParentheses(Testarr);

    /* check if firest element of string  NoTBalanced*/
    if (Ptr[0] == 'n')
    {
        Estate = E_OK;
        printf("Test Case 1 Passed\n");
    }
    else
    {
        printf("Test Case 1 Failed\n");
    }
}

void Testcase2(void)
{
    E_State_t Estate = Error;
    uint8_t Testarr[] = "{}}";

    uint8_t *Ptr = balancedParentheses(Testarr);


    /* check if firest element of string  NoTBalanced*/
    if (Ptr[0] == 'n')
    {
        Estate = E_OK;
        printf("Test Case 2 Passed\n");
    }
    else
    {
        printf("Test Case 2 Failed\n");
    }
}

void Testcase3(void)
{
    E_State_t Estate = Error;
    uint8_t Testarr[] = "(({2*3}+5))";

    uint8_t *Ptr = balancedParentheses(Testarr);


    /* check if firest element of string  Balanced*/
    if (Ptr[0] == 'b')
    {
        Estate = E_OK;
        printf("Test Case 3 Passed\n");
    }
    else
    {
        printf("Test Case 3 Failed\n");
    }
}


void Testcase4(void)
{
    E_State_t Estate = Error;
    uint8_t Testarr[] = "{({2+10}}*11}})}";

    uint8_t *Ptr = balancedParentheses(Testarr);


    /* check if firest element of string  NoTBalanced*/
    if (Ptr[0] == 'n')
    {
        Estate = E_OK;
        printf("Test Case 4 Passed\n");
    }
    else
    {
        printf("Test Case 4 Failed\n");
    }
}


int main()
{    Testcase3();
    Testcase1();
    Testcase2();
    Testcase4();
}
