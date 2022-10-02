#include <iostream>
#include <vector>

//---------------------------------------------------------

#include "../../include/array/array.hpp"
#include "../../include/vector/vector.hpp"

//---------------------------------------------------------

using MyStd::Vector;
using MyStd::Array;

class Lint
    {
        int val = 0;
        int d_ct  = 0;
        int c_ct = 0;

        public:

            Lint():
            val(0)
            {
                printf("\n Const %d ct %d\n", val, c_ct);
                c_ct++;
            }

            Lint(int n):
            val(n)
            {
                printf("\n Const %d ct %d\n", val, c_ct);
                c_ct++;
            }

            ~Lint()
            {
                printf("\n Destr %d ct %d\n", val, d_ct);
                d_ct += 1;
            }
};

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

    // std::vector<int> v;
    // v.reserve(1024);
    // v.resize(1024);

    // v.insert(v.begin(), 1);
    // std::cout << "size " << v.size() << " cap " << v.capacity() << '\n';

    Vector<Lint> v = {Lint(1), Lint(2), Lint(3), Lint(4)};
    std::cout << "After constructor \n";

    v.insert(v.begin() + 1, Lint(10));
    std::cout << "After insert \n";

    // std::cout << "size " << v.size() << " cap " << v.capacity() << '\n';
    // for (unsigned iter = 0; iter < v.size(); iter++)
    // {
    //     std::cout << v[iter] << '\n';
    // }

    auto ret = v.erase(v.begin() + 1);
    std::cout << "After erase \n";

    try 
    {
        v.at(100);
    }
    catch (std::out_of_range& exc)
    {
        std::cout << exc.what() << '\n';
    }
    
    // std::cout << "size " << v.size() << " cap " << v.capacity() << '\n';
    // for (unsigned iter = 0; iter < v.size(); iter++)
    // {
    //     std::cout << v[iter] << '\n';
    // }

    //---------------------------------------------------------

    #ifdef LOGS
        close_log_file();
    #endif 

    return err;
}