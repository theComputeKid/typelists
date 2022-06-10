/**
 * @file export.hpp
 *
 * @brief Macros to help export C++ templates.
 *
 * @author theComputeKid (theComputeKid@gmail.com)
 * @version 1.0
 * @date 2022-06-05
 *
 * @copyright Copyright (c) 2022 theComputeKid
 */
#pragma once
#include <any>
#include <variant>

/**
 * @brief Signature of the instantiation macro. Call this in the same namespace as the function to be instantiated. This
 * macro works by calling the std::visit for every type in the typelist, tricking the compiler into exporting symbols
 * for each type.
 *
 * @arg func - function name to be instantiated. Must not be namespaced.
 * @arg typelist - types to instatiate.
 */
#define TYPE_LIST_INSTANTIATE_1_TEMPLATE(func, typelist)                                                               \
  std::any func##TemplateInstantiate(typelist const types)                                                             \
  {                                                                                                                    \
    return std::visit([](auto t) { return std::any(func<decltype(t)>); }, types);                                      \
  }

#define TYPE_LIST_INSTANTIATE_2_TEMPLATES(func, typelist1, typelist2)                                                  \
  std::any func##TemplateInstantiate(typelist1 const types1, typelist2 const types2)                                   \
  {                                                                                                                    \
    return std::visit([](auto t1, auto t2) { return std::any(func<decltype(t1), decltype(t2)>); }, types1, types2);    \
  }

#define TYPE_LIST_INSTANTIATE_3_TEMPLATES(func, typelist1, typelist2, typelist3)                                       \
  std::any func##TemplateInstantiate(typelist1 const types1, typelist2 const types2, typelist3 const types3)           \
  {                                                                                                                    \
    return std::visit([](auto t1, auto t2, auto t3)                                                                    \
                      { return std::any(func<decltype(t1), decltype(t2), decltype(t3)>); },                            \
                      types1, types2, types3);                                                                         \
  }
