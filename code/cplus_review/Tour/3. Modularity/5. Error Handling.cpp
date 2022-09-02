#include <doctest/doctest.h>
#include <iostream>
#include <vector>

namespace
{

} // namespace

/**
 *
 */
TEST_CASE("Modularity / Error Handling")
{
	/**
	 * usage를 확인한다.  
	 */
	SUBCASE("Exception")
	{

	}

	/**
	 * 읽어 보기. 괜찮아 보이는 방법 써보기
	 */
	SUBCASE("Error Handling - Alternatives")
	{

	}

	SUBCASE("Contracts")
	{
		static_assert(4 == sizeof(int));
	}
}
