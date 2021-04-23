#include <stdio.h>
#include <stdlib.h>

// Vertex sayisi
#define DUGUM_SAYISI 5

int GRAF[DUGUM_SAYISI][DUGUM_SAYISI];

void __init__(){

	// aray 0 lardan olusturuluyor, eger o vertexe baglanti yok ise herhangi bie ekleme islemine gerek yok.
	GRAF[DUGUM_SAYISI][DUGUM_SAYISI] =  {0};


}

void add(int src, int dest, int weight){

	if(weight<0){
		printf("Hata!!, Dijkstra algoritmasında agirliklar eksi (-) deger alamaz !!.\n");
	}

	GRAF[src][dest] = weight;

}


// Minimum mesafe değerine sahip tepe noktasını bulmak için yazılmış fonksiyon
int minDistance(int dist[], bool sptSet[])
{
	// min degeri bulmak icin max deger atiyoruz
	int min = 999, min_index;

	for (int v = 0; v < DUGUM_SAYISI; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// mesafe dizisi yazdırılır
void printSolution(int dist[])
{
	printf("Vertex      Kaynaga olan uzaklik \n");
	for (int i = 0; i < DUGUM_SAYISI; i++)
		printf("%d      %d\n", i, dist[i]);
}

// matris kullanarak djikstra algoritmasi ile hedef vertexlere min degerleri bulma fonksiyonu
void dijkstra(int src)
{
	int dist[DUGUM_SAYISI]; // Çıktı dizisi, uzakligi tutacak

	bool sptSet[DUGUM_SAYISI]; // en kisa koseye gidilme konrolu

	// Mesafeleri sonsuz olarak baslatma ve en kisa koseye gidilme konrolu False olarak baslatma
	for (int i = 0; i < DUGUM_SAYISI; i++)
		dist[i] = 999, sptSet[i] = false;

	// kaynagin kendisine olan uzakligi = 0
	dist[src] = 0;

	// tum koseler icin en kisa yol aranir
	for (int count = 0; count < DUGUM_SAYISI - 1; count++) {
		
		int u = minDistance(dist, sptSet); // en kısa mesafeye sahip vertex fonksiyon yardimi ile secilir.

		// vertexe gidildi olarak isaretlenir
		sptSet[u] = true;

		// seçilen vertexin komsu vertexlerinin dist degerini guncelleme
		for (int v = 0; v < DUGUM_SAYISI; v++)

			// guncelleme
			if (!sptSet[v] && GRAF[u][v] && dist[u] != 999
				&& dist[u] + GRAF[u][v] < dist[v])
				dist[v] = dist[u] + GRAF[u][v];
	}

	// uzunlugu tutan arrayin ekrana yazdirilmasi
	printSolution(dist);
}

int main()
{
	__init__();
	add(0, 1, 8);
	add(0, 2, 9);
	add(0, 3, 4);

	add(1, 0, 2);
	add(1, 3, 9);
	add(1, 4, 12);

	add(2, 0, 9);
	add(2, 4, 24);

	add(3, 0, 9);
	add(3, 2, 6);
	add(3, 3, 6);

	add(4, 0, 7);
	add(4, 1, 8);
	add(4, 2, 32);
	add(4, 3, 33);
	add(4, 4, 1);
			                
	// dijkstra algoritma			                
	dijkstra(0);

	return 0;
}
