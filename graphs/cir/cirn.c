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
int path(int i,int *p,int l,int *ch){
	p[l]=i;
	//printf(" l= %d\n",l);
	//for(int ok=0;ok<=l;ok++) printf("%d\n",p[ok]);
	int k=adja(i);
	if(k==0 || *ch==1) return 0;
	else{
		for(int m=0;m<l;m++){
			if(p[m]==i){
				*ch=1;
				return 1;
			}
		}
		for(int o=1;o<=k;o++){
			int kl=aele(i,o);
			path(kl,p,l+1,ch);
		}
	}
}
int cir(){
	int i,j,ch=0;
	int *arr=calloc(n+1,sizeof(int));
	int *p=calloc(n+1,sizeof(int));
	for(i=0;i<n;i++){
		if(arr[i]==0){
			arr[i]=1;
			//int p[4+1]={-1,-1,-1,-1,-1};	
			path(i,p,0,&ch);
			if(ch==1){
				printf("\nYes,there is a Circuit\n");
				//for(int i=0;i<n;i++) printf("%d - ",p[i]);
				return 1;
			}
			else{
				printf("\nNo,there is no circuit\n");
				return 0;
			}
		}
	}
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
	//printf("circuit: %d",cir());
	//if(cir()) printf("Yes,there is a circuit");
	//else printf("No,there is no circuit!!");
}
