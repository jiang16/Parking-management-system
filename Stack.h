/***********************************************************************
    > Copyright: SDUT
    > Author: 姜新宇
    > Date: 2018-01-09 
    > Description: 操作界面 
    > Email: 1796362795@qq.com 
 **********************************************************************/
#ifndef _STACK_H
#define _STACK_H

//定义结构体栈
typedef struct Stack{
    int *base;   //动态数组基址
    int ptr;     //指向栈顶的指针
    int size;    //动态数组的大小
}Stack;

/*
 * 初始化栈
 * @param s    栈的地址
 * @param n    停车场的容量
 * @return 1   成功
 *         0   失败
 */
int InitStack(Stack *s, int n);

/*
 * 入栈
 * @param s    栈的地址
 * @param x    车牌号
 * @return 1   成功
 *         0   失败
 */
int StackPush(Stack *s, int x);

/*
 * 出栈
 * @param s    栈的地址
 * @return 1   成功
 *         0   失败
 */
int StackPop(Stack *s);

/*
 * 返回栈顶元素
 * @param s    栈的地址
 * @return >=0 成功
 *         -1  失败
 */
int StackTop(Stack s);

/*
 * 返回栈的长度
 * @param s    栈
 * @return >=0 长度
 */
int StackLength(Stack s);

/*
 * 判断栈是否为空
 * @param s    栈
 * @return 1   空
 *         0   非空
 */
int StackIsEmpty(Stack s);

/*
 * 在栈中查找值为x的元素
 * @param s    栈
 * @param x    车牌号
 * @return >=0 查找次数
 *         -1  查找失败
 */
int FindInStack(Stack s, int x);

/*
 * 释放栈中申请的内存
 * @param s    栈的地址
 */
void FreeStack(Stack *s);

#endif
