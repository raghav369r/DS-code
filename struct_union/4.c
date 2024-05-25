#include<stdio.h>
struct date{
	int dd;
	char month[5];
	int yy;
};
struct student{
	int id;
	char name[20];
	struct date dob;
};
typedef struct student stu_info;
int main(){
	//struct student s1;
	stu_info s1;
	printf("Enter student details: id name dd mm yyyy\n");
	scanf("%d%s%d%s%d",&s1.id,s1.name,&s1.dob.dd,s1.dob.month,&s1.dob.yy);
	printf("Entered details: \nid= %d\nname= %s\ndob= %d %s %d",s1.id,s1.name,s1.dob.dd,s1.dob.month,s1.dob.yy);
}
