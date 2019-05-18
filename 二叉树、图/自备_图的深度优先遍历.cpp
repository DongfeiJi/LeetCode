//图的深度优先遍历，由于可能有往返，因此与二叉树遍历区别在于需要一个visit变量
//遍历到某一node，先visit=1，然后打印，对于循环neighbors中visit=0的进行深度遍历 
#include <stdio.h>
#include <vector>

struct GraphNode{
	int label;
	std::vector<GraphNode *> neighbors;
	GraphNode(int x) : label(x) {};
};

void DFS_graph(GraphNode *node, int visit[]){
	visit[node->label] = 1;
	printf("%d ", node->label);
	for (int i = 0; i < node->neighbors.size(); i++){
		if (visit[node->neighbors[i]->label] == 0){
			DFS_graph(node->neighbors[i], visit);
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
			DFS_graph(Graph[i], visit);
			printf("\n");
		}
	}
	
	for (int i = 0; i < MAX_N; i++){
		delete Graph[i];
	}
	
	return 0;
}
