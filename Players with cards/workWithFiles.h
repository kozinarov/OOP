#pragma once

#ifndef __workWithFiles_HEADER__
#define __workWithFiles_HEADER__

#include "Structors.h"
#include <iostream>
#include <fstream>
using namespace std;


void write_player(const player p)
{
	ofstream player_f("players.dat", ios::out | ios::app | ios::binary);
	if (!player_f.is_open()) { return; }

	player_f.write((char*)&p.name, sizeof(p.name));
	player_f.write((char*)&p.ID, sizeof(p.ID));

	player_f.close();
}

void write_card(const card c)
{
	ofstream card_f("cards.dat", ios::out | ios::app | ios::binary);
	if (!card_f.is_open()) { return; }

	card_f.write((char*)&c.name, sizeof(c.name));
	card_f.write((char*)&c.ID, sizeof(c.ID));
	card_f.write((char*)&c.colour, sizeof(c.colour));

	card_f.close();
}

void write_deck(const deck d)
{
	ofstream deck_f("decks.dat", ios::out | ios::app | ios::binary);
	if (!deck_f.is_open()) { return; }

	deck_f.write((char*)&d.player_ID, sizeof(d.player_ID));
	deck_f.write((char*)&d.colour, sizeof(d.colour));
	for (size_t i = 0; i < 60; ++i)
		deck_f.write((char*)&d.cards_ID[i], sizeof(d.cards_ID[i]));

	deck_f.close();
}

void write_report(const s_report *r, const size_t size, const char *card_name, const char *card_colour, const int *pointers)
{

	ofstream report_f("report.txt");
	if (!report_f.is_open())
	{
		return;
	}
	//here the pointers are not used to show me the the next spot for saving any colour
	//but to point the beginning of the next colour segment therefor i am not interested in hte last pointer

	report_f << "Red" << endl;
	for (size_t i = 0; i < size; ++i)
	{
		if (i == pointers[0])
			report_f << "Black" << endl;
		if (i == pointers[1])
			report_f << "Blue" << endl;
		if (i == pointers[2])
			report_f << "White" << endl;
		if (i == pointers[3])
			report_f << "Green" << endl;

		if (r[i].player_name != NULL)
			report_f << "    Owner: " << r[i].player_name << " Card: " << r[i].card_name << " Color: " << r[i].card_colour << endl;
	}

	report_f << "Most common card: " << card_name << " Color: " << card_colour << endl;

	report_f.close();


}

int write_num(const char *f_name)
{
	size_t num_structs = 0;
	int begin, end;

	fstream f_empty(f_name, ios::out | ios::app | ios::binary);

	if (!f_empty.is_open())
	{
		cout << "error opening file";
		return 0;
	}

	f_empty.seekg(0, ios::beg);
	begin = f_empty.tellg();
	f_empty.seekg(0, ios::end);
	end = f_empty.tellg();
	if (end - begin == 0)
	{
		f_empty.write((char*)&num_structs, sizeof(int));
	}
	f_empty.close();


	fstream f(f_name, ios::out | ios::in | ios::ate | ios::binary);

	if (!f.is_open())
	{
		cout << "error opening file";
		return 0;
	}

	f.seekg(0, ios::beg);
	f.read((char*)&num_structs, sizeof(int));

	f.seekp(0, ios::beg);
	num_structs++;

	f.write((char*)&num_structs, sizeof(int));
	f.seekg(0, ios::end);

	f.close();

	return num_structs;
}

player* read_players(size_t &num_players)
{
	player* ps;
	ifstream player_f("players.dat", ios::in | ios::binary);
	if (!player_f.is_open()) { return 0; }
	player_f.read((char*)&num_players, sizeof(num_players));

	ps = new player[num_players];

	for (size_t i = 0; i < num_players; ++i)
	{
		player_f.read((char*)&ps[i].name, sizeof(ps[i].name));
		player_f.read((char*)&ps[i].ID, sizeof(ps[i].ID));

	}

	player_f.close();
	return ps;
}

card* read_cards(size_t &num_cards)
{
	card* cs;
	ifstream card_f("cards.dat", ios::in | ios::binary);
	if (!card_f.is_open()) { return 0; }
	card_f.read((char*)&num_cards, sizeof(num_cards));

	cs = new card[num_cards];

	for (size_t i = 0; i < num_cards; ++i)
	{
		card_f.read((char*)&cs[i].name, sizeof(cs[i].name));
		card_f.read((char*)&cs[i].ID, sizeof(cs[i].ID));
		card_f.read((char*)&cs[i].colour, sizeof(cs[i].colour));

	}

	card_f.close();
	return cs;
}

deck* read_decks(size_t &num_decks, unsigned int *&all_cards_IDs)
{
	deck* ds;
	int cnt = 0;

	ifstream deck_f("decks.dat", ios::in | ios::binary);
	if (!deck_f.is_open()) { return 0; }
	deck_f.read((char*)&num_decks, sizeof(num_decks));

	ds = new deck[num_decks];
	all_cards_IDs = new unsigned int[num_decks * 60];

	for (size_t i = 0; i < num_decks; ++i)
	{
		deck_f.read((char*)&ds[i].player_ID, sizeof(ds[i].player_ID));
		deck_f.read((char*)&ds[i].colour, sizeof(ds[i].colour));
		for (size_t j = 0; j < 60; ++j)
		{
			deck_f.read((char*)&ds[i].cards_ID[j], sizeof(ds[i].cards_ID[j]));
			all_cards_IDs[cnt] = ds[i].cards_ID[j];
			cnt++;
		}
	}
	deck_f.close();
	return ds;
}

#endif //__workWithFile_HEADER__