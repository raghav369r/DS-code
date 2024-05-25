#include<stdio.h>
char* address(){
	static char name[20]="Raghav reddy";
	return name;
}
int main(){
	char *ptr=address();
	puts(ptr);
}
