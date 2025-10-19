/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:44:57 by codespace         #+#    #+#             */
/*   Updated: 2025/10/12 23:25:36 by codespace        ###   ########.fr       */
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
