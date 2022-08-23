#include <doctest/doctest.h>

#include <iostream>
#include <string>

namespace
{


} // namespace

/**
 * 상속은 OOP 언어에 공통된 요소로 IsA 관계를 표현한다.
 * 상속된 클래스는 부모 클래스가 쓰인 곳에 쓰일 수 있다.  
 */
TEST_CASE("inheritance")
{
	/**
	 * 무엇인가? 부모처럼 동작하면서 세부 사항이 추가된 클래스
	 * 왜 필요한가? 인터페이스를 제공하기위해. 구현을 재사용하기위해.
	 * 어떻게 사용하는가? 
	 */
	SUBCASE("intro")
	{
	}

	SUBCASE("usage")
	{
		SUBCASE("basic")
		{
			class Parent
			{
			public:
				Parent()
				{
				}

				void Shout()
				{
					// std::cout << "Parent" << std::endl;
				}
			};

			class Child : public Parent
			{
			public:
				Child() : Parent()
				{}

				void Shout()
				{
					// std::cout << "Child" << std::endl;
				}
			};

			Parent p;
			p.Shout();

			Child c;
			c.Shout();
		}

		SUBCASE("protected")
		{
			class Base
			{
			protected:
				std::string parent_string;

			public:
				Base() : s("기반")
				{
					std::cout << "기반 클래스" << std::endl;
				}
				void what()
				{
					std::cout << s << std::endl;
				}

			private:
				std::string s;
			};

			class Derived : public Base
			{
				std::string child_string;

			public:
				Derived() : Base(), s("파생")
				{
					std::cout << "파생 클래스" << std::endl;

					what();
				}

				std::string s;
				
				// 오버라이딩
				void what()
				{
					std::cout << s << std::endl;
				}

			//	parent_string = 

			};

			std::cout << "===기반 클래스 생성===" << std::endl;
			Base p;
			std::cout << "===파생 클래스 생성===" << std::endl;
			Derived c;
		}
	}

	SUBCASE("use case")
	{

	}

}
