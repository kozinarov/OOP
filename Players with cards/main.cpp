
#include "stdafx.h"
#include "helpers.h"


void create_player()
{
	player p;
	size_t num_players = 0;

	cin.getline(p.name, p_name_size);

	player *ps;
	ps = read_players(num_players);
	for (size_t i = 0; i < num_players; ++i)
	{
		if (strcmp(ps[i].name, p.name) == 0)
		{
			cout << "There is a player with this name" << endl;
			return;
		}
	}
	delete[] ps;

	num_players = write_num("players.dat");
	if (num_players > 32768)
	{
		cout << "the number of players is bigger than 2^15" << endl;
		return;
	}
	p.ID = num_players;

	write_player(p);
}


void create_card()
{
	card c;
	size_t num_cards = 0;
	char line[256];

	cin.getline(line, 256);

	char *left;
	char *right;
	left = strtok_s(line, " ", &right);

	strncpy_s(c.name, right, 63);

	card *cs;
	cs = read_cards(num_cards);
	for (size_t i = 0; i < num_cards; ++i)
	{
		if (strcmp(cs[i].name, c.name) == 0)
		{
			cout << "There is a card with this name" << endl;
			return;
		}
	}
	delete[] cs;

	num_cards = write_num("cards.dat");
	if (num_cards > 32768)
	{
		cout << "the number of cards is bigger than 2^15" << endl;
		return;
	}
	c.ID = num_cards;

	strcpy_s(c.colour, 6, left);
	is_valid_colour(c.colour);

	write_card(c);

}


void create_deck()
{
	deck d;
	player *ps;
	card *cs;
	size_t num_players = 0;
	size_t num_cards = 0;
	char player_name[p_name_size];
	char cards_names[60][c_name_size];
	char cards_colours[60][6];

	cin.getline(player_name, p_name_size);

	ps = read_players(num_players);
	is_valid_player_name(player_name, ps, num_players, d.player_ID);
	delete[] ps;

	cs = read_cards(num_cards);
	for (size_t i = 0; i < 60; ++i)
	{
		cin.getline(cards_names[i], c_name_size);
		is_valid_card_name(cards_names[i], cs, num_cards, d.cards_ID[i], cards_colours[i]);
	}
	delete[] cs;

	get_deck_colour(cards_colours, d.colour);

	size_t num_decks = 0;
	num_decks = write_num("decks.dat");
	write_deck(d);
}

void report()
{
	player *ps;
	card *cs;
	deck *ds;
	s_report *r;
	size_t num_players = 0;
	size_t num_cards = 0;
	size_t num_decks = 0;
	unsigned int *all_cards_IDs;
	unsigned int most_common_card_ID = 0;
	char most_common_card_name[c_name_size] = { NULL };
	char most_common_card_colour[6] = { NULL };
	//point the position of the colours in the array
	int pointers[5] = { 0, 1, 2, 3, 4 };

	ps = read_players(num_players);
	cs = read_cards(num_cards);
	ds = read_decks(num_decks, all_cards_IDs);

	//num_decks + 5 because there may not be a deck from any color and there will be a free spot
	//therefore in the beginning they are NULL just that i can make a check while recording in the file just that i dont add empty row
	r = new s_report[num_decks + 5];

	for (size_t i = 0; i < num_decks + 5; ++i)
	{
		r[i].player_name = NULL;
		r[i].card_name = NULL;
		r[i].card_colour = NULL;
	}
	for (size_t i = 0; i < num_decks; ++i)
	{

		int idx = deck_colour_to_idx(ds[i].colour);
		if (r[pointers[idx]].player_name == NULL)
		{

			fill(r[pointers[idx]], ps, num_players, cs, num_cards, ds[i]);

			if (pointers[idx] == pointers[idx + 1])
				for (size_t j = idx; j < 5; ++j)
					pointers[j]++;
			else
				pointers[idx]++;
		}
		else
		{
			//starts backwards from the penultimate position num_decks + 5 - 1 - 1 
			//num_decks + 5 the array size, -1 because the array starts from 0, -1 because i want to strart from the penultimate
			for (int j = num_decks + 5 - 1 - 1; j >= pointers[idx]; --j)
				r[j + 1] = r[j];

			//the position pointers[ind] is now free for adding
			fill(r[pointers[idx]], ps, num_players, cs, num_cards, ds[i]);


			//change the pointers
			for (size_t j = idx; j < 5; ++j)
				pointers[j]++;

		}
	}

	most_common_card(all_cards_IDs, most_common_card_ID, num_decks * 60);

	for (size_t i = 0; i < num_cards; ++i)
	{
		if (cs[i].ID == most_common_card_ID)
		{
			strcpy_s(most_common_card_name, c_name_size, cs[i].name);
			strcpy_s(most_common_card_colour, 6, cs[i].colour);
		}
	}


	write_report(r, num_decks + 5, most_common_card_name, most_common_card_colour, pointers);

	if (ds != NULL)
	{
		delete[] ps;
		delete[] cs;
		delete[] ds;
		delete[] all_cards_IDs;
		for (size_t i = 0; i < num_decks; ++i)
		{
			delete[] r[i].player_name;
			delete[] r[i].card_name;
			delete[] r[i].card_colour;
		}
		delete[] r;
	}

}

int main()
{
	char command[256];

	while (true)
	{
		cin.getline(command, 256);

		if (strcmp(command, "cp") == 0)
		{
			create_player();
		}
		else if (strcmp(command, "cc") == 0)
		{
			create_card();
		}
		else if (strcmp(command, "cd") == 0)
		{
			create_deck();
		}
		else if (strcmp(command, "report") == 0)
		{
			report();
		}
		else
		{
			cout << "exit" << endl;
			break;
		}
	}


	return 0;
}