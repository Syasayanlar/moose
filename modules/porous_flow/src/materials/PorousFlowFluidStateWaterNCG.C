//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "PorousFlowFluidStateWaterNCG.h"
#include "PorousFlowCapillaryPressure.h"

registerMooseObject("PorousFlowApp", PorousFlowFluidStateWaterNCG);

defineLegacyParams(PorousFlowFluidStateWaterNCG);

InputParameters
PorousFlowFluidStateWaterNCG::validParams()
{
  InputParameters params = PorousFlowFluidState::validParams();
  params.addClassDescription("Fluid state class for water and non-condensable gas");
  return params;
}

PorousFlowFluidStateWaterNCG::PorousFlowFluidStateWaterNCG(const InputParameters & parameters)
  : PorousFlowFluidState(parameters)
{
  mooseDeprecated(name(),
                  ": the PorousFlowFluidStateWaterNCG material is deprecated. Just use "
                  "PorousFlowFluidState instead");
}
