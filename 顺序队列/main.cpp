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
		cout<<"�����빦�ܱ��function:";
		cin>>function;
		switch(function)
		{
		case 1:
			cout<<"�����������������num:";
			cin>>num;
			C.pushLotdata(num);break;
		case 2:
			C.popLotdata();break;
		case 3:
			cout<<"�����뵥���������e:";
			cin>>e;
			C.pushData(e);break;
		case 4:
			printf_s("������������:%d\n",C.popData());break;
		case 5:
			C.storeDatatofile();break;
		case 6:
			C.getDatafromfile();break;
		default:
			cout<<"����Ĺ��ܱ��function������"<<endl;
		}
		C.inputJudge(key);
		system("cls");
	}while(key);

	system("pause");
	return 0;
}
