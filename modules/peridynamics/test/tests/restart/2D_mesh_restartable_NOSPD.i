
[GlobalParams]
  displacements = 'disp_x disp_y'
[]

[Mesh]
  type = PeridynamicsMesh
  horizon_number = 3

  [./gmg]
    type = GeneratedMeshGenerator
    dim = 2
    nx = 4
    ny = 4
  [../]
  [./gpd]
    type = MeshGeneratorPD
    input = gmg
    retain_fe_mesh = false
  [../]
[]

[Variables]
  [./disp_x]
  [../]
  [./disp_y]
  [../]
[]

[BCs]
  [./left_x]
    type = DirichletBC
    variable = disp_x
    boundary = 1003
    value = 0.0
  [../]
  [./left_y]
    type = DirichletBC
    variable = disp_y
    boundary = 1003
    value = 0.0
  [../]
  [./right_x]
    type = DirichletBC
    variable = disp_x
    boundary = 1001
    value = 0.001
  [../]
[]

[Modules/Peridynamics/Mechanics/Master]
  [./all]
    formulation = NONORDINARY_STATE
  [../]
[]

[Materials]
  [./elasticity_tensor]
    type = ComputeIsotropicElasticityTensor
    youngs_modulus = 2.1e8
    poissons_ratio = 0.3
  [../]
  [./strain]
    type = ComputePlaneSmallStrainNOSPD
  [../]
  [./stress]
    type = ComputeLinearElasticStress
  [../]
[]

[Preconditioning]
  [./SMP]
    type = SMP
    full = true
  [../]
[]

[Executioner]
  type = Transient
  solve_type = PJFNK
  start_time = 0
  end_time = 1
  # num_steps = 2

  [./Quadrature]
    type = GAUSS_LOBATTO
    order = FIRST
  [../]
[]

[Outputs]
  file_base = 2D_mesh_restartable_NOSPD_out
  exodus = true
  checkpoint = true
[]
