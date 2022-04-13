/*
 * core.hpp
 *
 *
 * Create Date : 2022-04-13 21:36:41
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */

#ifndef CORE_HPP__
#define CORE_HPP__

#include <iostream>

#include <fmt/core.h>

#define yk_debug(...) std::cout << fmt::format(__VA_ARGS__) << std::endl;


class SampleClass {
  public:
    SampleClass() {}

    void print_hello();
};

#endif // CORE_HPP__
