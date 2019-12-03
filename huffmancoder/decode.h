#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
//#define DEBUG

using namespace std;
void readFromBinaryFile(vector<int>& codearray, string filename);
void decodeAsMap(string savedFile, map<char, string>& decodingMap, string outFile);

/**
	ĸ����void decodeAsMap(string savedFile,map<char, string>& decodingMap,int charNum,string outFile)
	\description
		�ú������𽫶������ļ��д�����0-1����map��Ӧ�ı��������н��룬����������ַ����洢���ļ�outFile����
	\param
		map<char, string>& decodingMap ���������������ձ�
		string outFile ��������д�����outFile
	\author XGH
\return
*/
void decodeAsMap(string savedFile, map<char, string>& decodingMap,string outFile) {
	cout << "...\n";
	//��ʼ�����������ļ��л�ù��������봮
	vector<int> codearray;
	ofstream fileOut(outFile, ios::out);
	readFromBinaryFile(codearray, savedFile);

	//����ÿһ������0-1�����н���
	string tempString = "";
	map<char, string>::iterator iter;
	int charCount = 0;
	int n = codearray.size();

#ifdef DEBUG
	cout << "���ԣ���������";
#endif // DEBUG

	for (int i = 0;i < n;++i) {
		int flag = 0;
		tempString.append((codearray[i]) ? "1" : "0");
		//ÿ��һ���ַ����ж�map������û�ж�Ӧ���ַ������Ҵ�������
		for (iter = decodingMap.begin(); iter != decodingMap.end(); iter++)
			if (iter->second == tempString) {
				//���ַ�д�������ļ�
				fileOut << iter->first;
#ifdef DEBUG
				cout << iter->first;
#endif // DEBUG
				flag = 1;
				break;
			}
		//���������ַ����ÿ�tempString ���������һ��codearray[i]���ж�
		if (flag)
			tempString = "";
	}
	cout << "\n�����ļ�" << outFile << "�ɹ����\n";
}

/**
  �Ӻ��� void readFromBinaryFile(vector<int>& codearray, string filename)
  \description
	   �ú����������һ��filename�����Ķ������ļ������������Ķ����Ʊ�����0-1������ʽ�洢��codearray����
  \param
	   int*:�洢�������ļ��е�0-1��
	   string:�������ļ���
  \author XGH
*/
void readFromBinaryFile(vector<int>& codearray, string filename) {
	ifstream fileIn(filename, ios::binary);
	if (!fileIn) {
		cerr << "\"" << filename << "\" could="" not="" open." << endl;
		exit(1);
	}
	//���ζ���ch��8λ���������е�ÿһλ0����1�洢��codearray����
	unsigned char ch;
	ch = fileIn.get();
	while(!fileIn.eof()){
		int mask = (1 << 7);
		for (int k = 0;k < 8;++k) {
			codearray.push_back((ch & (mask >> k)) ? 1 : 0);
		}
		ch = fileIn.get();
	}
	fileIn.close();

#ifdef DEBUG
	cout << "���ԣ����������봮��\n";
	int n = codearray.size();
	for (int k = 0;k < n;++k) {
		cout << codearray[k];
		if ((k + 1) % 8 == 0)
			cout << "\t";
		if ((k + 1) % 32 == 0)
			cout << "\n";
	}
	cout << "\n";
#endif // DEBUG
	
}


