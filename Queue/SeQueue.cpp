#include <stdio.h>
#include <cstdlib>
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int front, rare; //队列为一头入一头出，所以要设置两个指针，分别指向头和尾
} SqQueue;

void InitQueue(SqQueue &Q) //对队列进行初始化
{
    Q.rare = Q.front = 0;
}

bool EnQueue(SqQueue &Q, int m)
{
    if ((Q.rare + 1) % MaxSize == Q.front) //这里意思是当取模后为队头的值，相当于钟表转了一圈回去了，有与队头有出队的，所以队头指针不会一直在0上
        return false;                      //队列满，报错
    Q.data[Q.rare] = m;                    //将m插入到队尾   这里队尾指针一直指向有数据的下一位，即当数据为空时与推头都指向0，所以先插入数据，后移位
    Q.rare = (Q.rare + 1) % MaxSize;       //将队尾指针往后移一位,然后取模
                                           //这里由于队列一直会从队尾插入元素，队头流出元素，相当于一个一直前进的状态，但是当队尾到达尽头，且队头流出大量元素有空位置，再次从队头插入向后走
                                           //取模的原理是现在相当于一个环，如同表，绕圈走
                                           //如MaxSize为10，而对为指针已经跑到17上了，取模的话为7，相当于转了一圈再次到7
    return true;
}

bool DeQueue(SqQueue &Q)
{
    if (Q.rare == Q.front)
        return false;                  //栈空，报错
    Q.front = (Q.front + 1) % MaxSize; //这里意思是将队头指针后移就可做到出队操作了
    return true;
}
bool GetQueue(SqQueue &Q)
{
    if (Q.rare == Q.front)
        return false;                  //栈空，报错
    Q.front = (Q.front + 1) % MaxSize; //这里意思是将队头指针后移就可做到出队操作了
    return true;
}
bool QueueEmpty(SqQueue &Q)
{
    if (Q.rare == Q.front)
        return true;
    else
        return false;
}

int main()
{
    SqQueue Q;
    system("pause");
    return 0;
}
