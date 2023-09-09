#pragma once

#include <iostream>

template <typename T>
struct default_deleter{
	default_deleter() = default;
	default_deleter(const default_deleter&){}
	
	void operator()(T* ptr) const {
		delete ptr;
		ptr = nullptr;
	}
};



template <typename T, typename Deleter = default_deleter<T>>
class unique_ptr
{
private:
	T* m_ptr;
	Deleter deleter;
public:
	unique_ptr(){
		m_ptr = nullptr;
	}

	explicit unique_ptr(T* t): m_ptr(t){

	}

	~unique_ptr(){
		deleter(m_ptr);
	}

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator = (const unique_ptr&) = delete;

	unique_ptr(unique_ptr&& obj): m_ptr(obj.release()), deleter(obj.deleter){ }

	unique_ptr& operator =(unique_ptr&& obj){
		if (this != &obj){
			unique_ptr(std::move(obj)).swap(*this);
		}
		return *this;
	}
public:
	T* operator ->(){
		return m_ptr; 
	}
	T& operator *(){
		return *m_ptr; 
	}
	T* get() const{
		return m_ptr; 
	}
	T* release(){
		T* temp = m_ptr;
		m_ptr = nullptr;
		return temp;
	}
	void reset(T* ptr = nullptr){
		deleter(m_ptr);
		m_ptr = ptr;
	}
	void swap(unique_ptr& obj){
		std::swap(m_ptr, obj.m_ptr);
	}
};

template<typename T, typename... Args>
unique_ptr<T> make_unique(Args&&... args)
{
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}