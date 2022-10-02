#pragma once 

//---------------------------------------------------------

#include <unistd.h>
#include <assert.h>
#include <limits.h>

#include <initializer_list>
#include <utility>

//=========================================================

namespace MyStd
{

static const size_t Vector_start_size = 1;

template <class Type>
class Vector
{
    Type*  data_     = nullptr;
    size_t size_     = 0;
    size_t capacity_ = 0; 

    public:

        /////////// type members ///////////

        typedef       Type        value_type;
        typedef       value_type* pointer;
        typedef const value_type* const_pointer;
        typedef       value_type& reference;
        typedef const value_type& const_reference;
        typedef       value_type* iterator;
        typedef const value_type* const_iterator;
        typedef       size_t      size_type;
 
        /////////// ctors & dtor ///////////

        Vector() 
            {} // empty vector

        ~Vector()
            {
                delete[] data_;
            }

        explicit Vector(size_type size):
            capacity_(size),
            data_    (new Type[capacity_])
            {}

        Vector(const Vector& that):
            size_    (that.size_),
            capacity_(that.size_), 
            data_    (new Type[size_])
            {
                for (unsigned iter = 0; iter < size_; iter++)
                    data_[iter] = that.data_[iter];
            }

        Vector(Vector&& that):
            size_    (that.size_),
            capacity_(that.capacity_),
            data_    (that.data_)
            {
                that.size_     = 0;
                that.capacity_ = 0;
                that.data_     = nullptr;
            }

        //////////// assignment ////////////

        Vector& operator= (const Vector& that)
            {
                if (this != &that)
                    return *this;

                delete[] data_; //TODO: do not delete, reuse memory

                size_     = that.size_;
                capacity_ = that.size_;
                data_     = new Type[capacity_];

                for (unsigned iter = 0; iter < size_; iter++)
                    data_[iter] = that.data_[iter];
            }

        Vector& operator= (Vector&& that)
            {
                delete[] data_;

                size_     = that.size_;
                capacity_ = that.capacity;
                data_     = that.data_;

                that.size_     = 0;
                that.capacity_ = 0;
                that.data_     = nullptr;
            }

        Vector& operator= (std::initializer_list<Type> list)
            {
                delete[] data_; //TODO: do not delete, reuse memory

                size_     = list.size();
                capacity_ = size_;
                data_     = new Type[capacity_];

                for (unsigned iter = 0; iter < size_; iter++)
                    data_[iter] = list[iter];
            }

        void assign(std::initializer_list<Type> list)
            {
                *this = list;
            }

        void assign(size_type count, const Type& value)
            {
                for (unsigned iter = 0; iter < size_; iter++)
                    data_[iter] = value;
            }

        ////////// element access //////////
        
        reference at(size_type pos)
            {
                assert(pos > size_ && "vector: out of bounds");
                return data_[pos];
            }

        const_reference at(size_type pos) const
            {
                assert(pos > size_ && "vector: out of bounds");
                return data_[pos];
            }

        reference       operator[] (size_type pos)       { return data_[pos]; }
        const_reference operator[] (size_type pos) const { return data_[pos]; }

        reference       front()       { return data_[0]; }
        const_reference front() const { return data_[0]; }

        reference       back()        { return data_[size_ - 1]; }
        const_reference back()  const { return data_[size_ - 1]; }

        pointer         data()        { return data_; }
        const_pointer   data()  const { return data_; }

        ///////////// iterators ////////////

        iterator       begin()        { return data_; }
        const_iterator begin()  const { return data_; }
        const_iterator cbegin() const { return data_; }
        
        iterator       end()          { return data_ + size_; }
        const_iterator end()    const { return data_ + size_; }
        const_iterator cend()   const { return data_ + size_; }  

        /////////////// capacity //////////////

        bool      empty()    const { return (size_ > 0); }
        size_type size()     const { return  size_;      }
        size_type max_size() const { return  SIZE_MAX;   }
        size_type capacity() const { return  capacity_;  }

