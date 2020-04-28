//  Matt Perry, Tailon Russell, Chenyi Ling, McKade Sorensen
// Tests geneated from discord and others from cs372
#include "catch.hpp"
#include "shape.hpp"

#define CATCH_CONFIG_FAST_COMPILE

TEST_CASE("getHeight and getWidth functions")
{
	SECTION("Circle getHeight")
	{
		INFO("Radius 5 -> Height 10")
			REQUIRE(makeCircle(5)->getHeight() == 10);

		INFO("Radius 3 -> Height 6")
			REQUIRE(makeCircle(3)->getHeight() == 6);

		INFO("Radius 100 -> Height 200")
			REQUIRE(makeCircle(100)->getHeight() == 200);
	}

	SECTION("Circle getWidth")
	{
		INFO("Radius 7 -> Width 14");
		REQUIRE(makeCircle(7)->getWidth() == 14);

		INFO("Radius 12 -> Width 24");
		REQUIRE(makeCircle(12)->getWidth() == 24);

		INFO("Radius 250 -> Width 500");
		REQUIRE(makeCircle(250)->getWidth() == 500);
	}
}

TEST_CASE("Polygon getHeight and getWidth")
{
	SECTION("Polygon getHeight: _numSides is odd")
	{
		INFO("3 sides, length 2");
		REQUIRE(makePolygon(3, 2)->getHeight() ==
			2 * (1 + cos(M_PI / 3)) / (2 * sin(M_PI / 3)));

		INFO("5 sides, length 2.4");
		REQUIRE(makePolygon(5, 2.4)->getHeight() ==
			2.4 * (1 + cos(M_PI / 5)) / (2 * sin(M_PI / 5)));
	}

	SECTION("Polygon getWidth: _numSides is odd")
	{
		INFO("3 sides, length 2");
		REQUIRE(makePolygon(3, 2)->getWidth() == 2);

		INFO("5 sides, length 2.4");
		REQUIRE(makePolygon(5, 2.4)->getWidth() ==
			(2.4 * sin(M_PI * (5 - 1) / (2 * 5))) / sin(M_PI / 5));
	}

	SECTION("Polygon getHeight: _numSides divisible by 4")
	{
		INFO("4 sides, length 5");
		REQUIRE(makePolygon(4, 5)->getHeight() == (5 * (cos(M_PI / 4))) / sin(M_PI / 4));

		INFO("16 sides, length 20");
		REQUIRE(makePolygon(16, 20)->getHeight() == (20 * (cos(M_PI / 16))) / sin(M_PI / 16));
	}

	SECTION("Polygon getWidth: _numSides divisible by 4")
	{
		INFO("4 sides, length 5");
		REQUIRE(makePolygon(4, 5)->getWidth() == ((5 * cos(M_PI / 4)) / sin(M_PI / 4)));

		INFO("16 sides, length 20");
		REQUIRE(makePolygon(16, 20)->getWidth() == ((20 * cos(M_PI / 16)) / sin(M_PI / 16)));
	}

	SECTION("Polygon getHeight: _numSides divisible by 2, but not 4")
	{
		INFO("6 sides, length 7");
		REQUIRE(makePolygon(6, 7)->getHeight() == (7 * cos(M_PI / 6) / sin(M_PI / 6)));

		INFO("10 sides, length 15");
		REQUIRE(makePolygon(10, 15)->getHeight() == (15 * cos(M_PI / 10) / sin(M_PI / 10)));
	}

	SECTION("Polygon getWidth: _numSides divisible by 2, but not 4")
	{
		INFO("6 sides, length 7");
		REQUIRE(makePolygon(6, 7)->getWidth() == (7 / sin(M_PI / 6)));

		INFO("10 sides, length 15");
		REQUIRE(makePolygon(10, 15)->getWidth() == (15 / sin(M_PI / 10)));
	}
}

TEST_CASE("Rectangle getHeight and getWidth")
{
	SECTION("Rectangle getHeight")
	{
		INFO("Width 8, Height 4");
		REQUIRE(makeRectangle(8, 4)->getHeight() == 4);

		INFO("Width 17, Height 32");
		REQUIRE(makeRectangle(17, 32)->getHeight() == 32);
	}

	SECTION("Rectangle getWidth")
	{
		INFO("Width 8, Height 4");
		REQUIRE(makeRectangle(8, 4)->getWidth() == 8);

		INFO("Width 17, Height 32");
		REQUIRE(makeRectangle(17, 32)->getWidth() == 17);
	}
}

