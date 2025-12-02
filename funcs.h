#ifndef FUNCS_H
#define FUNCS_H

void scientific_menu(void);
void eee_menu(void);

int get_user_input_sub(int max_items);

//for scientific tool functions//
void unit_conversion(void);

float hzToRad(float hz);
float radToHz(float rad);
float dbmToMw(float dbm);
float mwToDbm(float mw);

void basic_statistics(void);

void eee_menu(void);
void rc_filter_tool(void);
void resistor_network_tool(void);


#endif