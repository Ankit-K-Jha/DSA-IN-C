#include<stdio.h>
int main()
{
    int length,i,j,temp,p;
    printf("Enter the length of the array: ");
    scanf("%d",&length);
    int a[length];
    printf("Enter the array entities: \n");
    for(i=0;i<length;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nArray elements are: \n");
    for(i=0;i<length;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nSelection sort example: \n");
    // for(i=0;i<length;i++)
    // {
    //     p=i;
    //     for(j=i;j<length;j++)
    //     {
    //         if(a[j]<a[p])
    //         {
    //             temp=a[p];
    //             a[p]=a[j];
    //             a[j]=temp;
    //         }
    //     }
    // }
    for(i=0;i<length-1;i++)
    {
        p=i;
        for(j=i;j<length;j++)
        {
            if(a[j]<a[p])
            {
                p=j;
            }
        }
        temp=a[p];
        a[p]=a[i];
        a[i]=temp;
    }
    for(i=0;i<length;i++)
    {
        printf("%d ",a[i]);
    }
}