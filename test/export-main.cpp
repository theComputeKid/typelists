#include "typelists.hpp"

template <typelists::base::real::concepts::All T1, typelists::base::real::concepts::Logical T2,
          typelists::base::real::concepts::Float T3>
void tripleTemplateFuncWithConcepts();

template <typename T1, typename T2>
void doubleTemplateFunc();

namespace testNS
{
  template <typename T>
  void singleTemplateFunc();
}

int main()
{
  testNS::singleTemplateFunc<float>();
  doubleTemplateFunc<double, bool>();
  tripleTemplateFuncWithConcepts<double, bool, float>();
  return 0;
}
