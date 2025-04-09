#pragma once
#include "Command.hpp"
#include <iostream>

class MoveLeftCommand : public Command {
public:
    void execute() override {
        std::cout << "Move Left" << std::endl;
    }
};