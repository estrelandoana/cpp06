/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 23:04:43 by codespace         #+#    #+#             */
/*   Updated: 2025/10/12 23:25:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

    unsigned long Serializer::serialize(Data* ptr) {
        return reinterpret_cast<unsigned long>(ptr);
    }
    
    Data* Serializer::deserialize(unsigned long raw) {
        return reinterpret_cast<Data*>(raw);
    }