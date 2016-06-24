//����������� ���������� �������� - STL 
	//���������� ����������� ���������� - vector
	//���������
#include <tchar.h>
#include <iostream>
#include <vector>
#include <iterator>
#include "myString.h"
#include "Shape.h"
#include "Point.h"
#include "Templs.h"
#include <ctime>
//#include <>


//#pragma warning(disable: 4786)


using namespace std;	
#define stop __asm nop
//#define stop system("pause");
#define _CLS system("cls");
#define  _SP system("pause");


//int main()
int _tmain(int argc, _TCHAR* argv[])
{
	std::srand(time(0));
	// ��������� ����������� ���������� vector 

//////////////////////////////////////////////////////////////////////
	//�������� ��������. 

	//�������� ��������� �������:
	//---------------------------
	//������ ������ ����� ����� - vInt � ��������� � ������� ������� size(),
	//��� ��� ������ �������. 

	//std::vector<int> vInt;
	//std::cout << vInt.size()<<std::endl;

	//
	//_SP
	
	//���������������� ��������� ��������, ��������� - ��� �� ���������
	//���� ���� ��������������, - ���������

	//vInt.push_back(1);
	//vInt.push_back(int());
	//vInt.front()=1;
	

	//std::cout << vInt.size() << std::endl;
	//PrintStat(vInt);

	//_SP

	//� ������� ������� push_back() � ����� ��������� ������ ������-���� ����������.
	//�� ������ �������� ����� ������� �� �������� ������� � ������� �������
	//size(), capacity(), max_size() � �������� �������� ���������. 
	
		//for (int i = 0; i < 10; i++) {
		//	vInt.push_back(rand());
		//	PrintStat(vInt);
		//}
		//_SP

			//
			//���������: ��� ��� ����� �������� ����������� ��� � � ��������� ��������,
			//�������� ������ �������, ������� ��� �������, ����������� �������� ������ ����
			//������� ��� "���������" � �������� ��������� �� �������.



			//������ ������������ - vDouble1 � �������� ���� ��������� ��������  �
			//��������� ��������� � ������� ���������� ���� �������. ��� �����
			//������������������� �������� �������?

			//std::vector<double>vDouble1(5);
			//PrintStat(vDouble1);
			//_SP


	//������ �������� ���� MyString � ��������� �������� - 5 ���������
	//� �������������� ������� �������� ������� "A"
	//C ������� ������� at() � ����� � ������� ���������
	//�������������� []  �������� �������� �����-���� ���������.
	//���������� "�����" �� ������� ������� � ������� at() �
	//� ������� []. 

	//std::vector<MyString> vStr(5, "A");

	//vStr[3] = "B";
	//vStr.at(4) = "C";
	////vStr[5] = "B";
	//try {
	//	vStr.at(5) = "C";
	//}
	//catch (std::out_of_range)
	//{std::cout << "U've missed";}
	//
	//_SP



	//������ ������������ - vDouble3, ������� �������� ������ ���������
	// [0,5) ������� ������������ ����� dMas. �������������� ������ dMas 
	//����� ������� � �������������������!
	
	double dMas[7];
	for (int i = 0;i < 7;i++) {
		dMas[i] = (87. / (rand() % 10 + 1));
	}
	//double::std::iterator 
	//decltype(auto) it = &dMas.begin();

	std::vector<double>vDouble3(dMas, dMas+5/*sizeof(dMas)*/);
	//_SP

	auto itb = vDouble3.begin();
	itb++;
	auto ite = vDouble3.end();

	//������ ������������ - vDouble4, ������� �������� ������ ���������
	// [2,5) ������� vDouble3. 

	std::vector<double>vDouble4(itb, ite);
//	_SP


	//������ ��������� ���� Point - vPoint1 �) � ��������� �������� 3. ����� �����������
	//����� ������ ��� ������� ��������?
	//b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).

	std::vector<Point>vPoint1(3);
	std::vector<Point>vPoint2(5, Point(1, 1));
	//_SP
	//������ ���������� �� Point - vpPoint � ��������� �������� 5
	//���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point
	{
		//std::vector<Point*>vpPoint(5,&Point((87. / (rand() % 10 + 1)), (87. / (rand() % 10 + 1))));
		//Print(vpPoint);
		//_SP

			
	//���������: ��� ������ �� ������ �������� ������ ����� ��� �����������
		//�) ������������� ����� ��������� �������
		//�) ��� ���������� operator<< ��� Point*

	}//����� �������������� �������� ����� ����������� ��� ������ �������? ///////////////////////////////////////////////////////////////////////?????????????????????????


	///////////////////////////////////////////////////////////////////////
	//�������������� ������.
	//���������, ������ �� ����� ����������� ���� ��������?
		
		//{
		//	size_t n = 10;
		//std::vector<int> v(n);
		//v.resize(n/2);
		//if (v.capacity() == n) {
		//	_SP
		//} //true?   --- ++ =))
		//_SP
		//}
		

		
		//{
		//	int n = 10;
		//	size_t m = 20;
		//vector<int> v(n);
		//v.reserve(m);
		//if (v.capacity() == m) {
		//	_SP
		//}//true? ///	������ ���� m > n
		//_SP
		//}
		

		
		{
		vector<int> v(3,5);
		v.resize(4,10); //��������? {5,5,5,10}
		v.resize(5); //��������? {5,5,5,10,0}
		//Print(v);
		//_SP
		}
		

	//�������� ��� "������" ������� � ����������
	//������ ����. 
	//� ������ ������� �������������� ������ ��� 5 ���������, � ����� ���������
	//��� ���������� � ������� push_back.
	//������ ������ ������ ��������� ���������� ����������� push_back.
	//
	//�������� ������, ������� �������� � �������� ���������


	vector<void*> v1(5);
	vector<void*> v2;
	///*MyString mStr= "qwe";
	//MyString* pmStr = &mStr;*/

	for (int i = 0;i < 5;i++) {
		v1.push_back(static_cast<void*>(new MyString("qwe")));
		v2.push_back(static_cast<void*>(new MyString("qwe")));
	}
	PrintVoid(v2, MyString());
	_SP



	
	//�������� "����������� �������" - ������� ��������
	//����� ���������� ������ int ar[] = {11,2,4,3,5};
	//�������� ������ �������� ��������� �������:
	//������ vv[0] - �������� 11 ��������� �� ��������� 11
	//vv[1] - �������� 2,2
	//vv[2] - �������� 4,4,4,4
	//...
	//������������ ���������� ������ ����������� ������� �� �������
	
	 int ar[] = { 11,2,4,3,5 };

	 //ar::iterator<int> it ;
	//it = &ar;

	 //vector<vector< int>> vv(sizeof(ar)/sizeof(int), vector<int>(*ar,*ar));
	 vector<vector< int>> vv((ar),(ar+5));       ////////////////////////////////////////////// ������ =((
	 //for (size_t i = 0; i < sizeof(ar)/sizeof(int); i++)	 {

		// vv[i][0]=ar[i];
	 //}
	//Print(vv[0]);
 	// stop

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//������� �������� ������������������ insert().
	//� ������ vChar2 �������� � ������ ������� ������ ������ ���
	//�������, ��� � ������� ������ ��� ���.


	 vector<char> vChar2;
	 //vChar2::value_type;
		 vector<char>::iterator it_e = vChar2.end();

		// *it_e='P';


	//�������� ����� ������ ��������� ������� vChar2 ����� 'W'
	



	//������� ������ ������������� ������������������ ��������.
	//��������: ���� - "qwerrrrty", ����� - "qwety"




	stop

///////////////////////////////////////////////////////////////////

	//�������� �������� ������������������ erase()
	//�������� ������� �������� �� ������ ������� ���� ������ 



	//������� ������ ������� � vector<char>

///////////////////////////////////////////////////////////////////
	//�������� ����� ������ ����� �������, ����� ��� �������� �����
	//������� ��������� ������ �� ��������� ����� ��������, �� �����������
	//���� �� � �������� �������



///////////////////////////////////////////////////////////////////

	//������� 1. ������. ��������, ����������� ��� �������.
	//�������� ������ ������ �� ��������� Point - ptList1 � ���������
	//��� ���������� � ������� ������� push_back(),
	//push_front, insert()
	

	//�������� ������ �������, ������� ����� �������� ��������
	//������ ���������� �� ������. ��������� ������ ������� �� �����������
	//vector � list. ��������� - �������� �� ������� ��� ����������.


	//�������� ����� �� ������� "�����������" - reverse()


	//�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ���� 
	//������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
	//�� � �������� ������� (����������� ��� ��������������� ����������� ���������)



	//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
	//�� �����������.
	//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
	//�������� ����������


	


	stop

	//���������� ��������������� ������ - merge(). ����������: ���
	//��� ���� ���������� � ������ �������.

	
	stop

	//���������� �������� �� ������ - remove()
	//��������� �� ������ ������� � ������������ ���������.
	//���������: ��� ������ ���� ����������� � ������ Point?
	

	//���������� �������� �� ������, ���������������� ��������� �������:
	//����� �� ��������� ������������ - remove_if(). 


	//���������� �� ������ ������ ������������� ������ - unique(). 

	stop

///////////////////////////////////////////////////////////////////
	//������� 2.������� � ����� ������� - ��������� deque

	//�������� ������ deque � ���������� ���� Point. � �������
	//assign ��������� deque ������� ��������� �������. � �������
	//�������������� ���� � ���������� ������� �������������� �������
	//�������� �������� ��������� �� ������



	//�������� deque � ���������� ���� MyString. ��������� ��� ����������
	//� ������� push_back(), push_front(), insert()
	//� ������� erase ������� �� deque ��� ��������, � ������� �������
	//���������� � 'A' ��� 'a'




  	return 0;
}