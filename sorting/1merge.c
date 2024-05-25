//Merge sort index starts with 1
#include<stdio.h>
#include<math.h>
void sort(int *,int ,int);
void merge(int *,int ,int ,int);
int main(){
	int n,i;
	printf("enter no of elements: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,1,n);
	for(i=0;i<n;i++) printf("%d-->",a[i]);
}
void sort(int *a,int start,int end){
	if(start<end){
		int mid=(start+end)/2;
		sort(a,start,mid);
		sort(a,mid+1,end);
		merge(a,start,mid,end);
	}
}
void merge(int *a,int start,int mid ,int end){
	printf("\n%d %d %d\n",start,mid,end);
	int len1=mid-start+1,len2=end-mid,i,j,k;
	int left[len1+1];
	int right[len2+1];
	for(i=0;i<len1;i++) left[i]=a[start-1+i];
	for(j=0;j<len2;j++) right[j]=a[mid+j];
	left[len1]=right[len2]=INFINITY;
	i=j=0;
	for(k=start-1;k<end;k++){
		if(left[i]<right[j]) a[k]=left[i++];
		else a[k]=right[j++];
	}	
}
