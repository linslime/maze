#pragma once
#include "space.h"
#include "SqStack.h"

MoveType move[4] = { {-1,0} ,{0,-1},{1,0}, {0,1} };

int k = 0;
int roadnum = 0;
int shortroad = 100000;
SqStack minroute;
