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
	NODE_TYPE type;//�ڵ�����
	int frequency;//Ƶ�ʣ�key value)
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
bool comp(Node*& a, Node*& b)//�����NODE�ıȽ�
{
	return (a->getFrequency()) < (b->getFrequency());
}
void sortNode(std::deque <Node*>& list) {
	std::sort(list.begin(), list.end(), comp);//��.��������
}

class Huffman {
private:
	Node* root;
public:
	Huffman(std::map<char, int> list);
	std::map<char, std::string> encode();
	void dfs(std::map<char, std::string>& list, Node* node, std::string str);

};
void Huffman::dfs(std::map<char, std::string>& list, Node* node, std::string str) {//���õݹ�ʵ�֣����ܾ�jb�����ͨ��stack��������
	if (node->getType() == LEAF) {
		list[node->getChar()] = str;//����Ҷ�ӽ�㣬��ֹ�ݹ�
		return;
	}
	dfs(list, node->getLeft(), str + "0");//����������
	dfs(list, node->getRight(), str + "1");//����������
}
std::map<char, std::string> Huffman::encode() {
	std::map<char, std::string> list;
	std::string str;
	dfs(list, root, str);
	return list;
}

Huffman::Huffman(std::map<char, int> list) {
	std::deque <Node*>  temp;//�����ʱ���
	for (auto& node : list)
		temp.push_back(&(Node::Node(node.first, node.second, LEAF)));//������Ԫ�ؼ�����ʱvector
	sortNode(temp);
	while (temp.size() != 1)
	{
		Node* left = temp.front();
		temp.pop_front();
		Node* right = temp.front();
		temp.pop_front();//ȡ��ǰ����Ԫ��
		Node* newNode = new Node(left, right, left->getFrequency() + right->getFrequency(), BIND);
		temp.push_back(newNode);//��Ԫ�ز��룬������Ԫ���ں�
		sortNode(temp);//�˴����Խ��������Ż���������������Ϊ�������ܻ��кܴ�����������
	}
	this->root = temp.front();//�������
}



