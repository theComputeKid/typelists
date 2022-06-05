/**
 * @file cppstd.hpp
 *
 * @brief C++ standard macros.
 *
 * @author theComputeKid (theComputeKid@gmail.com)
 * @version 0.1
 * @date 2022-06-05
 *
 * @copyright Copyright (c) 2022 theComputeKid
 */
#pragma once

#if __cplusplus >= 202002L
#  define TYPE_LIST_CPP_2020
#elif _MSVC_LANG >= 202002L
#  define TYPE_LIST_CPP_2020
#endif
