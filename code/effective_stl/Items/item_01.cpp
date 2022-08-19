#include <doctest/doctest.h>

#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

TEST_CASE("item 01. Choose your containers with care")
{

  SUBCASE("containers in stl")
  {
    SUBCASE("array")
    {
      std::array<int, 10> ia{ 1, 2, 3, 4 };

      ia[4] = 5;

      CHECK(ia[0] == 1);
      CHECK(ia[4] == 5);
      CHECK(ia[5] == 0); // works in debug and release build

      int v{}; // default value for int is 0 
      CHECK(v == 0);
    }

    SUBCASE("deque")
    {
      std::deque<int> d{ 1, 3, 0 };

      CHECK(d.front() == 1);
      CHECK(d.back() == 0);

      d.pop_front();
      CHECK(d.front() == 3);

      d.pop_back();
      CHECK(d.back() == 3);

      d.push_front(5);
      CHECK(d.front() == 5);
    }

    SUBCASE("foward_list")
    {
      std::forward_list<int> fl{ 1, 3, 2 };

      CHECK(*fl.cbegin() == 1);
    }

    SUBCASE("multimap")
    {
      std::multimap<int, std::string> iks{ {0, "a"}, {0, "b"}, {1, "c"}, {1, "d"}};

      auto bi = iks.lower_bound(0);
      auto ei = iks.upper_bound(0);

      for (auto ii = bi; ii != ei; ++ii)
      {
        std::cout << ii->second << std::endl;
      }
    }

    // TODO: there are more, but other items will drive test cases.
  }
}