TEST_CASE("Spacer getHeight and getWidth")
{
	SECTION("Spacer getHeight")
	{
		INFO("Width 8, Height 4");
		REQUIRE(makeSpacer(8, 4)->getHeight() == 4);

		INFO("Width 17, Height 32");
		REQUIRE(makeSpacer(17, 32)->getHeight() == 32);
	}

	SECTION("Spacer getWidth")
	{
		INFO("Width 8, Height 4");
		REQUIRE(makeSpacer(8, 4)->getWidth() == 8);

		INFO("Width 17, Height 32");
		REQUIRE(makeSpacer(17, 32)->getWidth() == 17);
	}
}

TEST_CASE("Triangle getHeight and getWidth")
{
	SECTION("Triangle getHeight")
	{
		INFO("Length 4");
		REQUIRE(makeTriangle(4)->getHeight() == 4 * (1 + cos(M_PI / 3)) / (2 * sin(M_PI / 3)));

		INFO("Triangle(4) == Polygon(3, 4)");
		REQUIRE(makeTriangle(4)->getHeight() == Polygon(3, 4).getHeight());

		INFO("Length 17");
		REQUIRE(makeTriangle(17)->getHeight() == 17 * (1 + cos(M_PI / 3)) / (2 * sin(M_PI / 3)));
	}

	SECTION("Triangle getWidth")
	{
		INFO("Length 4");
		REQUIRE(makeTriangle(4)->getWidth() == (4 * sin(M_PI * (3 - 1.0) / (2.0 * 3))) / sin(M_PI / 3));

		INFO("Triangle(4) == Polygon(3, 4)");
		REQUIRE(makeTriangle(4)->getWidth() == Polygon(3, 4).getWidth());

		INFO("Length 17");
		REQUIRE(makeTriangle(17)->getWidth() == (17 * sin(M_PI * (3 - 1.0) / (2.0 * 3))) / sin(M_PI / 3));
	}
}

TEST_CASE("RotatedShape getHeight and getWidth")
{
	SECTION("RotatedShape getHeight")
	{
		INFO("Rectangle(3, 4), rotated 90 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(3, 4), Angle::R90)->getHeight() == 3);

		INFO("Rectangle(3, 4), rotated 270 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(3, 4), Angle::R270)->getHeight() == 3);

		INFO("Rectangle(3, 4), rotated 180 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(3, 4), Angle::R180)->getHeight() == 4);

		INFO("Circle(17), rotated 90 degrees");
		REQUIRE(makeRotatedShape(makeCircle(17), Angle::R90)->getHeight() == 34);

		INFO("Triangle(17, 34), rotated 270 degrees");
		REQUIRE(makeRotatedShape(makeTriangle(17), Angle::R270)->getHeight() == 
			makeTriangle(17)->getWidth());

		INFO("Rectangle(17, 34), rotated 180 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(17, 34), Angle::R180)->getHeight() == 34);
	}

	SECTION("RotatedShape getWidth")
	{
		INFO("Rectangle(3, 4), rotated 90 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(3, 4), Angle::R90)->getWidth() == 4);

		INFO("Rectangle(3, 4), rotated 270 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(3, 4), Angle::R270)->getWidth() == 4);

		INFO("Rectangle(3, 4), rotated 180 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(3, 4), Angle::R180)->getWidth() == 3);

		INFO("Circle(17), rotated 90 degrees")
			REQUIRE(makeRotatedShape(makeCircle(17), Angle::R90)->getWidth() == 34);

		INFO("Triangle(17, 34), rotated 270 degrees");
		REQUIRE(makeRotatedShape(makeTriangle(17), Angle::R270)->getWidth() == 
			makeTriangle(17)->getHeight());

		INFO("Rectangle(17, 34), rotated 180 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(17, 34), Angle::R180)->getWidth() == 17);
	}
	
}

TEST_CASE("getHeight and getWidth functions Custom Shape")
{
	SECTION("Custom getHeight")
	{
		INFO("Radius 7 -> Width 14");
		REQUIRE(makeCustom(8,2,4)->getHeight() == 16);

		INFO("Radius 12 -> Width 24");
		REQUIRE(makeCustom(15,2,5)->getHeight() == 30);

		INFO("Radius 250 -> Width 500");
		REQUIRE(makeCustom(152,15,75)->getHeight() == 304);
	}

	SECTION("Custom getWidth")
	{
		INFO("Radius 7 -> Width 14");
		REQUIRE(makeCustom(7,2,4)->getWidth() == 14);

		INFO("Radius 12 -> Width 24");
		REQUIRE(makeCustom(12,4,4)->getWidth() == 24);

		INFO("Radius 250 -> Width 500");
		REQUIRE(makeCustom(250,15,125)->getWidth() == 500);
	}
}