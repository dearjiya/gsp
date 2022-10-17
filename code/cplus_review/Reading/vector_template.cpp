#include <doctest/doctest.h>

#include<iostream>
#include<string>
#include <vector>

namespace temp
{
template<typename T>
class Vector
{
public:
	// 생성자
	Vector(int n = 1)
		: data_{ new T[n] }
		, capacity_{ n }
		, length_{ 0 }
	{
	}

	// 맨 뒤에 새로운 원소를 추가한다
	void push_back(T s)
	{
		if (capacity_ <= length_)
		{
			T* temp = new T[capacity_ * 2];
			for (int i = 0; i < length_; i++)
			{
				temp[i] = data_[i];
			}
			delete[] data_;
			data_ = temp;
			capacity_ *= 2;
		}
		data_[length_] = s;
		length_++;
	}

	// 임의의 위치의 원소에 접근한다
	T operator[] (int i)
	{
		return data_[i];
	}

	// x번째 위치한 원소를 제거한다
	void remove(int x)
	{
		for (int i = x + 1; i < length_; i++)
		{
			data_[i - 1] = data_[i];
		}
		length_--;
	}

	// 현재 벡터의 크기를 구한다
	int size()
	{
		return length_;
	}

	void swap(int i, int j)
	{
		T temp = data_[i];
		data_[i] = data_[j];
		data_[j] = temp;
	}

	// 소멸자
	~Vector()
	{
		if (data_)
		{
			delete[] data_;
		}
	}
private:
	T* data_;
	int capacity_;
	int length_;
};

template <typename Cont>
void bubble_sort(Cont& cont)
{
	for (int i = 0; i < cont.size(); i++)
	{
		for (int j = i + 1; j < cont.size(); j++)
		{
			if (cont[i] > cont[j])
			{
				cont.swap(i, j);
			}
		}
	}
}

template<typename Cont, typename Comp>
void bubble_sort(Cont& cont, Comp& comp)
{

}

// bool 타입에 대한 템플릿 특수화
template<>
class Vector<bool>
{
public:
	Vector(int n = 1)
		: data_{ new unsigned int[n / 32 + 1] }, capacity_{ n / 32 + 1 }, length_{ 0 }
	{
		for (int i = 0; i < capacity_; i++)
		{
			data_[i] = 0;
		}
	}

	void push_back(bool s)
	{
		if (capacity_ * 32 <= length_)
		{
			unsigned int* temp = new unsigned int[capacity_ * 2];
			for (int i = 0; i < capacity_; i++)
			{
				temp[i] = data_[i];
			}
			for (int i = capacity_; i < 2 * capacity_; i++)
			{
				temp[i] = 0;
			}
			delete[] data_;
			data_ = temp;
			capacity_ *= 2;
		}

		if (s)
		{
			data_[length_ / 32] |= (1 << (length_ % 32));
		}
		length_++;
	}

private:
	unsigned int* data_;
	int capacity_;
	int length_;
};
}

TEST_CASE("vector_template")
{
	std::cout << "--------<vector_template>---------" << std::endl;
	SUBCASE("")
	{
		temp::Vector<int> int_vec;
		int_vec.push_back(3);
		int_vec.push_back(2);
		std::cout << "-----int_vec-----" << std::endl;
		std::cout<< "첫번째 원소: " << int_vec[0] << std::endl;
	}

	SUBCASE("")
	{
		temp::Vector<std::string> str_vec;
		str_vec.push_back("hello");
		str_vec.push_back("world");
		std::cout << "-----str_vec-----" << std::endl;
		std::cout << "첫번째 원소: " << str_vec[0] << std::endl;
	}
}