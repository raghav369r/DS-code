#include<stdio.h>
struct player{
	char idno[7];
	char sname[20];
	int rollno;
	char branch[3];
	struct dob{
		int day;
		int month;
		int year;
	}dob;
	float cgpa;
};
int main(){
	struct player p[3];
	int n,i;
	printf("Enter no of students: ");
	scanf("%d",&n);
	for(i=1;i<n+1;i++){
		printf("Enter details of student %d:\n",i);
		printf("student id no(s191098): ");
		scanf("%s",p[i-1].idno);
		printf("student name: ");
		scanf("%s",p[i-1].sname);
		printf("student roll number :");
		scanf("%d",&p[i-1].rollno);
		printf("student branch(CSE): ");
		scanf("%s",p[i-1].branch);
		printf("student dob(dd mm yyyy):");
		scanf("%d%d%d",&p[i-1].dob.day,&p[i-1].dob.month,&p[i-1].dob.year);
		printf("student cgpa");
		scanf("%f",&p[i-1].cgpa);
	}
	for(i=1;i<n+1;i++){
		printf("Enter details of student %d:\n",i);
		printf("student id no: %s",p[i-1].idno);
		printf("student name: %s",p[i-1].sname);
		printf("student roll number : %d",p[i-1].rollno);
		printf("student branch(CSE): %s",p[i-1].branch);
		printf("student dob(dd mm yyyy): %d %d %d ",p[i-1].dob.day,p[i-1].dob.month,p[i-1].dob.year);
		printf("student cgpa: %.2f",p[i-1].cgpa);
	}
}


