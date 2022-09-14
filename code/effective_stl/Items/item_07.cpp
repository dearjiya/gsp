#include <doctest/doctest.h>

#include <fstream>
#include <list>
#include <vector>

namespace
{
}

/**
 * new로 할당된 포인터를 갖는 컨테이너가 shared_ptr이나 unique_ptr이 아닌 경우는 이제 
 * 없도록 하는 것이 더 나아 보인다. raw ptr를 쓰는 경우는 잊기 쉬울 수도 있다. 
 */
TEST_CASE("item 07. when using containers of newed pointers,  remember to delete the pointers before the container is destroyed")
{
  /**
   * 
   */
  SUBCASE("")
  {
  }
}
