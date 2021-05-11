

local inputs = UserInputs.GetInstance()


if inputs.keyboard_a == true then
    velocity["x"] = -800
elseif inputs.keyboard_d == true then
    velocity["x"] = 800
else    
    velocity["x"] = 0
end

if inputs.keyboard_w == true then
    velocity["y"] = -800
elseif inputs.keyboard_s == true then
    velocity["y"] = 800
else    
    velocity["y"] = 0
end

