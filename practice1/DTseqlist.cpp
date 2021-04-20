#include <stdio.h>
#include <cstdlib>
#define InitSize 10 //默认最大长度
typedef struct
{
    int *date;   //指示动态分配数组的指针
    int maxSize; //顺序表的最大容量
    int length;  //顺序表的当前长度
} SeqList;

void InitList(SeqList &L)
{
    L.date = (int *)malloc(sizeof(int) * InitSize); //用malloc函数申请一篇连续的存储空间
    L.length = 0;
    L.maxSize = InitSize;
}

void IncreaseSize(SeqList &L, int len) //增加动态数组的长度
{
    int *p = L.date;
    L.date = (int *)malloc(sizeof(int) * (L.maxSize + len));
    for (int i = 0; i < L.length; i++)
    {
        L.date[i] = p[i]; //将数据复制到新区域
    }
    L.maxSize = L.maxSize + len; //顺序表最大长度增加len
    free(p);                     //释放原来内存空间
}

int main()
{
    SeqList L;   //声明一个顺序表
    InitList(L); //初始化顺序表
                 //王顺序表中随便插入几个元素
    printf("顺序表的最大长度为：%d\n", L.maxSize);
    printf("现有顺序表的长度为：%d\n", L.length);

    IncreaseSize(L, 5);
    printf("新顺序表的最大长度为：%d\n", L.maxSize);
    system("pause");
    return 0;
}