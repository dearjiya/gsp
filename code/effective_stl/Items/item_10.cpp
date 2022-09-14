#include <doctest/doctest.h>

#include <fstream>
#include <list>
#include <vector>

namespace
{
}

/**
 * STL allocator는 가끔 쓸 때가 있다. 내부에 대한 이해와 한계 등을 이해하고 
 * 잘 쓸 수 있는 방법을 설명한다. 무엇을 배울 것인가? 탐구의 자세를 
 * 배우는 것이 더욱 중요하다. 연습은 더 중요하다.
 */
TEST_CASE("item 10. be aware of allocator conventions and restrictions")
{
  /**
   * Scott Meyers는 Ph. D이고 C++에 관해 25년간 일했다.
   * 매우 뛰어난 전문가라 언어에 정통하여 세부에 빠지게 만드는 경향이 강하다. 
   * 물론 세부가 매우 중요한 라이브러리 개발자들이 있지만 우리는 주로 
   * 사용하는 입장이다. 따라서, 주의가 필요하다. 
   * 
   * 특히, Effective STL처럼 이전 버전의 C++에 기초하여 설명할 때는 더 
   * 유의해야 한다. 무엇을 얻을 지 모호할 때가 있고, 잘못된 길로 빠질 수 있다.
   * 
   * 그리고, 이제 C++에서 은퇴했다고 한다.
   */
  SUBCASE("watch out scott meyers")
  {
  }
}
