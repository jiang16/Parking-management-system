/***********************************************************************
    > Copyright: SDUT
    > Author: 姜新宇
    > Date: 2018-01-09 
    > Description: 操作界面 
    > Email: 1796362795@qq.com 
 **********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parking.h"
#include "Stack.h"
#include "Queue.h"


Stack parkArea;        //停车场
Stack assArea;         //辅助车道
Queue waitQueue;       //等待队列
int capacity;          //停车场的容量

//初始化停车场管理系统，若失败则退出程序
void Init(int n){
    if(!(InitStack(&parkArea, n) && InitStack(&assArea, n) && InitQueue(&waitQueue)))
    {
        printf("初始化失败！请重新载入系统！\n");
        exit(0);       //初始化失败，退出程序
    }
    capacity = n;
}

//打印欢迎界面
void PrintWelcome(){
    printf("┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯\n");
    printf("├     欢迎使用停车场管理系统     ┤\n");
    printf("├                                ┤\n");
    printf("├                                ┤\n");
    printf("├          > 1 停车              ┤\n");
    printf("├          > 2 取车              ┤\n");
    printf("├          > 3 退出              ┤\n");
    printf("├                                ┤\n");
    printf("├                                ┤\n");
    printf("┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷\n");
}

//判断输入是否合法
int Judge(char *id){
    int cnt = 1, ans = 0, i;
    for(i = strlen(id) - 1; i >= 0; i--) //判断输入的车牌号是否合法，即是否为非负整数
    {
        if(id[i] >= '0' && id[i] <= '9')
        {
            ans += cnt * (id[i] - '0');
            cnt *= 10;
        }
        else
            return -1;
    }
    return ans;
}

//显示当前停车场的停车状态
void Status(){
    int cars = StackLength(parkArea);
    printf("\n★ 当前停车场已停放%d辆车，还有%d个空车位★\n\n", cars, capacity - cars); 
}

//停车操作
void Park(int x){
    if(FindInStack(parkArea, x) != -1)   //当前车辆已在停车场
    {
        printf("▲ 这辆车已在停车场中，请勿重复操作！\n");
        return;
    }
    if(FindInQueue(waitQueue, x) != -1)  //当前车辆已在等待队列中
    {
        printf("▲ 这辆车在等待队列中， 请耐心等待！\n");
        return;
    }
    if(StackLength(parkArea) == capacity)//停车场已满，进入等待队列
    {
        QueuePush(&waitQueue, x);
        printf("▲ 停车场已满，您已进入等待队列，在您之前有%d辆车，请耐心等待！\n", FindInQueue(waitQueue, x));
    }
    else                                 //停车场未满，直接停放
    {
        StackPush(&parkArea, x);
        printf("▲ OK，您的车已停在停车场内\n");
        Status();                        //输出操作后停车场的车位状态                       
    }
}

//取车操作
void PickUp(int x){
    int numS = FindInStack(parkArea, x);
    int numQ = FindInQueue(waitQueue, x);
    if(numS == -1 && numQ == -1)         //当前车辆不在停车场和等待队列中
    {
        printf("▲ 这辆车不在停车场和等待队列中，无法取车！\n");
    }
    else if(numS == -1 && numQ == 0)     //当前车辆在等待队列队首，直接驶离
    {
        QueuePop(&waitQueue);
        printf("▲ 您驶离了等待队列，成功取车\n");
    }
    else if(numS == -1 && numQ > 0)      //当前车辆在等待队列中，无法取车
    {
        printf("▲ 您当前在等待队列中，无法取车！\n");
    }
    else                                 //当前车辆在停车场内
    {
        int top = StackTop(parkArea);
        while(top != x)                  //其后的车辆倒入辅助车道
        {
            StackPop(&parkArea);
            StackPush(&assArea, top);
            top = StackTop(parkArea);
        }
        StackPop(&parkArea);             //车牌号为x的车驶出停车场，取车完成
        while(!StackIsEmpty(assArea))    //辅助车道里的车挨个驶入停车场
        {
            top = StackTop(assArea);
            StackPush(&parkArea, top);
            StackPop(&assArea);
        }
        if(!QueueIsEmpty(waitQueue))     //等待队列队首车辆进入停车场
        {
            int front = QueueFront(waitQueue);
            QueuePop(&waitQueue);
            StackPush(&parkArea, front);
        }
        printf("▲ 您已成功取车\n");
        Status();                        //输出操作后停车场的车位状态 
    }
}

//退出程序
void Exit(){
    printf("◆ 欢迎下次使用◆\n");  //退出系统
    FreeStack(&parkArea);       //释放空间
    FreeStack(&assArea);
    FreeQueue(&waitQueue);
}
