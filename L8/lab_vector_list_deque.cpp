//����������� ���������� �������� - STL 
	//���������� ����������� ���������� - vector
	//���������
#include <tchar.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include "myString.h"
#include "Shape.h"
#include "Point.h"
#include "Templs.h"
#include <ctime>
#include <algorithm>


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
		std::vector<Point*>vpPoint(5);//, 
		int size = vpPoint.size();
		for (int i = 0; i < size;i++) {
		vpPoint[i] = new Point((87. / (rand() % 10 + 1)), (87. / (rand() % 10 + 1)));
		}

		//Print(vpPoint);
		//_SP
		CleanPoinerContainer(vpPoint);
			
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
		v1.push_back(new MyString("qwe"));
		v2.push_back(new MyString("qwe"));
	}
	//PrintVoid<decltype(v2), MyString>(v2);
	//SP
	CleanPoinerContainer(v1);
	CleanPoinerContainer(v2);

	
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
	 for (size_t i = 0; i < sizeof(ar)/sizeof(int); i++)	 {
		 vector<int>::iterator itb = (vv[i]).begin();
		 vector<int>::iterator ite = (vv[i]).end();

		 while (itb != ite) {
			 *itb = ar[i];
			 ++itb;
		 }
	 }
	//Print(vv);
 	//_SP
	// stop

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//������� �������� ������������������ insert().
	//� ������ vChar2 �������� � ������ ������� ������ ������ ���
	//�������, ��� � ������� ������ ��� ���.


	 vector<char> vChar2(2,'T');
	 //vChar2::value_type;
		 //vector<char>::iterator it_e = vChar2.end();
		 Insert_if_absent(vChar2, 'Q');
		 Insert_if_absent(vChar2, 'Q');
	//	 Print(vChar2);
	//	 _SP
			 // *it_e='P';


		 //�������� ����� ������ ��������� ������� vChar2 ����� 'W'

		 vector<char>::iterator it_b = vChar2.begin();
		 vector<char>::iterator it_e = vChar2.end();

		while (it_b != it_e){
			it_b = vChar2.insert(it_b, 'W');
				++it_b;
				++it_b;
				it_e = vChar2.end();
		}
		//_SP;
	


	//������� ������ ������������� ������������������ ��������.
	//��������: ���� - "qwerrrrty", ����� - "qwety"

		vChar2.clear();
		vChar2.push_back('q');
		vChar2.push_back('q');
		vChar2.push_back('w');
		vChar2.push_back('e');
		vChar2.push_back('r');
		vChar2.push_back('r');
		vChar2.push_back('r');
		vChar2.push_back('r');
		vChar2.push_back('t');
		vChar2.push_back('y');
		vChar2.push_back('y');
		
		Print(vChar2);
		
		DeleteSeqs(vChar2);
		Print(vChar2);
		_SP
		vChar2.push_back('q');
		vChar2.push_back('w');
		vChar2.push_back('e');
		//vChar2.clear();

		//stop

			///////////////////////////////////////////////////////////////////

				//�������� �������� ������������������ erase()
				//�������� ������� �������� �� ������ ������� ���� ������ 

			DeleteTwicy(vChar2);
			//_SP
			//Print(vChar2);
	//������� ������ ������� � vector<char>

			
		vChar2.push_back('q');
		vChar2.push_back(' ');
		vChar2.push_back(' ');
		vChar2.push_back('r');
		vChar2.push_back('r');
		vChar2.push_back(' ');
		vChar2.push_back('r');
		vChar2.push_back('t');
		vChar2.push_back('y');
		DelExcesSpaces(vChar2);
		//Print(vChar2);
		//_SP
			///////////////////////////////////////////////////////////////////
				//�������� ����� ������ ����� �������, ����� ��� �������� �����
				//������� ��������� ������ �� ��������� ����� ��������, �� �����������
				//���� �� � �������� �������

		auto it_b2 = vChar2.rbegin();
		auto it_e2 = vChar2.rend();
		vector<char> vCharRev(it_b2, it_e2);
		//Print(vCharRev);
		//_SP


