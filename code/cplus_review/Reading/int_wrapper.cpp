#include <doctest/doctest.h>
#include <iostream>

namespace
{
class Int
{
public:
	Int(int data)
		:data(data) {}
	Int(const Int& i)
		:data(i.data){}

	operator int() { return data; }

private:
	int data;
};

class Test {
	int x;

public:
	Test(int x) : x(x) {}
	Test(const Test& t) : x(t.x) {}

	Test& operator++() {
		x++;
		std::cout << "전위 증감 연산자" << std::endl;
		return *this;
	}

	// 전위 증감과 후위 증감에 차이를 두기 위해 후위 증감의 경우 인자로 int 를
	// 받지만 실제로는 아무것도 전달되지 않는다.
	Test operator++(int) {
		Test temp(*this);
		x++;
		std::cout << "후위 증감 연산자" << std::endl;
		return temp;
	}

	int get_x() const {
		return x;
	}
};

void func(const Test& t) {
	std::cout << "x : " << t.get_x() << std::endl;
}

} // namespace
/**
 * 타입변환연산자
 * operator (변환하고자 하는 타입) ()
 */
TEST_CASE("int wrapper")
{
	SUBCASE("wrapper")
	{
		Int x = 3;
		int a = x + 4;
		CHECK(a == 7);
	}

	SUBCASE("a++, ++a")
	{
		Test t(3);

		//func(++t); // 4
		//func(t++); // 4 가 출력됨
		//std::cout << "x : " << t.get_x() << std::endl;
	}
}
