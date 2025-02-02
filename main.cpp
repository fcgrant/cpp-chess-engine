//
// Created by Fgran on 11/09/2023.
//

#include "config.h"
#include "lookup.h"
#include "bitboard.h"
#include "init.h"

int main(){
    initLookupTables();
    BOARD_STRUCTURE boardStructure = initStartingStructure();
    return 0;
}