#include<stdio.h>
int HASHFUN(int *,int,int);
void display(int *,int);
int delete(int *,int,int);
int search(int *,int,int);
int main(){
	int HASHTABLE[10],i,len=10;
	for(i=0;i<10;i++) HASHTABLE[i]=-1;
	/*printf("Enter no of elements to add: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter element add: ");
		scanf("%d",&ele);
		HASHFUN(HASHTABLE,10,ele);
	}
	display(HASHTABLE,10);*/
	int op,ele;
	while(1){
		printf("1..add\n2..search\n3..delete\n4..display\n5..exit\nEnter ur choice: ");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("Enter element add: ");
				scanf("%d",&ele);
				if(HASHFUN(HASHTABLE,len,ele)) printf("Element added successfully\n");
				else printf("hash table is full,can't add element!!\n");
				break;
			case 2:
				printf("Enter element to search: ");
				scanf("%d",&ele);
				i=search(HASHTABLE,ele,len);
				if(i>0) printf("Element found at: %d\n",i);
				else printf("Element not found!!\n");
				break;
			case 3:
				printf("Enter element delete: ");
				scanf("%d",&ele);
				if(delete(HASHTABLE,ele,len)) printf("Element deleted successfully\n");
				else printf("Element not found to delete!!\n");
				break;
			case 4:
				display(HASHTABLE,len);
				break;
			case 5:
				return 1;
		}
	}
}
int HASHFUN(int *HASHTABLE,int len,int ele){
	int key=ele%len;
	if(HASHTABLE[key]==-1){
		HASHTABLE[key]=ele;
		return 1;
	}
	else{
		int check=key;
		key++;
		for(;check!=key;key=(key+1)%len){
		//for(i=key;i<len;i++,key=(key+i)%len){
			if(HASHTABLE[key]==-1){
				HASHTABLE[key]=ele;
				return 1;
			 }
		}
	}
	return 0;
}
int search(int *HASHTABLE,int ele,int len){
	int key=ele%len,i;
	if(HASHTABLE[key]==ele) return key;
	for(i=key+1;HASHTABLE[i]!=-1 && i!=key;i=(i+1)%len){
		if(HASHTABLE[i]==ele)
			return i;
	}
	return -1;
}
void display(int *HASHTABLE,int len){
	for(int i=0;i<len;i++){
		printf("%d\n",HASHTABLE[i]);
	}
}
int delete(int *HASHTABLE,int ele,int len){
	int key=ele%len,i;
	if(HASHTABLE[key]==ele){
		HASHTABLE[key]=-1;
		return 1;
	}
	//for(i=key+1;HASHTABLE[i]!=-1 && i!=key;i=(i+1)%len){
	for(i=key+1;i!=key;i=(i+1)%len){
		if(HASHTABLE[i]==ele){
			HASHTABLE[i]=-1;
			return 1;
		}
	}
	return 0;
}
