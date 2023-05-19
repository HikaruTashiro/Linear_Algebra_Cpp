#include "vector.hpp"
#include <algorithm>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <iomanip>

namespace math
{
    template<class Type, int row, int col>
    class matrix
    {
        public:
            vector<Type, col> table[row];

            matrix<Type, row, col>() = default;
            matrix<Type, row, col>(std::initializer_list<Type[col]> initializer);
            inline vec<Type, col>& operator[](int i);
            matrix<Type, col, row> transpose();
            matrix<Type, row, col> operator+(matrix<Type, row, col> &m);
            matrix<Type, row, col> operator-(matrix<Type, row, col> &m);
            template<class T, int r, int c>
            friend std::ostream& operator<<(std::ostream& stream, matrix<T, r, c> &m);
    };

    template<class Type, int row, int col>
    matrix<Type, row, col>::matrix(std::initializer_list<Type[col]> initializer)
    {
        auto iter_vec = table;
        for (auto iter_out : initializer)
        {
            std::copy(iter_out, iter_out + col, iter_vec->begin());
            iter_vec++;
        }
    }

    template<class Type, int row, int col>
    vec<Type, col>& matrix<Type, row, col>::operator[](int i)
    {
        if (i < row)
            return table[i];
        else
            throw std::out_of_range("Error: tried to acess out of range row\n");
    }

    template<class Type, int row, int col>
    matrix<Type, col, row> matrix<Type, row, col>::transpose()
    {
        matrix<Type, col, row> m;
        /*stub*/
        return m;
    }

    template<class Type, int row, int col>
    matrix<Type, row, col> matrix<Type, row, col>::operator+(matrix<Type, row, col> &m)
    {
        matrix<Type, row, col> m_ret;
        for (int i = 0; i < row; i++)
            std::transform(table[i].begin(), table[i].end(), m.table[i].begin(), m_ret.table[i].begin(), std::plus<Type>());
        return m_ret;
    }

    template<class Type, int row, int col>
    matrix<Type, row, col> matrix<Type, row, col>::operator-(matrix<Type, row, col> &m)
    {
        matrix<Type, row, col> m_ret;
        for (int i = 0; i < row; i++)
            std::transform(table[i].begin(), table[i].end(), m.table[i].begin(), m_ret.table[i].begin(), std::minus<Type>());
        return m_ret;
    }

    template<class T, int r, int c>
    std::ostream& operator<<(std::ostream& stream, matrix<T, r, c> &m)
    {
        for (auto iter = m.table; iter < m.table + r; iter++)
            stream << *iter << '\n';
        return stream;        
    }
}

template<class Type, int row, int col, int scol>
math::matrix<Type, row, scol> operator*(math::matrix<Type, row, col> &m1, math::matrix<Type, col, scol> &m2)
{
    /*stub*/
    //might be interesting to do some threads here

} 


template<class T, int r, int c>
using mat = math::matrix<T, r, c>;
