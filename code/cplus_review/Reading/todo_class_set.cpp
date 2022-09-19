#include<doctest/doctest.h>
#include<iostream>
#include<set>

template <typename T>
void print_set(std::set<T>& s)
{
	std::cout << "[ ";
	for (const auto& elem : s)
	{
		std::cout << elem << " " << std::endl;
	}
	std::cout << " ] " << std::endl;
}
class todo
{
public:
	todo(int priority, std::string desc)
		: priority_{ priority }, job_desc{ desc }
	{
	}
	bool operator< (const todo& t) const
	{
		if (priority_ < t.priority_)
		{

		}
	}
private:
	int priority_;
	std::string job_desc;
};

TEST_CASE("todo_class_set")
{
	SUBCASE("insert")
	{
		std::set<todo> todos;
		todos.insert(todo(1, "����"));
		todos.insert(todo(1, "����"));
		todos.insert(todo(3, "������Ʈ"));
		todos.insert(todo(2, "������"));

		print_set(todos);
	}
}