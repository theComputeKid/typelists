#include "typelists.hpp"

template <typelists::base::real::concepts::All T1, typename T2>
void doubleTemplateFunc()
{
}
TYPE_LIST_INSTANTIATE_2_TEMPLATE(doubleTemplateFunc, typelists::base::real::All, typelists::base::real::All)

template <typelists::base::real::concepts::Float T>
void singleTemplateFunc()
{
}
TYPE_LIST_INSTANTIATE_1_TEMPLATE(singleTemplateFunc, typelists::base::real::Float)
