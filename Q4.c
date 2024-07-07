#include <stdio.h>


struct Circle
{
	float r;
};


const float PI = 3.141592;


float area(struct Circle circle)
{
	return PI*circle.r*circle.r;
}


float circum(struct Circle circle)
{
	return 2*PI*circle.r;
}


int main(void)
{
	struct Circle c1, c2;
	printf(" Enter radius of first circle: ");
	scanf("%f", &c1.r);
	printf("Enter radius of second circle: ");
	scanf("%f", &c2.r);
	
	printf("\n\n     Area of first circle = %.3f sq units\n", area(c1));
	printf("Perimeter of first circle = %.3f sq units", circum(c1));
	printf("\n\n     Area of second circle = %.3f sq units\n", area(c2));
	printf("Perimeter of second circle = %.3f sq units\n", circum(c2));
	
	return 0;
}