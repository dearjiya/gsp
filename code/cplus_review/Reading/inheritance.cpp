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
					//std::cout << "��� Ŭ����" << std::endl;
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
				Derived() : Base(), s("�Ļ�")
				{
					std::cout << "�Ļ� Ŭ����" << std::endl;

					what();
				}

				std::string s;
				
				// �������̵�
				void what()
				{
					//std::cout << s << std::endl;
				}

			//	parent_string = 

			};

			//std::cout << "===��� Ŭ���� ����===" << std::endl;
			Base b;
			//std::cout << "===�Ļ� Ŭ���� ����===" << std::endl;
			Derived d;

			//std::cout << "===������ ����===" << std::endl;
			// Derived is a Base
			Base* b_b = &d;
			
			// b_b�� ����Ű�� ���� Derived ��ü�̱� ������ ������ �߻��ϹǷ� ���� �ٿ�ĳ����
			//Derived* base_to_derived = base_to_base;
			Derived* b_d = static_cast<Derived*>(b_b);
			b_d->what();
			// ĳ������ ��Ȯ�ϰ� �Ǿ����Ƿ� ������ ������ �߸� ����ϸ� ������ �߻��Ѵ�

		}
	}

	SUBCASE("use case")
	{
		class Base
		{
		public:
			Base() {}
			virtual ~Base() { std::cout << "Base �Ҹ��� ȣ��" << std::endl; }
		public:
			virtual void Talk()
			{
				std::cout << "���� Base" << std::endl;
			}
		};

		class Derived : public Base
		{
		public:
			Derived() {}
			~Derived() { std::cout << "Derived �Ҹ��� ȣ��" << std::endl; }
		public:
			void Talk()
			{
				std::cout << "���� Derived" << std::endl;
			}
		};

		Base* b = new Derived();

		delete b;
	}

}
