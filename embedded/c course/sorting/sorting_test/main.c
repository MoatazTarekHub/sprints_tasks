
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#define NOTFOUND 0
int cheking(uint8_t *arr,uint8_t size)
{
    int flag=0;
    int temp;
    for(int j=0; j<size-1; j++)
    {

        if (arr[j]>arr[j+1])
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            flag=1;
        }

    }
    if (flag==0)
    {
        printf("the array is sorted \n");
        return 1;
    }
    else
    {
        printf("the array is not sorted \n");
        return 0;

    }

}
void sorting(int*arr,int size)
{


    int temp;
    int flag;
    for(int i=0; i<size-1; i++)
    {
        flag=0;
        for(int j=0 ; j<size-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if (flag==0)
        {
            printf("the array is now sorted \n");
            break;
        }
    }
}
int searching(uint8_t*arr,uint8_t size,uint8_t input)
{
    int middle;
    int last=size-1;
    int first =0;
    for(int i=0; i<size; i++)
    {
        middle=(last+first)/2;
        if (input>arr[middle])
        {
            first=middle+1;
        }
        if (input<arr[middle])
        {
            last=middle-1;
        }
        if (input==arr[middle])
        {
            break;
        }
    }
    return middle;

}
void printing(int*arr,int size)
{
    for(int i=0 ; i<size; i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");

}
void Test_sorted(void)
{
    uint8_t arr[] = {1, 2, 3, 4};

    uint8_t size = sizeof(arr) / sizeof(arr[0]);
    if ( cheking(arr, size))
    {
        printf(" Test Case 1 Passed\n");
    }
    else
    {
        printf(" Test Case 1 Failed\n");
    }
}

void Test_Firstelement(void)
{
    uint8_t arr[] = {5, 6, 8, 11};

    uint8_t size = sizeof(arr) / sizeof(arr[0]);
    if (searching(arr, size,5)==0)
    {
        printf(" Test Case 2 Passed\n");
    }
    else
    {
        printf(" Test Case 2 Failed\n");
    }
}

void Test_Notfound(void)
{
    uint8_t arr[] = {1, 6, 3, 0};

    uint8_t size = sizeof(arr) / sizeof(arr[0]);

    if (searching(arr, size, 0) == NOTFOUND)
    {
        printf(" Test Case 3 Passed\n");
    }
    else
    {
        printf("Test Case 3 Failed\n");
    }
}

int main()
{
    Test_sorted();
    Test_Firstelement();
    Test_Notfound();
}
