#include <doctest/doctest.h>

#include <iostream>
#include <string>

namespace
{


} // namespace

/**
 * ����� OOP �� ����� ��ҷ� IsA ���踦 ǥ���Ѵ�.
 * ��ӵ� Ŭ������ �θ� Ŭ������ ���� ���� ���� �� �ִ�.  
 */
TEST_CASE("inheritance")
{
	/**
	 * �����ΰ�? �θ�ó�� �����ϸ鼭 ���� ������ �߰��� Ŭ����
	 * �� �ʿ��Ѱ�? �������̽��� �����ϱ�����. ������ �����ϱ�����.
	 * ��� ����ϴ°�? 
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
				Base() : s("���")
				{
					std::cout << "��� Ŭ����" << std::endl;
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
				Derived() : Base(), s("�Ļ�")
				{
					std::cout << "�Ļ� Ŭ����" << std::endl;

					what();
				}

				std::string s;
				
				// �������̵�
				void what()
				{
					std::cout << s << std::endl;
				}

			//	parent_string = 

			};

			std::cout << "===��� Ŭ���� ����===" << std::endl;
			Base p;
			std::cout << "===�Ļ� Ŭ���� ����===" << std::endl;
			Derived c;
		}
	}

	SUBCASE("use case")
	{

	}

}
