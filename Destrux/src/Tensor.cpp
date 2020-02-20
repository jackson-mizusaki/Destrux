#include "pch.h"
#include "Tensor.h"
namespace Destrux {
	template<typename OtherDerived>
	inline Tensor& Tensor::operator=(const Eigen::MatrixBase<OtherDerived>& other)
	{
		this->Eigen::Matrix3d::operator=(other);
		return *this;
	}


	Tensor iterate(Tensor t) {
		Tensor inverseTranspose = t.transpose().inverse();
		return 0.5 * (t + inverseTranspose);
	}

	void Tensor::PolarDecomposition(Tensor F, Tensor& R, Tensor& StretchTensor, Handedness handedness)
	{
		bool hasConverged = false;
		Tensor R_old = F;
		while (!hasConverged) {
			R = iterate(R_old);
			if (R == R_old) {
				hasConverged = true;
			}
			R_old = R;
		}
		if (handedness == Handedness::Left) {
			// F = VR -> V = FInverse(R)
			StretchTensor = F * R.inverse();

		}
		else {
			// F = RU -> U = Inverse(R)*F
			StretchTensor = R.inverse() * F;
		}

	}
}