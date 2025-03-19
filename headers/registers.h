#pragma once

#include <cstdint>

enum class Conditions : uint8_t { C, Z, I, D, B, L, V, N };

struct condReg_t {
  uint8_t reg_value;

  bool get(Conditions cond) { return (reg_value >> static_cast<uint8_t>(cond)) & 1; }
  void set(Conditions cond, const bool &value) { reg_value = reg_value & ~(1 << static_cast<uint8_t>(cond)) | (value << static_cast<uint8_t>(cond)); }

  // TODO: check the efficiency of this operations
};

struct Registers {
  // registers for programs
  uint8_t AC;       // accumulator
  uint8_t X, Y;     // index registers
  uint8_t PCH, PCL; // instruction counter
  uint8_t S;        // stack pointer
  condReg_t P;      // condition register

  // inner registers
  uint8_t IR;         // instruction register
  uint8_t AI, BI;     // ALU inputs
  uint8_t ADD;        // ALU inbetween result
  uint8_t PCHS, PCLS; // helping registers for instruction counter
  uint8_t ABH, ABL;   // output adress registers
  uint8_t DL;         // data latch
  uint8_t DOR;        // data output register
};
