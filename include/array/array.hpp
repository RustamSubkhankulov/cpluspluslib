#pragma once 

//---------------------------------------------------------

#include <stdio.h>
#include <unistd.h>
#include <assert.h>

#include <initializer_list>
#include <utility>
#include <concepts>

//=========================================================

template<class T,  size_t N>
class Array
{
    T data_[N];

    public:

        typedef       T           value_type;
        typedef       value_type* pointer;
        typedef const value_type* const_pointer;
        typedef       value_type& reference;
        typedef const value_type& const_reference;
        typedef       value_type* iterator;
        typedef const value_type* const_iterator;
        typedef       size_t      size_type;
        typedef const value_type* const_type_ptr;
        typedef       value_type* type_ptr;

        Array(std::initializer_list<T> l)
            {
                size_type l_size = l.size();
                assert(l_size <= N);

                for (unsigned iter = 0; iter < l_size; iter++)
                {
                    data_[iter] = *(l.begin() + iter);
                }
            }

        ~Array() = default;

        Array(const Array&) = default;
        Array(Array&&)      = default;

        Array& operator= (const Array&)  = default;
        Array& operator= (Array&&)       = default;

        reference at(size_type pos)
            {
                assert(pos < N && "array: out of bounds");
                return data_[pos];
            }

        const_reference at(size_type pos) const
            {
                assert(pos < N && "array: out of bounds");
                return data_[pos];
            }

        reference       operator[] (size_type pos)       { return data_[pos]; }
        const_reference operator[] (size_type pos) const { return data_[pos]; }

        reference       front()       { return data_[0]; }
        const_reference front() const { return data_[0]; }

        reference       back()        { return data_[N - 1]; }
        const_reference back()  const { return data_[N - 1]; }

        type_ptr        data()        { return data_; }
        const_type_ptr  data()  const { return data_; }

        void fill(const T& value)
            { 
                for (unsigned iter = 0; iter < N; iter++)
                    data_[iter] = value;
            }

        void swap(Array<T, N>& that)
            {
                for (unsigned iter = 0; iter < N; iter++)
                {
                    T temp        = std::move(  that [iter]);
                      that [iter] = std::move((*this)[iter]);
                    (*this)[iter] = std::move(  temp       );
                }
            }

        constexpr size_type size() const { return N; }

        // since we don't have default constuctor, array can not empty
        constexpr bool empty() const noexcept { return false; }

        constexpr size_type max_size() const { return N; } 

        iterator       begin()        { return data_; }
        const_iterator begin()  const { return data_; }
        const_iterator cbegin() const { return data_; }
        
        iterator       end()          { return data_ + N; }
        const_iterator end()    const { return data_ + N; }
        const_iterator cend()   const { return data_ + N; }       
};

//---------------------------------------------------------

template<class Type, size_t Num>
bool operator> (const Array<Type, Num>& a, const Array<Type, Num>& b)
{
    for (unsigned iter = 0; iter < Num; iter++)
        if (a[iter] < b[iter])
            return 0;

    return 1;
}

//---------------------------------------------------------

template<class Type, size_t Num>
bool operator>= (const Array<Type, Num>& a, const Array<Type, Num>& b)
{
    return ((a > b) || (a == b));
}

//---------------------------------------------------------

template<class Type, size_t Num>
bool operator<= (const Array<Type, Num>& a, const Array<Type, Num>& b)
{
    return ((a < b) || (a == b));
}

//---------------------------------------------------------

template<class Type, size_t Num>
bool operator< (const Array<Type, Num>& a, const Array<Type, Num>& b)
{
    return !(a > b);
}

//---------------------------------------------------------

template<class T, size_t N>
bool operator== (const Array<T, N>& a, const Array<T, N>& b)
{
    for (unsigned iter = 0; iter < N; iter++)
        if (a[iter] != b[iter])
            return false;

    return true;
}

//---------------------------------------------------------

template<class T, size_t N>
bool operator!= (const Array<T, N>& a, const Array<T, N>& b)
{
    return !(a == b);
}

//---------------------------------------------------------
