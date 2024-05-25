#include<stdio.h>
#include<stdlib.h>
int n;
int **adj;
int adja(int i){
	int k=0;
	for(int j=0;j<n;j++)
		if(adj[i][j]==1) k++;
	return k;
}
int aele(int i,int j){
	int k=0;
	for(int l=0;l<n;l++){
		if(adj[i][l]==1) k++;
		if(k==j) return l;
	}
}
int path(int i,int *p,int l){
	p[l]=i;
	int k=adja(i);
	if(k==0) return 0;
	else{
		for(int m=0;m<l;m++){
			if(p[m]==i){
				return l;
			}
		}
		for(int o=1;o<=k;o++){
			int kl=aele(i,o);
			int len=path(kl,p,l+1);
			if(len) return len;
			
		}
		return 0;
	}
}
int cir(){
	int i,j,ch;
	int *arr=calloc(n+1,sizeof(int));
	int *p=calloc(n+1,sizeof(int));
	for(i=0;i<n;i++){
		if(arr[i]==0){
			arr[i]=1;
			ch=path(i,p,0);
			if(ch){
				printf("\nYes,there is a Circuit\nCircuit: ");
				int i=0;
				for(;p[i]!=p[ch];i++);
				printf("%d -",p[i++]);
				for(;i<=ch;i++)
					printf(" %d -",p[i]);
				
				return 1;
			}
		}
	}
	printf("\nNo,there is no circuit\n");
	return 0;
}
int main(){
	int i,j;
	printf("Enter no of vetices: ");
	scanf("%d",&n);
	adj=calloc(n,sizeof(int*));
	for(i=0;i<n;i++)
		adj[i]=calloc(n,sizeof(int));
	while(1){
		printf("Enter edges(enter -1 -1 to stop): ");
		scanf("%d%d",&i,&j);
		if(i==-1) break;
		adj[i][j]=1;	
	}
	cir();
}
