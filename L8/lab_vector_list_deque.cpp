//Стандартная библиотека шаблонов - STL 
	//Контейнеры стандартной библиотеки - vector
	//Итераторы
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
	// Контейнер стандартной библиотеки vector 

//////////////////////////////////////////////////////////////////////
	//Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 

	//std::vector<int> vInt;
	//std::cout << vInt.size()<<std::endl;

	//
	//_SP
	
	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте

	//vInt.push_back(1);
	//vInt.push_back(int());
	//vInt.front()=1;
	

	//std::cout << vInt.size() << std::endl;
	//PrintStat(vInt);

	//_SP

	//С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	//На каждой итерации цикла следите за размером вектора с помощью методов
	//size(), capacity(), max_size() и выводите значения элементов. 
	
		//for (int i = 0; i < 10; i++) {
		//	vInt.push_back(rand());
		//	PrintStat(vInt);
		//}
		//_SP

			//
			//Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
			//напишите шаблон функции, которая для вектора, содержащего элементы любого типа
			//выводит его "реквизиты" и значения элементов на консоль.



			//вектор вещественных - vDouble1 с заданным Вами начальным размером  и
			//проверьте результат с помощью созданного Вами шаблона. Как будут
			//проинициализированы элементы вектора?

			//std::vector<double>vDouble1(5);
			//PrintStat(vDouble1);
			//_SP


	//вектор объектов типа MyString с начальным размером - 5 элементов
	//и инициализацией каждого элемента строкой "A"
	//C помощью функции at() а также с помощью оператора
	//индексирования []  измените значения каких-либо элементов.
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. 

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



	//вектор вещественных - vDouble3, который является копией элементов
	// [0,5) массива вещественных чисел dMas. Предворительно массив dMas 
	//нужно создать и проинициализировать!
	
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

	//вектор вещественных - vDouble4, который является копией элементов
	// [2,5) вектора vDouble3. 

	std::vector<double>vDouble4(itb, ite);
//	_SP


	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?
	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).

	std::vector<Point>vPoint1(3);
	std::vector<Point>vPoint2(5, Point(1, 1));
	//_SP
	//вектор указателей на Point - vpPoint с начальным размером 5
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
	{
		std::vector<Point*>vpPoint(5);//, 
		int size = vpPoint.size();
		for (int i = 0; i < size;i++) {
		vpPoint[i] = new Point((87. / (rand() % 10 + 1)), (87. / (rand() % 10 + 1)));
		}

		//Print(vpPoint);
		//_SP
		CleanPoinerContainer(vpPoint);
			
	//Подсказка: для вывода на печать значений скорее всего Вам понадобится
		//а) специализация Вашей шаблонной функции
		//б) или перегрузка operator<< для Point*

	}//Какие дополнительные действия нужно предпринять для такого вектора? ///////////////////////////////////////////////////////////////////////?????????????????????????


	///////////////////////////////////////////////////////////////////////
	//Резервирование памяти.
	//Подумайте, всегда ли верны приведенные ниже проверки?
		
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
		//}//true? ///	только если m > n
		//_SP
		//}
		

		
		{
		vector<int> v(3,5);
		v.resize(4,10); //значения? {5,5,5,10}
		v.resize(5); //значения? {5,5,5,10,0}
		//Print(v);
		//_SP
		}
		

	//Создайте два "пустых" вектора с элементами
	//любого типа. 
	//В первом векторе зарезервируйте память под 5 элементов, а потом заполните
	//его значениями с помощью push_back.
	//Второй вектор просто заполните значениями посредством push_back.
	//
	//Сравните размер, емкость векторов и значения элементов


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

	
	//Создание "двухмерного вектора" - вектора векторов
	//Задан одномерный массив int ar[] = {11,2,4,3,5};
	//Создайте вектор векторов следующим образом:
	//вектор vv[0] - содержит 11 элементов со значением 11
	//vv[1] - содержит 2,2
	//vv[2] - содержит 4,4,4,4
	//...
	//Распечатайте содержимое такого двухмерного вектора по строкам
	
	 int ar[] = { 11,2,4,3,5 };

	 //ar::iterator<int> it ;
	//it = &ar;

	 //vector<vector< int>> vv(sizeof(ar)/sizeof(int), vector<int>(*ar,*ar));
	 vector<vector< int>> vv((ar),(ar+5));       ////////////////////////////////////////////// печаль =((
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
	
	//Вставка элемента последовательности insert().
	//В вектор vChar2 вставьте в начало вектора символ только при
	//условии, что в векторе такого еще нет.


	 vector<char> vChar2(2,'T');
	 //vChar2::value_type;
		 //vector<char>::iterator it_e = vChar2.end();
		 Insert_if_absent(vChar2, 'Q');
		 Insert_if_absent(vChar2, 'Q');
	//	 Print(vChar2);
	//	 _SP
			 // *it_e='P';


		 //Вставьте перед каждым элементом вектора vChar2 букву 'W'

		 vector<char>::iterator it_b = vChar2.begin();
		 vector<char>::iterator it_e = vChar2.end();

		while (it_b != it_e){
			it_b = vChar2.insert(it_b, 'W');
				++it_b;
				++it_b;
				it_e = vChar2.end();
		}
		//_SP;
	


	//Сотрите только повторяющиеся последовательности символов.
	//Например: было - "qwerrrrty", стало - "qwety"

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

				//Удаление элемента последовательности erase()
				//Напишите функцию удаления из любого вектора всех дублей 

			DeleteTwicy(vChar2);
			//_SP
			//Print(vChar2);
	//Уберите лишние пробелы в vector<char>

			
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
				//Создайте новый вектор таким образом, чтобы его элементы стали
				//копиями элементов любого из созданных ранее векторов, но расположены
				//были бы в обратном порядке

		auto it_b2 = vChar2.rbegin();
		auto it_e2 = vChar2.rend();
		vector<char> vCharRev(it_b2, it_e2);
		//Print(vCharRev);
		//_SP


