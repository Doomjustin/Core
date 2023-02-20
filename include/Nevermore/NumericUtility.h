#ifndef NEVERMORE_NUMERIC_UTILITY_H
#define NEVERMORE_NUMERIC_UTILITY_H

#include <concepts>
#include <utility>


namespace SF {

template<typename T>
    requires std::integral<T>
constexpr bool is_even(T t)
{
    return t % 2 == 0;
}

template<typename T>
    requires std::integral<T>
constexpr bool is_odd(T t)
{
    return !is_even(std::forward<T>(t));
}

} // namespace SF

#endif // NEVERMORE_NUMERIC_UTILITY_H