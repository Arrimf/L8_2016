#pragma once

//#include <iostream>
//#include <tchar.h>

//template<typename T>
//std::ostream& operator<<(std::ostream& os, T& obj) {
//	os << typeid(obj).name() << std::endl << "Size: "\
//			<< obj.size() << "  Cap: " \
//			<< obj.capacity() << "   Max_size: "\
//			<< obj.max_size() << std::endl;
//		return os;
//}

template<typename T>
void PrintStat(const T& obj) {
	std::cout << typeid(obj).name() << std::endl << "Size: "\
			<< obj.size() << "  Cap: " \
			<< obj.capacity() << "   Max_size: "\
			<< obj.max_size() << std::endl;
		
}

template<typename T>
void Print(const T& obj) {
	auto it = obj.begin();
	while (it !=obj.end())
	{
		std::cout << *it<<std::endl;
		++it;
	}
	
	//std::cout << typeid(obj).name() << std::endl << "Size: "\
	//	<< obj.size() << "  Cap: " \
	//	<< obj.capacity() << "   Max_size: "\
	//	<< obj.max_size() << std::endl;

}