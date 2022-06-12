#include <tuple>

#include "typelists.hpp"

template <typelists::base::real::concepts::All T1, typelists::base::real::concepts::Logical T2,
          typelists::base::real::concepts::Float T3>
void tripleTemplateFuncWithConcepts()
{
}
TYPE_LIST_INSTANTIATE_3_TEMPLATES(tripleTemplateFuncWithConcepts, typelists::base::real::All,
                                  typelists::base::real::Logical, typelists::base::real::Float)

template <typename T1, typename T2>
void doubleTemplateFunc()
{
}
using t = std::tuple<typelists::base::real::All, typelists::base::real::All>;
TYPE_LIST_INSTANTIATE(doubleTemplateFunc, t)

namespace testNS
{
  template <typename T>
  void singleTemplateFunc()
  {
  }
  TYPE_LIST_INSTANTIATE(singleTemplateFunc, typelists::base::real::Float)
} // namespace testNS
