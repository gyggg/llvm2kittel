// This file is part of llvm2KITTeL
//
// Copyright 2010-2014 Stephan Falke
//
// Licensed under the University of Illinois/NCSA Open Source License.
// See LICENSE for details.

#ifndef LOOP_CONDITION_BLOCKS_COLLECTOR_H
#define LOOP_CONDITION_BLOCKS_COLLECTOR_H

#include "Version.h"

// llvm includes
#include "WARN_OFF.h"
#include <llvm/Analysis/LoopPass.h>
#if LLVM_VERSION < VERSION(3, 3)
  #include <llvm/InstrTypes.h>
  #include <llvm/Function.h>
  #include <llvm/Instructions.h>
#else
  #include <llvm/IR/InstrTypes.h>
  #include <llvm/IR/Function.h>
  #include <llvm/IR/Instructions.h>
#endif
#include <llvm/Pass.h>
#include "WARN_ON.h"

// C++ includes
#include <set>

class LoopConditionBlocksCollector : public llvm::LoopPass
{

public:
    LoopConditionBlocksCollector();
    ~LoopConditionBlocksCollector();

    bool runOnLoop(llvm::Loop *L, llvm::LPPassManager &LPM);

    virtual const char *getPassName() const { return "Collect loop condition blocks"; }

    static char ID;

    std::set<llvm::BasicBlock*> getLoopConditionBlocks() { return m_conditionBlocks; }

private:
    std::set<llvm::BasicBlock*> m_conditionBlocks;

private:
    LoopConditionBlocksCollector(const LoopConditionBlocksCollector &);
    LoopConditionBlocksCollector &operator=(const LoopConditionBlocksCollector &);

};

LoopConditionBlocksCollector *createLoopConditionBlocksCollectorPass();

#endif // LOOP_CONDITION_BLOCKS_COLLECTOR_H
