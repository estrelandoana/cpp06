/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 23:45:16 by codespace         #+#    #+#             */
/*   Updated: 2025/10/13 00:14:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate (void) {
    std::srand(std::time(0));
    int r = std::rand() % 3;

    if (r == 0){
        std::cout << "A instaced\n" << std::endl;
        return new A();
    } else if (r == 1) {
        std::cout << "B instanced\n" << std::endl;
        return new B();
    } else {
        std::cout << "C instanced\n" << std::endl;
        return new C();
    }
}

void identify (Base* ptr) {
    if (dynamic_cast<A*>(ptr))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(ptr))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(ptr))
        std::cout << "C" << std::endl;
}

void identify (Base& ptr) {
    try {
        (void)dynamic_cast<A&>(ptr);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception&) {}

    try {
        (void)dynamic_cast<B&>(ptr);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception&) {}

    try {
        (void)dynamic_cast<C&>(ptr);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception&) {}
}

int main() {
    Base* ptr = generate();
    identify(ptr);
    identify(*ptr);
    delete ptr;
}
