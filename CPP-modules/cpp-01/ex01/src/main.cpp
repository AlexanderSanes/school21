
#include "../include/Zombie.hpp"

#define N 4

int main() {
    Zombie *zombiz = zombieHorde(N, "Chump");

    for (size_t i = 0; i < N; i++) {
        zombiz[i].announce();
    }

    delete [] zombiz;
    return 0;
}