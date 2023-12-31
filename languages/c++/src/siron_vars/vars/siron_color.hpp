#pragma once

#include "../siron_var.hpp"
#include "../../siron_utils.hpp"

class siron_color : public siron_var {
public:
    union 
    {
        struct {
            int red;
            int green;
            int blue;
            float alpha;
        };

        struct {
            int r;
            int g;
            int b;
            float a;
        };

    };
public:
    void set_data(int vr, int vg, int vb, float va) { red = vr; green = vg; blue = vb; alpha = va; }
    void set_data(int vall, float va) { r = vall; g = vall; b = vall; a = va; }

    void set_data(int vr, int vg, int vb) { red = vr; green = vg; blue = vb; alpha = 1.0f; }
    void set_data(int vall) { r = vall; g = vall; b = vall; a = 1.0f; }
public:
    virtual void ReadData(siron_token token) override { 
        red = siron_utils::siron_convert_string_to_int(token.get_subtoken(2).get_subtoken(0).token_text);
        green = siron_utils::siron_convert_string_to_int(token.get_subtoken(2).get_subtoken(1).token_text);
        blue = siron_utils::siron_convert_string_to_int(token.get_subtoken(2).get_subtoken(2).token_text);
        alpha = siron_utils::siron_convert_string_to_float(token.get_subtoken(2).get_subtoken(3).token_text);
    };
    virtual siron_var_data WriteData() override { 
        siron_var_data data = siron_var_data();
        data.variable_type = "color";

        data.items.add(siron_utils::siron_convert_int_to_string(r));
        data.items.add(siron_utils::siron_convert_int_to_string(g));
        data.items.add(siron_utils::siron_convert_int_to_string(b));
        data.items.add(siron_utils::siron_convert_float_to_string(a));

        return data; 
    }
public:
    virtual siron_string_type to_string() override {
        siron_string_type return_value = "(";
        return_value += siron_utils::siron_convert_int_to_string(red) + ", ";
        return_value += siron_utils::siron_convert_int_to_string(green) + ", ";
        return_value += siron_utils::siron_convert_int_to_string(blue) + ", ";
        return_value += siron_utils::siron_convert_float_to_string(alpha);
        return_value += ")";
        return return_value;
    };
};