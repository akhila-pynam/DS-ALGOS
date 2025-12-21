#include <bits/stdc++.h>
using namespace std;

struct Node
{

	int data;
	Node *right;

	Node(int val)
	{
		data = val;
		right = nullptr;
	}
};

Node *head = NULL;
void linkedList(int value)
{

	Node *newNode = new Node(value);
	if (head == nullptr)
	{
		head = newNode;
		return;
	}

	Node *temp = head;
	while (temp->right != nullptr)
	{
		temp = temp->right;
	}

	temp->right = newNode;
}

void display()
{

	Node *temp = head;
	while (temp->right != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->right;
	}

	cout << temp->data << " ";
}

int main()
{

#ifndef ONLIE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{

		int value;
		cin >> value;

		linkedList(value);
	}

	display();

	return 0;
}
// INPUT :

// 4
// 2 3 4 5

// OUTPUT : 2 3 4 5
