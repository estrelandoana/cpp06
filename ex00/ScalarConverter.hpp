/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:55:25 by apaula-l          #+#    #+#             */
/*   Updated: 2025/10/22 19:00:56 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter {
    public:
        static void convert(const std::string& literal);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();
};

#endif
