#include <complex>
#include <cstdint>

#include "typelists.hpp"

using namespace typelists;

using typelists::utils::isTypeInTypeList;
static_assert(isTypeInTypeList<double, base::real::Float>());
static_assert(isTypeInTypeList<std::complex<uint16_t>, base::complex::UnsignedInteger>());
static_assert(!isTypeInTypeList<uint64_t, base::complex::All>());
static_assert(!isTypeInTypeList<bool, vector::complex::All>());

using typelists::utils::getTypeIndexInVariant;
static_assert(getTypeIndexInVariant<base::real::Float, double>() == 1);
static_assert(getTypeIndexInVariant<base::real::Float, float>() == 0);
static_assert(getTypeIndexInVariant<base::complex::UnsignedInteger, std::complex<uint32_t>>() == 2);

using typelists::utils::GetCorrespondingType;
static_assert(
    std::is_same_v<GetCorrespondingType<double, base::real::Float, base::complex::Float>::type, std::complex<double>>);
static_assert(std::is_same_v<
              GetCorrespondingType<int64_t, base::real::SignedInteger, base::real::UnsignedInteger>::type, uint64_t>);

int main()
{
  return 0;
}
