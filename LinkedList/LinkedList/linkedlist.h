#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template<class T>
class DNode
{
public:
    T value;
    DNode *pre;
    DNode *next;
public:
    DNode () {}
    ~DNode();
    DNode (T t, DNode *Pre, DNode *Next)
    {
        this -> value = t;
        this -> pre = Pre;
        this -> next = Next;
    }
};

template<class T>
class DLink
{
public:
    DLink();
    ~DLink();

    int size();
    int is_Empty();

    T get(int index);
    T get_first();
    T get_last();

    int insert(int indext, T t);
    int insert_first(T t);
    int append_last(T t);

    int del(int index);
    int delete_first();
    int delete_last();

private:
    int count;
    DNode<T> *phead;
    DNode<T> *get_node(int index);
};

template<class T>
DLink<T>::DLink():count(0)
{
    phead = new DNode<T>(); //创建表头,表头没有存数据.
    phead -> pre = phead -> next = phead;
}

template<class T>
DLink<T>::~DLink()
{
    //删除所有节点
    DNode<T> *ptmp;
    DNode<T> *pnode = phead -> next;
    while(pnode != phead)
    {
        ptmp = pnode;
        pnode = pnode -> next;
        delete ptmp;
    }
    //删除表头
    delete phead;
    phead = NULL;
}

template<class T>
int DLink<T>::size()
{
    return count;
}

template<class T>
int DLink<T>::is_Empty()
{
    return count == 0;
}

//获取index位置的节点
template<class T>
DNode<T>* DLink<T>::get_node(int index)
{
    //判断参数有效性
    if(index < 0 || index >= count)
    {
        cout << "get node failed! the index in out of bound!" << endl;
        return NULL;
    }
    //正向查找
    if(index <= count/2)
    {
        int i = 0;
        DNode<T> *pindex = phead -> next;
        while(i++ < index)
            pindex = pindex -> next;
        return index;
    }
    //反向查找
    int j = 0;
    int rindex = count - index - 1;
    DNode<T> *prindex = phead -> pre;
    while(j++ < rindex)
        prindex = prindex -> pre;
    return prindex;
}

//获取地index位置节点的值
template<class T>
T DLink<T>::get(int index)
{
    return get_node(index) -> value;
}

//获取最后一个节点的值
template<class T>
T DLink<T>::get_last()
{
    return get_node(cout-1) -> value;
}

#endif // LINKEDLIST_H























