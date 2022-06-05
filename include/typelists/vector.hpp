/**
 * @file vector.hpp
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
#include "typelists/base.hpp"
#include "typelists/utils.hpp"

/**  @brief Compile-time template metaprogramming with std::variant. */
namespace typelists::vector
{
  namespace real
  {
    /** @brief Typelist for logical */
    using Logical = utils::wrapTypeListsAsVector<base::real::Logical>::type;

    /** @brief Typelist for RealFloat in vector */
    using Float = utils::wrapTypeListsAsVector<base::real::Float>::type;

    /** @brief Typelist to use when your functor supports only real signed integer types. */
    using SignedInteger = utils::wrapTypeListsAsVector<base::real::SignedInteger>::type;

    /** @brief Typelist to use when your functor supports only real unsigned integer types. */
    using UnsignedInteger = utils::wrapTypeListsAsVector<base::real::SignedInteger>::type;

    /** @brief Typelist to use when your functor supports only real integer types. */
    using Integer = utils::wrapTypeListsAsVector<base::real::SignedInteger>::type;

    /** @brief Typelist to use when your functor supports only real integer types. */
    using Integral = utils::wrapTypeListsAsVector<base::real::Integral>::type;

    /** @brief Typelist to use when your functor supports real numeric types. */
    using Numeric = utils::wrapTypeListsAsVector<base::real::Numeric>::type;

    /** @brief Typelist to use when your functor supports everything in this header. */
    using All = utils::wrapTypeListsAsVector<base::real::All>::type;

  } // namespace real

  /**  @brief Complex vector types. */
  namespace complex
  {
    /** @brief Typelist for logical */
    using Logical = utils::wrapTypeListsAsVector<base::complex::Logical>::type;

    /** @brief Typelist for RealFloat in vector */
    using Float = utils::wrapTypeListsAsVector<base::complex::Float>::type;

    /** @brief Typelist to use when your functor supports only real signed integer types. */
    using SignedInteger = utils::wrapTypeListsAsVector<base::complex::SignedInteger>::type;

    /** @brief Typelist to use when your functor supports only real unsigned integer types. */
    using UnsignedInteger = utils::wrapTypeListsAsVector<base::complex::SignedInteger>::type;

    /** @brief Typelist to use when your functor supports only real integer types. */
    using Integer = utils::wrapTypeListsAsVector<base::complex::SignedInteger>::type;

    /** @brief Typelist to use when your functor supports only real integer types. */
    using Integral = utils::wrapTypeListsAsVector<base::complex::Integral>::type;

    /** @brief Typelist to use when your functor supports real numeric types. */
    using Numeric = utils::wrapTypeListsAsVector<base::complex::Numeric>::type;

    /** @brief Typelist to use when your functor supports everything in this header. */
    using All = utils::wrapTypeListsAsVector<base::complex::All>::type;

  } // namespace complex

  using All = utils::wrapTypeListsAsVector<base::All>::type;

#if __cplusplus >= 202002L
  namespace real::concepts
  {
    template <typename T>
    concept Logical = utils::isTypeInTypeList<T, vector::real::Logical>();

    template <typename T>
    concept Float = utils::isTypeInTypeList<T, vector::real::Float>();

    template <typename T>
    concept SignedInteger = utils::isTypeInTypeList<T, vector::real::SignedInteger>();

    template <typename T>
    concept UnsignedIntegerTypes = utils::isTypeInTypeList<T, vector::real::UnsignedInteger>();

    template <typename T>
    concept Integer = utils::isTypeInTypeList<T, vector::real::Integer>();

    template <typename T>
    concept Integral = utils::isTypeInTypeList<T, vector::real::Integral>();

    template <typename T>
    concept Numeric = utils::isTypeInTypeList<T, vector::real::Numeric>();

    template <typename T>
    concept All = utils::isTypeInTypeList<T, vector::real::All>();
  } // namespace real::concepts

  namespace complex::concepts
  {
    template <typename T>
    concept Logical = utils::isTypeInTypeList<T, vector::complex::Logical>();

    template <typename T>
    concept Float = utils::isTypeInTypeList<T, vector::complex::Float>();

    template <typename T>
    concept SignedInteger = utils::isTypeInTypeList<T, vector::complex::SignedInteger>();

    template <typename T>
    concept UnsignedIntegerTypes = utils::isTypeInTypeList<T, vector::complex::UnsignedInteger>();

    template <typename T>
    concept Integer = utils::isTypeInTypeList<T, vector::complex::Integer>();

    template <typename T>
    concept Integral = utils::isTypeInTypeList<T, vector::complex::Integral>();

    template <typename T>
    concept Numeric = utils::isTypeInTypeList<T, vector::complex::Numeric>();

    template <typename T>
    concept All = utils::isTypeInTypeList<T, vector::complex::All>();
  } // namespace complex::concepts

  namespace concepts
  {
    template <typename T>
    concept All = utils::isTypeInTypeList<T, vector::All>();
  }
#endif
} // namespace typelists::vector
