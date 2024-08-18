
#include "Type0.h"
#include "Type1.h"
#include "Type2.h"
#include "PartialFunction.h"
#include "PartialFunctionByCriteria.hpp"
#include "MaximumPartialFunction.h"
#include "MinimumPartialFunction.h"
#include<fstream>
#pragma once

PartialFunction* factory(std::ifstream& ifs);
