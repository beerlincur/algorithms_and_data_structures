//
//  BinarySearchTreeExceptions.hpp
//  Binary_search_trees
//
//  Created by zhozh on 05.03.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#ifndef BinarySearchTreeExceptions_hpp
#define BinarySearchTreeExceptions_hpp

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

#endif /* BinarySearchTreeExceptions_hpp */
