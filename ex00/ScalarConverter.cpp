/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:59:01 by apaula-l          #+#    #+#             */
/*   Updated: 2025/10/26 15:53:59 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <limits>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <sstream>

static bool isCharLiteral(const std::string& s) {
    return s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]));
}

static bool isSpecial(const std::string& s) {
    return s == "nan" || s == "nanf" ||
           s == "+inf" || s == "+inff" ||
           s == "-inf" || s == "-inff";
}

void ScalarConverter::convert(const std::string& literal) {
    bool char_ok = false;
    bool int_ok = false;
    bool float_ok = false;
    bool double_ok = false;

    char c = 0;
    long i = 0;
    float f = 0.0f;
    double d = 0.0;

    if (isSpecial(literal)) {
        if (literal == "nan" || literal == "nanf") {
            d = std::numeric_limits<double>::quiet_NaN();
            f = std::numeric_limits<float>::quiet_NaN();
        } else if (literal == "+inf" || literal == "+inff") {
            d = std::numeric_limits<double>::infinity();
            f = std::numeric_limits<float>::infinity();
        } else {
            d = -std::numeric_limits<double>::infinity();
            f = -std::numeric_limits<float>::infinity();
        }
        double_ok = true;
        float_ok = true;
    }
    else if (isCharLiteral(literal)) {
        c = literal[0];
        char_ok = true;
        int_ok = true;
        i = static_cast<long>(c);
        d = static_cast<double>(c);
        f = static_cast<float>(c);
        double_ok = float_ok = true;
    }
    else {
        char *end = NULL;
        errno = 0;
        long li = std::strtol(literal.c_str(), &end, 10);
        if (errno == 0 && end != literal.c_str() && *end == '\0') {
            i = li;
            int_ok = true;
            if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
                char_ok = true;
            d = static_cast<double>(i);
            f = static_cast<float>(i);
            double_ok = float_ok = true;
        } else {
            std::string s = literal;

            if (!s.empty() && s[s.size() - 1] == 'f' && s != "f") {
                s = s.substr(0, s.size() - 1);
            }

            errno = 0;
            end = NULL;
            double ld = std::strtod(s.c_str(), &end);
            if (errno == 0 && end != s.c_str() && *end == '\0') {
                d = ld;
                double_ok = true;

                if (std::fabs(d) <= std::numeric_limits<float>::max() || std::isnan(d) || std::isinf(d)) {
                    f = static_cast<float>(d);
                    float_ok = true;
                } else {
                    float_ok = false;
                }

                if (!(d != d) && !std::isinf(d) &&
                    d <= static_cast<double>(std::numeric_limits<int>::max()) &&
                    d >= static_cast<double>(std::numeric_limits<int>::min()))
                {
                    i = static_cast<long>(d);
                    int_ok = true;
                    if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
                        char_ok = true;
                }
            } else {}
        }
    }

    std::cout << "char: ";
    if (!char_ok) {
        std::cout << "impossible" << std::endl;
    } else {
        char display = static_cast<char>(i);
        if (std::isprint(static_cast<unsigned char>(display)))
            std::cout << "'" << display << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }

    std::cout << "int: ";
    if (!int_ok) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << i << std::endl;
    }

    std::cout << "float: ";
    if (!float_ok) {
        std::cout << "impossible" << std::endl;
    } else {
        if (std::isnan(f))
            std::cout << "nanf" << std::endl;
        else if (std::isinf(f)) {
            if (f > 0) std::cout << "+inff" << std::endl;
            else std::cout << "-inff" << std::endl;
        } else {
            std::ostringstream oss;
            if (std::fabs(f - static_cast<int>(f)) < 1e-6)
                oss << std::fixed << std::setprecision(1) << f;
            else
                oss << f;
            std::cout << oss.str() << "f" << std::endl;
        }
    }

    std::cout << "double: ";
    if (!double_ok) {
        std::cout << "impossible" << std::endl;
    } else {
        if (std::isnan(d))
            std::cout << "nan" << std::endl;
        else if (std::isinf(d)) {
            if (d > 0) std::cout << "+inf" << std::endl;
            else std::cout << "-inf" << std::endl;
        } else {
            std::ostringstream oss;
            if (std::fabs(d - static_cast<long>(d)) < 1e-9)
                oss << std::fixed << std::setprecision(1) << d;
            else
                oss << d;
            std::cout << oss.str() << std::endl;
        }
    }
}
