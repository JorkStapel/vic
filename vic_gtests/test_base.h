#pragma once

#include "pch.h"

#include "vic/linalg/determinant.h"
#include "vic/linalg/inverse.h"
#include "vic/linalg/linalg.h"
#include "vic/linalg/matrix_view.h"
#include "vic/linalg/transpose.h"

using namespace vic::linalg;

template <typename TMat1, typename TMat2>
void ExpectMatrixEqual(const TMat1& mat1, const TMat2& mat2, const double tol = 1E-10)
{
    ASSERT_EQ(mat1.GetRows(), mat2.GetRows());
    ASSERT_EQ(mat1.GetColumns(), mat2.GetColumns());

    for(std::size_t i = 0; i < mat1.GetRows(); ++i)
        for(std::size_t j = 0; j < mat2.GetColumns(); ++j)
            EXPECT_NEAR(mat1.Get(i, j), mat2.Get(i, j), tol);
}

template <typename TIter1, typename TIter2>
void ExpectIterablesEqual(const TIter1 begin1, const TIter1 end1, const TIter2 begin2, const TIter2 end2)
{
    // TODO: require TIter1:value_type == float
    auto it1 = begin1;
    auto it2 = begin2;
    for(; it1 < end1 && it2 < end2; ++it1, ++it2)
        EXPECT_NEAR(*it1, *it2, 1E-10);
}

template <typename TVec1, typename TVec2>
void ExpectVectorsEqual(const TVec1& vec1, const TVec2& vec2)
{
    ExpectIterablesEqual(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()); // pass along
}