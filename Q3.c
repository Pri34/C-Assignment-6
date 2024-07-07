#include <stdio.h>


struct Time
{
	unsigned int hrs;
	unsigned int min;
	unsigned int sec;
};


void correct_time(struct Time *t)
{
	if (t->sec >= 60)
	{
		t->min += t->sec / 60;
		t->sec  = t->sec % 60;
	}
	if (t->min >= 60)
	{
		t->hrs += t->min / 60;
		t->min  = t->min % 60;
	}
}


struct Time add_times(struct Time time1, struct Time time2)
{
	struct Time result;
	result.hrs = time1.hrs + time2.hrs;
	result.min = time1.min + time2.min;
	result.sec = time1.sec + time2.sec;
	correct_time(&result);
	return result;
}


int main(void)
{
	struct Time t1, t2;
	printf(" Enter first time (hh:mm:ss) : ");
	scanf("%d:%d:%d", &t1.hrs, &t1.min, &t1.sec);
	printf("Enter second time (hh:mm:ss) : ");
	scanf("%d:%d:%d", &t2.hrs, &t2.min, &t2.sec);
	
	struct Time sum = add_times(t1, t2);
	printf("\n Sum = %.2d:%.2d:%.2d\n", sum.hrs, sum.min, sum.sec);
	
	return 0;
}