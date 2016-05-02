#include "..\include\SparseDataVector.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  EMLL
//  File:     SparseDataVector.tcc (dataset)
//  Authors:  Ofer Dekel
//
//  [copyright]
//
////////////////////////////////////////////////////////////////////////////////////////////////////

namespace dataset
{
    template<typename ValueType, typename IntegerListType>
    template<typename IndexValueIteratorType, typename concept>
    SparseDataVector<ValueType, IntegerListType>::SparseDataVector(IndexValueIteratorType indexValueIterator)
    {
        while(indexValueIterator.IsValid())
        {
            auto indexValue = indexValueIterator.Get();
            SparseDataVector<ValueType, IntegerListType>::AppendEntry(indexValue.index, indexValue.value); // explicit call to SparseDataVector<ValueType>::AppendEntry is given to avoid virtual function call in Ctor
            indexValueIterator.Next();
        }
    }

    template<typename ValueType, typename IntegerListType>
    std::unique_ptr<IDataVector> SparseDataVector<ValueType, IntegerListType>::Clone() const
    {
        return std::make_unique<SparseDataVector<ValueType, IntegerListType>>(*this); 
    }

    template<typename ValueType, typename IntegerListType>
    std::vector<double> SparseDataVector<ValueType, IntegerListType>::ToArray(uint64_t size) const
    {
        auto vector = std::vector<double>(size);
        auto indexValueIterator = GetIterator();

        while(indexValueIterator.IsValid())
        {
            auto indexValue = indexValueIterator.Get();
            vector[indexValue.index] = indexValue.value;
            indexValueIterator.Next();
        }

        return vector;
    }
}
