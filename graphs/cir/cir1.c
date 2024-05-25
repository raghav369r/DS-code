#include<stdio.h>
#include<stdlib.h>
int n=4;
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
	printf(" l= %d\n",l);
	for(int ok=0;ok<=l;ok++) printf("%d\n",p[ok]);
	int k=adja(i);
	if(k==0) return 0;
	else{
		for(int m=0;m<l;m++)
			if(p[m]==i) return 1;
		for(int o=1;o<=k;o++){
			int kl=aele(i,o);
			path(kl,p,l+1);
		}
	}
}
int cir(){
	int i,j;
	int arr[4]={0};
	int *p=calloc(n+1,sizeof(int));
	for(i=0;i<n;i++){
		if(arr[i]==0){
			arr[i]=1;
			//int p[4+1]={-1,-1,-1,-1,-1};
			int l=path(i,p,0);
			if(l==1){
				printf("Circuit is: ");
				for(int i=0;i<n;i++) printf("%d - ",p[i]);
				return 1;
			}
		}
	}
	for(int i=0;i<n+1;i++) printf("%d - ",p[i]);
	return 0;
}
int main(){
	int i,j;
	adj=calloc(n,sizeof(int*));
	for(i=0;i<n;i++)
		adj[i]=calloc(n,sizeof(int));
	while(1){
		printf("Enter edges(enter -1 -1 to stop): ");
		scanf("%d%d",&i,&j);
		if(i==-1) break;
		adj[i][j]=1;	
	}
	//printf("circuit: %d",cir());
	if(cir()) printf("Yes,there is a circuit");
	else printf("No,there is no circuit!!");
}
