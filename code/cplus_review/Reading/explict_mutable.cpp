#include <doctest/doctest.h>

#include <vector>

namespace
{

} // namespace

/**
 * explicit�� mutable�� ������ �����̰� ������ ���Ǹ� ���´�. 
 * 
 * - explicit�� �����ڿ��� Ÿ���� �Ϲ���(implicit)���� ��ȯ���� �ʵ��� �����Ѵ�.
 * - mutable�� const �Լ����� ���� ������ ������ �����Ѵ�. 
 */
TEST_CASE("explicit_mutable")
{
	/**
	 * float���� int�� �Ϲ����� ��ȯ�� explicit�� ������ �����ڿ��� 
	 * �̷������, �����Ϸ������� ��� �����ش�. 
	 */
	SUBCASE("explicit")
	{
		class ExplicitTest
		{
		public:
			explicit ExplicitTest(int v)
				: v_{ v }
			{}

		private:
			int v_;
		};

		ExplicitTest test(1.1f);
	}

	/**
	 * @see class_const_static_member.cpp / SUBCASE("const member function")
	 * �� ������ �������̽� �ȿ� mutable ��� ������ �����ϴ� const �Լ��� 
	 * ���ð� �ִ�. 
	 */
	SUBCASE("mutable")
	{
	}
}
