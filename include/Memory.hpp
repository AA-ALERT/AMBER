// Copyright 2018 Netherlands Institute for Radio Astronomy (ASTRON)
// Copyright 2018 Netherlands eScience Center
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

// Load input files
void loadInput(AstroData::Observation & observation, const DeviceOptions & deviceOptions, const DataOptions & dataOptions, HostMemory & hostMemory, Timers & timers);
// Allocate host memory
void allocateHostMemory(AstroData::Observation & observation, const Options & options, const DeviceOptions & deviceOptions, const DataOptions & dataOptions, const KernelConfigurations & kernelConfigurations, HostMemory & hostMemory);
// Allocate device memory
void allocateDeviceMemory(const AstroData::Observation & observation, const isa::OpenCL::OpenCLRunTime & openclRunTime, const Options & options, const DeviceOptions & deviceOptions, const HostMemory & hostMemory, DeviceMemory & deviceMemory);
