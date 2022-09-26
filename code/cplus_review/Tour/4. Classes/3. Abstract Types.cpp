#include <doctest/doctest.h>
#include <iostream>
#include <list>
#include <Header/Vector.h>

namespace 
{

class Container
{
public:
	virtual double& operator[](int) = 0;
	virtual int size() const = 0;
	virtual ~Container() {}
private:
};

class Vector_container : public Container 
{
public: 
	Vector_container(int s) 
		: v(s) 
	{ 
	} 	

	double& operator[](int i) override 
	{ 
		return v[i]; 
	} 

	int size() const override 
	{ 
		return v.size(); 
	}
private: 
	test::Vector v; 
}; 

class List_container : public Container
{
public:
	List_container()
	{
	}
	List_container(std::initializer_list<double> il) : Id{ il }
	{
	}
	~List_container()
	{
	}
	double& operator[](int i) override;
	int size() const override
	{
		return Id.size();
	}

private:
	std::list<double> Id;
};
double& List_container::operator[](int i)
{
	for (auto& x : Id)
	{
		if (i == 0)
		{
			return x;
		}
		--i;
	}
	throw std::out_of_range{ "List_container" };
}
void use(Container& c)
{
	const int sz = c.size();
	for (int i = 0; i != sz; ++i)
	{
		std::cout << c[i] << std::endl;
	}
}
}

TEST_CASE("Classes / Abstract Types")
{
	SUBCASE("Vector_container를 연습")
	{
		// Container c{ 10 };
		Container* p = new Vector_container(10);

		Container& pv = *p;
		auto v = pv[0];
	}

	SUBCASE("std::list를 사용하는 container 작성")
	{
		List_container lc = { 1,2,3,4,5 };
		use(lc);
	}

}
