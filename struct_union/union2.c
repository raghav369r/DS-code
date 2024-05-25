#include<stdio.h>
#include<string.h>
union def{
	char str[10];
	int g;
};
int main(){
	union def n;
	strcpy(n.str,"aa");
	printf("%s %d",n.str,n.g);
}
