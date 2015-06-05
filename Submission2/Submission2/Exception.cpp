//
//  Exception.cpp
//  Submission2
//
//  Created by ChristianEnevoldsen on 12/05/15.
//  Copyright (c) 2015 ChristianEnevoldsen. All rights reserved.
//

#include <iostream>
#include "Exception.hpp"

Exception::Exception(std::string tagString, std::string probString)
: mTag(tagString), mProblem(probString) {}

void Exception::PrintDebug() const {
  std::cerr << "** Error (" << mTag << ") **\n";
  std::cerr << "** Problem (" << mProblem << ") **\n";
}
