/**
 * @file types.hpp
 *
 * @brief Enums to specify weakly-typed runtime types.
 *
 * @author theComputeKid (theComputeKid@gmail.com)
 * @version 0.1
 * @date 2022-06-10
 *
 * @copyright Copyright (c) 2022 theComputeKid
 */
#pragma once

namespace typelists::dispatch
{
  enum struct Types
  {
    BOOL,
    FLOAT,
    DOUBLE,
    INT8,
    INT16,
    INT32,
    INT64
  };

  enum struct Complexity
  {
    REAL,
    COMPLEX
  };

} // namespace typelists
