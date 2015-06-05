//
//  FileNotOpenException.cpp
//  Submission2
//
//  Created by ChristianEnevoldsen on 12/05/15.
//  Copyright (c) 2015 ChristianEnevoldsen. All rights reserved.
//

#include <stdio.h>
#include "FileNotOpenException.hpp"

FileNotOpenException::FileNotOpenException(std::string prob)
: Exception("FILE", prob) {}
