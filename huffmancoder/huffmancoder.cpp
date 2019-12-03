// huffmancoder.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
using namespace std;

#include <iostream>
#include <map>
#include <stdio.h> 
#include <windows.h>
#include <time.h>
#include "decode.h"
#include "encode.h"
#include "dealingWithFile.h"

void count();
void code();
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
		printf("        *   1.统计输入文件中每个字符频度并打印                                         *\n");
		printf("        *   2.对整个文件编码并保存编码后结果为\"文件名.dat\"						   *\n");
		printf("        *   并接着进行解码生成\"文件名.dat.result.txt\"								   *\n");	
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
		}
	} while (option != 0);

	return 0;
}

void count() {
	string filename;
	cout << "请输入要统计字符频度的文件名：";
	cin >> filename;
	
	map<char, int> myMap = tableFile(filename);
	cout << "字符频率统计如下：\n";
	for (map<char, int>::iterator iter = myMap.begin(); iter != myMap.end(); iter++)
		cout << iter->first << "(ACSII" << (int)iter->first << "): " << iter->second << endl;
	
}

void code() {
	string filename;
	cout << "请输入要编码并解码的文件名：";
	cin >> filename;

	map<char, int> myMap = tableFile(filename);
	Huffman huff(myMap);
	map<char, string> a = huff.encode();
	cout << "根据频度生成的字符编码如下：\n";
	for (map<char, string>::iterator iter = a.begin(); iter != a.end(); iter++)
		cout << iter->first << "(ACSII" << (int)iter->first << "): " << iter->second << endl;

	cout << "\n\n文件已成功输出到: " << encode(huff.encode(),filename) << endl;
	cout << endl << endl;
	decodeAsMap(filename + ".dat", a, filename + ".result.txt");
}

