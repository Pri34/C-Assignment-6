#include <stdio.h>


struct Student
{
	// Contains marks in each subject of student
	char name[30];
	float cs;
	float eee;
	float env;
	float chem;
	float math;
};


float avg_marks(struct Student student)
{
	return (student.cs + student.eee + student.env + student.chem + student.math) / 5.0;
}


int main(void)
{
	int n = 3;
	
	// Input 3 students
	struct Student students[n];
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nSTUDENT %d:-\n", i+1);
		
		printf("Enter name: ");
		gets(students[i].name);
		
		printf("Enter marks in Programming: ");
		scanf("%f", &students[i].cs);
		
		printf("Enter marks in Electrical: ");
		scanf("%f", &students[i].eee);
		
		printf("Enter marks in Environment: ");
		scanf("%f", &students[i].env);
		
		printf("Enter marks in Chemistry: ");
		scanf("%f", &students[i].chem);
		
		printf("Enter marks in Mathematics: ");
		scanf("%f", &students[i].math);
	
		fflush(stdin);
	}
	
	// Find highest avg marks
	float max_avg = 0;
	int max_avg_ind = 0;
	for (i = 0; i < n; i++)
	{
		float avg = avg_marks(students[i]);
		if (avg > max_avg)
		{
			max_avg = avg;
			max_avg_ind = i;
		}
	}	
	
	// Output
	printf("\n%s (STUDENT %d) has the highest average marks (%.3f)\n", students[max_avg_ind].name, max_avg_ind+1, max_avg);
	
	return 0;
}