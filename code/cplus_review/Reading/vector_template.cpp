#include <doctest/doctest.h>

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
			T* temp = new T[capacity * 2];
			for (int i = 0; i < length_; i++)
			{
				temp[i] = data_[i];
			}
			delete[] data_;
			data_ = temp;
			capacity_ *= 2;
		}
		data[length_] = s;
		length_++;
	}

	// 임의의 위치의 원소에 접근한다
	T operator

		// x번째 위치한 원소를 제거한다
		// 현재 벡터의 크기를 구한다
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
}

TEST_CASE("vector_template")
{
	SUBCASE("")
	{
	}
}