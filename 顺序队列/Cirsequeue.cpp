#include "Cirsequeue.h"

//ѭ��˳����г�ʼ������
void Cirsequeue::initStart()
{
	cout<<"ִ��˳����еĳ�ʼ������"<<endl;
	C.base=new int[MAX];
	if(!C.base)
	{
		cerr<<"��̬����ռ�ʧ��"<<endl;
		Sleep(1000);
		exit(1);
	}
	C.rear=C.front=0;
}

//ѭ�����ж�������Ӻ���
void Cirsequeue::pushLotdata(int num)
{
	cout<<"ִ��ѭ��˳����ж�������ӹ���"<<endl;
	initStart();
	int i;
	for(i=0;i<num;i++)
	{
		printf_s("�������%d���������:",i+1);
		cin>>C.base[C.rear];
		C.rear=(C.rear+1)%MAX;
	}
}

//ѭ�����������ݳ��Ӻ���
void Cirsequeue::popLotdata()
{
	cout<<"ִ��ѭ��˳�����������˳����ӹ���"<<endl;
	if(C.rear==C.front)
	{
		cerr<<"ѭ�����п�"<<endl;
		Sleep(1000);
		exit(3);
	}
	int i=0;
	do
	{
		i++;
		printf_s("��%d����������:%d\n",i,C.base[C.front]);
		C.front=(C.front+1)%MAX;
	}while(C.front!=C.rear);
}

//ѭ��˳����е�������Ӻ���
void Cirsequeue::pushData(int e)
{
	cout<<"ִ��ѭ��˳����е�������ӹ���"<<endl;
	if((C.rear+1)%MAX==C.front)
	{
		cerr<<"ѭ��������"<<endl;
		Sleep(1000);
		exit(4);
	}
	C.base[C.rear]=e;
	C.rear=(C.rear+1)%MAX;
}

//ѭ��˳����е����ݳ��Ӻ���
int Cirsequeue::popData()
{
	cout<<"ִ��ѭ��˳����е����ݳ��ӹ���"<<endl;
	if(C.rear==C.front)
	{
		cerr<<"ѭ������Ϊ��"<<endl;
		Sleep(1000);
		exit(5);
	}
	int e=C.base[C.front];
	C.front=(C.front+1)%MAX;
	return e;
}

//ѭ��˳��������ݴ洢���ı��ļ�����
void Cirsequeue::storeDatatofile()const
{
	cout<<"ִ��ѭ��˳��������ݴ洢���ı��ļ�����"<<endl;
	if(C.rear==C.front)
	{
		cerr<<"ѭ������Ϊ��"<<endl;
		Sleep(1000);
		exit(6);
	}
	ofstream outfile;
	outfile.open("Data.txt",ios::out);
	if(!outfile)
	{
		cerr<<"�ļ���ʧ��"<<endl;
		Sleep(1000);
		exit(7);
	}
	int front_tmp=C.front;
	int i=0;
	while(front_tmp!=C.rear)
	{
		i++;
		outfile<<"��"<<i<<"���������:"<<C.base[front_tmp++]<<endl;
	}
	outfile.close();
}

//�����ı��ļ����ݴ���ѭ��˳����к���
void Cirsequeue::getDatafromfile()
{
	cout<<"ִ�е����ı��ļ����ݴ���ѭ��˳����й���"<<endl;
	initStart();
	ifstream infile;
	infile.open("Data.txt",ios::in);
	if(!infile)
	{
		cerr<<"�ļ���ʧ��"<<endl;
		Sleep(1000);
		exit(8);
	}
	int i,data;
	char str[MAX];
	while(infile.peek()!=EOF)
	{
		infile.getline(str,sizeof(str));
		sscanf(str,"��%d���������:%d\n",&i,&data);
		C.base[C.rear]=data;
		C.rear=(C.rear+1)%MAX;
	}
	infile.close();
}

//ѭ�����й��ܴ�ӡ�������
void Cirsequeue::displayFunction()
{
	string str(50,'=');
	cout<<str<<endl;
	cout<<"    ѭ��˳����й��ܲ˵�    "<<endl;
	char* p[]={"1-ѭ��˳����ж�������ӹ���","2-ѭ��˳����������ݳ��ӹ���",
		"3-ѭ��˳����е�������ӹ���","4-ѭ��˳����е����ݳ��ӹ���",
		"5-ѭ��˳��������ݴ洢���ı��ļ�����","6-�����ı��ļ����ݴ���ѭ��˳����й���"};
	int count=sizeof(p)/sizeof(char*);
	for(int i=0;i<count;i++)
	{
		cout<<p[i]<<endl;
	}
	cout<<str<<endl;
}

//�����жϺ���
void Cirsequeue::inputJudge(bool &key)
{
	cout<<"�Ƿ�ִ����������? 1-���� 0-�˳� :";
	while(true)
	{
		cin>>key;
		if(cin.fail())
		{
			cerr<<"�������ֵ������"<<endl;
			cin.clear();
			cin.sync();
			cout<<"��������:";
		}
		else
			break;
	}
}
		


