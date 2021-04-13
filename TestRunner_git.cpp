#include <gtest/gtest.h>
#include "TestRunner.h"
#include "../Product.h"
#include "../UnpackedFood.h"
#include "../PrepackedFood.h"
#include <sstream>
#include <string>
#include <iostream>

//Product class//
//Testing the constructor
TEST(ProductConst, Test1) {
	Product p1;
	ASSERT_EQ("",p1.getName());
	ASSERT_EQ(0, p1.getBarCode());
}

TEST(ProductConst, Test2) {
	Product p1("Coffee", 1232);
	ASSERT_EQ("Coffee", p1.getName());
	ASSERT_EQ(1232, p1.getBarCode());
}

TEST(ProductConst, Test3) {
	Product p1("Flour", 1230);
	ASSERT_EQ("Flour", p1.getName());
	ASSERT_EQ(1230, p1.getBarCode());
}

TEST(ProductConst, Test4) {
	Product p1("Milk", 1237.7);
	ASSERT_EQ("Milk", p1.getName());
	ASSERT_EQ(1237, p1.getBarCode());
}

//Testing enterProductAttributes()
TEST(enterProductAttributesFUNC, Test1) {
	Product p1;
	std::istringstream input("Nutmeg\n1232\n");
	std::cin.rdbuf(input.rdbuf());

	p1.enterProductAttributes();

	ASSERT_EQ("Nutmeg", p1.getName());
	ASSERT_EQ(1232, p1.getBarCode());
}

TEST(enterProductAttributesFUNC, Test2) {
	Product p1;
	std::istringstream input("\n0\n");
	std::cin.rdbuf(input.rdbuf());

	p1.enterProductAttributes();

	ASSERT_EQ("", p1.getName());
	ASSERT_EQ(0, p1.getBarCode());
}

TEST(enterProductAttributesFUNC, Test3) {
	Product p1;
	std::istringstream input("\n5050\n");
	std::cin.rdbuf(input.rdbuf());

	p1.enterProductAttributes();

	ASSERT_EQ("", p1.getName());
	ASSERT_EQ(5050, p1.getBarCode());
}

TEST(enterProductAttributesFUNC, Test4) {
	Product p1;
	std::istringstream input("Nutmeg\n1232.5\n");
	std::cin.rdbuf(input.rdbuf());

	p1.enterProductAttributes();

	ASSERT_EQ("Nutmeg", p1.getName());
	ASSERT_EQ(1232, p1.getBarCode());
}

//Unpacked Food Class//
//Testing the constructor
TEST(UnpackFoodConst, Test1) {
	UnpackedFood food1;

	ASSERT_EQ("", food1.getName());
	ASSERT_EQ(0, food1.getBarCode());
	ASSERT_DOUBLE_EQ(0.0, food1.getWeight());
	ASSERT_DOUBLE_EQ(0.0, food1.getPrice());
}

TEST(UnpackFoodConst, Test2) {
	UnpackedFood food1("Pumpkin", 7890, 0.99, 4);

	ASSERT_EQ("Pumpkin", food1.getName());
	ASSERT_EQ(7890, food1.getBarCode());
	ASSERT_DOUBLE_EQ(0.99, food1.getWeight());
	ASSERT_DOUBLE_EQ(4, food1.getPrice());
}

TEST(UnpackFoodConst, Test3) {
	UnpackedFood food1("Squash", 7892, 2, 2);

	ASSERT_EQ("Squash", food1.getName());
	ASSERT_EQ(7892, food1.getBarCode());
	ASSERT_DOUBLE_EQ(2, food1.getWeight());
	ASSERT_DOUBLE_EQ(2, food1.getPrice());
}

TEST(UnpackFoodConst, Test4) {
	UnpackedFood food1("Banana");

	ASSERT_EQ("Banana", food1.getName());
	ASSERT_EQ(0, food1.getBarCode());
	ASSERT_DOUBLE_EQ(0.0, food1.getWeight());
	ASSERT_DOUBLE_EQ(0.0, food1.getPrice());
}

//TESTING enterProductAttributes()
TEST(enterProductAttributesUF, Test1) {
	UnpackedFood food1;

	std::istringstream input("Squash\n7892\n4\n2\n");
	std::cin.rdbuf(input.rdbuf());

	food1.enterProductAttributes();

	ASSERT_EQ("Squash", food1.getName());
	ASSERT_EQ(7892, food1.getBarCode());
	ASSERT_DOUBLE_EQ(2, food1.getWeight());
	ASSERT_DOUBLE_EQ(4, food1.getPrice());
}

TEST(enterProductAttributesUF, Test2) {
	UnpackedFood food1;

	std::istringstream input("Eggplant\n7891\n2.5\n0.5\n");
	std::cin.rdbuf(input.rdbuf());

	food1.enterProductAttributes();

	ASSERT_EQ("Eggplant", food1.getName());
	ASSERT_EQ(7891, food1.getBarCode());
	ASSERT_DOUBLE_EQ(0.5, food1.getWeight());
	ASSERT_DOUBLE_EQ(2.5, food1.getPrice());
}

TEST(enterProductAttributesUF, Test3) {
	UnpackedFood food1;

	std::istringstream input("Pumpkin\n0\n0\n2.5\n");
	std::cin.rdbuf(input.rdbuf());

	food1.enterProductAttributes();

	ASSERT_EQ("Pumpkin", food1.getName());
	ASSERT_EQ(0, food1.getBarCode());
	ASSERT_DOUBLE_EQ(2.5, food1.getWeight());
	ASSERT_DOUBLE_EQ(0, food1.getPrice());
}

TEST(enterProductAttributesUF, Test4) {
	UnpackedFood food1;

	std::istringstream input("Pumpkin");
	std::cin.rdbuf(input.rdbuf());

	food1.enterProductAttributes();

	ASSERT_EQ("Pumpkin", food1.getName());
	ASSERT_EQ(0, food1.getBarCode());
	ASSERT_DOUBLE_EQ(0, food1.getWeight());
	ASSERT_DOUBLE_EQ(0, food1.getPrice());
}


int TestRunner(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
