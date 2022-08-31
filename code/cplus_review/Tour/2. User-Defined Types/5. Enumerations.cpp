#include <doctest/doctest.h>
#include <iostream>
#include <vector>

namespace jiya
{

enum class EnumTest : short {
};

}


TEST_CASE("User-Defined Types/ Enumerations")
{
	/**
	 *
	 */
	SUBCASE("usage")
	{
		SUBCASE("usage - enum class")
		{
			enum class Color
			{
				red,
				pink,
				blue
			};
			enum class Traffic_Light
			{
				yellow,
				red,
				green
			};
			
			// Color x = red; // error: which red?
			// Color y = Traffic_Light::red; // error: that red is not a Color
			Color z = Color::red;
			Traffic_Light light = Traffic_Light::red;
			Color x = Color{ 5 };
			Color y{ 6 };
			CHECK(z ==Color::red);
		}

		SUBCASE("usage - enum")
		{
			enum Color
			{
				red,
				pink,
				blue
			};
			enum Traffic_Light
			{
				yellow,
				green,
				reds // red 중복 에러발생
			};

			int color = red;
			// std::cout << "red:" << color << std::endl;
			// CHECK(color == 0); 
		}
	}
}
