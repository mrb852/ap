//
//  OutOfRangeException.cpp
//  Submission2
//
//  Created by ChristianEnevoldsen on 12/05/15.
//  Copyright (c) 2015 ChristianEnevoldsen. All rights reserved.
//

#include <stdio.h>
#include "OutOfRangeException.hpp"

OutOfRangeException::OutOfRangeException(std::string prob)
: Exception("Out Of Range", prob) {}
