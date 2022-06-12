
# typelists: helpers for managing types

Requirements:
- C++17 compiler for typelists
- C++20 compiler for concepts

See tests for compilable examples.

This header-only library is meant to help compile-time metaprogramming. Using the typelists defined in the header files, you can:

1. Check if a type is in a typelist
```
typelists::utils::isTypeInTypeList<double, real::Float>()
// returns true if double is in the real::Float typelist.
```

2. Get the index of a type in a typelist
```
typelists::utils::getTypeIndexInVariant<typelists::base::real::Float, double>()
// returns 1 because double is the second type in the base::real::Float typelist
```

3. Map types in a typelist
```
>> typelists::utils::GetCorrespondingType<double, base::real::Float, base::complex::Float>::type
// returns std::complex<double>> because double is the second type in the base::real::Float typelist,
// which is also the index of std::complex<double>> in base::complex::Float.
// This way, we can map double to its complex version.
```

4. Restrict types using typelist concepts (C++20)
```
>> template <typelists::base::real::concepts::Float T> void myFunc();
// will only accept types in base::real::Float for satisfying T.
```

5. Export symbols for template functions based on typelists
```
template <typename T> void myFunc(){}
TEMPLATE_INSTANTIATE_SINGLE_TEMPLATE(myFunc, typelists::base::real::Float)
// instantiates myFunc for all types in real::Float.

template <typename T> void myFunc(){}
TEMPLATE_INSTANTIATE(myFunc, typelists::base::real::Float)
// Alternate way for the same results.

template <typename T1, typename T2> void myFunc(){}
using t = std::tuple<typelists::base::real::Float, typelists::base::real::Integer>
TEMPLATE_INSTANTIATE_SINGLE_TEMPLATE(myFunc, typelists::base::real::Float)
// instantiates T1 for all types in real::Float and T2 for all types in real::Integer.
```
