//inline Scalar at(uint i, uint j) const { return this->operator()(i, j); }
//inline MatrixBase<Derived> Minor(int i, int j)
//{
//	int newRows = internal::traits<Derived>::RowsAtCompileTime - 1;
//	Matrix<Scalar, newRows, newRows> MatrixMinor;
//	int a, b = 0;
//	for (int x = 0; x < this->rows(); x++) {
//		b = 0;
//		for (int y = 0; y < this->cols(); y++) {
//			if (x != i && y != j) {
//				MatrixMinor(a, b) = this->operator()(x, y);
//			}
//			b++;
//		}
//		a++;
//	}
//	return MatrixMinor;
//}
//
//
//inline Scalar Cofactor(int i, int j) {
//	Scalar C;
//	bool even = (i + j % 2) == 0;
//	if (even) {
//		C = this->determinant();
//	}
//	else {
//		C = -1.0 * this->determinant();
//	}
//	return C;
//}