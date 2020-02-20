#include <stdio.h>
int sort(long int a[],int low,int high);
int merge(long int a[],int low,int mid,int high);
int i,n;
long int x[500005],y[500005];
long long int ans;
int main()
{
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%ld%ld",&x[i],&y[i]);
    sort(x,0,n-1);
    sort(y,0,n-1);
    for(i=0; i<n; i++)
        ans+=(x[i]+y[i])*(2*i-n+1);
    printf("%lld",ans);
    return 0;
}
int sort(long int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        sort (a,low,mid);
        sort (a,mid+1,high);
        merge(a,low,mid,high);
    }
    return 0;
}
int merge(long int a[],int low,int mid,int high)
{
    int n1,n2,i,j,k;
    long int arr1[255000],arr2[255000];
    n1=mid-low+1;
    n2=high-mid;
    for(i=0; i<n1; i++)
        arr1[i]=a[low+i];
    for(j=0; j<n2; j++)
        arr2[j]=a[mid+j+1];
    arr1[i]=200000000;
    arr2[j]=200000000;
    i=0;
    j=0;
    for(k=low; k<=high; k++)
    {
        if(arr1[i]<=arr2[j])
            a[k]=arr1[i++];
        else
            a[k]=arr2[j++];
    }
    return 0;
}
