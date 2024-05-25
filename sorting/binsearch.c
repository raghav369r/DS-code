#include<stdio.h>
#include<stdlib.h>
int binsearch(int *,int int);
void sort(int *,int);
int main(){
	int key,len,i;
	printf("Enetr no of elements: ");
	scanf("%d",&len);
	int *arr=(int *)calloc(len,4);
	printf("Enter elements: ");
	for(i=0;i<len;i++) scanf("%d",&arr[i]);
	//for(i=0;i<len;i++) printf("%d-->",arr[i]);
	printf("\nEnter element to search: ");
	scanf("%d",&key);
	int res=binsearch(arr,len,key);
	if(res!=-1)
		printf("Element found at index %d",res);
	else 
		printf("Element not found!");
}
void sort(int *arr,int len){
	int i,j,k,tmp;
	for(i=1;i<len;i++){
		tmp=arr[i];
		for(k=i-1;arr[k]>tmp && k>=0;k--)
			arr[k+1]=arr[k];
		arr[k+1]=tmp;
	}
}
int binsearch(int arr[],int len,int key){
	sort(arr,len);
	int start=0,end=len-1,mid;
	while(start<=end){
		mid=(start+end)/2;
		if(arr[mid]==key) return mid;
		else if(arr[mid]>key) end=mid-1;
		else start=mid+1;
	}
	return -1;
}
