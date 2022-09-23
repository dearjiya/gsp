#include <doctest/doctest.h>
#include <iostream>
#include <vector>

namespace jiya
{
template <typename T>
class Vector 
{
public:
	Vector(int n = 1) 
		: data_(new T[n]), size_(0) 
	{
	}
	Vector(size_t size) 
		: size_(size) 
	{
		data_ = new T[size_];
		for (int i = 0; i < size_; i++) {
			data_[i] = 3;
		}
	}
	const T& at(size_t index) const 
	{
		if (index >= size_) {
			throw std::out_of_range("vector 의 index 가 범위를 초과하였습니다.");
		}
		return data_[index];
	}
	void push_back(T s)
	{
		data_[size_] = s;
		size_++;
	}
	~Vector()
	{
		delete[] data_; 
	}

private:
	T* data_;
	size_t size_;
};

}

/**
 *
 */
TEST_CASE("Modularity / Error Handling")
{
	/**
	 * usage를 확인한다.  
	 */
	SUBCASE("Exception")
	{
		//jiya::Vector<int> int_vec;
		//int_vec.push_back(1);
		//int_vec.push_back(2);
		//int_vec.push_back(3);
		//std::cout << "exception: " << std::endl;
		////std::cout << int_vec.at(4) << std::endl;
	}

	SUBCASE("try catch")
	{
		jiya::Vector<int> vec(3);
		int data = 0;
		try
		{
			data = vec.at(2);
		}
		catch (std::out_of_range& e)
		{
			std::cout << "예외 발생 ! " << e.what() << std::endl;
		}
		// 예외가 발생하지 않았다면 3을 이 출력되고, 예외가 발생하였다면 원래 data 에
		// 들어가 있던 0 이 출력된다.
		std::cout << "읽은 데이터 : " << data << std::endl;
	}
	

	/**
	 * 읽어 보기. 괜찮아 보이는 방법 써보기
	 */
	SUBCASE("Error Handling - Alternatives")
	{

	}

	SUBCASE("Contracts")
	{
		static_assert(4 == sizeof(int));
	}
}
