#include <iostream>
#include <type_traits>

#include "typelists.hpp"

using namespace typelists;

template <concepts::real::Float T>
void myFunc(T* inOut, T const in1, int const in2)
{
  std::cout << "Entered: ";
  if constexpr (std::is_same_v<T, float>)
  {
    std::cout << "float";
  }
  else
  {
    std::cout << "double";
  }
  std::cout << std::endl;
}

int main()
{
  double a = 1;
  int in2 = 1;
  void* in = &a;

  auto const wrapper = [&](auto&& v1, auto&& v2) { myFunc(v1, *v2, in2); };
  if (!typelists::runtimeDispatchFunc<real::Float>(wrapper, Types::FLOAT, Complexity::REAL, in, in))
  {
    std::cout << "Incorrect: runtime type not found in accepted types." << std::endl;
    return 1;
  }

  if (!typelists::runtimeDispatchFunc<real::Float>(wrapper, Types::FLOAT, Complexity::COMPLEX, in, in))
  {
    std::cout << "Correct: runtime type not found in accepted types." << std::endl;
  }

  return 0;
}
