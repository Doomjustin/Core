#ifndef NEVERMORE_UTILITY_H
#define NEVERMORE_UTILITY_H

#include <concepts>
#include <utility>


namespace SF {

// 只单纯检测能否copy
template<class T>
concept Copyable = std::copy_constructible<T> &&
                   std::assignable_from<T&, T&> &&
                   std::assignable_from<T&, const T&> &&
                   std::assignable_from<T&, const T>;

// 可单例化的类型T，需要满足不可copy但是可移动
template<typename T, typename... Args>
concept Singletonable = std::constructible_from<T, Args...> &&
                        std::movable<T> &&
                        !Copyable<T>;

// 多数时候，单例模式没有什么用，如果你用了，大概率是设计的不好
template<typename T, typename... Args>
    requires Singletonable<T, Args...>
T& make_singleton(Args&&... args)
{
    static T singleton { std::forward<Args>(args)... };

    return singleton;
}

} // namespace SF


// 抄袭自Qt的QT_DISABLE_COPY
#define SF_DISABLE_COPY(Class) \
    Class(const Class& other) = delete;\
    Class& operator=(const Class& other) = delete;

// 抄袭自Qt的QT_DISABLE_COPY_MOVE
#define SF_DISABLE_COPY_MOVE(Class) \
    SF_DISABLE_COPY(Class) \
    Class(Class&& other) noexcept = delete; \
    Class& operator=(Class&& other) noexcept = delete;

// 提供默认move语义
#define SF_DEFAULT_MOVE(Class) \
    Class(Class&& other) noexcept = default; \
    Class& operator=(Class&& other) noexcept = default;

#define SF_COPY_SEMANTIC_FWD(Class) \
    Class(const Class& other); \
    Class& operator=(const Class& other);

#define SF_MOVE_SEMANTIC_FWD(Class) \
    Class(Class&& other) noexcept ; \
    Class& operator=(Class&& other) noexcept;

#define SF_COPY_SEMANTIC_DEFINATION(Class) \
    Class::Class(const Class& other) = default; \
    Class& Class::operator=(const Class& other) = default;

#define SF_COPY_SEMANTIC_DEFINATION_DELETE(Class) \
    Class::Class(const Class& other) = delete; \
    Class& Class::operator=(const Class& other) = delete;

#define SF_MOVE_SEMANTIC_DEFINATION(Class) \
    Class::Class(Class&& other) noexcept = default; \
    Class& Class::operator=(Class&& other) noexcept = default;

#define SF_MOVE_SEMANTIC_DEFINATION_DELETE(Class) \
    Class::Class(Class&& other) noexcept = delete; \
    Class& Class::operator=(Class&& other) noexcept = delete;

#endif // NEVERMORE_UTILITY_H