#include<stdio.h>
#include <stdlib.h>
int binsearch(int *arr,int st,int en,int key){
	int mid=(st+en)/2;
	if(arr[mid]==key) return mid;
	else if(st==en && arr[mid]!=key) return-1;
	else if(arr[mid]>key) binsearch(arr,st,mid-1,key);
	else if(arr[mid]<key) binsearch(arr,mid+1,en,key);
}
int main(){
	int key,len,i;
	printf("Enetr no of elements: ");
	scanf("%d",&len);
	int *arr=(int *)calloc(len,4);
	printf("Enter elements: ");
	for(i=0;i<len;i++) scanf("%d",&arr[i]);
	printf("Enter element to search: ");
	scanf("%d",&key);
	int res=binsearch(arr,0,len,key);
	if(res!=-1)
		printf("Element found at index %d",res);
	else 
		printf("Element not found!");
}
