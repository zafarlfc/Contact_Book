#include "List.h"
#include <stdlib.h>
#include "fatal.h"
#include <string.h>

/*Every Contact will have following five attributes*/
struct Node
{
	char FirstName[15];
	char LastName[15];
	char Number[15];
	int Age;
	char HouseNo[15];
	Position Next;
};

/*CreateContactBook Function will create a new contact book and 
will delete all contents of the previous contact book*/

List CreateContactBook(List L)
{
	if (L != NULL)
		DeleteContactBook(L);
	L = malloc(sizeof(struct Node));
	if (L == NULL)
		FatalError("Out of memory!");
	L->Next = NULL;
	return L;
}

/*Insert Function will take all five attributes of the contact as input
and will create a new contact with that attributes and insert that contact 
at the start of the linked list. if it finds a contact in the linked list 
with the same first and last name then it will not add that contact in the 
linked list.*/
void Insert(char FirstName[], char LastName[], char Number[], int age, char HouseNo[], List L)
{
	Position Contact;
	Position FindContact;

	FindContact = Find(FirstName, LastName, L);
	if (FindContact != NULL)
	{
		printf("\n\tContact already exists. Contact name Must be unique.\n");
		return;
	}

	Contact = malloc(sizeof(struct Node));
	if (Contact == NULL)
		FatalError("Out of space!!!");

	strcpy_s(Contact->FirstName, 15, FirstName);
	strcpy_s(Contact->LastName, 15, LastName);
	strcpy_s(Contact->Number, 15, Number);
	Contact->Age = age;
	strcpy_s(Contact->HouseNo, 15, HouseNo);

	Contact->Next = L->Next;
	L->Next = Contact;

	printf("\n\t\t\tContact Created!\n\n");
}

/*Find function will take first and last name of a contact as input
and will return the position of that contact, if it finds a contact 
with the same first and last name in the linked list*/

Position
Find(char FirstName[], char LastName[], List L)
{
	Position Contact;

	Contact = Header(L);
	while (Contact != NULL &&
		   (strcmp(Contact->FirstName, FirstName) != 0 || strcmp(Contact->LastName, LastName) != 0))
	/*strcmp function is used to compare two strings*/
	{
		Contact = Contact->Next;
	}
	return Contact;
}

/*EditContact Function will take first and last name of a contact as input
and it will find that contact in the linked list using Find Function
, if that contact is found than it will update all attributes of that contact
by taking input from the user*/

void EditContact(char FirstName[], char LastName[], List L)
{
	char NewFirstName[15];
	char NewLastName[15];
	char NewNum[15];
	int Newage;
	char NewHouse[15];

	Position Contact;
	Contact = Find(FirstName, LastName, L);
	if (Contact == NULL)
	{
		printf("\n\t\t\tContact Not Found!\n\n");
	}

	else
	{
		printf("\n\t\t\tEnter New First Name:\t\t");
		gets_s(NewFirstName, 15);
		if ((NewFirstName[0] >= 'a') && (NewFirstName[0] <= 'z'))
		{
			NewFirstName[0] = NewFirstName[0] - 32;
		}
		strcpy_s(Contact->FirstName, 15, NewFirstName);
		printf("\t\t\tEnter New Last Name:\t\t");
		gets_s(NewLastName, 15);
		if ((NewLastName[0] >= 'a') && (NewLastName[0] <= 'z'))
		{
			NewLastName[0] = NewLastName[0] - 32;
		}
		strcpy_s(Contact->LastName, 15, NewLastName);
		printf("\t\t\tEnter New Phone Number:\t\t");
		gets_s(NewNum, 15);
		strcpy_s(Contact->Number, 15, NewNum);
		printf("\t\t\tEnter New House Number\t\t");
		gets_s(NewHouse, 15);
		strcpy_s(Contact->HouseNo, 15, NewHouse);
		printf("\t\t\tEnter New age of Person:\t");
		scanf_s("%d", &(Newage));
		Contact->Age = Newage;
		printf("\n\t\t\t\tContact Edited!\n\n");
	}
}

/*Delete function will take first and last name of contact as input 
and find the previous contact and will delete the contact with that 
first and last name*/

void Delete(char FirstName[], char LastName[], List L)
{
	Position Contact, TmpContact;

	Contact = FindPrevious(FirstName, LastName, L);

	if (!IsLast(Contact, L))
	{
		TmpContact = Contact->Next;
		Contact->Next = TmpContact->Next; /* Bypass deleted cell */
		free(TmpContact);
		printf("\n\n\t\t\tContact Deleted!\n\n");
	}
	else
	{
		printf("\n\n\t\t\tContact Not Found!\n\n");
	}
}

