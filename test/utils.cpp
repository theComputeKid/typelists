#include <complex>
#include <cstdint>

#include "typelists.hpp"

using namespace typelists;

using typelists::utils::isTypeInTypeList;
static_assert(isTypeInTypeList<double, real::Float>());
static_assert(isTypeInTypeList<std::complex<uint16_t>, complex::UnsignedInteger>());
static_assert(!isTypeInTypeList<uint64_t, complex::All>());

using typelists::utils::getTypeIndexInVariant;
static_assert(getTypeIndexInVariant<real::Float, double>() == 1);
static_assert(getTypeIndexInVariant<real::Float, float>() == 0);
static_assert(getTypeIndexInVariant<complex::UnsignedInteger, std::complex<uint32_t>>() == 2);

using typelists::utils::GetCorrespondingType;
static_assert(
    std::is_same_v<GetCorrespondingType<double, real::Float, complex::Float>::type, std::complex<double>>);
static_assert(std::is_same_v<
              GetCorrespondingType<int64_t, real::SignedInteger, real::UnsignedInteger>::type, uint64_t>);

int main()
{
  return 0;
}
