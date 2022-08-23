#include <doctest/doctest.h>

#include <iostream>
#include <string>
#include <vector>

namespace
{
class Employee
{
public:
	Employee(std::string name, int age, std::string position, int rank)
		: name_(name), age_(age), position_(position), rank_(rank)
	{
	}

	Employee(const Employee& employee)
	{
		name_ = employee.name_;
		age_ = employee.age_;
		position_ = employee.position_;
		rank_ = employee.rank_;
	}

	Employee() {}

	void print_info()
	{
		std::cout << name_ << " (" << position_ << " , " << age_ << ") ==>"
			<< calculate_pay() << "¸¸¿ø" << std::endl;
	}
	int calculate_pay()
	{
		return 200 + rank_ * 50;
	}
	
private:
	std::string name_;
	int age_;
	std::string position_;
	int rank_;
};

class EmployeeList
{
public:
	EmployeeList(int alloc_employee)
		: alloc_employee_(alloc_employee)
	{
		current_employee_ = 0;
		employee_list_ = new Employee * [alloc_employee_];
	}
	void add_employee(Employee* employee)
	{
		employee_list_[current_employee_] = employee;
		current_employee_++;
	}
	int current_employee_num()
	{
		return current_employee_;
	}
	void print_employee_info()
	{
		
	}

private:
	int alloc_employee_;
	int current_employee_;
	Employee** employee_list_;

	
};

} // namespace

TEST_CASE("employee class")
{
	SUBCASE("use case")
	{

	}
}
