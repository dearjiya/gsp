#include <doctest/doctest.h>
#include <iostream>

namespace concrete
{
class complex
{
public:
	complex(double r, double i) : real_{ r }, img_{ i }
	{
	}
	complex(double r) : real_{ r }
	{
	}
	complex() : real_{ 0 }, img_{ 0 }
	{
	}

	double real() const
	{
		return real_;
	}
	void real(double d)
	{
		real_ = d;
	}
	double imag() const
	{
		return img_;
	}
	void imag(double d)
	{
		img_ = d;
	}

	//complex& operator+=(complex z)
	//{
	//	real_ += z.real_;
	//	img_ += z.img_;
	//	return *this;
	//}

	//complex& operator -=(complex z)
	//{
	//	real_ -= z.real_;
	//	img_ -= z.img_;
	//	return *this;
	//}
	//complex& operator*=(complex);
	//complex& operator/=(complex);

	void print()
	{
		std::cout << real_ << "i" << img_ << std::endl;
	}
	inline void print2()
	{
		std::cout << real_ << "i" << img_ << std::endl;
	}

private:
	double real_;
	double img_;
};
}

TEST_CASE("Classes / Concrete Types")
{
	SUBCASE("complex review")
	{
		concrete::complex z{ 1,0 };
		const concrete::complex cz{ 1,2 };
		z = cz;
		// cz = z; // error
		double x = z.real();
	}

	/**
	 * inline 된 코드와 안 된 코드를 만들기 
	 */
	SUBCASE("inlining")
	{
		concrete::complex com_{ 2,3 };
		com_.print();
		com_.print2();
	}

	/**
	 * 클래스 외부에서 정의한 연산자 구현
	 */
	SUBCASE("complex free operators")
	{

	}
}
