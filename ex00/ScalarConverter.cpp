/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:59:01 by codespace         #+#    #+#             */
/*   Updated: 2025/10/01 02:03:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string& s) {
	return s.length() == 1 && !isdigit(s[0]);
}

static bool isInt(const std::string& s) {
	char* end;
	long val = std::strtol(s.c_str(), &end, 10);
	return *end == '\0' && val >= INT_MIN && val <= INT_MAX;
}

static bool isFloat(const std::string& s) {
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return true;
	size_t len = s.length();
	if (len < 2 || s[len - 1] != 'f')
		return false;
	char* end;
	std::strtof(s.c_str(), &end);
	return end == s.c_str() + len - 1;
}

static bool isDouble(const std::string& s) {
	if (s == "nan" || s == "+inf" || s == "-inf")
		return true;
	char* end;
	std::strtod(s.c_str(), &end);
	return *end == '\0';
}

void ScalarConverter::convert(const std::string& literal) {
	bool charType = isChar(literal);
	bool intType = isInt(literal);
	bool floatType = isFloat(literal);
	bool doubleType = isDouble(literal);

	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;

	if (charType) {
		c = literal[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	} else if (intType) {
		i = std::atoi(literal.c_str());
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
	} else if (floatType) {
		if (literal == "nanf") f = NAN;
		else if (literal == "+inff") f = INFINITY;
		else if (literal == "-inff") f = -INFINITY;
		else f = std::strtof(literal.c_str(), NULL);
		d = static_cast<double>(f);
		i = static_cast<int>(f);
		c = static_cast<char>(i);
	} else if (doubleType) {
		if (literal == "nan") d = NAN;
		else if (literal == "+inf") d = INFINITY;
		else if (literal == "-inf") d = -INFINITY;
		else d = std::strtod(literal.c_str(), NULL);
		f = static_cast<float>(d);
		i = static_cast<int>(d);
		c = static_cast<char>(i);
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	std::cout << "char: ";
	if (charType || (i >= 0 && i <= 127)) {
		if (isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "impossible" << std::endl;
	}

	std::cout << "int: ";
	if ((floatType && (literal == "nanf" || literal == "+inff" || literal == "-inff")) ||
		(doubleType && (literal == "nan" || literal == "+inf" || literal == "-inf"))) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << i << std::endl;
	}

	std::cout << "float: ";
	if (floatType && (literal == "nanf" || literal == "+inff" || literal == "-inff")) {
		std::cout << literal << std::endl;
	} else if (doubleType && (literal == "nan" || literal == "+inf" || literal == "-inf")) {
		if (literal == "nan") std::cout << "nanf" << std::endl;
		else if (literal == "+inf") std::cout << "+inff" << std::endl;
		else if (literal == "-inf") std::cout << "-inff" << std::endl;
	} else {
		std::cout << f;
		if (f - static_cast<int>(f) == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}

	std::cout << "double: ";
	if (floatType && (literal == "nanf" || literal == "+inff" || literal == "-inff")) {
		if (literal == "nanf") std::cout << "nan" << std::endl;
		else if (literal == "+inff") std::cout << "+inf" << std::endl;
		else if (literal == "-inff") std::cout << "-inf" << std::endl;
	} else if (doubleType && (literal == "nan" || literal == "+inf" || literal == "-inf")) {
		std::cout << literal << std::endl;
	} else {
		std::cout << d;
		if (d - static_cast<int>(d) == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
}
