#include <iostream>
#include "auto_ptr.h"
#include "unique_ptr.h"
#include "shared_ptr.h"

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
	
	// auto obj = make_unique<A>(5);

	// unique_ptr<A> obj2 = make_unique<A>(7);
	// std::cout << "Val1 = " << obj->get_val() << std::endl;
	// std::cout << "Val2 = " << obj2->get_val() << std::endl;

	// obj2 = std::move(obj);

	// // std::cout << "Val1 = " << obj->get_val() << std::endl;
	// std::cout << "Val2 = " << obj2->get_val() << std::endl;


	auto obj = make_shared<A>(7);
	shared_ptr<A> obj2 = obj;
	shared_ptr<A> obj3 = make_shared<A>(9);
	
	std::cout << "Val1 = " << obj->get_val() << std::endl;
	std::cout << "Val2 = " << obj2->get_val() << std::endl;
	std::cout << "Val3 = " << obj3->get_val() << std::endl;
	std::cout << "Count1 = " << obj.use_count() << std::endl;
	std::cout << "Count2 = " << obj2.use_count() << std::endl;
	std::cout << "Count3 = " << obj3.use_count() << std::endl;

	obj3 = std::move(obj);
	// std::cout << "Val1 = " << obj->get_val() << std::endl;
	std::cout << "Val2 = " << obj2->get_val() << std::endl;
	std::cout << "Val3 = " << obj3->get_val() << std::endl;
	// std::cout << "Count1 = " << obj.use_count() << std::endl;
	std::cout << "Count2 = " << obj2.use_count() << std::endl;
	std::cout << "Count3 = " << obj3.use_count() << std::endl;

	//tests
	// auto obj1 = make_shared<A>(5);
	// auto obj2(obj1);
	// auto obj3 = make_shared<A>(7);
	// auto obj4(obj3);
	// auto obj5(obj2);
	// auto obj6(obj2);

	// std::cout << "Obj1 = " << obj1->get_val() << std::endl;
	// std::cout << "Obj2 = " << obj2->get_val() << std::endl;
	// std::cout << "Obj3 = " << obj3->get_val() << std::endl;
	// std::cout << "Obj4 = " << obj4->get_val() << std::endl;
	// std::cout << "Obj5 = " << obj5->get_val() << std::endl;
	// std::cout << "Obj6 = " << obj6->get_val() << std::endl;

	// std::cout << std::endl;

	// std::cout << "Count1 = " << obj1.use_count() << std::endl;	
	// std::cout << "Count2 = " << obj2.use_count() << std::endl;
	// std::cout << "Count3 = " << obj3.use_count() << std::endl;
	// std::cout << "Count4 = " << obj4.use_count() << std::endl;
	// std::cout << "Count5 = " << obj5.use_count() << std::endl;
	// std::cout << "Count6 = " << obj6.use_count() << std::endl;


	// obj2 = obj3;
	// obj3 = std::move(obj6);

	// std::cout << std::endl;

	// std::cout << "Obj1 = " << obj1->get_val() << std::endl;
	// std::cout << "Obj2 = " << obj2->get_val() << std::endl;
	// std::cout << "Obj3 = " << obj3->get_val() << std::endl;
	// std::cout << "Obj4 = " << obj4->get_val() << std::endl;
	// std::cout << "Obj5 = " << obj5->get_val() << std::endl;
	// // std::cout << "Obj6 = " << obj6->get_val() << std::endl;

	// std::cout << std::endl;

	// std::cout << "Count1 = " << obj1.use_count() << std::endl;	
	// std::cout << "Count2 = " << obj2.use_count() << std::endl;
	// std::cout << "Count3 = " << obj3.use_count() << std::endl;
	// std::cout << "Count4 = " << obj4.use_count() << std::endl;
	// std::cout << "Count5 = " << obj5.use_count() << std::endl;
	// // std::cout << "Count6 = " << obj6.use_count() << std::endl;

	return 0;
}