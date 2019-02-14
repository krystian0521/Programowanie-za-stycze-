#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>

using namespace std;


//--------------------zadanie 1.1---------------------------

struct osoba {
	int age;
	int height;
	int semestr;
}student1,student2;


osoba *Create(int wiek, int wzrost, int semestr) {
	
	osoba* student1 = (osoba*) malloc(sizeof(osoba));
	student1->age = wiek;
	student1->height = wzrost;
	student1->semestr = semestr;

}

void PrintStudent(osoba *student1){
	cout << "Wiek-> " << student1->age << endl;
	cout << "Wzrost-> " << student1->height << endl;
	cout << "Semestr-> " << student1->semestr << endl;
	cout << "\n" << endl;
}

bool AreEqual(osoba *student1, osoba *student2) {
	if(student1->age == student1->age) {
		
		if(student1->height == student1->height) {
			
			if(student1->semestr == student1->semestr) {			
				return true;				
			} else {				
				return false;				
			}			
		} else {			
			return false;			
		}		
	} else {		
		return false;		
	}
}





//------------------zadanie 2-------------------------

struct Node {
    int Value;
    Node * Next;
};
 
Node* Create(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->Value = value;
    return node;
}

Node* GetTail(Node* root) {
    while (root->Value != NULL){
    	*root = *root->Next;
	}
	return root;
}

void Add(Node* root, int value) {
	*root = *GetTail(root);
	root->Next = (Node*) malloc(sizeof(Node));
	root->Next->Value = value;
}

void PrintList(Node* root) {
	Node* ostatni = GetTail(root);
	if(root != ostatni) {
		cout<<root->Value<<' - ';
		*root = *root->Next;
	}
}

void RemoveNode(Node* root, int value) {
	Node* bufor;
	Node* next;
	while(root->Value != value){
		if (root->Value != NULL) {
			*next = *root->Next;
		} else {
			break;
		}
	}
	*bufor = *next->Next;
	free(&next);
	GetTail(root)->Next = bufor;	
}

void FreeList(Node* root) {
	while(root->Next != NULL) {
		free(GetTail(root));
	}
	free(&root);
}

int Count(Node* root){
	int licznik = 0;
	while (root->Value != NULL){
		licznik++;
    	*root = *root->Next;
	}
	return licznik;
}



int main() {



int wiek;
int wzrost;
int semestr;
osoba *tab;
tab = (osoba *)malloc(3 * sizeof(osoba));
for (int i = 0; i < 3; i++) {
	
    cout<<"student "<<i+1<< ": "<<endl;
    cout<<"jego wiek: ";
    cin>>wiek;
    cout<<"jego wzrost: ";
    cin>>wzrost;
    cout<<"semestr: ";
    cin>>semestr;
    
    tab[i] = *Create(wiek, wzrost, semestr);
    cout<<endl;
	}
	
for (int i = 0; i < 3; i++) {
    cout<<"Sudent "<<i+1<<":"<<endl;
    PrintStudent(&tab[i]);
    cout<<endl;
	}
free(&tab); 


    //---------zadanie 3------------------
    
    int liczba;
    fstream plik;
 
    plik.open("numbers.txt", std::ios::out );
    if(plik.good() == true)
    {
    	do {
    		cout<<"liczba: ";
    		cin>>liczba;
    		
    		plik << liczba << endl;
		} while (liczba != 0 );
    	
        plik.close();
    }
    
    string linia;
   
    plik.open("numbers.txt", ios::in);
    if(plik.good() == true)
    {
    	while(!plik.eof())
        {
            getline(plik, linia);
            cout << linia << endl;
        }
    	
        plik.close();
    }
    
    Node * root2 = Create(2);
    PrintList(root2);
    


	//---------Polecenia i funkcje z zadania 2------------------

  	Node * root = Create(2);
    PrintList(root);
    
    Add(root, 4);
    Add(root, 8);
    Add(root, 16);
    PrintList(root);
    
    Add(root, 20);
    PrintList(root);
    
    printf("Ostatni wezel ma wartosc %d", GetTail(root)->Value);
    
    Add(root, 16);
    PrintList(root);
    printf("%d", Count(root));
    
    RemoveNode(root, 8);
    PrintList(root);
    RemoveNode(root, 10);
    PrintList(root);
    RemoveNode(root, 16);
    PrintList(root);
    
    printf("%d", Count(root));
    FreeList(root);
    PrintList(root);
    free(&tab);
 
    
    return(0);
	
	
}
