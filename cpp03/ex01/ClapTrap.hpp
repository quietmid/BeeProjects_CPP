
#pragma once

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>


class ClapTrap
{
    protected: // protected memebers are accessible by derived classes, such as ScavTap
        std::string name;
        int hp;
        int ep;
        int dmg;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();
        void attack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        //setter
        void setDmg(int dmg);
        //getter
        int getEp() const;
        int getHp() const;
        int getDmg() const;
        std::string getName() const;
};

#endif