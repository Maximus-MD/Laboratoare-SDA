#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i,n;
    printf("Indroduceti n =");
    scanf("%d",&n);
    int a[n];
    for(i=0; i<n; i++)
    {
        a[i]= rand()%100;
    }
    printf("\nArray este:\n");
    for( i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    int s=0;
    for (i=0; i<n; i++)
    {
        s=s+a[i];
    }
    printf("Suma elementelor este = %d",s);
    int p=1;
    for (i=0; i<n; i++)
    {
        p=p*a[i];
    }
    printf("produsul elementelor este = %d",p);
    return(0);
}