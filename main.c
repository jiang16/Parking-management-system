/***********************************************************************
    > Copyright: SDUT
    > Author: 姜新宇
    > Date: 2018-01-09 
    > Description: 操作界面 
    > Email: 1796362795@qq.com 
 **********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Parking.h"

#define N 5                       //停车场的容量，默认为5

int main(int argv, char *argc[]){
    Init(N);       
    while(1)
    {
        system("clear");          //清屏
        PrintWelcome();
        printf("● 请在此输入操作所对应的数字：\n");
        char num[30];             //接收输入的操作数字
        scanf("%s", num);
        int opNum = Judge(num);   //判定结果
        if(opNum == 1 || opNum == 2 || opNum == 3)
        {
            if(opNum == 3)
                break;
            printf("● 正在为您办理相应服务，请输入车牌号：\n");
            char id[30];          //接收输入的车牌号
            scanf("%s", id);
            int res = Judge(id);  //判定结果
            if(res == -1)
                printf("▲ 您输入的车牌号不合法！请确保输入的车牌号为非负整数\n"); 
            else if(opNum == 1)
                Park(res);
            else if(opNum = 2)
                PickUp(res);     
        }
        else
            printf("▲ 没有对应的操作！请重新输入\n");
        sleep(3);                 //睡眠
    }
    Exit();
    return 0;
}
