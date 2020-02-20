#include "pch.h"
#include "Tensor.h"
#include <functional>
#include <iostream>
#include <Eigen/Eigenvalues>
#include <cmath>


namespace Destrux {
	template<typename OtherDerived>
	inline Tensor& Tensor::operator=(const Eigen::MatrixBase<OtherDerived>& other)
	{
		this->Eigen::Matrix3d::operator=(other);
		return *this;
	}


	void iterate(Tensor &t, bool &invertible) {
		Tensor inverseTranspose;
		t.computeInverseWithCheck(inverseTranspose, invertible);
		inverseTranspose.transposeInPlace();
		t = 0.5 * (t + inverseTranspose);
	}

	bool Tensor::TheoreticalDecomposition(Tensor& R, Tensor& StretchTensor, Handedness handedness) {
		Eigen::Matrix3d Q;
		Tensor F = *this;
		if (handedness == Handedness::Right) {
			Eigen::EigenSolver<Eigen::Matrix3d> es(F.transpose() * F);
			Q = es.eigenvectors().real();
			Eigen::Matrix3d U_sq = es.eigenvalues().real().asDiagonal();
			//std::cout << U_sq << std::endl;
			Eigen::Matrix3d U_prime = (U_sq.array().sqrt()).matrix();
			//std::cout << U_prime << std::endl;
			StretchTensor = Q * U_prime * Q.transpose();

			Eigen::Matrix3d U_inv = StretchTensor.inverse();
			R = F * U_inv;
		}
		else {
			Eigen::EigenSolver<Eigen::Matrix3d> es(F * F.transpose());
			Q = es.eigenvectors().real();
			Eigen::Matrix3d V_sq =es.eigenvalues().real().asDiagonal();
			Eigen::Matrix3d V_prime = (V_sq.array().sqrt()).matrix();
			StretchTensor = Q * V_prime * Q.transpose();

			Eigen::Matrix3d V_inv = StretchTensor.inverse();
			R =  V_inv * F;
		}
		return true;
	}

	/// This iterative algorithm decomposes to  within 10 iterations
	bool Tensor::PolarDecomposition(Tensor& R, Tensor& StretchTensor, Handedness handedness)
	{
		bool hasConverged = false;
		Tensor F = *this;
		Tensor R_old;
		R = F;
		int i = 0;
		while (!hasConverged) {
			bool invertible = true;
			R_old = R;
			iterate(R, invertible);
			if (!invertible) {
				return false;
			}
			Tensor epsilon = R - R_old;
			
			if (epsilon.norm() < 0.001){
				hasConverged = true;
			}
			R_old = R;
			i++;
			std::cout << i << "'th iteration." << std::endl;
		}
		if (handedness == Handedness::Left) {
			// F = VR -> V = FInverse(R)
			StretchTensor = F * R.inverse();

		}
		else {
			// F = RU -> U = Inverse(R)*F
			StretchTensor = R.inverse() * F;
		}
		return true;
	}
}