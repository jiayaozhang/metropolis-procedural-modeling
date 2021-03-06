//#####################################################################
// Copyright 2009, Jerry Talton.
// This software is governed by the license contained in LICENSE.
//#####################################################################
#ifndef _PLUS_3_SYMBOL_HPP_
#define _PLUS_3_SYMBOL_HPP_

#include "Distributions.hpp"
#include "PlusSymbol.hpp"

namespace ProceduralModeling{

//#####################################################################
// Class Plus_3Symbol
//#####################################################################
class Plus_3Symbol : public PlusSymbol
{
public:
    Plus_3Symbol(Symbol** symbolTable)
     :PlusSymbol(true,1,4,1,2,symbolTable)
    {}

    virtual void render(const float* params) const
    {
        float newParams[1]={
            30.0+params[1]/12.0*Distributions::UniformSample(5.0,55.0,params[0])*params[2]};
        PlusSymbol::render(newParams);
    }

    virtual uint produce(const SymbolEntry* input,SymbolEntry* output,float& logProbability) const
    {
        output[0].mID=319;
        memcpy(output+1,input,sizeof(SymbolEntry)*3);
        logProbability=0;
        return 4;
    }

    virtual ushort setFlags(const float* params) const
    {
        return SymbolEntry::DETERMINISTIC;
    }

    virtual float logDiffusionProbability(const float* params) const
    {
        return log(Distributions::UniformEval(5.0,55.0,params[0]));
    }

    virtual void initGraphics()
    {
        PlusSymbol::initGraphics();
    }

    virtual void saveToMesh(const float* params) const
    {
        float newParams[1]={
            30.0+params[1]/12.0*Distributions::UniformSample(5.0,55.0,params[0])*params[2]};
        PlusSymbol::saveToMesh(newParams);
    }

    virtual void voxel(const float* params) const
    {
        float newParams[1]={
            30.0+params[1]/12.0*Distributions::UniformSample(5.0,55.0,params[0])*params[2]};
        PlusSymbol::voxel(newParams);
    }

    virtual const char* symbolName() const
    { return "Plus_3"; }

//#####################################################################
};

//#####################################################################
} // namespace ProceduralModeling

#endif //_PLUS_3_SYMBOL_HPP_
