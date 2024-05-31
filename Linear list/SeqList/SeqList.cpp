/*
 * @Author: Dexterary sunhan2121@mails.jlu.edu.cn
 * @Date: 2024-05-31 11:02:54
 * @LastEditors: Dexterary sunhan2121@mails.jlu.edu.cn
 * @LastEditTime: 2024-05-31 12:41:12
 * @FilePath: \Data-Structures\Linear list\SeqList\SeqList.cpp
 * @Description:顺序表的基本操作
 */

#include <iostream>
using namespace std;

#define ElemType int

// 静态分配
#define MaxSize 50
struct SeqList
{
    ElemType data[MaxSize];
    int length;
};

/*
// 动态分配
#define InitSize 100
struct SeqList
{
    ElemType *data;
    int MaxSize, length;
};
*/

/**
 * @description: 顺序表的初始化(静态分配)
 * @param {SeqList} &L 传入的顺序表
 */
void InitList(SeqList &L)
{
    L.length = 0;
}

/**
 * @description: 顺序表的初始化(动态分配)
 * @param {SeqList} &L 传入的顺序表
 */
/*
void InitList(SeqList &L)
{
    L.data = new ElemType[InitSize];
    L.length = 0;
    L.MaxSize = InitSize;
}
*/

/**
 * @description: 插入操作
 * @param {SeqList} &L 传入的顺序表
 * @param {int} i 插入的位序(从1开始)
 * @param {ElemType} e 插入的元素
 * @return {*}
 */
bool ListInsert(SeqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

/**
 * @description: 删除操作
 * @param {SeqList} &L 传入的顺序表
 * @param {int} i 删除的位序(从1开始)
 * @param {ElemType} &e 返回删除的元素
 * @return {*}
 */
bool ListDelete(SeqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

/**
 * @description: 按值查找
 * @param {SeqList} L 传入的顺序表
 * @param {ElemType} e 要查找的元素
 * @return {*} 返回元素的位序(从1开始)
 */
int LocateElem(SeqList L, ElemType e)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}

/**
 * @description: 打印顺序表
 * @param {SeqList} L 传入的顺序表
 */
void printList(SeqList L)
{
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
}

int main()
{
    SeqList L;
    InitList(L);
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    printList(L);
    cout << LocateElem(L, 4) << endl;
    ElemType e;
    ListDelete(L, 2, e);
    cout << e << endl;
    cout << LocateElem(L, 4) << endl;
    return 0;
}