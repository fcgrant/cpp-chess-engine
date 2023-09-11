//
// Created by Fgran on 11/09/2023.
//

#ifndef CPP_CHESS_ENGINE_CONFIG_H
#define CPP_CHESS_ENGINE_CONFIG_H

typedef unsigned long long U64;

// Upper case represents white pieces, lower case represents black pieces
enum {EMPTY, K, Q, R, N, B, P, k, q, r, n, b, p};
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE};
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE};

#endif //CPP_CHESS_ENGINE_CONFIG_H