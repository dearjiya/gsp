//#include <doctest/doctest.h>
//
//#include <iostream>
//#include <string>
//#include <vector>
//
//namespace
//{
//class Employee
//{
//public:
//	Employee(std::string name, int age, std::string position, int rank)
//		: name_(name), age_(age), position_(position), rank_(rank)
//	{
//	}
//
//	Employee(const Employee& employee)
//	{
//		name_ = employee.name_;
//		age_ = employee.age_;
//		position_ = employee.position_;
//		rank_ = employee.rank_;
//	}
//
//	Employee() {}
//
//	void print_info()
//	{
//		std::cout << name_ << " (" << position_ << " , " << age_ << ") ==>"
//			<< calculate_pay() << "����" << std::endl;
//	}
//	int calculate_pay()
//	{
//		return 200 + rank_ * 50;
//	}
//	
//protected:
//	std::string name_;
//	int age_;
//	std::string position_;
//	int rank_;
//};
//
//class EmployeeList
//{
//public:
//	EmployeeList(int alloc_employee)
//		: alloc_employee_(alloc_employee)
//	{
//		current_employee_ = 0;
//		current_manager_ = 0;
//		employee_list_ = new Employee*[alloc_employee_];
//		manager_list_ = new Manager * [alloc_employee_];
//	}
//	void add_employee(Employee* employee)
//	{
//		employee_list_[current_employee_] = employee;
//		current_employee_++;
//	}
//	void add_manager(Manager* manager)
//	{
//		manager_list_[current_manager_] = manager;
//		current_manager_++;
//	}
//	int current_employee_num()
//	{
//		return current_employee_;
//	}
//	void print_employee_info()
//	{
//		int total_pay = 0;
//		for (int i = 0; i < current_employee_; i++)
//		{
//			employee_list_[i]->print_info();
//			total_pay += employee_list_[i]->calculate_pay();
//		}
//		for (int i = 0; i < current_manager_; i++) {
//			manager_list_[i]->print_info();
//			total_pay += manager_list_[i]->calculate_pay();
//		}
//		std::cout << "�� ���: " << total_pay << "���� " << std::endl;
//	}
//
//	~EmployeeList()
//	{
//		for (int i = 0; i < current_employee_; i++)
//		{
//			delete employee_list_[i];
//		}
//		for (int i = 0; i < current_manager_; i++)
//		{
//			delete manager_list_[i];
//		}
//		delete[] employee_list_;
//		delete[] manager_list_;
//	}
//
//private:
//	int alloc_employee_;
//	int current_employee_;
//	int current_manager_;
//	Employee** employee_list_;	
//	Manager** manager_list_;
//};
//
//class Manager : public Employee
//{
//public:
//	Manager(std::string name, int age, std::string position, int rank, int year_of_service)
//		: year_of_service_(year_of_service), Employee(name, age, position, rank)
//	{
//	}
//
//	Manager(const Manager& manager)
//		: Employee(manager.name_, manager.age_, manager.position_, manager.rank_)
//	{
//		year_of_service_ = manager.year_of_service_;
//	}
//
//	Manager() : Employee() {}
//
//	int calculate_pay()
//	{
//		return 200 + rank_ * 50 + 5 * year_of_service_;
//	}
//
//	void print_info()
//	{
//		std::cout << name_ << " (" << position_ << " , " << age_ << ", "
//			<< year_of_service_ << "����) ==> " << calculate_pay() << "����"
//			<< std::endl;
//	}
//private:
//	int year_of_service_;
//};
//
//} // namespace
//
//TEST_CASE("employee class")
//{
//	SUBCASE("use case")
//	{
//		EmployeeList emp_list(10);
//		emp_list.add_employee(new Employee("��ȫö", 34, "����", 1));
//		emp_list.add_employee(new Employee("����", 34, "����", 1));
//
//		emp_list.add_employee(new Employee("���缮", 41, "����", 7));
//		emp_list.add_employee(new Employee("������", 43, "����", 4));
//		emp_list.add_employee(new Employee("�ڸ��", 43, "����", 5));
//		emp_list.add_employee(new Employee("������", 36, "�븮", 2));
//		emp_list.add_employee(new Employee("��", 36, "����", -2));
//		emp_list.print_employee_info();
//	}
//}
