/**
 * @file utils.hpp
 *
 * @brief Helpers for compile-time-metaprogramming.
 *
 * @author theComputeKid (theComputeKid@gmail.com)
 * @version 1.0
 * @date 2022-06-04
 *
 * @copyright Copyright (c) 2022 theComputeKid
 */
#pragma once

#include <complex>
#include <cstddef>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

/** @brief Utilities to help with compile-time variant metaprogramming magic. */
namespace typelists::utils
{
  /**
   * @brief Helper to concat typelists held in two variants. Ordering is kept consistent, with
   * Variant 2 added onto Variant 1.
   */
  template <typename Variant1, typename Variant2>
  struct concatTypeLists;

  template <typename... V1, typename... V2>
  struct concatTypeLists<std::variant<V1...>, std::variant<V2...>>
  {
    using type = typename std::variant<V1..., V2...>;
  };

  /** @brief Helper to complexify typelists. Ordering is kept consistent. E.g: float -> std::complex<float>. */
  template <typename Variant>
  struct wrapTypeListsAsComplex;

  template <typename... V1>
  struct wrapTypeListsAsComplex<std::variant<V1...>>
  {
    using type = typename std::variant<std::complex<V1>...>;
  };

  /** @brief Helper to wrap typelists in std::vector. Ordering is kept consistent. E.g: float -> std::vector<float>. */
  template <typename Variant>
  struct wrapTypeListsAsVector;

  template <typename... V1>
  struct wrapTypeListsAsVector<std::variant<V1...>>
  {
    using type = typename std::variant<std::vector<V1>...>;
  };

  /**
   * @brief Check if the type is a valid member of a variant.
   *
   * @tparam T Type to find inside variant
   * @tparam VARIANT_T Signature of the variant, i.e. one of the typelists above.
   */
  template <typename T, typename VARIANT_T>
  struct isTypeMemberOfVariant;

  template <typename T, typename... ALL_T>
  struct isTypeMemberOfVariant<T, std::variant<ALL_T...>> : public std::disjunction<std::is_same<T, ALL_T>...>
  {
  };

  /** @brief Check if a type is part of a typelist. */
  template <typename Type, typename TypeList>
  constexpr bool isTypeInTypeList()
  {
    return isTypeMemberOfVariant<Type, TypeList>();
  }

  /**
   * @brief Find the zero-based index of a type in a variant given it is present.
   *
   * @tparam VariantType Signature of a variant, i.e. the type-lists defined above
   * @tparam T The type for which the index is to be found
   * @tparam Index Zero based location of the type T in the type list of a VariantType. Used for
   * recursion.
   * @return constexpr size_t Zero based location of the type T in the type list of a VariantType
   */
  template <typename VariantType, typename T, size_t Index = 0>
  constexpr size_t getTypeIndexInVariant()
  {
    static_assert(isTypeInTypeList<T, VariantType>());
    if constexpr (Index == std::variant_size_v<VariantType>)
    {
      return Index;
    }
    else if constexpr (std::is_same_v<std::variant_alternative_t<Index, VariantType>, T>)
    {
      return Index;
    }
    else
    {
      return getTypeIndexInVariant<VariantType, T, Index + 1>();
    }
    return 0;
  }

  /** @brief Convert a type to its corresponding type in another typelist. E.g.: float -> std::complex<float>. */
  template <typename OriginalType, typename OriginalTypeList, typename NewTypeList>
  struct GetCorrespondingType
  {
    static_assert(isTypeInTypeList<OriginalType, OriginalTypeList>());
    static_assert(std::variant_size_v<OriginalTypeList> == std::variant_size_v<NewTypeList>);
    using type =
        typename std::variant_alternative_t<getTypeIndexInVariant<OriginalTypeList, OriginalType>(), NewTypeList>;
    static_assert(isTypeInTypeList<type, NewTypeList>());
  };
} // namespace typelists::utils
