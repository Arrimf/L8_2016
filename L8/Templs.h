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
template<typename It, typename V>
bool FindVal2(It& beg, It& en, V& val) {
	if (typeid(val) == typeid(*beg)) {
		++beg;
		while (beg != en) {
			if (*beg == val) {
				return true;
			}
			else { ++beg; }
		}
	}
	return false;
}

template<typename C, typename T>
	bool FindVal(C& container, T& val) {
		if (typeid(val) == typeid(C::value_type)) {   ////////?????
			auto it_b = container.begin();
			auto it_e = container.end();
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
	int FindDelAll(C& container, T val) {   //// && - ?
		int cnt = 0;
		if (typeid(val) == typeid(C::value_type)) {   ////////?????
			auto it_b = container.begin() + 1;
			auto it_e = container.end();
			while (it_b != it_e) {
				if (*it_b == val) {
					auto tmp = it_b - 1;
					container.erase(it_b);
					it_b = ++tmp;
					it_e = container.end();
					cnt++;
				}
				else { ++it_b; }
			}
		}
		return cnt;
	}

	template<typename C, typename T>
	bool Insert_if_absent(C& container,const T& val) {   //// && - ?
		if (FindVal(container, val)) {
			return false;
		}
		container.insert(container.begin(), val);
		return true;
	}

	template<typename T>
	int DefineSeq(T it) { /// как записать именно(исключительно) итератор?!...
		auto tmp = it+1;
		int cnt = 0;
		while (*it ==*tmp){
			++tmp;
			++cnt;
		}
		if (cnt) {
			return cnt + 1;
		}
		return cnt;
	}
	template<typename K>
	void DeleteTwicy(K& container) {
		auto it_b = container.begin();
		auto it_e = container.end()-1;
		while (it_b != it_e) {
			FindDelAll(container, *it_b);
			 ++it_b;
		}
	}


