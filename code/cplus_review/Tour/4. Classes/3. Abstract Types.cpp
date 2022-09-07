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
	}


}
