#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void merge(int *a,int p,int q,int r){
	int n1=q-p+1,n2=r-q,i,j,k;
	int L[n1+1];
	int R[n2+1];
	for(i=0;i<n1;i++) L[i]=a[p+i];
	for(j=0;j<n2;j++) R[j]=a[q+1+j];
	L[n1]=INFINITY;
	R[n2]=INFINITY;
	i=0;
	j=0;
	for(k=p;k<=r;k++){
		if(L[i]<=R[j]){
			a[k]=L[i];
			i++;
		}
		else{
			a[k]=R[j];
			j++;
		}
	}
}
void mergesort(int *a,int p,int r){
	if(p<r){
		int q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}
int main(){
	int n,i;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	int *arr=(int *)calloc(n,4);
	printf("Enter elements: ");
	for(i=0;i<n;i++) scanf("%d",&arr[i]);
	mergesort(arr,0,n-1);
	for(i=0;i<n;i++) printf("%d-->",arr[i]);	
}
