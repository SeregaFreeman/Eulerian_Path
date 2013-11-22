#ifndef EULERIAN_H
#define EULERIAN_H
struct Node
{
    int data;
    Node *next;
};
void push(Node *&st, int dat);
int pop(Node *&st);
int peek(Node *st);
void add(Node*& list,int data);
void del(Node* &l,int key);
int eiler(Node **gr,int num);
void eiler_path(Node **gr);
#endif
