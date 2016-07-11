#pragma once
#ifndef __helpers_HEADER__
#define __helpers_HEADER__


#include "workWithFiles.h"


void is_valid_colour(const char* colour)
{
	if (strcmp(colour, "Red") != 0 && strcmp(colour, "Black") != 0 && strcmp(colour, "Blue") != 0 && strcmp(colour, "White") != 0 && strcmp(colour, "Green") != 0)
	{
		throw "the colour us wrong";
	}
}


void is_valid_player_name(const char* name, const player* ps, const size_t num_players, unsigned int &player_ID)
{
	for (size_t i = 0; i < num_players; ++i)
	{
		if (strcmp(name, ps[i].name) == 0)
		{
			player_ID = ps[i].ID;
			return;
		}
	}

	throw "the player name is not in the data";
}

void is_valid_card_name(const char* name, const card* cs, const size_t num_cards, unsigned int &card_ID, char *card_colour)
{
	for (size_t i = 0; i < num_cards; ++i)
	{
		if (strcmp(name, cs[i].name) == 0)
		{
			card_ID = cs[i].ID;
			strcpy_s(card_colour, 6, cs[i].colour);
			return;
		}
	}

	cout << "the card name is not in the data";
	throw "the card name is not in the data";
}

void get_deck_colour(const char colours[][6], char *deck_colour)
{
	int arr[5] = { 0 };
	int	most_common_col = 0;
	int most_common_col_ind = 0;
	for (size_t i = 0; i < 60; ++i)
	{
		if (strcmp(colours[i], "Red") == 0)
			arr[0] += 1;
		if (strcmp(colours[i], "Black") == 0)
			arr[1] += 1;
		if (strcmp(colours[i], "Blue") == 0)
			arr[2] += 1;
		if (strcmp(colours[i], "White") == 0)
			arr[3] += 1;
		if (strcmp(colours[i], "Green") == 0)
			arr[4] += 1;
	}
	//to the number of the colours
	for (size_t i = 0; i < 5; ++i)
	{
		if (arr[i] > most_common_col)
		{
			most_common_col = arr[i];
			most_common_col_ind = i;
		}
	}

	if (most_common_col_ind == 0)
		strcpy_s(deck_colour, 6, "Red");
	if (most_common_col_ind == 1)
		strcpy_s(deck_colour, 6, "Black");
	if (most_common_col_ind == 2)
		strcpy_s(deck_colour, 6, "Blue");
	if (most_common_col_ind == 3)
		strcpy_s(deck_colour, 6, "White");
	if (most_common_col_ind == 4)
		strcpy_s(deck_colour, 6, "Green");

}

void swap(unsigned int& a, unsigned int& b)
{
	if (b < a)
	{
		int temp = a;
		a = b;
		b = temp;
	}
}
void bubbleSort(unsigned int* pArr, size_t size)
{
	if (!pArr || size == 0)
		return;

	for (size_t i = 0; i < size - 1; ++i)
	{
		for (size_t j = size - 1; j > i; --j)
		{
			swap(pArr[j - 1], pArr[j]);
		}
	}
}
void most_common_card(unsigned int *all_cards_IDs, unsigned int &card, size_t Size)
{
	bubbleSort(all_cards_IDs, Size);

	int cnt = 0;
	int longest = 0;
	for (size_t i = 0; i < Size; ++i)
	{
		if (i < Size && all_cards_IDs[i] == all_cards_IDs[i + 1])
		{
			cnt++;
		}
		else
		{
			cnt++;
			if (cnt > longest)
			{
				longest = cnt;
				card = all_cards_IDs[i - 1];
				if (i - 1 < 0)
				{
					card = all_cards_IDs[0];
				}

				cnt = 0;
			}
			cnt = 0;
		}
	}
}

int deck_colour_to_idx(const char * colour)
{
	if (strcmp(colour, "Red") == 0)
		return 0;
	if (strcmp(colour, "Black") == 0)
		return 1;
	if (strcmp(colour, "Blue") == 0)
		return 2;
	if (strcmp(colour, "White") == 0)
		return 3;
	if (strcmp(colour, "Green") == 0)
		return 4;
}

void fill(s_report &r, const player *ps, const size_t num_players, const card *cs, const size_t num_cards, const deck d)
{
	for (size_t i = 0; i < num_players; ++i)
	{
		if (ps[i].ID == d.player_ID)
		{
			r.player_name = new char[p_name_size];
			strcpy_s(r.player_name, p_name_size, ps[i].name);
		}
	}

	for (size_t i = 0; i < num_cards; ++i)
	{
		if (cs[i].ID == d.cards_ID[0])
		{
			r.card_name = new char[c_name_size];
			r.card_colour = new char[6];
			strcpy_s(r.card_name, c_name_size, cs[i].name);
			strcpy_s(r.card_colour, 6, cs[i].colour);
		}
	}
}


#endif //__helpers_HEADER__