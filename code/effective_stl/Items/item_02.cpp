#include <doctest/doctest.h>

TEST_CASE("item 02. Beware the illusion of container independent code")
{
  /**
   * 모든 컨테이너에 대해 동작하는 코드는 비현실적인 시도이다. 
   * 적절한 alias를 typedef나 using으로 제공하면 컨테이너를 교체하기 좀 더 수월해진다. 
   */
  SUBCASE("typedef / using")
  {
  }
}