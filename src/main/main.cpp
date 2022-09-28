#include "../../include/array/array.hpp"
#include "../../include/vector/vector.hpp"

//=========================================================

int main()
{
    int err = 0;

    #ifdef LOGS
        open_log_file(Logfile_name);
    #endif 

    Array<int, 3> a = {1, 2, 3};
    Array<int, 2> b = {3, 4};

    #ifdef LOGS
        close_log_file();
    #endif 

    return err;
}