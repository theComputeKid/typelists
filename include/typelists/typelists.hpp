/**
 * @file base.hpp
 *
 * @brief Typelists for compile-time-metaprogramming.
 *
 * @author theComputeKid (theComputeKid@gmail.com)
 * @version 1.0
 * @date 2022-06-04
 *
 * @copyright Copyright (c) 2022 theComputeKid
 */
#pragma once
#include <cstdint>
#include <tuple>
#include <variant>

#include "typelists/cppstd.hpp"
#include "typelists/utils.hpp"

/**  @brief Basic real types. */
namespace typelists
{
  template <typename... T>
  using Collection = std::tuple<T...>;

  namespace real
  {
    /** @brief Typelist for logical */
    using Logical = std::variant<bool>;

    /** @brief Typelist to use when your functor supports only real floating-point types. */
    using Float = std::variant<float, double>;

    /** @brief Typelist to use when your functor supports only real signed integer types. */
    using SignedInteger = std::variant<int8_t, int16_t, int32_t, int64_t>;

    /** @brief Typelist to use when your functor supports only real unsigned integer types. */
    using UnsignedInteger = std::variant<uint8_t, uint16_t, uint32_t, uint64_t>;

    /** @brief Typelist to use when your functor supports only real integer types. */
    using Integer = utils::concatTypeLists<SignedInteger, UnsignedInteger>::type;

    /** @brief Typelist to use when your functor supports all integral types. */
    using Integral = utils::concatTypeLists<Integer, Logical>::type;

    /** @brief Typelist to use when your functor supports real numeric types. */
    using Numeric = utils::concatTypeLists<Float, Integer>::type;

    /** @brief Typelist to use when your functor supports everything in this header. */
    using All = utils::concatTypeLists<Numeric, Logical>::type;

  } // namespace real

  /**  @brief Complex real types. */
  namespace complex
  {
    /** @brief Typelist for logical */
    using Logical = utils::wrapTypeListsAsComplex<real::Logical>::type;

    /** @brief Typelist for RealFloat in vector */
    using Float = utils::wrapTypeListsAsComplex<real::Float>::type;

    /** @brief Typelist to use when your functor supports only real signed integer types. */
    using SignedInteger = utils::wrapTypeListsAsComplex<real::SignedInteger>::type;

    /** @brief Typelist to use when your functor supports only real unsigned integer types. */
    using UnsignedInteger = utils::wrapTypeListsAsComplex<real::UnsignedInteger>::type;

    /** @brief Typelist to use when your functor supports only real integer types. */
    using Integer = utils::wrapTypeListsAsComplex<real::Integer>::type;

    /** @brief Typelist to use when your functor supports only real integer types. */
    using Integral = utils::wrapTypeListsAsComplex<real::Integral>::type;

    /** @brief Typelist to use when your functor supports real numeric types. */
    using Numeric = utils::wrapTypeListsAsComplex<real::Numeric>::type;

    /** @brief Typelist to use when your functor supports everything in this header. */
    using All = utils::wrapTypeListsAsComplex<real::All>::type;

  } // namespace complex

  using All = utils::concatTypeLists<real::All, complex::All>::type;

#ifdef TYPE_LIST_CPP_2020
  namespace concepts
  {
    namespace real
    {
      template <typename T>
      concept Logical = utils::isTypeInTypeList<T, typelists::real::Logical>();

      template <typename T>
      concept Float = utils::isTypeInTypeList<T, typelists::real::Float>();

      template <typename T>
      concept SignedInteger = utils::isTypeInTypeList<T, typelists::real::SignedInteger>();

      template <typename T>
      concept UnsignedIntegerTypes = utils::isTypeInTypeList<T, typelists::real::UnsignedInteger>();

      template <typename T>
      concept Integer = utils::isTypeInTypeList<T, typelists::real::Integer>();

      template <typename T>
      concept Integral = utils::isTypeInTypeList<T, typelists::real::Integral>();

      template <typename T>
      concept Numeric = utils::isTypeInTypeList<T, typelists::real::Numeric>();

      template <typename T>
      concept All = utils::isTypeInTypeList<T, typelists::real::All>();
    } // namespace real

    namespace complex
    {
      template <typename T>
      concept Logical = utils::isTypeInTypeList<T, typelists::complex::Logical>();

      template <typename T>
      concept Float = utils::isTypeInTypeList<T, typelists::complex::Float>();

      template <typename T>
      concept SignedInteger = utils::isTypeInTypeList<T, typelists::complex::SignedInteger>();

      template <typename T>
      concept UnsignedIntegerTypes = utils::isTypeInTypeList<T, typelists::complex::UnsignedInteger>();

      template <typename T>
      concept Integer = utils::isTypeInTypeList<T, typelists::complex::Integer>();

      template <typename T>
      concept Integral = utils::isTypeInTypeList<T, typelists::complex::Integral>();

      template <typename T>
      concept Numeric = utils::isTypeInTypeList<T, typelists::complex::Numeric>();

      template <typename T>
      concept All = utils::isTypeInTypeList<T, typelists::complex::All>();

    } // namespace complex

    template <typename T>
    concept All = utils::isTypeInTypeList<T, typelists::All>();
  } // namespace concepts
#endif
} // namespace typelists
