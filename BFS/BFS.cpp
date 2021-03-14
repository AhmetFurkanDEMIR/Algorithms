#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

#define count 5

typedef struct queue{

	int val;
	struct queue *next;

}queue;

typedef struct Node{

	struct queue *list[count];

}node;

node * root;


void __init__(){

	root=(node *)malloc(sizeof(node));
}

void addEdge(int v, int w){

	if(root->list[v]==NULL){
		root->list[v]=(queue *)malloc(sizeof(queue));
		root->list[v]->val=w;
		root->list[v]->next=NULL;
	}


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


void BFS(int s){

	bool *visited = new bool[count];
	for(int i = 0; i < count; i++)
		visited[i] = false;

	list<int> queuea;

	visited[s] = true;
	queuea.push_back(s);


	while(!queuea.empty())
	{
		s = queuea.front();
		printf("%d ",s);
		queuea.pop_front();

		queue *temp= root->list[s];

		while(temp!=NULL){

			if (!visited[temp->val])
			{
				visited[temp->val] = true;
				queuea.push_back(temp->val);
			}

			temp=temp->next;

		}

	}

}


int main()
{

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

	BFS(0);


	return 0;
}
