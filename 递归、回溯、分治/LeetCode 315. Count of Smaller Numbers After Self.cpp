/*
static const 就是其他函数调用此函数时候不会再复制这个const常量，没有static要复制
皇后就是横竖斜8个方向全部击杀
对于n皇后，那么可以用一个二维数组mark[][]来表示棋盘，并且用01表示法
对于皇后放在（x，y），表示他的占据位置，可以用循环来表示，但是太麻烦
因此引入方向数组dx，dy，0 -1 1的组合，一共8个放量
附加放置皇后更新棋盘的代码：
void put_down_the_queue(int x, int y, std::vector<std::vector<int>> &mark){
    static const int dx[]={-1,1,0,0,-1,-1,1,1};
    static const int dy[]={0,0,-1,1,-1,1,-1,1};//方向数组，dx[i]dy[i],就表示了一个方向
    mark[x][y]=1;//皇后放在（x,y）
    for(int i=0; i < mark.size();i++){//这个应该算多少行，二维数组的size是dim=0的size
        for(int j=0;j < 8;j++ ){//循环8个方向
            int new_x = x + i*dx[j];
            int new_y = y + i*dy[j];
            if(new_x >=0 && new_x < mark.size() && new_y >=0 && new_y < mark.size()){
                mark[new_x][new_y] = 1;
            }
        }
    }
}
对于本题，回溯法
N皇后问题每行肯定都要放置1个皇后，因此可以递归的对每一行放置皇后，再按列递归，同时回溯。
若放置皇后，则更新mark，回溯则恢复mark。
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;//结果
        std::vector<std::vector<int>> mark;//标记棋盘是否可以放置皇后的二维数组
        std::vector<std::string> location;//完成一次递归后，用来存储字符串摆放结果
        //先建一维数组，再遍历append扩展成为二维数组，！！！！！建立二维0数组的方法
        for(int i = 0; i < n;i++){
            mark.push_back((std::vector<int>()));//相当于放置n行空的一维数组
            for(int j = 0; j < n; j++){
                mark[i].push_back(0);//每一行放0
            }
			//！！！！！建立二维空字符串数据的方法
            location.push_back("");//放置n行空字符串
            location[i].append(n,'.');//对每一行数组扩展n个.
        }
        //这两个for就是初始化mark全是0，location全是.
        generate(0, n, location, result, mark);
        return result;
    }
private:
    void put_down_the_queue(int x, int y, std::vector<std::vector<int>> &mark){
        //附加放置皇后更新棋盘的代码
        static const int dx[]={-1,1,0,0,-1,-1,1,1};
        static const int dy[]={0,0,-1,1,-1,1,-1,1};//方向数组，dx[i]dy[i],就表示了一个方向
        mark[x][y]=1;//皇后放在（x,y）
        for(int i=0; i < mark.size(); i++){//这个应该算多少行，二维数组的size是dim=0的size
            for(int j=0;j < 8;j++ ){//循环8个方向
                int new_x = x + i*dx[j];
                int new_y = y + i*dy[j];
                if(new_x >=0 && new_x < mark.size() && new_y >=0 && new_y < mark.size()){
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }
    //generate与putdown函数理解：generate就是for循环在每一行放置皇后并且回溯，中间用到putdown更新mark
    //generate递归是放置每一行皇后，for中递归+回溯是判断每一列是否可以放皇后
private:
    void generate(int k, int n, //k代表正在放置第k行皇后，其实就是putdown函数中x坐标
                  std::vector<std::string> &location,//每一种放皇后的方法输出
                  std::vector<std::vector<std::string>> &result,
                  std::vector<std::vector<int>> &mark){
        if(k == n){//当k=n时候，完成了0-n-1行的皇后放置，递归结束
            result.push_back(location);//每一种情况字符串输出记录存入result
            return;
        }
        for(int i = 0; i < n; i++){//按顺序递归尝试0-n-1列
            if(mark[k][i] == 0){//如果第k行第i列mark标记值为0
                std::vector<std::vector<int>> tmp_mark = mark;//保存回溯前的镜像
                location[k][i] = 'Q';//放入当前皇后位置
                put_down_the_queue(k, i, mark);//更新放置皇后的mark数组
                generate(k+1, n, location, result, mark);//递归下一行皇后放置
                mark = tmp_mark;//回溯将当前mark数组复原
                location[k][i] = '.';//回溯重置当前location  
				//这里注意哦 没有之前回溯后再写递归函数是因为for循环，就相当于递归函数了
            }
        }
    }
};