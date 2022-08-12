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
					std::cout << "Parent" << std::endl;
				}
			};

			class Child : public Parent
			{
			public:
				Child() : Parent()
				{}

				void Shout()
				{
					std::cout << "Child" << std::endl;
				}
			};

			Parent p;
			p.Shout();

			Child c;
			c.Shout();
		}
	}

	SUBCASE("use case")
	{

	}

}
