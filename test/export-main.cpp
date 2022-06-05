#include "typelists.hpp"

template <typelists::base::real::concepts::All T1, typename T2>
void doubleTemplateFunc();

template <typelists::base::real::concepts::Float T>
void singleTemplateFunc();

int main()
{
  singleTemplateFunc<float>();
  doubleTemplateFunc<double, bool>();
  return 0;
}
