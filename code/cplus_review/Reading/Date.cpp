#include "Date.hpp"
#include <cassert>
#include <list>

namespace review
{

Date::Date(int year, int month, int day)
	: year_(year)
	, month_(month)
	, day_(day)
{
	assert(year_ >= 0);
	assert(month_ >= 1);
	assert(month_ <= 12);
	assert(day_ >= 1);
	assert(day_ <= 28);
}

void Date::AddDay(int inc)
{
	assert(inc >= 0);

}

int Date::AddMonth(int inc)
{
	assert(inc >= 0);
	//std::list<int> months(12);
	//months.push_back(31);
	
	int months[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (IsLeapYear())
	{
		
	}
	int sum = month_ + inc;
	if (sum > 12) 
	{
		month_ = sum - 12;
	}
	else 
	{
		month_ = sum;
	}

	return month_;
}

void Date::AddYear(int inc)
{
	assert(inc >= 0);
	year_ += inc;
}

int Date::GetDay() const
{
	return day_;
}

int Date::GetMonth() const
{
	return month_;
}

int Date::GetYear() const
{
	return year_;
}

bool Date::IsLeapYear() const
{
	bool is_divisible_by_4 = (GetYear() % 4) == 0;

	if (is_divisible_by_4)
	{
		bool is_divisible_by_100 = (GetYear() % 100) == 0;

		if (is_divisible_by_100)
		{
			bool is_divisible_by_400 = (GetYear() % 400) == 0;

			if (is_divisible_by_400)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool Date::IsValidDate()
{
	return true;
}

} // namespace review
