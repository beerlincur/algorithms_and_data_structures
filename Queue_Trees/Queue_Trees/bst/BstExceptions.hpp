//
//  BstExceptions.hpp
//  Queue_Trees
//
//  Created by zhozh on 18.03.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef BstExceptions_hpp
#define BstExceptions_hpp

#include <stdio.h>
#include <exception>

using std::exception;

class IndexOutOfRange: public exception
{
public:
    
    IndexOutOfRange() : reason("out of range") {};
    
    const char* what() { return reason; }

private:
       const char* reason;  // ! const
};

#endif /* BstExceptions_hpp */
