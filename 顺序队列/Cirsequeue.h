#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#define MAX 100

using namespace std;

struct cirsequeue
{
	int *base;
	int front;
	int rear;
};

class Cirsequeue
{
private:

	cirsequeue C;

public:

	void initStart();//循环顺序队列初始化函数

	void pushLotdata(int num);//循环顺序队列多数据入队函数

	void popLotdata();//循环顺序队列总数据出队函数

	void pushData(int e);//循环顺序队列单数据入队函数

	int popData();//循环顺序队列单数据出队函数

	void storeDatatofile()const;//循环顺序队列数据存储至文本文件函数

	void getDatafromfile();//导入文本文件数据创建循环顺序队列函数

	void displayFunction();//循环队列功能打印输出函数

	void inputJudge(bool &key);//输入判断函数
};

