#ifndef NEVERMORE_STRING_UTILITY_H
#define NEVERMORE_STRING_UTILITY_H

#include <string>
#include <string_view>
#include <algorithm>


namespace SF {

template<typename CharT, typename Traits = std::char_traits<CharT>>
std::basic_string<CharT, Traits> to_upper(std::basic_string<CharT, Traits> str)
{
    std::transform(str.begin(), str.end(),
                   str.begin(),
                   [] (unsigned char c) { return std::toupper(c); });

    return str;
}

template<typename CharT, typename Traits = std::char_traits<CharT>>
std::basic_string<CharT, Traits> to_lower(std::basic_string<CharT, Traits> str)
{
    std::transform(str.begin(), str.end(),
                   str.begin(),
                   [] (unsigned char c) { return std::tolower(c); });

    return str;
}

template<typename CharT, typename Traits = std::char_traits<CharT>>
std::basic_string<CharT, Traits> trim(std::basic_string<CharT, Traits> str)
{
    str.erase(std::remove_if(str.begin(),
                             str.end(),
                             [] (unsigned char x) { return std::isspace(x); }),
              str.end());

    return str;
}

template<typename CharT, typename Traits = std::char_traits<CharT>>
std::basic_string<CharT, Traits> left_trim(std::basic_string<CharT, Traits> str)
{
    str.erase(str.begin(),
              std::find_if(str.begin(),
                           str.end(),
                           [] (unsigned char x) { return !std::isspace(x); }));

    return str;
}

template<typename CharT, typename Traits = std::char_traits<CharT>>
std::basic_string<CharT, Traits> right_trim(std::basic_string<CharT, Traits> str)
{
    auto iter = std::find_if(str.rbegin(), str.rend(),
                             [] (unsigned char x) { return !std::isspace(x); });

    str.erase(iter.base(), str.end());

    return str;
}

} // namespace SF

#endif // NEVERMORE_STRING_UTILITY_H