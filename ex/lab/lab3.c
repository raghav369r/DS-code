#include<stdio.h>
int binsearch(int *arr,int st,int e,int num){
	int mid=(st+e)/2;
	if(st>mid) return 0;
	if(arr[mid]==num) return 1;
	else if(arr[mid]>num) binsearch(arr,st,mid-1,num);
	else if(arr[mid]<num) binsearch(arr,mid+1,e,num);
}
int main(){
	int arr[10]={1,4,3,2,9,0,8,7,6,12};
	if(binsearch(arr,0,9,12)){
		printf("Element found");
	}
	else printf("Element not found");
}	
