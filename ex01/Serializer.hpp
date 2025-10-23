/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:44:57 by apaula-l          #+#    #+#             */
/*   Updated: 2025/10/21 21:06:59 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include <iostream>
# include "Data.hpp"

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer&);
        Serializer& operator=(const Serializer&);
        ~Serializer();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
