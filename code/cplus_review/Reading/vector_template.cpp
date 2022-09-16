//#include <doctest/doctest.h>
//
//#include <vector>
//
//namespace temp
//{
//template<typename T>
//class Vector
//{
//public:
//	// ������
//	Vector(int n = 1)
//		: data_{ new T[n] }
//		, capacity_{ n }
//		, length_{ 0 }
//	{
//	}
//
//	// �� �ڿ� ���ο� ���Ҹ� �߰��Ѵ�
//	void push_back(T s)
//	{
//		if (capacity_ <= length_)
//		{
//			T* temp = new T[capacity * 2];
//			for (int i = 0; i < length_; i++)
//			{
//				temp[i] = data_[i];
//			}
//			delete[] data_;
//			data_ = temp;
//			capacity_ *= 2;
//		}
//		data[length_] = s;
//		length_++;
//	}
//
//	// ������ ��ġ�� ���ҿ� �����Ѵ�
//	T operator[] (int i)
//	{
//		return data_[i];
//	}
//
//	// x��° ��ġ�� ���Ҹ� �����Ѵ�
//	void remove(int x)
//	{
//		for (int i = x + 1; i < length_; i++)
//		{
//			data_[i - 1] = data_[i];
//		}
//		length_--;
//	}
//
//	// ���� ������ ũ�⸦ ���Ѵ�
//	int size()
//	{
//		return size_;
//	}
//
//	void swap(int i, int j)
//	{
//		T temp = data_[i];
//		data_[i] = data_[j];
//		data_[j] = temp;
//	}
//
//	// �Ҹ���
//	~Vector()
//	{
//		if (data_)
//		{
//			delete[] data_;
//		}
//	}
//private:
//	T* data_;
//	int capacity_;
//	int length_;
//};
//
//template <typename Cont>
//void bubble_sort(Cont& cont)
//{
//	for (int i = 0; i < cont.size(); i++)
//	{
//		for (int j = i + 1; j < cont.size(); j++)
//		{
//			if (cont[i] > cont[j])
//			{
//				cont.swap(i, j)
//			}
//		}
//	}
//}
//
//template<typename Cont, typename Comp>
//void bubble_sort(Cont& cont, Comp& comp)
//{
//
//}
//
//// bool Ÿ�Կ� ���� ���ø� Ư��ȭ
//template<>
//class Vector<bool>
//{
//public:
//	Vector(int n = 1)
//		: data_{ new unsigned int[n / 32 + 1] }, capacity_{ n / 32 + 1 }, length_{ 0 }
//	{
//
//	}
//private:
//	unsigned int* data_;
//	int capacity_;
//	int length_;
//};
//}
//
//TEST_CASE("vector_template")
//{
//	SUBCASE("")
//	{
//	}
//}