// Bagli liste yapisi ile graph larda BFS dolanma kodu
// Ahmet Furkan DEMIR

#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

// node sayisi
#define count 5

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

// BFS dolasma
void BFS(int s){

	// tum komsular gidildimi diye boolean liste
	bool *visited = new bool[count];
	for(int i = 0; i < count; i++)
		visited[i] = false;

	// dolasma listemiz
	list<int> queuea;

	// baslangic gidildi olarak isaretlendi
	visited[s] = true;
	// dolasma listemize eklendi
	queuea.push_back(s);


	while(!queuea.empty())
	{	
		// ekrana yazdirilip dolasma listesinden cikartilir
		s = queuea.front();
		printf("%d ",s);
		queuea.pop_front();

		// secili node 'ın tum komsularina gidilir
		queue *temp= root->list[s];
		while(temp!=NULL){

			// bu komsuya daha once girilmediyse iceri girilir
			if (!visited[temp->val])
			{	
				// komsu gidildi olarak isaretlenir ve listeye eklenir
				visited[temp->val] = true;
				queuea.push_back(temp->val);
			}

			// sonraki komsuya gecilir.
			temp=temp->next;

		}

	}

}

// main
int main()
{

	// init ve ekleme islemi
	__init__();
	addEdge(0, 1);
	addEdge(0, 3);
	addEdge(0, 2);
	addEdge(1, 3);
	addEdge(1, 2);
	addEdge(2, 4);
	addEdge(3, 4);
	addEdge(3, 2);
	addEdge(4, 1);

	// BFS dolasma, root olarak 0 secildi.
	BFS(0);


	return 0;
}
