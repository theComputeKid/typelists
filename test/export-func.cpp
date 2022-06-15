#include <tuple>

#include "typelists.hpp"

using namespace typelists;

template <concepts::real::All T1, concepts::real::Logical T2, concepts::real::Float T3>
void tripleTemplateFuncWithConcepts()
{
}
TYPE_LIST_INSTANTIATE_3_TEMPLATES(tripleTemplateFuncWithConcepts, real::All, real::Logical, real::Float)

template <typename T1, typename T2>
void doubleTemplateFunc()
{
}
using t = Collection<real::All, real::All>;
TYPE_LIST_INSTANTIATE(doubleTemplateFunc, t)

namespace testNS
{
  template <typename T>
  void singleTemplateFunc()
  {
  }
  TYPE_LIST_INSTANTIATE(singleTemplateFunc, real::Float)
} // namespace testNS
