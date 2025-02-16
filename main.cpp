//
// Created by Fgran on 11/09/2023.
//

#include "config.h"
#include "lookup.h"
#include "bitboard.h"
#include "init.h"
#include "move.h"
#include <iostream>
#include <vector>

int main(){
    initLookupTables();
    BOARD_STRUCTURE boardStructure = initStartingStructure();
    std::vector<std::vector<int>> moves = getMoves(boardStructure);
    return 0;
}