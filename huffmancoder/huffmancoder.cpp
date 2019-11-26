// huffmancoder.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
using namespace std;
#include <iostream>
#include <map>
#include "decode.h"
int main(int argc, char* argv[]) {

	cout << "---单元测试（邢国浩）---" << endl;

	//map将从编码过程中定义（不归我管）
	//之后这个地方随便找了一个样例的编码规则 二进制文件XGHtest.txt.hdta已经在本目录下了
	map<char, string> res;
	res.insert(pair<char, string>('A', "01"));
	res.insert(pair<char, string>('T', "111"));
	res.insert(pair<char, string>('C', "1010"));
	res.insert(pair<char, string>('S', "110"));
	res.insert(pair<char, string>('M', "001"));
	res.insert(pair<char, string>('N', "1011"));
	res.insert(pair<char, string>('O', "000"));
	res.insert(pair<char, string>('\n', "1000"));//(ASCII10)
	res.insert(pair<char, string>('\r', "1001"));//(ASCII13)

	decodeAsMap("XGHtest.txt.data", res, 60, "XGHdecodeResult.txt");

	cout << "\n---测试完了（邢国浩）" << endl;


	return 0;
}

