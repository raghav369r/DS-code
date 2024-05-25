#include<stdio.h>
int main(){
	int arr[1000];
	arr[0]=1;
	arr[1]=10;
	int i=1;
	while(arr[i]<1000000000){
		arr[i+1]=arr[i]*10;
		i++;
	}for(int j=0;j<=i;j++)
	printf("%d  %d\n",arr[j],j);
}
