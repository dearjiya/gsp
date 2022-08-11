#include <doctest/doctest.h>

TEST_CASE("copy constructor")
{
	/**
	 * ��������ڴ� �����ΰ�? �� �ʿ��Ѱ�? ��� ���°�?
	 * 
	 * - Ŭ������ �ܺο� �������̽��� ���ؼ��� ����� �� �ִ�. 
	 * - Ŭ������ Ÿ���̰� ������ �Ҵ��� �� �ִ�. 
	 * - �̹� �ִ� Ŭ���� �ν��Ͻ��� �ٸ� ������ �Ҵ��� �� �ֵ��� �ϱ����� ���� �����ڰ� �ʿ��ϴ�.
	 */
	SUBCASE("intro")
	{
		SUBCASE("copy constructor generated from the c++ compiler")
		{
			class Simple
			{
			public:
				Simple()
					: v_(0)
				{
				}

				Simple(int v)
					: v_(v)
				{
				}

				int GetValue() const
				{
					return v_;
				}

				Simple(const Simple& rhs) = default;

			private:
				int v_;
			};

			Simple v(3);
			Simple v2 = v;
			CHECK(v2.GetValue() == 3);
		}

		SUBCASE("custom copy constructor") 
		{
			class Simple
			{
			public:
				Simple()
					: v_(0)
				{
				}

				Simple(int v)
					: v_(v)
				{
				}

				int GetValue() const
				{
					return v_;
				}

				Simple(const Simple& rhs)
				{
					v_ = rhs.v_ + 1;
				}

			private:
				int v_;
			};

			Simple v(3);
			Simple v2 = v;
			CHECK(v2.GetValue() == 4);
		}
	}

	/**
	 * intro���� ��κ��� ��ʴ� ����Ǿ����� C++�� �� ���鼭 
	 * �ʿ��� �κе��� ����� ����� ���ƿͼ� �߰��� �����Ѵ�. (2022.08.11)
	 */
	SUBCASE("use case")
	{

	}
}