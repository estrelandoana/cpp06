/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 23:07:34 by codespace         #+#    #+#             */
/*   Updated: 2025/10/12 23:28:52 by codespace        ###   ########.fr       */
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
