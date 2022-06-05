#include "typelists.hpp"

using namespace typelists;
static_assert(std::variant_size_v<vector::real::Numeric> == std::variant_size_v<vector::complex::Numeric>);
static_assert(std::variant_size_v<vector::real::SignedInteger> == std::variant_size_v<base::complex::UnsignedInteger>);
static_assert(std::variant_size_v<vector::All> == std::variant_size_v<base::All>);

int main()
{
  return 0;
}
