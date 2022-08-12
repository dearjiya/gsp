#include <doctest/doctest.h>

#include <vector>

namespace
{

} // namespace

/**
 * explicit와 mutable은 별도의 개념이고 간단한 정의를 갖는다. 
 * 
 * - explicit는 생성자에서 타잎을 암묵적(implicit)으로 변환하지 않도록 지정한다.
 * - mutable은 const 함수에서 변경 가능한 변수를 지정한다. 
 */
TEST_CASE("explicit_mutable")
{
	/**
	 * float에서 int로 암묵적인 변환이 explicit를 지정한 생성자에서 
	 * 이루어지고, 컴파일러에서는 경고만 보여준다. 
	 */
	SUBCASE("explicit")
	{
		class ExplicitTest
		{
		public:
			explicit ExplicitTest(int v)
				: v_{ v }
			{}

		private:
			int v_;
		};

		ExplicitTest test(1.1f);
	}

	/**
	 * @see class_const_static_member.cpp / SUBCASE("const member function")
	 * 위 파일의 서브케이스 안에 mutable 멤버 변수를 변경하는 const 함수의 
	 * 예시가 있다. 
	 */
	SUBCASE("mutable")
	{
	}
}
