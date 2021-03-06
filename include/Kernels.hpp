// Copyright 2017 Netherlands Institute for Radio Astronomy (ASTRON)
// Copyright 2017 Netherlands eScience Center
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "configuration.hpp"
#include "DataTypes.hpp"

#pragma once

/**
 * @brief Generate the OpenCL kernels according to the provided configurations.
 */
void generateOpenCLKernels(const isa::OpenCL::OpenCLRunTime & openclRunTime, const AstroData::Observation & observation, const Options & options, const DeviceOptions & deviceOptions, const KernelConfigurations & kernelConfigurations, const HostMemory & hostMemory, const DeviceMemory & deviceMemory, Kernels & kernels);
/**
 * @brief Generate the run-time configurations for the OpenCL kernels, according to the provided configurations.
 */
void generateOpenCLRunTimeConfigurations(const AstroData::Observation & observation, const Options & options, const DeviceOptions & deviceOptions, const KernelConfigurations & kernelConfigurations, const HostMemory & hostMemory, KernelRunTimeConfigurations & kernelRunTimeConfigurations);
