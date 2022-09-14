#include <doctest/doctest.h>

#include <fstream>
#include <list>
#include <vector>

namespace
{
}

/**
 * auto_ptr is deprecated. is it still valid for unique_ptr?
 */
TEST_CASE("item 08. nerver create containers of auto_ptr")
{
  /**
   * 
   */
  SUBCASE("unique_ptr")
  {
    std::unique_ptr<int> p1 = std::make_unique<int>(1);

    // 아래 모두 컴파일 에러이다.
    // std::unique_ptr<int> p2{p1};
    // std::unique_ptr<int> p2 = p1;

    // unique_ptr은 복사 / 할당 될 수 없다. auto_ptr은 가능했다. 
  }
}
