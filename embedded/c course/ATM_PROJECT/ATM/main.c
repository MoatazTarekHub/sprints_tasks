#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
} ST_cardData_t;
ST_cardData_t user_card= {};


typedef struct ST_terminalData_t
{
    float transAmount;
    float maxTransAmount;
    uint8_t transactionDate[11];
} ST_terminalData_t;
ST_terminalData_t user_terminal= {};


typedef enum EN_transStat_t {DECLINED,
                             APPROVED
                            } EN_transStat_t;


typedef struct ST_accountBalance_t
{
    float balance;
    uint8_t primaryAccountNumber[20];
} ST_accountBalance_t;
ST_accountBalance_t ser_data[10] =
{
    10.12, "123123456",
    100.00, "123456789",
    6000.00, "234567891",
    500.00, "258649173",
    1500.12, "456789123",
    .55, "456789321",
    3250.25, "567891234",
    2100.00, "654823719",
    1.00, "793148625",
    0.00, "971362485",
};
void card_data(void)
{
    printf("please enter your name \n");
    gets(user_card.cardHolderName);

    printf("please enter the primary account number\n ");
    gets(user_card.primaryAccountNumber);

    printf("please enter the date of card exp. MM/YY \n");
    gets(user_card.cardExpirationDate);
}
void terminal_data(void)
{
    printf("please enter transaction date DD/MM/YY \n");
    gets(user_terminal.transactionDate);

    printf("please enter the amount\n ");
    scanf("%f",&user_terminal.transAmount);

    user_terminal.maxTransAmount=5000;

}
EN_transStat_t check_data(void)
{
    int i,j;
    EN_transStat_t state=DECLINED;

    for( i=0; i<10; i++)
    {

        for( j=0; j<9; j++)
        {
            if (user_card.primaryAccountNumber[j]!=ser_data[i].primaryAccountNumber[j])
            {
                break    ;

            }

        }
        if (j==9)
        {
            state= APPROVED;
            break;
        }

    }
    if (state==DECLINED){return state;}
    int card_year= ((user_card.cardExpirationDate[3]-'0')*10)+(user_card.cardExpirationDate[4]-'0');

    int tranc_year= ((user_terminal.transactionDate[8]-'0')*10)+(user_terminal.transactionDate[9]-'0');


    int card_month= ((user_card.cardExpirationDate[0]-'0')*10)+(user_card.cardExpirationDate[1]-'0');

    int tranc_month= ((user_terminal.transactionDate[3]-'0')*10)+(user_terminal.transactionDate[4]-'0');

    if (tranc_year>card_year)
    {
        state= DECLINED;

    }
    else if (tranc_year==card_year)
    {
        if(tranc_month>card_month)
        {
            state= DECLINED;
        }
        else
        {
            state= APPROVED;

        }

    }
    else
        {
            state= APPROVED;

        }
    if (state== DECLINED){
            printf("%d  %d", tranc_year , card_year);
            return state;}

    if((user_terminal.transAmount<user_terminal.maxTransAmount)&&(user_terminal.transAmount<ser_data[i].balance))
    {

        state= APPROVED;


    }
    else
    {
        state= DECLINED;

    }
    return state;

}






int main()
{
    char flag='y';
    while(flag=='y')
    {
        card_data();
        terminal_data();
        EN_transStat_t state=check_data();
        if (state==APPROVED)
        {
            printf("The Transaction is APPROVED \n ");
        }
        else
        {
            printf("The Transaction is DECLINED \n");
        }
        printf("do you want to continue ? ");

        scanf("%s",&flag);

        fflush(stdin);

        if(flag=='n')
        {
            break;
        }


    }
    return 0;

}
