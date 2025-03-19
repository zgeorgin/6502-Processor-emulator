#pragma once

#include <cstdint>

enum class Conditions : uint8_t
{
  C, Z, I, D, B, L, V, N
};

struct condReg_t {
  uint8_t reg_value;

  bool get(Conditions cond) { return (reg_value >> static_cast<uint8_t>(cond)) & 1; } 
  void set(Conditions cond, const bool& value) { reg_value = reg_value & ~(1 << static_cast<uint8_t>(cond)) | (value << static_cast<uint8_t>(cond)); }

  // TODO: check the efficiency of this operations 
};

class Processor {
  uint8_t A;    // accumulator
  uint8_t X, Y; // index registers
  uint16_t PC;  // command counter
  uint8_t S;    // stack pointer
  condReg_t P;    // condition register

public:
};