//图的宽度优先遍历，用for循环，同样和二叉树层次遍历一样，就是需要加一个visit
#include <stdio.h>
#include <vector>
#include <queue>

struct GraphNode{
	int label;
	std::vector<GraphNode *> neighbors;
	GraphNode(int x) : label(x) {};
};

void BFS_graph(GraphNode *node, int visit[]){
	std::queue<GraphNode *> Q;
	Q.push(node);
	visit[node->label] = 1;
	while(!Q.empty()){
		GraphNode *node = Q.front();
		Q.pop();
		printf("%d ", node->label);
		for (int i = 0; i < node->neighbors.size(); i++){
			if (visit[node->neighbors[i]->label] == 0){
				Q.push(node->neighbors[i]);
				visit[node->neighbors[i]->label] = 1;
			}
		}
	}
}

int main(){
	const int MAX_N = 5;
	GraphNode *Graph[MAX_N];
	for (int i = 0; i < MAX_N; i++){
		Graph[i] = new GraphNode(i);
	}
	
	Graph[0]->neighbors.push_back(Graph[4]);
	Graph[0]->neighbors.push_back(Graph[2]);
	Graph[1]->neighbors.push_back(Graph[0]);
	Graph[1]->neighbors.push_back(Graph[2]);
	Graph[2]->neighbors.push_back(Graph[3]);
	Graph[3]->neighbors.push_back(Graph[4]);
	Graph[4]->neighbors.push_back(Graph[3]);
	
	int visit[MAX_N] = {0};
	for (int i = 0; i < MAX_N; i++){
		if (visit[i] == 0){
			printf("From label(%d) : ", Graph[i]->label);
			BFS_graph(Graph[i], visit);
			printf("\n");
		}
	}
	
	for (int i = 0; i < MAX_N; i++){
		delete Graph[i];
	}
	
	return 0;
}
