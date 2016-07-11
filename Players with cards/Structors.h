#pragma once
#ifndef __Structors_HEADER__
#define __Structors_HEADER__

const size_t p_name_size = 128;
const size_t c_name_size = 64;


struct player
{
	char name[p_name_size];
	unsigned int ID;
};

struct card
{
	char name[c_name_size];
	unsigned int ID;
	char colour[6];

};

struct deck
{
	unsigned int player_ID;
	char colour[6];
	unsigned int cards_ID[60];
};

struct s_report
{
	char *player_name;
	char *card_name;
	char *card_colour;
};

#endif //__Structors_HEADER__