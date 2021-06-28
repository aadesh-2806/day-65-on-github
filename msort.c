#include<stdio.h>
/*
void mergesort(int *,int,int);
void merge(int *,int,int,int);
*/
void merge(int *a,int low,int mid,int high)
{
	int b[20];
	int i,j,k;
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high)
	{
		if (a[i]<=a[j])
		b[k++]=a[i++];
		else
		b[k++]=a[j++];
	}
	while(i<=mid)
	b[k++]=a[i++];
	
	while(j<=high)
	b[k++]=a[j++];
	
	for(i=low;i<=high;i++)
	a[i]=b[i];
}
void mergesort(int *a, int s,int e)
{
	int mid;
	if (s<e)
	{
		mid=(s+e)/2;
		mergesort(a,s,mid);
		mergesort(a,mid+1,e);
		merge(a,s,mid,e);
	}
}


void main()
{
	int a[20],n,i;
	printf("how many values\n");
	scanf("%d",&n);
	printf("give values:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	printf("The sorted values are:\n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
	
}
