#pragma once
#ifndef BLUEMABLE_H
#define BLUEMARBLE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0

extern int player_x;
extern int player_y;
extern int player_complete;

extern int computer_x;
extern int computer_y;
extern int computer_complete;

extern int player_turn;

extern int strength;

extern int dice;

void print_status(int, int, int, int, int, int);
void print_menu();
void get_dice_face();
void move();
#endif
