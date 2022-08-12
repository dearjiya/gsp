#include <doctest/doctest.h>

#include <string>
#include <memory>
#include <iostream>

namespace
{


} // namespace

/**
 * ������ �����ε��� C++�� ������ ������� DSL(Domain Specific Language)�� ����ų� 
 * ���� ����� �߰��� �� �ſ� �����ϰ� ���δ�.
 */
TEST_CASE("operator overloading")
{
	/**
	 * �����ΰ�? ������ �Լ��� Ŭ������ ���� �����Ͽ� �����ڰ� �ִ� Ŭ������ �����. 
	 * �� �ʿ��Ѱ�? ���� �ڿ������� ���ϰ� Ŭ������ Ư�� ����� ����� �� �ְ� �Ѵ�. 
	 * ��� ����ϴ°�? �⺻������ �Լ� �����̰� �����ڿ� �´� ������ ����Ͽ� �����ϰ� �����Ѵ�.
     *
	 * std::string�� �� ���� ������ ������ �����鼭 �����Ѵ�. 
	 * - operator�� �Լ���� ��. ������ �ణ �ٸ����� �Լ��̴�.
	 * - ȣ���� ������ ���ó�� �Ѵ�. 
	 */
	SUBCASE("intro")
	{
		SUBCASE("==")
		{
			std::string s1{ "hello" };
			std::string s2{ "hello" };

			auto is_same = (s1 == s2);
			CHECK(is_same);
		}

		/**
		 * std::string
		 */
		SUBCASE("std::string")
		{
			std::string s{ "�ѱ�" };

			std::cout << s << std::endl;
		}

		/**
		 * std::wstring�� UNICODE16LE ������ ����Ѵ�. 
		 */
		SUBCASE("std::wstring")
		{
			std::wstring w1{ L"�ѱ�" };
			std::wstring w2{ L"World" };
		}
	}

	/**
	 * ���÷� ������ MyString ����� ������ �߰��� �����Ѵ�. 
	 */
	SUBCASE("use case")
	{

	}

	/**
	 * ���Ҽ� Ŭ���� ������ ���ڿ� �����ó�� ���� �����̰� 
	 * ���� ������ �����ϱ����� �����̱⵵ �ϴ�. 
	 */
	SUBCASE("complex class")
	{
		/**
		 * ���� �����ڴ� ���� ������
		 * 
		 * Complex c1 = Complex{3, 1};
		 */
		SUBCASE("assignment operator")
		{
			/**
			 * ���� �����ڰ� ȣ��� ���� ���� �����ڰ� ȣ��� ���� �����ϱ�
			 */
			SUBCASE("when = is used?")
			{

			}
		}
	}
}
