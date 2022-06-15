#include "typelists/typelists.hpp"

using namespace typelists;
static_assert(std::variant_size_v<real::Numeric> == std::variant_size_v<complex::Numeric>);
static_assert(std::variant_size_v<real::SignedInteger> == std::variant_size_v<complex::UnsignedInteger>);

using typelists::utils::isTypeInTypeList;
static_assert(isTypeInTypeList<double, real::Float>());
static_assert(isTypeInTypeList<std::complex<uint16_t>, complex::UnsignedInteger>());
static_assert(!isTypeInTypeList<uint64_t, complex::All>());
static_assert(!isTypeInTypeList<bool, complex::All>());

int main()
{
  return 0;
}
