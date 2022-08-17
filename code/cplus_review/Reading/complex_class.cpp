#include <doctest/doctest.h>
#include <iostream>
#include <string>
#include <complex>
#include <cassert>
#define ABS(X) ((X) < 0 ? -(X) : (X))
#define EPSILON 0.000001

namespace jiya
{

class complex
{
public:
	complex(double real, double img)
		: real_(real)
		, img_(img)
	{
	}

	void print()
	{
		std::cout << real_ << " + " << img_ << "i" << std::endl;
	}

	complex operator+ (const complex& c)
	{
		complex res(real_ + c.real_, img_ + c.img_);
		return res;
	}
	complex operator- (const complex& c)
	{
		complex res(real_ - c.real_, img_ - c.img_);
		return res;
	}
	complex operator* (const complex& c)
	{
		complex res(real_ * c.real_ - img_ * c.img_, real_ * c.img_ + img_ * c.real_);
		return res;
	}
	complex operator/ (const complex& c)
	{
		complex res(
			(real_ * c.real_ + img_ * c.img_) / (c.real_ * c.real_ + c.img_ * c.img_),
			(img_ * c.real_ - real_ * c.img_) / (c.real_ * c.real_ + c.img_ * c.img_));
		return res;
	}
	complex operator= (const complex& c)
	{
		real_ = c.real_;
		img_ = c.img_;
		complex res(real_, img_);
		return res;
	}

	bool operator==(const complex& c)
	{
		if (real_ == c.real_ && img_ == c.img_)
		{
			//std::cout << real_ << img_ << std::endl;
			//std::cout << c.real_ << c.img_ << std::endl;
			return true;
		}
		return false;
	}

	bool compare_std(const complex& c)
	{
		if (ABS(real_ - c.real_ < EPSILON) && ABS(img_ - c.img_ < EPSILON))
		{
			return true;
		}
		return false;
	}

private:
	double real_; // 실수부
	double img_; // 허수부
};

} // namespace jiya

TEST_CASE("complex number class")
{
	SUBCASE("std::complex 사용")
	{
		SUBCASE("operator /")
		{
			std::complex<double> a(1.0, 2.0);
			std::complex<double> b(2.0, 3.0);
			std::complex<double> res = a / b;
			//	std::cout << "std::complex operator / " << res << std::endl;
		}
	}

	SUBCASE("복소수 클래스 만들기")
	{
		SUBCASE("단위 테스트 1 - operator+")
		{
			jiya::complex c1{ 1, 4 };
			jiya::complex c2{ 2, 5 };
			jiya::complex expected{ 3,9 };
			jiya::complex res = c1 + c2;
			//res.print();
			CHECK(res == expected);
		}
		SUBCASE("단위 테스트 2 - operator-")
		{
			jiya::complex c1{ 2, 5 };
			jiya::complex c2{ 1, 4 };
			jiya::complex expected{ 1,1 };
			jiya::complex res = c1 - c2;
			//res.print();
			CHECK(res == expected);
		}
		SUBCASE("단위 테스트 3 - operator*")
		{
			jiya::complex c1{ 1, 4 };
			jiya::complex c2{ 2, 5 };
			jiya::complex expected{ -18,13 };
			jiya::complex res = c1 * c2;
			//res.print();
			CHECK(res == expected);
		}
		SUBCASE("단위 테스트 4 - operator/")
		{
			jiya::complex c1{ 1, 2 };
			jiya::complex c2{ 2, 3 };
			jiya::complex res = c1 / c2;
			std::complex<double> a(1.0, 2.0);
			std::complex<double> b(2.0, 3.0);
			std::complex<double> std_res = a / b;
			jiya::complex res2{ std_res.real(), std_res.imag() };
			CHECK(res.compare_std(res2) == true);
		}
		SUBCASE("단위 테스트 5 - operator=")
		{
			// complex 반환과 complex& 반환 비교해보기
			jiya::complex c1{ 1,2 };
			jiya::complex c2{ 2,3 };
			//std::cout << "add1: " << 
			c1 = c2;
			std::cout << "=";
			c1.print();
		}
	}
}