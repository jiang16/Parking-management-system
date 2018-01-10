/***********************************************************************
    > Copyright: SDUT
    > Author: 姜新宇
    > Date: 2018-01-09 
    > Description: 操作界面 
    > Email: 1796362795@qq.com 
 **********************************************************************/
#ifndef _PARKING_H
#define _PARKING_H

/*
 * 初始化停车场管理系统，若失败则退出程序
 * @param n    停车场的容量
 */
void Init(int n);

/*
 * 打印欢迎界面
 */
void PrintWelcome();

/*
 * 判断输入是否合法
 * @param id    字符数组
 * @return >=0  合法
 *         -1   非法
 */
int Judge(char *id);

/*
 * 显示当前停车场的停车状态
 */
void Status();

/*
 * 停车操作
 * @param x    车牌号
 */
void Park(int x);

/*
 * 取车操作
 * @param x    车牌号
 */
void PickUp(int x);

/*
 * 退出程序
 */
void Exit();

#endif
