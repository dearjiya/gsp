#include <doctest/doctest.h>

#include <vector>

namespace temp
{
template<typename T>
class Vector
{
public:
	// ������
	Vector(int n = 1)
		: data_{ new T[n] }
		, capacity_{ n }
		, length_{ 0 }
	{
	}

	// �� �ڿ� ���ο� ���Ҹ� �߰��Ѵ�
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

	// ������ ��ġ�� ���ҿ� �����Ѵ�
	T operator

		// x��° ��ġ�� ���Ҹ� �����Ѵ�
		// ���� ������ ũ�⸦ ���Ѵ�
		// �Ҹ���
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