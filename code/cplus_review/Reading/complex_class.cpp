#include <doctest/doctest.h>
#include <iostream>
#include <string>
#include <complex>
#include <cassert>
#include <string>

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
	complex(const char* str)
	{
		double str_real_ = 0.0;
		double str_img_ = 0.0;
		size_t len_ = strlen(str);
		int pos_i_ = -1; // �ʱ�ȭ�� 0���� �ص� �ǳ�? for���� ���� 0�� ��� ����ΰ� ���� ����

		for (int i = 0; i < len_; i++)
		{
			if (str[i] == 'i')
			{
				// ����ΰ� ����
				pos_i_ = i;
				//std::cout << "pos_i_: " << pos_i_ << std::endl; //4�� �����
				break;
			}
		}

		if (pos_i_ == -1)
		{
			// ����ΰ� ������������
			str_real_ = get_number(str, 0, len_);
			str_img_ = 0.0;
		}
		else
		{
			str_real_ = get_number(str, 0, pos_i_ - 2);
			str_img_ = get_number(str, pos_i_ + 1, len_ - 1);
		}

		if (pos_i_ >= 1 && str[pos_i_ - 1] == '-')
		{
			str_img_ = str_img_ * -1.0;
		}
		real_ = str_real_;
		img_ = str_img_;
	}

	void print()
	{
		char* mid = new char[2];
		if (img_ < 0)
		{
			mid[0] = '-';
			mid[1] = '\0';
			img_ = img_ * -1;
		}
		else
		{
			mid[0] = '+';
			mid[1] = '\0';
		}

		std::cout << real_ << mid << "i" << img_ << std::endl;
	}

	complex operator+(const complex& c)
	{
		complex res(real_ + c.real_, img_ + c.img_);
		std::cout << "complex& " << std::endl;
		return res;
	}

	complex& operator+ (const char* str)
	{
		// �Է¹��� ���ڿ��� �м��Ͽ� real�κа� img�κ��� ã�´�.
		// [��ȣ](�Ǽ���)(��ȣ)i(�����)
		// �� �� ��ȣ�� ���������ϸ� ������ +�� �����Ѵ�.
		double str_real_ = 0.0;
		double str_img_ = 0.0;
		size_t len_ = strlen(str);
		int pos_i_ = -1; // �ʱ�ȭ�� 0���� �ص� �ǳ�? for���� ���� 0�� ��� ����ΰ� ���� ����

		for (int i = 0; i < len_; i++)
		{
			if (str[i] == 'i')
			{
				// ����ΰ� ����
				pos_i_ = i;
				//std::cout << "pos_i_: " << pos_i_ << std::endl; //4�� �����
				break;
			}
		}

		if (pos_i_ == -1)
		{
			// ����ΰ� ������������
			str_real_ = get_number(str, 0, len_);
			str_img_ = 0.0;
		}
		else
		{
			str_real_ = get_number(str, 0, pos_i_ - 2);
			str_img_ = get_number(str, pos_i_ + 1, len_ - 1);
		}

		if (pos_i_ >= 1 && str[pos_i_ - 1] == '-')
		{
			str_img_ = str_img_ * -1.0;
		}
		real_ = real_ + str_real_;
		img_ = img_ + str_img_;

		return *this;
	}

	double get_number(const char* str, int from, int to) const
	{
		//assert(from <= to);
		if (from > to)
		{
			throw std::out_of_range("index ũ�� ����");
		}

		bool minus = false;

		if (str[from] == '-')
		{
			minus = true;
		}
		if (str[from] == '-' || str[from] == '+')
		{
			from += 1;
		}

		char* temp = new char[to];

		for (int i = 0; i < to - from + 1; i++)
		{
			temp[i] = str[from + i];
		}
		temp[to - from + 1] = '\0';

		std::string string_;
		string_.append(temp);
		if (minus == true)
		{
			string_.insert(0, "-");
		}
		double res = std::stod(string_);
		return res;
	}
	
	complex& operator- (const complex& c)
	{
		real_ = real_ - c.real_;
		img_ = img_ - c.img_;
		return *this;
	}

	complex operator* (const complex& c)
	{
		complex res(real_ * c.real_ - img_ * c.img_, real_ * c.img_ + img_ * c.real_);
		return res;
	}

	complex operator/ (const complex& c)
	{
		// XXX: 0���� �����Ⱑ �Ǵ� ��� üũ 
		if (c.real_ == 0 && c.img_ == 0)
		{
			throw std::out_of_range("0���� ������ �Ǵ� ��Ȳ!");
		}
		complex res((real_ * c.real_ + img_ * c.img_) / (c.real_ * c.real_ + c.img_ * c.img_),
			(img_ * c.real_ - real_ * c.img_) / (c.real_ * c.real_ + c.img_ * c.img_));
		return res;
	}

	complex& operator= (const complex& c)
	{
		real_ = c.real_;
		img_ = c.img_;
		return *this;
	}

	complex& operator+= (const complex& c)
	{
		(*this) = (*this) + c;
		return *this;
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

	friend complex operator+(const complex& a, const complex& b);

private:
	double real_; // �Ǽ���
	double img_; // �����
};

