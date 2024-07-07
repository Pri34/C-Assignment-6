#include <stdio.h>


struct Employee
{
	unsigned short int id;
	char name[30];
	char pos[20];
	unsigned short int age;
	float pay;
};


void print(const struct Employee employees[], int size)
{
	printf("\n+-------+--------------------------------+----------------------+-------+-------------+\n");
	printf("| %-5s | %-30s | %-20s | %-5s | %-11s |\n", "EmpID", "Name", "Designation", "Age", "Salary");
	printf("+-------+--------------------------------+----------------------+-------+-------------+\n");
	int i;
	for (i = 0; i < size; i++)
	{
		printf("| %5d | %-30s | %-20s | %5d | %11.2f |\n", employees[i].id, employees[i].name, employees[i].pos, employees[i].age, employees[i].pay);
	}
	printf("+-------+--------------------------------+----------------------+-------+-------------+\n");
}


int main(void)
{
	// Given in question
	int n = 5;
	
	// Input employees
	struct Employee e[n];
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nEMPLOYEE %d:-\n", i+1);
		
		printf("Enter employee id: ");
		scanf("%d", &e[i].id);
		
		printf("Enter name: ");
		fflush(stdin);
		gets(e[i].name);
		
		printf("Enter age: ");
		scanf("%d", &e[i].age);
		
		printf("Enter designation: ");
		fflush(stdin);
		gets(e[i].pos);
		
		printf("Enter salary (in Rs): ");
		scanf("%f", &e[i].pay);
	}
	
	// Calling output function
	print(e, n);
	
	return 0;
}