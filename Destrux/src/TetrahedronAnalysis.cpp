#include "pch.h"
#include "TetrahedronAnalysis.h"

TetrahedronAnalysis::TetrahedronAnalysis(Vector12d _q) {
	q = _q;
	Coordinates << 1, q(1), q(2), q(3),
		1, q(4), q(5), q(6),
		1, q(7), q(8), q(9),
		1, q(10), q(11), q(12);
	Volume = Coordinates.determinant() / 6.0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			C(i, j) = Cofactor(Coordinates, i, j);
		}
	}

}

Vector4d TetrahedronAnalysis::CalculateGammas()
{
	Eigen::Matrix<double, 4, 4> adjoint;
	adjoint << 1, 1, 1, 1,
		q(1), q(4), q(7), q(10),
		q(2), q(5), q(8), q(11),
		q(3), q(6), q(9), q(12);

	adjoint.adjointInPlace();
	return Vector4d();
}

double TetrahedronAnalysis::shape(int j, double x, double y, double z)
{
	return (C(0, j) + C(1, j) * x + C(2, j) * y, C(3, j) * z);
}
/*Cofactor(Eigen::Matrix<Scalar,
Dim,
Dim,
0|_Rows==1&&_Cols!=1?Eigen::RowMajor:_Cols==1&&_Rows!=1?0:0,
_Rows,
_Cols>,int,int)': could not deduce template argument for 'Eigen::Matrix<Scalar,Dim,Dim,0|_Rows==1&&_Cols!=1?Eigen::RowMajor:_Cols==1&&_Rows!=1?0:0,_Rows,_Cols>' from 'Eigen::Matrix<double,4,4,0,4,4>'	Destrux	C : \Users\Jackson\source\repos\Destrux\Destrux\TetrahedronAnalysis.cpp	10
*/