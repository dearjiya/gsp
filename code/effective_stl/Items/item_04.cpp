#include <doctest/doctest.h>

#include <list>

namespace
{
}

/**
 * 작은 아이템이라고 할 수 있다. empty()는 모든 컨텐이너에서 O(1)이다.
 * 하지만 size()는 std::list처럼 O(n)일 수 있다. 
 */
TEST_CASE("item 04. call empty() instead of checking size() against 0")
{
  /**
   * std::list::size() 구현이 visual c++에서 O(1)이다. 이는 별도의 
   * size_ 필드를 유지해서 얻는다. 이는 책에서도 언급한 내용이다. 
   * std::list::splice()는 유용한가? 
   */
  SUBCASE("std::list::size()")
  {
    std::list<int> ls{ 1, 2, 3 };

    CHECK(ls.size() == 3);
  }
}
