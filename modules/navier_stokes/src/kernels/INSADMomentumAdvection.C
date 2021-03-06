//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "INSADMomentumAdvection.h"

registerADMooseObject("NavierStokesApp", INSADMomentumAdvection);

defineADLegacyParams(INSADMomentumAdvection);

template <ComputeStage compute_stage>
InputParameters
INSADMomentumAdvection<compute_stage>::validParams()
{
  InputParameters params = ADVectorKernelValue<compute_stage>::validParams();
  params.addClassDescription("Adds the convective term to the INS momentum equation");
  return params;
}

template <ComputeStage compute_stage>
INSADMomentumAdvection<compute_stage>::INSADMomentumAdvection(const InputParameters & parameters)
  : ADVectorKernelValue<compute_stage>(parameters),
    _convective_strong_residual(
        getADMaterialProperty<RealVectorValue>("convective_strong_residual"))
{
}

template <ComputeStage compute_stage>
ADRealVectorValue
INSADMomentumAdvection<compute_stage>::precomputeQpResidual()
{
  return _convective_strong_residual[_qp];
}
