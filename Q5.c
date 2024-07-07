#include <stdio.h>
#include <string.h>


struct Student
{
	char name[30];
	char dept[20];
	int yearOfStudy;
	float cgpa;	
};


void sort_students(struct Student students[], int size)
{
	// Bubble Sorts an array of students by name
	int i, j;
	for (i = 0; i < size-1; i++)
	{
		for (j = 0; j < size-1-i; j++)
		{
			if (strcmp(students[j].name, students[j + 1].name) > 0)
			{
				struct Student temp = students[j];
				students[j] = students[j+1];
				students[j+1] = temp;
			}
		}
	}
}


void print(struct Student students[], int size)
{
	// Prints array of structs in a tabular form
	printf("\n+--------------------------------+----------------------+------+------+\n");
	printf("| %-30s | %-20s | %-4s | %-4s |\n", "Name", "Departent", "Year", "CGPA");
	printf("+--------------------------------+----------------------+------+------+\n");
	int i;
	for (i = 0; i < size; i++)
	{
		printf("| %-30s | %-20s | %4d | %4.2f |\n", students[i].name, students[i].dept, students[i].yearOfStudy, students[i].cgpa);
	}
	printf("+--------------------------------+----------------------+------+------+\n");
}


int main(void)
{
	// Input
	int n;
	printf("Enter number of students: ");
	scanf("%d", &n);
	fflush(stdin);
	
	struct Student s[n];
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nSTUDENT %d:-\n", i+1);
		printf("Enter name: ");
		gets(s[i].name);
		fflush(stdin);
		printf("Enter department: ");
		gets(s[i].dept);
		fflush(stdin);
		printf("Enter year: ");
		scanf("%d", &s[i].yearOfStudy);
		fflush(stdin);
		printf("Enter CGPA: ");
		scanf("%f", &s[i].cgpa);
		fflush(stdin);
	}
	
	// Calling sort function
	sort_students(s, n);
	
	// Calling output function
	print(s, n);
	
	return 0;
}