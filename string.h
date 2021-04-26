#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <cassert>
//简易的string

//#include <string>
//
//namespace zzh
//{
//	class string
//	{
//	public:
//		/*string()
//			:_str(nullptr)  不能给nullptr
//		{}
//		string(const char* str)
//			:_str(new char[strlen(str) + 1])
//		{
//			memcpy(_str, str, strlen(str) + 1);
//		}*/
//		/*string()
//			:_str(new char[1])
//		{
//			_str[0] = '0';
//		}*/
//		string(const char* str = "") //缺省值不能为nullptr 不然空对象无法解引用
//			:_str(new char[strlen(str) + 1]) //string s2; s2无法使用size
//		{
//			memcpy(_str, str, strlen(str) + 1);
//		}
//		//拷贝构造  s3(s1) 深拷贝 ，拷贝空间
//		string(const string& s)
//			:_str(new char[strlen(s._str) + 1])
//		{
//			memcpy(_str, s._str, strlen(s._str) + 1);
//		}
//		//赋值重载  s1 = s2
//		/*const string& operator=(const string& s)
//		{
//			delete[] _str;
//			_str = new char[strlen(s._str) + 1];
//			memcpy(_str, s._str, strlen(s._str) + 1);
//			return *this;
//		 }*/
//		string& operator=(const string& s)
//		{
//			if (&s != this)  //防止自己给自己赋值
//			{
//				char* tmp = new char[strlen(s._str) + 1];
//				memcpy(tmp, s._str, strlen(s._str) + 1);
//				delete[] _str;
//				_str = tmp;
//			}
//			return *this;
//		}
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//		size_t size()
//		{
//			return strlen(_str);
//		}
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//		char* c_str()
//		{
//			return _str;
//		}
//	private:
//		char* _str;
//	};
//
//	void test_string1()
//	{
//		string s1("hello");
//		for (size_t i = 0; i < s1.size(); ++i)
//		{
//			s1[i] += 1;
//			cout << s1[i] << " ";
//		}
//		cout << endl;
//		cout << s1.c_str() << endl;
//		string s3(s1);
//		cout << s3.c_str() << endl;
//		string s4;
//		
//		
//		cout << s3.c_str() << endl;
//	}
//}

namespace zzh
{
	class string
	{
	public:
		typedef char* iterator;

