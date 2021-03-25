// bagli liste yapisi ile Kruksal's Minimum Spanning Tree
// Ahmet Furkan DEMIR

#include <stdio.h>
#include <stdlib.h>
using namespace std;

// toplam vertex sayisi
#define vertex 9

// Birleşim bulma için bir alt kümeyi temsil eden bir yapı
// cycle olusuyormu kontrolu
struct subset {
    int parent;
    int rank;
};

// komsulari tutan yapi (komsu vertexler)
typedef struct Edge{

	// mevcut vertex
	int src;

	// hedef vertex
	int dest;

	// agirlik, mesafe
	int weight;

	// sonraki vertex
	struct Edge *next;

}edge;

// ana yapi ve kucukten buyuge siralanmis olan yapi.
edge * root, * small;

// root init
void __init__(){

	root=(edge *)malloc(sizeof(edge));
	small=(edge *)malloc(sizeof(edge));
}

// vertexleri birbirine bagladigimiz yer, edge ler olusturdugumuz yer
// v den w ye baglanti gerceklesir, agirliklar (weight) ise komsular arasi mesafe
void addEdge(int v, int w, int value){

	// ilk edge eklenir
	if(root==NULL){
		root=(edge *)malloc(sizeof(edge));
		root->weight=value;
		root->dest=w;
		root->src=v;
		root->next=NULL;
	}

	// diger komsular eklenir
	else{

		edge * temp =root;

		while(temp->next!=NULL){
			temp=temp->next;
		}

		temp->next=(edge *)malloc(sizeof(edge));
		temp->next->weight=value;
		temp->next->dest=w;
		temp->next->src=v;
		temp->next->next=NULL;

	}

}

// ana yapiyi kucukten buyuge siraladigimiz yer
void sort_small(){

	int count, flag;

 	edge * temp = root;

 	while(temp!=NULL){

 		flag=0;

 		// ilk deger eklenir
 		if(small==NULL){
 			small->src=temp->src;
 			small->dest=temp->dest;
 			small->weight=temp->weight;
 			small->next=NULL;
 		}

 		// sonraki vertexler
 		else{	

 			// eger small yapisindaki degerden daha buyuk ise yeni root degeri atanir ve yapi bir arkaya kayar.
 			if(small->weight>temp->weight){

 				edge * temp_small=(edge *)malloc(sizeof(edge));
 				temp_small->src=temp->src;
 				temp_small->dest=temp->dest;
 				temp_small->weight=temp->weight;
 				temp_small->next=small;
 				small=temp_small;


 			}

 			// ortadan veya sondan siralamaya gore ekleme
 			else{

 				edge *temp_edge = small;

 				while(temp_edge->next!=NULL){
 					
 					// ortadan ekleme
	 				if(temp_edge->next->weight>temp->weight){

	 					edge * temp_small=(edge *)malloc(sizeof(edge));
	 					temp_small->src=temp->src;
	 					temp_small->dest=temp->dest;
	 					temp_small->weight=temp->weight;
	 					temp_small->next=small;
	 					temp_small->next=temp_edge->next;
	 					temp_edge->next=temp_small;

	 					flag=1;

	 					break;

	 				}

	 				temp_edge=temp_edge->next;
	 			}

	 			// sondan ekleme
	 			if(flag==0){
	 				temp_edge->next=(edge *)malloc(sizeof(edge));
	 				temp_edge->next->src=temp->src;
	 				temp_edge->next->dest=temp->dest;
	 				temp_edge->next->weight=temp->weight;
	 				temp_edge->next->next=NULL;
	 			}

 			}

 		}

 		// sonraki vertex
 		temp=temp->next;

 	}
}

 
// cycle kontrolu icin yardimci islev
int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 	
 	// return parent
    return subsets[i].parent;
}
 
// x ve y 'yi birlestirme fonksiyonu
void Union(struct subset subsets[], int x, int y)
{	

    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    // sirali olarak birlestirme, kucuklerden. 
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // Sıralar aynıysa
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
// algoriitma
void KruskalMST()
{
    edge result[vertex]; // sonuc yapimiz
    int e = 0; // result dizisini indisliyen degisken
 	int count;
 
    // vertexin alt kumeleri icin
    struct subset* subsets = (struct subset*)malloc(vertex * sizeof(struct subset));

    for (int v = 0; v < vertex; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // yapiyi (small) dolasip islem yaptigimiz yer, son vertex e kadar ilerlenir.
 	while(small!=NULL){

	 	// yapi da bir cycle olusuyormu diye kontrol edecegiz.
	    int x = find(subsets, small->src);
	    int y = find(subsets, small->dest);
	 
	    // cycle kontrolu
	    if (x != y) {
	        result[e++] = * small;

	        // birlestirme islemi
	        Union(subsets, x, y);
	    }

	    // sonraki edge
	    small=small->next;
    }
 
    // yapimizin son hali ve minCost 'u ekrana yazdirdik.
    int minimumCost = 0, i;
    for (i = 0; i < e; ++i)
    {
        printf("%d -> %d == %d\n", result[i].src, result[i].dest, result[i].weight); 
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost : %d",minimumCost);
    return;
}

int main(){

	// init ve ekleme islemi
	__init__();
	addEdge(7, 6, 1);
	addEdge(8, 2, 2);
	addEdge(6, 5, 2);
	addEdge(0, 1, 4);
	addEdge(2, 5, 4);
	addEdge(8, 6, 6);
	addEdge(2, 3, 7);
	addEdge(7, 8, 7);
	addEdge(0, 7, 8);
	addEdge(1, 2, 8);
	addEdge(3, 4, 9);
	addEdge(5, 4, 10);
	addEdge(1, 7, 11);
	addEdge(3, 5, 14);

	// yapiyi (vertexleri), weight degerine gore kucukten buyuge siralama islemi
	sort_small();

	printf("\n");

	// Kruskal algoritmasi
	KruskalMST();

	printf("\n");

	return 0;
}
