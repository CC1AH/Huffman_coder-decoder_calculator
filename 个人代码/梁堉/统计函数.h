#include <fstream>
#include <iostream>
#include <string>
#include <map>
/* 
这部分是测试用的部分 
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
	函数map<char,int> tableFile(string filename)
	\description
		该函数负责将filename为名称的文件中的字符及其数目统计到map中 
	\param
		string filename，传入的文件名称 
	\author liang636600
\return map<char,int>
*/
map<char, int> tableFile(string filename) {
	const char* file=filename.c_str();
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
