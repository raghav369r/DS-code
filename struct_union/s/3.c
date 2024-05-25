#include<stdio.h>
struct test{
	int x;
	char name[20];
	int y;
	struct test *ptr;
};
int main(){
	struct test a2;
	struct test a1={ 98,"kohli",34,&a2 };
	//a1={ 98,"kohli",34,&a2 };
	//a2={99,"DK",37,&a3};
	//a3={100,"ABD",36,NULL};
	//printf("%d %d",a1.x,a1.y);
	printf("%s %d %d %u\n",a1.name,a1.x,a1.y,a1.ptr);
	//printf("%s &d %d %x\n",a2.name,a2.x,a2.y,a2.ptr);
	//printf("%s &d %d %x\n",a3.name,a3.x,a3.y,a3.ptr);

}