///////////////////////////////////////////////////////////////////

	//������� 1. ������. ��������, ����������� ��� �������.
	//�������� ������ ������ �� ��������� Point - ptList1 � ���������
	//��� ���������� � ������� ������� push_back(),
	//push_front, insert()
	
		list<Point>	ptList1;
		ptList1.push_back(Point(2, 2));
		ptList1.push_back(Point(3, 2));
		ptList1.push_back(Point(5, 1));
		ptList1.push_front(Point(4, 5));
		ptList1.push_front(Point(3, 7));
		ptList1.push_front(Point(1, 2));
		list<Point>::iterator itLb = ptList1.begin();
		++itLb;
		++itLb;
		ptList1.insert(itLb,Point(2, 3));

		


	//�������� ������ �������, ������� ����� �������� ��������
	//������ ���������� �� ������. ��������� ������ ������� �� �����������
	//vector � list. ��������� - �������� �� ������� ��� ����������.

		//PrintStat(ptList1);
		//Print(ptList1);
		//_SP

			//�������� ����� �� ������� "�����������" - reverse()
		//reverse(ptList1.begin(),ptList1.end());
		//Print(ptList1);
			//_SP
			//�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ���� 
			//������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
			//�� � �������� ������� (����������� ��� ��������������� ����������� ���������)

			list<Point> ptList2(ptList1.rbegin(), ptList1.rend());
		//Print(ptList2);
		//_SP







	//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
	//�� �����������.
	//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
	//�������� ���������� - operator<


	
		ptList1.sort();
		ptList2.sort();
	//	Print(ptList1);
		//_SP

			stop

			//���������� ��������������� ������ - merge(). ����������: ���
			//��� ���� ���������� � ������ �������.

			list<Point> sortesP(ptList1.size() + ptList2.size());

		merge(ptList1.begin(), ptList1.end(), ptList2.begin(), ptList2.end(),sortesP.begin());
		//Print(sortesP);
		//_SP

			stop
			//DeleteTwicy(sortesP);
		//Print(sortesP);
		//_SP

			//���������� �������� �� ������ - remove()
			//��������� �� ������ ������� � ������������ ���������.
			//���������: ��� ������ ���� ����������� � ������ Point?
			//Print(sortesP);
			//_SP
			sortesP.erase(remove(sortesP.begin(), sortesP.end(), Point(2, 2)), sortesP.end());

			//Print(sortesP);
			//_SP

	//���������� �������� �� ������, ���������������� ��������� �������:
	//����� �� ��������� ������������ - remove_if().

				//sortesP.erase(remove_if(sortesP.begin(), sortesP.end(), 
			//			[](Point obj) {return ((obj.GetX() < 3) || (obj.GetY() < 3));}), sortesP.end());
			//Print(sortesP);
			//_SP


	//���������� �� ������ ������ ������������� ������ - unique().
			//DeleteSeqs(sortesP);
			//PrintStat(sortesP);
			//Print(sortesP);
			//_SP
	

///////////////////////////////////////////////////////////////////
	//������� 2.������� � ����� ������� - ��������� deque

	//�������� ������ deque � ���������� ���� Point. � �������
	//assign ��������� deque ������� ��������� �������. � �������
	//�������������� ���� � ���������� ������� �������������� �������
	//�������� �������� ��������� �� ������

			deque<Point> deqPo;
			deqPo.assign(sortesP.begin(), sortesP.end());
		//	Print(deqPo);
		//	_SP


		//�������� deque � ���������� ���� MyString. ��������� ��� ����������
		//� ������� push_back(), push_front(), insert()
		//� ������� erase ������� �� deque ��� ��������, � ������� �������
		//���������� � 'A' ��� 'a'

				deque<MyString> deqStr;
			deqStr.push_back("a privet");
			deqStr.push_back("ku-ku");
			deqStr.push_back("BOOO");
			deqStr.push_front("A, neznau");
			deqStr.push_front("chashechka");
			deque<MyString>::iterator itD = deqStr.begin();
			++itD;
			deqStr.insert(itD, "uuuuu");
			Print(deqStr);
			_SP

				deqStr.erase(
					remove_if(deqStr.begin(), deqStr.end(),
						[](MyString obj) {return (!strncmp((obj.GetString()), "A",1) || !strncmp((obj.GetString()), "a",1));}),
					deqStr.end());
			Print(deqStr);
			_SP



  	return 0;
}