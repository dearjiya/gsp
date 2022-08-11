#pragma once 

namespace review
{

// ������ date Ŭ���� ����
class Date
{
public:
	Date(int year, int month, int day);

	void AddDay(int inc);

	int AddMonth(int inc);

	void AddYear(int inc);

	int GetDay() const;

	int GetMonth() const;

	int GetYear() const;

	bool IsLeapYear() const;

	bool IsValidDate(); 

private:
	int year_;
	int month_;  
	int day_;    
};

} // namespace review
