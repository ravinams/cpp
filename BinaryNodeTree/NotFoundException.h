/**
 * @Author: Amirah Abdullah <amirah>
 * @Date:   November 14, 2018  12:04am
 * @Email:  amirah.ghada@ku.edu
 * @Filename: NotFoundExcept.h
 * @Last modified by:   amirah
 */
#ifndef NOTFOUNDEXCEPTION_H
#define NOTFOUNDEXCEPTION_H
#include <stdexcept>

class NotFoundException : public std::runtime_error {
public:
  /**
 	*  @pre None
 	*  @post Calls the constructor of std::runtime_error
 	*  @return runtime_error object
 	*/
  NotFoundException(const char* message);
};

#endif
