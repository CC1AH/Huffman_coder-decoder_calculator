#pragma once
#include <iostream>
#include <fstream>
#include<algorithm>
#include<map>
#include <vector>
#include<deque>
#include<string>

using namespace std;

//DST
enum NODE_TYPE { LEAF, BIND };
/******************************NODE****************************/
class Node {
private:
	NODE_TYPE type;//节点类型
	int frequency;//频率（key value)
	char data;
	Node* left;
	Node* right;
public:
	Node(char d, int s, NODE_TYPE type);
	Node(Node* l, Node* r, int s, NODE_TYPE t);
	int getFrequency() { return this->frequency; };
	NODE_TYPE getType() { return this->type; };
	char getChar() { return this->data; };
	Node* getLeft() { return this->left; };
	Node* getRight() { return this->right; };
};

Node::Node(char d, int s, NODE_TYPE type = LEAF) {
	this->data = d;
	this->frequency = s;
	this->type = LEAF;
}
Node::Node(Node* l, Node* r, int s, NODE_TYPE t = BIND) {
	this->left = l;
	this->right = r;
	this->frequency = s;
	this->type = BIND;
}
bool comp(Node*& a, Node*& b)//定义对NODE的比较
{
	return (a->getFrequency()) < (b->getFrequency());
}

void sortNode(std::deque <Node*>& list) {
	std::sort(list.begin(), list.end(), comp);//真.快速排序
}

void sortNode2(std::deque <Node*>& list) {
	for (int i = 0; i < list.size(); i++) {
		int minIndex = i;
		//内层循环控制本轮运动员的每一次报数和教练的记录工作
		for (int j = i + 1; j < list.size(); j++) {
			//如果当前报数的运动员身高比教练当前记录的身高要小，则重新记录
			if (list[i]->getFrequency() > list[j]->getFrequency()) {
				minIndex = j;
			}
		}
		//本轮报数和记录完毕后，教练让记录上的运动员与正确目标位置的运动员交换位置
		Node* tmp = list[minIndex];
		list[minIndex] = list[i];
		list[i] = tmp;
	}
}
class Huffman {
private:
	Node* root;
public:
	Huffman(std::map<char, int> list);
	std::map<char, std::string> encode();
	void dfs(std::map<char, std::string>& list, Node* node, std::string str);

};
void Huffman::dfs(std::map<char, std::string>& list, Node* node, std::string str) {//利用递归实现，性能巨jb差，可以通过stack提升性能
	if (node->getType() == LEAF) {
		list[node->getChar()] = str;//到达叶子结点，终止递归
		return;
	}
	if (node->getLeft() != NULL)
		dfs(list, node->getLeft(), str + "0");//遍历左子树
	if (node->getRight() != NULL)
		dfs(list, node->getRight(), str + "1");//遍历右子树
}
std::map<char, std::string> Huffman::encode() {
	std::map<char, std::string> list;
	std::string str = "";
	dfs(list, root, str);
	return list;
}

Huffman::Huffman(std::map<char, int> list) {
	std::deque <Node*>  temp;//存放临时结点
	for (auto& node : list) {
		//cout << node.first << node.second << endl;
		Node* tmp = new Node(node.first, node.second, LEAF);
		//cout << tmp->getChar() << tmp->getFrequency() << endl;
		temp.push_back(tmp);//将所有元素加入临时vector

	}
	sortNode(temp);
	while (temp.size() != 1)
	{
		Node* left = temp.front();
		//cout << left->getFrequency();
		temp.pop_front();
		Node* right = temp.front();
		//cout << right->getFrequency() << endl;
		temp.pop_front();//取出前两个元素
		Node* newNode = new Node(left, right, left->getFrequency() + right->getFrequency(), BIND);
		temp.push_back(newNode);//新元素插入，将两个元素融合
		sortNode(temp);//此处可以进行性能优化！！！！！！改为插入性能会有很大提升！！！
	}
	this->root = temp.front();//建树完成
}



