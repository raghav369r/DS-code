#include<stdio.h>
int main(){
	int arr[10]={122,17,93,3,36,1,-1,0,100,999};
	int i,j,min,mini;
	for(i=0;i<9;i++){
		min=arr[i];
		mini=i;
		for(j=i+1;j<10;j++){
			if(arr[j]<min){
				mini=j;
				min=arr[j];
			}
		}
		arr[mini]=arr[i];
		arr[i]=min;
	}
	for(i=0;i<10;i++) printf("%d-->",arr[i]);
}
