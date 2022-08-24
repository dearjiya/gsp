#include <doctest/doctest.h>

#include <list>
#include <vector>

namespace
{
}

/**
 * std::vector::assign�� ���� ������ ���� �����ϴ� �Լ��� �ξ� ȿ�����̴�. 
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
