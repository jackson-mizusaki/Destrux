# Overview
This file acts as a reference and introduction to many of the concepts used with this library. A background in linear algebra is assumed (vectors, matrices, and linearity). 

**Disclaimer: I do not have a formal education in continuum mechanics. The notes contained herein are my own, as i learn the principles of continuum mechanics and the finitie element method, and do not constitute a full course in such disciplines. Although i am using multiple sources to confirm my understanding of each concept, do not assume correctness of anything presented.**

# Descriptions and Coordinates
## Material Description
Material descriptions follow a particle within the body through space over time.

Changes to a body during deformation can be expressed as a change from the body's initial state.

Material coordinates are expressed by an uppercase **X** and are in relation to Cartesian bases ![\mathbf{E_{1}}, \mathbf{E_{2}}, \mathbf{E_{3}}](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7BE_%7B1%7D%7D%2C%20%5Cmathbf%7BE_%7B2%7D%7D%2C%20%5Cmathbf%7BE_%7B3%7D%7D)

## Spatial Description
Spatial descriptions examine a fixed point in space and describe which particles of a body are at that point over time.

Spatial coordinates are expressed by a lowercase x and are in relation to Cartesian bases ![\mathbf{e_{1}}, \mathbf{e_{2}}, \mathbf{e_{3}}](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7Be_%7B1%7D%7D%2C%20%5Cmathbf%7Be_%7B2%7D%7D%2C%20%5Cmathbf%7Be_%7B3%7D%7D) 

