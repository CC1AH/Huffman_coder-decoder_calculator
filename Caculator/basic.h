#pragma once
#include <iostream>
#include<string>
#include <cmath>
#include <stack>
extern std::string expression;
/*
std::string readLine() {
	char ch;
	std::string operand;
	std::cin.putback(ch);
	std::cin >> operand;
}*/
int isp(char ch) {
	switch(ch){
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
	return -1;
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
	return -1;
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
	//返回index+1 的char
	void GetNextchar(char & ch,int index){
		ch = expression[++index];
	}

	bool isdigit(char ch) {
		return isdigit(ch);
	}
	
	bool IsOperator(char ch) {
		if (ch == '=' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '(' || ch == ')' || ch == '^' || ch == '&')
			return true;
		else
			return false;
	}

	bool Get2Operands(std::stack<double>& opnd, double &x, double &y) {
		if (opnd.size()>1) {
			x = opnd.top();
			opnd.pop();
			y = opnd.top();
			opnd.pop();
			return true;
		}
		
		return false;
	}