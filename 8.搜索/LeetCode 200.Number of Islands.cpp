/*
设计一个函数，输入是grid，以及空mark，还有开始搜索的点（x,y）
使他可以返回一个小岛的mark
可以用DFS BFS
DFS方法：
1，标记当前搜索位置mark=1
2，设定四个搜索方向
3，若新位置不在地图内，忽略
4，若新位置未到达过，即mark=0，并且grid=1，那么继续DFS该位置
BFS方法：
1，设置队列Q，标记mark=1，待搜的点（x,y）入队列
2，队列不空，取头部，拓展四个搜索方向
3，若新位置不在地图，continue
4，若新位置未到达过，即mark=0，并且grid=1，将新位置push到队列，并且标记mark[new]=1
总体方法：
1，设置数量num=0
2，设置mark数组，并且初始化
3，遍历grid，如果当前点是陆地，且未被访问过（主要看mark），调用搜索代码，完成搜索后num++

如果要访问全部节点，那么深搜宽搜均可
有些题目只能DFS 或者只能BFS
*/
void DFS(std::vector<std::vector<int>> &mark, std::vector<std::vector<char>> &grid, int x, int y){
    mark[x][y] = 1;
    static const int dx[] = {-1, 1, 0, 0};
    static const int dy[] = {0, 0, -1, 1};//这是定义按照上下左右的顺序进行搜索，可以自定义
    for (int i = 0; i < 4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx < 0 || newx >= mark.size() || newy < 0 || newy >= mark.size()){
            continue;
        }
        if(mark[newx][newy] == 0 && grid[newx][newy] == '1'){
            DFS(mark, grid, newx, newy);
        }
    }
}

void BFS(std::vector<std::vector<int>> &mark, std::vector<std::vector<char>> &grid, int x, int y){
    static const int dx[] = {-1, 1, 0, 0};
    static const int dy[] = {0, 0, -1, 1};
    std::queue<std::pair<int, int>> Q;
    Q.push(std::make_pair(x,y));
    mark[x][y] = 1;
    while(!Q.empty()){
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx < 0 || newx >= mark.size() || newy < 0 || newy >= mark.size()){
                continue;
            }
            if(mark[newx][newy] == 0 && grid[newx][newy] == '1'){
                Q.push(std::make_pair(newx, newy));
                mark[newx][newy] = 1;
            }
        }
    }
}


class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int num = 0;
        std::vector<std::vector<int>> mark;
        for(int i = 0; i < grid.size(); i++){
            mark.push_back(std::vector<int>());
            for(int j = 0; j < grid[i].size(); j++){
                mark[i].push_back(0);
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; i < grid[i].size(); j++){
                if(mark[i][j] == 0 && grid[i][j] == '1'){
                    BFS(mark, grid, i ,j);
                    num++;
                }
            }
        }
        return num;
    }
};