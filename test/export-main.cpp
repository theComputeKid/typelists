#include "typelists.hpp"

template <typelists::base::real::concepts::All T1, typelists::base::real::concepts::Logical T2,
          typelists::base::real::concepts::Float T3>
void tripleTemplateFunc();

template <typelists::base::real::concepts::All T1, typename T2>
void doubleTemplateFunc();

namespace testNS
{
  template <typelists::base::real::concepts::Float T>
  void singleTemplateFunc();
}

int main()
{
  testNS::singleTemplateFunc<float>();
  doubleTemplateFunc<double, bool>();
  tripleTemplateFunc<double, bool, float>();
  return 0;
}
