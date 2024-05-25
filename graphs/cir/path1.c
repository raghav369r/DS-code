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
void paths(int s,int d,int *che){
	int k=adja(s);
	//printf("s= %d->a= %d",s,k);
	if(*che==1) printf("%d - ",s);
	if(k==0) return;
	else{
		for(int o=1;o<=k;o++){
			int kl=aele(s,o);
			if(kl==d){
				printf("%d ",d);
				*che=1;
				return ;
			}
			paths(kl,d,che);
			printf("%d ",s);
		}
	}
}
int path(int s,int d){
	printf("s= %d\td= %d\n",s,d);
	int *arr=calloc(n,sizeof(int));
	int che=0;
	paths(s,d,&che);
	return che;
}
int main(){
	int i,j,s,d;
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
	while(1){
		printf("Enter sorce vertex and destination vertex to print path: ");
		scanf("%d%d",&s,&d);
		if(s==-1) break;
		if(path(s,d))
			printf("yes there is a path\n");
		else printf("No there is no path\n");
	
	}
}
