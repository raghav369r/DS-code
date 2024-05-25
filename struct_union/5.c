#include<stdio.h>
struct student{
	int id;
	char name[20];
	int mark1,mark2,mark3;
	float percent;
};//s1 here to create variable of type student
typedef struct student stu_info;
int main(){
	//struct student s1;
	stu_info s1[3];
	int i;
	for(i=0;i<2;i++){
		printf("Enter student details: id name marks1 marks2 marks3\n");
		scanf("%d%s%d%d%d",&s1[i].id,s1[i].name,&s1[i].mark1,&s1[i].mark2,&s1[i].mark3);
	}
	for(i=0;i<3;i++){
		printf("Details of student 
		%d: \nid= %d\nname= %s\nmarks1= %d\nmarks2= %d\nmarks3= %d\n",i+1;s1[i].id,s1[i].name,s1[i].mark1,s1[i].mark2,s1[i].mark3);
	}
}
