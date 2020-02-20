#include "pch.h"
#include "CppUnitTest.h"
#include <Eigen/Dense>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DestruxTest
{
	TEST_CLASS(MatrixTest)
	{
	public:
		Eigen::Matrix<double, 4, 4> mat_d4x4;
		Eigen::Matrix<int, 3, 3> mat_i3x3;
		TEST_CLASS_INITIALIZE(initialize) {
			mat_i3x3 = new Eigen::Matrix<int, 3, 3>();
			mat_i3x3.operator<<(2, -1, 3,
				1, 4, -2,
				7, 5, 8);
		}
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(Destrux::Minor(mat_i3x3, 0, 0), 42);
			Assert::AreEqual(Minor(mat_i3x3, 0, 1), 22);
		}
	};
}
