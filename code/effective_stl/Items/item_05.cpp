#include <doctest/doctest.h>

#include <list>
#include <vector>

namespace
{
}

/**
 * std::vector::assign과 같이 범위에 대해 동작하는 함수가 훨씬 효율적이다. 
 */
TEST_CASE("item 05. prefer range member functions to their single-element counterparts")
{
  /**
   * 
   */
  SUBCASE("std::vector::insert()")
  {
    std::vector<int> vs1{ 1, 2, 3 };
    std::vector<int> vs2{ 10, 20, 30 };

    vs1.insert(vs1.end(), vs2.begin(), vs2.end());

    CHECK(vs1[3] == 10);
  }
}
