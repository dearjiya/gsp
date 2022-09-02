#include <doctest/doctest.h>
#include <iostream>
#include <vector>

namespace jiya
{
int func();
} 
namespace Hello
{
int func();
namespace World
{
int func();
}
}

int jiya::func()
{
	return 0;
}
int Hello::func()
{
	return 1;
}
int Hello::World::func()
{	
	return 2;
}
namespace helloworld = Hello::World;

TEST_CASE("Modularity / Namespaces")
{
	SUBCASE("namespace")
	{	
		CHECK(jiya::func() == 0);
		CHECK(Hello::func() == 1);
		using jiya::func;
		CHECK(func() == 0);
		CHECK(Hello::func() == 1);
		CHECK(helloworld::func() == 2);
	}
}
