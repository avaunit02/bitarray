#include "bitarray.hpp"
#include <cassert>
#include <iostream>

int main() {
    {
        using T = bitarray<129>;
        assert((T{-1LLU, -1LLU, -1LLU}).all());
        assert((T{0, 0, 0}).none());
        assert(!(T{0, 0, 0}).any());
        assert((T{1, 0, 0}).any());
        assert((T{3, 2, 1}).count() == 4);

        assert((T{0, 1 << 10, 0}).count_trailing_zeros() == 64 + 10);
        assert((T{0, 1 << 10, 0}).count_leading_zeros() == 129 - 64 - 11);
    }

    {
        /*
        bitarray<192> input{~0LLU, 0LLU, 0LLU}, output{};
        std::cout << input << std::endl;
        input = input >> 63;
        std::cout << input << std::endl;
        */
    }

    {
        bitarray<64> input{0xffLLU << 32 | 0x55LLU};
        std::cout << input << std::endl;
        auto output = input.interleave<2>(input);
        std::cout << output << std::endl;
    }

    return 0;
}
