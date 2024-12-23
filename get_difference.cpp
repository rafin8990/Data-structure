#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

int find_difference(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    Node *tmp = head;
    int maxVal = head->val;
    int minVal = head->val;

    while (tmp != NULL)
    {
        if (tmp->val > maxVal)
        {
            maxVal = tmp->val;
        }

        if (tmp->val < minVal)
        {
            minVal = tmp->val;
        }

        tmp = tmp->next;
    }

    int diff = maxVal - minVal;
    return diff;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }

    cout << find_difference(head) << endl;
    return 0;
}
