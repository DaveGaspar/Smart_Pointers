#pragma once

#include <iostream>

template <typename T>
class shared_ptr
{
private:
	class Control_Block
	{
	public:
		T* m_ptr;
	private:
		unsigned int m_count;
	public:
		Control_Block(): m_count(1){
			m_ptr = nullptr;
		}
		Control_Block(T* t): m_count(1){
			m_ptr = t;
		}
		~Control_Block(){
			delete m_ptr;
			m_ptr = nullptr;
		}

		Control_Block(const Control_Block&) = delete;
		Control_Block& operator=(const Control_Block&) = delete;
		void operator ++(){
			m_count++;
		}
		void operator ++(int){
			m_count++;
		}
		unsigned int operator --(){
			m_count--;
			return m_count;
		}
		unsigned int operator --(int){
			m_count--;
			return m_count;
		}
	public:
		unsigned int get_count(){
			return m_count;
		}
	};

	Control_Block* m_cb_ptr;
	
private:
	void release(){
		if (nullptr != m_cb_ptr){
			if (0 == (*m_cb_ptr)--){
				delete m_cb_ptr;
				m_cb_ptr = nullptr;
			}
		}
	}

public:
	shared_ptr(){
		m_cb_ptr = nullptr;
	}

	explicit shared_ptr(T* t){
		m_cb_ptr = new Control_Block(t);
	}

	~shared_ptr(){
		release();
	}

	shared_ptr(const shared_ptr& obj){
		this->m_cb_ptr = obj.m_cb_ptr;
		if (nullptr != obj.m_cb_ptr){
			(*m_cb_ptr)++;
		}
	}
	shared_ptr& operator = (const shared_ptr& obj){
		if (this != &obj) {
            release();
            m_cb_ptr = obj.m_cb_ptr;
            if (m_cb_ptr != nullptr) {
                (*m_cb_ptr)++;
            }
        }
		return *this;
	}

	shared_ptr(shared_ptr&& obj){
		this->m_cb_ptr = obj.m_cb_ptr;
		obj.m_cb_ptr = nullptr;
	}

	shared_ptr& operator =(shared_ptr&& obj){
		if (this != &obj){
			release();
			this->m_cb_ptr = obj.m_cb_ptr;
			obj.m_cb_ptr = nullptr;
		}
		return *this;
	}
public:
	T* operator ->(){
		return m_cb_ptr->m_ptr; 
	}
	T& operator *(){
		return *(m_cb_ptr->m_ptr); 
	}
	T* get() const{
		return m_cb_ptr->m_ptr; 
	}
	unsigned int use_count(){
		return m_cb_ptr->get_count();
	}
};

template<typename T, typename... Args>
shared_ptr<T> make_shared(Args&&... args)
{
    return shared_ptr<T>(new T(std::forward<Args>(args)...));
}