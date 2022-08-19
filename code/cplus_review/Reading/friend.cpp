#include <doctest/doctest.h>


namespace
{
class A
{
private:
	void private_func() {}
	int private_num;

	friend class B;
	friend void func();
};

class B
{
public:
	void b()
	{
		A a;
		a.private_func();
		a.private_num = 2;
	}
};

void func()
{
	A a;
	a.private_func();
	a.private_num = 2;
}
} // namespace
/**
 * class A가 class B와 void 함수 func를 friend 라고 선언했기 때문에 B와 func()은 A의 모든 private을
 * 볼 수 있지만 A는 B의 private 개체에 접근할 수 없다.
 */
TEST_CASE("friend keyword")
{
	SUBCASE("")
	{

	}
}
