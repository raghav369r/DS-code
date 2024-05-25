#include<stdio.h>
int main(){
	int arr[]={122,121,120,199,188};
	int i,j,k,tmp,n=sizeof(arr)/4;
	for(j=1;j<n;j++){
		tmp=arr[j];
		k=j-1;
		while(arr[k]>tmp && k>=0){
			arr[k+1]=arr[k];
			k--;
		}
		arr[k+1]=tmp;
	} 
	for(i=0;i<n;i++) printf("%d-->",arr[i]);
}
