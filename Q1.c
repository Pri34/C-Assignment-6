#include <stdio.h>

struct book
{
	char title[50];
	char author[50];
	float price;
};

int main(void)
{
	struct book books[3];
	
	// Inputting array of 3 books	
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("BOOK %d:-\n", i+1);
		printf("Enter book\'s title: ");
		fflush(stdin);
		gets(books[i].title);
		printf("Enter author\'s name: ");
		fflush(stdin);
		gets(books[i].author);
		printf("Enter book\'s price: ");
		scanf("%f", &books[i].price);
		printf("\n");
	}
	
	// Find max & min prices
	int max_index = 0, min_index = 0;
	float max_price = books[0].price, min_price = books[0].price;
	for (i = 0; i < 3; i++)
	{
		if (books[i].price > max_price)
		{
			max_index = i;
			max_price = books[i].price;
		}
		if (books[i].price < min_price)
		{
			min_index = i;
			min_price = books[i].price;
		}
	}
	
	// Display info for costliest and cheapest book
	struct book costly = books[max_index];
	struct book cheap = books[min_index];
	printf("Costliest book is %s, written by %s, and costs $%.2f.\n", costly.title, costly.author, costly.price);
	printf("Cheapest book is %s, written by %s, and costs $%.2f.\n", cheap.title, cheap.author, cheap.price);
	return 0;
}