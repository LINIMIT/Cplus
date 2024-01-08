#include <iostream>
using namespace std;
#include <vector>

class Node
{
public:
	Node(const char* data) : data(data) 
	{

	}
public:
	const char* data;
	vector<Node*> children;
};

Node* CreateTree()
{
	Node* root = new Node("R1 개발실");
	{
		Node* node = new Node("디자인팀");
		root->children.push_back(node);
		{
			Node* leaf = new Node("전투");
			root->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("경제");
			root->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("스토리");
			root->children.push_back(leaf);
		}

	}
	{
		Node* node = new Node("프로그래밍팀");
		root->children.push_back(node);
		{
			Node* leaf = new Node("클라");
			root->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("서버");
			root->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("엔진");
			root->children.push_back(leaf);
		}

	}
	{
		Node* node = new Node("아트");
		root->children.push_back(node);
		{
			Node* leaf = new Node("배경");
			root->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("캐릭터");
			root->children.push_back(leaf);
		}
		

	}
	return root;
}

void PrintTree(Node* root, int depth = 0)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "-";
	}
	cout << root->data << endl;
	int size = root->children.size();

	for (int i = 0; i < size; i++)
	{
		Node* node = root->children[i];
		PrintTree(node, depth + 1);
	}
}

int GetHeight(Node* root)
{
	int ret = 1;

	int size = root->children.size();
	for (int i = 0; i < size; i++)
	{
		Node* node = root->children[i];
		int h = GetHeight(node) + 1;
		if (ret < h)
		{
			ret = h;
		}
	}
	return ret;
}
void main()
{
	Node* root = CreateTree();
	PrintTree(root);
	int h = GetHeight(root);

}