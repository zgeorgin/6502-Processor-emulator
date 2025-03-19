#pragma once

#include <ALU.h>
#include <registers.h>

class CPU {
  Registers *regs;

  ALU alu;
    
public:
  CPU() : regs(new Registers()) {}
  ~CPU() { delete regs; }
};