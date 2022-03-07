#pragma once

#include "traits.h"
#include "linalg.h"

namespace vic
{
namespace linalg
{

template <typename TMatrix>
constexpr auto Transpose(const TMatrix& matrix)
{
	if constexpr (std::is_same_v<TMatrix, Identity<TMatrix::DataType, TMatrix::Rows>>)
	{
		return matrix; // transpose of identity is identity
	}
	else if constexpr (std::is_same_v<TMatrix, Diagonal<TMatrix::DataType, TMatrix::Rows, TMatrix::Columns>> &&
		(TMatrix::Rows == TMatrix::Columns))
	{
		return matrix; // transpose of diag is diag
	}
	else
	{
		return TransposeGeneral(matrix);
	}
}

template <typename TMatrix>
constexpr auto TransposeGeneral(const TMatrix& matrix)
{
	Matrix<TMatrix::DataType, TMatrix::GetColumns(), TMatrix::GetRows()> transpose;
	for (std::size_t i = 0; i < TMatrix::GetRows(); ++i)
		for (std::size_t j = 0; j < TMatrix::GetColumns(); ++j)
			transpose.At(j, i) = matrix.Get(i, j);
	return transpose;
}

}
}