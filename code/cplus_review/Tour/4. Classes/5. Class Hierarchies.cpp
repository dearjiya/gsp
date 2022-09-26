#include <doctest/doctest.h>
#include <iostream>
#include <list>
#include <Header/Vector.h>

namespace
{
class Point
{
public:
	int x; 
	int y;
};
class Shape
{
public:
	virtual Point center() const = 0;
	virtual void move(Point to) = 0;
	virtual void draw() const = 0;
	virtual void rotate(int angle) = 0; 
	//virtual  ̃Shape() {}
	
private:
	Point x;
	int r;
};
}

TEST_CASE("Classes / Class Hierarchies")
{
	/**
	 *
	 */
	SUBCASE("dynamic_cast")
	{

	}

	SUBCASE("unique_ptr 연습")
	{
		// 한 곳에서만 참조

	}

	SUBCASE("shared_ptr 연습")
	{
		// 여러 곳에서 참조 가능

	}
}
