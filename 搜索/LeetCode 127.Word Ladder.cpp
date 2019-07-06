/*
我的C++刷题记录，https://github.com/DongfeiJi/LeetCode
建图，用图的宽度优先搜索
使用map构造临街表表示图，图只是一种逻辑结构，邻接表不是就是链表，这里用map表示，key是string表示顶点，value是vector<string>表示对应可到达的位置
如何构造？
将beginword push到 wordlist
遍历wordlist，看第i与j是否相差一个字符，同时将他们相连

求解：BFS搜索过程中记录到达步数
1，设置搜索队列Q，节点是pair《顶点，步数》；设置集合visit，记录搜索过的顶点；初始化将《beginword，1》添加Q
2，Q不空，取出队列头部元素
a，若取出的队列头部元素为endword，返回步数
b，否则拓展该节点，并将该节点相邻的未添加到visit的节点与步数同时加入Q，拓展节点加入visit
3，若最终无法搜索到endword，返回0
*/

bool connect(const std::string &word1, const std::string &word2){
    int cnt = 0;//记录两个单词不相等字符的个数
    for(int i = 0; i < word1.length(); i++){
        if(word1[i] != word2[i]){
            cnt++;
        }
    }
    return cnt == 1;//相差一个字符就是图中相邻的两个点
}

void construct_graph(std::string &beginWord, std::vector<std::string>& wordList, std::map<std::string,std::vector<std::string>>& graph){
    wordList.push_back(beginWord); //这是为了防止wordList中不存在这个beginWord这个单词导致无法构建图
    for(int i = 0; i < wordList.size(); i++){
        graph[wordList[i]] = std::vector<std::string>();//构建一个空的基本图，定义key和value
    }
    for(int i = 0; i < wordList.size(); i++){
        for(int j = i+1; j <wordList.size(); j++){//这里注意下一定是从j=i+1开始，因为前面已经考虑过了
            if(connect(wordList[i],wordList[j])){
                graph[wordList[i]].push_back(wordList[j]);
                graph[wordList[j]].push_back(wordList[i]);
            }
        }
    }
}

int BFS_graph(std::string &beginWord, std::string &endWord, std::map<std::string,std::vector<std::string>> &graph){
    std::queue<std::pair<std::string, int>> Q;//定义队列《顶点，步数》
    std::set<std::string> visit;//记录已访问的顶点
    Q.push(std::make_pair(beginWord,1));//初始化起点
    visit.insert(beginWord);//标记起点已经访问
    while(!Q.empty()){
        std::string node = Q.front().first;
        int step = Q.front().second;
        Q.pop();
        if(node == endWord){//找到就返回，否则继续BFS
            return step;
        }
        const std::vector<std::string> &neighbors = graph[node];//取出全部临街点遍历
        for(int i = 0; i < neighbors.size(); i++){
            if(visit.find(neighbors[i]) == visit.end()){
                Q.push(std::make_pair(neighbors[i],step+1));
                visit.insert(neighbors[i]);//标记neighbors已经进入队列了
            }
        }
    }
    return 0;//否则返回没找到
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::map<std::string,std::vector<std::string>> graph;
        construct_graph(beginWord, wordList, graph);
        return BFS_graph(beginWord, endWord, graph);
    }
};