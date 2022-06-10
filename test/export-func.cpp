#include "typelists.hpp"

template <typelists::base::real::concepts::All T1, typelists::base::real::concepts::Logical T2,
          typelists::base::real::concepts::Float T3>
void tripleTemplateFunc()
{
}
TYPE_LIST_INSTANTIATE_3_TEMPLATES(tripleTemplateFunc, typelists::base::real::All, typelists::base::real::Logical,
                                  typelists::base::real::Float)

template <typelists::base::real::concepts::All T1, typename T2>
void doubleTemplateFunc()
{
}
TYPE_LIST_INSTANTIATE_2_TEMPLATES(doubleTemplateFunc, typelists::base::real::All, typelists::base::real::All)

namespace testNS
{
  template <typelists::base::real::concepts::Float T>
  void singleTemplateFunc()
  {
  }
  TYPE_LIST_INSTANTIATE_1_TEMPLATE(singleTemplateFunc, typelists::base::real::Float)

} // namespace testNS