complex operator+(const complex& a, const complex& b)
{
	complex res(a.real_ + b.real_, a.img_ + b.img_);
	return res;
}

} // namespace jiya

TEST_CASE("complex number class")
{
	SUBCASE("std::complex ���")
	{
		SUBCASE("operator /")
		{
			std::complex<double> a(0.0, 2.0);
			std::complex<double> b(0.0, 0.0);
			std::complex<double> res = a / b;
			//std::cout << "std::complex operator / " << res << std::endl;
		}
	}

	SUBCASE("���Ҽ� Ŭ���� �����")
	{
		SUBCASE("���� �׽�Ʈ 1 - operator+")
		{
			jiya::complex c1{ 1, 4 };
			jiya::complex c2{ 2, 5 };
			jiya::complex expected{ 3,9 };
			jiya::complex res = c1 + c2;
			//res.print();
			CHECK(res == expected);
		}

		SUBCASE("���� �׽�Ʈ 2 - operator-")
		{
			jiya::complex c1{ 2, 5 };
			jiya::complex c2{ 1, 4 };
			jiya::complex expected{ 1,1 };
			jiya::complex res = c1 - c2;
			//res.print();
			CHECK(res == expected);
		}

		SUBCASE("���� �׽�Ʈ 3 - operator*")
		{
			jiya::complex c1{ 1, 4 };
			jiya::complex c2{ 2, 5 };
			jiya::complex expected{ -18,13 };
			jiya::complex res = c1 * c2;
			//res.print();
			CHECK(res == expected);
		}

		SUBCASE("���� �׽�Ʈ 4 - operator/")
		{
			SUBCASE("case 1")
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

			SUBCASE("case 2")
			{
				jiya::complex c1{ 1, 2 };
				jiya::complex c2{ 0, 0 };
				//jiya::complex res = c1 / c2;
				std::complex<double> a(1.0, 2.0);
				std::complex<double> b(0.0, 0.0);
				std::complex<double> std_res = a / b;
				jiya::complex res2{ std_res.real(), std_res.imag() };
				//CHECK(res.compare_std(res2) == true);
			}
		}

		SUBCASE("���� �׽�Ʈ 5 - operator=")
		{
			jiya::complex c1{ 1,2 };
			jiya::complex c2{ 2,3 };
			c1 = c2;
			CHECK(c1 == c2);
		}

		SUBCASE("���� �׽�Ʈ 6 - string_complex")
		{
			SUBCASE("basic")
			{
				jiya::complex temp{ 3,2 };
				jiya::complex expected{ 5,5 };
				temp = temp + "2+i3";
				//temp.print();
				CHECK(temp == expected);
			}

			SUBCASE("minus_img")
			{
				jiya::complex temp{ 3,2 };
				jiya::complex expected{ 115,-691 };
				temp = temp + "112-i693";
				CHECK(temp == expected);
			}

			SUBCASE("minus_real")
			{
				jiya::complex temp{ 2,2 };
				jiya::complex expected{ -110, 65 };
				temp = temp + "-112+i63";
				//temp.print();
				CHECK(temp == expected);
			}

			SUBCASE("decimal_complex")
			{
				jiya::complex temp{ 3,2 };
				temp = temp + "0.112-i0.693";
				//temp.print();
				std::complex<double> a(3.0, 2.0);
				std::complex<double> b(0.112, -0.693);
				std::complex<double> std_res = a + b;
				jiya::complex res2{ std_res.real(), std_res.imag() };
				//res2.print();
				CHECK(temp.compare_std(res2) == true);
			}

			SUBCASE("operator_overloading_by_friend")
			{
				jiya::complex temp{ 3,2 };
				temp = "2+i3" + temp;
				jiya::complex expected{ 5,5 };
				CHECK(temp == expected);
			}	
		}
	}
}