/*This function will simply print the data of all contacts
in the linked list*/

void DisplayContacts(const List L)
{
	Position Contact = Header(L);
	int i = 1;

	if (IsEmpty(L))
		printf("\n\t\t\tContact Book Empty!\n\n");
	else
	{
		printf("\n\n\t\t\t\t\t----------CONTACT BOOK----------");
		printf("\n\n No.\t| FirstName\t\t| LastName\t\t| Contact No\t\t| Age \t| House No.   \t|");
		printf("\n_________________________________________________________________________________________________________");
		do
		{
			Contact = Advance(Contact);
			printf("\n\n %d\t| %s   \t\t| %s  \t\t| %s \t\t| %d \t| %s\t\t|\n", i,
				   Contact->FirstName, Contact->LastName, Contact->Number, Contact->Age, Contact->HouseNo);
			i++;
		} while (!IsLast(Contact, L));
		printf("\n");
	}
}

/*SortContactBook will use bubble sort technique to sort the contacts 
in the linked list alphabatically. ASCII function will return the ascii 
value of first character of first name*/

void SortContactBook(List L)
{
	Position Contact;
	Position NextContact;
	Position TmpContact;
	TmpContact = malloc(sizeof(struct Node));
	if (TmpContact == NULL)
		FatalError("Out of space!!!");

	for (Contact = L->Next; Contact != NULL; Contact = Advance(Contact))
	{
		for (NextContact = Contact->Next; NextContact != NULL; NextContact = Advance(NextContact))
		{
			if (ASCII(Contact->FirstName) > ASCII(NextContact->FirstName))
			{
				strcpy_s(TmpContact->FirstName, 15, Contact->FirstName);
				strcpy_s(TmpContact->LastName, 15, Contact->LastName);
				strcpy_s(TmpContact->Number, 15, Contact->Number);
				TmpContact->Age = Contact->Age;
				strcpy_s(TmpContact->HouseNo, 15, Contact->HouseNo);

				strcpy_s(Contact->FirstName, 15, NextContact->FirstName);
				strcpy_s(Contact->LastName, 15, NextContact->LastName);
				strcpy_s(Contact->Number, 15, NextContact->Number);
				Contact->Age = NextContact->Age;
				strcpy_s(Contact->HouseNo, 15, NextContact->HouseNo);

				strcpy_s(NextContact->FirstName, 15, TmpContact->FirstName);
				strcpy_s(NextContact->LastName, 15, TmpContact->LastName);
				strcpy_s(NextContact->Number, 15, TmpContact->Number);
				NextContact->Age = TmpContact->Age;
				strcpy_s(NextContact->HouseNo, 15, TmpContact->HouseNo);
			}
		}
	}
	printf("\n\n\t\tContact Book Sorted\n\n");
	free(TmpContact);
}

void DeleteContactBook(List L)
{
	Position Contact, TmpContact;

	Contact = L->Next; /* Header assumed */
	L->Next = NULL;
	while (Contact != NULL)
	{
		TmpContact = Contact->Next;
		free(Contact);
		Contact = TmpContact;
	}
}
/* END */

/*ASCII function will return the ascii value of first character
of a string*/

ElementType ASCII(char A[])
{
	int ascii;

	ascii = A[0];

	return ascii;
}

/*This function will print all the attributes of a contact*/

void PrintContact(Position Contact)
{
	if (Contact == NULL)
	{
		printf("\n\n\t\tContact Not Found!\n\n");
	}
	else
	{
		printf("\n\t\t\tThe Details of this Contact are:");
		printf("\n\n\t| FirstName  \t\t| LastName  \t\t| Contact No \t\t| Age \t| HouseNo");
		printf("\n\t_____________________________________________________________________________________________");
		printf("\n\n\t| %s    \t\t| %s   \t\t| %s \t\t| %d \t| %s \t\n\n",
			   Contact->FirstName, Contact->LastName, Contact->Number, Contact->Age, Contact->HouseNo);
	}
}

Position
FindPrevious(char FirstName[], char LastName[], List L)
{
	Position Contact;

	Contact = L;
	while (Contact->Next != NULL &&
		   (strcmp(Contact->Next->FirstName, FirstName) != 0 || strcmp(Contact->Next->LastName, LastName) != 0))
	{
		Contact = Contact->Next;
	}
	return Contact;
}

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

Position
Header(List L)
{
	return L;
}

Position
First(List L)
{
	return L->Next;
}

Position
Advance(Position P)
{
	return P->Next;
}

ElementType
Retrieve(Position P)
{
	return P->Age;
}