///////////////////////////////////////////////////////////////////

	//Задание 1. Списки. Операции, характерные для списков.
	//Создайте пустой список из элементов Point - ptList1 и наполните
	//его значениями с помощью методов push_back(),
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

		


	//Напишите шаблон функции, которая будет выводить элементы
	//ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
	//vector и list. Подсказка - хотелось бы увидеть тип контейнера.

		//PrintStat(ptList1);
		//Print(ptList1);
		//_SP

			//Сделайте любой из списков "реверсивным" - reverse()
		//reverse(ptList1.begin(),ptList1.end());
		//Print(ptList1);
			//_SP
			//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
			//копией вектора элементов типа Point, но значения элементов списка располагались
			//бы в обратном порядке (используйте при конструировании реверсивные итераторы)

			list<Point> ptList2(ptList1.rbegin(), ptList1.rend());
		//Print(ptList2);
		//_SP







	//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
	//по возрастанию.
	//Подумайте: что должно быть перегружено в классе Point для того, чтобы
	//работала сортировка - operator<


	
		ptList1.sort();
		ptList2.sort();
	//	Print(ptList1);
		//_SP

			stop

			//Объедините отсортированные списки - merge(). Посмотрите: что
			//при этом происходит с каждым списком.

			list<Point> sortesP(ptList1.size() + ptList2.size());

		merge(ptList1.begin(), ptList1.end(), ptList2.begin(), ptList2.end(),sortesP.begin());
		//Print(sortesP);
		//_SP

			stop
			//DeleteTwicy(sortesP);
		//Print(sortesP);
		//_SP

			//Исключение элемента из списка - remove()
			//Исключите из списка элемент с определенным значением.
			//Подумайте: что должно быть перегружено в классе Point?
			//Print(sortesP);
			//_SP
			sortesP.erase(remove(sortesP.begin(), sortesP.end(), Point(2, 2)), sortesP.end());

			//Print(sortesP);
			//_SP

	//Исключение элемента из списка, удовлетворяющего заданному условию:
	//любая из координат отрицательна - remove_if().

				//sortesP.erase(remove_if(sortesP.begin(), sortesP.end(), 
			//			[](Point obj) {return ((obj.GetX() < 3) || (obj.GetY() < 3));}), sortesP.end());
			//Print(sortesP);
			//_SP


	//Исключение из списка подряд расположенных дублей - unique().
			//DeleteSeqs(sortesP);
			//PrintStat(sortesP);
			//Print(sortesP);
			//_SP
	

///////////////////////////////////////////////////////////////////
	//Задание 2.Очередь с двумя концами - контейнер deque

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать

			deque<Point> deqPo;
			deqPo.assign(sortesP.begin(), sortesP.end());
		//	Print(deqPo);
		//	_SP


		//Создайте deque с элементами типа MyString. Заполните его значениями
		//с помощью push_back(), push_front(), insert()
		//С помощью erase удалите из deque все элементы, в которых строчки
		//начинаются с 'A' или 'a'

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