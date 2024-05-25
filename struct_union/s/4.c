#include<stdio.h>
#include<stdlib.h>
int main(){
	struct data {
		int id;
		char name[20];
		int age;
	};
	typedef struct data data;
	int n,i;
	printf("Enter no of students: ");
	scanf("%d",&n);
	struct data *ptr;
	ptr=(struct data*)malloc(n*sizeof(struct data));
	for(i=0;i<n;i++){
		printf("Enter student details: id   name   age\n");
		scanf("%d%s%d",&((ptr+i)->id),((ptr+i)->name),&((ptr+i)->age));
	}
	for(i=0;i<n;i++)
		printf("%d	%s	%d\n",(ptr+i)->id,(ptr+i)->name,(ptr+i)->age);
}
