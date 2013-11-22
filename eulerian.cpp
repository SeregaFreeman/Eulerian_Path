#include "eulerian.h"
#include <cstdlib>
#include <iostream>
using namespace std;

//============================Stack==============================

void push(Node *&st, int dat)
{
    // Загрузка числа в стек
    Node *el = new Node;
    el->data = dat;
    el->next = st;
    st=el;
}

int pop(Node *&st)
{
    // Извлечение из стека
    int value = st->data;
    Node *temp = st;
    st = st->next;
    delete temp;
    return value;
}

int peek(Node *st)
{
    // Получение числа без его извлечения
    return st->data;
}

//==============================================================

   // Массив списков смежности
const int vertex = 1; // Первая вершина

void add(Node*& list,int data)
{
    //Добавление смежной вершины

    if(!list)
    {
        list=new Node;
        list->data=data;
        list->next=0;
        return;
    }

    Node *temp=list;
    while(temp->next)temp=temp->next;
    Node *elem=new Node;
    elem->data=data;
    elem->next=NULL;
    temp->next=elem;
}

void del(Node* &l,int key)
{
    // Удаление вершины key из списка

    if(l->data==key)
    {
        Node *tmp=l;
        l=l->next;
        delete tmp;
    }
    else
    {
        Node *tmp=l;
        while(tmp)
        {
            if(tmp->next) // есть следующая вершина
                if(tmp->next->data==key)
                {
                    // и она искомая
                    Node *tmp2=tmp->next;
                    tmp->next=tmp->next->next;
                    delete tmp2;
                }
            tmp=tmp->next;
        }
    }
}

int eiler(Node **gr,int num)
{
    // Определение эйлеровости графа

    int count;
    for(int i=0; i<num; i++)
    {
        //проходим все вершины
        count=0;
        Node *tmp=gr[i];

        while(tmp)
        {
            // считаем степень
            count++;
            tmp=tmp->next;
        }
        if(count%2==1)return 0; // степень нечетная
    }
    return 1;   // все степени четные
}

void eiler_path(Node **gr)
{
    //Построение цикла

    Node *S = NULL;// Стек для  пройденных вершин
    int v=vertex;// 1я вершина (произвольная)
    int u;
    push(S,v); //сохраняем ее в стек
    while(S)
    {
        //пока стек не пуст
        v = peek(S); // текущая вершина
        if(!gr[v])  // если нет инцидентных ребер
        {
            v=pop(S);
            cout<<v+1<<"   "; //выводим вершину  (у нас отсчет от 1, поэтому +1)
        }
        else
        {
            u=gr[v]->data;
            push(S,u);  //проходим в следующую вершину
            del(gr[v],u);
            del(gr[u],v); //удаляем пройденное ребро
        }
    }
}
