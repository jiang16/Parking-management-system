/***********************************************************************
    > Copyright: SDUT
    > Author: 姜新宇
    > Date: 2018-01-09 
    > Description: 操作界面 
    > Email: 1796362795@qq.com 
 **********************************************************************/
#ifndef _QUEUE_H
#define _QUEUE_H

//定义节点结构体
typedef struct Node{
    int data;           //节点存储的数据
    struct Node *next;  //指向下一节点的指针
}Node;

//定义队列结构体
typedef struct Queue{
    Node *head;         //队列头指针
    Node *tail;         //队列尾指针
}Queue;

/*
 * 初始化队列，为其分配内存空间
 * @param q    队列的地址
 * @return 1   成功
 *         0   失败
 */
int InitQueue(Queue *q);

/*
 * 入队
 * @param q    队列的地址
 * @param x    车牌号
 */
void QueuePush(Queue *q, int x);

/*
 * 出队
 * @param q    队列的地址
 * @return 1   成功
 *         0   失败
 */
int QueuePop(Queue *q);

/*
 * 返回队首元素
 * @param q    队列的地址
 * @return >=0 成功
 *         -1  失败
 */
int QueueFront(Queue q);

/*
 * 判断栈是否为空
 * @param q    队列
 * @return 1   空
 *         0   非空
 */
int QueueIsEmpty(Queue q);

/*
 * 在队列中查找值为x的元素
 * @param q    队列
 * @param x    车牌号
 * @return >=0 该元素之前元素的个数
 *         -1  查找失败
 */
int FindInQueue(Queue q, int x);

/*
 * 释放队列中申请的内存
 * @param q    队列的地址
 */
void FreeQueue(Queue *q);

#endif
