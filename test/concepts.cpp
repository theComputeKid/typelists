#include <complex>
#include <cstdint>
#include <vector>

#include "typelists.hpp"

using namespace typelists;

static_assert(base::concepts::All<float>);
static_assert(base::complex::concepts::All<std::complex<uint64_t>>);
static_assert(!base::real::concepts::All<std::complex<double>>);
static_assert(!base::real::concepts::All<char>);

static_assert(base::real::concepts::Logical<bool>);
static_assert(!base::complex::concepts::Logical<double>);

static_assert(vector::real::concepts::All<std::vector<float>>);
static_assert(vector::complex::concepts::All<std::vector<std::complex<uint64_t>>>);
static_assert(!vector::complex::concepts::All<std::complex<double>>);
static_assert(!vector::real::concepts::All<char>);

int main()
{
  return 0;
}
