/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 23:07:34 by apaula-l          #+#    #+#             */
/*   Updated: 2025/10/21 21:06:39 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data data;
    data.i = 42;
    
    std::cout << "Original Data Address: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized: " << raw << std::endl;
    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserializer ptr: " << deserialized << std::endl;
    std::cout << "Deserialized id: " << deserialized->i <<std::endl;

    if (deserialized == &data)
        std::cout << "Pointers match!" << std::endl;
    else
        std::cout << "Pointers don't match!" << std::endl;

    std::cout << "Data -> id: " << deserialized->i << std::endl;
}
