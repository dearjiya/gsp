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
		if (priority_ == t.priority_)
		{
			return job_desc < t.job_desc;
		}
		return priority_ > t.priority_;
	}
	friend std::ostream& operator<<(std::ostream& o, const todo& td);

private:
	int priority_;
	std::string job_desc;
};

std::ostream& operator<<(std::ostream& o, const todo& td)
{
	o << "[ 중요도: " << td.priority_ << "] " << td.job_desc;
	return o;
}

TEST_CASE("todo_class_set")
{
	SUBCASE("insert")
	{
		std::set<todo> todos;
		todos.insert(todo(1, "숙제"));
		todos.insert(todo(1, "정리"));
		todos.insert(todo(3, "프로젝트"));
		todos.insert(todo(2, "저녁약속"));

		print_set(todos);
	}
}