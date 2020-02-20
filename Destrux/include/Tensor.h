#pragma once
#include <Eigen/Core>
#include <Eigen/Dense>
#include <tuple>
namespace Destrux {
    enum class Handedness { Left, Right };
    class Tensor : public Eigen::Matrix3d
    {
    public:
        Tensor(void) : Eigen::Matrix3d() {}
        // This constructor allows you to construct MyVectorType from Eigen expressions
        template<typename OtherDerived>
        Tensor(const Eigen::MatrixBase<OtherDerived>& other)
            : Eigen::Matrix3d(other)
        { }

        template<typename OtherDerived>
        Tensor& operator=(const Eigen::MatrixBase<OtherDerived>& other);

        bool TheoreticalDecomposition(Tensor&, Tensor&, Handedness);
        bool PolarDecomposition(Tensor&, Tensor&, Handedness);
    };

}