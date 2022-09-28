#pragma once 

//---------------------------------------------------------

#include <unistd.h>
#include <assert.h>
#include <initializer_list>

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
        // difference type
        // reverse_iterator
        // const reverse_iterator

        Array(std::initializer_list<T> l)
            {
                size_type l_size = l.size();
                assert(l_size > N);

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
                assert(pos < N);
                return data_[pos];
            }

        const_reference at(size_type pos) const
            {
                assert(pos < N);
                return data_[pos];
            }

        reference operator[] (size_type pos)
            { return data_[pos]; }

        const_reference operator[] (size_type pos) const
            { return data_[pos]; }

        reference front()
            { return data_[0]; }

        const_reference front() const
            { return data_[0]; }

        reference back()
            { return data_[N - 1]; }

        const_reference back() const
            { return data_[N - 1]; }

        T* data()
            { return data_; }

        const T* data() const
            { return data_; }

        void fill(const T& value)
            { 
                for (unsigned iter = 0; iter < N; iter++)
                    data_[iter] = value;
            }

        // void swap(Array& that);

        constexpr size_type size() const
            { return N; }

        // constexpr bool empty() const noexcept;

        constexpr size_type max_size() const
            { return N; } 

        iterator begin() 
            { return data_; }

        const_iterator begin() const
            { return data_; }
        
        const_iterator cbegin() const
            { return data_; }
        
        iterator end()
            { return data_ + N; }

        const_iterator end() const
            { return data_ + N; }

        const_iterator cend() const 
            { return data_ + N; }

        // reverse_iterator rbegin();
        // const_reverse_iterator rbegin();
        // const_reverse_iterator crbegin();

        // reverse_iterator rend();
        // const_reverse_iterator rend();
        // const_reverse_iterator crend();

        template<class Type, size_t Num>
        friend bool operator== (const Array<Type, Num>& a, const Array<Type, Num>& b);
};

//---------------------------------------------------------
