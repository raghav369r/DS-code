#include<stdio.h>
//#define length 10
int length;
int heapsize;
void swap(int *a,int *b){
	int c=*b;
	*b=*a;
	*a=c;
}
void Max_Heapify(int *a,int i){
	int leftchild=2*i,rightchild=2*i+1,lar;
	if(a[leftchild]>a[i]&& leftchild<=heapsize)
		lar=leftchild;
	else lar=i;
	if(a[rightchild]>=a[lar] && rightchild<=heapsize)
		lar=rightchild;
	if(lar!=i){
		swap(&a[lar],&a[i]);
		Max_Heapify(a,lar);
	}
}
void Build_maxheap(int *a){
	for(int i=length/2;i>=1;i--)
		Max_Heapify(a,i);
}
void heapsort(int *a){
	Build_maxheap(a);
	for(int i=length;i>=2;i--){
		swap(&a[1],&a[i]);
		heapsize--;
		Max_Heapify(a,1);
	}
}
int main(){
	int i;
	printf("Enter no of elements: ");
	scanf("%d",&length);
	heapsize=length;
	int a[length+1];
	for(i=1;i<=length;i++){
		scanf("%d",&a[i]);
	}
	heapsort(a);
	for(i=1;i<=length;i++) printf("%d->",a[i]);
}

