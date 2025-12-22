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

Node *head = nullptr;
Node *head1 = nullptr;
Node *head2 = nullptr;
void linkedList1(int value1)
{

    Node *newNode = new Node(value1);
    if (head1 == nullptr)
    {
        head1 = newNode;
        return;
    }

    Node *temp1 = head1;
    while (temp1->right != nullptr)
    {
        temp1 = temp1->right;
    }

    temp1->right = newNode;
}

void linkedList2(int value2)
{

    Node *newNode = new Node(value2);
    if (head2 == nullptr)
    {
        head2 = newNode;
        return;
    }

    Node *temp2 = head2;
    while (temp2->right != nullptr)
    {
        temp2 = temp2->right;
    }

    temp2->right = newNode;
}

int carry = 0;
void linkedList3(Node *linkedList1, Node *linkedList2)
{

    Node *newNode = new Node(0);
    head = newNode;

    while (linkedList1 && linkedList2)
    {

        int sum = linkedList1->data + linkedList2->data + carry;
        carry = sum / 10;
        newNode->right = new Node(sum % 10);
        newNode = newNode->right;
        linkedList1 = linkedList1->right;
        linkedList2 = linkedList2->right;
    }

    while (linkedList1)
    {

        int sum = linkedList1->data + carry;
        carry = sum / 10;
        newNode->right = new Node(sum % 10);
        newNode = newNode->right;
        linkedList1 = linkedList1->right;
    }

    while (linkedList2)
    {

        int sum = linkedList2->data + carry;
        carry = sum / 10;
        newNode->right = new Node(sum % 10);
        newNode = newNode->right;
        linkedList2 = linkedList2->right;
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

    int n1;
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {

        int value1;
        cin >> value1;

        linkedList1(value1);
    }

    int n2;
    cin >> n2;

    for (int i = 0; i < n2; i++)
    {

        int value2;
        cin >> value2;

        linkedList2(value2);
    }

    linkedList3(head1, head2);

    display();

    return 0;
}

INPUT :

    4 2 5 2 3 5 5 2 3 4 6

    OUTPUT : 0 7 7 5 7 6