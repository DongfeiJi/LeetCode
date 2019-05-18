#include <stdio.h>
#include <vector>

struct GraphNode{
	int label;
	std::vector<GraphNode *> neighbors;
	GraphNode(int x) : label(x) {};
};

int main(){	
	const int MAX_N = 5;
	GraphNode *Graph[MAX_N];
	
	for (int i = 0; i < MAX_N; i++){
		Graph[i] = new GraphNode(i);
	}
	
	Graph[0]->neighbors.push_back(Graph[2]);
	Graph[0]->neighbors.push_back(Graph[4]);
	Graph[1]->neighbors.push_back(Graph[0]);
	Graph[1]->neighbors.push_back(Graph[2]);
	Graph[2]->neighbors.push_back(Graph[3]);
	Graph[3]->neighbors.push_back(Graph[4]);
	Graph[4]->neighbors.push_back(Graph[3]);
	
	printf("Graph:\n");
	for (int i = 0; i < MAX_N; i++){
		printf("Label(%d) : ", i);
		for (int j = 0; j < Graph[i]->neighbors.size(); j++){
			printf("%d ", Graph[i]->neighbors[j]->label);
		}
		printf("\n");
	}
	
	for (int i = 0; i < MAX_N; i++){
		delete Graph[i];
	}
	
	return 0;
}


