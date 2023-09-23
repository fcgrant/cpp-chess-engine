//
// Created by Fgran on 23/09/2023.
//

#ifndef CPP_CHESS_ENGINE_LOOKUP_H
#define CPP_CHESS_ENGINE_LOOKUP_H
void initLookupTables();

void displayLookupTables();

// Used to determine the index of a position when querying the board array
extern int lookupTable64To120[64];

// Used to determine the index of a position when querying a 64-bit integer
extern int lookupTable120To64[BOARD_ARRAY_SIZE];
#endif //CPP_CHESS_ENGINE_LOOKUP_H
