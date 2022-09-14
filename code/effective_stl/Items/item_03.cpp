#include <doctest/doctest.h>

namespace
{

class Copy
{
public: 
  Copy() 
    : n_assign_called_{ 0 } 
    , n_copy_called_{ 0 }
  {}

  Copy(const Copy& rhs)
  {
    n_copy_called_ = rhs.n_copy_called_;
    ++n_copy_called_;
  }

  Copy& operator=(const Copy& rhs)
  {
    ++n_assign_called_;
    return *this;
  }

  size_t GetNumberOfCopyCalled() const
  {
    return n_copy_called_;
  }

  size_t GetNumberOfAssignCalled() const
  {
    return n_assign_called_;
  }
  
private:
  size_t n_copy_called_;
  size_t n_assign_called_;
};

} // namespace

/**
 * 포인터를 사용하지 않고 오브젝트를 직접 사용할 경우 컨테이너에 들어가는 
 * 오브젝트는 복사된 오브젝트이다. 얻을 때도 참조로 얻지 않으면 
 * 복사된다. 따라서, 오브젝트 복사가 효율적이고 정확해야 한다.
 */
TEST_CASE("item 03. Make copying cheap and correct for objects in containers")
{
  /**
   * 언제 copy construction이 되고 언제 assignment operator가 호출되는가?
   *
   * 아래에 잘 나와있다. 핵심은 이미 있는 오브젝트에 다른 오브젝트를 지정할 때 
   * 할당 연산자가 호출된다. 생성과 동시에 다른 오브젝트를 복사할 때는 
   * 복사 생성자가 호출된다.
   * https://www.geeksforgeeks.org/copy-constructor-vs-assignment-operator-in-c/
   */
  SUBCASE("copy constructor and assignment operator")
  {
    SUBCASE("copy constructor")
    {
      Copy c1 = Copy{}; 
      // temp object does not call copy constructor nor assignment operator. 
      // why? because it is the object with the default construction
      CHECK(c1.GetNumberOfCopyCalled() == 0);

      Copy c2{ c1 };
      CHECK(c2.GetNumberOfCopyCalled() == 1);
    }

    SUBCASE("assignment operator")
    {
      Copy c1{};
      Copy c2{};

      c2 = c1; 
      CHECK(c2.GetNumberOfAssignCalled() == 1);

      c2 = c1; 
      CHECK(c2.GetNumberOfAssignCalled() == 2);
    }
  }
}