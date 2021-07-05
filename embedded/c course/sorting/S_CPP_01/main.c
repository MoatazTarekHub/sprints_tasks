#include <stdio.h>
#include <stdlib.h>
int cheking(int*arr,int size)
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
        return 0;
    }
    else
    {
        printf("the array is not sorted \n");
        return 1;

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
int searching(int*arr,int size,int input)
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
int main()
{
    int arr[]= {1,2,4,3,6,9,15};
    int size_arr=sizeof(arr)/sizeof(arr[0]);
    if(cheking(arr,size_arr)==1){
    sorting(arr,size_arr);
    }
    printing(arr,size_arr);
    int index=searching(arr,size_arr,12);
    printf("%d",index);

    return 0;
}
