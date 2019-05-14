/*
利用栈来去括号（一个数字栈，一个操作符号栈），同时利用状态机转换思想避免if else设计麻烦
1，无括号时候，就是数字栈只要有两个了，就和操作符计算，结果push到数字栈，再按顺序入栈反复循环
2，存在括号的时候，使用一个变量compute_flag来记录是否可以计算，遇到±，flag=1；遇到 （ 不可以计算，falg=0，此时，数字栈与操作符号栈继续push，直到遇到）才可以计算。
3，这里注意一开始虽然未遇到（，但是由于只有一个数字和操作符号，flag也为0，就是初始化
4,注意一个点语言特性，定义compute函数，传进来两个栈，这里要用&xxx，因为直接传进来栈要拷贝，太大
5，字符串处理思路，这里采用工厂的思想，用状态机转移的形式。
*/
#include <stdio.h>

#include <string>
#include <stack>

class Solution {
public:
    int calculate(std::string s) {
    	static const int STATE_BEGIN = 0;
    	static const int NUMBER_STATE = 1;
    	static const int OPERATION_STATE = 2;//分别定义开始状态，数字状态，操作符状态
        std::stack<int> number_stack;
        std::stack<char> operation_stack;//分别定义数字栈，操作符栈
        long number = 0;//坑爹leetcode 由于存在超级大的数字，这里用long，int不够
        int STATE = STATE_BEGIN;//状态初始化
        int compuate_flag = 0;//初始化计算标志位
        for (int i = 0; i < s.length(); i++){
        	if (s[i] == ' '){
	        	continue;//循环扫描截至条件
	        }
	        switch(STATE){
        	case STATE_BEGIN:
        		if (s[i] >= '0' && s[i] <= '9'){
        			STATE = NUMBER_STATE;//如果遇到数字，转到数字状态
				}
				else{
					STATE = OPERATION_STATE;//遇到其他东西，转到操作符状态
				}
				i--;//退格是因为转到了对应状态没处理呀，所以退回来要处理
				break;
       		case NUMBER_STATE:
			  	if (s[i] >= '0' && s[i] <= '9'){
	  				number = number * 10 + s[i] - '0';//将字符转化为数字
	    		}
	    		else{
	    			number_stack.push(number);//转换后的数字push到数字栈里面
	    			if (compuate_flag == 1){
			    		compute(number_stack, operation_stack);//如果计算标识符为1，就可以计算
			    	}
	    			number = 0;//初始化数字值用于下一次数字字符转换
	    			i--;//凡是状态内部处理并且发生状态转移之后，都要退格，状态转移后要重新扫描处理
	    			STATE = OPERATION_STATE;//状态转移到操作符号状态
	       		}
      			break;
  			case OPERATION_STATE:
  				if (s[i] == '+' || s[i] == '-'){
  					operation_stack.push(s[i]);
  					compuate_flag = 1;//遇到+-操作符，压入操作符栈，计算标识符置1
			  	}
			  	else if (s[i] == '('){
	  				STATE = NUMBER_STATE;//遇到左括号，先算左括号，转移到数字状态，计算标识符置0
	  				compuate_flag = 0;
	  			}
	  			else if (s[i] >= '0' && s[i] <= '9'){
			  		STATE = NUMBER_STATE;//遇到数字，转到数字状态，这里要退格，因为还没有对这个数字进行处理			  		
			  		i--;
			  	}
			  	else if (s[i] == ')'){
			  		compute(number_stack, operation_stack);//遇到右括号，相当于计算了
	  			}
  				break;
        	}
        }
        if (number != 0){
        	number_stack.push(number);
       		compute(number_stack, operation_stack);//最后一步收尾的计算，勿忘！！！
        }
        if (number == 0 && number_stack.empty()){//如果数字值为0且数字栈为空 返回
        	return 0;
        }
        return number_stack.top();//返回数字栈最上面的
    }
private:
	void compute(std::stack<int> &number_stack,//这里注意一定要取地址，直接传入栈可能导致太大
				 std::stack<char> &operation_stack){
		if (number_stack.size() < 2){//如果数字栈只有一个数，返回
			return;
		}
		int num2 = number_stack.top();
		number_stack.pop();
		int num1 = number_stack.top();
		number_stack.pop();//num1与num2分别是数字栈用来计算的两个数，取出后别忘了弹出
		if (operation_stack.top() == '+'){
			number_stack.push(num1 + num2);
		}
		else if(operation_stack.top() == '-'){
			number_stack.push(num1 - num2);
		}
		operation_stack.pop();//遇到+-计算，操作符栈弹出
	}
};

int main(){	
	std::string s = "1+121 - (14+(5-6) )";
	Solution solve;
	printf("%d\n", solve.calculate(s));
	return 0;
}
/*
补充个字符串转换数字的代码，如“12345”,利用for循环，注意数字计算出来是用s[0]-'0',因为ASCII码
#include<stdio.h>
#include<string>
int main(){
    int number = 0;
    std::string s="12345";
    for(i=0;i<s.length();i++){
        number=number*10+s[i]-'0';
    }
    printf("number=%d\n",number);
    return 0;
}
*/