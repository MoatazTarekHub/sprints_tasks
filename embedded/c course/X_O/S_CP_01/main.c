#include <stdio.h>
#include <stdlib.h>
void print_TwoDim_array(char arr[5][5])
{
    for (int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }



}
int check_input(int *input,int cases){

for(int i=0;i<9;i++){
   if (input[i]==cases){
            return 2;
    }
}
return 1;

}
int check_result(char arr[5][5])
{
    if((arr[0][0]==arr[0][2])&&(arr[0][2]==arr[0][4]))
    {
        return 1;
    }
    else if ((arr[2][0]==arr[2][2])&&(arr[2][2]==arr[2][4]))
    {
        return 1;
    }
    else if ((arr[4][0]==arr[4][2])&&(arr[4][2]==arr[4][4]))
    {
        return 1;
    }
    else if ((arr[0][0]==arr[2][0])&&(arr[2][0]==arr[4][0]))
    {
        return 1;
    }
    else if ((arr[0][2]==arr[2][2])&&(arr[2][2]==arr[4][2]))
    {
        return 1;
    }
    else if ((arr[0][4]==arr[2][4])&&(arr[2][4]==arr[4][4]))
    {
        return 1;
    }
    else if ((arr[0][0]==arr[2][2])&&(arr[2][2]==arr[4][4]))
    {
        return 1;
    }
    else if ((arr[0][4]==arr[2][2])&&(arr[2][2]==arr[4][0]))
    {
        return 1;
    }



}

int main()
{
    int counter =0;
    int input=0;
    int flag=1;
    int index=0;
    char arr[5][5]= {{'1','|','2','|','3'},{'-','-','-','-','-'},{'4','|','5','|','6'},{'-','-','-','-','-'},{'7','|','8','|','9'}};
    int cases[9]={0};
    printf("user 1 is play with (O) and user 2 play with (X) \n \n");

    while(counter<9)
    {
        printf("please enter which case you want to play in \n");
        print_TwoDim_array(arr);
        printf("\n");
        printf("\n");
        scanf ("%d",&input);
        while(check_input(cases,input)!=1){
        printf("please enter valid place \n");
        scanf ("%d",&input);
        }
        cases[index]=input;

        switch(input)
        {
        case 1:
            if (flag==1)
            {
                arr[0][0]='O';
                flag=2;
            }
            else if(flag==2)
            {
                arr[0][0]='X';
                flag=1;
            }

            break;
        case 2:
            if (flag==1)
            {
                arr[0][2]='O';
                flag=2;
            }
            else if(flag==2)
            {
                arr[0][2]='X';
                flag=1;
            }

            break;
        case 3:
            if (flag==1)
            {
                arr[0][4]='O';
                flag=2;
            }
            else if(flag==2)
            {
                arr[0][4]='X';
                flag=1;
            }

            break;
        case 4:
            if (flag==1)
            {
                arr[2][0]='O';
                flag=2;
            }
            else if(flag==2)
            {
                arr[2][0]='X';
                flag=1;
            }

            break;
        case 5:
            if (flag==1)
            {
                arr[2][2]='O';
                flag=2;
            }
            else if(flag==2)
            {
                arr[2][2]='X';
                flag=1;
            }

            break;
        case 6:
            if (flag==1)
            {
                arr[2][4]='O';
                flag=2;
            }
            else if(flag==2)
            {
                arr[2][4]='X';
                flag=1;
            }

            break;
        case 7:
            if (flag==1)
            {
                arr[4][0]='O';
                flag=2;
            }
            else if(flag==2)
            {
                arr[4][0]='X';
                flag=1;
            }

            break;
        case 8:
            if (flag==1)
            {
                arr[4][2]='O';
                flag=2;
            }
            else if(flag==2)
            {
                arr[4][2]='X';
                flag=1;
            }

            break;
        case 9:
            if (flag==1)
            {
                arr[4][4]='O';
                flag=2;
            }
            else if(flag==2)
            {
                arr[4][4]='X';
                flag=1;
            }

            break;


        default:
            printf("mtgwdsh yla w d5l mn 1 l 9\n");
            counter--;
            index--;
        }
        if(check_result(arr)==1)
        {
            print_TwoDim_array(arr);

            if (flag==2)
            {
                printf("\n mabrook ksbt ya user 1 \n");

            }
            else if(flag==1)
            {
                printf("\n mabrook ksbt ya user 2 \n");

            }

            break;


        }
         counter ++;
         index ++;
    }
    if (counter==9)
    {      print_TwoDim_array(arr);

        printf("mfeesh 7d ksb t3adol ya wlad \n");

    }



}
