#include <stdio.h>
#include <stdbool.h>
#include <math.h>


struct Date
{
	int day;
	int month;
	int year;
};


bool is_leap(int yr)
{
	if (yr % 100 == 0)
	{
		if (yr % 400 == 0)
		{
			return true;
		}
	}
	else if (yr % 4 == 0)
	{
		return true;
	}
	return false;
}


bool check_date(struct Date d)
{
	switch (d.month)
	{
		case 2:
			if (is_leap(d.year))
			{
				if (d.day < 1 || 29 < d.day) return false;
			}
			else
			{
				if (d.day < 1 || 28 < d.day) return false;
			}
			break;
			
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (d.day < 1 || 31 < d.day) return false;
			break;
			
		case 4:
		case 6:
		case 9:
		case 11:
			if (d.day < 1 || 30 < d.day) return false;
			break;
			
		default:
			return false;
	}
	
	return true;
}


int no_of_days(struct Date d)
{
	int total = 0, i = 0;
	for (i = 0; i < d.year; i++)
		if (is_leap(i)) total += 366;
		else total += 365;
	for (i = 1; i < d.month; i++)
	{
		switch (i)
		{
			case 2:
				if (is_leap(d.year)) total += 29;
				else total += 28;
				break;
				
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				total += 31;
				break;
				
			case 4:
			case 6:
			case 9:
			case 11:
				total += 30;
				break;
		}
	}
	
	total += d.day;
	return total;
}


int subtract_days(struct Date d1, struct Date d2)
{
	// No. of days from 0/0/0000
	int days1 = no_of_days(d1);
	int days2 = no_of_days(d2);
	return (days1 - days2);
}


int main(void)
{
	struct Date d1, d2;
	do
	{
		printf("Enter 1st date (dd/mm/yyyy): ");
		scanf("%d/%d/%d", &d1.day, &d1.month, &d1.year);
	}
	while (check_date(d1) != true);
	do
	{
		printf("Enter 2nd date (dd/mm/yyyy): ");
		scanf("%d/%d/%d", &d2.day, &d2.month, &d2.year);		
	}
	while (check_date(d2) != true);

	printf("\n Difference in days = %d\n", abs(subtract_days(d1, d2)) );
	return 0;
}