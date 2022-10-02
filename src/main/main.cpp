#include <iostream>
#include <vector>

//---------------------------------------------------------

#include "../../include/array/array.hpp"
#include "../../include/vector/vector.hpp"

class Loud_int
{
    int val_;

    public:
        Loud_int(int val):
        val_(val)
        {}

        ~Loud_int()
        {
            printf("D %d\n", val_);
        }
};

//=========================================================

int main()
{
    int err = 0;

    #ifdef LOGS
        open_log_file(Logfile_name);
    #endif 

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

    std::vector<Loud_int> v{};

    for (unsigned iter = 0; iter < 1; iter++)
    {
        v.push_back(Loud_int(12));
    }

    fprintf(stderr, "AAA\n");

    for (unsigned iter = 0; iter < 1; iter++)
    {
        v.pop_back();
    }

    fprintf(stderr, "AAA\n");

    std::vector<int> v1 {1, 5, 3};
    std::vector<int> v2 {1, 2, 3, 4};

    fprintf(stderr, "\n %d \n", (v2 > v1));


    #ifdef LOGS
        close_log_file();
    #endif 

    return err;
}