#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#define DEBUG

using namespace std;
void readFromBinaryFile(vector<int>& codearray, string filename);
void decodeAsMap(string savedFile, map<char, string>& decodingMap, int charNum, string outFile);

/**
	母函数void decodeAsMap(string savedFile,map<char, string>& decodingMap,int charNum,string outFile)
	\description
		该函数负责将二进制文件中代表的0-1串按map对应的编码规则进行解码，并将结果的字符集存储在文件outFile里面
	\param
		map<char, string>& decodingMap 哈夫曼编码规则对照表
		int charNum 文件字符个数，用于确定终点
		string outFile 将解码结果写入的是outFile
	\author CC1AH
\return
*/
void decodeAsMap(string savedFile, map<char, string>& decodingMap, int charNum, string outFile) {
	cout << "...\n";
	//初始化变量并从文件中获得哈夫曼编码串
	vector<int> codearray;
	ofstream fileOut(outFile, ios::out);
	readFromBinaryFile(codearray, savedFile);

	//对于每一个可能0-1串进行解码
	string tempString = "";
	map<char, string>::iterator iter;
	int charCount = 0;
	int n = codearray.size();

#ifdef DEBUG
	cout << "调试：解码结果：";
#endif // DEBUG

	for (int i = 0;i < n && charCount < charNum;++i) {
		int flag = 0;
		tempString.append((codearray[i]) ? "1" : "0");
		//每加一个字符，判断map里面有没有对应的字符，并且处理它。
		for (iter = decodingMap.begin(); iter != decodingMap.end(); iter++)
			if (iter->second == tempString) {
				//将字符写入解码的文件
				fileOut << iter->first;
#ifdef DEBUG
				cout << iter->first;
#endif // DEBUG
				charCount++;
				flag = 1;
				break;
			}
		//处理过的字符串置空tempString 否则继续加一个codearray[i]再判断
		if (flag)
			tempString = "";
	}
	cout << "\n解码文件" << outFile << "成功输出";
}

/**
  子函数 void readFromBinaryFile(vector<int>& codearray, string filename)
  \description
	   该函数负责读入一个filename代表的二进制文件，将它代表的二进制编码以0-1串的形式存储在codearray里面
  \param
	   int*:存储二进制文件中的0-1串
	   string:二进制文件名
  \author CC1AH
*/
void readFromBinaryFile(vector<int>& codearray, string filename) {
	ifstream fileIn(filename, ios::in);
	if (!fileIn) {
		cerr << "\"" << filename << "\" could="" not="" open." << endl;
		exit(1);
	}
	//依次读入ch（8位），将其中的每一位0或者1存储到codearray里面
	char ch;
	fileIn >> ch;
	while (!fileIn.eof()) {
		int mask = (1 << 7);
		for (int k = 0;k < 8;++k) {
			codearray.push_back((ch & (mask >> k)) ? 1 : 0);
		}
		fileIn >> ch;
	}

#ifdef DEBUG
	cout << "调试：哈夫曼编码串：\n";
	int i = codearray.size();
	for (int k = 0;k < i;++k) {
		cout << codearray[k];
		if ((k + 1) % 8 == 0)
			cout << "\t";
		if ((k + 1) % 32 == 0)
			cout << "\n";
	}
	cout << "\n";
#endif // DEBUG

}



