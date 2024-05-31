#pragma once
#include <stdio.h>
#include "FunctionWithConstantValues.h"
#include "FunctionWithStandartValue.h"
#include "FunctionWithExcludedValues.h"
#include "PartialFunctionByCriteria.hpp"
#include "MinimumFunction.hpp"
#include "MaximumFunction.hpp"
#include "String.h"


constexpr int MAX_FILE_NAME_SIZE = 1024;

PartialFunction<Pair>* crafter(std::ifstream& ifs);
