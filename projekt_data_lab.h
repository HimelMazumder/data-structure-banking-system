#pragma once
#include<stdio.h>

struct accounts
{
	int acntNumb, age, NID;
	float depoAmnt;
	char name[20], dateBirth[20], cDate[20], address[30], phone[10];

	struct accounts *back, *next;
};

typedef struct accounts acc;

acc *head = NULL;
acc *last = NULL;

void fgets_corrected(char str_FC[30], int m)
{
	if (m == 0)
	{
		int i = 0;
		while (str_FC[i] != 10)
		{
			i++;
		}
		str_FC[i] = 0;
	}
	else
	{
		int i = 0;
		while (str_FC[i] != 10)
		{
			i++;
		}
		str_FC[i++] = '|';
		str_FC[i] = 0;
	}
}

void accountInsertion(acc *temp_AI)
{
	while (temp_AI->next != NULL)
	{
		temp_AI = temp_AI->next;
	}

	last = temp_AI;
}

void getDetails(acc *temp_GD)
{
	printf("Enter today's date (mm/dd/yy): ");
	fgets(temp_GD->cDate, 20, stdin);
	fgets_corrected(temp_GD->cDate, 0);

	printf("Enter the account number: ");
	scanf("%d", &temp_GD->acntNumb);
	getchar();

	printf("Enter the name: ");
	fgets(temp_GD->name, 20, stdin);
	fgets_corrected(temp_GD->name, 0);

	printf("Enter the date of birth (mm/dd/yy): ");
	fgets(temp_GD->dateBirth, 20, stdin);
	fgets_corrected(temp_GD->dateBirth, 0);

	printf("Enter age: ");
	scanf("%d", &temp_GD->age);
	getchar();

	printf("Enter the address: ");
	fgets(temp_GD->address, 30, stdin);
	fgets_corrected(temp_GD->address, 1);

	printf("Enter NID number: ");
	scanf("%d", &temp_GD->NID);
	getchar();

	printf("Enter phone number: ");
	fgets(temp_GD->phone, 30, stdin);
	fgets_corrected(temp_GD->phone, 0);

	printf("Enter the amount to deposite: BDT ");
	scanf("%f", &temp_GD->depoAmnt);
	getchar();
}

void addInFile(acc *temp_AIF)
{
	FILE *pt;
	pt = fopen("record.txt", "a");

	fprintf(pt, "%d ", temp_AIF->acntNumb);
	fputs(temp_AIF->name, pt);
	fprintf(pt, " ");
	fputs(temp_AIF->dateBirth, pt);
	fprintf(pt, " %d ", temp_AIF->age);
	fputs(temp_AIF->address, pt);
	fprintf(pt, " %d ", temp_AIF->NID); 
	fputs(temp_AIF->phone, pt);
	fprintf(pt, " %f ", temp_AIF->depoAmnt);
	fputs(temp_AIF->cDate, pt);
	fprintf(pt, "\n");
	fclose(pt);
}


void createAccount()
{
	acc *temp;

	if (head == NULL)
	{
		head = new acc();
		head->back = NULL;
		head->next = new acc();
		temp = head->next;
		temp->back = head;
		temp->next = NULL;
	}
	else
	{
		temp = head->next;
	}

	accountInsertion(temp);

	last->next = new acc();
	last->next->next = NULL;
	last->next->back = last;

	getDetails(last->next);
	addInFile(last->next);
}



