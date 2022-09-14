#include <doctest/doctest.h>

#include <fstream>
#include <list>
#include <vector>

namespace
{
}

/**
 * vexing : annoying 
 */
TEST_CASE("item 06. be alert of c++'s most vexing pasrse")
{
  /**
   * 
   */
  SUBCASE("separate declarations for complicated use cases")
  {
    std::ifstream dataFile(" ints.dat");
    std::istream_iterator<int> dataBegin(dataFile);
    std::istream_iterator<int> dataEnd;
    std::list<int> data(dataBegin, dataEnd);
  }
}
