#include "pch.h"
#include "CppUnitTest.h"
#include <Eigen/Dense>
#include "Tensor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DestruxTest
{
	TEST_CLASS(TensorTest)
	{
	public:
		Destrux::Tensor A;
		Destrux::Tensor B;
		Destrux::Tensor F;
		TEST_CLASS_INITIALIZE(initialize) {
			F << 21, 21, 20,
				40, 31, 36,
				30, 28, 28;
			A <<
		}
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual
		}
	};
}
