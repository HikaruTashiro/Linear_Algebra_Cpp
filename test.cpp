#include "vector.hpp"
#include "matrix.hpp"
#include <iostream>

int main()
{
    vec<float, 3> pog({3.0f,2.0f,3.0f});
    vec<float, 3> pagman({1.0f, 4.0f, 5.0f});
    vec<float, 4> pogzinho({1.0f,4.0f,6.0f,12.0f});
    std::cout << "pog vector: " << pog << '\n';
    std::cout << "pagman vector: " << pagman << '\n';

    vec<float, 3> result;
    std::cout << "pagman + pog: " << (result = pagman + pog) << '\n';
    std::cout << "pagman - pog: " << (result = pagman - pog) << '\n';

    std::cout << "pog + pagman : " << (result = pog + pagman) << '\n';
    std::cout << "pog - pagman : " << (result = pog - pagman) << '\n';

    std::cout << "dot pagman pog : " << pog * pagman << '\n';

    pog[0] = 1.0f;
    pog[1] = 1.0f;
    pog[2] = 1.0f;

    std::cout << "pog vector: " << pog << '\n';

    pog = pog + pagman;

    std::cout << "pog cross: " << (result = pagman | pog) << '\n';

    mat<float, 3, 3> m1({{1.0f,2.0f,3.0f},
                        {4.0f,5.0f,6.0f},
                        {7.0f,8.0f,9.0f}});
    std::cout << "Matrix m1\n" << m1 << '\n';
    mat<float, 3, 3> m2({{9.0f,8.0f,7.0f},
                        {6.0f,5.0f,4.0f},
                        {3.0f,2.0f,1.0f}});
    std::cout << "Matrix m2\n" << m2 << '\n';
    mat<float, 3, 3> res;

    std::cout << "m1 + m2:\n" << (res = m1 + m2) << '\n';
    std::cout << "m1 - m2:\n" << (res = m1 - m2) << '\n';
    std::cout << "3.5 * m1:\n" << (res = 3.5f * m1) << '\n';
    
    return 0;
}
