/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 23:45:16 by apaula-l          #+#    #+#             */
/*   Updated: 2025/10/21 21:07:48 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
    int r = std::rand() % 3;
    if (r == 0) return new A();
    if (r == 1) return new B();
    return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
    else std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Unknown" << std::endl;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    for (int i = 0; i < 5; ++i) {
        Base* p = generate();
        identify(p);
        identify(*p);
        delete p;
    }
    return 0;
}
