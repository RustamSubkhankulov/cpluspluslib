#include <iostream>

//---------------------------------------------------------

#include "../../include/array/array.hpp"
#include "../../include/vector/vector.hpp"

//=========================================================

int main()
{
    int err = 0;

    #ifdef LOGS
        open_log_file(Logfile_name);
    #endif 

    MyStd::Array<int, 4> a = {1, 2, 3, 4};
    MyStd::Array<int, 4> b = {3, 4, 5, 6};
    MyStd::Array<int, 4> c = {9, 9, 9, 9};
    a.swap(c);

    for (unsigned iter = 0; iter < a.size(); iter++)
    {
        std::cout << a[iter] << ' ' << (c > a) << '\n';
    }

    #ifdef LOGS
        close_log_file();
    #endif 

    return err;
}