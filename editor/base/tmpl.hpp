//
// Created by timking.nf@foxmail.com on 2021/3/2.
//

#ifndef LEETCODE_TMPL_HPP
#define LEETCODE_TMPL_HPP

#include <tuple>

template<typename F, typename T, std::size_t... I>
auto apply_impl(F f, const T& t, std::index_sequence<I...>)
  -> decltype(f(std::get<I>(t)...))
{
  return f(std::get<I>(t)...);
}

template<typename O, typename F, typename T, std::size_t... I>
auto apply_impl(O *obj, F f, const T& t, std::index_sequence<I...>)
  -> decltype((obj->*f)(std::get<I>(t)...))
{
  return (obj->*f)(std::get<I>(t)...);
}

// 辅助帮助实现 tuple 参数展开
template<typename F, typename T>
auto apply(F f, const T& t)
  -> decltype(apply_impl(f, t, std::make_index_sequence<std::tuple_size<T>::value>()))
{
  return apply_impl(f, t, std::make_index_sequence<std::tuple_size<T>::value>());
}

template<typename O, typename F, typename T>
auto apply(O *obj, F f, const T& t)
  -> decltype(apply_impl(obj, f, t, std::make_index_sequence<std::tuple_size<T>::value>()))
{
  return apply_impl(obj, f, t, std::make_index_sequence<std::tuple_size<T>::value>());
}


#endif  // LEETCODE_TMPL_HPP
