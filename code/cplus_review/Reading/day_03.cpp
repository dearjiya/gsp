#include <doctest/doctest.h>

#include "Date.hpp"

namespace
{
class Animal
{
// kdpark의 스타일
// public static 함수, 변수 
// public 함수
// protectecd 함수
// private 함수, 변수 

public:

private:

};
} // namespace

TEST_CASE("day 03")
{

	SUBCASE("Animal 클래스를 작성하고 함수들 사용")
	{
		// 예시의 Animal 클래스를 옮겨와서 잘 쓸 수 있는 지 확인

	}

	SUBCASE("public private 구분")
	{
		// encapsulation이라고 한다. 
		// private food는 접근 불가능하다.  

	}

	SUBCASE("Date 클래스 만들기")
	{
		// 완전하지 않아도 시도 자체가 중요하다. 

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
