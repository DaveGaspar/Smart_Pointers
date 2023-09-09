#include <iostream>
#include "auto_ptr.h"
#include "unique_ptr.h"

class A
{
private:
	int m_val = 0;
public:
	A() = delete;
	A(int a): m_val(a){
		std::cout << __func__ << std::endl;	
	}
	~A(){
		std::cout << __func__ << std::endl;	
	}
public:
	void set_val(int val){
		m_val = val;
	}
	int get_val(){
		return m_val;
	}
};

int main(){
	
	auto obj = make_unique<A>(5);

	unique_ptr<A> obj2 = make_unique<A>(7);
	std::cout << "Val1 = " << obj->get_val() << std::endl;
	std::cout << "Val2 = " << obj2->get_val() << std::endl;

	obj2 = std::move(obj);

	// std::cout << "Val1 = " << obj->get_val() << std::endl;
	std::cout << "Val2 = " << obj2->get_val() << std::endl;

	return 0;
}