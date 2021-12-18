#include <stdio.h>
#include "List.h"
#include "List.c"
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
	List L;
	Position P;

	L = CreateContactBook(NULL);
	P = Header(L);

	int select;
	while (1)
	{
		printf("----------Menu----------\n\n");
		printf("1.  Create New Contact Book.\n");
		printf("2.  Insert New Contact.\n");
		printf("3.  Find Any Contact.\n");
		printf("4.  Edit Any Contact\n");
		printf("5.  Delete Any Contact\n");
		printf("6.  Sort Contact Book\n");
		printf("7.  Display Contact Book\n");
		printf("8.  Load Test\n");
		printf("9.  Exit.\n");
		printf("\n\tSelect any option: ");
		scanf_s("%d", &select);
		getchar();

		if (select == 1)
		{
			L = CreateContactBook(NULL);
			printf("\n\t\tNew Contact Book Created. Previous Contacts Deleted\n\n");
		}

		else if (select == 2)
		{
			char FirstName[15];
			char LastName[15];
			char Number[15];
			int age;
			char HouseNo[15];

			printf("\n\t\tEnter First Name:\t");
			gets_s(FirstName, 15);

			/*if first character of first or last name is lower case
			then make it upper case*/
			if ((FirstName[0] >= 'a') && (FirstName[0] <= 'z'))
			{
				FirstName[0] = FirstName[0] - 32;
			}
			printf("\t\tEnter Last Name:\t");
			gets_s(LastName, 15);
			if ((LastName[0] >= 'a') && (LastName[0] <= 'z'))
			{
				LastName[0] = LastName[0] - 32;
			}
			printf("\t\tEnter Phone Number:\t");
			gets_s(Number, 15);
			printf("\t\tEnter House Number:\t");
			gets_s(HouseNo, 15);
			printf("\t\tEnter age of Person:\t");
			scanf_s("%d", &(age));

			Insert(FirstName, LastName, Number, age, HouseNo, L);
		}

		else if (select == 3)
		{
			char FirstName[15];
			char LastName[15];
			printf("\n\t\tEnter First Name of Contact: ");
			gets_s(FirstName, 15);
			printf("\t\tEnter Last Name of Contact: ");
			gets_s(LastName, 15);
			if ((FirstName[0] >= 'a') && (FirstName[0] <= 'z'))
			{
				FirstName[0] = FirstName[0] - 32;
			}
			if ((LastName[0] >= 'a') && (LastName[0] <= 'z'))
			{
				LastName[0] = LastName[0] - 32;
			}

			Position Contact;
			Contact = Find(FirstName, LastName, L);

			/*PrintContact function will print all 
			the data of that contact*/

			PrintContact(Contact);
		}

		else if (select == 4)
		{
			char FirstName[15];
			printf("\n\t\tEnter First Name of Contact you want to edit:\t");
			gets_s(FirstName, 15);
			if ((FirstName[0] >= 'a') && (FirstName[0] <= 'z'))
			{
				FirstName[0] = FirstName[0] - 32;
			}
			char LastName[15];
			printf("\t\tEnter Last Name of Contact you want to edit:\t");
			gets_s(LastName, 15);
			if ((LastName[0] >= 'a') && (LastName[0] <= 'z'))
			{
				LastName[0] = LastName[0] - 32;
			}

			EditContact(FirstName, LastName, L);
		}

		else if (select == 5)
		{
			char FirstName[15];
			printf("\n\n\t\tEnter First Name of Contact you want to delete:\t");
			gets_s(FirstName, 15);
			if ((FirstName[0] >= 'a') && (FirstName[0] <= 'z'))
			{
				FirstName[0] = FirstName[0] - 32;
			}
			char LastName[15];
			printf("\t\tEnter Last Name of Contact you want to delete:\t");
			gets_s(LastName, 15);
			if ((LastName[0] >= 'a') && (LastName[0] <= 'z'))
			{
				LastName[0] = LastName[0] - 32;
			}

			Delete(FirstName, LastName, L);
		}

		else if (select == 6)
		{
			SortContactBook(L);
		}

		else if (select == 7)
		{
			DisplayContacts(L);
		}

		else if (select == 8)
		{

			FILE *fptr;

			char FirstName[15];
			char LastName[15];
			char Num[15];
			int age;
			char HouseNo[15];

			fopen_s(&fptr, "D:\\PROJECTS\\Contact Book\\Contacts.txt", "r");

			if (fptr == NULL)
			{
				perror("error ");
				exit(1);
			}
			else
			{
				while (!feof(fptr))
				{
					fscanf(fptr, "%s %s %s %d %s", FirstName, LastName, Num, &age, HouseNo);
					if ((FirstName[0] >= 'a') && (FirstName[0] <= 'z'))
					{
						FirstName[0] = FirstName[0] - 32;
					}
					if ((LastName[0] >= 'a') && (LastName[0] <= 'z'))
					{
						LastName[0] = LastName[0] - 32;
					}
					Insert(FirstName, LastName, Num, age, HouseNo, L);
				}
			}
			fclose(fptr);
			printf("\n\t\t\tContacts Added!\n\n");
		}

		else if (select == 9)
		{
			break;
		}

		else
		{
			printf("\n\tInvalid Chioce! Select Again.\n\n");
		}
	}

	getchar();

	return 0;
}
