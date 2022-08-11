#include <doctest/doctest.h>

#include "Date.hpp"

namespace
{
class Animal
{
// kdpark�� ��Ÿ��
// public static �Լ�, ���� 
// public �Լ�
// protectecd �Լ�
// private �Լ�, ���� 

public:

private:

};
} // namespace

TEST_CASE("day 03")
{

	SUBCASE("Animal Ŭ������ �ۼ��ϰ� �Լ��� ���")
	{
		// ������ Animal Ŭ������ �Űܿͼ� �� �� �� �ִ� �� Ȯ��

	}

	SUBCASE("public private ����")
	{
		// encapsulation�̶�� �Ѵ�. 
		// private food�� ���� �Ұ����ϴ�.  

	}

	SUBCASE("Date Ŭ���� �����")
	{
		// �������� �ʾƵ� �õ� ��ü�� �߿��ϴ�. 

		SUBCASE("get functions")
		{
			review::Date date(2022, 8, 2);

			CHECK(date.GetYear() == 2022);
			CHECK(date.GetMonth() == 8);
			CHECK(date.GetDay() == 2);
		}

		SUBCASE("check leap year")
		{
			review::Date date1(2024, 1, 1);
			CHECK(date1.IsLeapYear());

			review::Date date2(2100, 1, 1);
			CHECK(!date2.IsLeapYear());

			review::Date date3(2400, 1, 1);
			CHECK(date3.IsLeapYear());
		}

		SUBCASE("check add month")
		{
			review::Date date(2022, 8, 2);
			CHECK(date.AddMonth(5) == 1);
		}
	}
}
