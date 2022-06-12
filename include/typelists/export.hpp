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

#include "typelists/utils.hpp"

/**
 * @brief Signature of the instantiation macro. Call this in the same namespace as the function to be instantiated. This
 * macro works by calling the std::visit for every type in the typelist, tricking the compiler into exporting symbols
 * for each type.
 *
 * @arg func - function name to be instantiated. Must not be namespaced.
 * @arg typelist - types to instatiate.
 */

/** @brief Instantiate one template explicitly. */
#define TYPE_LIST_INSTANTIATE_1_TEMPLATE(func, typelist)                                                               \
  std::any func##TemplateInstantiate(typelist const types)                                                             \
  {                                                                                                                    \
    return std::visit([](auto t) { return std::any(func<decltype(t)>); }, types);                                      \
  }

/** @brief Instantiate two templates explicitly. */
#define TYPE_LIST_INSTANTIATE_2_TEMPLATES(func, typelist1, typelist2)                                                  \
  std::any func##TemplateInstantiate(typelist1 const types1, typelist2 const types2)                                   \
  {                                                                                                                    \
    return std::visit([](auto t1, auto t2) { return std::any(func<decltype(t1), decltype(t2)>); }, types1, types2);    \
  }

/** @brief Instantiate three templates explicitly. */
#define TYPE_LIST_INSTANTIATE_3_TEMPLATES(func, typelist1, typelist2, typelist3)                                       \
  std::any func##TemplateInstantiate(typelist1 const types1, typelist2 const types2, typelist3 const types3)           \
  {                                                                                                                    \
    return std::visit([](auto t1, auto t2, auto t3)                                                                    \
                      { return std::any(func<decltype(t1), decltype(t2), decltype(t3)>); },                            \
                      types1, types2, types3);                                                                         \
  }

/**
 * @brief Instantiate for N types, providing either a single typelist, or a collection of typelists as a tuple, which
 * has been typedef'd to not have any commas in the name. See export-func.cpp for usage.
 */
#define TYPE_LIST_INSTANTIATE(func, list)                                                                              \
  template <typename... Args>                                                                                          \
  std::any func##InstantiateForEachType(Args... t)                                                                     \
  {                                                                                                                    \
    return std::any(func<Args...>);                                                                                    \
  }                                                                                                                    \
                                                                                                                       \
  template <typename... Args>                                                                                          \
  std::any func##InstantiateForEachTypeList(Args... t)                                                                 \
  {                                                                                                                    \
    return std::visit([&](auto... v) { return func##InstantiateForEachType(v...); }, t...);                            \
  }                                                                                                                    \
                                                                                                                       \
  template <typename T>                                                                                                \
  std::any func##DetermineWhetherTupleOrVariant(T t)                                                                   \
  {                                                                                                                    \
    if constexpr (typelists::utils::IsCollectionOfTypeLists<T>())                                                      \
    {                                                                                                                  \
      auto lambdaWrapper = [&](auto... args) { return func##InstantiateForEachTypeList(args...); };                    \
      return std::apply(lambdaWrapper, t);                                                                             \
    }                                                                                                                  \
    else                                                                                                               \
    {                                                                                                                  \
      static_assert(typelists::utils::IsTypeList<T>());                                                                \
      return std::visit([](auto v) { return std::any(func<decltype(v)>); }, t);                                        \
    }                                                                                                                  \
  }                                                                                                                    \
                                                                                                                       \
  std::any func##Instantiate(list t)                                                                                   \
  {                                                                                                                    \
    return func##DetermineWhetherTupleOrVariant(t);                                                                    \
  }