Consider a body with a particle at point **X** at time ![t_{0} = 0](https://render.githubusercontent.com/render/math?math=t_%7B0%7D%20%3D%200)

The position of that particle at the current time *t* can be expressed as the point **x**, where 
![\mathbf{x} = \Phi(\mathbf{X}, t)](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7Bx%7D%20%3D%20%5CPhi(%5Cmathbf%7BX%7D%2C%20t))

![\Phi](https://render.githubusercontent.com/render/math?math=%5CPhi) is a map between the coordinate of the particle in the initial material description to the coordinate in the current spatial description, i.e., its displacement.

The equivalent function that does not change between spatial and material descriptions is simply the displacement function, denoted by **u**:

![\mathbf{x_{t}} = u(\mathbf{x},t)](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7Bx_%7Bt%7D%7D%20%3D%20u(%5Cmathbf%7Bx%7D%2Ct))


The relation between **u** and **Φ** is expressed by

![u(\mathbf{x},t) = \Phi(\mathbf{X},t) - \mathbf{X_{0}}](https://render.githubusercontent.com/render/math?math=u(%5Cmathbf%7Bx%7D%2Ct)%20%3D%20%5CPhi(%5Cmathbf%7BX%7D%2Ct)%20-%20%5Cmathbf%7BX_%7B0%7D%7D)

One can translate between spatial and material coordinates by "push-forward" and "pull-back" operations. In general, such operators are defined (perhaps confusingly) by the functions Φ for push-forward, and Φ* for pull-back. In this context, the push-forward and pull-back operators are defined by the Deformation Gradient Tensor ![\mathbf{F}](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7BF%7D) (in different ways, for different operands)


## Deformation Gradient Tensor F
The motivation for using the deformation gradient tensor lies in needing to express the changes in particles after deformation by their positions from the reference configuration. Hence, **F** will relate in some way to the changes of a particle in a spatial description and the change of a particle in a material description. The displacement function **Φ** defined above already gives a relation between the two descriptions. 

**F** is then the gradient of **Φ**

Remember that each point in space is expressed by a 3-tuple. **X** and **x** are actually (X, Y, Z) and (x, y, z). 
The gradient tensor is a 3x3 matrix that looks like the following



[  ∂x/∂X  ∂x/∂Y  ∂x/∂Z  ]

|  ∂y/∂X  ∂y/∂Y  ∂y/∂Z  |

[  ∂z/∂X  ∂z/∂Y  ∂z/∂Z  ]

For formatting's sake, i will use [Einstein notation](https://en.wikipedia.org/wiki/Einstein_notation). Check out [https://www.continuummechanics.org/tensornotationbasic.html] for a nice introduction.

![F_{ij} = \dfrac{\partial x_{i}}{\partial X_{j}}](https://render.githubusercontent.com/render/math?math=F_%7Bij%7D%20%3D%20%5Cdfrac%7B%5Cpartial%20x_%7Bi%7D%7D%7B%5Cpartial%20X_%7Bj%7D%7D)

Note that many texts describe the *i*-th element of a tuple as ![\mathbf{X_{i}}](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7BX_%7Bi%7D%7D) or ![\mathbf{X_{i}}](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7Bx_%7Bi%7D%7D). For example, ∂y/∂Z would be written ∂x_2/∂X_3

This tensor describes the partial derivatives of each point in the current configuration (spatial description) with respect to each the point in the referenceconfiguration (material description).

## Displacement Gradient 
The displacement gradient ∇u is related to the deformation gradient tensor in that 

∇u = **F** - **I** 

where **I** is the identity matrix.

Non-rigorously, ![\nabla\cdot\mathbf{u} = \nabla(\Phi-\mathbf{X}) = \nabla(\Phi)-\nabla(\mathbf{X}) = \mathbf{F}-\mathbf{I}](https://render.githubusercontent.com/render/math?math=%5Cnabla%5Ccdot%5Cmathbf%7Bu%7D%20%3D%20%5Cnabla(%5CPhi-%5Cmathbf%7BX%7D)%20%3D%20%5Cnabla(%5CPhi)-%5Cnabla(%5Cmathbf%7BX%7D)%20%3D%20%5Cmathbf%7BF%7D-%5Cmathbf%7BI%7D)

## Right Cauchy-Green Deformation Tensor **C**
The right Cauchy-Green Deformation Tensor, henceforth the Cauchy-Green tensor, or just **C** when the context obvious, is a tensor obtained by multiplying the transpose of **F** by **F**

![\mathbf{C} = \mathbf{F^{T}F}](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7BC%7D%20%3D%20%5Cmathbf%7BF%5E%7BT%7DF%7D)

It is a symmetrix 3x3 matrix that looks like the following:

![C_{ij} = \dfrac{\partial x_{i}}{\partial X_{j}} \dfrac{\partial x_{j}}{\partial X_{i}}](https://render.githubusercontent.com/render/math?math=C_%7Bij%7D%20%3D%20%5Cdfrac%7B%5Cpartial%20x_%7Bi%7D%7D%7B%5Cpartial%20X_%7Bj%7D%7D%20%5Cdfrac%7B%5Cpartial%20x_%7Bj%7D%7D%7B%5Cpartial%20X_%7Bi%7D%7D)

There is a spatial description version of this tensor, known as the left Cauchy-Green tensor, or the Piola tensor, or the Finger tensor, normally represented by **B** or **b** as

![\mathbf{B} = \mathbf{FF^{T}}](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7BB%7D%20%3D%20%5Cmathbf%7BFF%5E%7BT%7D%7D)

# Strain
Because a body can have a rigid body displacement, i.e, every point in the body moves uniformly through space and does not change in reference to each other, the measure of deformation, strain, is a measure of how the displacement is locally different to its initial configuration. More physically, strain is a measure of a body's stretch or compression, as well as any angular stretching, or shearing.


## Green-Lagrange Strain Tensor E
The Green-Lagrange Strain Tensor **E** is defined as 

![\mathbf{E} = \dfrac{1}{2}(\mathbf{C} - \mathbf{I})](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7BE%7D%20%3D%20%5Cdfrac%7B1%7D%7B2%7D(%5Cmathbf%7BC%7D%20-%20%5Cmathbf%7BI%7D))

where **C** is the Cauchy-Green tensor, and **I** is the Identity tensor

The spatial version, the Eulerian/Almansi strain tensor is represented by **e** and is defined by
![\mathbf{e} = \dfrac{1}{2}(\mathbf{I} - \mathbf{B^{-1}}) ](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7Be%7D%20%3D%20%5Cdfrac%7B1%7D%7B2%7D(%5Cmathbf%7BI%7D%20-%20%5Cmathbf%7BB%5E%7B-1%7D%7D)%20)

## Some More Pull-back operators
The left and right Cauchy-Green tensors are related by

![\mathbf{b} = \mathbf{FCF^{-1}}](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7Bb%7D%20%3D%20%5Cmathbf%7BFCF%5E%7B-1%7D%7D) and

![\mathbf{C} = \mathbf{F^{-1}bF}](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7BC%7D%20%3D%20%5Cmathbf%7BF%5E%7B-1%7DbF%7D)

The Green-lagrange Strain and Eulerian/Almansi Strain tensors are related by

![\mathbf{e} = \mathbf{F^{-T}EF^{-1}}](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7Be%7D%20%3D%20%5Cmathbf%7BF%5E%7B-T%7DEF%5E%7B-1%7D%7D) and

![\mathbf{E} = \mathbf{F^{T}eF}](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7BE%7D%20%3D%20%5Cmathbf%7BF%5E%7BT%7DeF%7D)

# Stress
Stress is related in terms of Force/Area. When a force is applied in the same direction as the normal of the area, it is considered a normal stress, and represented by σ. When the force is orthogonal to the normal of the area, it is a shear stress, represented by τ

## Cauchy Stress Tensor σ
The Cauchy stress Tensor σ is a 3x3 matrix that defines the stresses of a material.

[ σ_xx   σ_xy   σ_xz  ]

| σ_yx   σ_yy   σ_yz  |

[ σ_zx   σ_zy   σ_zz  ]

This is related to the traction vector T in the following way

![T_{j}^{(n)} = \sigma_{ij}n_{i}](https://render.githubusercontent.com/render/math?math=T_%7Bj%7D%5E%7B(n)%7D%20%3D%20%5Csigma_%7Bij%7Dn_%7Bi%7D)

The Cauchy stress tensor is evaluated at a single spatial point, and so the traction vector gives the stresses encountered at the point 
