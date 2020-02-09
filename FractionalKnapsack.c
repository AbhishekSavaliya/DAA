#include<stdio.h>
#include<stdlib.h>
typedef struct item
{
    int num;
    double v,w;
}item;
typedef struct ans
{
    int n;
    double an;
}ans;
void display(item a[],int n)
{
    int i;
    printf("__________________________\n");
    for(i=0;i<n;i++)
        printf("%lf  %lf -> %lf-->%d\n",a[i].v,a[i].w,(a[i].v/a[i].w),a[i].num);
}
void insertionSort(item a[],int N)
{
    int i,t,j,key;
    for(i=1;i<N;i++)
    {
        key=i;
        for(j=i-1;j>=0;j--,key--)
        {
            if((a[j].v/a[j].w) < (a[key].v/a[key].w))
            {
                t=a[j].v;
                a[j].v=a[key].v;
                a[key].v=t;
                t=a[j].w;
                a[j].w=a[key].w;
                a[key].w=t;
                t=a[j].num;
                a[j].num=a[key].num;
                a[key].num=t;
            }
            else break;
        }
    }
}
void inSort(ans a[],int N)
{
    int i,t,j,key;
    double t1;
    for(i=1;i<N;i++)
    {
        key=i;
        for(j=i-1;j>=0;j--,key--)
        {
            if((a[j].n) > (a[key].n))
            {
                t=a[j].n;
                a[j].n=a[key].n;
                a[key].n=t;
                t1=a[j].an;
                a[j].an=a[key].an;
                a[key].an=t1;
            }
            else break;
        }
    }
}
void findItem(item a[],double tweight,int n,ans ans[])
{
    int i;
    double currentW=0;
    double tvalue=0,diff;
    for(i=0;i<n;i++)
        ans[i].n=a[i].num;
    for(i=0;currentW<tweight && i<n;i++)
    {
        tvalue=tvalue+a[i].v;
        currentW=currentW+a[i].w;
        ans[i].an=1;
    }
    if(currentW!=tweight)
    {
        if(i!=0)
            i--;
        diff=-currentW+tweight+a[i].w;
        tvalue=tvalue+(a[i].v*diff/a[i].w)-a[i].v;
        ans[i].an=diff/a[i].w;
    }
    printf("Total value is : %lf \n",tvalue);

    return ans;
}
void main()
{
    int n,i;
    double totalWeight;
    printf("Enter the number of total element :\n");
    scanf("%d",&n);
    item list[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the value and weight of %d item :\n",i+1);
        scanf("%lf",&list[i].v);
        scanf("%lf",&list[i].w);
        list[i].num=i;
    }
    //display(list,n);
    insertionSort(list,n);
    //display(list,n);
    printf("Enter the total weight\n");
    scanf("%lf",&totalWeight);
    ans ans[n];
    for(i=0;i<n;i++)
        ans[i].an=0;
    findItem(list,totalWeight,n,ans);
    inSort(ans,n);
    printf("___________________________________\n");
    for(i=0;i<n;i++)
        printf("%lf\n",ans[i].an);
}
