//
// Created by alanp on 07/02/2019.
//

#pragma once

#include <cstddef>
#include <vector>
#include <algorithm>

typedef unsigned char byte;

class Bitset {
    std::vector<bool> bits_;
    static constexpr byte u8_to_and_[8]  = {
        0x01,
        0x02,
        0x04,
        0x08,
        0x10,
        0x20,
        0x40,
        0x80,
    };
    size_t num_of_bits_;
public:
    Bitset() : num_of_bits_(0) {}

    template <class NUM>
    Bitset(NUM input) : bits_(sizeof(input) * 8, false) {
        static_assert(std::is_unsigned<NUM>::value,
                     "Rotate Left only makes sense for unsigned types");
        std::vector<byte> input_bytes;
        while (input > 0) {
            input_bytes.push_back((byte)(input % 256));
            input /= 256;
        }
        Initialise(input_bytes);
    }


    Bitset(const std::vector<byte>& input) : bits_(input.size() * 8, false) {
        Initialise(input);
    }

    void Initialise(const std::vector<byte>& input) {
        num_of_bits_ = input.size() * 8;
        bits_.resize(num_of_bits_, false);
        for (int i = 0; i < num_of_bits_; i++) {
            bits_[i] = ((input[i / 8] & u8_to_and_[i % 8]) > 0);
        }
    }

    void Reverse() {
        for (int i = 0; i < num_of_bits_ / 2; i++) {
            std::swap(bits_[i], bits_[num_of_bits_ - 1 - i]);
        }
    }

    unsigned long long GetULL() const {
        unsigned long long ret_val = 0;
        unsigned long long to_or = 1;
        for(int i = 0; i < std::min(bits_.size(), (size_t)64); i++) {
            ret_val |= (bits_[i])? to_or : 0;
            to_or <<= 1;
        }
        return ret_val;
    }

    std::vector<byte> GetBytes() const {
        const auto count_bytes = (bits_.size() + 7) / 8;
        std::vector<byte> ret_val(count_bytes, 0);
        for (unsigned long i = 0; i < count_bytes; i++) {
            byte to_or = 1;
            for(int j = 0; j < 8; j++) {
                ret_val[i] |= (bits_[8 * i + j])? to_or : 0;
                to_or <<= 1;
            }
        }
        return ret_val;
    }
    size_t GetLength() const {
        return bits_.size();
    }
    auto operator[](size_t i) const  -> decltype(bits_[i]){
        return bits_[i];
    }

    auto operator[](size_t i)  -> decltype(bits_[i]){
        return bits_[i];
    }
};