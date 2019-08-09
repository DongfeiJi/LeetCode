/*
方法二：上面提交是针对任何序列都可以啊，没有用到ACGT这个四个字符出现这个条件
思考只有ACGT，且是DNA一定可以编码为整形，ACGT分别用0123，即00，01，10，11表示
长度为10的DNA可以用20个比特位的整数表示，如AAAAACCCCT->00000000000101010111,低位-高位，
算法思路：
1，设置全局整数哈希int g_hash_map[1048576],就是2的20次方，表示所有长度为10的DNA序列
这里必须要全局，因为太大了，爆内存，为防止栈溢出，所以开到全局
2，将DNA字符串前10个字符使用左移转换为整数key，g_hash_map[key]++
3，从DNA第11位开始，按顺序遍历各个字符，遇到1个字符即将key右移两位（就是去掉最低位），并将新的DNA字符s[i]转换为整数后，或到最高位（就是将前一个key的最低位删，然后将最新的最高位或运算到前面的缺省），g_hash_map[key]++
4，遍历哈希表，若g_hash_map[i]大于1，则将i从低到高转换为10个字符的DNA序列，push到result
*/
#include <stdio.h>

#include <vector>
#include <string>

int g_hash_map[1048576] = {0};//哈希太大了，这是建立全部可能构成的DNA序列，value为出现次数

std::string change_int_to_DNA(int DNA){
	//将长度为20的数字片段(从最右侧开始提取)转为字符串
	static const char DNA_CHAR[] = {'A', 'C', 'G', 'T'};
	std::string str;		    	
	for (int i = 0; i < 10; i++){
		str += DNA_CHAR[DNA & 3];//由于3（11）的高位补0，所以与3位运算，是倒过来的结果
		DNA = DNA >> 2;//从最右侧两位两位提取
	}
	return str;
}

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    	std::vector<std::string> result;
		if (s.length() < 10){
	    	return result;//字符串长度是length，如果小于10，直接返回空result
	    }
	    for (int i = 0; i < 1048576; i++){
	    	g_hash_map[i] = 0;//每次调用更新全局数组，哈希数组全部初始化为0
	    }	    
    	int char_map[128] = {0};
    	char_map['A'] = 0;
    	char_map['C'] = 1;
    	char_map['G'] = 2;
    	char_map['T'] = 3;//设置字符到整数的转换数组    	
    	int key = 0;
    	for (int i = 9; i >= 0; i--){//存储转换为十进制的是从最高位开始转换，这是转换s的第一个10位序列
	    	key = (key << 2) + char_map[s[i]];
	    }//这里可以想下，十进制的转换，这里是4进制，先将前一次扫描的*4，就是左移两位+此次扫描
    	g_hash_map[key] = 1;
    	for (int i = 10; i < s.length(); i++){//滑动到下一个序列，从i=10开始
    		key = key >> 2;//key先右移2位，相当于去掉了最低为
    		key = key | (char_map[s[i]] << 18);
			//将key的最高位补上扫描的s[i]，这里s[i]*4的9次幂，变为高位，就是左移18位
			g_hash_map[key]++;
	    }
	    for (int i = 0; i < 1048576; i++){
    		if (g_hash_map[i] > 1){
	    		result.push_back(change_int_to_DNA(i));
		    }
    	}
    	return result;
    }
};

int main(){
	std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution solve;
	std::vector<std::string> result = solve.findRepeatedDnaSequences(s);
	for (int i = 0; i < result.size(); i++){
		printf("%s\n", result[i].c_str());
	}
	return 0;
}
