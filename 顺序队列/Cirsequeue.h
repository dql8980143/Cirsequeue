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

	void initStart();//ѭ��˳����г�ʼ������

	void pushLotdata(int num);//ѭ��˳����ж�������Ӻ���

	void popLotdata();//ѭ��˳����������ݳ��Ӻ���

	void pushData(int e);//ѭ��˳����е�������Ӻ���

	int popData();//ѭ��˳����е����ݳ��Ӻ���

	void storeDatatofile()const;//ѭ��˳��������ݴ洢���ı��ļ�����

	void getDatafromfile();//�����ı��ļ����ݴ���ѭ��˳����к���

	void displayFunction();//ѭ�����й��ܴ�ӡ�������

	void inputJudge(bool &key);//�����жϺ���
};

