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
	std::cout << typeid(obj).name() << std::endl << 
		"Size: " << obj.size() << \
		//"  Cap: " << obj.capacity() << 
		"   Max_size: "<< obj.max_size() << std::endl;		
}
template<typename  T>
void PrintVector(const std::vector<T>& obj) {
	int size = obj.size();
	for (int i = 0; i < size; i++){
		std::cout << obj[i] << std::endl;
	}
}

template<typename T>
void Print(const T& obj) {

	auto it = obj.begin();
	int size = obj.size();
	for (int i = 0; i < size; i++)	{
		std::cout << *it << std::endl;
		++it;
	}
}

template<typename T, typename P= typename T::value_type>
void PrintVoid(const T& obj ) {
	
	auto it = obj.begin();
	int size = obj.size();
	for (int i = 0; i < size; i++) {
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
	bool DefineSeq(T& it) { /// как записать именно(исключительно) итератор?!... - никак... =(((
		auto tmp = it;
		
		do {
			++tmp;
		} while (*it == *tmp);

		if (it == --tmp) {			
			return  false;
		}
		it = ++tmp;			//////?????
		return true;
	}

	template<typename K>
	void DeleteSeqs(K& container) {
		auto it_b = container.begin();
		auto it_e = --container.end();

		while (it_b != it_e) {
			auto itTmp = it_b;
			if (DefineSeq(itTmp)) {
				it_b = container.erase(it_b, itTmp);
				it_e = --container.end();
			}
			else {
				++it_b;
			}
		}
	}
	


	

	template<typename K>
	void DeleteTwicy(K& container) {
		auto it_val = container.begin();
		auto it_e_1 = --container.end() ;

		while (it_val != it_e_1) {
			auto it_runner = std::next(it_val);
			auto it_e = container.end();
			while (it_runner != it_e) {
				if (*it_val == *it_runner) {
					it_runner = container.erase(it_runner);
					it_e = container.end();
					it_e_1 = std::prev(it_e);
				}
				else{
					++it_runner;
				}
			}
		 ++it_val;
		}
	}

	template<typename K>
	void DelExcesSpaces(K& container) {
		auto it_val = container.begin();
		auto it_e_1 = --container.end() ;
		while (it_val != it_e_1) {
			if (*it_val == ' ') {
				auto tmp = it_val;
				if (DefineSeq(tmp)) {
					it_val = container.erase(++it_val, tmp);
					it_e_1 = --container.end();
				}
			}
			++it_val;
		}
	}

	template<typename K>
	void CleanPoinerContainer(K& container) {
		auto it_runner = container.begin();
		auto it_e = container.end();
		while (it_runner != it_e){
			delete *it_runner;
			++it_runner;
		}
	}