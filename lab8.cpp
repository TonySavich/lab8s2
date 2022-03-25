#include <iostream>
#include <cassert>
#include "matrix.hpp"

using mt::Mat22d;
using mt::Vec2d;

int main()
{
	std::cout << "=== Test 1 ===" << std::endl;

	{
		Mat22d A({ {
			 {1,2},
			 {3,4}
		} });

		Vec2d X({ {
			{1},
			{1}
		} });

		auto B = A * X;

		assert(B.get(0, 0) == 3);
		assert(B.get(1, 0) == 7);
	}

	std::cout << "Done!" << std::endl;

	std::cout << "=== Test 2 ===" << std::endl;

	{
		Mat22d A({ {
			 {1,1},
			 {1,1}
		} });

		Vec2d X({ {
			{1},
			{1}
		} });

		auto B = A * X;

		assert(B.get(0, 0) == 2);
		assert(B.get(1, 0) == 2);
	}

	std::cout << "Done!" << std::endl;

	
	std::cout << "=== Test 3 ===" << std::endl;

	{
		Mat22d A({ {
			 {1,1},
		 {4,3}
		} });

	

		auto B = A.inv(A);

		assert(B.get(0, 0) == -3);
		assert(B.get(0, 1) == 1);
		assert(B.get(1, 0) == 4);
		assert(B.get(1, 1) == -1);
	}

std::cout << "Done!" << std::endl;



std::cout << "=== Test 4 ===" << std::endl;

{

	mt::Matrix<double, 3, 3> A({ {
			 {1, 0, 1},
		 {8, 1, 5},
		{0, 0, 1}
		} });


	auto B = A.tran(A);

	assert(B.get(0, 0) == 1);
	assert(B.get(0, 1) == 8);
	assert(B.get(0, 2) == 0);
	assert(B.get(1, 0) == 0);
	assert(B.get(1, 1) == 1);
	assert(B.get(1, 2) == 0);
	assert(B.get(2, 0) == 1);
	assert(B.get(2, 1) == 5);
	assert(B.get(2, 2) == 1);
}

std::cout << "Done!" << std::endl;

std::cout << "=== Test 5 ===" << std::endl;

{
	Mat22d A({ {
		 {1,1},
		 {1,1}
	} });

	Mat22d B({ {
		 {1,1},
		 {1,1}
	} });


	auto Z = A +B;

	assert(Z.get(0, 0) == 2);
	assert(Z.get(0, 1) == 2);
	assert(Z.get(1, 0) == 2);
	assert(Z.get(1, 1) == 2);

}

std::cout << "Done!" << std::endl;
std::cout << "=== Test 6 ===" << std::endl;

{
	Mat22d A({ {
		 {1,1},
		 {1,1}
	} });

	Mat22d B({ {
		 {1,1},
		 {1,1}
	} });


	auto Z = A - B;

	assert(Z.get(0, 0) == 0);
	assert(Z.get(0, 1) == 0);
	assert(Z.get(1, 0) == 0);
	assert(Z.get(1, 1) == 0);

}

std::cout << "Done!" << std::endl;
std::cout << "=== Test 7 ===" << std::endl;

{
	Mat22d A({ {
		 {1,7},
		 {6,-2}
	} });



	auto Z = A.det(A);

	assert(Z == -44);


}

std::cout << "Done!" << std::endl;



	return 0;
}
