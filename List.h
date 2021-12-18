typedef int ElementType;

#ifndef _List_H
#define _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

/*1*/ List CreateContactBook(List L);
/*2*/ void Insert(char FirstName[], char LastName[], char Number[], int age, char HouseNo[], List L);
/*3*/ Position Find(char FirstName[], char LastName[], List L);
/*4*/ void EditContact(char FirstName[], char LastName[], List L);
/*5*/ void Delete(char FirstName[], char LastName[], List L);
/*6*/ void SortContactBook(List L);
/*7*/ void DisplayContacts(const List L);

void PrintContact(Position Contact);
Position FindPrevious(char FirstName[], char LastName[], List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
void DeleteContactBook(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
ElementType ASCII(char A[]);

#endif /* _List_H */
/* END */
