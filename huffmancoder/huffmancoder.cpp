// huffmancoder.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
using namespace std;
#include <iostream>
#include <map>
#include<stdio.h> 
#include<windows.h>
#include<time.h>
#include "decode.h"
#include "encode.h"
#include "dealingWithFile.h"
void count();
void code();
void decode();
void welcomePage();

void welcomePage()
{

	system("color F5");
	printf("        ********************************************************************************\n");
	printf("        *                                                                              *\n");
	printf("        *                                                                              *\n");
	printf("        *   *     *     *   ******  *        *****   ****      *     *     ******      *\n");
	printf("        *   *    * *    *   *       *       *       *    *    **     **    *           *\n");
	printf("        *    *  *   *  *    ******  *       *       *    *   *  *   *  *   ******      *\n");
	printf("        *     **     **     *       *       *       *    *  *    * *    *  *           *\n");
	printf("        *      *     *      ******  ******   *****   ****   *     *     *  ******      *\n");
	printf("        *                                                                              *\n");
	printf("        *                                                                              *\n");
	printf("        *                                                                              *\n");
	printf("        *                                                                              *\n");
	printf("        *                                                                              *\n");
	printf("        *                                                                              *\n");
	printf("        *                      欢迎使用Huffman编码器V1.0                               *\n");
	printf("        *                作者：第二组 邓拳 邢国浩 段士童 梁堉 李鑫洋                   *\n");
	printf("        *                                                                              *\n");
	printf("        *                                                                              *\n");
	printf("        ********************************************************************************\n");

	Sleep(2000);
	system("cls");

}


int main() {

	welcomePage();//进入界面 

	int option = 0;

	do {
		printf("        ********************************************************************************\n");
		printf("        *                                                                              *\n");
		printf("        *      *     *      ********      *     *     *     *                          *\n");
		printf("        *     * *   * *     *             * *   *     *     *                          *\n");
		printf("        *    *   * *   *    ********      *  *  *     *     *                          *\n");
		printf("        *   *     *     *   *             *   * *     *     *                          *\n");
		printf("        *   *     *     *   ********      *     *      *****                           *\n");
		printf("        *                                                                              *\n");
		printf("        *                                                                              *\n");
		printf("        *   请按照需求输入指令：                                                       *\n");
		printf("        *   1.统计输入文件字符频度并打印                           *\n");
		printf("        *   2.对整个文件编码并保存编码后结果                                           *\n");
		printf("        *   3.文件解码                                                                 *\n");
		printf("        *   0.退出                                                                     *\n");
		printf("        *                                                                              *\n");
		printf("        *                                                                              *\n");
		printf("        *                                                                              *\n");
		printf("        *                         Huffman编码器V1.0                                    *\n");
		printf("        ********************************************************************************\n");

		cin >> option;
		system("cls"); //清空上次操作界面
		switch (option) {
		case 1:
			count();
			break;
		case 2:
			code();
			break;
		case 3:
			decode();
			break;
		}
	} while (option != 0);

	return 0;
}

void count() {
	//LY 编写的测试
	map<char, int> myMap = tableFile("f1.txt");
	for (map<char, int>::iterator iter = myMap.begin(); iter != myMap.end(); iter++)
	cout << iter->first << ' ' << iter->second << endl;
}

void code() {
	map<char, int> myMap = tableFile("f1.txt");
	Huffman huff(myMap);
	map<char, string> a = huff.encode();
	for (map<char, string>::iterator iter = a.begin(); iter != a.end(); iter++)
		cout << iter->first << ' ' << iter->second << endl;
	//map<char, string> ses = huff.encode();
	//encoding(huff.encode());
}

void decode() {
    map<char, string> res;
	//XGH 编写的测试
	decodeAsMap("XGHtest.txt.data", res, 60, "XGHdecodeResult.txt");

}
/*ref for res
	res.insert(pair<char, string>('A', "01"));
	res.insert(pair<char, string>('T', "111"));
	res.insert(pair<char, string>('C', "1010"));
	res.insert(pair<char, string>('S', "110"));
	res.insert(pair<char, string>('M', "001"));
	res.insert(pair<char, string>('N', "1011"));
	res.insert(pair<char, string>('O', "000"));
	res.insert(pair<char, string>('\n', "1000"));//(ASCII10)
	res.insert(pair<char, string>('\r', "1001"));//(ASCII13)
*/
