/*方法二：宽度优先搜索
前置知识点：图的表示：1，临界矩阵，就是一个二维数组，多用于稠密图并且是带权的。
2，邻接表 node->neighbors代表邻接点,node->label当前节点值,node->neighbors->label邻接点值
深度优先搜索：从某一节点出发，持续往更深处搜索，利用visit数组记录是否访问过，然后返回初始结点，从下一个路径继续搜索，从此节点搜索完毕，再选另外一个初始节点继续搜索，主要是递归思想，递归回退才搜索完毕。
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
方法二：基于宽度优先搜索，引入入度概念，只将入度为0的点push到队列，然后该点指向所有的宽度遍历的点的入度全部减一，
接着继续push入度为0的点，实际意义就是push到队列的点就相当于遍历学习了，
所以下一层的邻接点由于前置课程学习过，所以入度也要减一,若最后所有入度为0，那么返回无环
*/
#include <stdio.h>

#include <vector>
#include <queue>

struct GraphNode{
	int label;
	std::vector<GraphNode *> neighbors;
	GraphNode(int x) : label(x) {};
};//定义图数据结构

class Solution {
public:
    bool canFinish(int numCourses,
		std::vector<std::pair<int, int> >& prerequisites) {
		std::vector<GraphNode*> graph;//图的邻接表
		std::vector<int> degree;
		for (int i = 0; i < numCourses; i++){
			degree.push_back(0);
			graph.push_back(new GraphNode(i));
		}//创建图的节点，new的一般要delete，degree初始化0
		for (int i = 0; i < prerequisites.size(); i++){
			GraphNode *begin = graph[prerequisites[i].second];
			GraphNode *end = graph[prerequisites[i].first];
			begin->neighbors.push_back(end);
			degree[prerequisites[i].first]++;
		}//由题，课程2指向课程1，按照图的实际意义，先学begin，在学end，箭头代表学习路径		
		std::queue<GraphNode *> Q;
		for (int i = 0; i < numCourses; i++){
			if (degree[i] == 0){
				Q.push(graph[i]);
			}
		}//循环所有节点，入度为0的push到队列
		while(!Q.empty()){
			GraphNode *node = Q.front();
			Q.pop();//访问了队列第一个node节点
			for (int i = 0; i < node->neighbors.size(); i++){//循环node节点的全部邻接点
				degree[node->neighbors[i]->label]--;//node所指向的邻接点入度全部减去1
				if (degree[node->neighbors[i]->label] == 0){//再将入度为0的节点push到队列
					Q.push(node->neighbors[i]);
				}
			}
		}		
		for (int i = 0; i < graph.size(); i++){
			delete graph[i];
		}		
		for (int i = 0; i < degree.size(); i++){
			if (degree[i]){
				return false;
			}
		}//如遍历过后，还有入度不是0的，那么有环，就返回false
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
