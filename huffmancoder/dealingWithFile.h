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
	����map<char,int> tableFile(string filename)
	\description
		�ú�������filenameΪ���Ƶ��ļ��е��ַ�������Ŀͳ�Ƶ�map��
	\param
		string filename��������ļ�����
	\author liang636600
\return map<char,int>
*/
map<char, int> tableFile(string filename) {
	const char* file = filename.c_str();
	ifstream in(file);

	map<char, int> myMap;
	//������ʱ����temp��Ϊ�����ȡ�ļ� 
	char temp;
	//���ļ��е��ַ�����myStr�� 
	string myStr;
	//����Ϊ�ļ���ȡ���� 
	while (!in.eof()) {
		temp = in.get();
		myStr += temp;
	}
	//���沿��ͳ����Ŀ��������ļ��У������Ӧ���ַ�����Ŀ��1����������ļ��У���ô
	//���һ��pair�����µ��ַ���ӵ�map�в��ҽ����Ӧ��intֵ��Ϊ1 
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
		��һ���ǲ���ʱ�õĴ��룬��ӡ��map�е�����
		for(map<char, int>::iterator iter = myMap.begin(); iter != myMap.end(); iter++)
		   cout<<iter->first<<' '<<iter->second<<endl;
	*/
	return  myMap;
}



//DQ

//*********************************************************************************************************
//��飺
//�����ĺ��������ڲ����ã�ֻ��encode����������ú�����������������һ��Ϊmap�����ڶ���Ϊ�����txt�ļ������֡�
//�������ɵĶ������ļ�����
//encode()�������ܣ���txt�ļ��е�Ӣ���Թ��������룬�ö�����.dat�ļ����棬�����ļ���Ϊ��encoding.dat��
//����һ���ֽ���0����
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
