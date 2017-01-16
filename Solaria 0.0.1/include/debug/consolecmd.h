#ifndef CONSOLECMD_H
#define CONSOLECMD_H

#include <string>
#include <vector>
#include <cstdbool>

#include "ship.h"
#include "uni.h"

using namespace std;

bool consolecmd(uni *universal, int playerid, string input, double dtime);

#endif // CONSOLECMD_H
