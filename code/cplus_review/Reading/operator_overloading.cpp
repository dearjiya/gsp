#include <doctest/doctest.h>

#include <string>
#include <memory>
#include <iostream>

namespace
{


} // namespace

/**
 * 연산자 오버로딩은 C++에 고유한 기능으로 DSL(Domain Specific Language)을 만들거나 
 * 편의 기능을 추가할 때 매우 유용하게 쓰인다.
 */
TEST_CASE("operator overloading")
{
	/**
	 * 무엇인가? 연산자 함수를 클래스에 대해 구현하여 연산자가 있는 클래스를 만든다. 
	 * 왜 필요한가? 보다 자연스럽고 편리하게 클래스의 특정 기능을 사용할 수 있게 한다. 
	 * 어떻게 사용하는가? 기본적으로 함수 구현이고 연산자에 맞는 형식을 사용하여 선언하고 정의한다.
     *
	 * std::string의 몇 가지 연산자 구현을 읽으면서 이해한다. 
	 * - operator는 함수라는 점. 문법은 약간 다르지만 함수이다.
	 * - 호출을 연산자 사용처럼 한다. 
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
			std::string s{ "한글" };

			std::cout << s << std::endl;
		}

		/**
		 * std::wstring은 UNICODE16LE 형식을 사용한다. 
		 */
		SUBCASE("std::wstring")
		{
			std::wstring w1{ L"한글" };
			std::wstring w2{ L"World" };
		}
	}

	/**
	 * 예시로 나오는 MyString 기반의 연산자 추가를 연습한다. 
	 */
	SUBCASE("use case")
	{

	}

	/**
	 * 복소수 클래스 만들기는 문자열 만들기처럼 좋은 연습이고 
	 * 이후 연습을 진행하기위한 기초이기도 하다. 
	 */
	SUBCASE("complex class")
	{
		/**
		 * 대입 연산자는 복사 생성자
		 * 
		 * Complex c1 = Complex{3, 1};
		 */
		SUBCASE("assignment operator")
		{
			/**
			 * 대입 연산자가 호출될 때와 복사 생성자가 호출될 때를 구분하기
			 */
			SUBCASE("when = is used?")
			{

			}
		}
	}
}
