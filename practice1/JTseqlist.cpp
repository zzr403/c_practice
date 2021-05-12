#include <stdio.h>
#include <cstdlib>
#define MaxSize 10 //定义最大长度
typedef struct
{
    int data[MaxSize]; // 用静态数组存放数据元素
    int length;        //顺序表当前长度
} SqList;

void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
        L.data[i] = 0; //将所有元素设置默认初始值
    //L.length = 0;      //顺序表长度为0
}
//插入元素
/*这里有三个形参，第一个是L数据，第二个是插入元素的位置i，第三个是插入的内容e
插入元素整体来说要考虑几个方面
1.数据长度会发生变化，也就是L.length会增加
2.在i位置插入一个元素，这个插入位置后面本来的元素会整体后移
3.i位置会多一个新的元素
*/

/*但是在插入前要进行一些判断
1.要保证输入元素的正确性，并反馈
2.如果这个MaxSize为10，但是此时我们的L.length为5，我们要操做的是在第7个位置插入一个数据，虽然可能成功了，但是差了一个6位置，这样不是一个合格的顺序表了
3.如果数据已经存储满了，那么在存储也一定会发生错误
4.要在这里加一个判断，成功与否的提示
*/
bool ListInsert(SqList &L, int i, int e)
{
    //判断1：输入的i符合要求
    if (i < 1 || i > L.length + 1)
        return false;
    //判断2：存储空间是否存满
    if (L.length >= MaxSize)
        return false;
    //如没有问题按一下步骤正式执行
    for (int j = L.length; j >= i; j--)
    {                              //j为数据的个数，早在i的位置加一个新的数，那么（i-最后一个数）会向后移动一位，所以对这个范围内的数进行处理
        L.data[j] = L.data[j - 1]; //将数据后移一位
    }
    L.data[i - 1] = e; //在i上插入一个新的数据
    L.length++;
    return true; //长度加1
}
/*以上有一个要点要注意，魏旭和数组下标是不同的，数组下表从0开始，位序从1开始
所以假设L.length=6,插入的位置在第三个
那么j的初始值为6,6>=3...
而下一条语句   L.data[j] = L.data[j - 1]; 代表将 L.data[6] = L.data[5]
意思是将第6个数据放到第7个位置，这样事没错的，要与以下的删除做对应，这是一个重点
*/
/*这里我遇到一个问题，我按照插入的思路写的这个函数，可是运行后发现结果不对，经过研究，插入将插入的元素后移，10->11,9->10,8->7
我按照这个思路删除就是前移，也就是10->9,9->8,8->7,但是这样其实是移动的一个数，10->9->8->7...
于是应该是4->3,5->4,6->5这样的*/
bool ListDelete(SqList &L, int i)
{
    //判断1：输入的i符合要求
    if (i < 1 || i > L.length + 1)
        return false;
    //返回要删除元素的值
    int e;
    e = L.data[i - 1]; //要删除的是第出、个元素，但是在数组中是从0开始，所以要减一个1
    //如没有问题按一下步骤正式执行
    //////////////////////////////////////////////////////////////////
    /*   for (int j = L.length - 1; j > i; j--)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    printf("删除的元素是%d\n", e);
    return true;
    */
    ////////////////////////////////////////////////////////////////////
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

//这里是按值查找
int LocateElemV(SqList L, int e)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}
int LocateElemW(SqList L, int i)
{
    int *p;
    p = &L.data[0];
    for (int j = 1; j < i; j++)
    {
        p++;
    }
    return *p;
}

bool MinDelete(SqList &L)
{
    int m = L.data[0];
    int n;
    if (L.length == 0)
        return false;
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] < m)
        {
            m = L.data[i];
            n = i;
        }
    }
    L.data[n] = L.data[L.length - 1];
    L.length--;
    return true;
}



int main()
{
    SqList L; //声明一个顺序表
    L.length = 5;

    for (int i = 0; i < L.length; i++)
        printf("未初始化之前的data[%d]=%d\n", i, L.data[i]);
    printf("length=%d\n", L.length);
    printf("+----------------------分隔---------------------------------+\n");

    InitList(L); //初始化顺序表

    for (int i = 0; i < L.length; i++)
        printf("进行初始化后的data[%d]=%d\n", i, L.data[i]);
    printf("length=%d\n", L.length);

    printf("+----------------------分隔---------------------------------+\n");
    ListInsert(L, 1, 4);
    ListInsert(L, 2, 1);
    ListInsert(L, 3, 7);
    ListInsert(L, 4, 3);
    ListInsert(L, 5, 2);

    printf("插入后的length=%d\n", L.length);
    for (int i = 0; i < L.length; i++)
        printf("插入后的的data[%d]=%d\n", i, L.data[i]);

    printf("+----------------------分隔---------------------------------+\n");
    ListDelete(L, 6);
    ListDelete(L, 6);
    ListDelete(L, 6);
    ListDelete(L, 6);
    ListDelete(L, 6);
    printf("删除的length=%d\n", L.length);
    for (int i = 0; i < L.length; i++)
        printf("删除后的的data[%d]=%d\n", i, L.data[i]);

    printf("+----------------------分隔---------------------------------+\n");
    printf("这里看一下每个元素的地址\n");
    for (int i = 0; i < L.length; i++)
        printf("第%d个元素的地址是%p\n", i + 1, &L.data[i]);
    printf("+----------------------按值查找---------------------------------+\n");
    //按值查找
    int locateV;
    locateV = LocateElemV(L, 5);
    printf("元素的位置是=%d\n", locateV);
    printf("+----------------------分按位查找---------------------------------+\n");
    //按值查找
    int locateW;
    locateW = LocateElemW(L, 4);

    printf("元素是=%d\n", locateW);

    printf("+----------------------删除最小值并用最后一位替换---------------------------------+\n");
    //按值查找
    MinDelete(L);
    for (int i = 0; i < L.length; i++)
        printf("删除后的的data[%d]=%d\n", i, L.data[i]);
    system("pause");
    return 0;
}