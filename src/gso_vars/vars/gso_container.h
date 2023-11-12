#pragma once

#include "../gso_var.h"

#include "gso_number.h"
#include "gso_int.h"
#include "gso_float.h"
#include "gso_double.h"
#include "gso_color.h"
#include "gso_char.h"
#include "gso_string.h"
#include "gso_file.h"
#include "gso_list.h"

class gso_container : public gso_var {
public:
    gso_vector_type<gso_var*> variables = {};
public:
    virtual void ReadData(gso_token token) override { 
        for (int i = 0; i < token.sub_tokens[2].sub_tokens.size(); i++) {
            gso_var* variable = nullptr;          
            gso_token_type token_type = token.sub_tokens[2].sub_tokens[i].sub_tokens[0].token_type;

            if (token_type == gso_token_type::gso_var_type_container_token)
                variable = new gso_container();
            if (token_type == gso_token_type::gso_var_type_number_token)
                variable = new gso_number();
            if (token_type == gso_token_type::gso_var_int_num1_token ||
                token_type == gso_token_type::gso_var_int_num2_token ||
                token_type == gso_token_type::gso_var_int_num3_token ||
                token_type == gso_token_type::gso_var_int_num4_token)
                variable = new gso_int();
            if (token_type == gso_token_type::gso_var_float_num1_token ||
                token_type == gso_token_type::gso_var_float_num2_token ||
                token_type == gso_token_type::gso_var_float_num3_token ||
                token_type == gso_token_type::gso_var_float_num4_token)
                variable = new gso_float();
            if (token_type == gso_token_type::gso_var_double_num1_token ||
                token_type == gso_token_type::gso_var_double_num2_token ||
                token_type == gso_token_type::gso_var_double_num3_token ||
                token_type == gso_token_type::gso_var_double_num4_token)
                variable = new gso_double();
            if (token_type ==  gso_token_type::gso_var_type_color_token)
                variable = new gso_color();
            if (token_type ==  gso_token_type::gso_var_type_char_token)
                variable = new gso_char();
            if (token_type == gso_token_type::gso_var_type_string_token)
                variable = new gso_string();
            if (token_type == gso_token_type::gso_var_type_file_token)
                variable = new gso_file();
            if (token_type == gso_token_type::gso_var_type_list_token)
                variable = new gso_list();

            variable->Read(token.sub_tokens[2].get_subtoken(i));
            variables.add(variable);
        }
    }
    virtual gso_token WriteData() override { return gso_token(); }
};