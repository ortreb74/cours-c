#include "charlist.h"
#include <stdio.h>

void TestCharList_nil() {
	printf ("TestCharList_nil\n");
	if (CharList_nil() == NULL) {
		printf ("OK\n");
	}
	else {
		printf ("KO\n");
	}
}

void TestCharList_cons() {
	printf("TestCharList_cons\n");
	CharList_cons('Z',NULL);
}


void Test2() {
	printf("TestCharList_cons et CharList_head\n");
	printf ("%c",CharList_head(CharList_cons('Z',NULL)));
	printf ("\n");
}

void test3() {
	CharList* list = CharList_cons('E',NULL);
	
	list = CharList_cons('B',list);

	list = CharList_cons('A',list);

	if (CharList_has(list,'E')) {
		printf("la liste contient un E\n"); 
	} else {
		printf("la liste ne contient pas un E\n"); 	
	}
	
}

CharList* initList() {
	CharList* list = CharList_cons('d',NULL);
	list = CharList_insert(list,'o');
	list = CharList_insert(list,'n');
	list = CharList_insert(list,'a');
	list = CharList_insert(list,'t');
	list = CharList_insert(list,'i');
	list = CharList_insert(list,'e');
	list = CharList_insert(list,'n');
	return list ;
}

void test4() {
	printf("après implémentation de CharList_insert\n");

	CharList * list = initList();
	printf ("La liste contient : ");
	displayList(list);

	if (CharList_has(list,'p')) {
		printf("la liste contient un p\n"); 
	} else {
		printf("la liste ne contient pas un p\n"); 	
	}

	if (CharList_has(list,'i')) {
		printf("la liste contient un i\n"); 
	} else {
		printf("la liste ne contient pas un i\n"); 	
	}	
}

void test5() {
	printf("Apres implementation de CharList_remove\n");
	CharList * list = initList();
	list = list = CharList_remove(list,'e');
	printf ("La liste contient : ");
	displayList(list);
}

int main(int argc, char const *argv[])
{
//	TestCharList_nil();
//	Test2();
	//test3();
     //test4();
    test5();
	//tester les fonctions implémentées
	return 0;
}




// CharList * CharList_nil ()
// CharList * CharList_cons (char head, CharList *tail) {
// CharList_head (CharList *self)
// CharList * CharList_tail (CharList *self)
// void CharList_delete (CharList *self)
