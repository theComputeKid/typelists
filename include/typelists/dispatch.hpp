/**
 * @file dispatch.hpp
 *
 * @brief Runtime type dispatch.
 *
 * @author theComputeKid (theComputeKid@gmail.com)
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022 theComputeKid
 */
#pragma once
#include <complex>
#include <cstdint>

#include "typelists/types.hpp"
#include "typelists/utils.hpp"

namespace typelists
{
  namespace detail
  {
    template <typename T>
    constexpr T* iProcessArgs(void* in)
    {
      return static_cast<T*>(in);
    }
  } // namespace detail

#define TYPELIST_DISPATCH_MACRO(runtimeType, cppType)                                                                  \
  if constexpr (utils::isTypeInTypeList<cppType, TypeList>())                                                          \
  {                                                                                                                    \
    if (t == runtimeType)                                                                                              \
    {                                                                                                                  \
      wrapper(detail::iProcessArgs<cppType>(args)...);                                                                 \
      return true;                                                                                                     \
    }                                                                                                                  \
  }

  /**
   * @brief Runtime dispatch for a templated function wrapped in a lambda. Inside the lambda, all template parameters
   * are converted into pointers to the template type, and so non-pointer types must be dereferenced.
   *
   * @tparam TypeList Typelist that the function is instantiated for.
   * @tparam LambdaType Deduced automatically.
   * @tparam Args Deduced automatically.
   * @param wrapper Lambda containing the templated function.
   * @param t runtime type to dispatch to.
   * @param c runtime complexity to dispatch to.
   * @param args Arguments to template function that are templated - must all be void*.
   * @return false if none of the accepted types were matched with the runtime type.
   */
  template <typename TypeList, typename LambdaType, typename... Args>
  bool runtimeDispatchFunc(LambdaType wrapper, Types const t, Complexity const c, Args... args)
  {
    if (c == Complexity::REAL)
    {
      TYPELIST_DISPATCH_MACRO(Types::FLOAT, float)
      TYPELIST_DISPATCH_MACRO(Types::DOUBLE, double)

      TYPELIST_DISPATCH_MACRO(Types::UINT8, uint8_t)
      TYPELIST_DISPATCH_MACRO(Types::UINT16, uint16_t)
      TYPELIST_DISPATCH_MACRO(Types::UINT32, uint32_t)
      TYPELIST_DISPATCH_MACRO(Types::UINT64, uint64_t)

      TYPELIST_DISPATCH_MACRO(Types::INT8, int8_t)
      TYPELIST_DISPATCH_MACRO(Types::INT16, int16_t)
      TYPELIST_DISPATCH_MACRO(Types::INT32, int32_t)
      TYPELIST_DISPATCH_MACRO(Types::INT64, int64_t)

      TYPELIST_DISPATCH_MACRO(Types::BOOL, bool)
    }
    else
    {
      TYPELIST_DISPATCH_MACRO(Types::FLOAT, std::complex<float>)
      TYPELIST_DISPATCH_MACRO(Types::DOUBLE, std::complex<double>)

      TYPELIST_DISPATCH_MACRO(Types::UINT8, std::complex<uint8_t>)
      TYPELIST_DISPATCH_MACRO(Types::UINT16, std::complex<uint16_t>)
      TYPELIST_DISPATCH_MACRO(Types::UINT32, std::complex<uint32_t>)
      TYPELIST_DISPATCH_MACRO(Types::UINT64, std::complex<uint64_t>)

      TYPELIST_DISPATCH_MACRO(Types::INT8, std::complex<int8_t>)
      TYPELIST_DISPATCH_MACRO(Types::INT16, std::complex<int16_t>)
      TYPELIST_DISPATCH_MACRO(Types::INT32, std::complex<int32_t>)
      TYPELIST_DISPATCH_MACRO(Types::INT64, std::complex<int64_t>)

      TYPELIST_DISPATCH_MACRO(Types::BOOL, std::complex<bool>)
    }
    return false;
  }
#undef TYPELIST_DISPATCH_MACRO
} // namespace typelists
