#pragma once

template <typename T>
class auto_ptr
{
private:
	T* m_ptr;
public:
	auto_ptr(){
		m_ptr = nullptr;
	}

	explicit auto_ptr(T* t): m_ptr(t){

	}
	~auto_ptr(){
		delete m_ptr;
		m_ptr = nullptr;
	}
	auto_ptr(const auto_ptr&) = delete;
	auto_ptr& operator = (const auto_ptr&) = delete;

public:
	T* operator ->(){
		return m_ptr; 
	}
	T& operator *(){
		return *m_ptr; 
	}
};