#include<stdio.h>
void LinearSearch(int arr[],int length,int key)
{
    int i,found=0,pstn;
    for(i=0;i<length;i++)
    {
        if(key==arr[i])
        {
            found++;pstn=i;
        }
    }
    if(found==1)
    {
        printf("The element %d is found at: %d postition.",key, (pstn+1));
    }
    else
    printf("Element Not Found!!");
}
int main()
{
    int length,key,i;
    printf("Enter the size of the array: \n");
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
    printf("Linear Search : \n");
    LinearSearch(a,length,key);
}