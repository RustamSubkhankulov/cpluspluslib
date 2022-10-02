#include <iostream>
#include <vector>

//---------------------------------------------------------

#include "../../include/array/array.hpp"
#include "../../include/vector/vector.hpp"

//---------------------------------------------------------

using MyStd::Vector;
using MyStd::Array;

//=========================================================

int main()
{
    int err = 0;

    #ifdef LOGS
        open_log_file(Logfile_name);
    #endif 

    //---------------------------------------------------------

    // std::vector<int> v{};

    // for (unsigned iter = 0; iter < 1024 * 1024; iter++)
    // {

    //     v.push_back(1);

    //     std::cout << "size " << v.size() << " cap " << v.capacity() << '\n';
    // }

    // for (unsigned iter = 0; iter < 1024 * 1024; iter++)
    // {

    //     v.pop_back();

    //     std::cout << "size " << v.size() << " cap " << v.capacity() << '\n';
    // }

    //---------------------------------------------------------

    // using std::cout;

    // Vector<int> v1;
    // cout << "size " << v1.size() << " cap " << v1.capacity() << '\n';

    // Vector<int> v2;
    // v2  = {1, 2, 3, 4};
    // cout << "size " << v2.size() << " cap " << v2.capacity() << '\n';

    // v1 = std::move(v2);
    // cout << "size " << v1.size() << " cap " << v1.capacity() << '\n';

    // v1.resize(6, 2);
    // cout << "size " << v1.size() << " cap " << v1.capacity() << '\n';

    // for (unsigned iter = 0; iter < v1.size(); iter++)
    // {
    //     cout << v1[iter] << '\n';
    // }

    // Vector<int> v3;
    // v3 = {1};

    // v1.swap(v3);
    // for (unsigned iter = 0; iter < v3.size(); iter++)
    // {
    //     cout << v3[iter] << '\n';
    // }

    //---------------------------------------------------------

    Vector<int> v1 = {1, 2, 3, 4};

    //---------------------------------------------------------

    #ifdef LOGS
        close_log_file();
    #endif 

    return err;
}