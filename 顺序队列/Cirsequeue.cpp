#include "Cirsequeue.h"

//循环顺序队列初始化函数
void Cirsequeue::initStart()
{
	cout<<"执行顺序队列的初始化功能"<<endl;
	C.base=new int[MAX];
	if(!C.base)
	{
		cerr<<"动态申请空间失败"<<endl;
		Sleep(1000);
		exit(1);
	}
	C.rear=C.front=0;
}

//循环队列多数据入队函数
void Cirsequeue::pushLotdata(int num)
{
	cout<<"执行循环顺序队列多数据入队功能"<<endl;
	initStart();
	int i;
	for(i=0;i<num;i++)
	{
		printf_s("请输入第%d个入队数据:",i+1);
		cin>>C.base[C.rear];
		C.rear=(C.rear+1)%MAX;
	}
}

//循环队列总数据出队函数
void Cirsequeue::popLotdata()
{
	cout<<"执行循环顺序队列总数据顺序出队功能"<<endl;
	if(C.rear==C.front)
	{
		cerr<<"循环队列空"<<endl;
		Sleep(1000);
		exit(3);
	}
	int i=0;
	do
	{
		i++;
		printf_s("第%d个出队数据:%d\n",i,C.base[C.front]);
		C.front=(C.front+1)%MAX;
	}while(C.front!=C.rear);
}

//循环顺序队列单数据入队函数
void Cirsequeue::pushData(int e)
{
	cout<<"执行循环顺序队列单数据入队功能"<<endl;
	if((C.rear+1)%MAX==C.front)
	{
		cerr<<"循环队列满"<<endl;
		Sleep(1000);
		exit(4);
	}
	C.base[C.rear]=e;
	C.rear=(C.rear+1)%MAX;
}

//循环顺序队列单数据出队函数
int Cirsequeue::popData()
{
	cout<<"执行循环顺序队列单数据出队功能"<<endl;
	if(C.rear==C.front)
	{
		cerr<<"循环队列为空"<<endl;
		Sleep(1000);
		exit(5);
	}
	int e=C.base[C.front];
	C.front=(C.front+1)%MAX;
	return e;
}

//循环顺序队列数据存储至文本文件函数
void Cirsequeue::storeDatatofile()const
{
	cout<<"执行循环顺序队列数据存储至文本文件功能"<<endl;
	if(C.rear==C.front)
	{
		cerr<<"循环队列为空"<<endl;
		Sleep(1000);
		exit(6);
	}
	ofstream outfile;
	outfile.open("Data.txt",ios::out);
	if(!outfile)
	{
		cerr<<"文件打开失败"<<endl;
		Sleep(1000);
		exit(7);
	}
	int front_tmp=C.front;
	int i=0;
	while(front_tmp!=C.rear)
	{
		i++;
		outfile<<"第"<<i<<"个入队数据:"<<C.base[front_tmp++]<<endl;
	}
	outfile.close();
}

//导入文本文件数据创建循环顺序队列函数
void Cirsequeue::getDatafromfile()
{
	cout<<"执行导入文本文件数据创建循环顺序队列功能"<<endl;
	initStart();
	ifstream infile;
	infile.open("Data.txt",ios::in);
	if(!infile)
	{
		cerr<<"文件打开失败"<<endl;
		Sleep(1000);
		exit(8);
	}
	int i,data;
	char str[MAX];
	while(infile.peek()!=EOF)
	{
		infile.getline(str,sizeof(str));
		sscanf(str,"第%d个入队数据:%d\n",&i,&data);
		C.base[C.rear]=data;
		C.rear=(C.rear+1)%MAX;
	}
	infile.close();
}

//循环队列功能打印输出函数
void Cirsequeue::displayFunction()
{
	string str(50,'=');
	cout<<str<<endl;
	cout<<"    循环顺序队列功能菜单    "<<endl;
	char* p[]={"1-循环顺序队列多数据入队功能","2-循环顺序队列总数据出队功能",
		"3-循环顺序队列单数据入队功能","4-循环顺序队列单数据出队功能",
		"5-循环顺序队列数据存储至文本文件功能","6-导入文本文件数据创建循环顺序队列功能"};
	int count=sizeof(p)/sizeof(char*);
	for(int i=0;i<count;i++)
	{
		cout<<p[i]<<endl;
	}
	cout<<str<<endl;
}

//输入判断函数
void Cirsequeue::inputJudge(bool &key)
{
	cout<<"是否执行其他功能? 1-继续 0-退出 :";
	while(true)
	{
		cin>>key;
		if(cin.fail())
		{
			cerr<<"输入的数值不合理"<<endl;
			cin.clear();
			cin.sync();
			cout<<"重新输入:";
		}
		else
			break;
	}
}
		


