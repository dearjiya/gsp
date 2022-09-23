#include <doctest/doctest.h>
#include <iostream>
#include <list>
#include <Header/Vector.h>

namespace
{
}

TEST_CASE("Essential Operations / Introduction")
{
	SUBCASE("understand following")
	{
		// Howev er, a copy or move constructor invocation is often optimized away 
		// by constructing the object used to initialize right in the target object.
		// For example : X make(Sometype); X x = make(value); 
		// Here, a compiler will typically construct the X from make() directly in x; 
		// thus eliminating(‘‘elid - ing’’) a copy.
	}

	/**
	 * memberwise copy. std::string member
	 */
	SUBCASE("default generated copy constructor, assignment copy operator")
	{
	}
}
