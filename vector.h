#pragma once
#include <cassert>
#include <string>
namespace zzh
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		vector(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			_finish = _start;   //这样遍历完一遍后，_finish正好在它的位置
			_endofstorage = _start + v.capacity();
			for (size_t i = 0; i < v.size(); ++i) //这个地方可以用memcpy
			{
				*_finish = v[i];
				++_finish;
			}
		}
		/*vector(const vector<T>& v)   //拷贝构造现代写法
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)   
		{
			reserve(v.capacity());
			for (const auto& e : v)
			{
				push_back(e);
			}
		}*/
		// v1 = v2
		/*vector<T>& operator=(const vector<T>& v)  //赋值的传统写法
		{
			if (this != &v)
			{
				iterator tmp = new T[v.capacity()];
				delete[] _start;
				_start = tmp;
				_finish = _start + v.size();
				_endofstorage = _start + v.capacity();
				memcpy(_start, v._start, sizeof(T) * v.size());
			}
			return *this;
		}*/
		void swap(vector<T>& v)  //这里不使用内置的swap(v1,v2);因为需要三次拷贝构造，
		{                         //代价太大  建议使用 swap(v2);
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endofstorage, v._endofstorage);
		}
		vector<T>& operator=(vector<T> v)  //拷贝构造的现代写法
		{
			swap(v);
			return *this;
		}
		~vector()  //析构
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		void reserve(size_t n)
		{
			size_t sz = size();
			iterator tmp = new T[n];
			if (_start)
			{
				//memcpy(tmp, _start, sz * sizeof(T)); //究极深拷贝
				for (size_t i = 0; i < sz; ++i)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;
			} 
			_start = tmp;
			_finish = _start + sz;
			_endofstorage = _start + n;
		}
		void resize(size_t n, const T& val = T())//给模板的缺省值
		{
			if (n <= size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				
					reserve(n);
				}
				while(_finish != _endofstorage)
				{
					*_finish = val;
					++_finish;
			    }

		}
		/*void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;
		}*/
		void push_back(const T& x)
		{
			insert(_finish, x);
		}
		void pop_back()
		{
			assert(size() > 0);
			--_finish;
		}
		void insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t sz = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + sz;
			}
			iterator it = _finish;
			while (it != pos)
			{
				*it = *(it - 1);
				--it;
			}
			*pos = x;
			++_finish;
		}
		void insert(size_t n, const T& x)
		{
			iterator pos = _start + n;
			insert(pos, x);
		}
		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			 iterator it = pos;
			while (it != _finish)
			{
				*it = *(it + 1);
				++it;
			}
			--_finish;
			return pos;
			
		}
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _endofstorage - _start;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _endofstorage - _start;
		}
		T& operator[](size_t i)
		{
			return *(_start + i);
		}
		const T& operator[](size_t i) const
		{
			return *(_start + i);
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	//template<class T>
	void vector_print(const vector<int>& v)
	{
		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	void test_vector()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(30);
		v.push_back(25);
		v.push_back(10);
		v.push_back(4);
		v.push_back(2);
		vector_print(v);

		vector<int> v1(v);
		vector<int> v2;
		v2 = v1;
		vector_print(v1);
		vector_print(v2);

	}
	void test_vector2()
	{
		int a = int();
		int b(1);
		
		cout << a <<" " << b << endl;
		double c = double();
		double d(1.1);
		cout <<"c = "<< c << " ";
		cout << "d = " << d << " ";

	}
	void test_vector3()
	{
		vector<string> v;
		v.push_back("11111111111111111111");
		v.push_back("222222222222222222");
		v.push_back("3333333");
		v.push_back("444444");
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}