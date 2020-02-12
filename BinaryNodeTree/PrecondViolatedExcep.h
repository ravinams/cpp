/**
 * @Author: Amirah Abdullah <amirah>
 * @Date:   November 14, 2018  12:04am
 * @Email:  amirah.ghada@ku.edu
 * @Filename: PrecondViolatedExcep.h
 * @Last modified by:   amirah
 */

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Listing 7-5.
     @file PrecondViolatedExcep.h */

#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public logic_error {
public:
  PrecondViolatedExcep(const string& message = "") : logic_error("Precondition Violated Exception: " + message) {}
};  // end PrecondViolatedExcep
#endif
