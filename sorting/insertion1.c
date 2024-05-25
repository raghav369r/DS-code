#include<stdio.h>
int main(){
	int arr[]={122,17,93,3,36,1,-1,0,100,999};
	int i,j,k,tmp,n=10,no=0;
	for(i=1;i<n;i++,no++){
		for(j=0;j<i;j++,no++){
			if(arr[i]<arr[j]){
				tmp=arr[i];
				for(k=i;k>j;k--,no++)
					arr[k]=arr[k-1];
				arr[k]=tmp;
			}
		}
	}
	for(i=0;i<n;i++) printf("%d-->",arr[i]);
	printf("\n%d-->",no);
}/*
int main(){
	int arr[]={122,17,93,3,36,1,-1,0,100,999};
	int i,j,k,tmp,n=10,no=0;
	for(i=1;i<n;i++,no++){
		tmp=arr[i];
		for(k=i-1;arr[k]>tmp && k>=0;k--,no++)
			arr[k+1]=arr[k];
		arr[k+1]=tmp;
	}
	for(i=0;i<n;i++) printf("%d-->",arr[i]);
	printf("\nno= %d",no);
}*/