		string(const char* str = "")
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
			_size = _capacity = strlen(str);
		}
		/*string(const string& s)
		{
			_size = strlen(s._str);
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, s._str);
		}*/
		/*void Swap(string& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}*/
		void swap(string& s)
		{
			::swap(_str, s._str); //加上域作用限定符，表示调用全局的swap
			::swap(_size, s._size); //否则调用这个类的swap
			::swap(_capacity, s._capacity);
		}
		//现代写法 拷贝构造
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			//Swap(tmp);
			swap(tmp);
		 }
		//传统写法 s1 = s2
		/*string& operator=(const string& s)
		{

			if (this != &s)
			{
				char* tmp = new char[strlen(s.c_str()) + 1];
				strcpy(tmp, s.c_str());
				delete[] _str;
				_str = tmp;
				_size = s.size();
				_capacity = s.capacity();
			}
			return *this;
		}*/

		//现代写法 
		string& operator=(string s)
		{
			//Swap(s);
			swap(s);
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		size_t size() const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
		}
		char& operator[](size_t i)
		{
			return _str[i];
		}
	  const	char& operator[](size_t i) const
		{
			return _str[i];
		}
		iterator begin() //迭代器
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		void reserve(size_t n = 0)
		{
			assert(n >= _capacity);
			
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
		/*void resize(size_t n)
		{
			if (n <= _size)
			{
				_str[n] = '\0';			
			}
			else
			{
				reserve(n);
			}
			_size = n;
		}
		void resize(size_t n, char c)
		{
			size_t t = _size;
			resize(n);
			if (n > t)
			{
				_size = t;
				size_t count = n - t;
				while (count--)
				{
					_str[_size] = c;
					++_size;
				}
				_str[_size] = '\0';
			}
		}*/
		//改变size
		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				_str[_size] = '\0';
				_size = n;
			}
			else
			{
				if (n > _capacity)
					reserve(n);
				size_t end = n;
				while (_size < end)
				{
					_str[_size] = ch;
					++_size;
				}
				_str[_size] = '\0';
			}
		}
		//插入
		void push_back(const char& c)
		{
			//增容
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}
			   _str[_size] = c;
			   ++_size;
			   _str[_size] = '\0';
		}
		void append(const char* ch)
		{
			int len = strlen(ch);
			if (_capacity < _size + len)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, ch);
			_size = _size + len;

		}
		string& operator+=(const char& c)
		{
			push_back(c);
			return *this;
		}
		string& operator+=(const char* ch)
		{
			append(ch);
			return *this;
		}
		string& operator+=(const string& s)
		{

		}
		void insert(size_t pos, char ch) //可以用insert复写push_back,append,
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}

			int end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}
			_str[pos] = ch;
			++_size;
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_capacity < _size + len)
			{
				size_t newcapacity = _size + len;
				reserve(newcapacity);
			}
			int end = _size;   //不能
			while (end >= (int)pos)  //这里加上强转成int，不然end会转换成size_t
				                        //不然insert 0，end变成-1后就会有问题
			{
				_str[end + len] = _str[end];
				--end;
			}
			//strcpy(_str + _size, str); //不能用strcpy，因为strcpy会将str的'\0'拷贝过去
			strncpy(_str + pos, str, len);	//导致覆盖掉一个字符
			_size += len;           
			return *this;
		}
		const char* c_str() const
		{
			return _str;
		}
		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (pos + len > _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t end = pos + len;
				while (end <= _size)
				{
					_str[end - len] = _str[end];
					++end;
				}
				_size -= len;
			}
			return *this;
		}
		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < size(); ++i)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		size_t find(const char* str, size_t pos = 0)
		{
			char* ptr = strstr(_str + pos, str);
			if (ptr != nullptr)
			{
				return ptr - _str;
			}
			return npos;
		}
		void clear()
		{
			delete[] _str;
			_size = _capacity = 0;
		}

		//比较大小 s1 < s2
		bool operator<(const string& s)
		{
			size_t ret = strcmp(_str, s.c_str());
			return ret < 0;
		}
		bool operator==(const string& s)
		{
			size_t ret = strcmp(_str, s.c_str());
			return ret == 0;
		}
		bool operator<=(const string& s)
		{
			return (*this < s) || (*this == s);
		}
		bool operator>(const string& s)
		{
			return !(*this <= s);
		}
		bool operator>=(const string& s)
		{
			return !(*this < s);
		}
		bool operator!=(const string& s)
		{
			return !(*this == s);
		}
	private:
		char* _str;
		size_t _size; //已经放的有效字符数
		size_t _capacity; //可以放的有效字符数

		static size_t npos;
	};
	size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s)
	{
		size_t i = 0;
		for (i = 0; i < s.size(); ++i)
		{
			out << s[i];
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		char ch;
		while (1)
		{
			ch = in.get(); //这里不能用in 因为in无法接收到空格和换行符
			if (ch == ' ' || ch == '\n')//去掉ch == ' '就是getline
			{
				break;
			}
			s += ch;
		}
		return in;
	}
	void string_test1()
	{
		string s1("hello");
		string s2(s1);
	}
}

namespace bit
{
	class string
	{
	public:
		
		string(const char* str = "")
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);
		}
		//拷贝构造 /传统写法
		/*string(const string& s)
		{
			char* tmp = new char[strlen(s._str) + 1];
			_str = tmp;
			strcpy(_str, s.c_str());
		}*/
		string(string& s)
			:_str(nullptr)
		{
			string tmp(s.c_str());
			swap(_str, tmp._str);
			
		}

		/*string& operator=(const string& s)
		{
			
			if (_str != s._str)
			{
				char* tmp = new char[strlen(s.c_str()) + 1];
				strcpy(tmp, s.c_str());
				delete[] _str;
				_str = tmp;
			}
			return *this;
		}*/
		// s1 = s2
		/*string& operator=(const string& s)
		{
			if(this != &s)
			{
			  string tmp(s);
			  swap(_str, tmp._str);
			}
			return *this;
		}*/
		//现代写法
		string& operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			
		}
		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
	};
	void test_string()
	{
		string s1("hello");
		string s2(s1);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		string s3;
		s3 = s2;
		
		cout << s3.c_str() << endl;
	}
}

