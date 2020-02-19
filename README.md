# Destrux
A library for realtime deformation and brittle fracture

# Overview
## Material Description
Material descriptions follow a particle within the body through space over time.
Changes to a body during deformation can be expressed as a change from the body's initial state.
Material coordinates are expressed by an uppercase X and are in relation to Cartesian bases E1, E2, and E3.

## Spatial Description
Spatial descriptions examine a fixed point in space and describe which particles of a body are at that point over time.
Spatial coordinates are expressed by a lowercase x and are in relation to Cartesian bases e1, e2, and e3. 

Consider a body with a particle at point X at time t0=0
The position of that particle at the current time t can be expressed as the point x, where 
![\mathbf{x} = \Phi(\mathbf{X}, t)](https://render.githubusercontent.com/render/math?math=%5Cmathbf%7Bx%7D%20%3D%20%5CPhi(%5Cmathbf%7BX%7D%2C%20t)
![\Phi](https://render.githubusercontent.com/render/math?math=%5CPhi) is a map between the coordinate of the particle in the initial material description to the coordinate in the current spatial 
description, i.e., its displacement.

The equivalent function that does not change between spatial and material descriptions is simply the displacement function, denoted by u:
x_t = u(x,t)

The relation between u and Φ is expressed
u(x,t) = Φ(X,t) - X

One can translate between spatial and material coordinates by "push-forward" and "pull-back" operations. In general linear algebra, 
such operators are defined by the functions phi for push-forward, and phi* for pull-back. In this context, the push-forward and pull-back operators 
are defined by the Deformation Gradient Tensor F (in different ways, for different operands)

*Deformation Gradient Tensor F
The motivation for using the deformation gradient tensor lies in needing to express the changes in particles after deformation by their positions 
from the reference configuration. Hence, F will relate in some way to the changes of a particle in a spatial description and the change of a particle
in a material description. The displacement function Φ defined above already expresses the relation between the two descriptions. 
F is then the gradient of Φ
Remember that each point in space is expressed by a 3-tuple. X and x are actually (X, Y, Z) and (x, y, z). 
The gradient tensor is a 3x3 matrix that looks like the following

[  ∂x/∂X  ∂x/∂Y  ∂x/∂Z  ]
|  ∂y/∂X  ∂y/∂Y  ∂y/∂Z  |
[  ∂z/∂X  ∂z/∂Y  ∂z/∂Z  ]

Note that many texts describe the i-th element of a tuple as X_i or x_i. For example, ∂y/∂Z would be written ∂x_2/∂X_3

This tensor describes the partial derivatives of each point in the current configuration (spatial description) with respect to each the point in the reference
configuration (material description).

**Displacement Gradient 
The displacement gradient ∇u is related to the deformation gradient tensor in that 
∇u = F - I
where I is the identity matrix.
Non-rigorously, ∇u = ∇(Φ-X) = ∇(Φ)-∇(X) = F - I

*Right Cauchy-Green Deformation Tensor C
The right Cauchy-Green Deformation Tensor, henceforth the Cauchy-Green tensor, or just C where the meaning of C is obvious, is a tensor obtained by multiplying
the transpose of F by F
C =  transpose(F) * F
It is a symmetrix matrix that looks like the following:

[  ∂x/∂X*∂x/∂X  ∂x/∂Y*∂y/∂X  ∂x/∂Z*∂z/∂X  ]
|  ∂y/∂X*∂x/∂Y  ∂y/∂Y*∂y/∂Y  ∂y/∂Z*∂z/∂Y  |
[  ∂z/∂X*∂x/∂Z  ∂z/∂Y*∂y/∂Z  ∂z/∂Z*∂z/∂Z  ]

There is a spatial description version of this tensor, known as the left Cauchy-Green tensor, or the Piola tensor, or the Finger tensor, normally 
represented by B or b as
B = F * transpose(F)

*Strain
Because a body can have a rigid body displacement, i.e, every point in the body moves uniformly through space and does not change in reference to each other, 
the measure of deformation, strain, is a measure of how the displacement is locally different to its initial configuration. More physically, strain is a 
measure of a body's stretch or compression, as well as any angular stretching, or shearing.



*Green-Lagrange Strain Tensor E
The Green-Lagrange Strain Tensor E is defined as 
E = 1/2(C - I) 
where C is the Cauchy-Green tensor, and I is the Identity tensor

The spatial version, the Eulerian/Almansi strain tensor is represented by e and is defined by
e = 1/2(I - Inverse(B))

*Some More Pull-back operators
The left and right Cauchy-Green tensors are related by
b = F * C * Inverse(F)     and
C = Inverse(F) * b * F

The Green-lagrange Strain and Eulerian/Almansi Strain tensors are related by
e = Inverse(Transpose(F)) * E * Inverse(F)     and
E = Transpose(F) * e * F

*Stress
Stress is related in terms of Force/Area. When a force is applied in the same direction as the normal of the area, it is considered a normal stress, and
represented by σ. When the force is orthogonal to the normal of the area, it is a shear stress, represented by τ

*Cauchy Stress Tensor σ
The Cauchy stress Tensor σ is a 3x3 matrix that defines the stresses of a material.

     [ σ_xx   σ_xy   σ_xz  ]
σ =  | σ_yx   σ_yy   σ_yz  |
     [ σ_zx   σ_zy   σ_zz  ]

This is related to the traction vector T in the following way
T(n) =  n . σ

The Cauchy stress tensor is evaluated at a single spatial point, and so the traction vector gives the stresses encountered at the point 
