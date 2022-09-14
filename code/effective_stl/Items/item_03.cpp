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
 * �����͸� ������� �ʰ� ������Ʈ�� ���� ����� ��� �����̳ʿ� ���� 
 * ������Ʈ�� ����� ������Ʈ�̴�. ���� ���� ������ ���� ������ 
 * ����ȴ�. ����, ������Ʈ ���簡 ȿ�����̰� ��Ȯ�ؾ� �Ѵ�.
 */
TEST_CASE("item 03. Make copying cheap and correct for objects in containers")
{
  /**
   * ���� copy construction�� �ǰ� ���� assignment operator�� ȣ��Ǵ°�?
   *
   * �Ʒ��� �� �����ִ�. �ٽ��� �̹� �ִ� ������Ʈ�� �ٸ� ������Ʈ�� ������ �� 
   * �Ҵ� �����ڰ� ȣ��ȴ�. ������ ���ÿ� �ٸ� ������Ʈ�� ������ ���� 
   * ���� �����ڰ� ȣ��ȴ�.
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