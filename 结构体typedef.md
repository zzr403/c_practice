结构体typedef

```c
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
```

解析：

分步提取：

1.  定义个结构体

   ```c
   struct LNode
   {
       int data;
       struct LNode *next;
   }
   ```

2. 利用typedef重命名

   ```c
   typedef struct LNode LNode
   ```

   由于在定义结构体变量的时候，如定义一个std1

   ```c
   struct LNode std1
   ```

   现在

   ```c
   LNode std1
   ```

3. 再次定义

   ```c
   typedef LNode *LinkList
   ```

   上述已经重定义了一个LNode，再定义指针类型的时候原本

   ```c
   LNode * std
   ```

   现在

   ```c
   LinkList std  //就是指针变量，声明一个指向单链表第一个节点的指针
   ```

注意，这里现在几种定义方法都可以用，且共存，如执行以下语句
```c
struct Lnode *head = (struct Lnode *)malloc(sizeof(struct Lnode));
```

```c
Lnode *head = (Lnode *)malloc(sizeof(Lnode));
```

### 结构体定义类型

1. 先声明结构体类型再定义变量

   如：

   ```c
   struct LinkNode  //先定义一个链表结构体，内部有数据和指针
   {
       int data;
       struct LinkNode *next;
   };
   struct LinkNode a;//相当于上面做了一恶搞结构体，这里定义数据类型，如同int a;
   struct LinkNode b;
   ```

2. 在声明类型的同时定义变量
   如：
   ```c
   struct LinkNode  //先定义一个链表结构体，内部有数据和指针
   {
       int data;
       struct LinkNode *next;
   } a; //效果与上面一样，相当于同时定义了一个a
   struct LinkNode b;//这里像上边一样，在定义一个b

3. 不指定类型名直接定义结构体变量

    如：

   ```c
   struct//先定义一个链表结构体，内部有数据和指针
   {
       int data;
       struct LinkNode *next;
   } a; //效果与上面一样，相当于同时定义了一个a
   //以上定义了一个变量a，但是不能再定义其他的了
   ```

4. 使用typedef重新命名

   如：

   ```c
   typedef struct//先定义一个链表结构体，内部有数据和指针
   {
       int data;
       struct LinkNode *next;
   }LinkNode; //效果与上面一样，相当于同时定义了一个a
   LinkNode a;
   LinkNode b;
   ```

   