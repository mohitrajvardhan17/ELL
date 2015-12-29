// DataVectorBuilder.h

#pragma once

#include "IDataVector.h"

// stl
#include <memory>
using std::unique_ptr;
using std::move;

namespace dataset
{
    /// DataVectorBuilder Base class
    ///
    template<typename DefaultDataVectorType>
    class DataVectorBuilder
    {
    public:

        /// Chooses the optimal DataVector representation for a list of index-value pairs
        ///
        template<typename IndexValueIteratorType>
        static unique_ptr<IDataVector> Build(IndexValueIteratorType IndexValueIterator);
    };
}

#include "../tcc/DataVectorBuilder.tcc"
