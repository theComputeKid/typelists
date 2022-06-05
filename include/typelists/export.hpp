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
#define TEMPLATE_INSTANTIATE_SINGLE_TEMPLATE(func, typelist)                                                           \
  std::any func##TemplateInstantiate(typelist const types)                                                             \
  {                                                                                                                    \
    return std::visit([](auto t) { return std::any(func<decltype(t)>); }, types);                                      \
  }

#define TEMPLATE_INSTANTIATE_DOUBLE_TEMPLATE(func, typelist1, typelist2)                                               \
  std::any func##TemplateInstantiate(typelist1 const types1, typelist2 const types2)                                   \
  {                                                                                                                    \
    return std::visit([](auto t1, auto t2) { return std::any(func<decltype(t1), decltype(t2)>); }, types1, types2);    \
  }
