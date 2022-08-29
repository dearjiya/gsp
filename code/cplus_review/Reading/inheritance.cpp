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
					//std::cout << "기반 클래스" << std::endl;
				}
				void what()
				{
					//std::cout << s << std::endl;
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
					//std::cout << s << std::endl;
				}

			//	parent_string = 

			};

			//std::cout << "===기반 클래스 생성===" << std::endl;
			Base b;
			//std::cout << "===파생 클래스 생성===" << std::endl;
			Derived d;

			//std::cout << "===포인터 버전===" << std::endl;
			// Derived is a Base
			Base* b_b = &d;
			
			// b_b가 가리키는 것이 Derived 객체이긴 하지만 에러가 발생하므로 강제 다운캐스팅
			//Derived* base_to_derived = base_to_base;
			Derived* b_d = static_cast<Derived*>(b_b);
			b_d->what();
			// 캐스팅이 정확하게 되었으므로 문제는 없지만 잘못 사용하면 오류가 발생한다

		}
	}

	SUBCASE("use case")
	{
		class Base
		{
		public:
			Base() {}
			virtual ~Base() { std::cout << "Base 소멸자 호출" << std::endl; }
		public:
			virtual void Talk()
			{
				std::cout << "나는 Base" << std::endl;
			}
		};

		class Derived : public Base
		{
		public:
			Derived() {}
			~Derived() { std::cout << "Derived 소멸자 호출" << std::endl; }
		public:
			void Talk()
			{
				std::cout << "나는 Derived" << std::endl;
			}
		};

		Base* b = new Derived();

		delete b;
	}

}
