// bagli liste yapisi ile graph larda DFS dolanma kodu
// Ahmet Furkan DEMIR

#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

// node sayisi
#define count 6

// komsulari tutan yapi
typedef struct queue{

	int val;
	struct queue *next;

}queue;

// nodelerin hepsini tutan yapi
typedef struct Node{

	struct queue *list[count];

}node;

// ana yapiya erisilen yer
node * root;

// root init
void __init__(){

	root=(node *)malloc(sizeof(node));
}

// dugumleri birbirine bagladigimiz yer
// v den w ye baglanti gerceklesir
void addEdge(int v, int w){

	// ilk komsu eklenir
	if(root->list[v]==NULL){
		root->list[v]=(queue *)malloc(sizeof(queue));
		root->list[v]->val=w;
		root->list[v]->next=NULL;
	}

	// diger komsular eklenir
	else{

		queue *temp=root->list[v];

		while(temp->next!=NULL){
			temp=temp->next;
		}

		temp->next=(queue *)malloc(sizeof(queue));
		temp->next->val=w;
		temp->next->next=NULL;

	}

}

void DFS_recursiv(int v, bool visited[]){
	
	// dugum yazdirilir ve gidildi olarak isaretlenir
    visited[v] = true;
    printf("%d ", v);
 
  	// dugumun tum komsulari
    // en sona kadar ilerler ekrana yazdirir ve komsular bitince diger taraftan devam eder.
    queue *temp= root->list[v];
	while(temp!=NULL){

		if (!visited[temp->val])

			// bu komsuya daha once girilmediyse iceri girilir ve kod recursiv olarak devam eder
            DFS_recursiv(temp->val, visited);

		// sonraki komsuya gecilir.
		temp=temp->next;

	}
}

// DFS dolasma
void DFS(int s){

	// tum komsular gidildimi diye boolean liste
    bool* visited = new bool[count];
    for (int i = 0; i < count; i++)
        visited[i] = false;
 
    // recursiv fonksiyon
    // graphı DFS olarak dolasacak
    DFS_recursiv(s, visited);

}

// main
int main()
{

	// init ve ekleme islemi
	__init__();
	addEdge(0, 1);
	addEdge(0, 3);
	addEdge(1, 2);
	addEdge(3, 5);
	addEdge(5, 0);
	addEdge(5, 3);
	addEdge(5, 4);
	addEdge(2, 3);
	addEdge(2, 4);
	addEdge(4, 2);

	// DFS dolasma, root olarak 0 secildi.
	DFS(0);


	return 0;
}
