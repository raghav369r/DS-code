#include<stdio.h>
void sort(int *arr,int len){
	int i,j,n=len;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int a=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=a;
			}
		}
	}
}
int main(){
	int n,i;
	printf("enter no of elements: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,n);
	for(i=0;i<n;i++) printf("%d-->",a[i]);
}
