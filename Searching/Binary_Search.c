#include<stdio.h>
void BinarySearch(int  arr[],int length,int key)
{
    int i,mid,end=length-1,start=0,found=0,pstn;
    for(i=0;i<length;i++)
    {
        mid=((start+end)/2);
        if(arr[mid]==key)
        {
            found++;
            pstn=mid+1;
            break;
        }
        else if(arr[mid]>key)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    if(found)
    {
        printf("%d is found at %d position.",key,pstn);
    }
    else
    printf("Element is not found!!");
}
int main()
{
    int i,length,key;
    printf("Enter the length of the array: \n");
    scanf("%d",&length);
    int a[length];
    printf("Enter the array elements: \n");
    for(i=0;i<length;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nArray elements are: \n");
    for(i=0;i<length;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nEnter the element to search: \n");
    scanf("%d",&key);
    printf("Binary Search example: \n");
    BinarySearch(a,length,key);
}