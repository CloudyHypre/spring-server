#ifndef BLACKJACK_H
#define BLACKJACK_H 1

#include <string.h>
#include <stdlib.h>
#include <time.h>

#define HAND_CARD_MAX  7
#define DECK_CARD_MAX  32
#define HAND_MAX       4
#define DECK_MAX       6
#define SEAT_MAX       7
#define TABLE_MAX      10

// Function prototypes
void blackjack_init(void);
void blackjack_shuffle_table(int);
int blackjack_deal_next_card_id(int);
int blackjack_get_table_id(int);
int blackjack_get_seat_id(int, int);
int blackjack_get_seat_socket(int, int);
int blackjack_get_seat_hand_card_id(int, int, int, int);
int blackjack_get_dealer_card_id(int, int);
void blackjack_set_seat_socket(int, int, int);
void blackjack_set_seat_hand_card_id(int, int, int, int, int);
void blackjack_set_table_dealer_card_id(int, int, int);

// Declare the entire blackjack game structure
struct card {
	int id;
	int highValue;
	int lowValue;
	char *display;
};

struct hand {
	int stay;
	struct card cards[HAND_CARD_MAX];
};

struct deck {
	struct card cards[DECK_CARD_MAX];
};

struct seat {
	int id;
	int socket;
	struct hand hands[HAND_MAX];
};

struct table {
	int id;
	int dealDeckIndex;
	int dealCardIndex;
	struct seat seats[SEAT_MAX];
	struct deck decks[DECK_MAX];
	struct card dealerhand[HAND_CARD_MAX];
};

struct blackjack {
	struct table tables[TABLE_MAX];
};

#endif
