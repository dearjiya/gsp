#include <doctest/doctest.h>

#include <list>

namespace
{
}

/**
 * ���� �������̶�� �� �� �ִ�. empty()�� ��� �����̳ʿ��� O(1)�̴�.
 * ������ size()�� std::listó�� O(n)�� �� �ִ�. 
 */
TEST_CASE("item 04. call empty() instead of checking size() against 0")
{
  /**
   * std::list::size() ������ visual c++���� O(1)�̴�. �̴� ������ 
   * size_ �ʵ带 �����ؼ� ��´�. �̴� å������ ����� �����̴�. 
   * std::list::splice()�� �����Ѱ�? 
   */
  SUBCASE("std::list::size()")
  {
    std::list<int> ls{ 1, 2, 3 };

    CHECK(ls.size() == 3);
  }
}
