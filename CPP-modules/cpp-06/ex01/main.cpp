// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.cpp                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/08/09 16:21:50 by ael-khni          #+#    #+#             */
// /*   Updated: 2022/08/09 16:26:52 by ael-khni         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include <iostream>

struct Data
{
    std::string name;
    int         age;
};

uintptr_t    serialize(Data *data)
{
    return reinterpret_cast<uintptr_t>(data);
}

Data*   deserialize(uintptr_t data)
{
    return reinterpret_cast<Data*>(data);
}

int main()
{
    Data *data = new Data;

    data->name = "achraf";
    data->age = 30;

    uintptr_t p = serialize(data);
    // std::cout << "serialize:\t" << p << std::endl;
    Data *d = deserialize(p);

    std::cout << "Name:\t" << d->name << std::endl;
    std::cout << "Age:\t" << d->age << std::endl;
    std::cout << "Old ptr:\t\t" << d << std::endl;

    std::cout << "Deserialized ptr:\t" << d << std::endl;

    delete data;

    return 0;
}