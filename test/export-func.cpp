#include "typelists.hpp"

template <typelists::base::real::concepts::All T1, typename T2>
void doubleTemplateFunc()
{
}
TEMPLATE_INSTANTIATE_DOUBLE_TEMPLATE(doubleTemplateFunc, typelists::base::real::All, typelists::base::real::All)

template <typelists::base::real::concepts::Float T>
void singleTemplateFunc()
{
}
TEMPLATE_INSTANTIATE_SINGLE_TEMPLATE(singleTemplateFunc, typelists::base::real::Float)
