
#include<iostream>
using namespace std;

template<typename T>
class myunique_ptr
{
	private:
		T *ptr;
		void __cleanup__()
		{
			if(ptr != nullptr)
				delete ptr;
		}
	public:
		myunique_ptr():ptr(nullptr)
		{
			cout<<"Default const"<<endl;
		}
		myunique_ptr(T *ptr):ptr(ptr)
		{
			cout<<"Const is called "<<endl;
		}
		myunique_ptr(const myunique_ptr &obj) = delete;
		
		myunique_ptr& operator = (const myunique_ptr &obj) = delete;
		
		myunique_ptr(myunique_ptr &&obj)
		{
			this->ptr = obj.ptr;
			obj.ptr = nullptr;
		}
		
		void operator = (myunique_ptr && obj)
		{
			__cleanup__();
			this->ptr = obj.ptr;
			obj.ptr = nullptr;
		}
		
		int* operator -> ()
		{
			return this->ptr;
		}
		int & operator * ()
		{
			return *(this->ptr);
		}
		~myunique_ptr()
		{
			cout<<"destructor "<<endl;
			__cleanup__();
		}
};

class Box
{
private:
    int length, width, height;
public:
    Box()
    {
    	length = 1;
    	width = 2;
    	height = 3;
	}
	~Box()
	{
		cout<<"Destructor in box called"<<endl;
	}
	void show()
	{
		cout<<"area is "<<length*width*height<<endl;
	}
};

int main()
{
	myunique_ptr p(new int());
	*p = 20;
	cout<<*p<<endl;
	myunique_ptr obj1(new Box);
}
