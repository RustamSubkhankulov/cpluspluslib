
//---------------------------------------------------------

#include "../../include/array/array.hpp"

//=========================================================

template<class Type, size_t Num>
bool operator== (const Array<Type, Num>& a, const Array<Type, Num>& b)
{
    for (unsigned iter = 0; iter < Num; iter++)
        if (a[iter] != b[iter])
            return false;

    return true;
}

//---------------------------------------------------------
