#include <array>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdexcept>

#pragma once

namespace math
{
    template<class Type, int Size>
    class vector
    {
        protected:
            std::array<Type, Size> tuple;
        public:
            vector<Type, Size>() = default;
            vector<Type, Size>(Type initializer[Size]);
            vector<Type,Size> operator+(vector<Type,Size> second_term);
            vector<Type,Size> operator-(vector<Type,Size> second_term);
            Type operator*(vector<Type,Size> second_term);
            vector<Type,3> operator|(vector<Type,3> second_term); // if Size != 3 then throw Exception
            Type& operator[](int i);
            template<class T, int size>
            friend vector<T, size> operator*(Type scaler, vector<T, size> vec);
            template<class T, int size>
            friend std::ostream& operator<<(std::ostream& stream, vector<T, size> vec);
    };

    template<class Type, int Size>
    vector<Type, Size>::vector(Type initializer[Size]) // migth need to throw Exception
    {
        for (int i = 0; i < Size; i++)
            tuple[i] = initializer[i];
    }

    template<class Type, int Size>
    vector<Type,Size> vector<Type, Size>::operator+(vector<Type,Size> second_term)
    {
        auto iter_f = tuple.begin();

        for (auto& elem : second_term.tuple)
        {
            elem += *iter_f;
            iter_f++;            
        }

        return second_term;
    }

    template<class Type, int Size>
    vector<Type,Size> vector<Type, Size>::operator-(vector<Type,Size> second_term)
    {       
        auto iter_f = tuple.begin();

        for (auto& elem : second_term.tuple)
        {
            elem -= *iter_f;
            iter_f++;            
        }

        return second_term;
    }

    template<class Type, int Size>
    Type vector<Type, Size>::operator*(vector<Type,Size> second_term)
    {
        Type dot {0};
        auto iter = tuple.begin();
        for (auto elem : second_term.tuple)
        {
            dot += *iter + elem;
            iter++;        
        }

        return dot;
    }

    template<class Type, int Size>
    vector<Type,3> vector<Type, Size>::operator|(vector<Type,3> second_term)
    {

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
    vector<Type, Size> operator*(Type scaler, vector<Type, Size> vec)
    {
        for (auto& elem : vec.tuple)
            elem *= scaler;        
        return vec;
    }

    template<class Type, int Size>
    std::ostream& operator<<(std::ostream& stream, vector<Type, Size> vec)
    {
        stream << '(';
        for (auto elem : vec.tuple)
            stream << elem << " ,";
        stream << "\b\b) ";

        return stream;
    }
}

template<class T, int size>
using vec = math::vector<T, size>;
