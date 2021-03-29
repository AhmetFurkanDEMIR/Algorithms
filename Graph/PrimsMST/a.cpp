// Ahmet Furkan DEMIR
// prims algorithm

#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

// vertex sayisi
#define vertex 10

// komsulari tutan yapi (edge) (komsu vertexler)
typedef struct edge{

	int dest;
	int weight;
	struct edge *next;

}edge;

// vertexlerin hepsini tutan yapi
typedef struct Node{

    // list yapisi vertexlerin hepsini tutacak
	struct edge *list[vertex];

}node;

// ana yapiya erisilen yer
node * root;

// root init
void __init__(){

	root=(node *)malloc(sizeof(node));
}

// dugumleri (vertexleri) birbirine bagladigimiz yer, edge ler olusturdugumuz yer
// v den w ye baglanti gerceklesir, agirliklar (weight) ise komsular arasi mesafe
void addEdge(int v, int w, int value){

	// ilk komsu eklenir
	if(root->list[v]==NULL){
		root->list[v]=(edge *)malloc(sizeof(edge));
		root->list[v]->weight=value;
		root->list[v]->dest=w;
		root->list[v]->next=NULL;
	}

	// diger komsular eklenir
	else{

		edge *temp=root->list[v];

		while(temp->next!=NULL){
			temp=temp->next;
		}

		temp->next=(edge *)malloc(sizeof(edge));
		temp->next->weight=value;
		temp->next->dest=w;
		temp->next->next=NULL;

	}

}

// yonsuz baglanti gerceklestirilir, boylece baglanti cift yonlu olur
void addEdge0(int v, int w, int value){

	addEdge(v, w, value);
	addEdge(w, v, value);

}

// komsu vertexlerinden minimum weight 'ın adresini dondurur.
int minKey(int key[], bool mstSet[])
{
	int min = 999, min_index;

	for (int v = 0; v < vertex; v++){
		if (mstSet[v] == false && key[v] < min){
			min = key[v], min_index = v;
		}
	}

	return min_index;
}

// primis mst ile olusturulan yeni graph print edilir.
int printMST(int parent[]){
	printf("Edge \tWeight\n");

	// her grapha zorunlu olarak gidilecegi icin, gidilecek yerleri bu degiskenden alacagiz.
	for (int i = 1; i < vertex; i++){

		// vertexin komsulari dolasilir
		edge * temp = root->list[parent[i]];

		while(temp!=NULL){

			// i vertexine gidilen weight yazdirilir.
			if(temp->dest==i){
				printf("%d - %d  -> %d\n", parent[i], i, temp->weight);
				break;
			}
			
			temp=temp->next;
		}

	}

	return 0;
}

// primMST
void primMST()
{
	// Oluşturulan MST'yi depolamak için dizi
	int parent[vertex];

	// minimum vertexler (komsular)
	int key[vertex];

	// gidilen yerleri isaretleyip, birdaha gidilmemesini saglamak
	bool mstSet[vertex];

	// degerleri baslatiyoruz
	for (int i = 0; i < vertex; i++){

		key[i] = 999;
		mstSet[i] = false;

	}

	// baslangic vertexi
	key[0] = 0;
	parent[0] = -1; // First node is always root of MST

	// Tüm vertexleri dolasir
	for (int count = 0; count < vertex; count++) {
		// min vertex
		int u = minKey(key, mstSet);

		// vertexi gidildi olarak isaretliyoruz
		mstSet[u] = true;

		edge * temp = root->list[u];
		while(temp!=NULL){

			if (temp->weight && mstSet[temp->dest] == false && temp->weight < key[temp->dest]){

				parent[temp->dest] = u, key[temp->dest] = temp->weight;
			}

			temp=temp->next;
		}

	}
	// print primis algoritmasi
	printMST(parent);
}


int main(){


	// init ve ekleme islemi
	__init__();
	addEdge0(0, 1, 10);
	addEdge0(1, 2, 8);
	addEdge0(2, 3, 13);
	addEdge0(4, 3, 26);
	addEdge0(1, 4, 30);
	addEdge0(2, 4, 38);
	addEdge0(3, 5, 23);
	addEdge0(5, 8, 14);
	addEdge0(8, 7, 3);
	addEdge0(5, 7, 19);
	addEdge0(6, 7, 32);
	addEdge0(5, 6, 48);
	addEdge0(7, 9, 36);
	
	primMST();


	return 0;
}
