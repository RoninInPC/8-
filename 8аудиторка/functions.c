#include<stdio.h>
#include"functions.h"
#include"rand.h"
ListOfFloat* MakeMainList(){
	ListOfFloat* Ans = (ListOfFloat*)malloc(sizeof(ListOfFloat));
	Ans->next = NULL;
	Ans->before = NULL;
	Ans->Number = MakeRandFloat(0);
	return Ans;
}
void addToRight(ListOfFloat* List, float New) {
	ListOfFloat* NewPartList = (ListOfFloat*)malloc(sizeof(ListOfFloat));
	NewPartList->next = NULL;
	NewPartList->Number = New;
	ListOfFloat* P = List;
	while (P->next != NULL) {
		P = P->next;
	}
	NewPartList->before = P;
	P->next = NewPartList;
	List = P;
}
void addToLeft(ListOfFloat* List, float New) {
	ListOfFloat* NewPartList = (ListOfFloat*)malloc(sizeof(ListOfFloat));
	NewPartList->before = NULL;
	NewPartList->Number = New;
	ListOfFloat* P = List;
	while (P->before != NULL) {
		P = P->before;
	}
	NewPartList->next = P;
	P->before = NewPartList;
	List = P;
}
ListOfFloat* MakeList(int Size) {
	ListOfFloat* Ans = MakeMainList();
	for (int i = 1; i < Size; i++) {
		addToRight(Ans, MakeRandFloat(i));
	}
	return Ans;
}
void outputToRight(ListOfFloat* List) {
	while (1) {
		printf("%f ", List->Number);
		if (List->next == NULL) break;
		List = List->next;
	}
	printf("\n");
}
void outputToLeft(ListOfFloat* List) {
	while (1) {
		if (List->next == NULL) break;
		List = List->next;
	}
	while (1) {
		printf("%f ", List->Number);
		if (List->before == NULL) break;
		List = List->before;
	}
	printf("\n");
}
void addBeforeCurrent(ListOfFloat* List, ListOfFloat* Current,float NewFloat) {
	ListOfFloat* P = List;
	while (1) {
		if (P->next == Current) break;
		P = P->next;
	}
	ListOfFloat* New = (ListOfFloat*)malloc(sizeof(ListOfFloat));
	New->Number = NewFloat;
	Current->before = New;
	New->next = Current;
	New->before = P;
	P->next = New;
	List = P;
}
ListOfFloat* findByValue(ListOfFloat* List, float Number) {
	while (1) {
		if (List->Number == Number) {
			return List;
		}
		List = List->next;
	}
	return NULL;
}
void addBeforeValue(ListOfFloat* List, float Number, float FloatNew) {
	while (1) {
		if (List->Number == Number) {
			break;
		}
		List = List->next;
	}
	ListOfFloat* New = (ListOfFloat*)malloc(sizeof(ListOfFloat));
	New->Number = FloatNew;
	New->next = List->next;
	New->before = List;
	List->next = New;
}
void deleteByValue(ListOfFloat* List, float Number) {
	while (1) {
		if (List->Number == Number) {
			ListOfFloat* Next = List->next;
			ListOfFloat* Before = List->before;
			ListOfFloat* tmp = List;
			free(tmp);
			if (Before != NULL) {
				List = Before;
			}
			if (List != NULL) {
				List->next = Next;
				List = List->next;
				List->before = Before;
			}
			break;
		}
		List = List->next;
	}
}
void deleteByPointer(ListOfFloat* List, ListOfFloat* Pointer) {
	List = Pointer;
	ListOfFloat* Next = List->next;
	ListOfFloat* Before = List->before;
	ListOfFloat* tmp = List;
	free(tmp);
	if (Before != NULL) {
		List = Before;
	}
	if (List != NULL) {
		List->next = Next;
		List = List->next;
		List->before = Before;
	}
}
void swapTwoElement(ListOfFloat* List, ListOfFloat* Pointer1, ListOfFloat* Pointer2) {
	List = Pointer1;
	int Number1 = List->Number;
	List = Pointer2;
	int Number2 = List->Number;
	List = Pointer1;
	List->Number = Number1;
	List = Pointer2;
	List->Number = Number2;
}
void splice(ListOfFloat* List, ListOfFloat* Left, ListOfFloat* Right, ListOfFloat* List2, ListOfFloat* Position) {
	List = Left;
	List2 = Position;
	ListOfFloat* Next = List2->next;
	while (1) {
		ListOfFloat* Copy = List;
		Copy->before = List2;
		List2->next = Copy;
		if (List == Right)break;
		List = List->next;
		List2 = List2->next;
	}
	List2->next = Next;
}