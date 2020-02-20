#pragma once
#include "Tetrahedron.h"
#include <Eigen/Dense>
#include <tuple>

typedef Eigen::Matrix<double, 12, 1> Vector12d;
typedef Eigen::Matrix<double, 4, 1> Vector4d;

template <typename T, int N, int O>
Eigen::Matrix<T, N-1, N-1, O, N-1, N-1> Submatrix(Eigen::Matrix<T, N, N, O, N, N> Mat, int i, int j)
{
	
	Eigen::Matrix<T, N-1, N-1> Submatrix;
	int a, b = 0;
	for (int x = 0; x < N; x++) {
		b = 0;
		for (int y = 0; y < N; y++) {
			if (x != i && y != j) {
				Submatrix(a, b) = Mat(x, y);
			}
			b++;
		}
		a++;
	}
	return Submatrix;
}

template <typename T, int N, int O>
T Minor(Eigen::Matrix<T, N, N, O, N, N> Mat, int i, int j) {
	return Submatrix(Mat, i, j).determinant();
}
template <typename T, int N, int O >
T Cofactor(Eigen::Matrix<T, N, N, O, N, N> Mat, int i, int j) {
	T C;

	bool even = (i + j % 2) == 0;
	if (even) {
		C = Minor(Mat, i, j);
	}
	else {
		C = -1.0 * Minor(Mat, i, j)T;
	}
	return C;
}

enum Handedness { Left, Right };

std::tuple<Eigen::Matrix3d, Eigen::Matrix3d> PolarDecomposition(Eigen::Matrix3d F, Handedness handedness ) {
	bool hasConverged = false;
	Eigen::Matrix3d R, StretchTensor;
	Eigen::Matrix3d R_old = F;
	while (!hasConverged) {
		R = iterate(R_old);
		if (R == R_old) {
			hasConverged = true;
		}
		R_old = R;
	}
	if (handedness = Left) {
		// F = VR -> V = FInverse(R)
		StretchTensor = F * R.inverse();

	}
	else {
		// F = RU -> U = Inverse(R)*F
		StretchTensor = R.inverse() * F;
	}
	return std::make_tuple(R, StretchTensor);
}

Eigen::Matrix3d iterate(Eigen::Matrix3d mat) {
	Eigen::Matrix3d inverseTranspose = mat.transpose().inverse();
	return 0.5 * (mat + inverseTranspose);
}

class TetrahedronAnalysis
{
private:
	Vector12d q;
	Eigen::Matrix<double, 4, 4> C;
	Eigen::Matrix<double, 4, 4> Coordinates;
	double Volume;
public:
	TetrahedronAnalysis();
	TetrahedronAnalysis(Vector12d _q);
	Vector4d CalculateGammas();
	double shape(int j, double x, double y, double z);
};

