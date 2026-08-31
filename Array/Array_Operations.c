#include <stdio.h>

int main()
{
    int n, m, i, j, ch, elt, size, c = 1;
    printf("Enter the size of the array:- ");
    scanf("%d", &size);
    printf("Enter the number of desired entities:-");
    scanf("%d", &n);
    if (n > size || n < 0)
    {
        printf("Invalid number of elements!\n");
        return 0;
    }
    int a[size];
    printf("Enter the elements of the array:- \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Array elements are:- \n");
    for (i = 0; i < n; i++)
    {

        printf("%d ", a[i]);
    }
    printf("\n");
    while (c == 1)
    {
        printf("Enter your choice:- \n1) Insertion\n2) Deletion\n3) Maximum\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            if (n == size)
            {
                printf("Array is full! Cannot insert.\n");
                break;
            }
            printf("Enter the element to insert:- ");
            scanf("%d", &elt);
            printf("Enter the index to insert:- ");
            scanf("%d", &j);
            if (j < 0 || j > n)
            {
                printf("Invalid index!\n");
                break;
            }
            for (i = n - 1; i >= j; i--)
            {
                a[i + 1] = a[i];
            }
            a[j] = elt;
            n++;
            printf("Modified array is:- \n");

            for (i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
            printf("Enter 1 to continue:");
            scanf("%d", &c);
        }
        break;
        case 2:
        {
            if (n == 0)
            {
                printf("Array is empty!\n");
                break;
            }
            printf("Enter the index of the element to delete:- ");
            scanf("%d", &j);
            if (j < 0 || j >= n)
            {
                printf("Invalid index!\n");
                break;
            }
            for (i = j; i < n; i++)
            {
                a[i] = a[i + 1];
            }
            n--;
            printf("Modified array is:- \n");
            for (i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
            printf("Enter 1 to continue:");
            scanf("%d", &c);
        }
        break;
        case 3:
        {
            m = a[0];
            for (i = 0; i < n; i++)
            {
                if (a[i] > m)
                {
                    m = a[i];
                }
                else
                    continue;
            }
            printf("Maximum element is:- %d \n", m);
            printf("Enter 1 to continue:");
            scanf("%d", &c);
        }
        break;
        default:
        {
            printf("Invalid choice!!");
            printf("Enter 1 to continue:");
            scanf("%d", &c);
        }
        break;
        }
    }
    return 0;
}