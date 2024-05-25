#include<stdio.h>
typedef struct{
	int id;
	char name[20];
	char branch[3];
}s1;//s1,s2;
//typedef struct student std;
int main(){
	//struct student s1={1098,"raghav","CSE"};
	//struct student s2={1099,"raghav","CSE"};
	//std s1={1098,"raghav","CSE"};
	s1 s1={1098,"raghav","CSE"};
	printf("%d %s %s\n",s1.id,s1.name,s1.branch);
	//printf("%d %s %s",s2.id,s2.name,s2.branch);
}
