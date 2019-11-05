// mycalculator.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//
//#include "basic.h"
#include "pch.h"
#include <iostream>
#include<string>
#include<stack>

std::string expression;

void readLine() {
	char ch = '\0';
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

bool  cal(char op, double x, double y, double& r) {
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
			std::cout << "ֻ������������ģ����" << std::endl;
		}
	case '^':
		r = std::pow(x, y); break;
	case '&':
		try {
			r = pow(x, 1.0 / y);
			break;
		}
		catch (...) {
			std::cout << "���ܿ�0�η�" << std::endl;
		}
	default:
		break;
	}
}

int isdigit(char ch) {
	if ((ch > 47 && ch < 58) || ch == '.')
		return 1;
	return 0;
}
//����index+1 ��char
double GetNextexpression(int& index, int& isnum) {
	char c;
	char str[20];
	int i = 0;
	double ret;

	memset(str, 0, sizeof(str));

	//���жϽ�Ҫ������ǲ�������������
	isnum = isdigit(expression[index]);
	while (index < expression.size()) {
		c = expression[index]; //��Ԥ��һ��
		//һ������ȡ�����
		if (isdigit(c) != isnum)
			return atof(str);
		index++;

		if (isnum) {
			str[i] = c;//��c���ӵ�str
			i++;
		}
		else {

			if (IsOperator(c)) {
				//�ж�str�ǲ���һ�������Ĳ�����
				//һ��������ȡ�����
				return c;
			}
		}

	}
	return 0;
}



bool Get2Operands(std::stack<double>& opnd, double& x, double& y) {
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
	/*���ز����������ȹ�ϵ������ + < *  */
	if (a > b)
		return '>';
	else if (a < b)
		return '<';
	else
		return '=';

}






bool EvaluateExpression(std::string expression, double& result) {
	int index =0;				//	��ȡʱ��һ���ո�//�Ϲ��ƣ�û�пո�
	double a = 0, b = 0;		//����������
	double op;			//������
	char optr = '\0';			//������
	char theta;			//��ջ��ȡ���Ĳ�����
	std::stack <double> OPND;	//������ջ,�洢������
	std::stack <char> OPTR;	//������ջ,�洢��������OPSET�е�λ��
	int isnum = 0;
	int lastType = 0;		//�ϴ�ȡ�����ַ������࣬Ҳ�����ϴμ�¼��isnum

	OPTR.push('=');
	OPND.push(0);
	op = GetNextexpression(index, isnum);
	if (!isnum)
		optr = (char)(int)op;
	while (op != '=' || OPTR.top() != '=') {
		if (isnum) {
			//������
			OPND.push(op);
			lastType = isnum;
			op = GetNextexpression(index, isnum);
			if (!isnum)
				optr = (char)(int)op;
		}
		else {
			//������
			switch (Precede(isp(OPTR.top()), osp(optr))) {
			case '<'://��������ջ 
				/*����ǰ��������ջ*/
				OPTR.push(optr);
				lastType = isnum;
				op = GetNextexpression(index, isnum);
				if (!isnum)
					optr = (char)(int)op;
				break;
			case '='://������
				OPTR.pop();
				lastType = isnum;
				op = GetNextexpression(index, isnum);
				if (!isnum)
					optr = (int)op;
				break;
			case '>'://��ջ������
				theta = OPTR.top();;
				OPTR.pop();
				if (OPND.size() <= 1) {
					//���ʽ����
					return false;
				}
				b = OPND.top();
				OPND.pop();
				a = OPND.top();
				OPND.pop();
				if (!cal(theta, a, b, result)) {
					//�������
					return false;
				}
				OPND.push(result);//�������Ľ��ѹ��ջ��
				break;
			}
		}
	}
	//��������ջ�ﻹ�����ݣ�����
	if (OPND.size() >= 2)
	{
		return false;
	}
	result = OPND.top();//������ɣ����ؽ��
	return true;
}
/*int main()
{
	double res = 0;
	readLine();
	//std::cout << expression << std::endl;
	EvaluateExpression(expression, res);
	std::cout << res << std::endl;
}*/


// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ������ʾ: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
