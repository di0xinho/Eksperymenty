#pragma once
#include "Command.hpp"
#include <iostream>

class MoveRightCommand : public Command {
public:
    void execute() override {
        std::cout << "Move Right" << std::endl;
    }
};