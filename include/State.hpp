#pragma once

class State {
public:
    virtual ~State() = default;

    virtual void Init() = 0;

    virtual void handleInput() = 0;
    virtual void update(float dt) = 0;
    virtual void render(float dt) = 0;

    virtual void pause() {}
    virtual void resume() {}
};