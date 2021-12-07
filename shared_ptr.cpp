#include<iostream>
using namespace std;

template<typename T>
class shared_ptr
{
	T *ptr;
	unsigned int *refcount;
	public:
	shared_ptr():ptr(nullptr),refcount(new unsigned int(0))
	{
	}
	shared_ptr(T *p):ptr(p), refcount(new unsigned int(1))
	{
	}
	shared_ptr(const shared_ptr& source)
	{
		this->ptr = source.ptr;
		this->refcount = source.refcount;
		if(source.ptr != nullptr)
			(*this->refcount)++;
	}
	shared_ptr& operator=(const shared_ptr& source)
	{
	
	refcount--;
	if(refcount == 0)
	{
	if(ptr != nullptr)
	delete ptr;
	delete refcount;
	}
	
	this->ptr = source.ptr;
	this->refcount = source.refcount;
	if(source.ptr != nullptr)
	*(this->refcount)++;
	}
	shared_ptr(shared_ptr &&source)
	{
	this->ptr = source.ptr;
	this->refcount = source.refcount;
	source.ptr = source.refcount = nullptr;
	}
	shared_ptr&& operator=(shared_ptr &&source)
	{
	this->ptr = source.ptr;
	this->refcount = source.refcount;
	source.ptr = source.refcount = nullptr;
	}
	unsigned int get_count()
	{
	return *refcount;
	}
	T* operator->()
	{
	return this->ptr;
	}
	T& operator*()
	{
	return *ptr;
	}
};

int main()
{
	shared_ptr<int> obj1(new int);
	*obj1 = 20;
	shared_ptr<int> obj2 = obj1;
	unsigned int res = obj2.get_count();
	cout<<res;
}
