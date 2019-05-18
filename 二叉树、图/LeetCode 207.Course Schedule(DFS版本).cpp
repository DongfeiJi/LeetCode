
/*方法一：深度优先搜索
前置知识点：图的表示：1，临界矩阵，就是一个二维数组，多用于稠密图并且是带权的。
2，邻接表 node->neighbors代表邻接点,node->label当前节点值,node->neighbors->label邻接点值
深度优先搜索：从某一节点出发，持续往更深处搜索，利用visit数组记录是否访问过，然后返回初始结点，
从下一个路径继续搜索，从此节点搜索完毕，再选另外一个初始节点继续搜索，
主要是深度理解递归思想，递归回退全部return了才搜索完毕。
void DFS_graph(GraphNode *node, int visit[]){
	visit[node->label] = 1;//访问到了这个点 置1代表访问完了
	printf("%d ", node->label);
	for (int i = 0; i < node->neighbors.size(); i++){
		if (visit[node->neighbors[i]->label] == 0){//如果邻接点还没有被访问
			DFS_graph(node->neighbors[i], visit);
		}
	}
} 
宽度优先搜索：从某一节点开始，先将全部邻节点搜索，即按层搜索，全部搜索后，换初始起点。用队列实现，无递归。
void BFS_graph(GraphNode *node, int visit[]){
	std::queue<GraphNode *> Q;//用队列实现
	Q.push(node);
	visit[node->label] = 1;//根节点push到队列，访问置1
	while(!Q.empty()){
		GraphNode *node = Q.front();
		Q.pop();
		printf("%d ", node->label);//返回根节点后pop
		for (int i = 0; i < node->neighbors.size(); i++){//循环访问所有邻接点
			if (visit[node->neighbors[i]->label] == 0){//如果邻接点没有被访问
				Q.push(node->neighbors[i]);
				visit[node->neighbors[i]->label] = 1;//push到队列，访问置1
			}
		}
	}
}
总结：深度搜索，相当于找子问题，用递归。宽度搜索是给定范围，因此用队列循环实现。复杂度都是o(N)
回归本题：读题读例子，很明显就是图的问题表示，并且求图内是否有环来判断。
方法一：深度优先搜索（递归）：如果正在搜索某一起始点，还未推出该点的递归深度搜索，遇到了一个起始点，那么有环
*/
#include <stdio.h>

#include <vector>
struct GraphNode{
	int label;
	std::vector<GraphNode *> neighbors;
	GraphNode(int x) : label(x) {};
};

//visit -1表示还没被访问，0表示正在递归访问，1表示访问过
bool DFS_graph(GraphNode *node, std::vector<int> &visit){
	visit[node->label] = 0;//标记此时正在访问node->label这个初始节点
	for (int i = 0; i < node->neighbors.size(); i++){//递归搜索初始节点全部邻接点
		if (visit[node->neighbors[i]->label] == -1){//如果邻接点没被访问过，下面开始深度递归访问
			if (DFS_graph(node->neighbors[i], visit) == 0){
				return false;//如果递归没退出，遇到正在访问过程中的任何一个节点，返回0
			}
		}
		else if (visit[node->neighbors[i]->label] == 0){
			return false;//这就是两个课程，有环，直接就是自己遇到了自己，返回0
		}
	}
	visit[node->label] = 1;//访问过后，node->label标记为访问过了
	return true;
}

class Solution {
public:
    bool canFinish(int numCourses,
		std::vector<std::pair<int, int> >& prerequisites) {
		std::vector<GraphNode*> graph;//图的邻接表
		std::vector<int> visit;//节点访问状态数组，-1 未访问，0 正在访问，1 访问过
		for (int i = 0; i < numCourses; i++){
			graph.push_back(new GraphNode(i));
			visit.push_back(-1);
		}//创建图的节点，new的一般要delet，visit初始化-1
		for (int i = 0; i < prerequisites.size(); i++){
			GraphNode *begin = graph[prerequisites[i].second];
			GraphNode *end = graph[prerequisites[i].first];
			begin->neighbors.push_back(end);
		}//由题，课程2指向课程1，按照图的实际意义，先学begin，在学end，箭头代表学习路径
		for (int i = 0; i < graph.size(); i++){//循环所有初始节点
			if (visit[i] == -1 && !DFS_graph(graph[i], visit)){
				return false;//如果节点没有被访问过，进行DFS，如果遇到环，返回false
			}
		}
		for (int i = 0; i < numCourses; i++){
			delete graph[i];
		}
		return true;
    }
};

int main(){	
	std::vector<std::pair<int, int> > prerequisites;
	prerequisites.push_back(std::make_pair(1, 0));
	prerequisites.push_back(std::make_pair(2, 0));
	prerequisites.push_back(std::make_pair(3, 1));
	prerequisites.push_back(std::make_pair(3, 2));
	Solution solve;
	printf("%d\n", solve.canFinish(4, prerequisites));
	return 0;
}
