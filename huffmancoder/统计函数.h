#include <fstream>
#include <iostream>
#include <string>
#include <map>
/* 
�ⲿ���ǲ����õĲ��� 
using namespace std;
map<char, int> tableFile(string filename);
int main()
{
	map<char, int> myMap = tableFile("g:\\f3.txt");
	for(map<char, int>::iterator iter = myMap.begin(); iter != myMap.end(); iter++)  
	       cout<<iter->first<<' '<<iter->second<<endl;
}
*/

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
	const char* file=filename.c_str();
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
