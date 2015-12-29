// ZeroDataVector.cpp

#include "ZeroDataVector.h"

#include <stdexcept>

using std::runtime_error;

namespace dataset
{

    bool ZeroDataVector::Iterator::IsValid() const
    {
        return false;
    }

    void ZeroDataVector::Iterator::Next()
    {}

    IndexValue ZeroDataVector::Iterator::Get() const
    {
        throw runtime_error("this code should bever be reached");
    }

    ZeroDataVector::ZeroDataVector(const IDataVector& other) 
    {}

    IDataVector::type ZeroDataVector::GetType() const
    {
        return type::zero;
    }

    void ZeroDataVector::PushBack(uint64 index, double value)
    {
        if(value != 0)
        {
            throw runtime_error("Cannot set elements of a zero vector");
        }
    }

    void ZeroDataVector::Reset()
    {}

    uint64 ZeroDataVector::Size() const
    {
        return 0;
    }

    uint64 ZeroDataVector::NumNonzeros() const
    {
        return 0;
    }

    double ZeroDataVector::Norm2() const
    {
        return 0.0;
    }

    void ZeroDataVector::AddTo(double* p_other, double scalar) const
    {}

    double ZeroDataVector::Dot(const double* p_other) const
    {
        return 0.0;
    }

    ZeroDataVector::Iterator ZeroDataVector::GetIterator() const
    {
        return Iterator();
    }

    void ZeroDataVector::Print(ostream & os) const
    {}
}