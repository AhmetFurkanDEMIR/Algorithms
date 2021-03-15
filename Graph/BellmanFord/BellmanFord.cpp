// bagli liste yapisi ile graph larda belman-ford ile en kisa yol bulma algoritmasi
// Ahmet Furkan DEMIR

#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

// node sayisi (vertex)
#define count 6

// komsulari tutan yapi (komsu vertexler)
typedef struct queue{

	int id;
	int weight;
	struct queue *next;

}queue;

// nodelerin hepsini tutan yapi
typedef struct Node{

    // list yapisi vertexlerin hepsini tutacak
	struct queue *list[count];

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
		root->list[v]=(queue *)malloc(sizeof(queue));
		root->list[v]->weight=value;
		root->list[v]->id=w;
		root->list[v]->next=NULL;
	}

	// diger komsular eklenir
	else{

		queue *temp=root->list[v];

		while(temp->next!=NULL){
			temp=temp->next;
		}

		temp->next=(queue *)malloc(sizeof(queue));
		temp->next->weight=value;
		temp->next->id=w;
		temp->next->next=NULL;

	}

}

// dist dizisi ekrana print edilir
// bu dizi ana vertexe olan uzaklıkları tutar
void print(int dist[]) 
{ 
    printf("Vertex   Shortest distance\n"); 
    for (int i = 0; i < count; ++i){
        printf("%d \t\t %d\n", i, dist[i]); 
    }
} 

// belman-ford algoritmasi
void BellmanFord(int s) { 

    // ana vertexe uzakligi tutacak olan dizi
    int dist[count]; 

    // max deger atiyoruz, cunki kucukmu diye karsilastirip yeni deger atamasi yapacagiz
    for (int i = 0; i < count; i++){

        dist[i] = 999;
    }

    // baslangic vertex = 0
    dist[s] = 0; 

    // tum vertexlerimize sırayla ilerleyecegiz
    for (int i = 0; i < count; i++) { 

        // verteximizin komsularini dolasacagiz
        queue *temp= root->list[i];
        while(temp!=NULL){

            // u = suanki vertex
            int u = i; 

            // hedef (komsu) vertex
            int v = temp->id; 

            // uzaklik yani weight
            int weight = temp->weight; 

            // eger kucuk ise mevcut dist guncellenir ve yeni en kısa mesefa bu guncelleme olur
            // eger buyuk ise herhangi bir guncellemeye gerek kalmaz.
            if (dist[u] != 999 && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight; 
            }
            
            // sonraki komsu vertexe gecilir
            temp=temp->next;
        } 
        
    }
    
    // mesefe print edilir
    print(dist); 

} 


// main
int main()
{

	// init ve ekleme islemi
	__init__();
	addEdge(0, 1, 8);
	addEdge(0, 2, 1);

	addEdge(1, 5, -3);
	addEdge(1, 3, 4);

	addEdge(2, 3, 2);
	addEdge(2, 4, 5);

    addEdge(3, 2, 8);
    addEdge(3, 4, 6);

    addEdge(4, 3, 1);
    addEdge(4, 5, 3);
    addEdge(4, 1, -6);
    addEdge(5, 4, -2);

    // algoritma 
	BellmanFord(0);


	return 0;
}
