//
// Created by Fgran on 11/09/2023.
//

#include "config.h"
#include "lookup.h"
#include "bitboard.h"
int main(){
    initLookupTables();

    U64 bitBoard = 0ULL;
    printBitBoard(bitBoard);

    bitBoard |= (1ULL << lookupTable120To64[A2]);
    printBitBoard(bitBoard);

    bitBoard |= (1ULL << lookupTable120To64[H8]);
    printBitBoard(bitBoard);


    return 0;
}