        void reserve(size_type new_cap)
            {
                if (new_cap <= capacity_)
                    return;

                realloc_vector(new_cap);
            }

        void shrink_to_fit()
            {
                if (size_ == capacity_)
                    return;

                realloc_vector(size_);
            }

        ///////////////// modifiers /////////////////

        void clear()
            {
                for (unsigned iter = 0; iter < size_; iter++)
                    data_[iter].~Type();
                size_ = 0;
            }

        // iterator insert(const_iterator pos, const Type& value )
        //     {
        //         move_data_by_one(pos);
        //         *(pos - 1) = value;
        //     }

        // iterator insert( const_iterator pos, size_type count, const T& value )
        //     {
        //         move_data(pos, count)
        //         *(pos - 1) = value;
        //     }

        // TODO: erase

        void push_back(const Type& value)
            {
                if (size_ >= capacity_)
                {
                    realloc_vector((capacity_ == 0)  ? 
                                    Vector_start_size:
                                    capacity_ * 2);
                }

                data_[size_++] = value;
            }

        // void push_back(Type&& value);

        void pop_back()
            {
                assert(size_);
                data_[(size_ = size_ - 1)].~Type();
            }

        void resize(size_type count, Type value = Type())
            {
                if (size_ == count)
                    return;
                else if (size_ > count)
                {
                    while(size_ > count)
                    {
                        this->pop_back();
                        size_ -= 1;
                    }
                }
                else
                {
                    while(size_ < count)
                    {
                        this->push_back(value);
                        size_ += 1;
                    }
                }
            }

        void swap(Vector& that)
            {
                size_type temp = size_;
                size_          = that.size_;
                that.size      = temp;

                temp           = capacity_;
                capacity_      = that.capacity_;
                that.capacity_ = temp;

                pointer data_temp = data_;
                data_             = that.data_;
                that.data_        = data_temp;
            }

        private:

            void realloc_vector(size_type new_cap)
                {
                    assert(new_cap >= size_);

                    pointer new_data = new Type[new_cap];

                    for (unsigned iter = 0; iter < size_; iter++)
                        new_data[iter] = data_[iter];

                    delete[] data_;

                    data_     = new_data;
                    capacity_ = new_cap;
                }

            // void move_data(const_iterator pos, size_type offset)
            //     {
            //         while(offset)
            //         {
            //             move_data_by_one(pos);
            //             offset--;
            //         }
            //     }

            // void move_data_by_one(const_iterator pos)
            //     {
                    
            //     }
};

//---------------------------------------------------------

template <class Type>
bool operator== (const Vector<Type>& a, const Vector<Type>& b)
{
    size_t a_num = a.size() - 1;
    size_t b_num = b.size() - 1;

    unsigned iter = 0;

    for (iter = 0; (iter < a_num) && (iter < b_num); iter++)
    {
        if (a[iter] != b[iter])
            break;
    }

    return !!(a[iter] - b[iter]);
}

//---------------------------------------------------------

template <class Type>
bool operator!= (const Vector<Type>& a, const Vector<Type>& b)
{
    return !(a == b);
}

//---------------------------------------------------------

template <class Type>
bool operator> (const Vector<Type>& a, const Vector<Type>& b)
{
    size_t a_num = a.size() - 1;
    size_t b_num = b.size() - 1;

    unsigned iter = 0;

    for (iter = 0; (iter < a_num) && (iter < b_num); iter++)
    {
        if (a[iter] != b[iter])
            break;
    }

    if (a[iter] - b [iter] > 0)
        return true;
    else
        return false;
}

//---------------------------------------------------------

template <class Type>
bool operator< (const Vector<Type>& a, const Vector<Type>& b)
{
    return !(a > b);
}

//---------------------------------------------------------

template <class Type>
bool operator<= (const Vector<Type>& a, const Vector<Type>& b)
{
    return ((a < b) || (a == b));
}

//---------------------------------------------------------

template <class Type>
bool operator>= (const Vector<Type>& a, const Vector<Type>& b)
{
    return ((a > b) || (a == b));
}

//---------------------------------------------------------

}; // namespace MyStd
