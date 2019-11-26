// mycalculator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//#include "basic.h"
#include "pch.h"
#include <iostream>
#include<string>
#include<stack>

std::string expression;

void readLine(){
	char ch='\0';
	std::cin.putback(ch);
	std::cin >> expression;
}
bool IsOperator(char ch) {
	if (ch == '=' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '(' || ch == ')' || ch == '^' || ch == '&')
		return true;
	else
		return false;
}
int isp(char ch) {
	switch (ch) {
	case '=':return 0;
	case '+':return 3;
	case '-':return 3;
	case '*':return 5;
	case '/':return 5;
	case '%':return 5;
	case '(':return 1;
	case ')':return 8;
	case '^':return 7;
	case '&':return 7;
	default:
		break;
	}
}

int osp(char ch) {
	switch (ch) {
	case '=':return 0;
	case '+':return 2;
	case '-':return 2;
	case '*':return 4;
	case '/':return 4;
	case '%':return 4;
	case '(':return 8;
	case ')':return 1;
	case '^':return 6;
	case '&':return 6;
	default:
		break;
	}
}

bool  cal(char op, double x, double y, double & r) {
	switch (op)
	{
	case '+': r = x + y; break;
	case '-': r = x - y; break;
	case '*': r = x * y; break;
	case '/':
		if (y == 0)
		{
			throw "Division by zero condition!";
		}
		r = x / y; break;
	case '%':
		try {
			r = (int)x % ((int)y); break;
		}
		catch (...) {
			std::cout << "只有整数可以求模！！" << std::endl;
		}
	case '^':
		r = std::pow(x, y); break;
	case '&':
		try {
			r = pow(x, 1.0 / y);
			break;
		}
		catch (...) {
			std::cout << "不能开0次方" << std::endl;
		}
	default:
		break;
	}
}

int isdigit(char ch) {
	if ((ch>47&&ch<58) || ch == '.')
		return 1;
	return 0;
}
//返回index+1 的char
double GetNextexpression(int &index, int & isnum) {
	char c;
	char str[20];
	int i = 0;
	double ret;

	memset(str, 0, sizeof(str));

	//先判断将要读入的是操作符还是数字
	isnum = isdigit(expression[index]);
	while (index < expression.size()) {
		c = expression[index]; //先预读一个
		//一个数字取出完成
		if (isdigit(c) != isnum)return atof(str);
		index++;

		if (isnum) {
			str[i] = c;//将c连接到str
			i++;
		}
		else {

			if (IsOperator(c)) {
				//判断str是不是一个完整的操作符
				//一个操作符取出完成
				return c;
			}
		}

	}
	return 0;
}



bool Get2Operands(std::stack<double>& opnd, double &x, double &y) {
	if (opnd.size() > 1) {
		x = opnd.top();
		opnd.pop();
		y = opnd.top();
		opnd.pop();
		return true;
	}

	return false;
}

char Precede(int a, int b) {
	/*返回操作符的优先关系，例如 + < *  */
	if (a > b)
		return '>';
	else if (a < b)
		return '<';
	else
		return '=';

}






bool EvaluateExpression(std::string expression, double & result) {
	int index = 1;				//	读取时有一个空格
	double a = 0, b = 0;		//两个操作数
	double op;			//操作数
	char optr='\0';			//操作符
	char theta;			//从栈中取出的操作符
	std::stack <double> OPND;	//操作数栈,存储操作数
	std::stack <char> OPTR;	//操作符栈,存储操作符在OPSET中的位置
	int isnum=0;
	int lastType = 0;		//上次取出的字符的种类，也就是上次记录的isnum

	OPTR.push('=');
	OPND.push(0);
	op = GetNextexpression(index, isnum);
	if (!isnum)
		optr = (char)(int)op;
	while (op != '=' || OPTR.top() != '=') {
		if (isnum) {
			//操作数
			OPND.push(op);
			lastType = isnum;
			op = GetNextexpression(index, isnum);
			if (!isnum)
				optr = (char)(int)op;
		}
		else {
			//操作符
			switch (Precede(isp(OPTR.top()), osp(optr))) {
			case '<'://操作符入栈 
				/*将当前操作符入栈*/
				OPTR.push(optr);
				lastType = isnum;
				op = GetNextexpression(index, isnum);
				if (!isnum)
					optr = (char)(int)op;
				break;
			case '='://脱括号
				OPTR.pop();
				lastType = isnum;
				op = GetNextexpression(index, isnum);
				if (!isnum)
					optr = (int)op;
				break;
			case '>'://退栈并计算
				theta = OPTR.top();;
				OPTR.pop();
					if (OPND.size() <= 1) {
						//表达式错误
						return false;
					}
					b = OPND.top();
					OPND.pop();
					a = OPND.top();
					OPND.pop();
				if (!cal(theta, a, b, result)) {
					//计算错误
					return false;
				}
				OPND.push(result);//将运算后的结果压入栈顶
				break;
			}
		}
	}
	//计算完了栈里还有数据，错了
	if (OPND.size() >= 2)
	{
		return false;
	}
	result = OPND.top();//计算完成，返回结果
	return true;
}
int main()
{
	double res=0;
	readLine();
	//std::cout << expression << std::endl;
	EvaluateExpression(expression, res);
	std::cout << res << std::endl;
}

