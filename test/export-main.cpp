#include "typelists.hpp"

using namespace typelists;

template <concepts::real::All T1, concepts::real::Logical T2, concepts::real::Float T3>
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
