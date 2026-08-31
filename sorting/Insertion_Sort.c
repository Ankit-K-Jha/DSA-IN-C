#include<stdio.h>
void printarray(int *a,int length)
{
    for(int  i=0;i<length;i++)
    {
        printf("%d ",a[i]);
    }
}
void insertionsort(int *a, int length)
{
    int key,j,i;
    for(i=1;i<length;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main()
{
    int length,i;
    printf("Enter the length of the array: \n");
    scanf("%d",&length);
    int a[length];
    printf("Enter the array elements: \n");
    for(i=0;i<length;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nArray elements are: \n");
    printarray(a,length);
    printf("\nInsertion Sort: \n");
    insertionsort(a,length);
    printarray(a,length);
}