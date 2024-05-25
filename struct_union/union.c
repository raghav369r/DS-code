#include<stdio.h>
union def{
	int g;
	char h;
};
int main(){
	union def n;
	n.g=365;
	printf("%d %c",n.g,n.h);
	n.h='a';
	printf("%d %c",n.g,n.h);
}
