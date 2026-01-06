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
void MixedlinkedList(int value)
{

    if (head == nullptr)
    {
        head = new Node(value);
        return;
    }

    Node *temp = head;
    while (temp->right != nullptr)
    {
        temp = temp->right;
    }

    temp->right = new Node(value);
}

void linkedList()
{

    Node *temp = head;

    while (temp != nullptr && temp->right != nullptr)
    {

        if (temp->right->data == temp->data)
        {
            temp->right = temp->right->right;
        }
        else
            temp = temp->right;
    }
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

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        MixedlinkedList(value);
    }

    linkedList();
    display();

    return 0;

}

INPUT :

5 
1 1 2 3 3

OUTPUT : 1 2 3