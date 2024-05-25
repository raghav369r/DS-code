#include<stdio.h>
struct test{
	int x;
	int y;
};
void swap(struct test *b){
	int c=b->x;
	b->x=b->y;
	b->y=c;
	printf("in function: ");
	printf("%d %d",b->x,b->y);
}
int main(){
	struct test a1={1,2},*p1;
	p1=&a1;
	p1->x=10;
	p1->y=20;
	swap(p1);
	printf("\nin main: ");
	printf("%d %d",a1.x,a1.y);
}
