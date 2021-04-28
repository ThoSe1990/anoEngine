#ifndef _USERINPUTS_HPP_
#define _USERINPUTS_HPP_


class UserInputs
{
private:
    UserInputs () {}
public:

    UserInputs(UserInputs const&) = delete;
    void operator=(UserInputs const&) = delete;

    static UserInputs& GetInstance() noexcept
    {
        static UserInputs instance;
        return instance;
    }
    int mouseX;
    int mouseY;
    
    bool mouseButtonLeftUp;
    bool mouseButtonLeftDown;
    bool mouseButtonLeftClick;

    bool mouseButtonRightUp;
    bool mouseButtonRightDown;
    bool mouseButtonRightClick;

    bool keyboard_a;
    bool keyboard_s;
    bool keyboard_d;
    bool keyboard_w;

};

#endif