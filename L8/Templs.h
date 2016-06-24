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
void Print(T& obj) {

	auto it = obj.begin();
	while (it != obj.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
}

template<typename T, typename P= typename T::value_type>
void PrintVoid( T& obj, P& ) {
	
	auto it = obj.begin();
	while (it !=obj.end())
	{
		std::cout << static_cast<P*>(*it)<<std::endl;
		++it;
	}
	
	//std::cout << typeid(obj).name() << std::endl << "Size: "\
	//	<< obj.size() << "  Cap: " \
	//	<< obj.capacity() << "   Max_size: "\
	//	<< obj.max_size() << std::endl;

}
template<typename C, typename T>
	bool FindVal(C& container, T& val) {
		if (typeid(val) == typeid(*container)) {
			auto it_b = container.begin();
			auto it_e = container.end()
				while (it_b != it_e) {
					if (*it_b == val) {
						return true;
					}
					else { ++it_b; }
				}
		}
	return false;
}

template<typename C, typename T>
	bool Insert_if_absent(C& container, T& val) {
		if (FindVal(container, val)) { 
			return false;
		}
	container.insert(val);
	return true;
}