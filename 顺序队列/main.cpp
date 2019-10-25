#include "Cirsequeue.h"

int main()
{
	Cirsequeue C;
	int function;
	int num;
	int e;
	bool key;
	do
	{
		C.displayFunction();
		cout<<"请输入功能标号function:";
		cin>>function;
		switch(function)
		{
		case 1:
			cout<<"请输入入队数据总数num:";
			cin>>num;
			C.pushLotdata(num);break;
		case 2:
			C.popLotdata();break;
		case 3:
			cout<<"请输入单个入队数据e:";
			cin>>e;
			C.pushData(e);break;
		case 4:
			printf_s("单个出队数据:%d\n",C.popData());break;
		case 5:
			C.storeDatatofile();break;
		case 6:
			C.getDatafromfile();break;
		default:
			cout<<"输入的功能编号function不合理"<<endl;
		}
		C.inputJudge(key);
		system("cls");
	}while(key);

	system("pause");
	return 0;
}
