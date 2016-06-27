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
		auto it_val = container.begin();
		auto it_e_1 = container.end() - 1;

		while (it_val != it_e_1) {
			auto it_runner = it_val + 1;
			auto it_e = container.end();
			while (it_runner != it_e) {
				if (*it_val == *it_runner) {
					auto tmp = it_runner - 1;
					container.erase(it_runner);
					it_runner = tmp;
					it_e = container.end();
					it_e_1 = it_e - 1;
				}
				++it_runner;
			}
		 ++it_val;
		}
	}

	template<typename K>
	void DelExcesSpaces(K& container) {
		auto it_val = container.begin();
		auto it_e_1 = container.end() - 1;
		while (it_val != it_e_1) {
			if (*it_val == ' ') {
				if (int i = DefineSeq(it_val)) {
					auto it_tmp = it_val - 1;
					container.erase(it_val, it_val + --i);
					it_val = it_tmp;
					it_e_1 = container.end() - 1;
				}
			}
			++it_val;
		}
	}