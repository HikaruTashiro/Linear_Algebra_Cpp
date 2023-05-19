#include <initializer_list>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#pragma once

namespace math
{
    template<class Type, int Size>
    class vector {
        protected:
            Type tuple[Size];
        public:
            vector<Type, Size>() = default;
            vector<Type, Size>(const vector<Type, Size> &cp_vec);
            vector<Type, Size>(std::initializer_list<Type> initializer);
            vector<Type,Size> operator+(const vector<Type,Size> &second_term);
            vector<Type,Size> operator-(const vector<Type,Size> &second_term);
            Type operator*(const vector<Type,Size> &second_term);
            inline Type& operator[](int i);
            template<class T, int size>
            friend vector<T, size> operator*(Type scaler, const vector<T, size> &vec);
            vector<Type, 3> operator|(const vector<Type, 3> &v);
            template<class T, int size>
            friend std::ostream& operator<<(std::ostream& stream, vector<T, size> &vec);

            constexpr Type* 
            begin() noexcept {return tuple;}
            constexpr Type* 
            end() noexcept {return begin() + Size;}
    };

    template<class Type, int Size>
    vector<Type, Size>::vector(std::initializer_list<Type> initializer) // migth need to throw Exception
    {
        std::copy(initializer.begin(), initializer.end(), tuple);
    }                                                   

    template<class Type, int Size>
    vector<Type, Size>::vector(const vector<Type, Size>& cp_vec)
    {
        std::copy(cp_vec.tuple, cp_vec.tuple + Size, tuple);
    }

    template<class Type, int Size>
    vector<Type,Size> vector<Type, Size>::operator+(const vector<Type, Size> &second_term)
    {
        vector<Type, Size> new_v;
        std::transform(tuple, tuple + Size, second_term.tuple, new_v.tuple, std::plus<Type>());
        return new_v;
    }

    template<class Type, int Size>
    vector<Type,Size> vector<Type, Size>::operator-(const vector<Type,Size> &second_term)
    {
        vector<Type, Size> new_v;
        std::transform(tuple, tuple + Size, second_term.tuple, new_v.tuple, std::minus<Type>());
        return new_v;
    }

    template<class Type, int Size>
    Type vector<Type, Size>::operator*(const vector<Type,Size> &second_term)
    {
        Type _{};
        return std::inner_product(tuple, tuple + Size, second_term.tuple, _);
    }

    template<class Type, int Size>
    Type& vector<Type, Size>::operator[](int i) 
    {
        if (i < Size)
            return tuple[i];
        else
            throw std::out_of_range("Error: Attempted to acess out of range element\n");
    }

    template<class Type, int Size>
    vector<Type, Size> operator*(Type scaler, const vector<Type, Size> &vec)
    {
        vector<Type, Size> new_v;
        std::transform(vec.tuple, vec.tuple + Size, new_v.tuple, std::bind(std::multiplies<Type>(), std::placeholders::_1, scaler));
        return new_v;
    }

    template<class Type, int Size>
    vector<Type, 3> vector<Type, Size>::operator|(const vector<Type, 3> &v)
    {
        float i, j, k;     
        i = tuple[1] * v.tuple[2] - tuple[2] * v.tuple[1];
        j = tuple[2] * v.tuple[0] - tuple[0] * v.tuple[2];
        k = tuple[0] * v.tuple[1] - tuple[1] * v.tuple[0];
        return vector<Type, 3>({i, j, k});
    }

    template<class Type, int Size>
    std::ostream& operator<<(std::ostream& stream, vector<Type, Size> &vec)
    {
        stream << '(';
        for (auto iter = vec.tuple; iter != vec.tuple + Size; iter++)
            stream << *iter << " ,";
        stream << "\b\b) ";
        
        return stream;
    }
}

template<class T, int size>
using vec = math::vector<T, size>;
