#include <complex>

#include "typelists.hpp"

using namespace typelists;

static_assert(concepts::All<float>);
static_assert(concepts::complex::All<std::complex<uint64_t>>);
static_assert(!concepts::real::All<std::complex<double>>);
static_assert(!concepts::real::All<char>);
static_assert(concepts::real::Logical<bool>);
static_assert(!concepts::real::Logical<double>);

int main()
{
  return 0;
}
