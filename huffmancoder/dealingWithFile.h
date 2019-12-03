#pragma once
#include <iostream>
#include <fstream>
#include<map>
#include<cmath>
#include<string>
using namespace std;
map<char, int> tableFile(string filename);

string encode(map<char, string> p, string filename);
void encoding(string str,string filename);
unsigned int bin2int(std::string strBin);
string plug(map<char, string> information, string filename);

//LY
/**
	函数map<char,int> tableFile(string filename)
	\description
		该函数负责将filename为名称的文件中的字符及其数目统计到map中
	\param
		string filename，传入的文件名称
	\author liang636600
\return map<char,int>
*/
map<char, int> tableFile(string filename) {
	const char* file = filename.c_str();
	ifstream in(file);

	map<char, int> myMap;
	//定义临时变量temp，为方便读取文件 
	char temp;
	//将文件中的字符存在myStr中 
	string myStr;
	//下面为文件读取操作 
	while (!in.eof()) {
		temp = in.get();
		myStr += temp;
	}
	//下面部分统计数目，如果在文件中，则相对应的字符的数目加1，如果不在文件中，那么
	//添加一个pair，将新的字符添加到map中并且将其对应的int值置为1 
	for (int i = 0;i < myStr.length() - 1;i++) {
		map<char, int>::iterator it = myMap.find(myStr[i]);
		if (it != myMap.end()) {
			myMap[myStr[i]]++;
		}
		else {
			myMap.insert(pair<char, int>(myStr[i], 1));
		}
	}

	in.close();
	/*
		这一段是测试时用的代码，打印出map中的数据
		for(map<char, int>::iterator iter = myMap.begin(); iter != myMap.end(); iter++)
		   cout<<iter->first<<' '<<iter->second<<endl;
	*/
	return  myMap;
}



//DQ

//*********************************************************************************************************
//简介：
//其他的函数都在内部调用，只看encode这个函数，该函数有两个参数，第一个为map名，第二个为读入的txt文件的名字。
//返回生成的二进制文件名。
//encode()函数功能：将txt文件中的英文以哈夫曼编码，用二进制.dat文件保存，保存文件名为“encoding.dat”
//不足一个字节用0补齐
//*********************************************************************************************************
string encode(map<char, string> p, string filename) {
	string a = plug(p, filename);
	encoding(a,filename);
	return filename + ".dat";
}


void encoding(string str,string filename) {
	int len = str.size();
	ofstream file(filename + ".dat", ios::binary);
	for (int i = 0; i < len; i += 8) {
		string a;
		if (i + 8 > len) {
			for (int j = i; j < len; j++) {
				a += str[j];
			}
			for (int k = 8; k > len - i; i--) {
				a += '0';
			}
			int c = bin2int(a);
			file.write((char*)& c, 1);
			break;
		}
		for (int j = i; j < i + 8; j++) {
			a += str[j];
		}
		int x = bin2int(a);
		file.write((char*)& x, 1);
	}
	file.close();
}

string plug(map<char, string> information, string filename) {
	fstream fileTwo;
	char x;
	fileTwo.open(filename, ios::in);
	map<char, string >::iterator ite;
	string str1;
	fileTwo >> noskipws;
	while (fileTwo >> x && !fileTwo.eof()) {
		string str2;
		ite = information.find(x);
		str2 = ite->second;
		str1 += str2;
	}
	fileTwo.close();
	return str1;
}



unsigned int bin2int(std::string strBin)
{
	unsigned int i = 0;
	const char* pch = strBin.c_str();
	while (*pch == '0' || *pch == '1') {
		i <<= 1;
		i |= *pch++ - '0';
	}

	return i;
}
