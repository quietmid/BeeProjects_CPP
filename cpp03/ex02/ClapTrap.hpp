
#pragma once

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string name;
        unsigned int hp;
        unsigned int ep;
        unsigned int dmg;
    public:
        //constructors & destructors
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        virtual ~ClapTrap();

        //Assignment Operator
        ClapTrap& operator=(const ClapTrap &copy);
        //functions
        virtual void attack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        //setter
        void setDmg(unsigned int dmg);
        //getter
        unsigned int getEp() const;
        unsigned int getHp() const;
        std::string getName() const;
};

#endif