// Stockfish 1.0 -- single-file amalgamation (GPLv3, see original Copying.txt)

// ======== benchmark.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////
#include <fstream>
#include <sstream>
#include <vector>

// ---- begin benchmark.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(BENCHMARK_H_INCLUDED)
#define BENCHMARK_H_INCLUDED

////
//// Includes
////

#include <string>


////
//// Prototypes
////

extern void benchmark(const std::string& commandLine);

#endif // !defined(BENCHMARK_H_INCLUDED)
// ---- end benchmark.h ----
// ---- begin search.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(SEARCH_H_INCLUDED)
#define SEARCH_H_INCLUDED

////
//// Includes
////

// ---- begin types.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(TYPES_H_INCLUDED)
#define TYPES_H_INCLUDED

#if !defined(_MSC_VER)

#include <inttypes.h>

#else

typedef __int8 int8_t;
typedef unsigned __int8 uint8_t;
typedef __int16 int16;
typedef unsigned __int16 uint16_t;
typedef __int32 int32;
typedef unsigned __int32 uint32_t;
typedef __int64 int64;
typedef unsigned __int64 uint64_t;

typedef __int16 int16_t;
typedef __int64 int64_t;

#endif // !defined(_MSC_VER)

// Hash keys:
typedef uint64_t Key;

#endif // !defined(TYPES_H_INCLUDED)
// ---- end types.h ----
// ---- begin depth.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(DEPTH_H_INCLUDED)
#define DEPTH_H_INCLUDED

////
//// Types
////

enum Depth {
  DEPTH_ZERO = 0,
  DEPTH_MAX = 200  // 100 * OnePly;
};


////
//// Constants
////

/// Note: If OnePly is changed, the constant HistoryMax in history.h should
/// probably also be changed.

const Depth OnePly = Depth(2);


////
//// Inline functions
////

inline Depth operator+ (Depth d, int i) { return Depth(int(d) + i); }
inline Depth operator+ (Depth d1, Depth d2) { return Depth(int(d1) + int(d2)); }
inline void operator+= (Depth &d, int i) { d = Depth(int(d) + i); }
inline void operator+= (Depth &d1, Depth d2) { d1 += int(d2); }
inline Depth operator- (Depth d, int i) { return Depth(int(d) - i); }
inline Depth operator- (Depth d1, Depth d2) { return Depth(int(d1) - int(d2)); }
inline void operator-= (Depth & d, int i) { d = Depth(int(d) - i); }
inline Depth operator* (Depth d, int i) { return Depth(int(d) * i); }
inline Depth operator* (int i, Depth d) { return Depth(int(d) * i); }
inline void operator*= (Depth &d, int i) { d = Depth(int(d) * i); }
inline Depth operator/ (Depth d, int i) { return Depth(int(d) / i); }
inline void operator/= (Depth &d, int i) { d = Depth(int(d) / i); }


#endif // !defined(DEPTH_H_INCLUDED)
// ---- end depth.h ----
// ---- begin history.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(HISTORY_H_INCLUDED)
#define HISTORY_H_INCLUDED

////
//// Includes
////

// ---- begin move.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(MOVE_H_INCLUDED)
#define MOVE_H_INCLUDED

////
//// Includes
////

#include <iostream>

// ---- begin misc.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(MISC_H_INCLUDED)
#define MISC_H_INCLUDED


////
//// Includes
////

#include <string>


////
//// Constants
////


/// Version number.  If this is left empty, the current date (in the format
/// YYMMDD) is used as a version number.

const std::string EngineVersion = "1.0";


////
//// Macros
////

#define Min(x, y) (((x) < (y))? (x) : (y))
#define Max(x, y) (((x) < (y))? (y) : (x))


////
//// Prototypes
////

extern const std::string engine_name();
extern int get_system_time();
extern int cpu_count();
extern int Bioskey();

////
//// Debug
////
extern long dbg_cnt0;
extern long dbg_cnt1;

inline void dbg_hit_on(bool b) { dbg_cnt0++; if (b) dbg_cnt1++; }
inline void dbg_hit_on_c(bool c, bool b) { if (c) dbg_hit_on(b); }

inline void dbg_before() { dbg_cnt0++; }
inline void dbg_after() { dbg_cnt1++; }

inline void dbg_mean_of(int v) { dbg_cnt0++; dbg_cnt1 += v; }

extern void dbg_print_hit_rate();
extern void dbg_print_mean();

extern bool dbg_show_mean;
extern bool dbg_show_hit_rate;

#endif // !defined(MISC_H_INCLUDED)
// ---- end misc.h ----
// ---- begin piece.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(PIECE_H_INCLUDED)
#define PIECE_H_INCLUDED

//// 
//// Includes
////

// ---- begin color.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(COLOR_H_INCLUDED)
#define COLOR_H_INCLUDED

////
//// Includes
////



////
//// Types
////

enum Color {
  WHITE, 
  BLACK, 
  COLOR_NONE
};


////
//// Inline functions
////

inline Color operator+ (Color c, int i) { return Color(int(c) + i); }
inline void operator++ (Color &c, int i) { c = Color(int(c) + 1); }

inline Color opposite_color(Color c) {
  return Color(int(c) ^ 1);
}


////
//// Prototypes
////

extern bool color_is_ok(Color c);


#endif // !defined(COLOR_H_INCLUDED)
// ---- end color.h ----
// ---- begin square.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(SQUARE_H_INCLUDED)
#define SQUARE_H_INCLUDED

////
//// Includes
////

#include <string>



////
//// Types
////

enum Square {
  SQ_A1, SQ_B1, SQ_C1, SQ_D1, SQ_E1, SQ_F1, SQ_G1, SQ_H1,
  SQ_A2, SQ_B2, SQ_C2, SQ_D2, SQ_E2, SQ_F2, SQ_G2, SQ_H2,
  SQ_A3, SQ_B3, SQ_C3, SQ_D3, SQ_E3, SQ_F3, SQ_G3, SQ_H3,
  SQ_A4, SQ_B4, SQ_C4, SQ_D4, SQ_E4, SQ_F4, SQ_G4, SQ_H4,
  SQ_A5, SQ_B5, SQ_C5, SQ_D5, SQ_E5, SQ_F5, SQ_G5, SQ_H5,
  SQ_A6, SQ_B6, SQ_C6, SQ_D6, SQ_E6, SQ_F6, SQ_G6, SQ_H6,
  SQ_A7, SQ_B7, SQ_C7, SQ_D7, SQ_E7, SQ_F7, SQ_G7, SQ_H7,
  SQ_A8, SQ_B8, SQ_C8, SQ_D8, SQ_E8, SQ_F8, SQ_G8, SQ_H8,
  SQ_NONE
}; 

enum File {
  FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE
};

enum Rank {
  RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE
};

enum SquareDelta {
  DELTA_SSW = -021, DELTA_SS = -020, DELTA_SSE = -017, DELTA_SWW = -012,
  DELTA_SW = -011, DELTA_S = -010, DELTA_SE = -07, DELTA_SEE = -06,
  DELTA_W = -01, DELTA_ZERO = 0, DELTA_E = 01, DELTA_NWW = 06, DELTA_NW = 07,
  DELTA_N = 010, DELTA_NE = 011, DELTA_NEE = 012, DELTA_NNW = 017,
  DELTA_NN = 020, DELTA_NNE = 021
};


////
//// Constants
////

const int FlipMask = 070;
const int FlopMask = 07;


//// 
//// Inline functions
////

inline File operator+ (File x, int i) { return File(int(x) + i); }
inline File operator+ (File x, File y) { return x + int(y); }
inline void operator++ (File &x, int) { x = File(int(x) + 1); }
inline void operator+= (File &x, int i) { x = File(int(x) + i); }
inline File operator- (File x, int i) { return File(int(x) - i); }
inline void operator-- (File &x, int) { x = File(int(x) - 1); }
inline void operator-= (File &x, int i) { x = File(int(x) - i); }

inline Rank operator+ (Rank x, int i) { return Rank(int(x) + i); }
inline Rank operator+ (Rank x, Rank y) { return x + int(y); }
inline void operator++ (Rank &x, int) { x = Rank(int(x) + 1); }
inline void operator+= (Rank &x, int i) { x = Rank(int(x) + i); }
inline Rank operator- (Rank x, int i) { return Rank(int(x) - i); }
inline void operator-- (Rank &x, int) { x = Rank(int(x) - 1); }
inline void operator-= (Rank &x, int i) { x = Rank(int(x) - i); }

inline Square operator+ (Square x, int i) { return Square(int(x) + i); }
inline void operator++ (Square &x, int) { x = Square(int(x) + 1); }
inline void operator+= (Square &x, int i) { x = Square(int(x) + i); }
inline Square operator- (Square x, int i) { return Square(int(x) - i); }
inline void operator-- (Square &x, int) { x = Square(int(x) - 1); }
inline void operator-= (Square &x, int i) { x = Square(int(x) - i); }
inline Square operator+ (Square x, SquareDelta i) { return Square(int(x) + i); }
inline void operator+= (Square &x, SquareDelta i) { x = Square(int(x) + i); }
inline Square operator- (Square x, SquareDelta i) { return Square(int(x) - i); }
inline void operator-= (Square &x, SquareDelta i) { x = Square(int(x) - i); }
inline SquareDelta operator- (Square x, Square y) {
  return SquareDelta(int(x) - int(y));
}

inline Square make_square(File f, Rank r) {
  return Square(int(f) | (int(r) << 3));
}

inline File square_file(Square s) {
  return File(int(s) & 7);
}

inline Rank square_rank(Square s) {
  return Rank(int(s) >> 3);
}

inline Square flip_square(Square s) {
  return Square(int(s) ^ FlipMask);
}

inline Square flop_square(Square s) {
  return Square(int(s) ^ FlopMask);
}

inline Square relative_square(Color c, Square s) {
  return Square(int(s) ^ (int(c) * FlipMask));
}

inline Rank relative_rank(Color c, Square s) {
  return square_rank(relative_square(c, s));
}

inline Color square_color(Square s) {
  return Color((int(square_file(s)) + int(square_rank(s))) & 1);
}

inline int file_distance(File f1, File f2) {
  return abs(int(f1) - int(f2));
}

inline int file_distance(Square s1, Square s2) {
  return file_distance(square_file(s1), square_file(s2));
}

inline int rank_distance(Rank r1, Rank r2) {
  return abs(int(r1) - int(r2));
}

inline int rank_distance(Square s1, Square s2) {
  return rank_distance(square_rank(s1), square_rank(s2));
}

inline int square_distance(Square s1, Square s2) {
  return Max(file_distance(s1, s2), rank_distance(s1, s2));
}


//// 
//// Prototypes
////

extern File file_from_char(char c);
extern char file_to_char(File f);
extern Rank rank_from_char(char c);
extern char rank_to_char(Rank r);
extern Square square_from_string(const std::string &str);
extern const std::string square_to_string(Square s);

extern bool file_is_ok(File f);
extern bool rank_is_ok(Rank r);
extern bool square_is_ok(Square s);


#endif // !defined(SQUARE_H_INCLUDED)
// ---- end square.h ----


//// 
//// Types
////

enum PieceType {
  NO_PIECE_TYPE = 0,
  PAWN = 1, KNIGHT = 2, BISHOP = 3, ROOK = 4, QUEEN = 5, KING = 6
};

enum Piece {
  NO_PIECE = 0, WP = 1, WN = 2, WB = 3, WR = 4, WQ = 5, WK = 6,
  BP = 9, BN = 10, BB = 11, BR = 12, BQ = 13, BK = 14,
  EMPTY = 16, OUTSIDE = 17
};


////
//// Constants and variables
////

const PieceType PieceTypeMin = PAWN;
const PieceType PieceTypeMax = KING;

extern const int SlidingArray[18];
extern const SquareDelta Directions[16][16];   
extern const SquareDelta PawnPush[2];


//// 
//// Inline functions
////

inline Piece operator+ (Piece p, int i) { return Piece(int(p) + i); }
inline void operator++ (Piece &p, int) { p = Piece(int(p) + 1); }
inline Piece operator- (Piece p, int i) { return Piece(int(p) - i); }
inline void operator-- (Piece &p, int) { p = Piece(int(p) - 1); }
inline PieceType operator+ (PieceType p, int i) {return PieceType(int(p) + i);}
inline void operator++ (PieceType &p, int) { p = PieceType(int(p) + 1); }
inline PieceType operator- (PieceType p, int i) {return PieceType(int(p) - i);}
inline void operator-- (PieceType &p, int) { p = PieceType(int(p) - 1); }

inline PieceType type_of_piece(Piece p)  {
  return PieceType(int(p) & 7);
}

inline Color color_of_piece(Piece p) {
  return Color(int(p) >> 3);
}

inline Piece piece_of_color_and_type(Color c, PieceType pt) {
  return Piece((int(c) << 3) | int(pt));
}

inline Piece pawn_of_color(Color c) {
  return piece_of_color_and_type(c, PAWN);
}

inline Piece knight_of_color(Color c) {
  return piece_of_color_and_type(c, KNIGHT);
}

inline Piece bishop_of_color(Color c) {
  return piece_of_color_and_type(c, BISHOP);
}

inline Piece rook_of_color(Color c) {
  return piece_of_color_and_type(c, ROOK);
}

inline Piece queen_of_color(Color c) {
  return piece_of_color_and_type(c, QUEEN);
}

inline Piece king_of_color(Color c) {
  return piece_of_color_and_type(c, KING);
}

inline int piece_is_slider(Piece p) {
  return SlidingArray[int(p)];
}

inline int piece_type_is_slider(PieceType pt) {
  return SlidingArray[int(pt)];
}

inline SquareDelta pawn_push(Color c) {
  return PawnPush[c];
}
  

////
//// Prototypes
////

extern char piece_type_to_char(PieceType pt, bool upcase);
extern PieceType piece_type_from_char(char c);
extern bool piece_is_ok(Piece pc);
extern bool piece_type_is_ok(PieceType pt);


#endif // !defined(PIECE_H_INCLUDED)
// ---- end piece.h ----


////
//// Types
////

class Position;

enum Move {
  MOVE_NONE = 0,
  MOVE_NULL = 65, 
  MOVE_MAX = 0xFFFFFF
};


struct MoveStack {
  Move move;
  int score;
};


////
//// Inline functions
////

inline Square move_from(Move m) {
  return Square((int(m) >> 6) & 077);
}

inline Square move_to(Move m) {
  return Square(m & 077);
}

inline PieceType move_promotion(Move m) {
  return PieceType((int(m) >> 12) & 7);
}

inline bool move_is_ep(Move m) {
  return bool((int(m) >> 15) & 1);
}

inline bool move_is_castle(Move m) {
  return bool((int(m) >> 16) & 1);
}

inline bool move_is_short_castle(Move m) {
  return move_is_castle(m) && (move_to(m) > move_from(m));
}

inline bool move_is_long_castle(Move m) {
  return move_is_castle(m) && (move_to(m) < move_from(m));
}

inline Move make_promotion_move(Square from, Square to, PieceType promotion) {
  return Move(int(to) | (int(from) << 6) | (int(promotion) << 12));
}

inline Move make_move(Square from, Square to) {
  return Move(int(to) | (int(from) << 6));
}

inline Move make_castle_move(Square from, Square to) {
  return Move(int(to) | (int(from) << 6) | (1 << 16));
}

inline Move make_ep_move(Square from, Square to) {
  return Move(int(to) | (int(from) << 6) | (1 << 15));
}


////
//// Prototypes
////

extern std::ostream &operator << (std::ostream &os, Move m);
extern Move move_from_string(const Position &pos, const std::string &str);
extern const std::string move_to_string(Move m);
extern bool move_is_ok(Move m);


#endif // !defined(MOVE_H_INCLUDED)
// ---- end move.h ----


////
//// Types
////

/// The History class stores statistics about how often different moves have
/// been successful or unsuccessful during the current search.  These
/// statistics are used for reduction and move ordering decisions.

class History {

public:
  History();
  void clear();
  void success(Piece p, Move m, Depth d);
  void failure(Piece p, Move m);
  int move_ordering_score(Piece p, Move m) const;
  bool ok_to_prune(Piece p, Move m, Depth d) const;

private:
  int history[16][64];  // [piece][square]
  int successCount[16][64];
  int failureCount[16][64];
};


////
//// Constants and variables
////

/// HistoryMax controls how often the history counters will be scaled down:
/// When the history score for a move gets bigger than HistoryMax, all
/// entries in the table are divided by 2.  It is difficult to guess what
/// the ideal value of this constant is.  Scaling down the scores often has
/// the effect that parts of the search tree which have been searched
/// recently have a bigger importance for move ordering than the moves which
/// have been searched a long time ago.
///
/// Note that HistoryMax should probably be changed whenever the constant
/// OnePly in depth.h is changed.  This is somewhat annoying.  Perhaps it
/// would be better to scale down the history table at regular intervals?

const int HistoryMax = 50000;


#endif // !defined(HISTORY_H_INCLUDED)
// ---- end history.h ----
// ---- begin lock.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(LOCK_H_INCLUDED)
#define LOCK_H_INCLUDED


// x86 assembly language locks or OS spin locks may perform faster than
// mutex locks on some platforms.  On my machine, mutexes seem to be the
// best.

//#define ASM_LOCK
//#define OS_SPIN_LOCK


#if defined(ASM_LOCK)


typedef volatile int Lock;

static inline void LockX86(Lock *lock) {
  int dummy;
  asm __volatile__("1:          movl    $1, %0" "\n\t"
      "            xchgl   (%1), %0" "\n\t" "            testl   %0, %0" "\n\t"
      "            jz      3f" "\n\t" "2:          pause" "\n\t"
      "            movl    (%1), %0" "\n\t" "            testl   %0, %0" "\n\t"
      "            jnz     2b" "\n\t" "            jmp     1b" "\n\t" "3:"
      "\n\t":"=&q"(dummy)
      :"q"(lock)
      :"cc");
}

static inline void UnlockX86(Lock *lock) {
  int dummy;
  asm __volatile__("movl    $0, (%1)":"=&q"(dummy)
      :"q"(lock));
}

#  define lock_init(x, y) (*(x) = 0)
#  define lock_grab(x) LockX86(x)
#  define lock_release(x) UnlockX86(x)
#  define lock_destroy(x)


#elif defined(OS_SPIN_LOCK)


#  include <libkern/OSAtomic.h>

typedef OSSpinLock Lock;

#  define lock_init(x, y) (*(x) = 0)
#  define lock_grab(x) OSSpinLockLock(x)
#  define lock_release(x) OSSpinLockUnlock(x)
#  define lock_destroy(x)


#elif !defined(_MSC_VER)

#  include <pthread.h>

typedef pthread_mutex_t Lock;

#  define lock_init(x, y) pthread_mutex_init(x, y)
#  define lock_grab(x) pthread_mutex_lock(x)
#  define lock_release(x) pthread_mutex_unlock(x)
#  define lock_destroy(x) pthread_mutex_destroy(x)


#else


#  include <windows.h>

typedef CRITICAL_SECTION Lock;
#  define lock_init(x, y) InitializeCriticalSection(x)
#  define lock_grab(x) EnterCriticalSection(x)
#  define lock_release(x) LeaveCriticalSection(x)
#  define lock_destroy(x) DeleteCriticalSection(x)


#endif


#endif // !defined(LOCK_H_INCLUDED)
// ---- end lock.h ----
// ---- begin movegen.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(MOVEGEN_H_INCLUDED)
#define MOVEGEN_H_INCLUDED

////
//// Includes
////

// ---- begin position.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(POSITION_H_INCLUDED)
#define POSITION_H_INCLUDED

// Disable a silly and noisy warning from MSVC compiler
#if defined(_MSC_VER)

// Forcing value to bool 'true' or 'false' (performance warning)
#pragma warning(disable: 4800)

#endif

////
//// Includes
////

// ---- begin bitboard.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.


  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(BITBOARD_H_INCLUDED)
#define BITBOARD_H_INCLUDED


////
//// Defines
////

// Comment following define if you prefer manually adjust
// platform macros defined below
#define AUTO_CONFIGURATION

// Quiet a warning on Intel compiler
#if !defined(__SIZEOF_INT__ )
#define __SIZEOF_INT__ 0
#endif

// Check for 64 bits for different compilers: Intel, MSVC and gcc
#if defined(__x86_64) || defined(_WIN64) || (__SIZEOF_INT__ > 4)
#define IS_64BIT
#endif

#if !defined(AUTO_CONFIGURATION) || defined(IS_64BIT)

//#define USE_COMPACT_ROOK_ATTACKS
//#define USE_32BIT_ATTACKS
#define USE_FOLDED_BITSCAN

#define BITCOUNT_SWAR_64
//#define BITCOUNT_SWAR_32
//#define BITCOUNT_LOOP

#else

#define USE_32BIT_ATTACKS
#define USE_FOLDED_BITSCAN
#define BITCOUNT_SWAR_32

#endif

////
//// Includes
////

// ---- begin direction.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(DIRECTION_H_INCLUDED)
#define DIRECTION_H_INCLUDED

////
//// Includes
////



////
//// Types
////

enum Direction {
  DIR_E = 0, DIR_N = 1, DIR_NE = 2, DIR_NW = 3, DIR_NONE = 4
};

enum SignedDirection {
  SIGNED_DIR_E = 0, SIGNED_DIR_W = 1,
  SIGNED_DIR_N = 2, SIGNED_DIR_S = 3,
  SIGNED_DIR_NE = 4, SIGNED_DIR_SW = 5,
  SIGNED_DIR_NW = 6, SIGNED_DIR_SE = 7,
  SIGNED_DIR_NONE = 8
};


////
//// Variables
////

extern uint8_t DirectionTable[64][64];
extern uint8_t SignedDirectionTable[64][64];


////
//// Inline functions
////

inline void operator++ (Direction &d, int) { d = Direction(int(d) + 1); }

inline void operator++ (SignedDirection &d, int) {
  d = SignedDirection(int(d) + 1);
}

inline Direction direction_between_squares(Square s1, Square s2) {
  return Direction(DirectionTable[s1][s2]);
}

inline SignedDirection signed_direction_between_squares(Square s1, Square s2) {
  return SignedDirection(SignedDirectionTable[s1][s2]);
}


////
//// Prototypes
////

extern void init_direction_table();


#endif // !defined(DIRECTION_H_INCLUDED)
// ---- end direction.h ----


////
//// Types
////

typedef uint64_t Bitboard;


////
//// Constants and variables
////

const Bitboard EmptyBoardBB = 0ULL;

const Bitboard WhiteSquaresBB = 0x55AA55AA55AA55AAULL;
const Bitboard BlackSquaresBB = 0xAA55AA55AA55AA55ULL;

extern const Bitboard SquaresByColorBB[2];

const Bitboard FileABB = 0x0101010101010101ULL;
const Bitboard FileBBB = 0x0202020202020202ULL;
const Bitboard FileCBB = 0x0404040404040404ULL;
const Bitboard FileDBB = 0x0808080808080808ULL;
const Bitboard FileEBB = 0x1010101010101010ULL;
const Bitboard FileFBB = 0x2020202020202020ULL;
const Bitboard FileGBB = 0x4040404040404040ULL;
const Bitboard FileHBB = 0x8080808080808080ULL;

extern const Bitboard FileBB[8];
extern const Bitboard NeighboringFilesBB[8];
extern const Bitboard ThisAndNeighboringFilesBB[8];

const Bitboard Rank1BB = 0xFFULL;
const Bitboard Rank2BB = 0xFF00ULL;
const Bitboard Rank3BB = 0xFF0000ULL;
const Bitboard Rank4BB = 0xFF000000ULL;
const Bitboard Rank5BB = 0xFF00000000ULL;
const Bitboard Rank6BB = 0xFF0000000000ULL;
const Bitboard Rank7BB = 0xFF000000000000ULL;
const Bitboard Rank8BB = 0xFF00000000000000ULL;

extern const Bitboard RankBB[8];
extern const Bitboard RelativeRankBB[2][8];
extern const Bitboard InFrontBB[2][8];

extern Bitboard SetMaskBB[64];
extern Bitboard ClearMaskBB[64];

extern Bitboard StepAttackBB[16][64];
extern Bitboard RayBB[64][8];
extern Bitboard BetweenBB[64][64];

extern Bitboard PassedPawnMask[2][64];
extern Bitboard OutpostMask[2][64];

#if defined(USE_COMPACT_ROOK_ATTACKS)
extern Bitboard RankAttacks[8][64], FileAttacks[8][64];
#else
extern const uint64_t RMult[64];
extern const int RShift[64];
extern Bitboard RMask[64];
extern int RAttackIndex[64];
extern Bitboard RAttacks[0x19000];
#endif // defined(USE_COMPACT_ROOK_ATTACKS)

extern const uint64_t BMult[64];
extern const int BShift[64];
extern Bitboard BMask[64];
extern int BAttackIndex[64];
extern Bitboard BAttacks[0x1480];

extern Bitboard BishopPseudoAttacks[64];
extern Bitboard RookPseudoAttacks[64];
extern Bitboard QueenPseudoAttacks[64];


////
//// Inline functions
////

/// Functions for testing whether a given bit is set in a bitboard, and for
/// setting and clearing bits.

inline Bitboard bit_is_set(Bitboard b, Square s) {
  return b & SetMaskBB[s];
}

inline void set_bit(Bitboard *b, Square s) {
  *b |= SetMaskBB[s];
}

inline void clear_bit(Bitboard *b, Square s) {
  *b &= ClearMaskBB[s];
}


/// rank_bb() and file_bb() gives a bitboard containing all squares on a given
/// file or rank.  It is also possible to pass a square as input to these
/// functions.

inline Bitboard rank_bb(Rank r) {
  return RankBB[r];
}

inline Bitboard rank_bb(Square s) {
  return rank_bb(square_rank(s));
}

inline Bitboard file_bb(File f) {
  return FileBB[f];
}

inline Bitboard file_bb(Square s) {
  return file_bb(square_file(s));
}


/// neighboring_files_bb takes a file or a square as input, and returns a
/// bitboard representing all squares on the neighboring files.

inline Bitboard neighboring_files_bb(File f) {
  return NeighboringFilesBB[f];
}

inline Bitboard neighboring_files_bb(Square s) {
  return neighboring_files_bb(square_file(s));
}


/// this_and_neighboring_files_bb takes a file or a square as input, and
/// returns a bitboard representing all squares on the given and neighboring
/// files.

inline Bitboard this_and_neighboring_files_bb(File f) {
  return ThisAndNeighboringFilesBB[f];
}

inline Bitboard this_and_neighboring_files_bb(Square s) {
  return this_and_neighboring_files_bb(square_file(s));
}


/// relative_rank_bb() takes a color and a rank as input, and returns a bitboard
/// representing all squares on the given rank from the given color's point of
/// view.  For instance, relative_rank_bb(WHITE, 7) gives all squares on the
/// 7th rank, while relative_rank_bb(BLACK, 7) gives all squares on the 2nd
/// rank.

inline Bitboard relative_rank_bb(Color c, Rank r) {
  return RelativeRankBB[c][r];
}


/// in_front_bb() takes a color and a rank or square as input, and returns a
/// bitboard representing all the squares on all ranks in front of the rank
/// (or square), from the given color's point of view.  For instance,
/// in_front_bb(WHITE, RANK_5) will give all squares on ranks 6, 7 and 8, while
/// in_front_bb(BLACK, SQ_D3) will give all squares on ranks 1 and 2.

inline Bitboard in_front_bb(Color c, Rank r) {
  return InFrontBB[c][r];
}

inline Bitboard in_front_bb(Color c, Square s) {
  return in_front_bb(c, square_rank(s));
}


/// ray_bb() gives a bitboard representing all squares along the ray in a
/// given direction from a given square.

inline Bitboard ray_bb(Square s, SignedDirection d) {
  return RayBB[s][d];
}


/// Functions for computing sliding attack bitboards.  rook_attacks_bb(),
/// bishop_attacks_bb() and queen_attacks_bb() all take a square and a
/// bitboard of occupied squares as input, and return a bitboard representing
/// all squares attacked by a rook, bishop or queen on the given square.

#if defined(USE_COMPACT_ROOK_ATTACKS)

inline Bitboard file_attacks_bb(Square s, Bitboard blockers) {
  Bitboard b = (blockers >> square_file(s)) & 0x01010101010100ULL;
  return
    FileAttacks[square_rank(s)][(b*0xd6e8802041d0c441ULL)>>58] & file_bb(s);
}

inline Bitboard rank_attacks_bb(Square s, Bitboard blockers) {
  Bitboard b = (blockers >> ((s & 56) + 1)) & 63;
  return RankAttacks[square_file(s)][b] & rank_bb(s);
}

inline Bitboard rook_attacks_bb(Square s, Bitboard blockers) {
  return file_attacks_bb(s, blockers) | rank_attacks_bb(s, blockers);
}

#elif defined(USE_32BIT_ATTACKS)

inline Bitboard rook_attacks_bb(Square s, Bitboard blockers) {
  Bitboard b = blockers & RMask[s];
  return RAttacks[RAttackIndex[s] +
                  (unsigned(int(b) * int(RMult[s]) ^
                            int(b >> 32) * int(RMult[s] >> 32))
                   >> RShift[s])];
}

#else

inline Bitboard rook_attacks_bb(Square s, Bitboard blockers) {
  Bitboard b = blockers & RMask[s];
  return RAttacks[RAttackIndex[s] + ((b * RMult[s]) >> RShift[s])];
}

#endif

#if defined(USE_32BIT_ATTACKS)

inline Bitboard bishop_attacks_bb(Square s, Bitboard blockers) {
  Bitboard b = blockers & BMask[s];
  return BAttacks[BAttackIndex[s] +
                  (unsigned(int(b) * int(BMult[s]) ^
                            int(b >> 32) * int(BMult[s] >> 32))
                   >> BShift[s])];
}

#else // defined(USE_32BIT_ATTACKS)

inline Bitboard bishop_attacks_bb(Square s, Bitboard blockers) {
  Bitboard b = blockers & BMask[s];
  return BAttacks[BAttackIndex[s] + ((b * BMult[s]) >> BShift[s])];
}

#endif // defined(USE_32BIT_ATTACKS)

inline Bitboard queen_attacks_bb(Square s, Bitboard blockers) {
  return rook_attacks_bb(s, blockers) | bishop_attacks_bb(s, blockers);
}


/// squares_between returns a bitboard representing all squares between
/// two squares.  For instance, squares_between(SQ_C4, SQ_F7) returns a
/// bitboard with the bits for square d5 and e6 set.  If s1 and s2 are not
/// on the same line, file or diagonal, EmptyBoardBB is returned.

inline Bitboard squares_between(Square s1, Square s2) {
  return BetweenBB[s1][s2];
}


/// squares_in_front_of takes a color and a square as input, and returns a
/// bitboard representing all squares along the line in front of the square,
/// from the point of view of the given color.  For instance,
/// squares_in_front_of(BLACK, SQ_E4) returns a bitboard with the squares
/// e3, e2 and e1 set.

inline Bitboard squares_in_front_of(Color c, Square s) {
  return in_front_bb(c, s) & file_bb(s);
}


/// squares_behind is similar to squares_in_front, but returns the squares
/// behind the square instead of in front of the square.

inline Bitboard squares_behind(Color c, Square s) {
  return in_front_bb(opposite_color(c), s) & file_bb(s);
}


/// passed_pawn_mask takes a color and a square as input, and returns a
/// bitboard mask which can be used to test if a pawn of the given color on
/// the given square is a passed pawn.

inline Bitboard passed_pawn_mask(Color c, Square s) {
  return PassedPawnMask[c][s];
}


/// outpost_mask takes a color and a square as input, and returns a bitboard
/// mask which can be used to test whether a piece on the square can possibly
/// be driven away by an enemy pawn.

inline Bitboard outpost_mask(Color c, Square s) {
  return OutpostMask[c][s];
}


/// isolated_pawn_mask takes a square as input, and returns a bitboard mask
/// which can be used to test whether a pawn on the given square is isolated.

inline Bitboard isolated_pawn_mask(Square s) {
  return neighboring_files_bb(s);
}


/// count_1s() counts the number of nonzero bits in a bitboard.

#if defined(BITCOUNT_LOOP)

inline int count_1s(Bitboard b) {
  int r;
  for(r = 0; b; r++, b &= b - 1);
  return r;
}

inline int count_1s_max_15(Bitboard b) {
  return count_1s(b);
}

#elif defined(BITCOUNT_SWAR_32)

inline int count_1s(Bitboard b) {
  unsigned w = unsigned(b >> 32), v = unsigned(b);
  v = v - ((v >> 1) & 0x55555555);
  w = w - ((w >> 1) & 0x55555555);
  v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
  w = (w & 0x33333333) + ((w >> 2) & 0x33333333);
  v = (v + (v >> 4)) & 0x0F0F0F0F;
  w = (w + (w >> 4)) & 0x0F0F0F0F;
  v = ((v+w) * 0x01010101) >> 24; // mul is fast on amd procs
  return int(v);
}

inline int count_1s_max_15(Bitboard b) {
  unsigned w = unsigned(b >> 32), v = unsigned(b);
  v = v - ((v >> 1) & 0x55555555);
  w = w - ((w >> 1) & 0x55555555);
  v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
  w = (w & 0x33333333) + ((w >> 2) & 0x33333333);
  v = ((v+w) * 0x11111111) >> 28;
  return int(v);
}

#elif defined(BITCOUNT_SWAR_64)

inline int count_1s(Bitboard b) {
  b -= ((b>>1) & 0x5555555555555555ULL);
  b = ((b>>2) & 0x3333333333333333ULL) + (b & 0x3333333333333333ULL);
  b = ((b>>4) + b) & 0x0F0F0F0F0F0F0F0FULL;
  b *= 0x0101010101010101ULL;
  return int(b >> 56);
}

inline int count_1s_max_15(Bitboard b) {
  b -= (b>>1) & 0x5555555555555555ULL;
  b = ((b>>2) & 0x3333333333333333ULL) + (b & 0x3333333333333333ULL);
  b *= 0x1111111111111111ULL;
  return int(b >> 60);
}

#endif // BITCOUNT


////
//// Prototypes
////

extern void print_bitboard(Bitboard b);
extern void init_bitboards();
extern Square first_1(Bitboard b);
extern Square pop_1st_bit(Bitboard *b);


#endif // !defined(BITBOARD_H_INCLUDED)
// ---- end bitboard.h ----
// ---- begin phase.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(PHASE_H_INCLUDED)
#define PHASE_H_INCLUDED

////
//// Types
////

enum Phase {
  PHASE_ENDGAME = 0,
  PHASE_MIDGAME = 128
};


#endif // !defined(PHASE_H_INCLUDED)
// ---- end phase.h ----
// ---- begin value.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(VALUE_H_INCLUDED)
#define VALUE_H_INCLUDED

////
//// Includes
////



////
//// Types
////

enum ValueType {
  VALUE_TYPE_NONE = 0,
  VALUE_TYPE_UPPER = 1,  // Upper bound
  VALUE_TYPE_LOWER = 2,  // Lower bound
  VALUE_TYPE_EXACT = 3   // Exact score
};


enum Value {
  VALUE_DRAW = 0,
  VALUE_KNOWN_WIN = 15000,
  VALUE_MATE = 30000,
  VALUE_INFINITE = 30001,
  VALUE_NONE = 30002
};


////
//// Constants and variables
////

/// Piece values, middle game and endgame

/// Important: If the material values are changed, one must also
/// adjust the piece square tables, and the method game_phase() in the
/// Position class!

const Value PawnValueMidgame = Value(0xCC);
const Value PawnValueEndgame = Value(0x100);
const Value KnightValueMidgame = Value(0x340);
const Value KnightValueEndgame = Value(0x340);
const Value BishopValueMidgame = Value(0x340);
const Value BishopValueEndgame = Value(0x340);
const Value RookValueMidgame = Value(0x505);
const Value RookValueEndgame = Value(0x505);
const Value QueenValueMidgame = Value(0xA00);
const Value QueenValueEndgame = Value(0xA00);

const Value PieceValueMidgame[17] = {
  Value(0),
  PawnValueMidgame, KnightValueMidgame, BishopValueMidgame,
  RookValueMidgame, QueenValueMidgame,
  Value(0), Value(0), Value(0),
  PawnValueMidgame, KnightValueMidgame, BishopValueMidgame,
  RookValueMidgame, QueenValueMidgame,
  Value(0), Value(0), Value(0)
};

const Value PieceValueEndgame[17] = {
  Value(0),
  PawnValueEndgame, KnightValueEndgame, BishopValueEndgame,
  RookValueEndgame, QueenValueEndgame,
  Value(0), Value(0), Value(0),
  PawnValueEndgame, KnightValueEndgame, BishopValueEndgame,
  RookValueEndgame, QueenValueEndgame,
  Value(0), Value(0), Value(0)
};

/// Bonus for having the side to move

const Value TempoValueMidgame = Value(50);
const Value TempoValueEndgame = Value(20);


////
//// Inline functions
////

inline Value operator+ (Value v, int i) { return Value(int(v) + i); }
inline Value operator+ (Value v1, Value v2) { return Value(int(v1) + int(v2)); }
inline void operator+= (Value &v1, Value v2) {
  v1 = Value(int(v1) + int(v2));
}
inline Value operator- (Value v, int i) { return Value(int(v) - i); }
inline Value operator- (Value v) { return Value(-int(v)); }
inline Value operator- (Value v1, Value v2) { return Value(int(v1) - int(v2)); }
inline void operator-= (Value &v1, Value v2) {
  v1 = Value(int(v1) - int(v2));
}
inline Value operator* (Value v, int i) { return Value(int(v) * i); }
inline void operator*= (Value &v, int i) { v = Value(int(v) * i); }
inline Value operator* (int i, Value v) { return Value(int(v) * i); }
inline Value operator/ (Value v, int i) { return Value(int(v) / i); }
inline void operator/= (Value &v, int i) { v = Value(int(v) / i); }


inline Value value_mate_in(int ply) {
  return Value(VALUE_MATE - Value(ply));
}
               
inline Value value_mated_in(int ply) {
  return Value(-VALUE_MATE + Value(ply));
}

inline bool is_upper_bound(ValueType vt) {
  return (int(vt) & int(VALUE_TYPE_UPPER)) != 0;
}

inline bool is_lower_bound(ValueType vt) {
  return (int(vt) & int(VALUE_TYPE_LOWER)) != 0;
}

inline Value piece_value_midgame(PieceType pt) {
  return PieceValueMidgame[pt];
}

inline Value piece_value_endgame(PieceType pt) {
  return PieceValueEndgame[pt];
}

inline Value piece_value_midgame(Piece p) {
  return PieceValueMidgame[p];
}

inline Value piece_value_endgame(Piece p) {
  return PieceValueEndgame[p];
}


////
//// Prototypes
////

extern Value value_to_tt(Value v, int ply);
extern Value value_from_tt(Value v, int ply);
extern int value_to_centipawns(Value v);
extern Value value_from_centipawns(int cp);
extern const std::string value_to_string(Value v);


#endif // !defined(VALUE_H_INCLUDED)
// ---- end value.h ----


////
//// Constants
////

/// FEN string for the initial position:
const std::string StartPosition =
  "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

/// Maximum number of plies per game (220 should be enough, because the
/// maximum search depth is 100, and during position setup we reset the
/// move counter for every non-reversible move):
const int MaxGameLength = 220;


////
//// Types
////

/// Castle rights, encoded as bit fields:

enum CastleRights {
  NO_CASTLES = 0,
  WHITE_OO = 1,
  BLACK_OO = 2,
  WHITE_OOO = 4,
  BLACK_OOO = 8,
  ALL_CASTLES = 15
};


/// The UndoInfo struct stores information we need to restore a Position
/// object to its previous state when we retract a move.  Whenever a move
/// is made on the board (by calling Position::do_move), an UndoInfo object
/// must be passed as a parameter.  When the move is unmade (by calling
/// Position::undo_move), the same UndoInfo object must be passed again.

struct UndoInfo {
  int castleRights;
  Square epSquare;
  Bitboard checkersBB;
  Key key, pawnKey, materialKey;
  int rule50;
  Move lastMove;
  PieceType capture;
  Value mgValue, egValue;
};


/// The position data structure.  A position consists of the following data:
///
///    * For each piece type, a bitboard representing the squares occupied
///      by pieces of that type.
///    * For each color, a bitboard representing the squares occupiecd by
///      pieces of that color.
///    * A bitboard of all occupied squares.
///    * A bitboard of all checking pieces.
///    * A 64-entry array of pieces, indexed by the squares of the board.
///    * The current side to move.
///    * Information about the castling rights for both sides.
///    * The initial files of the kings and both pairs of rooks.  This is
///      used to implement the Chess960 castling rules.
///    * The en passant square (which is SQ_NONE if no en passant capture is
///      possible).
///    * The squares of the kings for both sides.
///    * The last move played.
///    * Hash keys for the position itself, the current pawn structure, and
///      the current material situation.
///    * Hash keys for all previous positions in the game (for detecting
///      repetition draws.
///    * A counter for detecting 50 move rule draws.

class Position {

  friend class MaterialInfo;
  friend class EndgameFunctions;

public:
  // Constructors
  Position() {};
  Position(const Position &pos);
  Position(const std::string &fen);

  // Text input/output
  void from_fen(const std::string &fen);
  const std::string to_fen() const;
  void print() const;

  // Copying
  void copy(const Position &pos);
  void flipped_copy(const Position &pos);

  // The piece on a given square
  Piece piece_on(Square s) const;
  PieceType type_of_piece_on(Square s) const;
  Color color_of_piece_on(Square s) const;
  bool square_is_empty(Square s) const;
  bool square_is_occupied(Square s) const;
  Value midgame_value_of_piece_on(Square s) const;
  Value endgame_value_of_piece_on(Square s) const;

  // Side to move
  Color side_to_move() const;

  // Bitboard representation of the position
  Bitboard empty_squares() const;
  Bitboard occupied_squares() const;
  Bitboard pieces_of_color(Color c) const;
  Bitboard pieces_of_type(PieceType pt) const;
  Bitboard pieces_of_color_and_type(Color c, PieceType pt) const;
  Bitboard pawns() const;
  Bitboard knights() const;
  Bitboard bishops() const;
  Bitboard rooks() const;
  Bitboard queens() const;
  Bitboard kings() const;
  Bitboard rooks_and_queens() const;
  Bitboard bishops_and_queens() const;
  Bitboard sliders() const;
  Bitboard pawns(Color c) const;
  Bitboard knights(Color c) const;
  Bitboard bishops(Color c) const;
  Bitboard rooks(Color c) const;
  Bitboard queens(Color c) const;
  Bitboard kings(Color c) const;
  Bitboard rooks_and_queens(Color c) const;
  Bitboard bishops_and_queens(Color c) const;
  Bitboard sliders_of_color(Color c) const;

  // Number of pieces of each color and type
  int piece_count(Color c, PieceType pt) const;

  // The en passant square:
  Square ep_square() const;

  // Current king position for each color
  Square king_square(Color c) const;

  // Castling rights.
  bool can_castle_kingside(Color c) const;
  bool can_castle_queenside(Color c) const;
  bool can_castle(Color c) const;
  Square initial_kr_square(Color c) const;
  Square initial_qr_square(Color c) const;

  // Attack bitboards
  Bitboard sliding_attacks(Square s, Direction d) const;
  Bitboard ray_attacks(Square s, SignedDirection d) const;
  Bitboard pawn_attacks(Color c, Square s) const;

  template<PieceType>
  Bitboard piece_attacks(Square s) const;

  // Bitboards for pinned pieces and discovered check candidates
  Bitboard discovered_check_candidates(Color c) const;
  Bitboard pinned_pieces(Color c) const;

  // Checking pieces
  Bitboard checkers() const;

  // Piece lists
  Square piece_list(Color c, PieceType pt, int index) const;

  // Attack information for a given square
  bool square_is_attacked(Square s, Color c) const;
  Bitboard attacks_to(Square s) const;
  Bitboard attacks_to(Square s, Color c) const;
  bool is_check() const;
  bool pawn_attacks_square(Color c, Square f, Square t) const;

  template<PieceType>
  Bitboard piece_attacks_square(Square f, Square t) const; // Dispatch at compile-time

  bool piece_attacks_square(Square f, Square t) const; // Dispatch at run-time

  // Properties of moves
  bool pl_move_is_legal(Move m) const;
  bool pl_move_is_legal(Move m, Bitboard pinned) const;
  bool move_is_check(Move m) const;
  bool move_is_check(Move m, Bitboard dcCandidates) const;
  bool move_is_capture(Move m) const;
  bool move_is_deep_pawn_push(Move m) const;
  bool move_is_pawn_push_to_7th(Move m) const;
  bool move_is_passed_pawn_push(Move m) const;
  bool move_was_passed_pawn_push(Move m) const;
  bool move_attacks_square(Move m, Square s) const;

  // Information about pawns
  bool pawn_is_passed(Color c, Square s) const;
  bool pawn_is_isolated(Color c, Square s) const;
  bool pawn_is_doubled(Color c, Square s) const;

  // Open and half-open files
  bool file_is_open(File f) const;
  bool file_is_half_open(Color c, File f) const;

  // Weak squares
  bool square_is_weak(Square s, Color c) const;

  // Doing and undoing moves
  void backup(UndoInfo &u) const;
  void restore(const UndoInfo &u);
  void do_move(Move m, UndoInfo &u);
  void do_move(Move m, UndoInfo &u, Bitboard dcCandidates);
  void undo_move(Move m, const UndoInfo &u);
  void do_null_move(UndoInfo &u);
  void undo_null_move(const UndoInfo &u);

  // Static exchange evaluation
  int see(Square from, Square to) const;
  int see(Move m) const;

  // Accessing hash keys
  Key get_key() const;
  Key get_pawn_key() const;
  Key get_material_key() const;

  // Incremental evaluation
  Value mg_value() const;
  Value eg_value() const;
  Value non_pawn_material(Color c) const;
  Phase game_phase() const;
  Value mg_pst_delta(Move m) const;

  // Game termination checks
  bool is_mate();
  bool is_draw() const;

  // Check if one side threatens a mate in one
  bool has_mate_threat(Color c);

  // Number of plies since the last non-reversible move
  int rule_50_counter() const;

  // Other properties of the position
  bool opposite_colored_bishops() const;
  bool has_pawn_on_7th(Color c) const;

  // Reset the gamePly variable to 0
  void reset_game_ply();

  // Position consistency check, for debugging
  bool is_ok(int* failedStep = NULL) const;

  // Static member functions:
  static void init_zobrist();
  static void init_piece_square_tables();

private:
  // Initialization helper functions (used while setting up a position)
  void clear();
  void put_piece(Piece p, Square s);
  void allow_oo(Color c);
  void allow_ooo(Color c);

  // Helper functions for doing and undoing moves
  void do_capture_move(Move m, PieceType capture, Color them, Square to);
  void do_castle_move(Move m);
  void do_promotion_move(Move m, UndoInfo &u);
  void do_ep_move(Move m);
  void undo_castle_move(Move m);
  void undo_promotion_move(Move m, const UndoInfo &u);
  void undo_ep_move(Move m);
  void find_checkers();

  template<PieceType Piece, bool FindPinned>
  Bitboard hidden_checks(Color c, Square ksq) const;

  // Computing hash keys from scratch (for initialization and debugging)
  Key compute_key() const;
  Key compute_pawn_key() const;
  Key compute_material_key() const;

  // Computing incremental evaluation scores and material counts
  Value mg_pst(Color c, PieceType pt, Square s) const;
  Value eg_pst(Color c, PieceType pt, Square s) const;
  Value compute_mg_value() const;
  Value compute_eg_value() const;
  Value compute_non_pawn_material(Color c) const;

  // Bitboards
  Bitboard byColorBB[2], byTypeBB[8];
  Bitboard checkersBB;

  // Board
  Piece board[64];

  // Piece counts
  int pieceCount[2][8]; // [color][pieceType]

  // Piece lists
  Square pieceList[2][8][16]; // [color][pieceType][index]
  int index[64];

  // Other info
  Color sideToMove;
  int castleRights;
  File initialKFile, initialKRFile, initialQRFile;
  Square epSquare;
  Square kingSquare[2];
  Move lastMove;
  Key key, pawnKey, materialKey, history[MaxGameLength];
  int rule50, gamePly;
  Value mgValue, egValue;
  Value npMaterial[2];

  // Static variables
  static int castleRightsMask[64];
  static Key zobrist[2][8][64];
  static Key zobEp[64];
  static Key zobCastle[16];
  static Key zobMaterial[2][8][16];
  static Key zobSideToMove;
  static Value MgPieceSquareTable[16][64];
  static Value EgPieceSquareTable[16][64];
};


////
//// Inline functions
////

inline Piece Position::piece_on(Square s) const {
  return board[s];
}

inline Color Position::color_of_piece_on(Square s) const {
  return color_of_piece(piece_on(s));
}

inline PieceType Position::type_of_piece_on(Square s) const {
  return type_of_piece(piece_on(s));
}

inline bool Position::square_is_empty(Square s) const {
  return piece_on(s) == EMPTY;
}

inline bool Position::square_is_occupied(Square s) const {
  return !square_is_empty(s);
}

inline Value Position::midgame_value_of_piece_on(Square s) const {
  return piece_value_midgame(piece_on(s));
}

inline Value Position::endgame_value_of_piece_on(Square s) const {
  return piece_value_endgame(piece_on(s));
}

inline Color Position::side_to_move() const {
  return sideToMove;
}

inline Bitboard Position::occupied_squares() const {
  return byTypeBB[0];
}

inline Bitboard Position::empty_squares() const {
  return ~(occupied_squares());
}

inline Bitboard Position::pieces_of_color(Color c) const {
  return byColorBB[c];
}

inline Bitboard Position::pieces_of_type(PieceType pt) const {
  return byTypeBB[pt];
}

inline Bitboard Position::pieces_of_color_and_type(Color c, PieceType pt) const {
  return pieces_of_color(c) & pieces_of_type(pt);
}

inline Bitboard Position::pawns() const {
  return pieces_of_type(PAWN);
}

inline Bitboard Position::knights() const {
  return pieces_of_type(KNIGHT);
}

inline Bitboard Position::bishops() const {
  return pieces_of_type(BISHOP);
}

inline Bitboard Position::rooks() const {
  return pieces_of_type(ROOK);
}

inline Bitboard Position::queens() const {
  return pieces_of_type(QUEEN);
}

inline Bitboard Position::kings() const {
  return pieces_of_type(KING);
}

inline Bitboard Position::rooks_and_queens() const {
  return rooks() | queens();
}

inline Bitboard Position::bishops_and_queens() const {
  return bishops() | queens();
}

inline Bitboard Position::sliders() const {
  return bishops() | queens() | rooks();
}

inline Bitboard Position::pawns(Color c) const {
  return pieces_of_color_and_type(c, PAWN);
}

inline Bitboard Position::knights(Color c) const {
  return pieces_of_color_and_type(c, KNIGHT);
}

inline Bitboard Position::bishops(Color c) const {
  return pieces_of_color_and_type(c, BISHOP);
}

inline Bitboard Position::rooks(Color c) const {
  return pieces_of_color_and_type(c, ROOK);
}

inline Bitboard Position::queens(Color c) const {
  return pieces_of_color_and_type(c, QUEEN);
}

inline Bitboard Position::kings(Color c) const {
  return pieces_of_color_and_type(c, KING);
}

inline Bitboard Position::rooks_and_queens(Color c) const {
  return rooks_and_queens() & pieces_of_color(c);
}

inline Bitboard Position::bishops_and_queens(Color c) const {
  return bishops_and_queens() & pieces_of_color(c);
}

inline Bitboard Position::sliders_of_color(Color c) const {
  return sliders() & pieces_of_color(c);
}

inline int Position::piece_count(Color c, PieceType pt) const {
  return pieceCount[c][pt];
}

inline Square Position::piece_list(Color c, PieceType pt, int index) const {
  return pieceList[c][pt][index];
}

inline Square Position::ep_square() const {
  return epSquare;
}

inline Square Position::king_square(Color c) const {
  return kingSquare[c];
}

inline bool Position::can_castle_kingside(Color side) const {
  return castleRights & (1+int(side));
}

inline bool Position::can_castle_queenside(Color side) const {
  return castleRights & (4+4*int(side));
}

inline bool Position::can_castle(Color side) const {
  return can_castle_kingside(side) || can_castle_queenside(side);
}

inline Square Position::initial_kr_square(Color c) const {
  return relative_square(c, make_square(initialKRFile, RANK_1));
}

inline Square Position::initial_qr_square(Color c) const {
  return relative_square(c, make_square(initialQRFile, RANK_1));
}

inline Bitboard Position::pawn_attacks(Color c, Square s) const {
  return StepAttackBB[pawn_of_color(c)][s];
}

template<>
inline Bitboard Position::piece_attacks<KNIGHT>(Square s) const {
  return StepAttackBB[KNIGHT][s];
}

template<>
inline Bitboard Position::piece_attacks<BISHOP>(Square s) const {
  return bishop_attacks_bb(s, occupied_squares());
}

template<>
inline Bitboard Position::piece_attacks<ROOK>(Square s) const {
  return rook_attacks_bb(s, occupied_squares());
}

template<>
inline Bitboard Position::piece_attacks<QUEEN>(Square s) const {
  return piece_attacks<ROOK>(s) | piece_attacks<BISHOP>(s);
}

template<>
inline Bitboard Position::piece_attacks<KING>(Square s) const {
  return StepAttackBB[KING][s];
}

inline Bitboard Position::checkers() const {
  return checkersBB;
}

inline bool Position::is_check() const {
  return checkersBB != EmptyBoardBB;
}

inline bool Position::pawn_attacks_square(Color c, Square f, Square t) const {
  return bit_is_set(pawn_attacks(c, f), t);
}

template<PieceType Piece>
Bitboard Position::piece_attacks_square(Square f, Square t) const {
  return bit_is_set(piece_attacks<Piece>(f), t);
}

inline bool Position::pawn_is_passed(Color c, Square s) const {
  return !(pawns(opposite_color(c)) & passed_pawn_mask(c, s));
}

inline bool Position::pawn_is_isolated(Color c, Square s) const {
  return !(pawns(c) & neighboring_files_bb(s));
}

inline bool Position::pawn_is_doubled(Color c, Square s) const {
  return pawns(c) & squares_behind(c, s);
}

inline bool Position::file_is_open(File f) const {
  return !(pawns() & file_bb(f));
}

inline bool Position::file_is_half_open(Color c, File f) const {
  return !(pawns(c) & file_bb(f));
}

inline bool Position::square_is_weak(Square s, Color c) const {
  return !(pawns(c) & outpost_mask(opposite_color(c), s));
}

inline Key Position::get_key() const {
  return key;
}

inline Key Position::get_pawn_key() const {
  return pawnKey;
}

inline Key Position::get_material_key() const {
  return materialKey;
}

inline Value Position::mg_pst(Color c, PieceType pt, Square s) const {
  return MgPieceSquareTable[piece_of_color_and_type(c, pt)][s];
}

inline Value Position::mg_pst_delta(Move m) const {
  return MgPieceSquareTable[piece_on(move_from(m))][move_to(m)]
        -MgPieceSquareTable[piece_on(move_from(m))][move_from(m)];
}

inline Value Position::eg_pst(Color c, PieceType pt, Square s) const {
  return EgPieceSquareTable[piece_of_color_and_type(c, pt)][s];
}

inline Value Position::mg_value() const {
  return mgValue;
}

inline Value Position::eg_value() const {
  return egValue;
}

inline Value Position::non_pawn_material(Color c) const {
  return npMaterial[c];
}

inline Phase Position::game_phase() const {

  // The purpose of the Value(325) terms below is to make sure the difference
  // between MidgameLimit and EndgameLimit is a power of 2, which should make
  // the division at the end of the function a bit faster.
  static const Value MidgameLimit =  2 * QueenValueMidgame
                                   + 2 * RookValueMidgame
                                   + 6 * BishopValueMidgame
                                   + Value(325);

  static const Value EndgameLimit = 4 * RookValueMidgame - Value(325);

  Value npm = non_pawn_material(WHITE) + non_pawn_material(BLACK);

  if (npm >= MidgameLimit)
      return PHASE_MIDGAME;
  else if(npm <= EndgameLimit)
      return PHASE_ENDGAME;
  else
      return Phase(((npm - EndgameLimit) * 128) / (MidgameLimit - EndgameLimit));
}

inline bool Position::move_is_deep_pawn_push(Move m) const {

  Color c = side_to_move();
  return   piece_on(move_from(m)) == pawn_of_color(c)
        && relative_rank(c, move_to(m)) > RANK_4;
}

inline bool Position::move_is_pawn_push_to_7th(Move m) const {

  Color c = side_to_move();
  return   piece_on(move_from(m)) == pawn_of_color(c)
        && relative_rank(c, move_to(m)) == RANK_7;
}

inline bool Position::move_is_passed_pawn_push(Move m) const {

  Color c = side_to_move();
  return   piece_on(move_from(m)) == pawn_of_color(c)
        && pawn_is_passed(c, move_to(m));
}

inline bool Position::move_was_passed_pawn_push(Move m) const {

  Color c = opposite_color(side_to_move());
  return   piece_on(move_to(m)) == pawn_of_color(c)
        && pawn_is_passed(c, move_to(m));
}

inline int Position::rule_50_counter() const {

  return rule50;
}

inline bool Position::opposite_colored_bishops() const {

  return   piece_count(WHITE, BISHOP) == 1
        && piece_count(BLACK, BISHOP) == 1
        && square_color(piece_list(WHITE, BISHOP, 0)) != square_color(piece_list(BLACK, BISHOP, 0));
}

inline bool Position::has_pawn_on_7th(Color c) const {

  return pawns(c) & relative_rank_bb(c, RANK_7);
}


#endif // !defined(POSITION_H_INCLUDED)
// ---- end position.h ----


////
//// Prototypes
////

extern int generate_captures(const Position &pos, MoveStack *mlist);
extern int generate_noncaptures(const Position &pos, MoveStack *mlist);
extern int generate_checks(const Position &pos, MoveStack *mlist, Bitboard dc);
extern int generate_evasions(const Position &pos, MoveStack *mlist);
extern int generate_legal_moves(const Position &pos, MoveStack *mlist);
extern bool move_is_legal(const Position &pos, const Move m, Bitboard pinned);


#endif // !defined(MOVEGEN_H_INCLUDED)
// ---- end movegen.h ----
// ---- begin tt.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(TT_H_INCLUDED)
#define TT_H_INCLUDED

////
//// Includes
////



////
//// Types
////

/// The TTEntry class is the class of transposition table entries.

class TTEntry {

public:
  TTEntry();
  TTEntry(Key k, Value v, ValueType t, Depth d, Move m, int generation);
  Key key() const { return key_; }
  Depth depth() const { return Depth(depth_); }
  Move move() const { return Move(data & 0x7FFFF); }
  Value value() const { return Value(value_); }
  ValueType type() const { return ValueType((data >> 20) & 3); }
  int generation() const { return (data >> 23); }

private:
  Key key_;
  uint32_t data;
  int16_t value_;
  int16_t depth_;
};

/// The transposition table class.  This is basically just a huge array
/// containing TTEntry objects, and a few methods for writing new entries
/// and reading new ones.

class TranspositionTable {

public:
  TranspositionTable(unsigned mbSize);
  ~TranspositionTable();
  void set_size(unsigned mbSize);
  void clear();
  void store(const Position &pos, Value v, Depth d, Move m, ValueType type);
  const TTEntry* retrieve(const Position &pos) const;
  void new_search();
  void insert_pv(const Position &pos, Move pv[]);
  int full();

private:
  inline TTEntry* first_entry(const Position &pos) const;

  unsigned size;
  int writes;
  TTEntry* entries;
  uint8_t generation;
};


////
//// Constants and variables
////

// Default transposition table size, in megabytes:
const int TTDefaultSize = 32;


#endif // !defined(TT_H_INCLUDED)
// ---- end tt.h ----


////
//// Constants
////

const int PLY_MAX = 100;
const int PLY_MAX_PLUS_2 = 102;


////
//// Types
////

/// The SearchStack struct keeps track of the information we need to remember
/// from nodes shallower and deeper in the tree during the search.  Each
/// search thread has its own array of SearchStack objects, indexed by the
/// current ply.

struct SearchStack {
  Move pv[PLY_MAX];
  Move currentMove;
  Value currentMoveCaptureValue;
  Move mateKiller, killer1, killer2;
  Move threatMove;
  Depth reduction;
};


////
//// Global variables
////

extern TranspositionTable TT;

extern int ActiveThreads;

extern Lock SMPLock;

// Perhaps better to make H local, and pass as parameter to MovePicker?
extern History H;  


////
//// Prototypes
////

extern void init_threads();
extern void stop_threads();
extern void think(const Position &pos, bool infinite, bool ponder, int side_to_move,
                  int time[], int increment[], int movesToGo, int maxDepth, 
                  int maxNodes, int maxTime, Move searchMoves[]);
extern int64_t nodes_searched();


#endif // !defined(SEARCH_H_INCLUDED)
// ---- end search.h ----
// ---- begin thread.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(THREAD_H_INCLUDED)
#define THREAD_H_INCLUDED


////
//// Includes
////

// ---- begin movepick.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined MOVEPICK_H_INCLUDED
#define MOVEPICK_H_INCLUDED

////
//// Includes
////



////
//// Types
////

/// MovePicker is a class which is used to pick one legal move at a time from
/// the current position.  It is initialized with a Position object and a few
/// moves we have reason to believe are good.  The most important method is
/// MovePicker::pick_next_move(), which returns a new legal move each time it
/// is called, until there are no legal moves left, when MOVE_NONE is returned.
/// In order to improve the efficiency of the alpha beta algorithm, MovePicker
/// attempts to return the moves which are most likely to be strongest first.

class MovePicker {

public:

  enum MovegenPhase {
    PH_TT_MOVE,        // Transposition table move
    PH_MATE_KILLER,    // Mate killer from the current ply
    PH_GOOD_CAPTURES,  // Queen promotions and captures with SEE values >= 0
    PH_BAD_CAPTURES,   // Queen promotions and captures with SEE values < 0
    PH_KILLER_1,       // Killer move 1 from the current ply (not used yet).
    PH_KILLER_2,       // Killer move 2 from the current ply (not used yet).
    PH_NONCAPTURES,    // Non-captures and underpromotions
    PH_EVASIONS,       // Check evasions
    PH_QCAPTURES,      // Captures in quiescence search
    PH_QCHECKS,        // Checks in quiescence search
    PH_STOP
  };

  MovePicker(const Position& p, bool pvnode, Move ttm, Move mk, Move k1, Move k2, Depth d);
  Move get_next_move();
  Move get_next_move(Lock &lock);
  int number_of_moves() const;
  int current_move_score() const;
  MovegenPhase current_move_type() const;
  Bitboard discovered_check_candidates() const;

  static void init_phase_table();

private:
  void score_captures();
  void score_noncaptures();
  void score_evasions();
  void score_qcaptures();
  Move pick_move_from_list();
  int find_best_index();

  const Position& pos;
  Move ttMove, mateKiller, killer1, killer2;
  Bitboard pinned, dc;
  MoveStack moves[256], badCaptures[64];
  bool pvNode;
  Depth depth;
  int phaseIndex;
  int numOfMoves, numOfBadCaptures;
  int movesPicked, badCapturesPicked;
  bool finished;
};


////
//// Inline functions
////

/// MovePicker::number_of_moves() simply returns the numOfMoves member
/// variable. It is intended to be used in positions where the side to move
/// is in check, for detecting checkmates or situations where there is only
/// a single reply to check.

inline int MovePicker::number_of_moves() const {

  return numOfMoves;
}

/// MovePicker::discovered_check_candidates() returns a bitboard containing
/// all pieces which can possibly give discovered check.  This bitboard is
/// computed by the constructor function.

inline Bitboard MovePicker::discovered_check_candidates() const {
  return dc;
}

#endif // !defined(MOVEPICK_H_INCLUDED)
// ---- end movepick.h ----


////
//// Constants and variables
////

const int THREAD_MAX = 8;


////
//// Types
////

struct SplitPoint {
  SplitPoint *parent;
  Position pos;
  SearchStack sstack[THREAD_MAX][PLY_MAX];
  SearchStack *parentSstack;
  int ply;
  Depth depth;
  volatile Value alpha, beta, bestValue;
  bool pvNode;
  Bitboard dcCandidates;
  int master, slaves[THREAD_MAX];
  Lock lock;
  MovePicker *mp;
  volatile int moves;
  volatile int cpus;
  bool finished;
};


struct Thread {
  SplitPoint *splitPoint;
  int activeSplitPoints;
  uint64_t nodes;
  bool failHighPly1;
  volatile bool stop;
  volatile bool running;
  volatile bool idle;
  volatile bool workIsWaiting;
  volatile bool printCurrentLine;
  unsigned char pad[64];
};


#endif // !defined(THREAD_H_INCLUDED)
// ---- end thread.h ----
// ---- begin ucioption.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(UCIOPTION_H_INCLUDED)
#define UCIOPTION_H_INCLUDED

////
//// Includes
////

#include <string>


////
//// Variables
////

extern bool Chess960;


////
//// Prototypes
////

extern void init_uci_options();
extern void print_uci_options();
extern bool get_option_value_bool(const std::string &optionName);
extern int get_option_value_int(const std::string &optionName);
extern const std::string get_option_value_string(const std::string &optionName);
extern bool button_was_pressed(const std::string &buttonName);
extern void set_option_value(const std::string &optionName, 
                             const std::string &newValue);
extern void push_button(const std::string &buttonName);


#endif // !defined(UCIOPTION_H_INCLUDED)
// ---- end ucioption.h ----


////
//// Variables
////

const std::string BenchmarkPositions[] = {
  "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1",
  "r4rk1/1b2qppp/p1n1p3/1p6/1b1PN3/3BRN2/PP3PPP/R2Q2K1 b - - 7 16",
  "4r1k1/ppq3pp/3b4/2pP4/2Q1p3/4B1P1/PP5P/R5K1 b - - 0 20",
  "4rrk1/pp1n3p/3q2pQ/2p1pb2/2PP4/2P3N1/P2B2PP/4RRK1 b - - 7 19",
  "rq3rk1/ppp2ppp/1bnpb3/3N2B1/3NP3/7P/PPPQ1PP1/2KR3R w - - 7 14",
  "r1bq1r1k/1pp1n1pp/1p1p4/4p2Q/4Pp2/1BNP4/PPP2PPP/3R1RK1 w - - 2 14",
  "r3r1k1/2p2ppp/p1p1bn2/8/1q2P3/2NPQN2/PPP3PP/R4RK1 b - - 2 15",
  "r1bbk1nr/pp3p1p/2n5/1N4p1/2Np1B2/8/PPP2PPP/2KR1B1R w kq - 0 13",
  "r1bq1rk1/ppp1nppp/4n3/3p3Q/3P4/1BP1B3/PP1N2PP/R4RK1 w - - 1 16",
  "4r1k1/r1q2ppp/ppp2n2/4P3/5Rb1/1N1BQ3/PPP3PP/R5K1 w - - 1 17",
  "2rqkb1r/ppp2p2/2npb1p1/1N1Nn2p/2P1PP2/8/PP2B1PP/R1BQK2R b KQ - 0 11",
  "r1bq1r1k/b1p1npp1/p2p3p/1p6/3PP3/1B2NN2/PP3PPP/R2Q1RK1 w - - 1 16",
  "3r1rk1/p5pp/bpp1pp2/8/q1PP1P2/b3P3/P2NQRPP/1R2B1K1 b - - 6 22",
  "r1q2rk1/2p1bppp/2Pp4/p6b/Q1PNp3/4B3/PP1R1PPP/2K4R w - - 2 18",
  "4k2r/1pb2ppp/1p2p3/1R1p4/3P4/2r1PN2/P4PPP/1R4K1 b  - 3 22",
  "3q2k1/pb3p1p/4pbp1/2r5/PpN2N2/1P2P2P/5PP1/Q2R2K1 b - - 4 26"
};
  

////
//// Functions
////

/// benchmark() runs a simple benchmark by letting Stockfish analyze a set
/// of positions for a given time each.  There are four parameters; the
/// transposition table size, the number of search threads that should
/// be used, the time in seconds spent for each position (optional, default
/// is 60) and an optional file name where to look for positions in fen
/// format (default are the BenchmarkPositions defined above).
/// The analysis is written to a file named bench.txt.

void benchmark(const std::string& commandLine) {

  std::istringstream csVal(commandLine);
  std::istringstream csStr(commandLine);
  std::string ttSize, threads, fileName;
  int val, secsPerPos;

  csStr >> ttSize;
  csVal >> val;
  if (val < 4 || val > 1024)
  {
      std::cerr << "The hash table size must be between 4 and 1024" << std::endl;
      exit(EXIT_FAILURE);
  }
  csStr >> threads;
  csVal >> val;
  if (val < 1 || val > THREAD_MAX)
  {
      std::cerr << "The number of threads must be between 1 and " << THREAD_MAX
                << std::endl;
      exit(EXIT_FAILURE);
  }  
  set_option_value("Hash", ttSize);
  set_option_value("Threads", threads);
  set_option_value("OwnBook", "false");
  set_option_value("Use Search Log", "true");
  set_option_value("Search Log Filename", "bench.txt");

  csVal >> secsPerPos;
  csVal >> fileName;

  std::vector<std::string> positions;
  
  if (fileName != "default")
  {
      std::ifstream fenFile(fileName.c_str());
      if (!fenFile.is_open())
      {
          std::cerr << "Unable to open positions file " << fileName
                    << std::endl;
          exit(EXIT_FAILURE);
      }        
      std::string pos;
      while (fenFile.good())
      {
          std::getline(fenFile, pos);
          if (!pos.empty())
              positions.push_back(pos);
      }
      fenFile.close();
  } else
      for (int i = 0; i < 16; i++)
          positions.push_back(std::string(BenchmarkPositions[i]));

  std::vector<std::string>::iterator it;
  for (it = positions.begin(); it != positions.end(); ++it)
  {
      Move moves[1] = {MOVE_NONE};
      int dummy[2] = {0, 0};
      Position pos(*it);
      think(pos, true, false, 0, dummy, dummy, 0, 0, 0, secsPerPos * 1000, moves);
  }
}

// ======== bitbase.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cassert>

// ---- begin bitbase.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(BITBASE_H_INCLUDED)
#define BITBASE_H_INCLUDED

////
//// Includes
////



////
//// Prototypes
////

extern void generate_kpk_bitbase(uint8_t bitbase[]);


#endif // !defined(BITBASE_H_INCLUDED)
// ---- end bitbase.h ----


////
//// Local definitions
////

namespace {

  enum Result {
    RESULT_UNKNOWN,
    RESULT_INVALID,
    RESULT_WIN,
    RESULT_LOSS,
    RESULT_DRAW
  };

  struct KPKPosition {
    void from_index(int index);
    int to_index() const;
    bool is_legal() const;
    bool is_immediate_draw() const;
    bool is_immediate_win() const;
    Bitboard wk_attacks() const;
    Bitboard bk_attacks() const;
    Bitboard pawn_attacks() const;
    
    Square whiteKingSquare, blackKingSquare, pawnSquare;
    Color sideToMove;
  };
    

  Result *Bitbase;
  const int IndexMax = 2*24*64*64;
  int UnknownCount = 0;

  void initialize();
  bool next_iteration();
  Result classify_wtm(const KPKPosition &p);
  Result classify_btm(const KPKPosition &p);
  int compute_index(Square wksq, Square bksq, Square psq, Color stm);
  int compress_result(Result r);
  
}


////
//// Functions
////

void generate_kpk_bitbase(uint8_t bitbase[]) {
  // Allocate array and initialize:
  Bitbase = new Result[IndexMax];
  initialize();

  // Iterate until all positions are classified:
  while(next_iteration());

  // Compress bitbase into the supplied parameter:
  int i, j, b;
  for(i = 0; i < 24576; i++) {
    for(b = 0, j = 0; j < 8; b |= (compress_result(Bitbase[8*i+j]) << j), j++);
    bitbase[i] = b;
  }

  // Release allocated memory:
  delete [] Bitbase;
}


namespace {

  void KPKPosition::from_index(int index) {
    int s;
    sideToMove = Color(index % 2);
    blackKingSquare = Square((index / 2) % 64);
    whiteKingSquare = Square((index / 128) % 64);
    s = (index / 8192) % 24;
    pawnSquare = make_square(File(s % 4), Rank(s / 4 + 1));
  }


  int KPKPosition::to_index() const {
    return compute_index(whiteKingSquare, blackKingSquare, pawnSquare,
                         sideToMove);
  }
    

  bool KPKPosition::is_legal() const {
    if(whiteKingSquare == pawnSquare || whiteKingSquare == blackKingSquare ||
       pawnSquare == blackKingSquare)
      return false;
    if(sideToMove == WHITE) {
      if(bit_is_set(this->wk_attacks(), blackKingSquare))
        return false;
      if(bit_is_set(this->pawn_attacks(), blackKingSquare))
        return false;
    }
    else {
      if(bit_is_set(this->bk_attacks(), whiteKingSquare))
        return false;
    }
    return true;
  }


  bool KPKPosition::is_immediate_draw() const {
    if(sideToMove == BLACK) {
      Bitboard wka = this->wk_attacks();
      Bitboard bka = this->bk_attacks();
    
      // Case 1: Stalemate
      if((bka & ~(wka | this->pawn_attacks())) == EmptyBoardBB)
        return true;

      // Case 2: King can capture pawn
      if(bit_is_set(bka, pawnSquare) && !bit_is_set(wka, pawnSquare))
        return true;
    }
    else {
      // Case 1: Stalemate
      if(whiteKingSquare == SQ_A8 && pawnSquare == SQ_A7 &&
         (blackKingSquare == SQ_C7 || blackKingSquare == SQ_C8))
        return true;
    }

    return false;
  }


  bool KPKPosition::is_immediate_win() const {
    // The position is an immediate win if it is white to move and the white
    // pawn can be promoted without getting captured:
    return
      sideToMove == WHITE &&
      square_rank(pawnSquare) == RANK_7 &&
      (square_distance(blackKingSquare, pawnSquare+DELTA_N) > 1 ||
       bit_is_set(this->wk_attacks(), pawnSquare+DELTA_N));
  }
    

  Bitboard KPKPosition::wk_attacks() const {
    return StepAttackBB[WK][whiteKingSquare];
  }


  Bitboard KPKPosition::bk_attacks() const {
    return StepAttackBB[BK][blackKingSquare];
  }


  Bitboard KPKPosition::pawn_attacks() const {
    return StepAttackBB[WP][pawnSquare];
  }


  void initialize() {
    KPKPosition p;
    for(int i = 0; i < IndexMax; i++) {
      p.from_index(i);
      if(!p.is_legal())
        Bitbase[i] = RESULT_INVALID;
      else if(p.is_immediate_draw())
        Bitbase[i] = RESULT_DRAW;
      else if(p.is_immediate_win())
        Bitbase[i] = RESULT_WIN;
      else {
        Bitbase[i] = RESULT_UNKNOWN;
        UnknownCount++;
      }
    }
  }


  bool next_iteration() {
    KPKPosition p;
    int previousUnknownCount = UnknownCount;
    
    for(int i = 0; i < IndexMax; i++)
      if(Bitbase[i] == RESULT_UNKNOWN) {
        p.from_index(i);

        Bitbase[i] = (p.sideToMove == WHITE)? classify_wtm(p) : classify_btm(p);

        if(Bitbase[i] == RESULT_WIN || Bitbase[i] == RESULT_LOSS ||
           Bitbase[i] == RESULT_DRAW)
          UnknownCount--;
      }

    return UnknownCount != previousUnknownCount;
  }


  Result classify_wtm(const KPKPosition &p) {

    // If one move leads to a position classified as RESULT_LOSS, the result
    // of the current position is RESULT_WIN.  If all moves lead to positions
    // classified as RESULT_DRAW, the current position is classified as
    // RESULT_DRAW.  Otherwise, the current position is classified as
    // RESULT_UNKNOWN.

    bool unknownFound = false;
    Bitboard b;
    Square s;
    
    // King moves
    b = p.wk_attacks();
    while(b) {
      s = pop_1st_bit(&b);
      switch(Bitbase[compute_index(s, p.blackKingSquare, p.pawnSquare,
                                   BLACK)]) {
      case RESULT_LOSS:
        return RESULT_WIN;

      case RESULT_UNKNOWN:
        unknownFound = true;
        break;

      case RESULT_DRAW: case RESULT_INVALID:
        break;

      default:
        assert(false);
      }
    }

    // Pawn moves
    if(square_rank(p.pawnSquare) < RANK_7) {
      s = p.pawnSquare + DELTA_N;
      switch(Bitbase[compute_index(p.whiteKingSquare, p.blackKingSquare, s,
                                   BLACK)]) {
      case RESULT_LOSS:
        return RESULT_WIN;
        
      case RESULT_UNKNOWN:
        unknownFound = true;
        break;
          
      case RESULT_DRAW: case RESULT_INVALID:
        break;
        
      default:
        assert(false);
      }

      if(square_rank(s) == RANK_3 &&
         s != p.whiteKingSquare && s != p.blackKingSquare) {
        s += DELTA_N;
        switch(Bitbase[compute_index(p.whiteKingSquare, p.blackKingSquare, s,
                                     BLACK)]) {
        case RESULT_LOSS:
          return RESULT_WIN;
          
        case RESULT_UNKNOWN:
          unknownFound = true;
          break;
          
        case RESULT_DRAW: case RESULT_INVALID:
          break;
          
        default:
          assert(false);
        }
      }
    }
    
    return unknownFound? RESULT_UNKNOWN : RESULT_DRAW;
  }


  Result classify_btm(const KPKPosition &p) {

    // If one move leads to a position classified as RESULT_DRAW, the result
    // of the current position is RESULT_DRAW.  If all moves lead to positions
    // classified as RESULT_WIN, the current position is classified as
    // RESULT_LOSS.  Otherwise, the current position is classified as
    // RESULT_UNKNOWN.

    bool unknownFound = false;
    Bitboard b;
    Square s;

    // King moves
    b = p.bk_attacks();
    while(b) {
      s = pop_1st_bit(&b);
      switch(Bitbase[compute_index(p.whiteKingSquare, s, p.pawnSquare,
                                   WHITE)]) {
      case RESULT_DRAW:
        return RESULT_DRAW;

      case RESULT_UNKNOWN:
        unknownFound = true;
        break;

      case RESULT_WIN: case RESULT_INVALID:
        break;

      default:
        assert(false);
      }
    }

    return unknownFound? RESULT_UNKNOWN : RESULT_LOSS;
  }


  int compute_index(Square wksq, Square bksq, Square psq, Color stm) {
    int p = int(square_file(psq)) + (int(square_rank(psq)) - 1) * 4;
    int result = int(stm) + 2*int(bksq) + 128*int(wksq) + 8192*p;
    assert(result >= 0 && result < IndexMax);
    return result;
  }


  int compress_result(Result r) {
    return (r == RESULT_WIN || r == RESULT_LOSS)? 1 : 0;
  }
      
}  

// ======== bitboard.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#ifdef _MSC_VER
    #include <intrin.h>
    #ifdef _WIN64
        #pragma intrinsic(_BitScanForward64)
    #else
        #pragma intrinsic(_BitScanForward)
    #endif
    #define USING_INTRINSICS
#endif

#include <iostream>



////
//// Constants and variables
////

const Bitboard SquaresByColorBB[2] = {BlackSquaresBB, WhiteSquaresBB};

const Bitboard FileBB[8] = {
  FileABB, FileBBB, FileCBB, FileDBB, FileEBB, FileFBB, FileGBB, FileHBB
};

const Bitboard NeighboringFilesBB[8] = {
  FileBBB, FileABB|FileCBB, FileBBB|FileDBB, FileCBB|FileEBB,
  FileDBB|FileFBB, FileEBB|FileGBB, FileFBB|FileHBB, FileGBB
};

const Bitboard ThisAndNeighboringFilesBB[8] = {
  FileABB|FileBBB, FileABB|FileBBB|FileCBB,
  FileBBB|FileCBB|FileDBB, FileCBB|FileDBB|FileEBB,
  FileDBB|FileEBB|FileFBB, FileEBB|FileFBB|FileGBB,
  FileFBB|FileGBB|FileHBB, FileGBB|FileHBB
};

const Bitboard RankBB[8] = {
  Rank1BB, Rank2BB, Rank3BB, Rank4BB, Rank5BB, Rank6BB, Rank7BB, Rank8BB
};

const Bitboard RelativeRankBB[2][8] = {
  {
    Rank1BB, Rank2BB, Rank3BB, Rank4BB, Rank5BB, Rank6BB, Rank7BB, Rank8BB
  },
  {
    Rank8BB, Rank7BB, Rank6BB, Rank5BB, Rank4BB, Rank3BB, Rank2BB, Rank1BB
  }
};

const Bitboard InFrontBB[2][8] = {
  {
    Rank2BB | Rank3BB | Rank4BB | Rank5BB | Rank6BB | Rank7BB | Rank8BB,
    Rank3BB | Rank4BB | Rank5BB | Rank6BB | Rank7BB | Rank8BB,
    Rank4BB | Rank5BB | Rank6BB | Rank7BB | Rank8BB,
    Rank5BB | Rank6BB | Rank7BB | Rank8BB,
    Rank6BB | Rank7BB | Rank8BB,
    Rank7BB | Rank8BB,
    Rank8BB,
    EmptyBoardBB
  },
  {
    EmptyBoardBB,
    Rank1BB,
    Rank2BB | Rank1BB,
    Rank3BB | Rank2BB | Rank1BB,
    Rank4BB | Rank3BB | Rank2BB | Rank1BB,
    Rank5BB | Rank4BB | Rank3BB | Rank2BB | Rank1BB,
    Rank6BB | Rank5BB | Rank4BB | Rank3BB | Rank2BB | Rank1BB,
    Rank7BB | Rank6BB | Rank5BB | Rank4BB | Rank3BB | Rank2BB | Rank1BB
  }
};

#if defined(USE_COMPACT_ROOK_ATTACKS)

Bitboard RankAttacks[8][64], FileAttacks[8][64];

#elif defined(USE_32BIT_ATTACKS)

const uint64_t RMult[64] = {
  0xd7445cdec88002c0ULL, 0xd0a505c1f2001722ULL, 0xe065d1c896002182ULL,
  0x9a8c41e75a000892ULL, 0x8900b10c89002aa8ULL, 0x9b28d1c1d60005a2ULL,
  0x15d6c88de002d9aULL, 0xb1dbfc802e8016a9ULL, 0x149a1042d9d60029ULL,
  0xb9c08050599e002fULL, 0x132208c3af300403ULL, 0xc1000ce2e9c50070ULL,
  0x9d9aa13c99020012ULL, 0xb6b078daf71e0046ULL, 0x9d880182fb6e002eULL,
  0x52889f467e850037ULL, 0xda6dc008d19a8480ULL, 0x468286034f902420ULL,
  0x7140ac09dc54c020ULL, 0xd76ffffa39548808ULL, 0xea901c4141500808ULL,
  0xc91004093f953a02ULL, 0x2882afa8f6bb402ULL, 0xaebe335692442c01ULL,
  0xe904a22079fb91eULL, 0x13a514851055f606ULL, 0x76c782018c8fe632ULL,
  0x1dc012a9d116da06ULL, 0x3c9e0037264fffa6ULL, 0x2036002853c6e4a2ULL,
  0xe3fe08500afb47d4ULL, 0xf38af25c86b025c2ULL, 0xc0800e2182cf9a40ULL,
  0x72002480d1f60673ULL, 0x2500200bae6e9b53ULL, 0xc60018c1eefca252ULL,
  0x600590473e3608aULL, 0x46002c4ab3fe51b2ULL, 0xa200011486bcc8d2ULL,
  0xb680078095784c63ULL, 0x2742002639bf11aeULL, 0xc7d60021a5bdb142ULL,
  0xc8c04016bb83d820ULL, 0xbd520028123b4842ULL, 0x9d1600344ac2a832ULL,
  0x6a808005631c8a05ULL, 0x604600a148d5389aULL, 0xe2e40103d40dea65ULL,
  0x945b5a0087c62a81ULL, 0x12dc200cd82d28eULL, 0x2431c600b5f9ef76ULL,
  0xfb142a006a9b314aULL, 0x6870e00a1c97d62ULL, 0x2a9db2004a2689a2ULL,
  0xd3594600caf5d1a2ULL, 0xee0e4900439344a7ULL, 0x89c4d266ca25007aULL,
  0x3e0013a2743f97e3ULL, 0x180e31a0431378aULL, 0x3a9e465a4d42a512ULL,
  0x98d0a11a0c0d9cc2ULL, 0x8e711c1aba19b01eULL, 0x8dcdc836dd201142ULL,
  0x5ac08a4735370479ULL,
};

const int RShift[64] = {
  20, 21, 21, 21, 21, 21, 21, 20, 21, 22, 22, 22, 22, 22, 22, 21,
  21, 22, 22, 22, 22, 22, 22, 21, 21, 22, 22, 22, 22, 22, 22, 21,
  21, 22, 22, 22, 22, 22, 22, 21, 21, 22, 22, 22, 22, 22, 22, 21,
  21, 22, 22, 22, 22, 22, 22, 21, 20, 21, 21, 21, 21, 21, 21, 20
};

#else // if defined(USE_32BIT_ATTACKS)

const uint64_t RMult[64] = {
  0xa8002c000108020ULL, 0x4440200140003000ULL, 0x8080200010011880ULL,
  0x380180080141000ULL, 0x1a00060008211044ULL, 0x410001000a0c0008ULL,
  0x9500060004008100ULL, 0x100024284a20700ULL, 0x802140008000ULL,
  0x80c01002a00840ULL, 0x402004282011020ULL, 0x9862000820420050ULL,
  0x1001448011100ULL, 0x6432800200800400ULL, 0x40100010002000cULL,
  0x2800d0010c080ULL, 0x90c0008000803042ULL, 0x4010004000200041ULL,
  0x3010010200040ULL, 0xa40828028001000ULL, 0x123010008000430ULL,
  0x24008004020080ULL, 0x60040001104802ULL, 0x582200028400d1ULL,
  0x4000802080044000ULL, 0x408208200420308ULL, 0x610038080102000ULL,
  0x3601000900100020ULL, 0x80080040180ULL, 0xc2020080040080ULL,
  0x80084400100102ULL, 0x4022408200014401ULL, 0x40052040800082ULL,
  0xb08200280804000ULL, 0x8a80a008801000ULL, 0x4000480080801000ULL,
  0x911808800801401ULL, 0x822a003002001894ULL, 0x401068091400108aULL,
  0x4a10a00004cULL, 0x2000800640008024ULL, 0x1486408102020020ULL,
  0x100a000d50041ULL, 0x810050020b0020ULL, 0x204000800808004ULL,
  0x20048100a000cULL, 0x112000831020004ULL, 0x9000040810002ULL,
  0x440490200208200ULL, 0x8910401000200040ULL, 0x6404200050008480ULL,
  0x4b824a2010010100ULL, 0x4080801810c0080ULL, 0x400802a0080ULL,
  0x8224080110026400ULL, 0x40002c4104088200ULL, 0x1002100104a0282ULL,
  0x1208400811048021ULL, 0x3201014a40d02001ULL, 0x5100019200501ULL,
  0x101000208001005ULL, 0x2008450080702ULL, 0x1002080301d00cULL,
  0x410201ce5c030092ULL
};

const int RShift[64] = {
  52, 53, 53, 53, 53, 53, 53, 52, 53, 54, 54, 54, 54, 54, 54, 53,
  53, 54, 54, 54, 54, 54, 54, 53, 53, 54, 54, 54, 54, 54, 54, 53,
  53, 54, 54, 54, 54, 54, 54, 53, 53, 54, 54, 54, 54, 54, 54, 53,
  53, 54, 54, 54, 54, 54, 54, 53, 52, 53, 53, 53, 53, 53, 53, 52
};

#endif // defined(USE_32BIT_ATTACKS)

#if !defined(USE_COMPACT_ROOK_ATTACKS)
Bitboard RMask[64];
int RAttackIndex[64];
Bitboard RAttacks[0x19000];
#endif

#if defined(USE_32BIT_ATTACKS)

const uint64_t BMult[64] = {
  0x54142844c6a22981ULL, 0x710358a6ea25c19eULL, 0x704f746d63a4a8dcULL,
  0xbfed1a0b80f838c5ULL, 0x90561d5631e62110ULL, 0x2804260376e60944ULL,
  0x84a656409aa76871ULL, 0xf0267f64c28b6197ULL, 0x70764ebb762f0585ULL,
  0x92aa09e0cfe161deULL, 0x41ee1f6bb266f60eULL, 0xddcbf04f6039c444ULL,
  0x5a3fab7bac0d988aULL, 0xd3727877fa4eaa03ULL, 0xd988402d868ddaaeULL,
  0x812b291afa075c7cULL, 0x94faf987b685a932ULL, 0x3ed867d8470d08dbULL,
  0x92517660b8901de8ULL, 0x2d97e43e058814b4ULL, 0x880a10c220b25582ULL,
  0xc7c6520d1f1a0477ULL, 0xdbfc7fbcd7656aa6ULL, 0x78b1b9bfb1a2b84fULL,
  0x2f20037f112a0bc1ULL, 0x657171ea2269a916ULL, 0xc08302b07142210eULL,
  0x880a4403064080bULL, 0x3602420842208c00ULL, 0x852800dc7e0b6602ULL,
  0x595a3fbbaa0f03b2ULL, 0x9f01411558159d5eULL, 0x2b4a4a5f88b394f2ULL,
  0x4afcbffc292dd03aULL, 0x4a4094a3b3f10522ULL, 0xb06f00b491f30048ULL,
  0xd5b3820280d77004ULL, 0x8b2e01e7c8e57a75ULL, 0x2d342794e886c2e6ULL,
  0xc302c410cde21461ULL, 0x111f426f1379c274ULL, 0xe0569220abb31588ULL,
  0x5026d3064d453324ULL, 0xe2076040c343cd8aULL, 0x93efd1e1738021eeULL,
  0xb680804bed143132ULL, 0x44e361b21986944cULL, 0x44c60170ef5c598cULL,
  0xf4da475c195c9c94ULL, 0xa3afbb5f72060b1dULL, 0xbc75f410e41c4ffcULL,
  0xb51c099390520922ULL, 0x902c011f8f8ec368ULL, 0x950b56b3d6f5490aULL,
  0x3909e0635bf202d0ULL, 0x5744f90206ec10ccULL, 0xdc59fd76317abbc1ULL,
  0x881c7c67fcbfc4f6ULL, 0x47ca41e7e440d423ULL, 0xeb0c88112048d004ULL,
  0x51c60e04359aef1aULL, 0x1aa1fe0e957a5554ULL, 0xdd9448db4f5e3104ULL,
  0xdc01f6dca4bebbdcULL,
};

const int BShift[64] = {
  26, 27, 27, 27, 27, 27, 27, 26, 27, 27, 27, 27, 27, 27, 27, 27,
  27, 27, 25, 25, 25, 25, 27, 27, 27, 27, 25, 23, 23, 25, 27, 27,
  27, 27, 25, 23, 23, 25, 27, 27, 27, 27, 25, 25, 25, 25, 27, 27,
  27, 27, 27, 27, 27, 27, 27, 27, 26, 27, 27, 27, 27, 27, 27, 26
};

#else // if defined(USE_32BIT_ATTACKS)

const uint64_t BMult[64] = {
  0x440049104032280ULL, 0x1021023c82008040ULL, 0x404040082000048ULL,
  0x48c4440084048090ULL, 0x2801104026490000ULL, 0x4100880442040800ULL,
  0x181011002e06040ULL, 0x9101004104200e00ULL, 0x1240848848310401ULL,
  0x2000142828050024ULL, 0x1004024d5000ULL, 0x102044400800200ULL,
  0x8108108820112000ULL, 0xa880818210c00046ULL, 0x4008008801082000ULL,
  0x60882404049400ULL, 0x104402004240810ULL, 0xa002084250200ULL,
  0x100b0880801100ULL, 0x4080201220101ULL, 0x44008080a00000ULL,
  0x202200842000ULL, 0x5006004882d00808ULL, 0x200045080802ULL,
  0x86100020200601ULL, 0xa802080a20112c02ULL, 0x80411218080900ULL,
  0x200a0880080a0ULL, 0x9a01010000104000ULL, 0x28008003100080ULL,
  0x211021004480417ULL, 0x401004188220806ULL, 0x825051400c2006ULL,
  0x140c0210943000ULL, 0x242800300080ULL, 0xc2208120080200ULL,
  0x2430008200002200ULL, 0x1010100112008040ULL, 0x8141050100020842ULL,
  0x822081014405ULL, 0x800c049e40400804ULL, 0x4a0404028a000820ULL,
  0x22060201041200ULL, 0x360904200840801ULL, 0x881a08208800400ULL,
  0x60202c00400420ULL, 0x1204440086061400ULL, 0x8184042804040ULL,
  0x64040315300400ULL, 0xc01008801090a00ULL, 0x808010401140c00ULL,
  0x4004830c2020040ULL, 0x80005002020054ULL, 0x40000c14481a0490ULL,
  0x10500101042048ULL, 0x1010100200424000ULL, 0x640901901040ULL,
  0xa0201014840ULL, 0x840082aa011002ULL, 0x10010840084240aULL,
  0x420400810420608ULL, 0x8d40230408102100ULL, 0x4a00200612222409ULL,
  0xa08520292120600ULL
};

const int BShift[64] = {
  58, 59, 59, 59, 59, 59, 59, 58, 59, 59, 59, 59, 59, 59, 59, 59,
  59, 59, 57, 57, 57, 57, 59, 59, 59, 59, 57, 55, 55, 57, 59, 59,
  59, 59, 57, 55, 55, 57, 59, 59, 59, 59, 57, 57, 57, 57, 59, 59,
  59, 59, 59, 59, 59, 59, 59, 59, 58, 59, 59, 59, 59, 59, 59, 58
};

#endif // defined(USE_32BIT_ATTACKS)

Bitboard BMask[64];
int BAttackIndex[64];
Bitboard BAttacks[0x1480];

Bitboard SetMaskBB[64];
Bitboard ClearMaskBB[64];

Bitboard StepAttackBB[16][64];
Bitboard RayBB[64][8];
Bitboard BetweenBB[64][64];

Bitboard PassedPawnMask[2][64];
Bitboard OutpostMask[2][64];

Bitboard BishopPseudoAttacks[64];
Bitboard RookPseudoAttacks[64];
Bitboard QueenPseudoAttacks[64];


////
//// Local definitions
////

namespace {
  void init_masks();
  void init_ray_bitboards();
  void init_attacks();
  void init_between_bitboards();
  Bitboard sliding_attacks(int sq, Bitboard block, int dirs, int deltas[][2],
                           int fmin, int fmax, int rmin, int rmax);
  Bitboard index_to_bitboard(int index, Bitboard mask);
  void init_sliding_attacks(Bitboard attacks[],
                            int attackIndex[], Bitboard mask[],
                            const int shift[2], const Bitboard mult[],
                            int deltas[][2]);
  void init_pseudo_attacks();
#if defined(USE_COMPACT_ROOK_ATTACKS)
  void init_file_and_rank_attacks();
#endif
}


////
//// Functions
////

/// print_bitboard() prints a bitboard in an easily readable format to the
/// standard output.  This is sometimes useful for debugging.

void print_bitboard(Bitboard b) {
  for(Rank r = RANK_8; r >= RANK_1; r--) {
    std::cout << "+---+---+---+---+---+---+---+---+" << std::endl;
    for(File f = FILE_A; f <= FILE_H; f++)
      std::cout << "| " << (bit_is_set(b, make_square(f, r))? 'X' : ' ') << ' ';
    std::cout << "|" << std::endl;
  }
  std::cout << "+---+---+---+---+---+---+---+---+" << std::endl;
}


/// init_bitboards() initializes various bitboard arrays.  It is called during
/// program initialization.

void init_bitboards() {
  int rookDeltas[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
  int bishopDeltas[4][2] = {{1,1},{-1,1},{1,-1},{-1,-1}};
  init_masks();
  init_ray_bitboards();
  init_attacks();
  init_between_bitboards();
#if defined(USE_COMPACT_ROOK_ATTACKS)
  init_file_and_rank_attacks();
#else
  init_sliding_attacks(RAttacks, RAttackIndex, RMask, RShift,
                       RMult, rookDeltas);
#endif
  init_sliding_attacks(BAttacks, BAttackIndex, BMask, BShift,
                       BMult, bishopDeltas);
  init_pseudo_attacks();
}


#if defined(USE_FOLDED_BITSCAN)

static const int BitTable[64] = {
  63, 30, 3, 32, 25, 41, 22, 33, 15, 50, 42, 13, 11, 53, 19, 34, 61, 29, 2,
  51, 21, 43, 45, 10, 18, 47, 1, 54, 9, 57, 0, 35, 62, 31, 40, 4, 49, 5, 52,
  26, 60, 6, 23, 44, 46, 27, 56, 16, 7, 39, 48, 24, 59, 14, 12, 55, 38, 28,
  58, 20, 37, 17, 36, 8
};


/// first_1() finds the least significant nonzero bit in a nonzero bitboard.

Square first_1(Bitboard b) {
  b ^= (b - 1);
  uint32_t fold = int(b) ^ int(b >> 32);
  return Square(BitTable[(fold * 0x783a9b23) >> 26]);
}


/// pop_1st_bit() finds and clears the least significant nonzero bit in a
/// nonzero bitboard.

#if defined(USE_32BIT_ATTACKS)

// Use type-punning
union b_union {

    Bitboard b;
    struct {
        uint32_t l;
        uint32_t h;
    };
};

// WARNING: Needs -fno-strict-aliasing compiler option
Square pop_1st_bit(Bitboard *bb) {

  b_union u;
  uint32_t b;

  u.b = *bb;

  if (u.l)
  {
      b = u.l;
      *((uint32_t*)bb) = b & (b - 1);
      b ^= (b - 1);
  }
  else
  {
      b = u.h;
      *((uint32_t*)bb+1) = b & (b - 1); // Little endian only?
      b = ~(b ^ (b - 1));
  }
  return Square(BitTable[(b * 0x783a9b23) >> 26]);
}

#else

Square pop_1st_bit(Bitboard *b) {
  Bitboard bb = *b ^ (*b - 1);
  uint32_t fold = int(bb) ^ int(bb >> 32);
  *b &= (*b - 1);
  return Square(BitTable[(fold * 0x783a9b23) >> 26]);
}

#endif

#else

static const int BitTable[64] = {
  0, 1, 2, 7, 3, 13, 8, 19, 4, 25, 14, 28, 9, 34, 20, 40, 5, 17, 26, 38, 15,
  46, 29, 48, 10, 31, 35, 54, 21, 50, 41, 57, 63, 6, 12, 18, 24, 27, 33, 39,
  16, 37, 45, 47, 30, 53, 49, 56, 62, 11, 23, 32, 36, 44, 52, 55, 61, 22, 43,
  51, 60, 42, 59, 58
};


/// first_1() finds the least significant nonzero bit in a nonzero bitboard.

Square first_1(Bitboard b) {
  return Square(BitTable[((b & -b) * 0x218a392cd3d5dbfULL) >> 58]);
}


/// pop_1st_bit() finds and clears the least significant nonzero bit in a
/// nonzero bitboard.

Square pop_1st_bit(Bitboard *b) {
  Bitboard bb = *b;
  *b &= (*b - 1);
  return Square(BitTable[((bb & -bb) * 0x218a392cd3d5dbfULL) >> 58]);
}

#endif // defined(USE_FOLDED_BITSCAN)


namespace {

  // All functions below are used to precompute various bitboards during
  // program initialization.  Some of the functions may be difficult to
  // understand, but they all seem to work correctly, and it should never
  // be necessary to touch any of them.

  void init_masks() {
    for(Square s = SQ_A1; s <= SQ_H8; s++) {
      SetMaskBB[s] = (1ULL << s);
      ClearMaskBB[s] = ~SetMaskBB[s];
    }
    for(Color c = WHITE; c <= BLACK; c++)
      for(Square s = SQ_A1; s <= SQ_H8; s++) {
        PassedPawnMask[c][s] =
          in_front_bb(c, s) & this_and_neighboring_files_bb(s);
        OutpostMask[c][s] = in_front_bb(c, s) & neighboring_files_bb(s);
      }
  }


  void init_ray_bitboards() {
    int d[8] = {1, -1, 16, -16, 17, -17, 15, -15};
    for(int i = 0; i < 128; i = i + 9 & ~8) {
      for(int j = 0; j < 8; j++) {
        RayBB[(i&7)|((i>>4)<<3)][j] = EmptyBoardBB;
        for(int k = i + d[j]; (k & 0x88) == 0; k += d[j])
          set_bit(&(RayBB[(i&7)|((i>>4)<<3)][j]), Square((k&7)|((k>>4)<<3)));
      }
    }
  }


  void init_attacks() {
    int i, j, k, l;
    int step[16][8] =  {
      {0},
      {7,9,0}, {17,15,10,6,-6,-10,-15,-17}, {9,7,-7,-9,0}, {8,1,-1,-8,0},
      {9,7,-7,-9,8,1,-1,-8}, {9,7,-7,-9,8,1,-1,-8}, {0}, {0},
      {-7,-9,0}, {17,15,10,6,-6,-10,-15,-17}, {9,7,-7,-9,0}, {8,1,-1,-8,0},
      {9,7,-7,-9,8,1,-1,-8}, {9,7,-7,-9,8,1,-1,-8}
    };

    for(i = 0; i < 64; i++) {
      for(j = 0; j <= int(BK); j++) {
        StepAttackBB[j][i] = EmptyBoardBB;
        for(k = 0; k < 8 && step[j][k] != 0; k++) {
          l = i + step[j][k];
          if(l >= 0 && l < 64 && abs((i&7) - (l&7)) < 3)
            StepAttackBB[j][i] |= (1ULL << l);
        }
      }
    }
  }


  Bitboard sliding_attacks(int sq, Bitboard block, int dirs, int deltas[][2],
                           int fmin=0, int fmax=7, int rmin=0, int rmax=7) {
    Bitboard result = 0ULL;
    int rk = sq / 8, fl = sq % 8, r, f, i;
    for(i = 0; i < dirs; i++) {
      int dx = deltas[i][0], dy = deltas[i][1];
      for(f = fl+dx, r = rk+dy;
          (dx==0 || (f>=fmin && f<=fmax)) && (dy==0 || (r>=rmin && r<=rmax));
          f += dx, r += dy) {
        result |= (1ULL << (f + r*8));
        if(block & (1ULL << (f + r*8))) break;
      }
    }
    return result;
  }


  void init_between_bitboards() {
    SquareDelta step[8] = {
      DELTA_E, DELTA_W, DELTA_N, DELTA_S, DELTA_NE, DELTA_SW, DELTA_NW, DELTA_SE
    };
    SignedDirection d;
    for(Square s1 = SQ_A1; s1 <= SQ_H8; s1++)
      for(Square s2 = SQ_A1; s2 <= SQ_H8; s2++) {
        BetweenBB[s1][s2] = EmptyBoardBB;
        d = signed_direction_between_squares(s1, s2);
        if(d != SIGNED_DIR_NONE)
          for(Square s3 = s1 + step[d]; s3 != s2; s3 += step[d])
            set_bit(&(BetweenBB[s1][s2]), s3);
      }
  }


  Bitboard index_to_bitboard(int index, Bitboard mask) {
    int i, j, bits = count_1s(mask);
    Bitboard result = 0ULL;
    for(i = 0; i < bits; i++) {
      j = pop_1st_bit(&mask);
      if(index & (1 << i)) result |= (1ULL << j);
    }
    return result;
  }


  void init_sliding_attacks(Bitboard attacks[],
                            int attackIndex[], Bitboard mask[],
                            const int shift[2], const Bitboard mult[],
                            int deltas[][2]) {
    int i, j, k, index = 0;
    Bitboard b;
    for(i = 0; i < 64; i++) {
      attackIndex[i] = index;
      mask[i] = sliding_attacks(i, 0ULL, 4, deltas, 1, 6, 1, 6);
      j = (1 << (64 - shift[i]));
      for(k = 0; k < j; k++) {
#if defined(USE_32BIT_ATTACKS)
        b = index_to_bitboard(k, mask[i]);
        attacks[index +
                 (unsigned(int(b) * int(mult[i]) ^
                           int(b >> 32) * int(mult[i] >> 32))
                  >> shift[i])] =
          sliding_attacks(i, b, 4, deltas);
#else
        b = index_to_bitboard(k, mask[i]);
        attacks[index + ((b * mult[i]) >> shift[i])] =
          sliding_attacks(i, b, 4, deltas);
#endif
      }
      index += j;
    }
  }


  void init_pseudo_attacks() {
    Square s;
    for(s = SQ_A1; s <= SQ_H8; s++) {
      BishopPseudoAttacks[s] = bishop_attacks_bb(s, EmptyBoardBB);
      RookPseudoAttacks[s] = rook_attacks_bb(s, EmptyBoardBB);
      QueenPseudoAttacks[s] = queen_attacks_bb(s, EmptyBoardBB);
    }
  }

#if defined(USE_COMPACT_ROOK_ATTACKS)
  void init_file_and_rank_attacks() {
    int i, j, k, l, m, s;
    Bitboard b1, b2;
    for(i = 0; i < 64; i++) {

      for(m = 0; m <= 1; m++) {
        b1 = 0ULL;
        for(j = 0; j < 6; j++) if(i & (1<<j)) b1 |= (1ULL << ((j+1)*(1+m*7)));
        for(j = 0; j < 8; j++) {
          b2 = 0ULL;
          for(k = 0, s = 1; k < 2; k++, s *= -1) {
            for(l = j+s; l >= 0 && l <= 7; l += s) {
              b2 |= (m? RankBB[l] : FileBB[l]);
              if(b1 & (1ULL << (l*(1+m*7)))) break;
            }
          }
          if(m) FileAttacks[j][(b1*0xd6e8802041d0c441ULL) >> 58] = b2;
          else RankAttacks[j][i] = b2;
        }
      }
    }
  }
#endif // defined(USE_COMPACT_ROOK_ATTACKS)

}

// ======== book.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


/*
  The code in this file is based on the opening book code in PolyGlot
  by Fabien Letouzey.  PolyGlot is available under the GNU General
  Public License, and can be downloaded from http://wbec-ridderkerk.nl
*/


////
//// Includes
////

#include <cassert>

// ---- begin book.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


/*
  The code in this file is based on the opening book code in PolyGlot
  by Fabien Letouzey.  PolyGlot is available under the GNU General
  Public License, and can be downloaded from http://wbec-ridderkerk.nl
*/


#if !defined(BOOK_H_INCLUDED)
#define BOOK_H_INCLUDED


////
//// Includes
////

#include <fstream>
#include <string>



////
//// Types
////

struct BookEntry {
  uint64_t key;
  uint16_t move;
  uint16_t count;
  uint16_t n;
  uint16_t sum;
};

class Book {

public:
  // Constructors
  Book();

  // Open and close book files
  void open(const std::string &fName);
  void close();

  // Testing if a book is opened
  bool is_open() const;

  // The file name of the currently active book
  const std::string file_name() const;

  // Get a book move for a given position
  Move get_move(const Position &pos) const;

private:
  int find_key(uint64_t key) const;
  void read_entry(BookEntry &entry, int n) const;

  std::string fileName;
  mutable std::ifstream bookFile;
  int bookSize;
};


////
//// Global variables
////

extern Book OpeningBook;


#endif // !defined(BOOK_H_INCLUDED)
// ---- end book.h ----
// ---- begin mersenne.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(MERSENNE_H_INCLUDED)
#define MERSENNE_H_INCLUDED

////
//// Includes
////



////
//// Prototypes
////

extern uint32_t genrand_int32(void);
extern uint64_t genrand_int64(void);
extern void init_mersenne(void);


#endif // !defined(MERSENNE_H_INCLUDED)
// ---- end mersenne.h ----


////
//// Global variables
////

Book OpeningBook;


////
//// Local definitions
////

namespace {

  /// Random numbers from PolyGlot, used to compute book hash keys.

  const uint64_t Random64[781] = {
    0x9D39247E33776D41ULL, 0x2AF7398005AAA5C7ULL, 0x44DB015024623547ULL,
    0x9C15F73E62A76AE2ULL, 0x75834465489C0C89ULL, 0x3290AC3A203001BFULL,
    0x0FBBAD1F61042279ULL, 0xE83A908FF2FB60CAULL, 0x0D7E765D58755C10ULL,
    0x1A083822CEAFE02DULL, 0x9605D5F0E25EC3B0ULL, 0xD021FF5CD13A2ED5ULL,
    0x40BDF15D4A672E32ULL, 0x011355146FD56395ULL, 0x5DB4832046F3D9E5ULL,
    0x239F8B2D7FF719CCULL, 0x05D1A1AE85B49AA1ULL, 0x679F848F6E8FC971ULL,
    0x7449BBFF801FED0BULL, 0x7D11CDB1C3B7ADF0ULL, 0x82C7709E781EB7CCULL,
    0xF3218F1C9510786CULL, 0x331478F3AF51BBE6ULL, 0x4BB38DE5E7219443ULL,
    0xAA649C6EBCFD50FCULL, 0x8DBD98A352AFD40BULL, 0x87D2074B81D79217ULL,
    0x19F3C751D3E92AE1ULL, 0xB4AB30F062B19ABFULL, 0x7B0500AC42047AC4ULL,
    0xC9452CA81A09D85DULL, 0x24AA6C514DA27500ULL, 0x4C9F34427501B447ULL,
    0x14A68FD73C910841ULL, 0xA71B9B83461CBD93ULL, 0x03488B95B0F1850FULL,
    0x637B2B34FF93C040ULL, 0x09D1BC9A3DD90A94ULL, 0x3575668334A1DD3BULL,
    0x735E2B97A4C45A23ULL, 0x18727070F1BD400BULL, 0x1FCBACD259BF02E7ULL,
    0xD310A7C2CE9B6555ULL, 0xBF983FE0FE5D8244ULL, 0x9F74D14F7454A824ULL,
    0x51EBDC4AB9BA3035ULL, 0x5C82C505DB9AB0FAULL, 0xFCF7FE8A3430B241ULL,
    0x3253A729B9BA3DDEULL, 0x8C74C368081B3075ULL, 0xB9BC6C87167C33E7ULL,
    0x7EF48F2B83024E20ULL, 0x11D505D4C351BD7FULL, 0x6568FCA92C76A243ULL,
    0x4DE0B0F40F32A7B8ULL, 0x96D693460CC37E5DULL, 0x42E240CB63689F2FULL,
    0x6D2BDCDAE2919661ULL, 0x42880B0236E4D951ULL, 0x5F0F4A5898171BB6ULL,
    0x39F890F579F92F88ULL, 0x93C5B5F47356388BULL, 0x63DC359D8D231B78ULL,
    0xEC16CA8AEA98AD76ULL, 0x5355F900C2A82DC7ULL, 0x07FB9F855A997142ULL,
    0x5093417AA8A7ED5EULL, 0x7BCBC38DA25A7F3CULL, 0x19FC8A768CF4B6D4ULL,
    0x637A7780DECFC0D9ULL, 0x8249A47AEE0E41F7ULL, 0x79AD695501E7D1E8ULL,
    0x14ACBAF4777D5776ULL, 0xF145B6BECCDEA195ULL, 0xDABF2AC8201752FCULL,
    0x24C3C94DF9C8D3F6ULL, 0xBB6E2924F03912EAULL, 0x0CE26C0B95C980D9ULL,
    0xA49CD132BFBF7CC4ULL, 0xE99D662AF4243939ULL, 0x27E6AD7891165C3FULL,
    0x8535F040B9744FF1ULL, 0x54B3F4FA5F40D873ULL, 0x72B12C32127FED2BULL,
    0xEE954D3C7B411F47ULL, 0x9A85AC909A24EAA1ULL, 0x70AC4CD9F04F21F5ULL,
    0xF9B89D3E99A075C2ULL, 0x87B3E2B2B5C907B1ULL, 0xA366E5B8C54F48B8ULL,
    0xAE4A9346CC3F7CF2ULL, 0x1920C04D47267BBDULL, 0x87BF02C6B49E2AE9ULL,
    0x092237AC237F3859ULL, 0xFF07F64EF8ED14D0ULL, 0x8DE8DCA9F03CC54EULL,
    0x9C1633264DB49C89ULL, 0xB3F22C3D0B0B38EDULL, 0x390E5FB44D01144BULL,
    0x5BFEA5B4712768E9ULL, 0x1E1032911FA78984ULL, 0x9A74ACB964E78CB3ULL,
    0x4F80F7A035DAFB04ULL, 0x6304D09A0B3738C4ULL, 0x2171E64683023A08ULL,
    0x5B9B63EB9CEFF80CULL, 0x506AACF489889342ULL, 0x1881AFC9A3A701D6ULL,
    0x6503080440750644ULL, 0xDFD395339CDBF4A7ULL, 0xEF927DBCF00C20F2ULL,
    0x7B32F7D1E03680ECULL, 0xB9FD7620E7316243ULL, 0x05A7E8A57DB91B77ULL,
    0xB5889C6E15630A75ULL, 0x4A750A09CE9573F7ULL, 0xCF464CEC899A2F8AULL,
    0xF538639CE705B824ULL, 0x3C79A0FF5580EF7FULL, 0xEDE6C87F8477609DULL,
    0x799E81F05BC93F31ULL, 0x86536B8CF3428A8CULL, 0x97D7374C60087B73ULL,
    0xA246637CFF328532ULL, 0x043FCAE60CC0EBA0ULL, 0x920E449535DD359EULL,
    0x70EB093B15B290CCULL, 0x73A1921916591CBDULL, 0x56436C9FE1A1AA8DULL,
    0xEFAC4B70633B8F81ULL, 0xBB215798D45DF7AFULL, 0x45F20042F24F1768ULL,
    0x930F80F4E8EB7462ULL, 0xFF6712FFCFD75EA1ULL, 0xAE623FD67468AA70ULL,
    0xDD2C5BC84BC8D8FCULL, 0x7EED120D54CF2DD9ULL, 0x22FE545401165F1CULL,
    0xC91800E98FB99929ULL, 0x808BD68E6AC10365ULL, 0xDEC468145B7605F6ULL,
    0x1BEDE3A3AEF53302ULL, 0x43539603D6C55602ULL, 0xAA969B5C691CCB7AULL,
    0xA87832D392EFEE56ULL, 0x65942C7B3C7E11AEULL, 0xDED2D633CAD004F6ULL,
    0x21F08570F420E565ULL, 0xB415938D7DA94E3CULL, 0x91B859E59ECB6350ULL,
    0x10CFF333E0ED804AULL, 0x28AED140BE0BB7DDULL, 0xC5CC1D89724FA456ULL,
    0x5648F680F11A2741ULL, 0x2D255069F0B7DAB3ULL, 0x9BC5A38EF729ABD4ULL,
    0xEF2F054308F6A2BCULL, 0xAF2042F5CC5C2858ULL, 0x480412BAB7F5BE2AULL,
    0xAEF3AF4A563DFE43ULL, 0x19AFE59AE451497FULL, 0x52593803DFF1E840ULL,
    0xF4F076E65F2CE6F0ULL, 0x11379625747D5AF3ULL, 0xBCE5D2248682C115ULL,
    0x9DA4243DE836994FULL, 0x066F70B33FE09017ULL, 0x4DC4DE189B671A1CULL,
    0x51039AB7712457C3ULL, 0xC07A3F80C31FB4B4ULL, 0xB46EE9C5E64A6E7CULL,
    0xB3819A42ABE61C87ULL, 0x21A007933A522A20ULL, 0x2DF16F761598AA4FULL,
    0x763C4A1371B368FDULL, 0xF793C46702E086A0ULL, 0xD7288E012AEB8D31ULL,
    0xDE336A2A4BC1C44BULL, 0x0BF692B38D079F23ULL, 0x2C604A7A177326B3ULL,
    0x4850E73E03EB6064ULL, 0xCFC447F1E53C8E1BULL, 0xB05CA3F564268D99ULL,
    0x9AE182C8BC9474E8ULL, 0xA4FC4BD4FC5558CAULL, 0xE755178D58FC4E76ULL,
    0x69B97DB1A4C03DFEULL, 0xF9B5B7C4ACC67C96ULL, 0xFC6A82D64B8655FBULL,
    0x9C684CB6C4D24417ULL, 0x8EC97D2917456ED0ULL, 0x6703DF9D2924E97EULL,
    0xC547F57E42A7444EULL, 0x78E37644E7CAD29EULL, 0xFE9A44E9362F05FAULL,
    0x08BD35CC38336615ULL, 0x9315E5EB3A129ACEULL, 0x94061B871E04DF75ULL,
    0xDF1D9F9D784BA010ULL, 0x3BBA57B68871B59DULL, 0xD2B7ADEEDED1F73FULL,
    0xF7A255D83BC373F8ULL, 0xD7F4F2448C0CEB81ULL, 0xD95BE88CD210FFA7ULL,
    0x336F52F8FF4728E7ULL, 0xA74049DAC312AC71ULL, 0xA2F61BB6E437FDB5ULL,
    0x4F2A5CB07F6A35B3ULL, 0x87D380BDA5BF7859ULL, 0x16B9F7E06C453A21ULL,
    0x7BA2484C8A0FD54EULL, 0xF3A678CAD9A2E38CULL, 0x39B0BF7DDE437BA2ULL,
    0xFCAF55C1BF8A4424ULL, 0x18FCF680573FA594ULL, 0x4C0563B89F495AC3ULL,
    0x40E087931A00930DULL, 0x8CFFA9412EB642C1ULL, 0x68CA39053261169FULL,
    0x7A1EE967D27579E2ULL, 0x9D1D60E5076F5B6FULL, 0x3810E399B6F65BA2ULL,
    0x32095B6D4AB5F9B1ULL, 0x35CAB62109DD038AULL, 0xA90B24499FCFAFB1ULL,
    0x77A225A07CC2C6BDULL, 0x513E5E634C70E331ULL, 0x4361C0CA3F692F12ULL,
    0xD941ACA44B20A45BULL, 0x528F7C8602C5807BULL, 0x52AB92BEB9613989ULL,
    0x9D1DFA2EFC557F73ULL, 0x722FF175F572C348ULL, 0x1D1260A51107FE97ULL,
    0x7A249A57EC0C9BA2ULL, 0x04208FE9E8F7F2D6ULL, 0x5A110C6058B920A0ULL,
    0x0CD9A497658A5698ULL, 0x56FD23C8F9715A4CULL, 0x284C847B9D887AAEULL,
    0x04FEABFBBDB619CBULL, 0x742E1E651C60BA83ULL, 0x9A9632E65904AD3CULL,
    0x881B82A13B51B9E2ULL, 0x506E6744CD974924ULL, 0xB0183DB56FFC6A79ULL,
    0x0ED9B915C66ED37EULL, 0x5E11E86D5873D484ULL, 0xF678647E3519AC6EULL,
    0x1B85D488D0F20CC5ULL, 0xDAB9FE6525D89021ULL, 0x0D151D86ADB73615ULL,
    0xA865A54EDCC0F019ULL, 0x93C42566AEF98FFBULL, 0x99E7AFEABE000731ULL,
    0x48CBFF086DDF285AULL, 0x7F9B6AF1EBF78BAFULL, 0x58627E1A149BBA21ULL,
    0x2CD16E2ABD791E33ULL, 0xD363EFF5F0977996ULL, 0x0CE2A38C344A6EEDULL,
    0x1A804AADB9CFA741ULL, 0x907F30421D78C5DEULL, 0x501F65EDB3034D07ULL,
    0x37624AE5A48FA6E9ULL, 0x957BAF61700CFF4EULL, 0x3A6C27934E31188AULL,
    0xD49503536ABCA345ULL, 0x088E049589C432E0ULL, 0xF943AEE7FEBF21B8ULL,
    0x6C3B8E3E336139D3ULL, 0x364F6FFA464EE52EULL, 0xD60F6DCEDC314222ULL,
    0x56963B0DCA418FC0ULL, 0x16F50EDF91E513AFULL, 0xEF1955914B609F93ULL,
    0x565601C0364E3228ULL, 0xECB53939887E8175ULL, 0xBAC7A9A18531294BULL,
    0xB344C470397BBA52ULL, 0x65D34954DAF3CEBDULL, 0xB4B81B3FA97511E2ULL,
    0xB422061193D6F6A7ULL, 0x071582401C38434DULL, 0x7A13F18BBEDC4FF5ULL,
    0xBC4097B116C524D2ULL, 0x59B97885E2F2EA28ULL, 0x99170A5DC3115544ULL,
    0x6F423357E7C6A9F9ULL, 0x325928EE6E6F8794ULL, 0xD0E4366228B03343ULL,
    0x565C31F7DE89EA27ULL, 0x30F5611484119414ULL, 0xD873DB391292ED4FULL,
    0x7BD94E1D8E17DEBCULL, 0xC7D9F16864A76E94ULL, 0x947AE053EE56E63CULL,
    0xC8C93882F9475F5FULL, 0x3A9BF55BA91F81CAULL, 0xD9A11FBB3D9808E4ULL,
    0x0FD22063EDC29FCAULL, 0xB3F256D8ACA0B0B9ULL, 0xB03031A8B4516E84ULL,
    0x35DD37D5871448AFULL, 0xE9F6082B05542E4EULL, 0xEBFAFA33D7254B59ULL,
    0x9255ABB50D532280ULL, 0xB9AB4CE57F2D34F3ULL, 0x693501D628297551ULL,
    0xC62C58F97DD949BFULL, 0xCD454F8F19C5126AULL, 0xBBE83F4ECC2BDECBULL,
    0xDC842B7E2819E230ULL, 0xBA89142E007503B8ULL, 0xA3BC941D0A5061CBULL,
    0xE9F6760E32CD8021ULL, 0x09C7E552BC76492FULL, 0x852F54934DA55CC9ULL,
    0x8107FCCF064FCF56ULL, 0x098954D51FFF6580ULL, 0x23B70EDB1955C4BFULL,
    0xC330DE426430F69DULL, 0x4715ED43E8A45C0AULL, 0xA8D7E4DAB780A08DULL,
    0x0572B974F03CE0BBULL, 0xB57D2E985E1419C7ULL, 0xE8D9ECBE2CF3D73FULL,
    0x2FE4B17170E59750ULL, 0x11317BA87905E790ULL, 0x7FBF21EC8A1F45ECULL,
    0x1725CABFCB045B00ULL, 0x964E915CD5E2B207ULL, 0x3E2B8BCBF016D66DULL,
    0xBE7444E39328A0ACULL, 0xF85B2B4FBCDE44B7ULL, 0x49353FEA39BA63B1ULL,
    0x1DD01AAFCD53486AULL, 0x1FCA8A92FD719F85ULL, 0xFC7C95D827357AFAULL,
    0x18A6A990C8B35EBDULL, 0xCCCB7005C6B9C28DULL, 0x3BDBB92C43B17F26ULL,
    0xAA70B5B4F89695A2ULL, 0xE94C39A54A98307FULL, 0xB7A0B174CFF6F36EULL,
    0xD4DBA84729AF48ADULL, 0x2E18BC1AD9704A68ULL, 0x2DE0966DAF2F8B1CULL,
    0xB9C11D5B1E43A07EULL, 0x64972D68DEE33360ULL, 0x94628D38D0C20584ULL,
    0xDBC0D2B6AB90A559ULL, 0xD2733C4335C6A72FULL, 0x7E75D99D94A70F4DULL,
    0x6CED1983376FA72BULL, 0x97FCAACBF030BC24ULL, 0x7B77497B32503B12ULL,
    0x8547EDDFB81CCB94ULL, 0x79999CDFF70902CBULL, 0xCFFE1939438E9B24ULL,
    0x829626E3892D95D7ULL, 0x92FAE24291F2B3F1ULL, 0x63E22C147B9C3403ULL,
    0xC678B6D860284A1CULL, 0x5873888850659AE7ULL, 0x0981DCD296A8736DULL,
    0x9F65789A6509A440ULL, 0x9FF38FED72E9052FULL, 0xE479EE5B9930578CULL,
    0xE7F28ECD2D49EECDULL, 0x56C074A581EA17FEULL, 0x5544F7D774B14AEFULL,
    0x7B3F0195FC6F290FULL, 0x12153635B2C0CF57ULL, 0x7F5126DBBA5E0CA7ULL,
    0x7A76956C3EAFB413ULL, 0x3D5774A11D31AB39ULL, 0x8A1B083821F40CB4ULL,
    0x7B4A38E32537DF62ULL, 0x950113646D1D6E03ULL, 0x4DA8979A0041E8A9ULL,
    0x3BC36E078F7515D7ULL, 0x5D0A12F27AD310D1ULL, 0x7F9D1A2E1EBE1327ULL,
    0xDA3A361B1C5157B1ULL, 0xDCDD7D20903D0C25ULL, 0x36833336D068F707ULL,
    0xCE68341F79893389ULL, 0xAB9090168DD05F34ULL, 0x43954B3252DC25E5ULL,
    0xB438C2B67F98E5E9ULL, 0x10DCD78E3851A492ULL, 0xDBC27AB5447822BFULL,
    0x9B3CDB65F82CA382ULL, 0xB67B7896167B4C84ULL, 0xBFCED1B0048EAC50ULL,
    0xA9119B60369FFEBDULL, 0x1FFF7AC80904BF45ULL, 0xAC12FB171817EEE7ULL,
    0xAF08DA9177DDA93DULL, 0x1B0CAB936E65C744ULL, 0xB559EB1D04E5E932ULL,
    0xC37B45B3F8D6F2BAULL, 0xC3A9DC228CAAC9E9ULL, 0xF3B8B6675A6507FFULL,
    0x9FC477DE4ED681DAULL, 0x67378D8ECCEF96CBULL, 0x6DD856D94D259236ULL,
    0xA319CE15B0B4DB31ULL, 0x073973751F12DD5EULL, 0x8A8E849EB32781A5ULL,
    0xE1925C71285279F5ULL, 0x74C04BF1790C0EFEULL, 0x4DDA48153C94938AULL,
    0x9D266D6A1CC0542CULL, 0x7440FB816508C4FEULL, 0x13328503DF48229FULL,
    0xD6BF7BAEE43CAC40ULL, 0x4838D65F6EF6748FULL, 0x1E152328F3318DEAULL,
    0x8F8419A348F296BFULL, 0x72C8834A5957B511ULL, 0xD7A023A73260B45CULL,
    0x94EBC8ABCFB56DAEULL, 0x9FC10D0F989993E0ULL, 0xDE68A2355B93CAE6ULL,
    0xA44CFE79AE538BBEULL, 0x9D1D84FCCE371425ULL, 0x51D2B1AB2DDFB636ULL,
    0x2FD7E4B9E72CD38CULL, 0x65CA5B96B7552210ULL, 0xDD69A0D8AB3B546DULL,
    0x604D51B25FBF70E2ULL, 0x73AA8A564FB7AC9EULL, 0x1A8C1E992B941148ULL,
    0xAAC40A2703D9BEA0ULL, 0x764DBEAE7FA4F3A6ULL, 0x1E99B96E70A9BE8BULL,
    0x2C5E9DEB57EF4743ULL, 0x3A938FEE32D29981ULL, 0x26E6DB8FFDF5ADFEULL,
    0x469356C504EC9F9DULL, 0xC8763C5B08D1908CULL, 0x3F6C6AF859D80055ULL,
    0x7F7CC39420A3A545ULL, 0x9BFB227EBDF4C5CEULL, 0x89039D79D6FC5C5CULL,
    0x8FE88B57305E2AB6ULL, 0xA09E8C8C35AB96DEULL, 0xFA7E393983325753ULL,
    0xD6B6D0ECC617C699ULL, 0xDFEA21EA9E7557E3ULL, 0xB67C1FA481680AF8ULL,
    0xCA1E3785A9E724E5ULL, 0x1CFC8BED0D681639ULL, 0xD18D8549D140CAEAULL,
    0x4ED0FE7E9DC91335ULL, 0xE4DBF0634473F5D2ULL, 0x1761F93A44D5AEFEULL,
    0x53898E4C3910DA55ULL, 0x734DE8181F6EC39AULL, 0x2680B122BAA28D97ULL,
    0x298AF231C85BAFABULL, 0x7983EED3740847D5ULL, 0x66C1A2A1A60CD889ULL,
    0x9E17E49642A3E4C1ULL, 0xEDB454E7BADC0805ULL, 0x50B704CAB602C329ULL,
    0x4CC317FB9CDDD023ULL, 0x66B4835D9EAFEA22ULL, 0x219B97E26FFC81BDULL,
    0x261E4E4C0A333A9DULL, 0x1FE2CCA76517DB90ULL, 0xD7504DFA8816EDBBULL,
    0xB9571FA04DC089C8ULL, 0x1DDC0325259B27DEULL, 0xCF3F4688801EB9AAULL,
    0xF4F5D05C10CAB243ULL, 0x38B6525C21A42B0EULL, 0x36F60E2BA4FA6800ULL,
    0xEB3593803173E0CEULL, 0x9C4CD6257C5A3603ULL, 0xAF0C317D32ADAA8AULL,
    0x258E5A80C7204C4BULL, 0x8B889D624D44885DULL, 0xF4D14597E660F855ULL,
    0xD4347F66EC8941C3ULL, 0xE699ED85B0DFB40DULL, 0x2472F6207C2D0484ULL,
    0xC2A1E7B5B459AEB5ULL, 0xAB4F6451CC1D45ECULL, 0x63767572AE3D6174ULL,
    0xA59E0BD101731A28ULL, 0x116D0016CB948F09ULL, 0x2CF9C8CA052F6E9FULL,
    0x0B090A7560A968E3ULL, 0xABEEDDB2DDE06FF1ULL, 0x58EFC10B06A2068DULL,
    0xC6E57A78FBD986E0ULL, 0x2EAB8CA63CE802D7ULL, 0x14A195640116F336ULL,
    0x7C0828DD624EC390ULL, 0xD74BBE77E6116AC7ULL, 0x804456AF10F5FB53ULL,
    0xEBE9EA2ADF4321C7ULL, 0x03219A39EE587A30ULL, 0x49787FEF17AF9924ULL,
    0xA1E9300CD8520548ULL, 0x5B45E522E4B1B4EFULL, 0xB49C3B3995091A36ULL,
    0xD4490AD526F14431ULL, 0x12A8F216AF9418C2ULL, 0x001F837CC7350524ULL,
    0x1877B51E57A764D5ULL, 0xA2853B80F17F58EEULL, 0x993E1DE72D36D310ULL,
    0xB3598080CE64A656ULL, 0x252F59CF0D9F04BBULL, 0xD23C8E176D113600ULL,
    0x1BDA0492E7E4586EULL, 0x21E0BD5026C619BFULL, 0x3B097ADAF088F94EULL,
    0x8D14DEDB30BE846EULL, 0xF95CFFA23AF5F6F4ULL, 0x3871700761B3F743ULL,
    0xCA672B91E9E4FA16ULL, 0x64C8E531BFF53B55ULL, 0x241260ED4AD1E87DULL,
    0x106C09B972D2E822ULL, 0x7FBA195410E5CA30ULL, 0x7884D9BC6CB569D8ULL,
    0x0647DFEDCD894A29ULL, 0x63573FF03E224774ULL, 0x4FC8E9560F91B123ULL,
    0x1DB956E450275779ULL, 0xB8D91274B9E9D4FBULL, 0xA2EBEE47E2FBFCE1ULL,
    0xD9F1F30CCD97FB09ULL, 0xEFED53D75FD64E6BULL, 0x2E6D02C36017F67FULL,
    0xA9AA4D20DB084E9BULL, 0xB64BE8D8B25396C1ULL, 0x70CB6AF7C2D5BCF0ULL,
    0x98F076A4F7A2322EULL, 0xBF84470805E69B5FULL, 0x94C3251F06F90CF3ULL,
    0x3E003E616A6591E9ULL, 0xB925A6CD0421AFF3ULL, 0x61BDD1307C66E300ULL,
    0xBF8D5108E27E0D48ULL, 0x240AB57A8B888B20ULL, 0xFC87614BAF287E07ULL,
    0xEF02CDD06FFDB432ULL, 0xA1082C0466DF6C0AULL, 0x8215E577001332C8ULL,
    0xD39BB9C3A48DB6CFULL, 0x2738259634305C14ULL, 0x61CF4F94C97DF93DULL,
    0x1B6BACA2AE4E125BULL, 0x758F450C88572E0BULL, 0x959F587D507A8359ULL,
    0xB063E962E045F54DULL, 0x60E8ED72C0DFF5D1ULL, 0x7B64978555326F9FULL,
    0xFD080D236DA814BAULL, 0x8C90FD9B083F4558ULL, 0x106F72FE81E2C590ULL,
    0x7976033A39F7D952ULL, 0xA4EC0132764CA04BULL, 0x733EA705FAE4FA77ULL,
    0xB4D8F77BC3E56167ULL, 0x9E21F4F903B33FD9ULL, 0x9D765E419FB69F6DULL,
    0xD30C088BA61EA5EFULL, 0x5D94337FBFAF7F5BULL, 0x1A4E4822EB4D7A59ULL,
    0x6FFE73E81B637FB3ULL, 0xDDF957BC36D8B9CAULL, 0x64D0E29EEA8838B3ULL,
    0x08DD9BDFD96B9F63ULL, 0x087E79E5A57D1D13ULL, 0xE328E230E3E2B3FBULL,
    0x1C2559E30F0946BEULL, 0x720BF5F26F4D2EAAULL, 0xB0774D261CC609DBULL,
    0x443F64EC5A371195ULL, 0x4112CF68649A260EULL, 0xD813F2FAB7F5C5CAULL,
    0x660D3257380841EEULL, 0x59AC2C7873F910A3ULL, 0xE846963877671A17ULL,
    0x93B633ABFA3469F8ULL, 0xC0C0F5A60EF4CDCFULL, 0xCAF21ECD4377B28CULL,
    0x57277707199B8175ULL, 0x506C11B9D90E8B1DULL, 0xD83CC2687A19255FULL,
    0x4A29C6465A314CD1ULL, 0xED2DF21216235097ULL, 0xB5635C95FF7296E2ULL,
    0x22AF003AB672E811ULL, 0x52E762596BF68235ULL, 0x9AEBA33AC6ECC6B0ULL,
    0x944F6DE09134DFB6ULL, 0x6C47BEC883A7DE39ULL, 0x6AD047C430A12104ULL,
    0xA5B1CFDBA0AB4067ULL, 0x7C45D833AFF07862ULL, 0x5092EF950A16DA0BULL,
    0x9338E69C052B8E7BULL, 0x455A4B4CFE30E3F5ULL, 0x6B02E63195AD0CF8ULL,
    0x6B17B224BAD6BF27ULL, 0xD1E0CCD25BB9C169ULL, 0xDE0C89A556B9AE70ULL,
    0x50065E535A213CF6ULL, 0x9C1169FA2777B874ULL, 0x78EDEFD694AF1EEDULL,
    0x6DC93D9526A50E68ULL, 0xEE97F453F06791EDULL, 0x32AB0EDB696703D3ULL,
    0x3A6853C7E70757A7ULL, 0x31865CED6120F37DULL, 0x67FEF95D92607890ULL,
    0x1F2B1D1F15F6DC9CULL, 0xB69E38A8965C6B65ULL, 0xAA9119FF184CCCF4ULL,
    0xF43C732873F24C13ULL, 0xFB4A3D794A9A80D2ULL, 0x3550C2321FD6109CULL,
    0x371F77E76BB8417EULL, 0x6BFA9AAE5EC05779ULL, 0xCD04F3FF001A4778ULL,
    0xE3273522064480CAULL, 0x9F91508BFFCFC14AULL, 0x049A7F41061A9E60ULL,
    0xFCB6BE43A9F2FE9BULL, 0x08DE8A1C7797DA9BULL, 0x8F9887E6078735A1ULL,
    0xB5B4071DBFC73A66ULL, 0x230E343DFBA08D33ULL, 0x43ED7F5A0FAE657DULL,
    0x3A88A0FBBCB05C63ULL, 0x21874B8B4D2DBC4FULL, 0x1BDEA12E35F6A8C9ULL,
    0x53C065C6C8E63528ULL, 0xE34A1D250E7A8D6BULL, 0xD6B04D3B7651DD7EULL,
    0x5E90277E7CB39E2DULL, 0x2C046F22062DC67DULL, 0xB10BB459132D0A26ULL,
    0x3FA9DDFB67E2F199ULL, 0x0E09B88E1914F7AFULL, 0x10E8B35AF3EEAB37ULL,
    0x9EEDECA8E272B933ULL, 0xD4C718BC4AE8AE5FULL, 0x81536D601170FC20ULL,
    0x91B534F885818A06ULL, 0xEC8177F83F900978ULL, 0x190E714FADA5156EULL,
    0xB592BF39B0364963ULL, 0x89C350C893AE7DC1ULL, 0xAC042E70F8B383F2ULL,
    0xB49B52E587A1EE60ULL, 0xFB152FE3FF26DA89ULL, 0x3E666E6F69AE2C15ULL,
    0x3B544EBE544C19F9ULL, 0xE805A1E290CF2456ULL, 0x24B33C9D7ED25117ULL,
    0xE74733427B72F0C1ULL, 0x0A804D18B7097475ULL, 0x57E3306D881EDB4FULL,
    0x4AE7D6A36EB5DBCBULL, 0x2D8D5432157064C8ULL, 0xD1E649DE1E7F268BULL,
    0x8A328A1CEDFE552CULL, 0x07A3AEC79624C7DAULL, 0x84547DDC3E203C94ULL,
    0x990A98FD5071D263ULL, 0x1A4FF12616EEFC89ULL, 0xF6F7FD1431714200ULL,
    0x30C05B1BA332F41CULL, 0x8D2636B81555A786ULL, 0x46C9FEB55D120902ULL,
    0xCCEC0A73B49C9921ULL, 0x4E9D2827355FC492ULL, 0x19EBB029435DCB0FULL,
    0x4659D2B743848A2CULL, 0x963EF2C96B33BE31ULL, 0x74F85198B05A2E7DULL,
    0x5A0F544DD2B1FB18ULL, 0x03727073C2E134B1ULL, 0xC7F6AA2DE59AEA61ULL,
    0x352787BAA0D7C22FULL, 0x9853EAB63B5E0B35ULL, 0xABBDCDD7ED5C0860ULL,
    0xCF05DAF5AC8D77B0ULL, 0x49CAD48CEBF4A71EULL, 0x7A4C10EC2158C4A6ULL,
    0xD9E92AA246BF719EULL, 0x13AE978D09FE5557ULL, 0x730499AF921549FFULL,
    0x4E4B705B92903BA4ULL, 0xFF577222C14F0A3AULL, 0x55B6344CF97AAFAEULL,
    0xB862225B055B6960ULL, 0xCAC09AFBDDD2CDB4ULL, 0xDAF8E9829FE96B5FULL,
    0xB5FDFC5D3132C498ULL, 0x310CB380DB6F7503ULL, 0xE87FBB46217A360EULL,
    0x2102AE466EBB1148ULL, 0xF8549E1A3AA5E00DULL, 0x07A69AFDCC42261AULL,
    0xC4C118BFE78FEAAEULL, 0xF9F4892ED96BD438ULL, 0x1AF3DBE25D8F45DAULL,
    0xF5B4B0B0D2DEEEB4ULL, 0x962ACEEFA82E1C84ULL, 0x046E3ECAAF453CE9ULL,
    0xF05D129681949A4CULL, 0x964781CE734B3C84ULL, 0x9C2ED44081CE5FBDULL,
    0x522E23F3925E319EULL, 0x177E00F9FC32F791ULL, 0x2BC60A63A6F3B3F2ULL,
    0x222BBFAE61725606ULL, 0x486289DDCC3D6780ULL, 0x7DC7785B8EFDFC80ULL,
    0x8AF38731C02BA980ULL, 0x1FAB64EA29A2DDF7ULL, 0xE4D9429322CD065AULL,
    0x9DA058C67844F20CULL, 0x24C0E332B70019B0ULL, 0x233003B5A6CFE6ADULL,
    0xD586BD01C5C217F6ULL, 0x5E5637885F29BC2BULL, 0x7EBA726D8C94094BULL,
    0x0A56A5F0BFE39272ULL, 0xD79476A84EE20D06ULL, 0x9E4C1269BAA4BF37ULL,
    0x17EFEE45B0DEE640ULL, 0x1D95B0A5FCF90BC6ULL, 0x93CBE0B699C2585DULL,
    0x65FA4F227A2B6D79ULL, 0xD5F9E858292504D5ULL, 0xC2B5A03F71471A6FULL,
    0x59300222B4561E00ULL, 0xCE2F8642CA0712DCULL, 0x7CA9723FBB2E8988ULL,
    0x2785338347F2BA08ULL, 0xC61BB3A141E50E8CULL, 0x150F361DAB9DEC26ULL,
    0x9F6A419D382595F4ULL, 0x64A53DC924FE7AC9ULL, 0x142DE49FFF7A7C3DULL,
    0x0C335248857FA9E7ULL, 0x0A9C32D5EAE45305ULL, 0xE6C42178C4BBB92EULL,
    0x71F1CE2490D20B07ULL, 0xF1BCC3D275AFE51AULL, 0xE728E8C83C334074ULL,
    0x96FBF83A12884624ULL, 0x81A1549FD6573DA5ULL, 0x5FA7867CAF35E149ULL,
    0x56986E2EF3ED091BULL, 0x917F1DD5F8886C61ULL, 0xD20D8C88C8FFE65FULL,
    0x31D71DCE64B2C310ULL, 0xF165B587DF898190ULL, 0xA57E6339DD2CF3A0ULL,
    0x1EF6E6DBB1961EC9ULL, 0x70CC73D90BC26E24ULL, 0xE21A6B35DF0C3AD7ULL,
    0x003A93D8B2806962ULL, 0x1C99DED33CB890A1ULL, 0xCF3145DE0ADD4289ULL,
    0xD0E4427A5514FB72ULL, 0x77C621CC9FB3A483ULL, 0x67A34DAC4356550BULL,
    0xF8D626AAAF278509ULL
  };


  /// Indices to the Random64[] array
  
  const int RandomPiece = 0;
  const int RandomCastle = 768;
  const int RandomEnPassant = 772;
  const int RandomTurn = 780;

  
  /// Convert pieces to the range 0..1
  
  const int PieceTo12[] = {
    0, 0, 2, 4, 6, 8, 10, 0, 0, 1, 3, 5, 7, 9, 11
  };


  /// Prototypes
  
  uint64_t book_key(const Position &pos);
  uint64_t book_piece_key(Piece p, Square s);
  uint64_t book_castle_key(const Position &pos);
  uint64_t book_ep_key(const Position &pos);
  uint64_t book_color_key(const Position &pos);

  uint16_t read_integer16(std::ifstream& file);
  uint64_t read_integer64(std::ifstream& file);
  uint64_t read_integer(std::ifstream& file, int size);
}


////
//// Functions
////


/// Constructor

Book::Book() : bookSize(0) {}


/// Book::open() opens a book file with a given file name.

void Book::open(const std::string &fName) {

  fileName = fName;
  bookFile.open(fileName.c_str(), std::ifstream::in | std::ifstream::binary);
  if (!bookFile.is_open())
      return;

  bookFile.seekg(0, std::ios::end);
  bookSize = bookFile.tellg() / 16;
  bookFile.seekg(0, std::ios::beg);

  if (!bookFile.good())
  {
      std::cerr << "Failed to open book file " << fileName << std::endl;
      exit(EXIT_FAILURE);
  }
}


/// Book::close() closes the currently open book file.

void Book::close() {

  if (bookFile.is_open())
      bookFile.close();
}


/// Book::is_open() tests whether a book file has been opened.

bool Book::is_open() const {
  
  return bookFile.is_open() && bookSize != 0;
}


/// Book::file_name() returns the file name of the currently active book,
/// or the empty string if no book is open.

const std::string Book::file_name() const {

  return bookFile.is_open() ? fileName : "";
}
  

/// Book::get_move() gets a book move for a given position.  Returns
/// MOVE_NONE if no book move is found.

Move Book::get_move(const Position &pos) const {
  if(this->is_open()) {
    int bestMove = 0, bestScore = 0, move, score;
    uint64_t key = book_key(pos);
    BookEntry entry;

    for(int i = this->find_key(key); i < bookSize; i++) {
      this->read_entry(entry, i);
      if(entry.key != key)
        break;
      move = entry.move;
      score = entry.count;
      assert(score > 0);

      bestScore += score;
      if(int(genrand_int32() % bestScore) < score)
        bestMove = move;
    }

    if(bestMove != 0) {
      MoveStack moves[256];
      int n, j;
      n = generate_legal_moves(pos, moves);
      for(j = 0; j < n; j++)
        if((int(moves[j].move) & 07777) == bestMove)
          return moves[j].move;
    }
  }
  return MOVE_NONE;
}


/// Book::find_key() takes a book key as input, and does a binary search
/// through the book file for the given key.  The index to the first book
/// entry with the same key as the input is returned.  When the key is not
/// found in the book file, bookSize is returned.

int Book::find_key(uint64_t key) const {
  int left, right, mid;
  BookEntry entry;

  // Binary search (finds the leftmost entry)
  left = 0;
  right = bookSize - 1;

  assert(left <= right);

  while(left < right) {
    mid = (left + right) / 2;
    assert(mid >= left && mid < right);

    this->read_entry(entry, mid);

    if(key <= entry.key)
      right = mid;
    else
      left = mid + 1;
  }

  assert(left == right);

  this->read_entry(entry, left);

  return (entry.key == key)? left : bookSize;
}


/// Book::read_entry() takes a BookEntry reference and an integer index as
/// input, and looks up the opening book entry at the given index in the book
/// file.  The book entry is copied to the first input parameter.

void Book::read_entry(BookEntry& entry, int n) const {

  assert(n >= 0 && n < bookSize);
  assert(bookFile.is_open());

  bookFile.seekg(n*16, std::ios_base::beg);
  if (!bookFile.good())
  {
    std::cerr << "Failed to read book entry at index " << n << std::endl;
    exit(EXIT_FAILURE);
  }
  entry.key = read_integer64(bookFile);
  entry.move = read_integer16(bookFile);
  entry.count = read_integer16(bookFile);
  entry.n = read_integer16(bookFile);
  entry.sum = read_integer16(bookFile);
}


////
//// Local definitions
////

namespace {

  uint64_t book_key(const Position &pos) {
    uint64_t result = 0ULL;

    for(Color c = WHITE; c <= BLACK; c++) {
      Bitboard b = pos.pieces_of_color(c);
      Square s;
      Piece p;
      while(b != EmptyBoardBB) {
        s = pop_1st_bit(&b);
        p = pos.piece_on(s);
        assert(piece_is_ok(p));
        assert(color_of_piece(p) == c);

        result ^= book_piece_key(p, s);
      }
    }

    result ^= book_castle_key(pos);
    result ^= book_ep_key(pos);
    result ^= book_color_key(pos);

    return result;
  }
        

  uint64_t book_piece_key(Piece p, Square s) {
    return Random64[RandomPiece + (PieceTo12[int(p)]^1)*64 + int(s)];
  }


  uint64_t book_castle_key(const Position &pos) {
    uint64_t result = 0ULL;

    if(pos.can_castle_kingside(WHITE))
      result ^= Random64[RandomCastle+0];
    if(pos.can_castle_queenside(WHITE))
      result ^= Random64[RandomCastle+1];
    if(pos.can_castle_kingside(BLACK))
      result ^= Random64[RandomCastle+2];
    if(pos.can_castle_queenside(BLACK))
      result ^= Random64[RandomCastle+3];
    return result;
  }

  
  uint64_t book_ep_key(const Position &pos) {
    return (pos.ep_square() == SQ_NONE)?
      0ULL : Random64[RandomEnPassant + square_file(pos.ep_square())];
  }

  
  uint64_t book_color_key(const Position &pos) {
    return (pos.side_to_move() == WHITE)? Random64[RandomTurn] : 0ULL;
  }
  

  uint16_t read_integer16(std::ifstream& file) {
    
    uint64_t n = read_integer(file, 2);
    assert(n == (uint16_t)n);
    return (uint16_t)n;      
  }


  uint64_t read_integer64(std::ifstream& file) {
    
    return read_integer(file, 8);      
  }


  uint64_t read_integer(std::ifstream& file, int size) {

    char buf[8];
    file.read(buf, size);

    if (!file.good())
    {
        std::cerr << "Failed to read " << size << " bytes from book file"
                  << std::endl;
        exit(EXIT_FAILURE);
    }
    // Numbers are stored in little endian format
    uint64_t n = 0ULL;
    for (int i = 0; i < size; i++)
        n = (n << 8) + (unsigned char)buf[i];

    return n;
  }
}

// ======== color.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////



////
//// Functions
////

/// color_is_ok(), for debugging:

bool color_is_ok(Color c) {
  return c == WHITE || c == BLACK;
}

// ======== direction.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////



////
//// Variables
////

uint8_t DirectionTable[64][64];
uint8_t SignedDirectionTable[64][64];


////
//// Functions
////

void init_direction_table() {
  SquareDelta deltas[8] = {
    DELTA_E, DELTA_W, DELTA_N, DELTA_S, DELTA_NE, DELTA_SW, DELTA_NW, DELTA_SE
  };
  for(Square s1 = SQ_A1; s1 <= SQ_H8; s1++)
    for(Square s2 = SQ_A1; s2 <= SQ_H8; s2++) {
      DirectionTable[s1][s2] = uint8_t(DIR_NONE);
      SignedDirectionTable[s1][s2] = uint8_t(SIGNED_DIR_NONE);
      if(s1 == s2) continue;
      for(SignedDirection d = SIGNED_DIR_E; d <= SIGNED_DIR_SE; d++) {
        SquareDelta delta = deltas[d];
        Square s3, s4;
        for(s4 = s1 + delta, s3 = s1;
            square_distance(s4, s3) == 1 && s4 != s2 && square_is_ok(s4);
            s3 = s4, s4 += delta);
        if(s4 == s2 && square_distance(s4, s3) == 1) {
          SignedDirectionTable[s1][s2] = uint8_t(d);
          DirectionTable[s1][s2] = uint8_t(d/2);
          break;
        }
      }
    }
}

// ======== endgame.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cassert>

// ---- begin endgame.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(ENDGAME_H_INCLUDED)
#define ENDGAME_H_INCLUDED

////
//// Includes
////

// ---- begin scale.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(SCALE_H_INCLUDED)
#define SCALE_H_INCLUDED

////
//// Includes
////



////
//// Types
////

enum ScaleFactor {
  SCALE_FACTOR_ZERO = 0,
  SCALE_FACTOR_NORMAL = 64,
  SCALE_FACTOR_MAX = 128,
  SCALE_FACTOR_NONE = 255
};


////
//// Inline functions
////

inline Value apply_scale_factor(Value v, ScaleFactor f) {
  return Value((v * f) / int(SCALE_FACTOR_NORMAL));
}


#endif // !defined(SCALE_H_INCLUDED)
// ---- end scale.h ----


////
//// Types
////

/// Abstract base class for all special endgame evaluation functions:

class EndgameEvaluationFunction {
public:
  EndgameEvaluationFunction(Color c);
  virtual ~EndgameEvaluationFunction() { }

  virtual Value apply(const Position &pos) =0;

protected:
  Color strongerSide, weakerSide;
};


/// Subclasses for various concrete endgames:

// Generic "mate lone king" eval:
class KXKEvaluationFunction : public EndgameEvaluationFunction {
public:
  KXKEvaluationFunction(Color c);
  Value apply(const Position &pos);
};

// KBN vs K:
class KBNKEvaluationFunction : public EndgameEvaluationFunction {
public:
  KBNKEvaluationFunction(Color c);
  Value apply(const Position &pos);
};

// KP vs K:
class KPKEvaluationFunction : public EndgameEvaluationFunction {
public:
  KPKEvaluationFunction(Color c);
  Value apply(const Position &pos);
};

// KR vs KP:
class KRKPEvaluationFunction : public EndgameEvaluationFunction {
public:
  KRKPEvaluationFunction(Color c);
  Value apply(const Position &pos);
};

// KR vs KB:
class KRKBEvaluationFunction : public EndgameEvaluationFunction {
public:
  KRKBEvaluationFunction(Color c);
  Value apply(const Position &pos);
};

// KR vs KN:
class KRKNEvaluationFunction : public EndgameEvaluationFunction {
public:
  KRKNEvaluationFunction(Color c);
  Value apply(const Position &pos);
};

// KQ vs KR:
class KQKREvaluationFunction : public EndgameEvaluationFunction {
public:
  KQKREvaluationFunction(Color c);
  Value apply(const Position &pos);
};


/// Abstract base class for all evaluation scaling functions:

class ScalingFunction {
public:
  ScalingFunction(Color c);
  virtual ~ScalingFunction() { }

  virtual ScaleFactor apply(const Position &pos) =0;

protected:
  Color strongerSide, weakerSide;
};


/// Subclasses for various concrete endgames:

// KBP vs K:
class KBPKScalingFunction : public ScalingFunction {
public:
  KBPKScalingFunction(Color c);
  ScaleFactor apply(const Position &pos);
};

// KQ vs KRP:
class KQKRPScalingFunction: public ScalingFunction {
public:
  KQKRPScalingFunction(Color c);
  ScaleFactor apply(const Position &pos);
};

// KRP vs KR:
class KRPKRScalingFunction : public ScalingFunction {
public:
  KRPKRScalingFunction(Color c);
  ScaleFactor apply(const Position &pos);
};

// KRPP vs KRP:
class KRPPKRPScalingFunction : public ScalingFunction {
public:
  KRPPKRPScalingFunction(Color c);
  ScaleFactor apply(const Position &pos);
};

// King and pawns vs king:
class KPsKScalingFunction : public ScalingFunction {
public:
  KPsKScalingFunction(Color c);
  ScaleFactor apply(const Position &pos);
};

// KBP vs KB:
class KBPKBScalingFunction : public ScalingFunction {
public:
  KBPKBScalingFunction(Color c);
  ScaleFactor apply(const Position &pos);
};

// KBP vs KN:
class KBPKNScalingFunction : public ScalingFunction {
public:
  KBPKNScalingFunction(Color c);
  ScaleFactor apply(const Position &pos);
};

// KNP vs K:
class KNPKScalingFunction : public ScalingFunction {
public:
  KNPKScalingFunction(Color c);
  ScaleFactor apply(const Position &pos);
};

// KP vs KP:
class KPKPScalingFunction : public ScalingFunction {
public:
  KPKPScalingFunction(Color c);
  ScaleFactor apply(const Position &pos);
};


////
//// Constants and variables
////

// Generic "mate lone king" eval:
extern KXKEvaluationFunction EvaluateKXK, EvaluateKKX;

// KBN vs K:
extern KBNKEvaluationFunction EvaluateKBNK, EvaluateKKBN;

// KP vs K:
extern KPKEvaluationFunction EvaluateKPK, EvaluateKKP;

// KR vs KP:
extern KRKPEvaluationFunction EvaluateKRKP, EvaluateKPKR;

// KR vs KB:
extern KRKBEvaluationFunction EvaluateKRKB, EvaluateKBKR;

// KR vs KN:
extern KRKNEvaluationFunction EvaluateKRKN, EvaluateKNKR;

// KQ vs KR:
extern KQKREvaluationFunction EvaluateKQKR, EvaluateKRKQ;

// KBP vs K:
extern KBPKScalingFunction ScaleKBPK, ScaleKKBP;

// KQ vs KRP:
extern KQKRPScalingFunction ScaleKQKRP, ScaleKRPKQ;

// KRP vs KR:
extern KRPKRScalingFunction ScaleKRPKR, ScaleKRKRP;

// KRPP vs KRP:
extern KRPPKRPScalingFunction ScaleKRPPKRP, ScaleKRPKRPP;

// King and pawns vs king:
extern KPsKScalingFunction ScaleKPsK, ScaleKKPs;

// KBP vs KB:
extern KBPKBScalingFunction ScaleKBPKB, ScaleKBKBP;

// KBP vs KN:
extern KBPKNScalingFunction ScaleKBPKN, ScaleKNKBP;

// KNP vs K:
extern KNPKScalingFunction ScaleKNPK, ScaleKKNP;

// KP vs KP:
extern KPKPScalingFunction ScaleKPKPw, ScaleKPKPb;


////
//// Prototypes
////

extern void init_bitbases();


#endif // !defined(ENDGAME_H_INCLUDED)
// ---- end endgame.h ----


////
//// Constants and variables
////

/// Evaluation functions

// Generic "mate lone king" eval:
KXKEvaluationFunction EvaluateKXK = KXKEvaluationFunction(WHITE);
KXKEvaluationFunction EvaluateKKX = KXKEvaluationFunction(BLACK);

// KBN vs K:
KBNKEvaluationFunction EvaluateKBNK = KBNKEvaluationFunction(WHITE);
KBNKEvaluationFunction EvaluateKKBN = KBNKEvaluationFunction(BLACK);

// KP vs K:
KPKEvaluationFunction EvaluateKPK = KPKEvaluationFunction(WHITE);
KPKEvaluationFunction EvaluateKKP = KPKEvaluationFunction(BLACK);

// KR vs KP:
KRKPEvaluationFunction EvaluateKRKP = KRKPEvaluationFunction(WHITE);
KRKPEvaluationFunction EvaluateKPKR = KRKPEvaluationFunction(BLACK);

// KR vs KB:
KRKBEvaluationFunction EvaluateKRKB = KRKBEvaluationFunction(WHITE);
KRKBEvaluationFunction EvaluateKBKR = KRKBEvaluationFunction(BLACK);

// KR vs KN:
KRKNEvaluationFunction EvaluateKRKN = KRKNEvaluationFunction(WHITE);
KRKNEvaluationFunction EvaluateKNKR = KRKNEvaluationFunction(BLACK);

// KQ vs KR:
KQKREvaluationFunction EvaluateKQKR = KQKREvaluationFunction(WHITE);
KQKREvaluationFunction EvaluateKRKQ = KQKREvaluationFunction(BLACK);


/// Scaling functions

// KBP vs K:
KBPKScalingFunction ScaleKBPK = KBPKScalingFunction(WHITE);
KBPKScalingFunction ScaleKKBP = KBPKScalingFunction(BLACK);

// KQ vs KRP:
KQKRPScalingFunction ScaleKQKRP = KQKRPScalingFunction(WHITE);
KQKRPScalingFunction ScaleKRPKQ = KQKRPScalingFunction(BLACK);

// KRP vs KR:
KRPKRScalingFunction ScaleKRPKR = KRPKRScalingFunction(WHITE);
KRPKRScalingFunction ScaleKRKRP = KRPKRScalingFunction(BLACK);

// KRPP vs KRP:
KRPPKRPScalingFunction ScaleKRPPKRP = KRPPKRPScalingFunction(WHITE);
KRPPKRPScalingFunction ScaleKRPKRPP = KRPPKRPScalingFunction(BLACK);

// King and pawns vs king:
KPsKScalingFunction ScaleKPsK = KPsKScalingFunction(WHITE);
KPsKScalingFunction ScaleKKPs = KPsKScalingFunction(BLACK);

// KBP vs KB:
KBPKBScalingFunction ScaleKBPKB = KBPKBScalingFunction(WHITE);
KBPKBScalingFunction ScaleKBKBP = KBPKBScalingFunction(BLACK);

// KBP vs KN:
KBPKNScalingFunction ScaleKBPKN = KBPKNScalingFunction(WHITE);
KBPKNScalingFunction ScaleKNKBP = KBPKNScalingFunction(BLACK);

// KNP vs K:
KNPKScalingFunction ScaleKNPK = KNPKScalingFunction(WHITE);
KNPKScalingFunction ScaleKKNP = KNPKScalingFunction(BLACK);

// KPKP
KPKPScalingFunction ScaleKPKPw = KPKPScalingFunction(WHITE);
KPKPScalingFunction ScaleKPKPb = KPKPScalingFunction(BLACK);


////
//// Local definitions
////

namespace {

  // Table used to drive the defending king towards the edge of the board
  // in KX vs K and KQ vs KR endgames:
  const uint8_t MateTable[64] = {
    100, 90, 80, 70, 70, 80, 90, 100,
    90, 70, 60, 50, 50, 60, 70, 90,
    80, 60, 40, 30, 30, 40, 60, 80,
    70, 50, 30, 20, 20, 30, 50, 70,
    70, 50, 30, 20, 20, 30, 50, 70,
    80, 60, 40, 30, 30, 40, 60, 80,
    90, 70, 60, 50, 50, 60, 70, 90,
    100, 90, 80, 70, 70, 80, 90, 100,
  };

  // Table used to drive the defending king towards a corner square of the
  // right color in KBN vs K endgames:
  const uint8_t KBNKMateTable[64] = {
    200, 190, 180, 170, 160, 150, 140, 130,
    190, 180, 170, 160, 150, 140, 130, 140,
    180, 170, 155, 140, 140, 125, 140, 150,
    170, 160, 140, 120, 110, 140, 150, 160,
    160, 150, 140, 110, 120, 140, 160, 170,
    150, 140, 125, 140, 140, 155, 170, 180,
    140, 130, 140, 150, 160, 170, 180, 190,
    130, 140, 150, 160, 170, 180, 190, 200
  };

  // The attacking side is given a descending bonus based on distance between
  // the two kings in basic endgames:
  const int DistanceBonus[8] = {0, 0, 100, 80, 60, 40, 20, 10};

  // Bitbase for KP vs K:
  uint8_t KPKBitbase[24576];

  // Penalty for big distance between king and knight for the defending king
  // and knight in KR vs KN endgames:
  const int KRKNKingKnightDistancePenalty[8] = { 0, 0, 4, 10, 20, 32, 48, 70 };

  // Various inline functions for accessing the above arrays:
  
  inline Value mate_table(Square s) {
    return Value(MateTable[s]);
  }

  inline Value kbnk_mate_table(Square s) {
    return Value(KBNKMateTable[s]);
  }

  inline Value distance_bonus(int d) {
    return Value(DistanceBonus[d]);
  }

  inline Value krkn_king_knight_distance_penalty(int d) {
    return Value(KRKNKingKnightDistancePenalty[d]);
  }

  // Function for probing the KP vs K bitbase:
  int probe_kpk(Square wksq, Square wpsq, Square bksq, Color stm);

}
    

////
//// Functions
////

/// Constructors

EndgameEvaluationFunction::EndgameEvaluationFunction(Color c) {
  strongerSide = c;
  weakerSide = opposite_color(strongerSide);
}

KXKEvaluationFunction::KXKEvaluationFunction(Color c) : EndgameEvaluationFunction(c) { }
KBNKEvaluationFunction::KBNKEvaluationFunction(Color c) : EndgameEvaluationFunction(c) { }
KPKEvaluationFunction::KPKEvaluationFunction(Color c) : EndgameEvaluationFunction(c) { }
KRKPEvaluationFunction::KRKPEvaluationFunction(Color c) : EndgameEvaluationFunction(c) { }
KRKBEvaluationFunction::KRKBEvaluationFunction(Color c) : EndgameEvaluationFunction(c) { }
KRKNEvaluationFunction::KRKNEvaluationFunction(Color c) : EndgameEvaluationFunction(c) { }
KQKREvaluationFunction::KQKREvaluationFunction(Color c) : EndgameEvaluationFunction(c) { }


ScalingFunction::ScalingFunction(Color c) {
  strongerSide = c;
  weakerSide = opposite_color(c);
}

KBPKScalingFunction::KBPKScalingFunction(Color c) : ScalingFunction(c) { }
KQKRPScalingFunction::KQKRPScalingFunction(Color c) : ScalingFunction(c) { }
KRPKRScalingFunction::KRPKRScalingFunction(Color c) : ScalingFunction(c) { }
KRPPKRPScalingFunction::KRPPKRPScalingFunction(Color c) : ScalingFunction(c) { }
KPsKScalingFunction::KPsKScalingFunction(Color c) : ScalingFunction(c) { }
KBPKBScalingFunction::KBPKBScalingFunction(Color c) : ScalingFunction(c) { }
KBPKNScalingFunction::KBPKNScalingFunction(Color c) : ScalingFunction(c) { }
KNPKScalingFunction::KNPKScalingFunction(Color c) : ScalingFunction(c) { }
KPKPScalingFunction::KPKPScalingFunction(Color c) : ScalingFunction(c) { }


/// Mate with KX vs K.  This function is used to evaluate positions with
/// King and plenty of material vs a lone king.  It simply gives the
/// attacking side a bonus for driving the defending king towards the edge
/// of the board, and for keeping the distance between the two kings small.

Value KXKEvaluationFunction::apply(const Position &pos) {

  assert(pos.non_pawn_material(weakerSide) == Value(0));
  assert(pos.piece_count(weakerSide, PAWN) == Value(0));

  Square winnerKSq = pos.king_square(strongerSide);
  Square loserKSq = pos.king_square(weakerSide);

  Value result =
    pos.non_pawn_material(strongerSide) +
    pos.piece_count(strongerSide, PAWN) * PawnValueEndgame +
    mate_table(loserKSq) +
    distance_bonus(square_distance(winnerKSq, loserKSq));

  if(pos.piece_count(strongerSide, QUEEN) > 0 || pos.piece_count(strongerSide, ROOK) > 0 ||
     pos.piece_count(strongerSide, BISHOP) > 1)
    // TODO: check for two equal-colored bishops!
    result += VALUE_KNOWN_WIN;

  return (strongerSide == pos.side_to_move())? result : -result;
}


/// Mate with KBN vs K.  This is similar to KX vs K, but we have to drive the
/// defending king towards a corner square of the right color.
                  
Value KBNKEvaluationFunction::apply(const Position &pos) {

  assert(pos.non_pawn_material(weakerSide) == Value(0));
  assert(pos.piece_count(weakerSide, PAWN) == Value(0));
  assert(pos.non_pawn_material(strongerSide) ==
         KnightValueMidgame + BishopValueMidgame);
  assert(pos.piece_count(strongerSide, BISHOP) == 1);
  assert(pos.piece_count(strongerSide, KNIGHT) == 1);
  assert(pos.piece_count(strongerSide, PAWN) == 0);

  Square winnerKSq = pos.king_square(strongerSide);
  Square loserKSq = pos.king_square(weakerSide);
  Square bishopSquare = pos.piece_list(strongerSide, BISHOP, 0);

  if(square_color(bishopSquare) == BLACK) {
    winnerKSq = flop_square(winnerKSq);
    loserKSq = flop_square(loserKSq);
  }

  Value result =
    VALUE_KNOWN_WIN + distance_bonus(square_distance(winnerKSq, loserKSq)) +
    kbnk_mate_table(loserKSq);

  return (strongerSide == pos.side_to_move())? result : -result;
}


/// KP vs K.  This endgame is evaluated with the help of a bitbase.

Value KPKEvaluationFunction::apply(const Position &pos) {

  assert(pos.non_pawn_material(strongerSide) == Value(0));
  assert(pos.non_pawn_material(weakerSide) == Value(0));
  assert(pos.piece_count(strongerSide, PAWN) == 1);
  assert(pos.piece_count(weakerSide, PAWN) == 0);
  
  Square wksq, bksq, wpsq;
  Color stm;

  if(strongerSide == WHITE) {
    wksq = pos.king_square(WHITE);
    bksq = pos.king_square(BLACK);
    wpsq = pos.piece_list(WHITE, PAWN, 0);
    stm = pos.side_to_move();
  }
  else {
    wksq = flip_square(pos.king_square(BLACK));
    bksq = flip_square(pos.king_square(WHITE));
    wpsq = flip_square(pos.piece_list(BLACK, PAWN, 0));
    stm = opposite_color(pos.side_to_move());
  }

  if(square_file(wpsq) >= FILE_E) {
    wksq = flop_square(wksq);
    bksq = flop_square(bksq);
    wpsq = flop_square(wpsq);
  }

  if(probe_kpk(wksq, wpsq, bksq, stm)) {
    Value result =
      VALUE_KNOWN_WIN + PawnValueEndgame + Value(square_rank(wpsq));
    return (strongerSide == pos.side_to_move())? result : -result;
  }

  return VALUE_DRAW;
}


/// KR vs KP.  This is a somewhat tricky endgame to evaluate precisely without
/// a bitbase.  The function below returns drawish scores when the pawn is
/// far advanced with support of the king, while the attacking king is far
/// away.

Value KRKPEvaluationFunction::apply(const Position &pos) {

  assert(pos.non_pawn_material(strongerSide) == RookValueMidgame);
  assert(pos.piece_count(strongerSide, PAWN) == 0);
  assert(pos.non_pawn_material(weakerSide) == 0);
  assert(pos.piece_count(weakerSide, PAWN) == 1);

  Square wksq, wrsq, bksq, bpsq;
  int tempo = (pos.side_to_move() == strongerSide);

  wksq = pos.king_square(strongerSide);
  wrsq = pos.piece_list(strongerSide, ROOK, 0);
  bksq = pos.king_square(weakerSide);
  bpsq = pos.piece_list(weakerSide, PAWN, 0);

  if(strongerSide == BLACK) {
    wksq = flip_square(wksq);
    wrsq = flip_square(wrsq);
    bksq = flip_square(bksq);
    bpsq = flip_square(bpsq);
  }

  Square queeningSq = make_square(square_file(bpsq), RANK_1);
  Value result;

  // If the stronger side's king is in front of the pawn, it's a win:
  if(wksq < bpsq && square_file(wksq) == square_file(bpsq))
    result = RookValueEndgame - Value(square_distance(wksq, bpsq));

  // If the weaker side's king is too far from the pawn and the rook,
  // it's a win:
  else if(square_distance(bksq, bpsq) - (tempo^1) >= 3 &&
          square_distance(bksq, wrsq) >= 3)
    result = RookValueEndgame - Value(square_distance(wksq, bpsq));

  // If the pawn is far advanced and supported by the defending king,
  // the position is drawish:
  else if(square_rank(bksq) <= RANK_3 && square_distance(bksq, bpsq) == 1 &&
          square_rank(wksq) >= RANK_4 &&
          square_distance(wksq, bpsq) - tempo > 2)
    result = Value(80 - square_distance(wksq, bpsq) * 8);

  else
    result = Value(200)
      - Value(square_distance(wksq, bpsq + DELTA_S) * 8)
      + Value(square_distance(bksq, bpsq + DELTA_S) * 8)
      + Value(square_distance(bpsq, queeningSq) * 8);

  return (strongerSide == pos.side_to_move())? result : -result;
}


/// KR vs KB.  This is very simple, and always returns drawish scores.  The
/// score is slightly bigger when the defending king is close to the edge.

Value KRKBEvaluationFunction::apply(const Position &pos) {

  assert(pos.non_pawn_material(strongerSide) == RookValueMidgame);
  assert(pos.piece_count(strongerSide, PAWN) == 0);
  assert(pos.non_pawn_material(weakerSide) == BishopValueMidgame);
  assert(pos.piece_count(weakerSide, PAWN) == 0);
  assert(pos.piece_count(weakerSide, BISHOP) == 1);

  Value result = mate_table(pos.king_square(weakerSide));
  return (pos.side_to_move() == strongerSide)? result : -result;
}


/// KR vs KN.  The attacking side has slightly better winning chances than
/// in KR vs KB, particularly if the king and the knight are far apart.

Value KRKNEvaluationFunction::apply(const Position &pos) {

  assert(pos.non_pawn_material(strongerSide) == RookValueMidgame);
  assert(pos.piece_count(strongerSide, PAWN) == 0);
  assert(pos.non_pawn_material(weakerSide) == KnightValueMidgame);
  assert(pos.piece_count(weakerSide, PAWN) == 0);
  assert(pos.piece_count(weakerSide, KNIGHT) == 1);

  Square defendingKSq = pos.king_square(weakerSide);
  Square nSq = pos.piece_list(weakerSide, KNIGHT, 0);

  Value result = Value(10) + mate_table(defendingKSq) +
    krkn_king_knight_distance_penalty(square_distance(defendingKSq, nSq));

  return (strongerSide == pos.side_to_move())? result : -result;
}


/// KQ vs KR.  This is almost identical to KX vs K:  We give the attacking
/// king a bonus for having the kings close together, and for forcing the
/// defending king towards the edge.  If we also take care to avoid null move
/// for the defending side in the search, this is usually sufficient to be
/// able to win KQ vs KR.

Value KQKREvaluationFunction::apply(const Position &pos) {
  assert(pos.non_pawn_material(strongerSide) == QueenValueMidgame);
  assert(pos.piece_count(strongerSide, PAWN) == 0);
  assert(pos.non_pawn_material(weakerSide) == RookValueMidgame);
  assert(pos.piece_count(weakerSide, PAWN) == 0);

  Square winnerKSq = pos.king_square(strongerSide);
  Square loserKSq = pos.king_square(weakerSide);
  
  Value result = QueenValueEndgame - RookValueEndgame +
    mate_table(loserKSq) + distance_bonus(square_distance(winnerKSq, loserKSq));

  return (strongerSide == pos.side_to_move())? result : -result;
}


/// KBPKScalingFunction scales endgames where the stronger side has king,
/// bishop and one or more pawns.  It checks for draws with rook pawns and a
/// bishop of the wrong color.  If such a draw is detected, ScaleFactor(0) is
/// returned.  If not, the return value is SCALE_FACTOR_NONE, i.e. no scaling
/// will be used.

ScaleFactor KBPKScalingFunction::apply(const Position &pos) {
  assert(pos.non_pawn_material(strongerSide) == BishopValueMidgame);
  assert(pos.piece_count(strongerSide, BISHOP) == 1);
  assert(pos.piece_count(strongerSide, PAWN) >= 1);

  // No assertions about the material of weakerSide, because we want draws to
  // be detected even when the weaker side has some pawns.

  Bitboard pawns = pos.pawns(strongerSide);
  File pawnFile = square_file(pos.piece_list(strongerSide, PAWN, 0));

  if((pawnFile == FILE_A || pawnFile == FILE_H) &&
     (pawns & ~file_bb(pawnFile)) == EmptyBoardBB) {
    // All pawns are on a single rook file.

    Square bishopSq = pos.piece_list(strongerSide, BISHOP, 0);
    Square queeningSq =
      relative_square(strongerSide, make_square(pawnFile, RANK_8));
    Square kingSq = pos.king_square(weakerSide);

    if(square_color(queeningSq) != square_color(bishopSq) &&
       file_distance(square_file(kingSq), pawnFile) <= 1) {
      // The bishop has the wrong color, and the defending king is on the
      // file of the pawn(s) or the neighboring file.  Find the rank of the
      // frontmost pawn:

      Rank rank;
      if(strongerSide == WHITE) {
        for(rank = RANK_7; (rank_bb(rank) & pawns) == EmptyBoardBB; rank--);
        assert(rank >= RANK_2 && rank <= RANK_7);
      }
      else {
        for(rank = RANK_2; (rank_bb(rank) & pawns) == EmptyBoardBB; rank++);
        rank = Rank(rank^7);  // HACK
        assert(rank >= RANK_2 && rank <= RANK_7);
      }
      // If the defending king has distance 1 to the promotion square or
      // is placed somewhere in front of the pawn, it's a draw.
      if(square_distance(kingSq, queeningSq) <= 1 ||
         relative_rank(strongerSide, kingSq) >= rank)
        return ScaleFactor(0);
    }
  }
  return SCALE_FACTOR_NONE;
}


/// KQKRPScalingFunction scales endgames where the stronger side has only
/// king and queen, while the weaker side has at least a rook and a pawn.
/// It tests for fortress draws with a rook on the third rank defended by
/// a pawn.

ScaleFactor KQKRPScalingFunction::apply(const Position &pos) {
  assert(pos.non_pawn_material(strongerSide) == QueenValueMidgame);
  assert(pos.piece_count(strongerSide, QUEEN) == 1);
  assert(pos.piece_count(strongerSide, PAWN) == 0);
  assert(pos.piece_count(weakerSide, ROOK) == 1);
  assert(pos.piece_count(weakerSide, PAWN) >= 1);

  Square kingSq = pos.king_square(weakerSide);
  if(relative_rank(weakerSide, kingSq) <= RANK_2 &&
     relative_rank(weakerSide, pos.king_square(strongerSide)) >= RANK_4 &&
     (pos.rooks(weakerSide) & relative_rank_bb(weakerSide, RANK_3)) &&
     (pos.pawns(weakerSide) & relative_rank_bb(weakerSide, RANK_2)) &&
     (pos.piece_attacks<KING>(kingSq) & pos.pawns(weakerSide))) {
    Square rsq = pos.piece_list(weakerSide, ROOK, 0);
    if(pos.pawn_attacks(strongerSide, rsq) & pos.pawns(weakerSide))
      return ScaleFactor(0);
  }
  return SCALE_FACTOR_NONE;
}


/// KRPKRScalingFunction scales KRP vs KR endgames.  This function knows a
/// handful of the most important classes of drawn positions, but is far
/// from perfect.  It would probably be a good idea to add more knowledge
/// in the future.
///
/// It would also be nice to rewrite the actual code for this function,
/// which is mostly copied from Glaurung 1.x, and not very pretty.

ScaleFactor KRPKRScalingFunction::apply(const Position &pos) {
  assert(pos.non_pawn_material(strongerSide) == RookValueMidgame);
  assert(pos.piece_count(strongerSide, PAWN) == 1);
  assert(pos.non_pawn_material(weakerSide) == RookValueMidgame);
  assert(pos.piece_count(weakerSide, PAWN) == 0);

  Square wksq = pos.king_square(strongerSide);
  Square wrsq = pos.piece_list(strongerSide, ROOK, 0);
  Square wpsq = pos.piece_list(strongerSide, PAWN, 0);
  Square bksq = pos.king_square(weakerSide);
  Square brsq = pos.piece_list(weakerSide, ROOK, 0);

  // Orient the board in such a way that the stronger side is white, and the
  // pawn is on the left half of the board:
  if(strongerSide == BLACK) {
    wksq = flip_square(wksq);
    wrsq = flip_square(wrsq);
    wpsq = flip_square(wpsq);
    bksq = flip_square(bksq);
    brsq = flip_square(brsq);
  }
  if(square_file(wpsq) > FILE_D) {
    wksq = flop_square(wksq);
    wrsq = flop_square(wrsq);
    wpsq = flop_square(wpsq);
    bksq = flop_square(bksq);
    brsq = flop_square(brsq);
  }

  File f = square_file(wpsq);
  Rank r = square_rank(wpsq);
  Square queeningSq = make_square(f, RANK_8);
  int tempo = (pos.side_to_move() == strongerSide);

  // If the pawn is not too far advanced and the defending king defends the
  // queening square, use the third-rank defence:
  if(r <= RANK_5 && square_distance(bksq, queeningSq) <= 1 && wksq <= SQ_H5 &&
     (square_rank(brsq) == RANK_6 || (r <= RANK_3 &&
                                      square_rank(wrsq) != RANK_6)))
    return ScaleFactor(0);

  // The defending side saves a draw by checking from behind in case the pawn
  // has advanced to the 6th rank with the king behind.
  if(r == RANK_6 && square_distance(bksq, queeningSq) <= 1 &&
     square_rank(wksq) + tempo <= RANK_6 &&
     (square_rank(brsq) == RANK_1 ||
      (!tempo && abs(square_file(brsq) - f) >= 3)))
    return ScaleFactor(0);

  if(r >= RANK_6 && bksq == queeningSq && square_rank(brsq) == RANK_1 &&
     (!tempo || square_distance(wksq, wpsq) >= 2))
    return ScaleFactor(0);

  // White pawn on a7 and rook on a8 is a draw if black's king is on g7 or h7
  // and the black rook is behind the pawn.
  if(wpsq == SQ_A7 && wrsq == SQ_A8 && (bksq == SQ_H7 || bksq == SQ_G7) &&
     square_file(brsq) == FILE_A &&
     (square_rank(brsq) <= RANK_3 || square_file(wksq) >= FILE_D ||
      square_rank(wksq) <= RANK_5))
    return ScaleFactor(0);

  // If the defending king blocks the pawn and the attacking king is too far
  // away, it's a draw.
  if(r <= RANK_5 && bksq == wpsq + DELTA_N &&
     square_distance(wksq, wpsq) - tempo >= 2 &&
     square_distance(wksq, brsq) - tempo >= 2)
    return ScaleFactor(0);

  // Pawn on the 7th rank supported by the rook from behind usually wins if the
  // attacking king is closer to the queening square than the defending king,
  // and the defending king cannot gain tempi by threatening the attacking
  // rook.
  if(r == RANK_7 && f != FILE_A && square_file(wrsq) == f
     && wrsq != queeningSq
     && (square_distance(wksq, queeningSq) <
         square_distance(bksq, queeningSq) - 2 + tempo)
     && (square_distance(wksq, queeningSq) <
         square_distance(bksq, wrsq) + tempo))
    return ScaleFactor(SCALE_FACTOR_MAX
                       - 2 * square_distance(wksq, queeningSq));

  // Similar to the above, but with the pawn further back:
  if(f != FILE_A && square_file(wrsq) == f && wrsq < wpsq
     && (square_distance(wksq, queeningSq) <
         square_distance(bksq, queeningSq) - 2 + tempo)
     && (square_distance(wksq, wpsq + DELTA_N) <
         square_distance(bksq, wpsq + DELTA_N) - 2 + tempo)
     && (square_distance(bksq, wrsq) + tempo >= 3
         || (square_distance(wksq, queeningSq) <
             square_distance(bksq, wrsq) + tempo
             && (square_distance(wksq, wpsq + DELTA_N) <
                 square_distance(bksq, wrsq) + tempo))))
    return
      ScaleFactor(SCALE_FACTOR_MAX
                  - (8 * square_distance(wpsq, queeningSq) +
                     2 * square_distance(wksq, queeningSq)));

  return SCALE_FACTOR_NONE;
}


/// KRPPKRPScalingFunction scales KRPP vs KRP endgames.  There is only a
/// single pattern:  If the stronger side has no pawns and the defending king
/// is actively placed, the position is drawish.

ScaleFactor KRPPKRPScalingFunction::apply(const Position &pos) {
  assert(pos.non_pawn_material(strongerSide) == RookValueMidgame);
  assert(pos.piece_count(strongerSide, PAWN) == 2);
  assert(pos.non_pawn_material(weakerSide) == RookValueMidgame);
  assert(pos.piece_count(weakerSide, PAWN) == 1);

  Square wpsq1 = pos.piece_list(strongerSide, PAWN, 0);
  Square wpsq2 = pos.piece_list(strongerSide, PAWN, 1);
  Square bksq = pos.king_square(weakerSide);

  // Does the stronger side have a passed pawn?
  if(pos.pawn_is_passed(strongerSide, wpsq1) ||
     pos.pawn_is_passed(strongerSide, wpsq2))
    return SCALE_FACTOR_NONE;

  Rank r = Max(relative_rank(strongerSide, wpsq1), relative_rank(strongerSide, wpsq2));

  if(file_distance(bksq, wpsq1) <= 1 && file_distance(bksq, wpsq2) <= 1
     && relative_rank(strongerSide, bksq) > r) {
    switch(r) {

    case RANK_2: return ScaleFactor(10);
    case RANK_3: return ScaleFactor(10);
    case RANK_4: return ScaleFactor(15);
    case RANK_5: return ScaleFactor(20);
    case RANK_6: return ScaleFactor(40);
    default: assert(false);

    }
  }
  return SCALE_FACTOR_NONE;
}


/// KPsKScalingFunction scales endgames with king and two or more pawns
/// against king.  There is just a single rule here:  If all pawns are on
/// the same rook file and are blocked by the defending king, it's a draw.

ScaleFactor KPsKScalingFunction::apply(const Position &pos) {
  assert(pos.non_pawn_material(strongerSide) == Value(0));
  assert(pos.piece_count(strongerSide, PAWN) >= 2);
  assert(pos.non_pawn_material(weakerSide) == Value(0));
  assert(pos.piece_count(weakerSide, PAWN) == 0);

  Bitboard pawns = pos.pawns(strongerSide);

  // Are all pawns on the 'a' file?
  if((pawns & ~FileABB) == EmptyBoardBB) {
    // Does the defending king block the pawns?
    Square ksq = pos.king_square(weakerSide);
    if(square_distance(ksq, relative_square(strongerSide, SQ_A8)) <= 1)
      return ScaleFactor(0);
    else if(square_file(ksq) == FILE_A &&
       (in_front_bb(strongerSide, ksq) & pawns) == EmptyBoardBB)
      return ScaleFactor(0);
    else
      return SCALE_FACTOR_NONE;
  }
  // Are all pawns on the 'h' file?
  else if((pawns & ~FileHBB) == EmptyBoardBB) {
    // Does the defending king block the pawns?
    Square ksq = pos.king_square(weakerSide);
    if(square_distance(ksq, relative_square(strongerSide, SQ_H8)) <= 1)
      return ScaleFactor(0);
    else if(square_file(ksq) == FILE_H &&
       (in_front_bb(strongerSide, ksq) & pawns) == EmptyBoardBB)
      return ScaleFactor(0);
    else
      return SCALE_FACTOR_NONE;
  }
  else
    return SCALE_FACTOR_NONE;
}


/// KBPKBScalingFunction scales KBP vs KB endgames.  There are two rules:
/// If the defending king is somewhere along the path of the pawn, and the
/// square of the king is not of the same color as the stronger side's bishop,
/// it's a draw.  If the two bishops have opposite color, it's almost always
/// a draw.

ScaleFactor KBPKBScalingFunction::apply(const Position &pos) {
  assert(pos.non_pawn_material(strongerSide) == BishopValueMidgame);
  assert(pos.piece_count(strongerSide, BISHOP) == 1);
  assert(pos.piece_count(strongerSide, PAWN) == 1);
  assert(pos.non_pawn_material(weakerSide) == BishopValueMidgame);
  assert(pos.piece_count(weakerSide, BISHOP) == 1);
  assert(pos.piece_count(weakerSide, PAWN) == 0);

  Square pawnSq = pos.piece_list(strongerSide, PAWN, 0);
  Square strongerBishopSq = pos.piece_list(strongerSide, BISHOP, 0);
  Square weakerBishopSq = pos.piece_list(weakerSide, BISHOP, 0);
  Square weakerKingSq = pos.king_square(weakerSide);

  // Case 1: Defending king blocks the pawn, and cannot be driven away.
  if(square_file(weakerKingSq) == square_file(pawnSq)
     && relative_rank(strongerSide, pawnSq) < relative_rank(strongerSide, weakerKingSq)
     && (square_color(weakerKingSq) != square_color(strongerBishopSq)
         || relative_rank(strongerSide, weakerKingSq) <= RANK_6))
    return ScaleFactor(0);

  // Case 2: Opposite colored bishops.
  if(square_color(strongerBishopSq) != square_color(weakerBishopSq)) {
    
    // We assume that the position is drawn in the following three situations:
    //  
    //   a. The pawn is on rank 5 or further back.
    //   b. The defending king is somewhere in the pawn's path.
    //   c. The defending bishop attacks some square along the pawn's path,
    //      and is at least three squares away from the pawn.
    //
    // These rules are probably not perfect, but in practice they work
    // reasonably well.
    
    if(relative_rank(strongerSide, pawnSq) <= RANK_5)
      return ScaleFactor(0);
    else {
      Bitboard ray =
        ray_bb(pawnSq, (strongerSide == WHITE)? SIGNED_DIR_N : SIGNED_DIR_S);
      if(ray & pos.kings(weakerSide))
        return ScaleFactor(0);
      if((pos.piece_attacks<BISHOP>(weakerBishopSq) & ray)
         && square_distance(weakerBishopSq, pawnSq) >= 3)
        return ScaleFactor(0);
    }
  }
  return SCALE_FACTOR_NONE;
}


/// KBPKNScalingFunction scales KBP vs KN endgames.  There is a single rule:
/// If the defending king is somewhere along the path of the pawn, and the
/// square of the king is not of the same color as the stronger side's bishop,
/// it's a draw.

ScaleFactor KBPKNScalingFunction::apply(const Position &pos) {
  assert(pos.non_pawn_material(strongerSide) == BishopValueMidgame);
  assert(pos.piece_count(strongerSide, BISHOP) == 1);
  assert(pos.piece_count(strongerSide, PAWN) == 1);
  assert(pos.non_pawn_material(weakerSide) == KnightValueMidgame);
  assert(pos.piece_count(weakerSide, KNIGHT) == 1);
  assert(pos.piece_count(weakerSide, PAWN) == 0);

  Square pawnSq = pos.piece_list(strongerSide, PAWN, 0);
  Square strongerBishopSq = pos.piece_list(strongerSide, BISHOP, 0);
  Square weakerKingSq = pos.king_square(weakerSide);
      
  if(square_file(weakerKingSq) == square_file(pawnSq)
     && relative_rank(strongerSide, pawnSq) < relative_rank(strongerSide, weakerKingSq)
     && (square_color(weakerKingSq) != square_color(strongerBishopSq)
         || relative_rank(strongerSide, weakerKingSq) <= RANK_6))
    return ScaleFactor(0);

  return SCALE_FACTOR_NONE;
}


/// KNPKScalingFunction scales KNP vs K endgames.  There is a single rule:
/// If the pawn is a rook pawn on the 7th rank and the defending king prevents
/// the pawn from advancing, the position is drawn.

ScaleFactor KNPKScalingFunction::apply(const Position &pos) {
  assert(pos.non_pawn_material(strongerSide) == KnightValueMidgame);
  assert(pos.piece_count(strongerSide, KNIGHT) == 1);
  assert(pos.piece_count(strongerSide, PAWN) == 1);
  assert(pos.non_pawn_material(weakerSide) == Value(0));
  assert(pos.piece_count(weakerSide, PAWN) == 0);

  Square pawnSq = pos.piece_list(strongerSide, PAWN, 0);
  Square weakerKingSq = pos.king_square(weakerSide);

  if(pawnSq == relative_square(strongerSide, SQ_A7) &&
     square_distance(weakerKingSq, relative_square(strongerSide, SQ_A8)) <= 1)
    return ScaleFactor(0);

  if(pawnSq == relative_square(strongerSide, SQ_H7) &&
     square_distance(weakerKingSq, relative_square(strongerSide, SQ_H8)) <= 1)
    return ScaleFactor(0);

  return SCALE_FACTOR_NONE;
}


/// KPKPScalingFunction scales KP vs KP endgames.  This is done by removing
/// the weakest side's pawn and probing the KP vs K bitbase:  If the weakest
/// side has a draw without the pawn, she probably has at least a draw with
/// the pawn as well.  The exception is when the stronger side's pawn is far
/// advanced and not on a rook file; in this case it is often possible to win
/// (e.g. 8/4k3/3p4/3P4/6K1/8/8/8 w - - 0 1).

ScaleFactor KPKPScalingFunction::apply(const Position &pos) {
  assert(pos.non_pawn_material(strongerSide) == Value(0));
  assert(pos.non_pawn_material(weakerSide) == Value(0));
  assert(pos.piece_count(WHITE, PAWN) == 1);
  assert(pos.piece_count(BLACK, PAWN) == 1);

  Square wksq, bksq, wpsq;
  Color stm;

  if(strongerSide == WHITE) {
    wksq = pos.king_square(WHITE);
    bksq = pos.king_square(BLACK);
    wpsq = pos.piece_list(WHITE, PAWN, 0);
    stm = pos.side_to_move();
  }
  else {
    wksq = flip_square(pos.king_square(BLACK));
    bksq = flip_square(pos.king_square(WHITE));
    wpsq = flip_square(pos.piece_list(BLACK, PAWN, 0));
    stm = opposite_color(pos.side_to_move());
  }

  if(square_file(wpsq) >= FILE_E) {
    wksq = flop_square(wksq);
    bksq = flop_square(bksq);
    wpsq = flop_square(wpsq);
  }

  // If the pawn has advanced to the fifth rank or further, and is not a
  // rook pawn, it's too dangerous to assume that it's at least a draw.
  if(square_rank(wpsq) >= RANK_5 && square_file(wpsq) != FILE_A)
    return SCALE_FACTOR_NONE;

  // Probe the KPK bitbase with the weakest side's pawn removed.  If it's a
  // draw, it's probably at least a draw even with the pawn.
  if(probe_kpk(wksq, wpsq, bksq, stm))
    return SCALE_FACTOR_NONE;
  else
    return ScaleFactor(0);
}


/// init_bitbases() is called during program initialization, and simply loads
/// bitbases from disk into memory.  At the moment, there is only the bitbase
/// for KP vs K, but we may decide to add other bitbases later.

void init_bitbases() {
  generate_kpk_bitbase(KPKBitbase);
}


namespace {

  // Probe the KP vs K bitbase:

  int probe_kpk(Square wksq, Square wpsq, Square bksq, Color stm) {
    int wp = int(square_file(wpsq)) + (int(square_rank(wpsq)) - 1) * 4;
    int index = int(stm) + 2*int(bksq) + 128*int(wksq) + 8192*wp;
    
    assert(index >= 0 && index < 24576*8);
    return KPKBitbase[index/8] & (1 << (index&7));
  }
  
}

// ======== evaluate.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cassert>
#include <cstring>

// ---- begin evaluate.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(EVALUATE_H_INCLUDED)
#define EVALUATE_H_INCLUDED

////
//// Includes
////

// ---- begin material.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(MATERIAL_H_INCLUDED)
#define MATERIAL_H_INCLUDED

////
//// Includes
////



////
//// Types
////

/// MaterialInfo is a class which contains various information about a
/// material configuration. It contains a material balance evaluation,
/// a function pointer to a special endgame evaluation function (which in
/// most cases is NULL, meaning that the standard evaluation function will
/// be used), and "scale factors" for black and white.
///
/// The scale factors are used to scale the evaluation score up or down.
/// For instance, in KRB vs KR endgames, the score is scaled down by a factor
/// of 4, which will result in scores of absolute value less than one pawn.

class MaterialInfo {

  friend class MaterialInfoTable;

public:
  Value mg_value() const;
  Value eg_value() const;
  ScaleFactor scale_factor(const Position& pos, Color c) const;
  bool specialized_eval_exists() const;
  Value evaluate(const Position& pos) const;

private:
  void clear();
  
  Key key;
  int16_t mgValue;
  int16_t egValue;
  uint8_t factor[2];
  EndgameEvaluationFunction* evaluationFunction;
  ScalingFunction* scalingFunction[2];
};


/// EndgameFunctions class stores the endgame evaluation functions std::map.
/// Because STL library is not thread safe even for read access, the maps,
/// although with identical content, are replicated for each thread. This
/// is faster then using locks with an unique set of global maps.

class EndgameFunctions;


/// The MaterialInfoTable class represents a pawn hash table. It is basically
/// just an array of MaterialInfo objects and a few methods for accessing these
/// objects. The most important method is get_material_info, which looks up a
/// position in the table and returns a pointer to a MaterialInfo object.

class MaterialInfoTable {

public:
  MaterialInfoTable(unsigned numOfEntries);
  ~MaterialInfoTable();
  void clear();
  MaterialInfo* get_material_info(const Position& pos);

private:
  unsigned size;
  MaterialInfo* entries;
  EndgameFunctions* funcs;
};


////
//// Inline functions
////

/// MaterialInfo::mg_value and MaterialInfo::eg_value simply returns the
/// material balance evaluation for the middle game and the endgame.

inline Value MaterialInfo::mg_value() const {

  return Value(mgValue);
}

inline Value MaterialInfo::eg_value() const {

  return Value(egValue);
}


/// MaterialInfo::clear() resets a MaterialInfo object to an empty state,
/// with all slots at their default values.

inline void MaterialInfo::clear() {

  mgValue = egValue = 0;
  factor[WHITE] = factor[BLACK] = uint8_t(SCALE_FACTOR_NORMAL);
  evaluationFunction = NULL;
  scalingFunction[WHITE] = scalingFunction[BLACK] = NULL;
}


/// MaterialInfo::scale_factor takes a position and a color as input, and
/// returns a scale factor for the given color.  We have to provide the
/// position in addition to the color, because the scale factor need not
/// to be a constant: It can also be a function which should be applied to
/// the position. For instance, in KBP vs K endgames, a scaling function
/// which checks for draws with rook pawns and wrong-colored bishops.

inline ScaleFactor MaterialInfo::scale_factor(const Position& pos, Color c) const {

  if (scalingFunction[c] != NULL)
  {
      ScaleFactor sf = scalingFunction[c]->apply(pos);
      if (sf != SCALE_FACTOR_NONE)
          return sf;
  }
  return ScaleFactor(factor[c]);
}


/// MaterialInfo::specialized_eval_exists decides whether there is a
/// specialized evaluation function for the current material configuration,
/// or if the normal evaluation function should be used.

inline bool MaterialInfo::specialized_eval_exists() const {

  return evaluationFunction != NULL;
}


/// MaterialInfo::evaluate applies a specialized evaluation function
/// to a given position object.  It should only be called when
/// specialized_eval_exists() returns 'true'.

inline Value MaterialInfo::evaluate(const Position& pos) const {

  return evaluationFunction->apply(pos);
}

#endif // !defined(MATERIAL_H_INCLUDED)
// ---- end material.h ----
// ---- begin pawns.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(PAWNS_H_INCLUDED)
#define PAWNS_H_INCLUDED

////
//// Includes
////



////
//// Types
////

/// PawnInfo is a class which contains various information about a pawn 
/// structure.  Currently, it only includes a middle game and an end game
/// pawn structure evaluation, and a bitboard of passed pawns.  We may want
/// to add further information in the future.  A lookup to the pawn hash table
/// (performed by calling the get_pawn_info method in a PawnInfoTable object)
/// returns a pointer to a PawnInfo object.

class PawnInfo {

  friend class PawnInfoTable;

public:
  Value mg_value() const;
  Value eg_value() const;
  Value kingside_storm_value(Color c) const;
  Value queenside_storm_value(Color c) const;
  Bitboard passed_pawns() const;
  bool file_is_half_open(Color c, File f) const;
  bool has_open_file_to_left(Color c, File f) const;
  bool has_open_file_to_right(Color c, File f) const;

private:
  void clear();

  Key key;
  Bitboard passedPawns;
  int16_t mgValue, egValue;
  int8_t ksStormValue[2], qsStormValue[2];
  uint8_t halfOpenFiles[2];
};


/// The PawnInfoTable class represents a pawn hash table.  It is basically
/// just an array of PawnInfo objects and a few methods for accessing these
/// objects.  The most important method is get_pawn_info, which looks up a
/// position in the table and returns a pointer to a PawnInfo object.

class PawnInfoTable {

public:
  PawnInfoTable(unsigned numOfEntries);
  ~PawnInfoTable();
  void clear();
  PawnInfo *get_pawn_info(const Position &pos);

private:
  unsigned size;
  PawnInfo *entries;
};


////
//// Inline functions
////

inline Value PawnInfo::mg_value() const {
  return Value(mgValue);
}

inline Value PawnInfo::eg_value() const {
  return Value(egValue);
}

inline Bitboard PawnInfo::passed_pawns() const {
  return passedPawns;
}

inline Value PawnInfo::kingside_storm_value(Color c) const {
  return Value(ksStormValue[c]);
}

inline Value PawnInfo::queenside_storm_value(Color c) const {
  return Value(qsStormValue[c]);
}

inline bool PawnInfo::file_is_half_open(Color c, File f) const {
  return (halfOpenFiles[c] & (1 << int(f)));
}

inline bool PawnInfo::has_open_file_to_left(Color c, File f) const {
  return halfOpenFiles[c] & ((1 << int(f)) - 1);
}

inline bool PawnInfo::has_open_file_to_right(Color c, File f) const {
  return halfOpenFiles[c] & ~((1 << int(f+1)) - 1);
}

inline void PawnInfo::clear() {
  mgValue = egValue = 0;
  passedPawns = EmptyBoardBB;
  ksStormValue[WHITE] = ksStormValue[BLACK] = 0;
  qsStormValue[WHITE] = qsStormValue[BLACK] = 0;
  halfOpenFiles[WHITE] = halfOpenFiles[BLACK] = 0xFF;
}


#endif // !defined(PAWNS_H_INCLUDED)
// ---- end pawns.h ----


////
//// Types
////

/// The EvalInfo struct contains various information computed and collected
/// by the evaluation function.  An EvalInfo object is passed as one of the
/// arguments to the evaluation function, and the search can make use of its
/// contents to make intelligent search decisions.
///
/// At the moment, this is not utilized very much:  The only part of the
/// EvalInfo object which is used by the search is futilityMargin.

struct EvalInfo {
  
  // Middle game and endgame evaluations:
  Value mgValue, egValue;

  // Pointers to material and pawn hash table entries:
  MaterialInfo *mi;
  PawnInfo *pi;

  // attackedBy[color][piece type] is a bitboard representing all squares
  // attacked by a given color and piece type.  attackedBy[color][0] contains
  // all squares attacked by the given color.
  Bitboard attackedBy[2][8];
  Bitboard attacked_by(Color c) const { return attackedBy[c][0]; }
  Bitboard attacked_by(Color c, PieceType pt) const { return attackedBy[c][pt]; }

  // kingZone[color] is the zone around the enemy king which is considered
  // by the king safety evaluation.  This consists of the squares directly
  // adjacent to the king, and the three (or two, for a king on an edge file)
  // squares two ranks in front of the king.  For instance, if black's king
  // is on g8, kingZone[WHITE] is a bitboard containing the squares f8, h8,
  // f7, g7, h7, f6, g6 and h6.
  Bitboard kingZone[2];

  // kingAttackersCount[color] is the number of pieces of the given color
  // which attack a square in the kingZone of the enemy king.
  int kingAttackersCount[2];

  // kingAttackersWeight[color] is the sum of the "weight" of the pieces of the
  // given color which attack a square in the kingZone of the enemy king. The
  // weights of the individual piece types are given by the variables
  // QueenAttackWeight, RookAttackWeight, BishopAttackWeight and
  // KnightAttackWeight in evaluate.cpp
  int kingAttackersWeight[2];

  // kingAdjacentZoneAttacksCount[color] is the number of attacks to squares
  // directly adjacent to the king of the given color. Pieces which attack
  // more than one square are counted multiple times. For instance, if black's
  // king is on g8 and there's a white knight on g5, this knight adds
  // 2 to kingAdjacentZoneAttacksCount[BLACK].
  int kingAdjacentZoneAttacksCount[2];

  // mateThreat[color] is a move for the given side which gives a direct mate.
  Move mateThreat[2];

  // Middle game and endgame mobility scores.
  Value mgMobility, egMobility;

  // Extra futility margin.  This is added to the standard futility margin
  // in the quiescence search.  
  Value futilityMargin;
};


////
//// Prototypes
////

extern Value evaluate(const Position &pos, EvalInfo &ei, int threadID);
extern Value quick_evaluate(const Position &pos);
extern void init_eval(int threads);
extern void quit_eval();
extern void read_weights(Color sideToMove);


#endif // !defined(EVALUATE_H_INCLUDED)
// ---- end evaluate.h ----


////
//// Local definitions
////

namespace {

  const int Sign[2] = {1, -1};

  // Evaluation grain size, must be a power of 2.
  const int GrainSize = 4;

  // Evaluation weights
  int WeightMobilityMidgame      = 0x100;
  int WeightMobilityEndgame      = 0x100;
  int WeightPawnStructureMidgame = 0x100;
  int WeightPawnStructureEndgame = 0x100;
  int WeightPassedPawnsMidgame   = 0x100;
  int WeightPassedPawnsEndgame   = 0x100;
  int WeightKingSafety[2] = { 0x100, 0x100 };

  // Internal evaluation weights.  These are applied on top of the evaluation
  // weights read from UCI parameters.  The purpose is to be able to change
  // the evaluation weights while keeping the default values of the UCI
  // parameters at 100, which looks prettier.
  const int WeightMobilityMidgameInternal      = 0x100;
  const int WeightMobilityEndgameInternal      = 0x100;
  const int WeightPawnStructureMidgameInternal = 0x100;
  const int WeightPawnStructureEndgameInternal = 0x100;
  const int WeightPassedPawnsMidgameInternal   = 0x100;
  const int WeightPassedPawnsEndgameInternal   = 0x100;
  const int WeightKingSafetyInternal           = 0x100;
  const int WeightKingOppSafetyInternal        = 0x100;

  // Visually better to define tables constants
  typedef Value V;

  // Knight mobility bonus in middle game and endgame, indexed by the number
  // of attacked squares not occupied by friendly piecess.
  const Value MidgameKnightMobilityBonus[] = {
  //    0       1      2     3      4      5      6      7      8
    V(-30), V(-20),V(-10), V(0), V(10), V(20), V(25), V(30), V(30)
  };

  const Value EndgameKnightMobilityBonus[] = {
  //    0       1      2     3      4      5      6      7      8
    V(-30), V(-20),V(-10), V(0), V(10), V(20), V(25), V(30), V(30)
  };

  // Bishop mobility bonus in middle game and endgame, indexed by the number
  // of attacked squares not occupied by friendly pieces.  X-ray attacks through
  // queens are also included.
  const Value MidgameBishopMobilityBonus[] = {
  //    0       1      2      3      4      5      6      7
    V(-30), V(-15),  V(0), V(15), V(30), V(45), V(58), V(66),
  //    8       9     10     11     12     13     14     15
    V( 72), V( 76), V(78), V(80), V(81), V(82), V(83), V(83)
  };

  const Value EndgameBishopMobilityBonus[] = {
  //    0       1      2      3      4      5      6      7
    V(-30), V(-15),  V(0), V(15), V(30), V(45), V(58), V(66),
  //    8       9     10     11     12     13     14     15
    V( 72), V( 76), V(78), V(80), V(81), V(82), V(83), V(83)
  };

  // Rook mobility bonus in middle game and endgame, indexed by the number
  // of attacked squares not occupied by friendly pieces.  X-ray attacks through
  // queens and rooks are also included.
  const Value MidgameRookMobilityBonus[] = {
  //    0       1      2      3      4      5      6      7
    V(-18), V(-12), V(-6),  V(0),  V(6), V(12), V(16), V(21),
  //    8       9     10     11     12     13     14     15
    V( 24), V( 27), V(28), V(29), V(30), V(31), V(32), V(33)
  };

  const Value EndgameRookMobilityBonus[] = {
  //    0       1      2      3      4      5      6      7
    V(-30), V(-18), V(-6),  V(6), V(18), V(30), V(42), V(54),
  //    8       9     10     11     12     13     14     15
    V( 66), V( 74), V(78), V(80), V(81), V(82), V(83), V(83)
  };

  // Queen mobility bonus in middle game and endgame, indexed by the number
  // of attacked squares not occupied by friendly pieces.
  const Value MidgameQueenMobilityBonus[] = {
  //    0      1      2      3      4      5      6      7
    V(-10), V(-8), V(-6), V(-4), V(-2), V( 0), V( 2), V( 4),
  //    8      9     10     11     12     13     14     15
    V(  6), V( 8), V(10), V(12), V(13), V(14), V(15), V(16),
  //   16     17     18     19     20     21     22     23
    V( 16), V(16), V(16), V(16), V(16), V(16), V(16), V(16),
  //   24     25     26     27     28     29     30     31
    V( 16), V(16), V(16), V(16), V(16), V(16), V(16), V(16)
  };

  const Value EndgameQueenMobilityBonus[] = {
  //    0      1      2      3      4      5      6      7
    V(-20),V(-15),V(-10), V(-5), V( 0), V( 5), V(10), V(15),
  //    8      9     10     11     12     13     14     15
    V( 19), V(23), V(27), V(29), V(30), V(30), V(30), V(30),
  //   16     17     18     19     20     21     22     23
    V( 30), V(30), V(30), V(30), V(30), V(30), V(30), V(30),
  //   24     25     26     27     28     29     30     31
    V( 30), V(30), V(30), V(30), V(30), V(30), V(30), V(30)
  };

  // Outpost bonuses for knights and bishops, indexed by square (from white's
  // point of view).
  const Value KnightOutpostBonus[64] = {
  //  A     B     C     D     E     F     G     H
    V(0), V(0), V(0), V(0), V(0), V(0), V(0), V(0), // 1
    V(0), V(0), V(0), V(0), V(0), V(0), V(0), V(0), // 2
    V(0), V(0), V(5),V(10),V(10), V(5), V(0), V(0), // 3
    V(0), V(5),V(20),V(30),V(30),V(20), V(5), V(0), // 4
    V(0),V(10),V(30),V(40),V(40),V(30),V(10), V(0), // 5
    V(0), V(5),V(20),V(20),V(20),V(20), V(5), V(0), // 6
    V(0), V(0), V(0), V(0), V(0), V(0), V(0), V(0), // 7
    V(0), V(0), V(0), V(0), V(0), V(0), V(0), V(0)  // 8
  };

  const Value BishopOutpostBonus[64] = {
  //  A     B     C     D     E     F     G     H
    V(0), V(0), V(0), V(0), V(0), V(0), V(0), V(0), // 1
    V(0), V(0), V(0), V(0), V(0), V(0), V(0), V(0), // 2
    V(0), V(0), V(5), V(5), V(5), V(5), V(0), V(0), // 3
    V(0), V(5),V(10),V(10),V(10),V(10), V(5), V(0), // 4
    V(0),V(10),V(20),V(20),V(20),V(20),V(10), V(0), // 5
    V(0), V(5), V(8), V(8), V(8), V(8), V(5), V(0), // 6
    V(0), V(0), V(0), V(0), V(0), V(0), V(0), V(0), // 7
    V(0), V(0), V(0), V(0), V(0), V(0), V(0), V(0)  // 8
  };

  // Bonus for unstoppable passed pawns:
  const Value UnstoppablePawnValue = Value(0x500);

  // Rooks and queens on the 7th rank:
  const Value MidgameRookOn7thBonus  = Value(50);
  const Value EndgameRookOn7thBonus  = Value(100);
  const Value MidgameQueenOn7thBonus = Value(25);
  const Value EndgameQueenOn7thBonus = Value(50);

  // Rooks on open files:
  const Value RookOpenFileBonus     = Value(40);
  const Value RookHalfOpenFileBonus = Value(20);

  // Penalty for rooks trapped inside a friendly king which has lost the
  // right to castle:
  const Value TrappedRookPenalty = Value(180);

  // Penalty for a bishop on a7/h7 (a2/h2 for black) which is trapped by
  // enemy pawns:
  const Value TrappedBishopA7H7Penalty = Value(300);

  // Bitboard masks for detecting trapped bishops on a7/h7 (a2/h2 for black):
  const Bitboard MaskA7H7[2] = {
    ((1ULL << SQ_A7) | (1ULL << SQ_H7)),
    ((1ULL << SQ_A2) | (1ULL << SQ_H2))
  };

  // Penalty for a bishop on a1/h1 (a8/h8 for black) which is trapped by
  // a friendly pawn on b2/g2 (b7/g7 for black).  This can obviously only
  // happen in Chess960 games.
  const Value TrappedBishopA1H1Penalty = Value(100);

  // Bitboard masks for detecting trapped bishops on a1/h1 (a8/h8 for black):
  const Bitboard MaskA1H1[2] = {
    ((1ULL << SQ_A1) | (1ULL << SQ_H1)),
    ((1ULL << SQ_A8) | (1ULL << SQ_H8))
  };

  /// King safety constants and variables.  The king safety scores are taken
  /// from the array SafetyTable[].  Various little "meta-bonuses" measuring
  /// the strength of the attack are added up into an integer, which is used
  /// as an index to SafetyTable[].

  // Attack weights for each piece type.
  const int QueenAttackWeight  = 5;
  const int RookAttackWeight   = 3;
  const int BishopAttackWeight = 2;
  const int KnightAttackWeight = 2;

  // Bonuses for safe checks for each piece type.
  int QueenContactCheckBonus = 4;
  int RookContactCheckBonus  = 2;
  int QueenCheckBonus        = 2;
  int RookCheckBonus         = 1;
  int BishopCheckBonus       = 1;
  int KnightCheckBonus       = 1;
  int DiscoveredCheckBonus   = 3;

  // Scan for queen contact mates?
  const bool QueenContactMates = true;

  // Bonus for having a mate threat.
  int MateThreatBonus = 3;

  // InitKingDanger[] contains bonuses based on the position of the defending
  // king.
  const int InitKingDanger[64] = {
     2,  0,  2,  5,  5,  2,  0,  2,
     2,  2,  4,  8,  8,  4,  2,  2,
     7, 10, 12, 12, 12, 12, 10,  7,
    15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15
  };

  // SafetyTable[] contains the actual king safety scores.  It is initialized
  // in init_safety().
  Value SafetyTable[101];

  // Pawn and material hash tables, indexed by the current thread id:
  PawnInfoTable *PawnTable[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  MaterialInfoTable *MaterialTable[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  // Sizes of pawn and material hash tables:
  const int PawnTableSize = 16384;
  const int MaterialTableSize = 1024;

  // Array which gives the number of nonzero bits in an 8-bit integer:
  uint8_t BitCount8Bit[256];

  // Function prototypes:
  void evaluate_knight(const Position &p, Square s, Color us, EvalInfo &ei);
  void evaluate_bishop(const Position &p, Square s, Color us, EvalInfo &ei);
  void evaluate_rook(const Position &p, Square s, Color us, EvalInfo &ei);
  void evaluate_queen(const Position &p, Square s, Color us, EvalInfo &ei);
  void evaluate_king(const Position &p, Square s, Color us, EvalInfo &ei);

  void evaluate_passed_pawns(const Position &pos, EvalInfo &ei);
  void evaluate_trapped_bishop_a7h7(const Position &pos, Square s, Color us,
                                    EvalInfo &ei);
  void evaluate_trapped_bishop_a1h1(const Position &pos, Square s, Color us,
                                    EvalInfo &ei);

  inline Value apply_weight(Value v, int w);
  Value scale_by_game_phase(Value mv, Value ev, Phase ph, const ScaleFactor sf[]);

  int count_1s_8bit(Bitboard b);

  int compute_weight(int uciWeight, int internalWeight);
  int weight_option(const std::string& opt, int weight);
  void init_safety();

}


////
//// Functions
////

/// evaluate() is the main evaluation function.  It always computes two
/// values, an endgame score and a middle game score, and interpolates
/// between them based on the remaining material.

Value evaluate(const Position &pos, EvalInfo &ei, int threadID) {

  assert(pos.is_ok());
  assert(threadID >= 0 && threadID < THREAD_MAX);

  memset(&ei, 0, sizeof(EvalInfo));

  // Initialize by reading the incrementally updated scores included in the
  // position object (material + piece square tables)
  ei.mgValue = pos.mg_value();
  ei.egValue = pos.eg_value();

  // Probe the material hash table
  ei.mi = MaterialTable[threadID]->get_material_info(pos);
  ei.mgValue += ei.mi->mg_value();
  ei.egValue += ei.mi->eg_value();

  // If we have a specialized evaluation function for the current material
  // configuration, call it and return
  if (ei.mi->specialized_eval_exists())
      return ei.mi->evaluate(pos);

  // After get_material_info() call that modifies them
  ScaleFactor factor[2];
  factor[WHITE] = ei.mi->scale_factor(pos, WHITE);
  factor[BLACK] = ei.mi->scale_factor(pos, BLACK);

  // Probe the pawn hash table
  ei.pi = PawnTable[threadID]->get_pawn_info(pos);
  ei.mgValue += apply_weight(ei.pi->mg_value(), WeightPawnStructureMidgame);
  ei.egValue += apply_weight(ei.pi->eg_value(), WeightPawnStructureEndgame);

  // Initialize king attack bitboards and king attack zones for both sides
  ei.attackedBy[WHITE][KING] = pos.piece_attacks<KING>(pos.king_square(WHITE));
  ei.attackedBy[BLACK][KING] = pos.piece_attacks<KING>(pos.king_square(BLACK));
  ei.kingZone[WHITE] = ei.attackedBy[BLACK][KING] | (ei.attackedBy[BLACK][KING] >> 8);
  ei.kingZone[BLACK] = ei.attackedBy[WHITE][KING] | (ei.attackedBy[WHITE][KING] << 8);

  // Initialize pawn attack bitboards for both sides
  ei.attackedBy[WHITE][PAWN] = ((pos.pawns(WHITE) << 9) & ~FileABB) | ((pos.pawns(WHITE) << 7) & ~FileHBB);
  ei.attackedBy[BLACK][PAWN] = ((pos.pawns(BLACK) >> 7) & ~FileABB) | ((pos.pawns(BLACK) >> 9) & ~FileHBB);
  ei.kingAttackersCount[WHITE] = count_1s_max_15(ei.attackedBy[WHITE][PAWN] & ei.attackedBy[BLACK][KING])/2;
  ei.kingAttackersCount[BLACK] = count_1s_max_15(ei.attackedBy[BLACK][PAWN] & ei.attackedBy[WHITE][KING])/2;

  // Evaluate pieces
  for (Color c = WHITE; c <= BLACK; c++)
  {
    // Knights
    for (int i = 0; i < pos.piece_count(c, KNIGHT); i++)
        evaluate_knight(pos, pos.piece_list(c, KNIGHT, i), c, ei);

    // Bishops
    for (int i = 0; i < pos.piece_count(c, BISHOP); i++)
        evaluate_bishop(pos, pos.piece_list(c, BISHOP, i), c, ei);

    // Rooks
    for (int i = 0; i < pos.piece_count(c, ROOK); i++)
        evaluate_rook(pos, pos.piece_list(c, ROOK, i), c, ei);

    // Queens
    for(int i = 0; i < pos.piece_count(c, QUEEN); i++)
        evaluate_queen(pos, pos.piece_list(c, QUEEN, i), c, ei);

    // Special pattern: trapped bishops on a7/h7/a2/h2
    Bitboard b = pos.bishops(c) & MaskA7H7[c];
    while (b)
    {
        Square s = pop_1st_bit(&b);
        evaluate_trapped_bishop_a7h7(pos, s, c, ei);
    }

    // Special pattern: trapped bishops on a1/h1/a8/h8 in Chess960:
    if (Chess960)
    {
        b = pos.bishops(c) & MaskA1H1[c];
        while (b)
        {
            Square s = pop_1st_bit(&b);
            evaluate_trapped_bishop_a1h1(pos, s, c, ei);
        }
    }

    // Sum up all attacked squares
    ei.attackedBy[c][0] =   ei.attackedBy[c][PAWN]   | ei.attackedBy[c][KNIGHT]
                          | ei.attackedBy[c][BISHOP] | ei.attackedBy[c][ROOK]
                          | ei.attackedBy[c][QUEEN]  | ei.attackedBy[c][KING];
  }

  // Kings.  Kings are evaluated after all other pieces for both sides,
  // because we need complete attack information for all pieces when computing
  // the king safety evaluation.
  for (Color c = WHITE; c <= BLACK; c++)
      evaluate_king(pos, pos.king_square(c), c, ei);

  // Evaluate passed pawns.  We evaluate passed pawns for both sides at once,
  // because we need to know which side promotes first in positions where
  // both sides have an unstoppable passed pawn.
  if (ei.pi->passed_pawns())
      evaluate_passed_pawns(pos, ei);

  Phase phase = pos.game_phase();

  // Middle-game specific evaluation terms
  if (phase > PHASE_ENDGAME)
  {
    // Pawn storms in positions with opposite castling.
    if (   square_file(pos.king_square(WHITE)) >= FILE_E
        && square_file(pos.king_square(BLACK)) <= FILE_D)

        ei.mgValue += ei.pi->queenside_storm_value(WHITE)
                    - ei.pi->kingside_storm_value(BLACK);

    else if (   square_file(pos.king_square(WHITE)) <= FILE_D
             && square_file(pos.king_square(BLACK)) >= FILE_E)

        ei.mgValue += ei.pi->kingside_storm_value(WHITE)
                    - ei.pi->queenside_storm_value(BLACK);
  }

  // Mobility
  ei.mgValue += apply_weight(ei.mgMobility, WeightMobilityMidgame);
  ei.egValue += apply_weight(ei.egMobility, WeightMobilityEndgame);

  // If we don't already have an unusual scale factor, check for opposite
  // colored bishop endgames, and use a lower scale for those:
  if (   phase < PHASE_MIDGAME
      && pos.opposite_colored_bishops()
      && (   (factor[WHITE] == SCALE_FACTOR_NORMAL && ei.egValue > Value(0))
          || (factor[BLACK] == SCALE_FACTOR_NORMAL && ei.egValue < Value(0))))
  {
      ScaleFactor sf;

      // Only the two bishops ?
      if (   pos.non_pawn_material(WHITE) == BishopValueMidgame
          && pos.non_pawn_material(BLACK) == BishopValueMidgame)
      {
          // Check for KBP vs KB with only a single pawn that is almost
          // certainly a draw or at least two pawns.
          bool one_pawn = (pos.piece_count(WHITE, PAWN) + pos.piece_count(BLACK, PAWN) == 1);
          sf = one_pawn ? ScaleFactor(8) : ScaleFactor(32);
      }
      else
          // Endgame with opposite-colored bishops, but also other pieces. Still
          // a bit drawish, but not as drawish as with only the two bishops.
           sf = ScaleFactor(50);

      if (factor[WHITE] == SCALE_FACTOR_NORMAL)
          factor[WHITE] = sf;
      if (factor[BLACK] == SCALE_FACTOR_NORMAL)
          factor[BLACK] = sf;
  }

  // Interpolate between the middle game and the endgame score, and
  // return
  Color stm = pos.side_to_move();

  Value v = Sign[stm] * scale_by_game_phase(ei.mgValue, ei.egValue, phase, factor);

  return (ei.mateThreat[stm] == MOVE_NONE ? v : 8 * QueenValueMidgame - v);
}


/// quick_evaluate() does a very approximate evaluation of the current position.
/// It currently considers only material and piece square table scores.  Perhaps
/// we should add scores from the pawn and material hash tables?

Value quick_evaluate(const Position &pos) {

  assert(pos.is_ok());

  static const
  ScaleFactor sf[2] = {SCALE_FACTOR_NORMAL, SCALE_FACTOR_NORMAL};  

  Value mgv = pos.mg_value();
  Value egv = pos.eg_value();
  Phase ph = pos.game_phase();
  Color stm = pos.side_to_move();

  return Sign[stm] * scale_by_game_phase(mgv, egv, ph, sf);
}


/// init_eval() initializes various tables used by the evaluation function.

void init_eval(int threads) {

  assert(threads <= THREAD_MAX);

  for (int i = 0; i < THREAD_MAX; i++)
  {
    if (i >= threads)
    {
        delete PawnTable[i];
        delete MaterialTable[i];
        PawnTable[i] = NULL;
        MaterialTable[i] = NULL;
        continue;
    }
    if (!PawnTable[i])
        PawnTable[i] = new PawnInfoTable(PawnTableSize);
    if (!MaterialTable[i])
        MaterialTable[i] = new MaterialInfoTable(MaterialTableSize);
  }

  for (Bitboard b = 0ULL; b < 256ULL; b++)
      BitCount8Bit[b] = count_1s(b);
}


/// quit_eval() releases heap-allocated memory at program termination.

void quit_eval() {

  for (int i = 0; i < THREAD_MAX; i++)
  {
      delete PawnTable[i];
      delete MaterialTable[i];
  }
}


/// read_weights() reads evaluation weights from the corresponding UCI
/// parameters.

void read_weights(Color us) {

  WeightMobilityMidgame      = weight_option("Mobility (Middle Game)", WeightMobilityMidgameInternal);
  WeightMobilityEndgame      = weight_option("Mobility (Endgame)", WeightMobilityEndgameInternal);
  WeightPawnStructureMidgame = weight_option("Pawn Structure (Middle Game)", WeightPawnStructureMidgameInternal);
  WeightPawnStructureEndgame = weight_option("Pawn Structure (Endgame)", WeightPawnStructureEndgameInternal);
  WeightPassedPawnsMidgame   = weight_option("Passed Pawns (Middle Game)", WeightPassedPawnsMidgameInternal);
  WeightPassedPawnsEndgame   = weight_option("Passed Pawns (Endgame)", WeightPassedPawnsEndgameInternal);

  Color them = opposite_color(us);

  WeightKingSafety[us]   = weight_option("Cowardice", WeightKingSafetyInternal);
  WeightKingSafety[them] = weight_option("Aggressiveness", WeightKingOppSafetyInternal);

  init_safety();
}


namespace {

  // evaluate_common() computes terms common to all pieces attack

  int evaluate_common(const Position&p, const Bitboard& b, Color us, EvalInfo& ei,
                       int AttackWeight, const Value* mgBonus, const Value* egBonus,
                       Square s = SQ_NONE, const Value* OutpostBonus = NULL) {

    Color them = opposite_color(us);

    // King attack
    if (b & ei.kingZone[us])
    {
        ei.kingAttackersCount[us]++;
        ei.kingAttackersWeight[us] += AttackWeight;
        Bitboard bb = (b & ei.attackedBy[them][KING]);
        if (bb)
            ei.kingAdjacentZoneAttacksCount[us] += count_1s_max_15(bb);
    }

    // Mobility
    int mob = count_1s_max_15(b & ~p.pieces_of_color(us));
    ei.mgMobility += Sign[us] * mgBonus[mob];
    ei.egMobility += Sign[us] * egBonus[mob];

    // Bishop and Knight outposts
    if (!OutpostBonus || !p.square_is_weak(s, them))
        return mob;

    // Initial bonus based on square
    Value v, bonus;
    v = bonus = OutpostBonus[relative_square(us, s)];

    // Increase bonus if supported by pawn, especially if the opponent has
    // no minor piece which can exchange the outpost piece
    if (v && (p.pawn_attacks(them, s) & p.pawns(us)))
    {
        bonus += v / 2;
        if (   p.piece_count(them, KNIGHT) == 0
            && (SquaresByColorBB[square_color(s)] & p.bishops(them)) == EmptyBoardBB)
            bonus += v;
    }
    ei.mgValue += Sign[us] * bonus;
    ei.egValue += Sign[us] * bonus;
    return mob;
  }


  // evaluate_knight() assigns bonuses and penalties to a knight of a given
  // color on a given square.

  void evaluate_knight(const Position &p, Square s, Color us, EvalInfo &ei) {

    Bitboard b = p.piece_attacks<KNIGHT>(s);
    ei.attackedBy[us][KNIGHT] |= b;

    // King attack, mobility and outposts
    evaluate_common(p, b, us, ei, KnightAttackWeight, MidgameKnightMobilityBonus,
                    EndgameKnightMobilityBonus, s, KnightOutpostBonus);
  }


  // evaluate_bishop() assigns bonuses and penalties to a bishop of a given
  // color on a given square.

  void evaluate_bishop(const Position &p, Square s, Color us, EvalInfo &ei) {

    Bitboard b = bishop_attacks_bb(s, p.occupied_squares() & ~p.queens(us));
    ei.attackedBy[us][BISHOP] |= b;

    // King attack, mobility and outposts
    evaluate_common(p, b, us, ei, BishopAttackWeight, MidgameBishopMobilityBonus,
                    EndgameBishopMobilityBonus, s, BishopOutpostBonus);
  }


  // evaluate_rook() assigns bonuses and penalties to a rook of a given
  // color on a given square.

  void evaluate_rook(const Position &p, Square s, Color us, EvalInfo &ei) {

    //Bitboard b = p.rook_attacks(s);
    Bitboard b = rook_attacks_bb(s, p.occupied_squares() & ~p.rooks_and_queens(us));
    ei.attackedBy[us][ROOK] |= b;

    // King attack and mobility
    int mob = evaluate_common(p, b, us, ei, RookAttackWeight, MidgameRookMobilityBonus,
                              EndgameRookMobilityBonus);

    // Rook on 7th rank
    Color them = opposite_color(us);

    if (   relative_rank(us, s) == RANK_7
        && relative_rank(us, p.king_square(them)) == RANK_8)
    {
        ei.mgValue += Sign[us] * MidgameRookOn7thBonus;
        ei.egValue += Sign[us] * EndgameRookOn7thBonus;
    }

    // Open and half-open files
    File f = square_file(s);
    if (ei.pi->file_is_half_open(us, f))
    {
        if (ei.pi->file_is_half_open(them, f))
        {
            ei.mgValue += Sign[us] * RookOpenFileBonus;
            ei.egValue += Sign[us] * RookOpenFileBonus;
        }
        else
        {
            ei.mgValue += Sign[us] * RookHalfOpenFileBonus;
            ei.egValue += Sign[us] * RookHalfOpenFileBonus;
        }
    }

    // Penalize rooks which are trapped inside a king. Penalize more if
    // king has lost right to castle
    if (mob > 6 || ei.pi->file_is_half_open(us, f))
        return;

    Square ksq = p.king_square(us);

    if (    square_file(ksq) >= FILE_E
        &&  square_file(s) > square_file(ksq)
        && (relative_rank(us, ksq) == RANK_1 || square_rank(ksq) == square_rank(s)))
    {
        // Is there a half-open file between the king and the edge of the board?
        if (!ei.pi->has_open_file_to_right(us, square_file(ksq)))
            ei.mgValue -= p.can_castle(us)? Sign[us] * ((TrappedRookPenalty - mob * 16) / 2)
                                          : Sign[us] *  (TrappedRookPenalty - mob * 16);
    }
    else if (    square_file(ksq) <= FILE_D
             &&  square_file(s) < square_file(ksq)
             && (relative_rank(us, ksq) == RANK_1 || square_rank(ksq) == square_rank(s)))
    {
        // Is there a half-open file between the king and the edge of the board?
        if (!ei.pi->has_open_file_to_left(us, square_file(ksq)))
            ei.mgValue -= p.can_castle(us)? Sign[us] * ((TrappedRookPenalty - mob * 16) / 2)
                                          : Sign[us] * (TrappedRookPenalty - mob * 16);
    }
  }


  // evaluate_queen() assigns bonuses and penalties to a queen of a given
  // color on a given square.

  void evaluate_queen(const Position &p, Square s, Color us, EvalInfo &ei) {

    Bitboard b = p.piece_attacks<QUEEN>(s);
    ei.attackedBy[us][QUEEN] |= b;

    // King attack and mobility
    evaluate_common(p, b, us, ei, QueenAttackWeight, MidgameQueenMobilityBonus,
                    EndgameQueenMobilityBonus);

    // Queen on 7th rank
    Color them = opposite_color(us);

    if (   relative_rank(us, s) == RANK_7
        && relative_rank(us, p.king_square(them)) == RANK_8)
    {
        ei.mgValue += Sign[us] * MidgameQueenOn7thBonus;
        ei.egValue += Sign[us] * EndgameQueenOn7thBonus;
    }
  }

  inline Bitboard shiftRowsDown(const Bitboard& b, int num) {

    return b >> (num << 3);
  }

  // evaluate_king() assigns bonuses and penalties to a king of a given
  // color on a given square.

  void evaluate_king(const Position &p, Square s, Color us, EvalInfo &ei) {

    int shelter = 0, sign = Sign[us];

    // King shelter
    if (relative_rank(us, s) <= RANK_4)
    {
        Bitboard pawns = p.pawns(us) & this_and_neighboring_files_bb(s);
        Rank r = square_rank(s);
        for (int i = 1; i < 4; i++)
            shelter += count_1s_8bit(shiftRowsDown(pawns, r+i*sign)) * (128>>i);

        ei.mgValue += sign * Value(shelter);
    }

    // King safety.  This is quite complicated, and is almost certainly far
    // from optimally tuned.
    Color them = opposite_color(us);

    if (   p.piece_count(them, QUEEN) >= 1
        && ei.kingAttackersCount[them] >= 2
        && p.non_pawn_material(them) >= QueenValueMidgame + RookValueMidgame
        && ei.kingAdjacentZoneAttacksCount[them])
    {
      // Is it the attackers turn to move?
      bool sente = (them == p.side_to_move());

      // Find the attacked squares around the king which has no defenders
      // apart from the king itself
      Bitboard undefended =
             ei.attacked_by(them)       & ~ei.attacked_by(us, PAWN)
          & ~ei.attacked_by(us, KNIGHT) & ~ei.attacked_by(us, BISHOP)
          & ~ei.attacked_by(us, ROOK)   & ~ei.attacked_by(us, QUEEN)
          & ei.attacked_by(us, KING);

      Bitboard occ = p.occupied_squares(), b, b2;

      // Initialize the 'attackUnits' variable, which is used later on as an
      // index to the SafetyTable[] array.  The initial is based on the number
      // and types of the attacking pieces, the number of attacked and
      // undefended squares around the king, the square of the king, and the
      // quality of the pawn shelter.
      int attackUnits =
            Min((ei.kingAttackersCount[them] * ei.kingAttackersWeight[them]) / 2, 25)
          + (ei.kingAdjacentZoneAttacksCount[them] + count_1s_max_15(undefended)) * 3
          + InitKingDanger[relative_square(us, s)] - shelter / 32;

      // Analyse safe queen contact checks
      b = undefended & ei.attacked_by(them, QUEEN) & ~p.pieces_of_color(them);
      if (b)
      {
        Bitboard attackedByOthers =
              ei.attacked_by(them, PAWN)   | ei.attacked_by(them, KNIGHT)
            | ei.attacked_by(them, BISHOP) | ei.attacked_by(them, ROOK);

        b &= attackedByOthers;
        if (b)
        {
          // The bitboard b now contains the squares available for safe queen
          // contact checks.
          int count = count_1s_max_15(b);
          attackUnits += QueenContactCheckBonus * count * (sente ? 2 : 1);

          // Is there a mate threat?
          if (QueenContactMates && !p.is_check())
          {
            Bitboard escapeSquares =
                p.piece_attacks<KING>(s) & ~p.pieces_of_color(us) & ~attackedByOthers;

            while (b)
            {
                Square from, to = pop_1st_bit(&b);
                if (!(escapeSquares & ~queen_attacks_bb(to, occ & ClearMaskBB[s])))
                {
                    // We have a mate, unless the queen is pinned or there
                    // is an X-ray attack through the queen.
                    for (int i = 0; i < p.piece_count(them, QUEEN); i++)
                    {
                        from = p.piece_list(them, QUEEN, i);
                        if (    bit_is_set(p.piece_attacks<QUEEN>(from), to)
                            && !bit_is_set(p.pinned_pieces(them), from)
                            && !(rook_attacks_bb(to, occ & ClearMaskBB[from]) & p.rooks_and_queens(us))
                            && !(rook_attacks_bb(to, occ & ClearMaskBB[from]) & p.rooks_and_queens(us)))
                            
                            ei.mateThreat[them] = make_move(from, to);
                    }
                }
            }
          }
        }
      }
      // Analyse safe rook contact checks:
      if (RookContactCheckBonus)
      {
          b = undefended & ei.attacked_by(them, ROOK) & ~p.pieces_of_color(them);
          if (b)
          {
              Bitboard attackedByOthers =
                    ei.attacked_by(them, PAWN)   | ei.attacked_by(them, KNIGHT)
                  | ei.attacked_by(them, BISHOP) | ei.attacked_by(them, QUEEN);

              b &= attackedByOthers;
              if (b)
              {
                  int count = count_1s_max_15(b);
                  attackUnits += (RookContactCheckBonus * count * (sente? 2 : 1));
              }
          }
      }
      // Analyse safe distance checks:
      if (QueenCheckBonus > 0 || RookCheckBonus > 0)
      {
          b = p.piece_attacks<ROOK>(s) & ~p.pieces_of_color(them) & ~ei.attacked_by(us);

          // Queen checks
          b2 = b & ei.attacked_by(them, QUEEN);
          if( b2)
              attackUnits += QueenCheckBonus * count_1s_max_15(b2);

          // Rook checks
          b2 = b & ei.attacked_by(them, ROOK);
          if (b2)
              attackUnits += RookCheckBonus * count_1s_max_15(b2);
      }
      if (QueenCheckBonus > 0 || BishopCheckBonus > 0)
      {
          b = p.piece_attacks<BISHOP>(s) & ~p.pieces_of_color(them) & ~ei.attacked_by(us);

          // Queen checks
          b2 = b & ei.attacked_by(them, QUEEN);
          if (b2)
              attackUnits += QueenCheckBonus * count_1s_max_15(b2);

          // Bishop checks
          b2 = b & ei.attacked_by(them, BISHOP);
          if (b2)
              attackUnits += BishopCheckBonus * count_1s_max_15(b2);
      }
      if (KnightCheckBonus > 0)
      {
          b = p.piece_attacks<KNIGHT>(s) & ~p.pieces_of_color(them) & ~ei.attacked_by(us);

          // Knight checks
          b2 = b & ei.attacked_by(them, KNIGHT);
          if (b2)
              attackUnits += KnightCheckBonus * count_1s_max_15(b2);
      }

      // Analyse discovered checks (only for non-pawns right now, consider
      // adding pawns later).
      if (DiscoveredCheckBonus)
      {
        b = p.discovered_check_candidates(them) & ~p.pawns();
        if (b)
          attackUnits += DiscoveredCheckBonus * count_1s_max_15(b) * (sente? 2 : 1);
      }

      // Has a mate threat been found?  We don't do anything here if the
      // side with the mating move is the side to move, because in that
      // case the mating side will get a huge bonus at the end of the main
      // evaluation function instead.
      if (ei.mateThreat[them] != MOVE_NONE)
          attackUnits += MateThreatBonus;

      // Ensure that attackUnits is between 0 and 99, in order to avoid array
      // out of bounds errors:
      if (attackUnits < 0)
          attackUnits = 0;

      if (attackUnits >= 100)
          attackUnits = 99;

      // Finally, extract the king safety score from the SafetyTable[] array.
      // Add the score to the evaluation, and also to ei.futilityMargin.  The
      // reason for adding the king safety score to the futility margin is
      // that the king safety scores can sometimes be very big, and that
      // capturing a single attacking piece can therefore result in a score
      // change far bigger than the value of the captured piece.
      Value v = apply_weight(SafetyTable[attackUnits], WeightKingSafety[us]);

      ei.mgValue -= sign * v;

      if (us == p.side_to_move())
          ei.futilityMargin += v;
    }
  }


  // evaluate_passed_pawns() evaluates the passed pawns for both sides.

  void evaluate_passed_pawns(const Position &pos, EvalInfo &ei) {
    bool hasUnstoppable[2] = {false, false};
    int movesToGo[2] = {100, 100};

    for(Color us = WHITE; us <= BLACK; us++) {
      Color them = opposite_color(us);
      Square ourKingSq = pos.king_square(us);
      Square theirKingSq = pos.king_square(them);
      Bitboard b = ei.pi->passed_pawns() & pos.pawns(us), b2, b3, b4;

      while(b) {
        Square s = pop_1st_bit(&b);
        assert(pos.piece_on(s) == pawn_of_color(us));
        assert(pos.pawn_is_passed(us, s));

        int r = int(relative_rank(us, s) - RANK_2);
        int tr = Max(0, r * (r-1));
        Square blockSq = s + pawn_push(us);

        // Base bonus based on rank:
        Value mbonus = Value(20 * tr);
        Value ebonus = Value(10 + r * r * 10);

        // Adjust bonus based on king proximity:
        ebonus -= Value(square_distance(ourKingSq, blockSq) * 3 * tr);
        ebonus -=
          Value(square_distance(ourKingSq, blockSq + pawn_push(us)) * 1 * tr);
        ebonus += Value(square_distance(theirKingSq, blockSq) * 6 * tr);

        // If the pawn is free to advance, increase bonus:
        if(pos.square_is_empty(blockSq)) {

          b2 = squares_in_front_of(us, s);
          b3 = b2 & ei.attacked_by(them);
          b4 = b2 & ei.attacked_by(us);
          if((b2 & pos.pieces_of_color(them)) == EmptyBoardBB) {
            // There are no enemy pieces in the pawn's path!  Are any of the
            // squares in the pawn's path attacked by the enemy?
            if(b3 == EmptyBoardBB)
              // No enemy attacks, huge bonus!
              ebonus += Value(tr * ((b2 == b4)? 17 : 15));
            else
              // OK, there are enemy attacks.  Are those squares which are
              // attacked by the enemy also attacked by us?  If yes, big bonus
              // (but smaller than when there are no enemy attacks), if no,
              // somewhat smaller bonus.
              ebonus += Value(tr * (((b3 & b4) == b3)? 13 : 8));
          }
          else {
            // There are some enemy pieces in the pawn's path.  While this is
            // sad, we still assign a moderate bonus if all squares in the path
            // which are either occupied by or attacked by enemy pieces are
            // also attacked by us.
            if(((b3 | (b2 & pos.pieces_of_color(them))) & ~b4) == EmptyBoardBB)
              ebonus += Value(tr * 6);
          }
          // At last, add a small bonus when there are no *friendly* pieces
          // in the pawn's path:
          if((b2 & pos.pieces_of_color(us)) == EmptyBoardBB)
            ebonus += Value(tr);
        }

        // If the pawn is supported by a friendly pawn, increase bonus.
        b2 = pos.pawns(us) & neighboring_files_bb(s);
        if(b2 & rank_bb(s))
          ebonus += Value(r * 20);
        else if(pos.pawn_attacks(them, s) & b2)
          ebonus += Value(r * 12);

        // If the other side has only a king, check whether the pawn is
        // unstoppable:
        if(pos.non_pawn_material(them) == Value(0)) {
          Square qsq;
          int d;

          qsq = relative_square(us, make_square(square_file(s), RANK_8));
          d = square_distance(s, qsq) - square_distance(theirKingSq, qsq)
            + ((us == pos.side_to_move())? 0 : 1);

          if(d < 0) {
            int mtg = RANK_8 - relative_rank(us, s);
            int blockerCount =
              count_1s_max_15(squares_in_front_of(us,s)&pos.occupied_squares());
            mtg += blockerCount;
            d += blockerCount;
            if(d < 0) {
              hasUnstoppable[us] = true;
              movesToGo[us] = Min(movesToGo[us], mtg);
            }
          }
        }
        // Rook pawns are a special case:  They are sometimes worse, and
        // sometimes better than other passed pawns.  It is difficult to find
        // good rules for determining whether they are good or bad.  For now,
        // we try the following:  Increase the value for rook pawns if the
        // other side has no pieces apart from a knight, and decrease the
        // value if the other side has a rook or queen.
        if(square_file(s) == FILE_A || square_file(s) == FILE_H) {
          if(pos.non_pawn_material(them) == KnightValueMidgame
             && pos.piece_count(them, KNIGHT) == 1)
            ebonus += ebonus / 4;
          else if(pos.rooks_and_queens(them))
            ebonus -= ebonus / 4;
        }

        // Add the scores for this pawn to the middle game and endgame eval.
        ei.mgValue += apply_weight(Sign[us] * mbonus, WeightPassedPawnsMidgame);
        ei.egValue += apply_weight(Sign[us] * ebonus, WeightPassedPawnsEndgame);
      }
    }

    // Does either side have an unstoppable passed pawn?
    if(hasUnstoppable[WHITE] && !hasUnstoppable[BLACK])
      ei.egValue += UnstoppablePawnValue - Value(0x40 * movesToGo[WHITE]);
    else if(hasUnstoppable[BLACK] && !hasUnstoppable[WHITE])
      ei.egValue -= UnstoppablePawnValue - Value(0x40 * movesToGo[BLACK]);
    else if(hasUnstoppable[BLACK] && hasUnstoppable[WHITE]) {
      // Both sides have unstoppable pawns!  Try to find out who queens
      // first.  We begin by transforming 'movesToGo' to the number of
      // plies until the pawn queens for both sides:
      movesToGo[WHITE] *= 2;
      movesToGo[BLACK] *= 2;
      movesToGo[pos.side_to_move()]--;

      // If one side queens at least three plies before the other, that
      // side wins:
      if(movesToGo[WHITE] <= movesToGo[BLACK] - 3)
        ei.egValue += UnstoppablePawnValue - Value(0x40 * (movesToGo[WHITE]/2));
      else if(movesToGo[BLACK] <= movesToGo[WHITE] - 3)
        ei.egValue -= UnstoppablePawnValue - Value(0x40 * (movesToGo[BLACK]/2));

      // We could also add some rules about the situation when one side
      // queens exactly one ply before the other:  Does the first queen
      // check the opponent's king, or attack the opponent's queening square?
      // This is slightly tricky to get right, because it is possible that
      // the opponent's king has moved somewhere before the first pawn queens.
    }
  }


  // evaluate_trapped_bishop_a7h7() determines whether a bishop on a7/h7
  // (a2/h2 for black) is trapped by enemy pawns, and assigns a penalty
  // if it is.

  void evaluate_trapped_bishop_a7h7(const Position &pos, Square s, Color us,
                                    EvalInfo &ei) {

    assert(square_is_ok(s));
    assert(pos.piece_on(s) == bishop_of_color(us));

    Square b6 = relative_square(us, (square_file(s) == FILE_A) ? SQ_B6 : SQ_G6);
    Square b8 = relative_square(us, (square_file(s) == FILE_A) ? SQ_B8 : SQ_G8);

    if (   pos.piece_on(b6) == pawn_of_color(opposite_color(us))
        && pos.see(s, b6) < 0
        && pos.see(s, b8) < 0)
    {
        ei.mgValue -= Sign[us] * TrappedBishopA7H7Penalty;
        ei.egValue -= Sign[us] * TrappedBishopA7H7Penalty;
    }
  }


  // evaluate_trapped_bishop_a1h1() determines whether a bishop on a1/h1
  // (a8/h8 for black) is trapped by a friendly pawn on b2/g2 (b7/g7 for
  // black), and assigns a penalty if it is.  This pattern can obviously
  // only occur in Chess960 games.

  void evaluate_trapped_bishop_a1h1(const Position &pos, Square s, Color us,
                                    EvalInfo &ei) {
    Piece pawn = pawn_of_color(us);
    Square b2, b3, c3;

    assert(Chess960);
    assert(square_is_ok(s));
    assert(pos.piece_on(s) == bishop_of_color(us));

    if(square_file(s) == FILE_A) {
      b2 = relative_square(us, SQ_B2);
      b3 = relative_square(us, SQ_B3);
      c3 = relative_square(us, SQ_C3);
    }
    else {
      b2 = relative_square(us, SQ_G2);
      b3 = relative_square(us, SQ_G3);
      c3 = relative_square(us, SQ_F3);
    }

    if(pos.piece_on(b2) == pawn) {
      Value penalty;

      if(!pos.square_is_empty(b3))
        penalty = 2*TrappedBishopA1H1Penalty;
      else if(pos.piece_on(c3) == pawn)
        penalty = TrappedBishopA1H1Penalty;
      else
        penalty = TrappedBishopA1H1Penalty / 2;

      ei.mgValue -= Sign[us] * penalty;
      ei.egValue -= Sign[us] * penalty;
    }

  }


  // apply_weight applies an evaluation weight to a value.

  inline Value apply_weight(Value v, int w) {
    return (v*w) / 0x100;
  }


  // scale_by_game_phase interpolates between a middle game and an endgame
  // score, based on game phase.  It also scales the return value by a
  // ScaleFactor array.

  Value scale_by_game_phase(Value mv, Value ev, Phase ph, const ScaleFactor sf[]) {

    assert(mv > -VALUE_INFINITE && mv < VALUE_INFINITE);
    assert(ev > -VALUE_INFINITE && ev < VALUE_INFINITE);
    assert(ph >= PHASE_ENDGAME && ph <= PHASE_MIDGAME);

    ev = apply_scale_factor(ev, sf[(ev > Value(0) ? WHITE : BLACK)]);

    // Linearized sigmoid interpolator
    int sph = int(ph);
    sph -= (64 - sph) / 4;
    sph = Min(PHASE_MIDGAME, Max(PHASE_ENDGAME, sph));

    Value result = Value(int((mv * sph + ev * (128 - sph)) / 128));

    return Value(int(result) & ~(GrainSize - 1));
  }


  // count_1s_8bit() counts the number of nonzero bits in the 8 least
  // significant bits of a Bitboard. This function is used by the king
  // shield evaluation.

  int count_1s_8bit(Bitboard b) {
    return int(BitCount8Bit[b & 0xFF]);
  }


  // compute_weight() computes the value of an evaluation weight, by combining
  // an UCI-configurable weight with an internal weight.

  int compute_weight(int uciWeight, int internalWeight) {
    uciWeight = (uciWeight * 0x100) / 100;
    return (uciWeight * internalWeight) / 0x100;
  }


  // helper used in read_weights()
  int weight_option(const std::string& opt, int weight) {

    return compute_weight(get_option_value_int(opt), weight);
  }


  // init_safety() initizes the king safety evaluation, based on UCI
  // parameters.  It is called from read_weights().

  void init_safety() {

    QueenContactCheckBonus = get_option_value_int("Queen Contact Check Bonus");
    RookContactCheckBonus  = get_option_value_int("Rook Contact Check Bonus");
    QueenCheckBonus        = get_option_value_int("Queen Check Bonus");
    RookCheckBonus         = get_option_value_int("Rook Check Bonus");
    BishopCheckBonus       = get_option_value_int("Bishop Check Bonus");
    KnightCheckBonus       = get_option_value_int("Knight Check Bonus");
    DiscoveredCheckBonus   = get_option_value_int("Discovered Check Bonus");
    MateThreatBonus        = get_option_value_int("Mate Threat Bonus");

    int maxSlope = get_option_value_int("King Safety Max Slope");
    int peak     = get_option_value_int("King Safety Max Value") * 256 / 100;
    double a     = get_option_value_int("King Safety Coefficient") / 100.0;
    double b     = get_option_value_int("King Safety X Intercept");
    bool quad    = (get_option_value_string("King Safety Curve") == "Quadratic");
    bool linear  = (get_option_value_string("King Safety Curve") == "Linear");

    for (int i = 0; i < 100; i++)
    {
        if (i < b)
            SafetyTable[i] = Value(0);
        else if(quad)
            SafetyTable[i] = Value((int)(a * (i - b) * (i - b)));
        else if(linear)
            SafetyTable[i] = Value((int)(100 * a * (i - b)));
    }

    for (int i = 0; i < 100; i++)
    {
        if (SafetyTable[i+1] - SafetyTable[i] > maxSlope)
            for (int j = i + 1; j < 100; j++)
                SafetyTable[j] = SafetyTable[j-1] + Value(maxSlope);

        if (SafetyTable[i]  > Value(peak))
            SafetyTable[i] = Value(peak);
    }
  }

}

// ======== history.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cassert>



////
//// Functions
////

/// Constructor

History::History() {
  this->clear();
}


/// History::clear() clears the history tables.

void History::clear() {
  memset(history, 0, 2 * 8 * 64 * sizeof(int));
  memset(successCount, 0, 2 * 8 * 64 * sizeof(int));
  memset(failureCount, 0, 2 * 8 * 64 * sizeof(int));
}


/// History::success() registers a move as being successful.  This is done
/// whenever a non-capturing move causes a beta cutoff in the main search.
/// The three parameters are the moving piece, the move itself, and the
/// search depth.

void History::success(Piece p, Move m, Depth d) {
  assert(piece_is_ok(p));
  assert(move_is_ok(m));

  history[p][move_to(m)] += int(d) * int(d);
  successCount[p][move_to(m)]++;

  // Prevent history overflow:
  if(history[p][move_to(m)] >= HistoryMax)
    for(int i = 0; i < 16; i++)
      for(int j = 0; j < 64; j++)
        history[i][j] /= 2;
}


/// History::failure() registers a move as being unsuccessful.  The function is
/// called for each non-capturing move which failed to produce a beta cutoff
/// at a node where a beta cutoff was finally found.

void History::failure(Piece p, Move m) {
  assert(piece_is_ok(p));
  assert(move_is_ok(m));

  failureCount[p][move_to(m)]++;
}


/// History::move_ordering_score() returns an integer value used to order the
/// non-capturing moves in the MovePicker class.

int History::move_ordering_score(Piece p, Move m) const {
  assert(piece_is_ok(p));
  assert(move_is_ok(m));

  return history[p][move_to(m)];
}


/// History::ok_to_prune() decides whether a move has been sufficiently
/// unsuccessful that it makes sense to prune it entirely. 

bool History::ok_to_prune(Piece p, Move m, Depth d) const {
  assert(piece_is_ok(p));
  assert(move_is_ok(m));

  return (int(d) * successCount[p][move_to(m)] < failureCount[p][move_to(m)]);
}

// ======== material.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cassert>
#include <map>



////
//// Local definitions
////

namespace {

  const Value BishopPairMidgameBonus = Value(100);
  const Value BishopPairEndgameBonus = Value(100);

  Key KNNKMaterialKey, KKNNMaterialKey;

}

////
//// Classes
////


/// See header for a class description. It is declared here to avoid
/// to include <map> in the header file.

class EndgameFunctions {

public:
  EndgameFunctions();
  EndgameEvaluationFunction* getEEF(Key key) const;
  ScalingFunction* getESF(Key key, Color* c) const;

private:
  void add(Key k, EndgameEvaluationFunction* f);
  void add(Key k, Color c, ScalingFunction* f);

  struct ScalingInfo
  {
      Color col;
      ScalingFunction* fun;
  };

  std::map<Key, EndgameEvaluationFunction*> EEFmap;
  std::map<Key, ScalingInfo> ESFmap;
};


////
//// Functions
////


/// Constructor for the MaterialInfoTable class

MaterialInfoTable::MaterialInfoTable(unsigned int numOfEntries) {

  size = numOfEntries;
  entries = new MaterialInfo[size];
  funcs = new EndgameFunctions();
  if (!entries || !funcs)
  {
      std::cerr << "Failed to allocate " << (numOfEntries * sizeof(MaterialInfo))
                << " bytes for material hash table." << std::endl;
      exit(EXIT_FAILURE);
  }
  clear();
}


/// Destructor for the MaterialInfoTable class

MaterialInfoTable::~MaterialInfoTable() {

  delete [] entries;
  delete funcs;
}


/// MaterialInfoTable::clear() clears a material hash table by setting
/// all entries to 0.

void MaterialInfoTable::clear() {

  memset(entries, 0, size * sizeof(MaterialInfo));
}


/// MaterialInfoTable::get_material_info() takes a position object as input,
/// computes or looks up a MaterialInfo object, and returns a pointer to it.
/// If the material configuration is not already present in the table, it
/// is stored there, so we don't have to recompute everything when the
/// same material configuration occurs again.

MaterialInfo* MaterialInfoTable::get_material_info(const Position& pos) {

  Key key = pos.get_material_key();
  int index = key & (size - 1);
  MaterialInfo* mi = entries + index;

  // If mi->key matches the position's material hash key, it means that we
  // have analysed this material configuration before, and we can simply
  // return the information we found the last time instead of recomputing it.
  if (mi->key == key)
      return mi;

  // Clear the MaterialInfo object, and set its key
  mi->clear();
  mi->key = key;

  // A special case before looking for a specialized evaluation function
  // KNN vs K is a draw.
  if (key == KNNKMaterialKey || key == KKNNMaterialKey)
  {
      mi->factor[WHITE] = mi->factor[BLACK] = 0;
      return mi;
  }

  // Let's look if we have a specialized evaluation function for this
  // particular material configuration.
  if ((mi->evaluationFunction = funcs->getEEF(key)) != NULL)
      return mi;

  else if (   pos.non_pawn_material(BLACK) == Value(0)
           && pos.piece_count(BLACK, PAWN) == 0
           && pos.non_pawn_material(WHITE) >= RookValueEndgame)
  {
      mi->evaluationFunction = &EvaluateKXK;
      return mi;
  }
  else if (   pos.non_pawn_material(WHITE) == Value(0)
           && pos.piece_count(WHITE, PAWN) == 0
           && pos.non_pawn_material(BLACK) >= RookValueEndgame)
  {
      mi->evaluationFunction = &EvaluateKKX;
      return mi;
  }

  // OK, we didn't find any special evaluation function for the current
  // material configuration. Is there a suitable scaling function?
  //
  // The code below is rather messy, and it could easily get worse later,
  // if we decide to add more special cases.  We face problems when there
  // are several conflicting applicable scaling functions and we need to
  // decide which one to use.
  Color c;
  ScalingFunction* sf;

  if ((sf = funcs->getESF(key, &c)) != NULL)
  {
      mi->scalingFunction[c] = sf;
      return mi;
  }

  if (   pos.non_pawn_material(WHITE) == BishopValueMidgame
      && pos.piece_count(WHITE, BISHOP) == 1
      && pos.piece_count(WHITE, PAWN) >= 1)
      mi->scalingFunction[WHITE] = &ScaleKBPK;

  if (   pos.non_pawn_material(BLACK) == BishopValueMidgame
      && pos.piece_count(BLACK, BISHOP) == 1
      && pos.piece_count(BLACK, PAWN) >= 1)
      mi->scalingFunction[BLACK] = &ScaleKKBP;

  if (   pos.piece_count(WHITE, PAWN) == 0
      && pos.non_pawn_material(WHITE) == QueenValueMidgame
      && pos.piece_count(WHITE, QUEEN) == 1
      && pos.piece_count(BLACK, ROOK) == 1
      && pos.piece_count(BLACK, PAWN) >= 1)
      mi->scalingFunction[WHITE] = &ScaleKQKRP;

  else if (   pos.piece_count(BLACK, PAWN) == 0
           && pos.non_pawn_material(BLACK) == QueenValueMidgame
           && pos.piece_count(BLACK, QUEEN) == 1
           && pos.piece_count(WHITE, ROOK) == 1
           && pos.piece_count(WHITE, PAWN) >= 1)
      mi->scalingFunction[BLACK] = &ScaleKRPKQ;

  if (pos.non_pawn_material(WHITE) + pos.non_pawn_material(BLACK) == Value(0))
  {
      if (pos.piece_count(BLACK, PAWN) == 0)
      {
          assert(pos.piece_count(WHITE, PAWN) >= 2);
          mi->scalingFunction[WHITE] = &ScaleKPsK;
      }
      else if (pos.piece_count(WHITE, PAWN) == 0)
      {
          assert(pos.piece_count(BLACK, PAWN) >= 2);
          mi->scalingFunction[BLACK] = &ScaleKKPs;
      }
      else if (pos.piece_count(WHITE, PAWN) == 1 && pos.piece_count(BLACK, PAWN) == 1)
      {
          mi->scalingFunction[WHITE] = &ScaleKPKPw;
          mi->scalingFunction[BLACK] = &ScaleKPKPb;
      }
  }

  // Evaluate the material balance

  int sign;
  Value egValue = Value(0);
  Value mgValue = Value(0);

  for (c = WHITE, sign = 1; c <= BLACK; c++, sign = -sign)
  {
    // No pawns makes it difficult to win, even with a material advantage
    if (   pos.piece_count(c, PAWN) == 0
        && pos.non_pawn_material(c) - pos.non_pawn_material(opposite_color(c)) <= BishopValueMidgame)
    {
        if (   pos.non_pawn_material(c) == pos.non_pawn_material(opposite_color(c))
            || pos.non_pawn_material(c) < RookValueMidgame)
            mi->factor[c] = 0;
        else
        {
            switch (pos.piece_count(c, BISHOP)) {
            case 2:
                mi->factor[c] = 32;
                break;
            case 1:
                mi->factor[c] = 12;
                break;
            case 0:
                mi->factor[c] = 6;
                break;
            }
        }
    }

    // Bishop pair
    if (pos.piece_count(c, BISHOP) >= 2)
    {
        mgValue += sign * BishopPairMidgameBonus;
        egValue += sign * BishopPairEndgameBonus;
    }

    // Knights are stronger when there are many pawns on the board.  The
    // formula is taken from Larry Kaufman's paper "The Evaluation of Material
    // Imbalances in Chess":
    // http://mywebpages.comcast.net/danheisman/Articles/evaluation_of_material_imbalance.htm
    mgValue += sign * Value(pos.piece_count(c, KNIGHT)*(pos.piece_count(c, PAWN)-5)*16);
    egValue += sign * Value(pos.piece_count(c, KNIGHT)*(pos.piece_count(c, PAWN)-5)*16);

    // Redundancy of major pieces, again based on Kaufman's paper:
    if (pos.piece_count(c, ROOK) >= 1)
    {
        Value v = Value((pos.piece_count(c, ROOK) - 1) * 32 + pos.piece_count(c, QUEEN) * 16);
        mgValue -= sign * v;
        egValue -= sign * v;
    }
  }
  mi->mgValue = int16_t(mgValue);
  mi->egValue = int16_t(egValue);
  return mi;
}


/// EndgameFunctions member definitions. This class is used to store the maps
/// of end game and scaling functions that MaterialInfoTable will query for 
/// each key. The maps are constant and are populated only at construction,
/// but are per-thread instead of globals to avoid expensive locks.

EndgameFunctions::EndgameFunctions() {

  typedef Key ZM[2][8][16];
  const ZM& z = Position::zobMaterial;

  static const Color W = WHITE;
  static const Color B = BLACK;

  KNNKMaterialKey = z[W][KNIGHT][1] ^ z[W][KNIGHT][2];
  KKNNMaterialKey = z[B][KNIGHT][1] ^ z[B][KNIGHT][2];

  add(z[W][PAWN][1], &EvaluateKPK);
  add(z[B][PAWN][1], &EvaluateKKP);

  add(z[W][BISHOP][1] ^ z[W][KNIGHT][1], &EvaluateKBNK);
  add(z[B][BISHOP][1] ^ z[B][KNIGHT][1], &EvaluateKKBN);
  add(z[W][ROOK][1]   ^ z[B][PAWN][1],   &EvaluateKRKP);
  add(z[W][PAWN][1]   ^ z[B][ROOK][1],   &EvaluateKPKR);
  add(z[W][ROOK][1]   ^ z[B][BISHOP][1], &EvaluateKRKB);
  add(z[W][BISHOP][1] ^ z[B][ROOK][1],   &EvaluateKBKR);
  add(z[W][ROOK][1]   ^ z[B][KNIGHT][1], &EvaluateKRKN);
  add(z[W][KNIGHT][1] ^ z[B][ROOK][1],   &EvaluateKNKR);
  add(z[W][QUEEN][1]  ^ z[B][ROOK][1],   &EvaluateKQKR);
  add(z[W][ROOK][1]   ^ z[B][QUEEN][1],  &EvaluateKRKQ);

  add(z[W][KNIGHT][1] ^ z[W][PAWN][1], W, &ScaleKNPK);
  add(z[B][KNIGHT][1] ^ z[B][PAWN][1], B, &ScaleKKNP);

  add(z[W][ROOK][1]   ^ z[W][PAWN][1]   ^ z[B][ROOK][1]  , W, &ScaleKRPKR);
  add(z[W][ROOK][1]   ^ z[B][ROOK][1]   ^ z[B][PAWN][1]  , B, &ScaleKRKRP);
  add(z[W][BISHOP][1] ^ z[W][PAWN][1]   ^ z[B][BISHOP][1], W, &ScaleKBPKB);
  add(z[W][BISHOP][1] ^ z[B][BISHOP][1] ^ z[B][PAWN][1]  , B, &ScaleKBKBP);
  add(z[W][BISHOP][1] ^ z[W][PAWN][1]   ^ z[B][KNIGHT][1], W, &ScaleKBPKN);
  add(z[W][KNIGHT][1] ^ z[B][BISHOP][1] ^ z[B][PAWN][1]  , B, &ScaleKNKBP);

  add(z[W][ROOK][1] ^ z[W][PAWN][1] ^ z[W][PAWN][2] ^ z[B][ROOK][1] ^ z[B][PAWN][1], W, &ScaleKRPPKRP);
  add(z[W][ROOK][1] ^ z[W][PAWN][1] ^ z[B][ROOK][1] ^ z[B][PAWN][1] ^ z[B][PAWN][2], B, &ScaleKRPKRPP);
}

void EndgameFunctions::add(Key k, EndgameEvaluationFunction* f) {

  EEFmap.insert(std::pair<Key, EndgameEvaluationFunction*>(k, f));
}

void EndgameFunctions::add(Key k, Color c, ScalingFunction* f) {

  ScalingInfo s = {c, f};
  ESFmap.insert(std::pair<Key, ScalingInfo>(k, s));
}

EndgameEvaluationFunction* EndgameFunctions::getEEF(Key key) const {

  std::map<Key, EndgameEvaluationFunction*>::const_iterator it(EEFmap.find(key));
  return (it != EEFmap.end() ? it->second : NULL);
}

ScalingFunction* EndgameFunctions::getESF(Key key, Color* c) const {

  std::map<Key, ScalingInfo>::const_iterator it(ESFmap.find(key));
  if (it == ESFmap.end())
      return NULL;

  *c = it->second.col;
  return it->second.fun;
}

// ======== mersenne.cpp ========
/*
   A C-program for MT19937, with initialization improved 2002/1/26.
   Coded by Takuji Nishimura and Makoto Matsumoto.

   Before using, initialize the state by using init_genrand(seed)
   or init_by_array(init_key, key_length).

   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

     3. The names of its contributors may not be used to endorse or promote
        products derived from this software without specific prior written
        permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


   Any feedback is very welcome.
   http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/emt.html
   email: m-mat @ math.sci.hiroshima-u.ac.jp (remove space)
*/


/* Period parameters */
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

static unsigned long mt[N]; /* the array for the state vector  */
static int mti=N+1; /* mti==N+1 means mt[N] is not initialized */

/* initializes mt[N] with a seed */
static void init_genrand(unsigned long s)
{
    mt[0]= s & 0xffffffffUL;
    for (mti=1; mti<N; mti++) {
        mt[mti] =
            (1812433253UL * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti);
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array mt[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        mt[mti] &= 0xffffffffUL;
        /* for >32 bit machines */
    }
}

/* initialize by an array with array-length */
/* init_key is the array for initializing keys */
/* key_length is its length */
/* slight change for C++, 2004/2/26 */
static void init_by_array(unsigned long init_key[], int key_length)
{
    int i, j, k;
    init_genrand(19650218UL);
    i=1; j=0;
    k = (N>key_length ? N : key_length);
    for (; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1664525UL))
          + init_key[j] + j; /* non linear */
        mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++; j++;
        if (i>=N) { mt[0] = mt[N-1]; i=1; }
        if (j>=key_length) j=0;
    }
    for (k=N-1; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1566083941UL))
          - i; /* non linear */
        mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++;
        if (i>=N) { mt[0] = mt[N-1]; i=1; }
    }

    mt[0] = 0x80000000UL; /* MSB is 1; assuring non-zero initial array */
}

/* generates a random number on [0,0xffffffff]-interval */
uint32_t genrand_int32(void) {
  unsigned long y;
  static unsigned long mag01[2]={0x0UL, MATRIX_A};
  /* mag01[x] = x * MATRIX_A  for x=0,1 */

  if (mti >= N) { /* generate N words at one time */
    int kk;

    if (mti == N+1)   /* if init_genrand() has not been called, */
      init_genrand(5489UL); /* a default initial seed is used */

    for (kk=0;kk<N-M;kk++) {
      y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
      mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1UL];
    }
    for (;kk<N-1;kk++) {
      y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
      mt[kk] = mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
    }
    y = (mt[N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
    mt[N-1] = mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1UL];

    mti = 0;
  }

  y = mt[mti++];

  /* Tempering */
  y ^= (y >> 11);
  y ^= (y << 7) & 0x9d2c5680UL;
  y ^= (y << 15) & 0xefc60000UL;
  y ^= (y >> 18);

  return y;
}

uint64_t genrand_int64(void) {
  uint64_t x, y;

  x = genrand_int32(); y = genrand_int32();
  return (x<<32)|y;
}

void init_mersenne(void) {
  unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
  init_by_array(init, length);
}

#undef N
#undef M
#undef MATRIX_A
#undef UPPER_MASK
#undef LOWER_MASK

// ======== misc.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#if !defined(_MSC_VER)

#  include <sys/time.h>
#  include <sys/types.h>
#  include <unistd.h>

#else

#  include <windows.h>
#  include <time.h>
#  include "dos.h"
int gettimeofday(struct timeval * tp, struct timezone * tzp);

#endif

#include <cstdio>
#include <iomanip>
#include <iostream>
#include <sstream>



////
//// Variables
////

long dbg_cnt0 = 0;
long dbg_cnt1 = 0;

bool dbg_show_mean = false;
bool dbg_show_hit_rate = false;


////
//// Functions
////

void dbg_print_hit_rate() {

  std::cout << "Total " << dbg_cnt0 << " Hit " << dbg_cnt1
            << " hit rate (%) " << (dbg_cnt1*100)/(dbg_cnt0 ? dbg_cnt0 : 1)
            << std::endl;
}

void dbg_print_mean() {

  std::cout << "Total " << dbg_cnt0 << " Mean "
            << (float)dbg_cnt1 / (dbg_cnt0 ? dbg_cnt0 : 1) << std::endl;
}

/// engine_name() returns the full name of the current Stockfish version.
/// This will be either "Stockfish YYMMDD" (where YYMMDD is the date when the
/// program was compiled) or "Stockfish <version number>", depending on whether
/// the constant EngineVersion (defined in misc.h) is empty.

const std::string engine_name() {

  if (EngineVersion.empty())
  {
      std::string date(__DATE__); // From compiler, format is "Sep 21 2008"
      std::string months("Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec");

      size_t mon = 1 + months.find(date.substr(0, 3)) / 4;

      std::stringstream s;
      std::string day = (date[4] == ' ' ? date.substr(5, 1) : date.substr(4, 2));

      s << "Stockfish " << date.substr(date.length() - 2) << std::setfill('0')
        << std::setw(2) << mon << std::setw(2) << day;

      return s.str();
  } else
      return "Stockfish " + EngineVersion;
}


/// get_system_time() returns the current system time, measured in
/// milliseconds.

int get_system_time() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return t.tv_sec*1000 + t.tv_usec/1000;
}


/// cpu_count() tries to detect the number of CPU cores.

#if !defined(_MSC_VER)

#  if defined(_SC_NPROCESSORS_ONLN)
int cpu_count() {
  return Min(sysconf(_SC_NPROCESSORS_ONLN), 8);
}
#  else
int cpu_count() {
  return 1;
}
#  endif

#else

int cpu_count() {
  SYSTEM_INFO s;
  GetSystemInfo(&s);
  return Min(s.dwNumberOfProcessors, 8);
}

#endif


/*
  From Beowulf, from Olithink
*/
#ifndef _WIN32
/* Non-windows version */
int Bioskey()
{
  fd_set          readfds;
  struct timeval  timeout;

  FD_ZERO(&readfds);
  FD_SET(fileno(stdin), &readfds);
  /* Set to timeout immediately */
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;
  select(16, &readfds, 0, 0, &timeout);

  return (FD_ISSET(fileno(stdin), &readfds));
}

#else
/* Windows-version */
#include <windows.h>
#include <conio.h>
int Bioskey()
{
    static int      init = 0,
                    pipe;
    static HANDLE   inh;
    DWORD           dw;
    /* If we're running under XBoard then we can't use _kbhit() as the input
     * commands are sent to us directly over the internal pipe */

#if defined(FILE_CNT)
    if (stdin->_cnt > 0)
        return stdin->_cnt;
#endif
    if (!init) {
        init = 1;
        inh = GetStdHandle(STD_INPUT_HANDLE);
        pipe = !GetConsoleMode(inh, &dw);
        if (!pipe) {
            SetConsoleMode(inh, dw & ~(ENABLE_MOUSE_INPUT | ENABLE_WINDOW_INPUT));
            FlushConsoleInputBuffer(inh);
        }
    }
    if (pipe) {
        if (!PeekNamedPipe(inh, NULL, 0, NULL, &dw, NULL))
            return 1;
        return dw;
    } else {
        // Count the number of unread input records, including keyboard,
        // mouse, and window-resizing input records.
        GetNumberOfConsoleInputEvents(inh, &dw);
        if (dw <= 0)
            return 0;

        // Read data from console without removing it from the buffer
        INPUT_RECORD rec[256];
        DWORD recCnt;
        if (!PeekConsoleInput(inh, rec, Min(dw, 256), &recCnt))
            return 0;

        // Search for at least one keyboard event
        for (DWORD i = 0; i < recCnt; i++)
            if (rec[i].EventType == KEY_EVENT)
                return 1;

        return 0;
    }
}
#endif

// ======== move.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cassert>



////
//// Functions
////

/// move_from_string() takes a position and a string as input, and attempts to
/// convert the string to a move, using simple coordinate notation (g1f3,
/// a7a8q, etc.). In order to correctly parse en passant captures and castling
/// moves, we need the position. This function is not robust, and expects that
/// the input move is legal and correctly formatted.

Move move_from_string(const Position& pos, const std::string& str) {

  Square from, to;
  Piece piece;
  Color us = pos.side_to_move();

  if (str.length() < 4)
      return MOVE_NONE;

  // Read the from and to squares
  from = square_from_string(str.substr(0, 2));
  to = square_from_string(str.substr(2, 4));

  // Find the moving piece
  piece = pos.piece_on(from);

  // If the string has more than 4 characters, try to interpret the 5th
  // character as a promotion
  if (type_of_piece(piece) == PAWN && str.length() > 4)
  {
      switch (tolower(str[4])) {
      case 'n':
          return make_promotion_move(from, to, KNIGHT);
      case 'b':
          return make_promotion_move(from, to, BISHOP);
      case 'r':
          return make_promotion_move(from, to, ROOK);
      case 'q':
          return make_promotion_move(from, to, QUEEN);
    }
  }

  if (piece == king_of_color(us))
  {
      // Is this a castling move? A king move is assumed to be a castling
      // move if the destination square is occupied by a friendly rook, or
      // if the distance between the source and destination squares is more
      // than 1.
      if (pos.piece_on(to) == rook_of_color(us))
          return make_castle_move(from, to);

      else if (square_distance(from, to) > 1)
      {
          // This is a castling move, but we have to translate it to the
          // internal "king captures rook" representation.
          SquareDelta delta = (to > from ? DELTA_E : DELTA_W);
          Square s = from + delta;
          while (relative_rank(us, s) == RANK_1 && pos.piece_on(s) != rook_of_color(us))
              s += delta;

          return (relative_rank(us, s) == RANK_1 ? make_castle_move(from, s) : MOVE_NONE);
      }
  }
  else if (piece == pawn_of_color(us))
  {
      // En passant move? We assume that a pawn move is an en passant move
      // without further testing if the destination square is epSquare.
      if (to == pos.ep_square())
          return make_ep_move(from, to);
  }
  return make_move(from, to);
}


/// move_to_string() converts a move to a string in coordinate notation
/// (g1f3, a7a8q, etc.).  The only special case is castling moves, where we
/// print in the e1g1 notation in normal chess mode, and in e1h1 notation in
/// Chess960 mode.

const std::string move_to_string(Move move) {

  std::string str;
  Square from = move_from(move);
  Square to = move_to(move);

  if (move == MOVE_NONE)
      str = "(none)";
  else if (move == MOVE_NULL)
      str = "0000";
  else
  {
      if (!Chess960)
      {
          if (move_is_short_castle(move))
              return (from == SQ_E1 ? "e1g1" : "e8g8");

          if (move_is_long_castle(move))
              return (from == SQ_E1 ? "e1c1" : "e8c8");
      }
      str = square_to_string(from) + square_to_string(to);
      if (move_promotion(move))
          str += piece_type_to_char(move_promotion(move), false);
  }
  return str;
}


/// Overload the << operator, to make it easier to print moves.

std::ostream &operator << (std::ostream &os, Move m) {

  return os << move_to_string(m);
}


/// move_is_ok(), for debugging.

bool move_is_ok(Move m) {

  return square_is_ok(move_from(m)) && square_is_ok(move_to(m));
}

// ======== movegen.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author) Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cassert>


// Simple macro to wrap a very common while loop, no facny, no flexibility,
// hardcoded list name 'mlist' and from square 'from'.
#define SERIALIZE_MOVES(b) while (b) (*mlist++).move = make_move(from, pop_1st_bit(&b))

////
//// Local definitions
////

namespace {

  // Function
  MoveStack* generate_castle_moves(const Position&, MoveStack*);

  // Template generate_pawn_captures() with specializations
  template<Color, Color, Bitboard, SquareDelta, SquareDelta, SquareDelta>
  MoveStack* do_generate_pawn_captures(const Position& pos, MoveStack* mlist);

  template<Color>
  inline MoveStack* generate_pawn_captures(const Position& p, MoveStack* m) {
      return do_generate_pawn_captures<WHITE, BLACK, Rank8BB, DELTA_NE, DELTA_NW, DELTA_N>(p, m);
  }
  template<>
  inline MoveStack* generate_pawn_captures<BLACK>(const Position& p, MoveStack* m) {
      return do_generate_pawn_captures<BLACK, WHITE, Rank1BB, DELTA_SE, DELTA_SW, DELTA_S>(p, m);
  }

  // Template generate_pawn_noncaptures() with specializations
  template<Color, Color, Bitboard, Bitboard, SquareDelta, SquareDelta, SquareDelta>
  MoveStack* do_generate_pawn_noncaptures(const Position& pos, MoveStack* mlist);

  template<Color>
  inline MoveStack* generate_pawn_noncaptures(const Position& p, MoveStack* m) {
      return do_generate_pawn_noncaptures<WHITE, BLACK, Rank8BB, Rank3BB, DELTA_NE, DELTA_NW, DELTA_N>(p, m);
  }
  template<>
  inline MoveStack* generate_pawn_noncaptures<BLACK>(const Position& p, MoveStack* m) {
      return do_generate_pawn_noncaptures<BLACK, WHITE, Rank1BB, Rank6BB, DELTA_SE, DELTA_SW, DELTA_S>(p, m);
  }

  // Template generate_pawn_blocking_evasions() with specializations
  template<Color Us, Rank, Bitboard, SquareDelta>
  MoveStack* do_generate_pawn_blocking_evasions(const Position& pos, Bitboard not_pinned,
                                                Bitboard blockSquares, MoveStack* mlist);
  template<Color>
  inline MoveStack* generate_pawn_blocking_evasions(const Position& p, Bitboard np, Bitboard bs, MoveStack* m) {
      return do_generate_pawn_blocking_evasions<WHITE, RANK_8, Rank3BB, DELTA_N>(p, np, bs, m);
  }
  template<>
  inline MoveStack* generate_pawn_blocking_evasions<BLACK>(const Position& p, Bitboard np, Bitboard bs, MoveStack* m) {
      return do_generate_pawn_blocking_evasions<BLACK, RANK_1, Rank6BB, DELTA_S>(p, np, bs, m);
  }

  // Template generate_pawn_checks() with specializations
  template<Color, Color, Bitboard, Bitboard, SquareDelta>
  MoveStack* do_generate_pawn_checks(const Position&, Bitboard, Square, MoveStack*);

  template<Color>
  inline MoveStack* generate_pawn_checks(const Position& p, Bitboard dc, Square ksq, MoveStack* m) {
      return do_generate_pawn_checks<WHITE, BLACK, Rank8BB, Rank3BB, DELTA_N>(p, dc, ksq, m);
  }
  template<>
  inline MoveStack* generate_pawn_checks<BLACK>(const Position& p, Bitboard dc, Square ksq, MoveStack* m) {
      return do_generate_pawn_checks<BLACK, WHITE, Rank1BB, Rank6BB, DELTA_S>(p, dc, ksq, m);
  }

  // non-pawn templates
  template<PieceType>
  MoveStack* generate_piece_moves(const Position&, MoveStack*, Color us, Bitboard);
  template<>
  MoveStack* generate_piece_moves<KING>(const Position& pos, MoveStack* mlist, Color us, Bitboard target);

  template<PieceType>
  MoveStack* generate_piece_checks(const Position&, Bitboard, Bitboard, Square, MoveStack*);
  MoveStack* generate_piece_checks_king(const Position&, Square, Bitboard, Square, MoveStack*);

  template<PieceType>
  MoveStack* generate_piece_blocking_evasions(const Position&, Bitboard, Bitboard, MoveStack*);
}


////
//// Functions
////


/// generate_captures generates() all pseudo-legal captures and queen
/// promotions.  The return value is the number of moves generated.

int generate_captures(const Position& pos, MoveStack* mlist) {

  assert(pos.is_ok());
  assert(!pos.is_check());

  Color us = pos.side_to_move();
  Bitboard target = pos.pieces_of_color(opposite_color(us));
  MoveStack* mlist_start = mlist;

  if (us == WHITE)
      mlist = generate_pawn_captures<WHITE>(pos, mlist);
  else
      mlist = generate_pawn_captures<BLACK>(pos, mlist);

  mlist = generate_piece_moves<KNIGHT>(pos, mlist, us, target);
  mlist = generate_piece_moves<BISHOP>(pos, mlist, us, target);
  mlist = generate_piece_moves<ROOK>(pos, mlist, us, target);
  mlist = generate_piece_moves<QUEEN>(pos, mlist, us, target);
  mlist = generate_piece_moves<KING>(pos, mlist, us, target);
  return int(mlist - mlist_start);
}


/// generate_noncaptures() generates all pseudo-legal non-captures and
/// underpromotions.  The return value is the number of moves generated.

int generate_noncaptures(const Position& pos, MoveStack* mlist) {

  assert(pos.is_ok());
  assert(!pos.is_check());

  Color us = pos.side_to_move();
  Bitboard target = pos.empty_squares();
  MoveStack* mlist_start = mlist;

  if (us == WHITE)
      mlist = generate_pawn_noncaptures<WHITE>(pos, mlist);
  else
      mlist = generate_pawn_noncaptures<BLACK>(pos, mlist);

  mlist = generate_piece_moves<KNIGHT>(pos, mlist, us, target);
  mlist = generate_piece_moves<BISHOP>(pos, mlist, us, target);
  mlist = generate_piece_moves<ROOK>(pos, mlist, us, target);
  mlist = generate_piece_moves<QUEEN>(pos, mlist, us, target);
  mlist = generate_piece_moves<KING>(pos, mlist, us, target);
  mlist = generate_castle_moves(pos, mlist);
  return int(mlist - mlist_start);
}


/// generate_checks() generates all pseudo-legal non-capturing, non-promoting
/// checks, except castling moves (will add this later).  It returns the
/// number of generated moves.

int generate_checks(const Position& pos, MoveStack* mlist, Bitboard dc) {

  assert(pos.is_ok());
  assert(!pos.is_check());

  Color us = pos.side_to_move();
  Square ksq = pos.king_square(opposite_color(us));
  MoveStack* mlist_start = mlist;

  assert(pos.piece_on(ksq) == king_of_color(opposite_color(us)));

  dc = pos.discovered_check_candidates(us);

  // Pawn moves
  if (us == WHITE)
     mlist = generate_pawn_checks<WHITE>(pos, dc, ksq, mlist);
  else
     mlist = generate_pawn_checks<BLACK>(pos, dc, ksq, mlist);

  // Pieces moves
  Bitboard b = pos.knights(us);
  if (b)
      mlist = generate_piece_checks<KNIGHT>(pos, b, dc, ksq, mlist);

  b = pos.bishops(us);
  if (b)
      mlist = generate_piece_checks<BISHOP>(pos, b, dc, ksq, mlist);

  b = pos.rooks(us);
  if (b)
      mlist = generate_piece_checks<ROOK>(pos, b, dc, ksq, mlist);

  b = pos.queens(us);
  if (b)
      mlist = generate_piece_checks<QUEEN>(pos, b, dc, ksq, mlist);

  // Hopefully we always have a king ;-)
  mlist = generate_piece_checks_king(pos, pos.king_square(us), dc, ksq, mlist);

  // TODO: Castling moves!

  return int(mlist - mlist_start);
}


/// generate_evasions() generates all check evasions when the side to move is
/// in check.  Unlike the other move generation functions, this one generates
/// only legal moves.  It returns the number of generated moves.  This
/// function is very ugly, and needs cleaning up some time later.  FIXME

int generate_evasions(const Position& pos, MoveStack* mlist) {

  assert(pos.is_ok());
  assert(pos.is_check());

  Square from, to;
  Color us = pos.side_to_move();
  Color them = opposite_color(us);
  Square ksq = pos.king_square(us);
  MoveStack* mlist_start = mlist;

  assert(pos.piece_on(ksq) == king_of_color(us));

  // Generate evasions for king
  Bitboard b1 = pos.piece_attacks<KING>(ksq) & ~pos.pieces_of_color(us);
  Bitboard b2 = pos.occupied_squares();
  clear_bit(&b2, ksq);

  while (b1)
  {
    to = pop_1st_bit(&b1);

    // Make sure 'to' is not attacked by the other side. This is a bit ugly,
    // because we can't use Position::square_is_attacked. Instead we use
    // the low-level bishop_attacks_bb and rook_attacks_bb with the bitboard
    // b2 (the occupied squares with the king removed) in order to test whether
    // the king will remain in check on the destination square.
    if (!(   (pos.piece_attacks<KNIGHT>(to) & pos.knights(them))
          || (pos.pawn_attacks(us, to)      & pos.pawns(them))
          || (bishop_attacks_bb(to, b2)     & pos.bishops_and_queens(them))
          || (rook_attacks_bb(to, b2)       & pos.rooks_and_queens(them))
          || (pos.piece_attacks<KING>(to)   & pos.kings(them))))

        (*mlist++).move = make_move(ksq, to);
  }

  // Generate evasions for other pieces only if not double check. We use a
  // simple bit twiddling hack here rather than calling count_1s in order to
  // save some time (we know that pos.checkers() has at most two nonzero bits).
  Bitboard checkers = pos.checkers();

  if (!(checkers & (checkers - 1))) // Only one bit set?
  {
      Square checksq = first_1(checkers);

      assert(pos.color_of_piece_on(checksq) == them);

      // Find pinned pieces
      Bitboard not_pinned = ~pos.pinned_pieces(us);

      // Generate captures of the checking piece

      // Pawn captures
      b1 = pos.pawn_attacks(them, checksq) & pos.pawns(us) & not_pinned;
      while (b1)
      {
          from = pop_1st_bit(&b1);
          if (relative_rank(us, checksq) == RANK_8)
          {
              (*mlist++).move = make_promotion_move(from, checksq, QUEEN);
              (*mlist++).move = make_promotion_move(from, checksq, ROOK);
              (*mlist++).move = make_promotion_move(from, checksq, BISHOP);
              (*mlist++).move = make_promotion_move(from, checksq, KNIGHT);
          } else
              (*mlist++).move = make_move(from, checksq);
      }

      // Pieces captures
      b1 = (  (pos.piece_attacks<KNIGHT>(checksq) & pos.knights(us))
            | (pos.piece_attacks<BISHOP>(checksq) & pos.bishops_and_queens(us))
            | (pos.piece_attacks<ROOK>(checksq)   & pos.rooks_and_queens(us)) ) & not_pinned;

      while (b1)
      {
          from = pop_1st_bit(&b1);
          (*mlist++).move = make_move(from, checksq);
      }

      // Blocking check evasions are possible only if the checking piece is
      // a slider
      if (checkers & pos.sliders())
      {
          Bitboard blockSquares = squares_between(checksq, ksq);

          assert((pos.occupied_squares() & blockSquares) == EmptyBoardBB);

          // Pawn moves. Because a blocking evasion can never be a capture, we
          // only generate pawn pushes.
          if (us == WHITE)
              mlist = generate_pawn_blocking_evasions<WHITE>(pos, not_pinned, blockSquares, mlist);
          else
              mlist = generate_pawn_blocking_evasions<BLACK>(pos, not_pinned, blockSquares, mlist);

          // Pieces moves
          b1 = pos.knights(us) & not_pinned;
          if (b1)
              mlist = generate_piece_blocking_evasions<KNIGHT>(pos, b1, blockSquares, mlist);

          b1 = pos.bishops(us) & not_pinned;
          if (b1)
              mlist = generate_piece_blocking_evasions<BISHOP>(pos, b1, blockSquares, mlist);

          b1 = pos.rooks(us) & not_pinned;
          if (b1)
              mlist = generate_piece_blocking_evasions<ROOK>(pos, b1, blockSquares, mlist);

          b1 = pos.queens(us) & not_pinned;
          if (b1)
              mlist = generate_piece_blocking_evasions<QUEEN>(pos, b1, blockSquares, mlist);
    }

    // Finally, the ugly special case of en passant captures. An en passant
    // capture can only be a check evasion if the check is not a discovered
    // check. If pos.ep_square() is set, the last move made must have been
    // a double pawn push. If, furthermore, the checking piece is a pawn,
    // an en passant check evasion may be possible.
    if (pos.ep_square() != SQ_NONE && (checkers & pos.pawns(them)))
    {
        to = pos.ep_square();
        b1 = pos.pawn_attacks(them, to) & pos.pawns(us);

        assert(b1 != EmptyBoardBB);

        b1 &= not_pinned;
        while (b1)
        {
            from = pop_1st_bit(&b1);

            // Before generating the move, we have to make sure it is legal.
            // This is somewhat tricky, because the two disappearing pawns may
            // cause new "discovered checks".  We test this by removing the
            // two relevant bits from the occupied squares bitboard, and using
            // the low-level bitboard functions for bishop and rook attacks.
            b2 = pos.occupied_squares();
            clear_bit(&b2, from);
            clear_bit(&b2, checksq);
            if (!(  (bishop_attacks_bb(ksq, b2) & pos.bishops_and_queens(them))
                  ||(rook_attacks_bb(ksq, b2)   & pos.rooks_and_queens(them))))

                 (*mlist++).move = make_ep_move(from, to);
        }
    }
  }
  return int(mlist - mlist_start);
}


/// generate_legal_moves() computes a complete list of legal moves in the
/// current position.  This function is not very fast, and should be used
/// only in situations where performance is unimportant.  It wouldn't be
/// very hard to write an efficient legal move generator, but for the moment
/// we don't need it.

int generate_legal_moves(const Position& pos, MoveStack* mlist) {

  assert(pos.is_ok());

  if (pos.is_check())
      return generate_evasions(pos, mlist);

  // Generate pseudo-legal moves
  int n = generate_captures(pos, mlist);
  n += generate_noncaptures(pos, mlist + n);

  Bitboard pinned = pos.pinned_pieces(pos.side_to_move());

  // Remove illegal moves from the list
  for (int i = 0; i < n; i++)
      if (!pos.pl_move_is_legal(mlist[i].move, pinned))
          mlist[i--].move = mlist[--n].move;

  return n;
}


/// move_is_legal() takes a position and a (not necessarily pseudo-legal)
/// move and a pinned pieces bitboard as input, and tests whether
/// the move is legal.  If the move is legal, the move itself is
/// returned. If not, the function returns false.  This function must
/// only be used when the side to move is not in check.

bool move_is_legal(const Position& pos, const Move m, Bitboard pinned) {

  assert(pos.is_ok());
  assert(!pos.is_check());
  assert(move_is_ok(m));
  assert(pinned == pos.pinned_pieces(pos.side_to_move()));

  Color us = pos.side_to_move();
  Color them = opposite_color(us);
  Square from = move_from(m);
  Piece pc = pos.piece_on(from);

  // If the from square is not occupied by a piece belonging to the side to
  // move, the move is obviously not legal.
  if (color_of_piece(pc) != us)
      return false;

  Square to = move_to(m);

  // En passant moves
  if (move_is_ep(m))
  {
      // The piece must be a pawn and destination square must be the
      // en passant square.
      if (   type_of_piece(pc) != PAWN
          || to != pos.ep_square())
          return false;

      assert(pos.square_is_empty(to));
      assert(pos.piece_on(to - pawn_push(us)) == pawn_of_color(them));

      // The move is pseudo-legal, check if it is also legal
      return pos.pl_move_is_legal(m, pinned);
  }

  // Castling moves
  if (move_is_short_castle(m))
  {
      // The piece must be a king and side to move must still have
      // the right to castle kingside.
      if (   type_of_piece(pc) != KING
          ||!pos.can_castle_kingside(us))
          return false;

      assert(from == pos.king_square(us));
      assert(to == pos.initial_kr_square(us));
      assert(pos.piece_on(to) == rook_of_color(us));

      Square g1 = relative_square(us, SQ_G1);
      Square f1 = relative_square(us, SQ_F1);
      Square s;
      bool illegal = false;

      // Check if any of the squares between king and rook
      // is occupied or under attack.
      for (s = Min(from, g1); s <= Max(from, g1); s++)
          if (  (s != from && s != to && !pos.square_is_empty(s))
              || pos.square_is_attacked(s, them))
              illegal = true;

      // Check if any of the squares between king and rook
      // is occupied.
      for (s = Min(to, f1); s <= Max(to, f1); s++)
          if (s != from && s != to && !pos.square_is_empty(s))
              illegal = true;

      return !illegal;
  }

  if (move_is_long_castle(m))
  {
      // The piece must be a king and side to move must still have
      // the right to castle kingside.
      if (   type_of_piece(pc) != KING
          ||!pos.can_castle_queenside(us))
          return false;

      assert(from == pos.king_square(us));
      assert(to == pos.initial_qr_square(us));
      assert(pos.piece_on(to) == rook_of_color(us));

      Square c1 = relative_square(us, SQ_C1);
      Square d1 = relative_square(us, SQ_D1);
      Square s;
      bool illegal = false;

      for (s = Min(from, c1); s <= Max(from, c1); s++)
          if(  (s != from && s != to && !pos.square_is_empty(s))
             || pos.square_is_attacked(s, them))
              illegal = true;

      for (s = Min(to, d1); s <= Max(to, d1); s++)
          if(s != from && s != to && !pos.square_is_empty(s))
              illegal = true;

      if (   square_file(to) == FILE_B
          && (   pos.piece_on(to + DELTA_W) == rook_of_color(them)
              || pos.piece_on(to + DELTA_W) == queen_of_color(them)))
          illegal = true;

      return !illegal;
  }

  // Normal moves

  // The destination square cannot be occupied by a friendly piece
  if (pos.color_of_piece_on(to) == us)
      return false;

  // Proceed according to the type of the moving piece.
  if (type_of_piece(pc) == PAWN)
  {
      // If the destination square is on the 8/1th rank, the move must
      // be a promotion.
      if (   (  (square_rank(to) == RANK_8 && us == WHITE)
              ||(square_rank(to) == RANK_1 && us != WHITE))
           && !move_promotion(m))
          return false;

      // Proceed according to the square delta between the source and
      // destionation squares.
      switch (to - from)
      {
      case DELTA_NW:
      case DELTA_NE:
      case DELTA_SW:
      case DELTA_SE:
      // Capture. The destination square must be occupied by an enemy
      // piece (en passant captures was handled earlier).
          if (pos.color_of_piece_on(to) != them)
              return false;
          break;

      case DELTA_N:
      case DELTA_S:
      // Pawn push. The destination square must be empty.
          if (!pos.square_is_empty(to))
              return false;
          break;

      case DELTA_NN:
      // Double white pawn push. The destination square must be on the fourth
      // rank, and both the destination square and the square between the
      // source and destination squares must be empty.
      if (   square_rank(to) != RANK_4
          || !pos.square_is_empty(to)
          || !pos.square_is_empty(from + DELTA_N))
          return false;
          break;

      case DELTA_SS:
      // Double black pawn push. The destination square must be on the fifth
      // rank, and both the destination square and the square between the
      // source and destination squares must be empty.
          if (   square_rank(to) != RANK_5
              || !pos.square_is_empty(to)
              || !pos.square_is_empty(from + DELTA_S))
              return false;
          break;

      default:
          return false;
      }
      // The move is pseudo-legal, check if it is also legal
      return pos.pl_move_is_legal(m, pinned);
  }

  // Luckly we can handle all the other pieces in one go
  return (   pos.piece_attacks_square(from, to)
          && pos.pl_move_is_legal(m, pinned)
          && !move_promotion(m));
}


namespace {

  template<PieceType Piece>
  MoveStack* generate_piece_moves(const Position& pos, MoveStack* mlist, Color us, Bitboard target) {

    Square from;
    Bitboard b;

    for (int i = 0, e = pos.piece_count(us, Piece); i < e; i++)
    {
        from = pos.piece_list(us, Piece, i);
        b = pos.piece_attacks<Piece>(from) & target;
        SERIALIZE_MOVES(b);
    }
    return mlist;
  }

  template<>
  MoveStack* generate_piece_moves<KING>(const Position& pos, MoveStack* mlist, Color us, Bitboard target) {

    Bitboard b;
    Square from = pos.king_square(us);

    b = pos.piece_attacks<KING>(from) & target;
    SERIALIZE_MOVES(b);
    return mlist;
  }

  template<PieceType Piece>
  MoveStack* generate_piece_blocking_evasions(const Position& pos, Bitboard b,
                                              Bitboard blockSquares, MoveStack* mlist) {
    while (b)
    {
        Square from = pop_1st_bit(&b);
        Bitboard bb = pos.piece_attacks<Piece>(from) & blockSquares;
        SERIALIZE_MOVES(bb);
    }
    return mlist;
  }


  template<Color Us, Color Them, Bitboard TRank8BB, SquareDelta TDELTA_NE,
           SquareDelta TDELTA_NW, SquareDelta TDELTA_N
          >
  MoveStack* do_generate_pawn_captures(const Position& pos, MoveStack* mlist) {

    Square to;
    Bitboard pawns = pos.pawns(Us);
    Bitboard enemyPieces = pos.pieces_of_color(Them);

    // Captures in the a1-h8 (a8-h1 for black) direction
    Bitboard b1 = (Us == WHITE ? pawns << 9 : pawns >> 7) & ~FileABB & enemyPieces;

    // Capturing promotions
    Bitboard b2 = b1 & TRank8BB;
    while (b2)
    {
        to = pop_1st_bit(&b2);
        (*mlist++).move = make_promotion_move(to - TDELTA_NE, to, QUEEN);
    }

    // Capturing non-promotions
    b2 = b1 & ~TRank8BB;
    while (b2)
    {
        to = pop_1st_bit(&b2);
        (*mlist++).move = make_move(to - TDELTA_NE, to);
    }

    // Captures in the h1-a8 (h8-a1 for black) direction
    b1 = (Us == WHITE ? pawns << 7 : pawns >> 9) & ~FileHBB & enemyPieces;

    // Capturing promotions
    b2 = b1 & TRank8BB;
    while (b2)
    {
        to = pop_1st_bit(&b2);
        (*mlist++).move = make_promotion_move(to - TDELTA_NW, to, QUEEN);
    }

    // Capturing non-promotions
    b2 = b1 & ~TRank8BB;
    while (b2)
    {
        to = pop_1st_bit(&b2);
        (*mlist++).move = make_move(to - TDELTA_NW, to);
    }

    // Non-capturing promotions
    b1 = (Us == WHITE ? pawns << 8 : pawns >> 8) & pos.empty_squares() & TRank8BB;
    while (b1)
    {
        to = pop_1st_bit(&b1);
        (*mlist++).move = make_promotion_move(to - TDELTA_N, to, QUEEN);
    }

    // En passant captures
    if (pos.ep_square() != SQ_NONE)
    {
        assert(Us != WHITE || square_rank(pos.ep_square()) == RANK_6);
        assert(Us != BLACK || square_rank(pos.ep_square()) == RANK_3);

        b1 = pawns & pos.pawn_attacks(Them, pos.ep_square());
        assert(b1 != EmptyBoardBB);

        while (b1)
        {
            to = pop_1st_bit(&b1);
            (*mlist++).move = make_ep_move(to, pos.ep_square());
        }
    }
    return mlist;
  }

  template<Color Us, Color Them, Bitboard TRank8BB, Bitboard TRank3BB,
           SquareDelta TDELTA_NE, SquareDelta TDELTA_NW, SquareDelta TDELTA_N
          >
  MoveStack* do_generate_pawn_noncaptures(const Position& pos, MoveStack* mlist) {

    Bitboard pawns = pos.pawns(Us);
    Bitboard enemyPieces = pos.pieces_of_color(Them);
    Bitboard emptySquares = pos.empty_squares();
    Bitboard b1, b2;
    Square to;

    // Underpromotion captures in the a1-h8 (a8-h1 for black) direction
    b1 = (Us == WHITE ? pawns << 9 : pawns >> 7) & ~FileABB & enemyPieces & TRank8BB;
    while (b1)
    {
        to = pop_1st_bit(&b1);
        (*mlist++).move = make_promotion_move(to - TDELTA_NE, to, ROOK);
        (*mlist++).move = make_promotion_move(to - TDELTA_NE, to, BISHOP);
        (*mlist++).move = make_promotion_move(to - TDELTA_NE, to, KNIGHT);
    }

    // Underpromotion captures in the h1-a8 (h8-a1 for black) direction
    b1 = (Us == WHITE ? pawns << 7 : pawns >> 9) & ~FileHBB & enemyPieces & TRank8BB;
    while (b1)
    {
        to = pop_1st_bit(&b1);
        (*mlist++).move = make_promotion_move(to - TDELTA_NW, to, ROOK);
        (*mlist++).move = make_promotion_move(to - TDELTA_NW, to, BISHOP);
        (*mlist++).move = make_promotion_move(to - TDELTA_NW, to, KNIGHT);
    }

    // Single pawn pushes
    b1 = (Us == WHITE ? pawns << 8 : pawns >> 8) & emptySquares;
    b2 = b1 & TRank8BB;
    while (b2)
    {
      to = pop_1st_bit(&b2);
      (*mlist++).move = make_promotion_move(to - TDELTA_N, to, ROOK);
      (*mlist++).move = make_promotion_move(to - TDELTA_N, to, BISHOP);
      (*mlist++).move = make_promotion_move(to - TDELTA_N, to, KNIGHT);
    }
    b2 = b1 & ~TRank8BB;
    while (b2)
    {
        to = pop_1st_bit(&b2);
        (*mlist++).move = make_move(to - TDELTA_N, to);
    }

    // Double pawn pushes
    b2 = (Us == WHITE ? (b1 & TRank3BB) << 8 : (b1 & TRank3BB) >> 8) & emptySquares;
    while (b2)
    {
      to = pop_1st_bit(&b2);
      (*mlist++).move = make_move(to - TDELTA_N - TDELTA_N, to);
    }
    return mlist;
  }


  template<Color Us, Color Them, Bitboard TRank8BB, Bitboard TRank3BB, SquareDelta TDELTA_N>
  MoveStack* do_generate_pawn_checks(const Position& pos, Bitboard dc, Square ksq, MoveStack* mlist)
  {
    // Pawn moves which give discovered check. This is possible only if the
    // pawn is not on the same file as the enemy king, because we don't
    // generate captures.
    Bitboard empty = pos.empty_squares();

    // Find all friendly pawns not on the enemy king's file
    Bitboard b1 = pos.pawns(Us) & ~file_bb(ksq), b2, b3;

    // Discovered checks, single pawn pushes
    b2 = b3 = (Us == WHITE ? (b1 & dc) << 8 : (b1 & dc) >> 8) & ~TRank8BB & empty;
    while (b3)
    {
        Square to = pop_1st_bit(&b3);
        (*mlist++).move = make_move(to - TDELTA_N, to);
    }

    // Discovered checks, double pawn pushes
    b3 = (Us == WHITE ? (b2 & TRank3BB) << 8 : (b2 & TRank3BB) >> 8) & empty;
    while (b3)
    {
        Square to = pop_1st_bit(&b3);
        (*mlist++).move = make_move(to - TDELTA_N - TDELTA_N, to);
    }

    // Direct checks. These are possible only for pawns on neighboring files
    // of the enemy king

    b1 &= (~dc & neighboring_files_bb(ksq)); // FIXME why ~dc ??

    // Direct checks, single pawn pushes
    b2 = (Us == WHITE ? b1 << 8 : b1 >> 8) & empty;
    b3 = b2 & pos.pawn_attacks(Them, ksq);
    while (b3)
    {
        Square to = pop_1st_bit(&b3);
        (*mlist++).move = make_move(to - TDELTA_N, to);
    }

    // Direct checks, double pawn pushes
    b3 =  (Us == WHITE ? (b2 & TRank3BB) << 8 : (b2 & TRank3BB) >> 8)
        & empty
        & pos.pawn_attacks(Them, ksq);

    while (b3)
    {
        Square to = pop_1st_bit(&b3);
        (*mlist++).move = make_move(to - TDELTA_N - TDELTA_N, to);
    }
    return mlist;
  }

  template<PieceType Piece>
  MoveStack* generate_piece_checks(const Position& pos, Bitboard target, Bitboard dc,
                                   Square ksq, MoveStack* mlist) {
    // Discovered checks
    Bitboard b = target & dc;
    while (b)
    {
        Square from = pop_1st_bit(&b);
        Bitboard bb = pos.piece_attacks<Piece>(from) & pos.empty_squares();
        SERIALIZE_MOVES(bb);
    }
    // Direct checks
    b = target & ~dc;
    Bitboard checkSqs = pos.piece_attacks<Piece>(ksq) & pos.empty_squares();
    while (b)
    {
        Square from = pop_1st_bit(&b);
        Bitboard bb = pos.piece_attacks<Piece>(from) & checkSqs;
        SERIALIZE_MOVES(bb);
    }
    return mlist;
  }

  MoveStack* generate_piece_checks_king(const Position& pos, Square from, Bitboard dc,
                                        Square ksq, MoveStack* mlist) {
    if (bit_is_set(dc, from))
    {
        Bitboard b =   pos.piece_attacks<KING>(from)
                     & pos.empty_squares()
                     & ~QueenPseudoAttacks[ksq];
        SERIALIZE_MOVES(b);
    }
    return mlist;
  }


  template<Color Us, Rank TRANK_8, Bitboard TRank3BB, SquareDelta TDELTA_N>
  MoveStack* do_generate_pawn_blocking_evasions(const Position& pos, Bitboard not_pinned,
                                                Bitboard blockSquares, MoveStack* mlist) {
    Square to;

    // Find non-pinned pawns
    Bitboard b1 = pos.pawns(Us) & not_pinned;

    // Single pawn pushes. We don't have to AND with empty squares here,
    // because the blocking squares will always be empty.
    Bitboard b2 = (Us == WHITE ? b1 << 8 : b1 >> 8) & blockSquares;
    while (b2)
    {
        to = pop_1st_bit(&b2);

        assert(pos.piece_on(to) == EMPTY);

        if (square_rank(to) == TRANK_8)
        {
            (*mlist++).move = make_promotion_move(to - TDELTA_N, to, QUEEN);
            (*mlist++).move = make_promotion_move(to - TDELTA_N, to, ROOK);
            (*mlist++).move = make_promotion_move(to - TDELTA_N, to, BISHOP);
            (*mlist++).move = make_promotion_move(to - TDELTA_N, to, KNIGHT);
        } else
            (*mlist++).move = make_move(to - TDELTA_N, to);
    }

    // Double pawn pushes
    b2 = (Us == WHITE ? b1 << 8 : b1 >> 8) & pos.empty_squares() & TRank3BB;
    b2 = (Us == WHITE ? b2 << 8 : b2 >> 8) & blockSquares;;
    while (b2)
    {
        to = pop_1st_bit(&b2);

        assert(pos.piece_on(to) == EMPTY);
        assert(Us != WHITE || square_rank(to) == RANK_4);
        assert(Us != BLACK || square_rank(to) == RANK_5);

        (*mlist++).move = make_move(to - TDELTA_N - TDELTA_N, to);
    }
    return mlist;
  }


  MoveStack* generate_castle_moves(const Position& pos, MoveStack* mlist) {

    Color us = pos.side_to_move();

    if (pos.can_castle(us))
    {
        Color them = opposite_color(us);
        Square ksq = pos.king_square(us);

        assert(pos.piece_on(ksq) == king_of_color(us));

        if (pos.can_castle_kingside(us))
        {
            Square rsq = pos.initial_kr_square(us);
            Square g1 = relative_square(us, SQ_G1);
            Square f1 = relative_square(us, SQ_F1);
            Square s;
            bool illegal = false;

            assert(pos.piece_on(rsq) == rook_of_color(us));

            for (s = Min(ksq, g1); s <= Max(ksq, g1); s++)
                if (  (s != ksq && s != rsq && pos.square_is_occupied(s))
                    || pos.square_is_attacked(s, them))
                    illegal = true;

            for (s = Min(rsq, f1); s <= Max(rsq, f1); s++)
                if (s != ksq && s != rsq && pos.square_is_occupied(s))
                    illegal = true;

            if (!illegal)
                (*mlist++).move = make_castle_move(ksq, rsq);
      }

      if (pos.can_castle_queenside(us))
      {
          Square rsq = pos.initial_qr_square(us);
          Square c1 = relative_square(us, SQ_C1);
          Square d1 = relative_square(us, SQ_D1);
          Square s;
          bool illegal = false;

          assert(pos.piece_on(rsq) == rook_of_color(us));

          for (s = Min(ksq, c1); s <= Max(ksq, c1); s++)
              if (  (s != ksq && s != rsq && pos.square_is_occupied(s))
                  || pos.square_is_attacked(s, them))
                  illegal = true;

          for (s = Min(rsq, d1); s <= Max(rsq, d1); s++)
              if (s != ksq && s != rsq && pos.square_is_occupied(s))
                  illegal = true;

        if (   square_file(rsq) == FILE_B
            && (   pos.piece_on(relative_square(us, SQ_A1)) == rook_of_color(them)
                || pos.piece_on(relative_square(us, SQ_A1)) == queen_of_color(them)))
            illegal = true;

        if (!illegal)
            (*mlist++).move = make_castle_move(ksq, rsq);
      }
    }
    return mlist;
  }

}

// ======== movepick.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.


  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cassert>



////
//// Local definitions
////

namespace {

  /// Variables

  MovePicker::MovegenPhase PhaseTable[32];
  int MainSearchPhaseIndex;
  int EvasionsPhaseIndex;
  int QsearchWithChecksPhaseIndex;
  int QsearchWithoutChecksPhaseIndex;

}



////
//// Functions
////


/// Constructor for the MovePicker class.  Apart from the position for which
/// it is asked to pick legal moves, MovePicker also wants some information
/// to help it to return the presumably good moves first, to decide which
/// moves to return (in the quiescence search, for instance, we only want to
/// search captures, promotions and some checks) and about how important good
/// move ordering is at the current node.

MovePicker::MovePicker(const Position& p, bool pvnode, Move ttm, Move mk,
                       Move k1, Move k2, Depth d) : pos(p) {
  pvNode = pvnode;
  ttMove = ttm;
  mateKiller = (mk == ttm)? MOVE_NONE : mk;
  killer1 = k1;
  killer2 = k2;
  depth = d;
  movesPicked = 0;
  numOfMoves = 0;
  numOfBadCaptures = 0;
  dc = p.discovered_check_candidates(p.side_to_move());

  if (p.is_check())
    phaseIndex = EvasionsPhaseIndex;
  else if (depth > Depth(0))
    phaseIndex = MainSearchPhaseIndex;
  else if (depth == Depth(0))
    phaseIndex = QsearchWithChecksPhaseIndex;
  else
    phaseIndex = QsearchWithoutChecksPhaseIndex;

  pinned = p.pinned_pieces(p.side_to_move());

  finished = false;
}


/// MovePicker::get_next_move() is the most important method of the MovePicker
/// class.  It returns a new legal move every time it is called, until there
/// are no more moves left of the types we are interested in.

Move MovePicker::get_next_move() {

  Move move;

  while (true)
  {
    // If we already have a list of generated moves, pick the best move from
    // the list, and return it.
    move = pick_move_from_list();
    if (move != MOVE_NONE)
    {
        assert(move_is_ok(move));
        return move;
    }

    // Next phase
    phaseIndex++;
    switch (PhaseTable[phaseIndex]) {

    case PH_TT_MOVE:
        if (ttMove != MOVE_NONE)
        {
            assert(move_is_ok(ttMove));
            if (move_is_legal(pos, ttMove, pinned))
                return ttMove;
        }
        break;

    case PH_MATE_KILLER:
        if (mateKiller != MOVE_NONE)
        {
            assert(move_is_ok(mateKiller));
            if (move_is_legal(pos, mateKiller, pinned))
                return mateKiller;
       }
       break;

    case PH_GOOD_CAPTURES:
        numOfMoves = generate_captures(pos, moves);
        score_captures();
        movesPicked = 0;
        break;

    case PH_BAD_CAPTURES:
        badCapturesPicked = 0;
        break;

    case PH_NONCAPTURES:
        numOfMoves = generate_noncaptures(pos, moves);
        score_noncaptures();
        movesPicked = 0;
        break;

    case PH_EVASIONS:
        assert(pos.is_check());
        numOfMoves = generate_evasions(pos, moves);
        score_evasions();
        movesPicked = 0;
        break;

    case PH_QCAPTURES:
        numOfMoves = generate_captures(pos, moves);
        score_qcaptures();
        movesPicked = 0;
        break;

    case PH_QCHECKS:
        numOfMoves = generate_checks(pos, moves, dc);
        movesPicked = 0;
        break;

    case PH_STOP:
        return MOVE_NONE;

    default:
        assert(false);
        return MOVE_NONE;
    }
  }
}


/// A variant of get_next_move() which takes a lock as a parameter, used to
/// prevent multiple threads from picking the same move at a split point.

Move MovePicker::get_next_move(Lock &lock) {

   lock_grab(&lock);
   if (finished)
   {
       lock_release(&lock);
       return MOVE_NONE;
   }
   Move m = get_next_move();
   if (m == MOVE_NONE)
       finished = true;

   lock_release(&lock);
   return m;
}


/// MovePicker::score_captures(), MovePicker::score_noncaptures(),
/// MovePicker::score_evasions() and MovePicker::score_qcaptures() assign a
/// numerical move ordering score to each move in a move list.  The moves
/// with highest scores will be picked first by pick_move_from_list().

void MovePicker::score_captures() {
  // Winning and equal captures in the main search are ordered by MVV/LVA.
  // Suprisingly, this appears to perform slightly better than SEE based
  // move ordering.  The reason is probably that in a position with a winning
  // capture, capturing a more valuable (but sufficiently defended) piece
  // first usually doesn't hurt.  The opponent will have to recapture, and
  // the hanging piece will still be hanging (except in the unusual cases
  // where it is possible to recapture with the hanging piece). Exchanging
  // big pieces before capturing a hanging piece probably helps to reduce
  // the subtree size.
  Move m;
  int seeValue;

  for (int i = 0; i < numOfMoves; i++)
  {
      m = moves[i].move;
      seeValue = pos.see(m);
      if (seeValue >= 0)
      {
          if (move_promotion(m))
              moves[i].score = QueenValueMidgame;
          else
              moves[i].score = int(pos.midgame_value_of_piece_on(move_to(m)))
                              -int(pos.type_of_piece_on(move_from(m)));
      } else
          moves[i].score = seeValue;
  }
}

void MovePicker::score_noncaptures() {
  // First score by history, when no history is available then use
  // piece/square tables values. This seems to be better then a
  // random choice when we don't have an history for any move.
  Move m;
  int hs;

  for (int i = 0; i < numOfMoves; i++)
  {
      m = moves[i].move;

      if (m == killer1)
          hs = HistoryMax + 2;
      else if (m == killer2)
          hs = HistoryMax + 1;
      else
          hs = H.move_ordering_score(pos.piece_on(move_from(m)), m);

      // Ensure moves in history are always sorted as first
      if (hs > 0)
          hs += 1000;

      moves[i].score = hs + pos.mg_pst_delta(m);
  }
}

void MovePicker::score_evasions() {

  for (int i = 0; i < numOfMoves; i++)
  {
      Move m = moves[i].move;
      if (m == ttMove)
          moves[i].score = 2*HistoryMax;
      else if (!pos.square_is_empty(move_to(m)))
      {
          int seeScore = pos.see(m);
          moves[i].score = (seeScore >= 0)? seeScore + HistoryMax : seeScore;
      } else
          moves[i].score = H.move_ordering_score(pos.piece_on(move_from(m)), m);
  }
  // FIXME try psqt also here
}

void MovePicker::score_qcaptures() {

  // Use MVV/LVA ordering
  for (int i = 0; i < numOfMoves; i++)
  {
      Move m = moves[i].move;
      if (move_promotion(m))
          moves[i].score = QueenValueMidgame;
      else
          moves[i].score = int(pos.midgame_value_of_piece_on(move_to(m)))
                          -int(pos.type_of_piece_on(move_from(m)));
  }
}


/// find_best_index() loops across the moves and returns index of
/// the highest scored one.

int MovePicker::find_best_index() {

  int bestScore = -10000000, bestIndex = -1;

  for (int i = movesPicked; i < numOfMoves; i++)
      if (moves[i].score > bestScore)
      {
          bestIndex = i;
          bestScore = moves[i].score;
      }
  return bestIndex;
}


/// MovePicker::pick_move_from_list() picks the move with the biggest score
/// from a list of generated moves (moves[] or badCaptures[], depending on
/// the current move generation phase).  It takes care not to return the
/// transposition table move if that has already been serched previously.
/// While picking captures in the PH_GOOD_CAPTURES phase (i.e. while picking
/// non-losing captures in the main search), it moves all captures with
/// negative SEE values to the badCaptures[] array.

Move MovePicker::pick_move_from_list() {

  int bestIndex;
  Move move;

  switch (PhaseTable[phaseIndex]) {
  case PH_GOOD_CAPTURES:
      assert(!pos.is_check());
      assert(movesPicked >= 0);

      while (movesPicked < numOfMoves)
      {
          int bestScore = -10000000;
          bestIndex = -1;
          for (int i = movesPicked; i < numOfMoves; i++)
          {
              if (moves[i].score < 0)
              {
                  // Losing capture, move it to the badCaptures[] array
                  assert(numOfBadCaptures < 63);
                  badCaptures[numOfBadCaptures++] = moves[i];
                  moves[i--] = moves[--numOfMoves];
              }
              else if (moves[i].score > bestScore)
              {
                  bestIndex = i;
                  bestScore = moves[i].score;
              }
          }
          if (bestIndex != -1) // Found a good capture
          {
              move = moves[bestIndex].move;
              moves[bestIndex] = moves[movesPicked++];
              if (   move != ttMove
                  && move != mateKiller
                  && pos.pl_move_is_legal(move, pinned))
                  return move;
          }
      }
      break;

  case PH_NONCAPTURES:
      assert(!pos.is_check());
      assert(movesPicked >= 0);

      while (movesPicked < numOfMoves)
      {
          // If this is a PV node or we have only picked a few moves, scan
          // the entire move list for the best move.  If many moves have already
          // been searched and it is not a PV node, we are probably failing low
          // anyway, so we just pick the first move from the list.
          bestIndex = (pvNode || movesPicked < 12) ? find_best_index() : movesPicked;

          if (bestIndex != -1)
          {
              move = moves[bestIndex].move;
              moves[bestIndex] = moves[movesPicked++];
              if (   move != ttMove
                  && move != mateKiller
                  && pos.pl_move_is_legal(move, pinned))
                  return move;
          }
      }
      break;

  case PH_EVASIONS:
      assert(pos.is_check());
      assert(movesPicked >= 0);

      while (movesPicked < numOfMoves)
      {
          bestIndex = find_best_index();

          if (bestIndex != -1)
          {
              move = moves[bestIndex].move;
              moves[bestIndex] = moves[movesPicked++];
              return move;
          }
    }
    break;

  case PH_BAD_CAPTURES:
      assert(!pos.is_check());
      assert(badCapturesPicked >= 0);
      // It's probably a good idea to use SEE move ordering here, instead
      // of just picking the first move.  FIXME
      while (badCapturesPicked < numOfBadCaptures)
      {
          move = badCaptures[badCapturesPicked++].move;
          if (   move != ttMove
              && move != mateKiller
              && pos.pl_move_is_legal(move, pinned))
              return move;
      }
      break;

  case PH_QCAPTURES:
      assert(!pos.is_check());
      assert(movesPicked >= 0);
      while (movesPicked < numOfMoves)
      {
          bestIndex = (movesPicked < 4 ? find_best_index() : movesPicked);

          if (bestIndex != -1)
          {
              move = moves[bestIndex].move;
              moves[bestIndex] = moves[movesPicked++];
              // Remember to change the line below if we decide to hash the qsearch!
              // Maybe also postpone the legality check until after futility pruning?
              if (/* move != ttMove && */ pos.pl_move_is_legal(move, pinned))
                  return move;
          }
      }
      break;

  case PH_QCHECKS:
      assert(!pos.is_check());
      assert(movesPicked >= 0);
      // Perhaps we should do something better than just picking the first
      // move here?  FIXME
      while (movesPicked < numOfMoves)
      {
          move = moves[movesPicked++].move;
          // Remember to change the line below if we decide to hash the qsearch!
          if (/* move != ttMove && */ pos.pl_move_is_legal(move, pinned))
              return move;
      }
      break;

  default:
      break;
  }
  return MOVE_NONE;
}


/// MovePicker::current_move_type() returns the type of the just
/// picked next move. It can be used in search to further differentiate
/// according to the current move type: capture, non capture, escape, etc.
MovePicker::MovegenPhase MovePicker::current_move_type() const {

  return PhaseTable[phaseIndex];
}


/// MovePicker::init_phase_table() initializes the PhaseTable[],
/// MainSearchPhaseIndex, EvasionPhaseIndex, QsearchWithChecksPhaseIndex
/// and QsearchWithoutChecksPhaseIndex variables. It is only called once
/// during program startup, and never again while the program is running.

void MovePicker::init_phase_table() {

  PhaseTable[0] = PH_STOP;
  int i = 1;

  // Main search
  MainSearchPhaseIndex = i - 1;
  PhaseTable[i++] = PH_TT_MOVE;
  PhaseTable[i++] = PH_MATE_KILLER;
  PhaseTable[i++] = PH_GOOD_CAPTURES;
  // PH_KILLER_1 and PH_KILLER_2 are not yet used.
  // PhaseTable[i++] = PH_KILLER_1;
  // PhaseTable[i++] = PH_KILLER_2;
  PhaseTable[i++] = PH_NONCAPTURES;
  PhaseTable[i++] = PH_BAD_CAPTURES;
  PhaseTable[i++] = PH_STOP;

  // Check evasions
  EvasionsPhaseIndex = i - 1;
  PhaseTable[i++] = PH_EVASIONS;
  PhaseTable[i++] = PH_STOP;

  // Quiescence search with checks
  QsearchWithChecksPhaseIndex = i - 1;
  PhaseTable[i++] = PH_QCAPTURES;
  PhaseTable[i++] = PH_QCHECKS;
  PhaseTable[i++] = PH_STOP;

  // Quiescence search without checks
  QsearchWithoutChecksPhaseIndex = i - 1;
  PhaseTable[i++] = PH_QCAPTURES;
  PhaseTable[i++] = PH_STOP;
}

// ======== pawns.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cassert>



////
//// Local definitions
////

namespace {

  /// Constants and variables

  // Doubled pawn penalty by file, middle game.
  const Value DoubledPawnMidgamePenalty[8] = {
    Value(20), Value(30), Value(34), Value(34),
    Value(34), Value(34), Value(30), Value(20)
  };

  // Doubled pawn penalty by file, endgame.
  const Value DoubledPawnEndgamePenalty[8] = {
    Value(35), Value(40), Value(40), Value(40),
    Value(40), Value(40), Value(40), Value(35)
  };

  // Isolated pawn penalty by file, middle game.
  const Value IsolatedPawnMidgamePenalty[8] = {
    Value(20), Value(30), Value(34), Value(34),
    Value(34), Value(34), Value(30), Value(20)
  };

  // Isolated pawn penalty by file, endgame.
  const Value IsolatedPawnEndgamePenalty[8] = {
    Value(35), Value(40), Value(40), Value(40),
    Value(40), Value(40), Value(40), Value(35)
  };

  // Backward pawn penalty by file, middle game.
  const Value BackwardPawnMidgamePenalty[8] = {
    Value(16), Value(24), Value(27), Value(27),
    Value(27), Value(27), Value(24), Value(16)
  };

  // Backward pawn penalty by file, endgame.
  const Value BackwardPawnEndgamePenalty[8] = {
    Value(28), Value(32), Value(32), Value(32),
    Value(32), Value(32), Value(32), Value(28)
  };

  // Pawn chain membership bonus by file, middle game. 
  const Value ChainMidgameBonus[8] = {
    Value(14), Value(16), Value(17), Value(18),
    Value(18), Value(17), Value(16), Value(14)
  };

  // Pawn chain membership bonus by file, endgame. 
  const Value ChainEndgameBonus[8] = {
    Value(16), Value(16), Value(16), Value(16),
    Value(16), Value(16), Value(16), Value(16)
  };

  // Candidate passed pawn bonus by rank, middle game.
  const Value CandidateMidgameBonus[8] = {
    Value(0), Value(12), Value(12), Value(20),
    Value(40), Value(90), Value(0), Value(0)
  };

  // Candidate passed pawn bonus by rank, endgame.
  const Value CandidateEndgameBonus[8] = {
    Value(0), Value(24), Value(24), Value(40),
    Value(80), Value(180), Value(0), Value(0)
  };

  // Evaluate pawn storms?
  const bool EvaluatePawnStorms = true;

  // Pawn storm tables for positions with opposite castling:
  const int QStormTable[64] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    -22, -22, -22, -13, -4, 0, 0, 0,
    -4, -9, -9, -9, -4, 0, 0, 0,
    9, 18, 22, 18, 9, 0, 0, 0,
    22, 31, 31, 22, 0, 0, 0, 0,
    31, 40, 40, 31, 0, 0, 0, 0,
    31, 40, 40, 31, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
  };
  
  const int KStormTable[64] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, -13, -22, -27, -27,
    0, 0, 0, -4, -9, -13, -18, -18,
    0, 0, 0, 0, 9, 9, 9, 9,
    0, 0, 0, 0, 9, 18, 27, 27,
    0, 0, 0, 0, 9, 27, 40, 36,
    0, 0, 0, 0, 0, 31, 40, 31,
    0, 0, 0, 0, 0, 0, 0, 0
  };

  // Pawn storm open file bonuses by file:
  const int KStormOpenFileBonus[8] = {
    45, 45, 30, 0, 0, 0, 0, 0
  };

  const int QStormOpenFileBonus[8] = {
    0, 0, 0, 0, 0, 30, 45, 30
  };

}


////
//// Functions
////

/// Constructor

PawnInfoTable::PawnInfoTable(unsigned numOfEntries) {
  size = numOfEntries;
  entries = new PawnInfo[size];
  if(entries == NULL) {
    std::cerr << "Failed to allocate " << (numOfEntries * sizeof(PawnInfo))
              << " bytes for pawn hash table." << std::endl;
    exit(EXIT_FAILURE);
  }
  this->clear();
}


/// Destructor

PawnInfoTable::~PawnInfoTable() {
  delete [] entries;
}


/// PawnInfoTable::clear() clears the pawn hash table by setting all
/// entries to 0.

void PawnInfoTable::clear() {
  memset(entries, 0, size * sizeof(PawnInfo));
}


/// PawnInfoTable::get_pawn_info() takes a position object as input, computes
/// a PawnInfo object, and returns a pointer to it.  The result is also 
/// stored in a hash table, so we don't have to recompute everything when
/// the same pawn structure occurs again.

PawnInfo *PawnInfoTable::get_pawn_info(const Position &pos) {
  assert(pos.is_ok());

  Key key = pos.get_pawn_key();
  int index = int(key & (size - 1));
  PawnInfo *pi = entries + index;

  // If pi->key matches the position's pawn hash key, it means that we 
  // have analysed this pawn structure before, and we can simply return the
  // information we found the last time instead of recomputing it:
  if(pi->key == key)
    return pi;

  // Clear the PawnInfo object, and set the key:
  pi->clear();
  pi->key = key;

  Value mgValue[2] = {Value(0), Value(0)};
  Value egValue[2] = {Value(0), Value(0)};

  // Loop through the pawns for both colors:
  for(Color us = WHITE; us <= BLACK; us++) {
    Color them = opposite_color(us);
    Bitboard ourPawns = pos.pawns(us);
    Bitboard theirPawns = pos.pawns(them);
    Bitboard pawns = ourPawns;

    // Initialize pawn storm scores by giving bonuses for open files:
    if(EvaluatePawnStorms)
      for(File f = FILE_A; f <= FILE_H; f++)
        if(pos.file_is_half_open(us, f)) {
          pi->ksStormValue[us] += KStormOpenFileBonus[f];
          pi->qsStormValue[us] += QStormOpenFileBonus[f];
        }

    // Loop through all pawns of the current color and score each pawn:
    while(pawns) {
      Square s = pop_1st_bit(&pawns);
      File f = square_file(s);
      Rank r = square_rank(s);
      bool passed, doubled, isolated, backward, chain, candidate;
      int bonus;

      assert(pos.piece_on(s) == pawn_of_color(us));

      // The file containing the pawn is not half open:
      pi->halfOpenFiles[us] &= ~(1 << f);

      // Passed, isolated or doubled pawn?
      passed = pos.pawn_is_passed(us, s);
      isolated = pos.pawn_is_isolated(us, s);
      doubled = pos.pawn_is_doubled(us, s);

      if(EvaluatePawnStorms) {
        // We calculate kingside and queenside pawn storm
        // scores for both colors.  These are used when evaluating
        // middle game positions with opposite side castling.
        //
        // Each pawn is given a base score given by a piece square table
        // (KStormTable[] or QStormTable[]).  This score is increased if
        // there are enemy pawns on adjacent files in front of the pawn.
        // This is because we want to be able to open files against the
        // enemy king, and to avoid blocking the pawn structure (e.g. white
        // pawns on h6, g5, black pawns on h7, g6, f7).
        
        // Kingside pawn storms:
        bonus = KStormTable[relative_square(us, s)];
        if(bonus > 0 && outpost_mask(us, s) & theirPawns) {
          switch(f) {

          case FILE_F:
            bonus += bonus / 4;
            break;

          case FILE_G:
            bonus += bonus / 2 + bonus / 4;
            break;

          case FILE_H:
            bonus += bonus / 2;
            break;

          default:
            break;
          }
        }
        pi->ksStormValue[us] += bonus;

        // Queenside pawn storms:
        bonus = QStormTable[relative_square(us, s)];
        if(bonus > 0 && passed_pawn_mask(us, s) & theirPawns) {
          switch(f) {

          case FILE_A:
            bonus += bonus / 2;
            break;

          case FILE_B:
            bonus += bonus / 2 + bonus / 4;
            break;

          case FILE_C:
            bonus += bonus / 2;
            break;

          default:
            break;
          }
        }
        pi->qsStormValue[us] += bonus;
      }
      
      // Member of a pawn chain?  We could speed up the test a little by 
      // introducing an array of masks indexed by color and square for doing
      // the test, but because everything is hashed, it probably won't make
      // any noticable difference.
      chain = (us == WHITE)?
        (ourPawns & neighboring_files_bb(f) & (rank_bb(r) | rank_bb(r-1))) :
        (ourPawns & neighboring_files_bb(f) & (rank_bb(r) | rank_bb(r+1)));


      // Test for backward pawn.

      // If the pawn is isolated, passed, or member of a pawn chain, it cannot
      // be backward:
      if(passed || isolated || chain)
        backward = false;
      // If the pawn can capture an enemy pawn, it's not backward:
      else if(pos.pawn_attacks(us, s) & theirPawns)
        backward = false;
      // Check for friendly pawns behind on neighboring files:
      else if(ourPawns & in_front_bb(them, r) & neighboring_files_bb(f))
        backward = false;
      else {
        // We now know that there is no friendly pawns beside or behind this
        // pawn on neighboring files.  We now check whether the pawn is
        // backward by looking in the forward direction on the neighboring
        // files, and seeing whether we meet a friendly or an enemy pawn first.
        Bitboard b;
        if(us == WHITE) {
          for(b=pos.pawn_attacks(us, s); !(b&(ourPawns|theirPawns)); b<<=8);
          backward = (b | (b << 8)) & theirPawns;
        }
        else {
          for(b=pos.pawn_attacks(us, s); !(b&(ourPawns|theirPawns)); b>>=8);
          backward = (b | (b >> 8)) & theirPawns;
        }
      }

      // Test for candidate passed pawn.
      candidate =
        (!passed && pos.file_is_half_open(them, f) &&
         count_1s_max_15(neighboring_files_bb(f)
                         & (in_front_bb(them, r) | rank_bb(r))
                         & ourPawns)
         - count_1s_max_15(neighboring_files_bb(f) & in_front_bb(us, r)
                           & theirPawns)
         >= 0);

      // In order to prevent doubled passed pawns from receiving a too big
      // bonus, only the frontmost passed pawn on each file is considered as
      // a true passed pawn.
      if(passed && (ourPawns & squares_in_front_of(us, s))) {
        // candidate = true;
        passed = false;
      }

      // Score this pawn:
      Value mv = Value(0), ev = Value(0);
      if(isolated) {
        mv -= IsolatedPawnMidgamePenalty[f];
        ev -= IsolatedPawnEndgamePenalty[f];
        if(pos.file_is_half_open(them, f)) {
          mv -= IsolatedPawnMidgamePenalty[f] / 2;
          ev -= IsolatedPawnEndgamePenalty[f] / 2;
        }
      }
      if(doubled)  {
        mv -= DoubledPawnMidgamePenalty[f];
        ev -= DoubledPawnEndgamePenalty[f];
      }
      if(backward)  {
        mv -= BackwardPawnMidgamePenalty[f];
        ev -= BackwardPawnEndgamePenalty[f];
        if(pos.file_is_half_open(them, f)) {
          mv -= BackwardPawnMidgamePenalty[f] / 2;
          ev -= BackwardPawnEndgamePenalty[f] / 2;
        }
      }
      if(chain) {
        mv += ChainMidgameBonus[f];
        ev += ChainEndgameBonus[f];
      }
      if(candidate) {
        mv += CandidateMidgameBonus[relative_rank(us, s)];
        ev += CandidateEndgameBonus[relative_rank(us, s)];
      }

      mgValue[us] += mv;
      egValue[us] += ev;
        
      // If the pawn is passed, set the square of the pawn in the passedPawns
      // bitboard:
      if(passed)
        set_bit(&(pi->passedPawns), s);
    }
  }

  pi->mgValue = int16_t(mgValue[WHITE] - mgValue[BLACK]);
  pi->egValue = int16_t(egValue[WHITE] - egValue[BLACK]);

  return pi;
}

// ======== piece.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cstring>



////
//// Constants and variables
////

const int SlidingArray[18] = {
  0, 0, 0, 1, 2, 3, 0, 0, 0, 0, 0, 1, 2, 3, 0, 0, 0, 0
};

const SquareDelta Directions[16][16] = {
  {DELTA_ZERO},
  {DELTA_NW, DELTA_NE, DELTA_ZERO},
  {DELTA_SSW, DELTA_SSE, DELTA_SWW, DELTA_SEE,
   DELTA_NWW, DELTA_NEE, DELTA_NNW, DELTA_NNE, DELTA_ZERO},
  {DELTA_SE, DELTA_SW, DELTA_NE, DELTA_NW, DELTA_ZERO},
  {DELTA_S, DELTA_E, DELTA_W, DELTA_N, DELTA_ZERO},
  {DELTA_S, DELTA_E, DELTA_W, DELTA_N, 
   DELTA_SE, DELTA_SW, DELTA_NE, DELTA_NW, DELTA_ZERO},
  {DELTA_S, DELTA_E, DELTA_W, DELTA_N, 
   DELTA_SE, DELTA_SW, DELTA_NE, DELTA_NW, DELTA_ZERO},
  {DELTA_ZERO},
  {DELTA_ZERO},
  {DELTA_SW, DELTA_SE, DELTA_ZERO},
  {DELTA_SSW, DELTA_SSE, DELTA_SWW, DELTA_SEE,
   DELTA_NWW, DELTA_NEE, DELTA_NNW, DELTA_NNE, DELTA_ZERO},
  {DELTA_SE, DELTA_SW, DELTA_NE, DELTA_NW, DELTA_ZERO},
  {DELTA_S, DELTA_E, DELTA_W, DELTA_N, DELTA_ZERO},
  {DELTA_S, DELTA_E, DELTA_W, DELTA_N, 
   DELTA_SE, DELTA_SW, DELTA_NE, DELTA_NW, DELTA_ZERO},
  {DELTA_S, DELTA_E, DELTA_W, DELTA_N, 
   DELTA_SE, DELTA_SW, DELTA_NE, DELTA_NW, DELTA_ZERO},
};   

const SquareDelta PawnPush[2] = {
  DELTA_N, DELTA_S
};


////
//// Functions
////

/// Translating piece types to/from English piece letters:

static const char PieceChars[] = " pnbrqk";

char piece_type_to_char(PieceType pt, bool upcase = false) {
  return upcase? toupper(PieceChars[pt]) : PieceChars[pt];
}

PieceType piece_type_from_char(char c) {
  const char *ch = strchr(PieceChars, tolower(c));
  return ch? PieceType(ch - PieceChars) : NO_PIECE_TYPE;
}


/// piece_is_ok() and piece_type_is_ok(), for debugging:

bool piece_is_ok(Piece pc) {
  return
    piece_type_is_ok(type_of_piece(pc)) &&
    color_is_ok(color_of_piece(pc));
}

bool piece_type_is_ok(PieceType pc) {
  return pc >= PAWN && pc <= KING;
}

// ======== position.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cassert>
#include <iostream>
#include <fstream>

// ---- begin psqtab.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(PSQTAB_H_INCLUDED)
#define PSQTAB_H_INCLUDED

////
//// Includes
////



////
//// Variables
////

static const Value MP = PawnValueMidgame;
static const Value MK = KnightValueMidgame;
static const Value MB = BishopValueMidgame;
static const Value MR = RookValueMidgame;
static const Value MQ = QueenValueMidgame;

static const int MgPST[][64] = {
  { },
  {// Pawn
   // A      B      C      D      E      F      G      H
        0,     0,     0,     0,     0,     0,     0,     0,
    MP-38, MP-12, MP- 0, MP+12, MP+12, MP- 0, MP-12, MP-38,
    MP-38, MP-12, MP+ 6, MP+38, MP+38, MP+ 6, MP-12, MP-38,
    MP-38, MP-12, MP+16, MP+64, MP+64, MP+16, MP-12, MP-38,
    MP-38, MP-12, MP+16, MP+38, MP+38, MP+16, MP-12, MP-38,
    MP-38, MP-12, MP+ 6, MP+12, MP+12, MP+ 6, MP-12, MP-38,
    MP-38, MP-12, MP- 0, MP+12, MP+12, MP- 0, MP-12, MP-38,
        0,     0,     0,     0,     0,     0,     0,     0
  },
  {// Knight
   //  A      B       C      D      E      F      G       H
    MK-128, MK-102, MK-76, MK-64, MK-64, MK-76, MK-102, MK-128,
    MK- 89, MK- 64, MK-38, MK-25, MK-25, MK-38, MK- 64, MK- 89,
    MK- 51, MK- 25, MK- 0, MK+12, MK+12, MK- 0, MK- 25, MK- 51,
    MK- 25, MK-  0, MK+25, MK+38, MK+38, MK+25, MK-  0, MK- 25,
    MK- 12, MK+ 12, MK+38, MK+51, MK+51, MK+38, MK+ 12, MK- 12,
    MK- 12, MK+ 12, MK+38, MK+51, MK+51, MK+38, MK+ 12, MK- 12,
    MK- 51, MK- 25, MK- 0, MK+12, MK+12, MK- 0, MK- 25, MK- 51,
    MK-182, MK- 64, MK-38, MK-25, MK-25, MK-38, MK- 64, MK-182
  },
  {// Bishop
   // A      B      C      D      E      F      G      H
    MB-46, MB-46, MB-40, MB-35, MB-35, MB-40, MB-46, MB-46,
    MB-20, MB- 0, MB- 5, MB- 0, MB- 0, MB- 5, MB- 0, MB-20,
    MB-15, MB- 5, MB+10, MB+ 5, MB+ 5, MB+10, MB- 5, MB-15,
    MB-10, MB- 0, MB+ 5, MB+20, MB+20, MB+ 5, MB- 0, MB-10,
    MB-10, MB- 0, MB+ 5, MB+20, MB+20, MB+ 5, MB- 0, MB-10,
    MB-15, MB- 5, MB+10, MB+ 5, MB+ 5, MB+10, MB- 5, MB-15,
    MB-20, MB- 0, MB- 5, MB- 0, MB- 0, MB- 5, MB- 0, MB-20,
    MB-20, MB-20, MB-15, MB-10, MB-10, MB-15, MB-20, MB-20
  },
  {// Rook
   // A      B      C     D     E     F     G      H
    MR-18, MR-10, MR-3, MR+4, MR+4, MR-3, MR-10, MR-18,
    MR-18, MR-10, MR-3, MR+4, MR+4, MR-3, MR-10, MR-18,
    MR-18, MR-10, MR-3, MR+4, MR+4, MR-3, MR-10, MR-18,
    MR-18, MR-10, MR-3, MR+4, MR+4, MR-3, MR-10, MR-18,
    MR-18, MR-10, MR-3, MR+4, MR+4, MR-3, MR-10, MR-18,
    MR-18, MR-10, MR-3, MR+4, MR+4, MR-3, MR-10, MR-18,
    MR-18, MR-10, MR-3, MR+4, MR+4, MR-3, MR-10, MR-18,
    MR-18, MR-10, MR-3, MR+4, MR+4, MR-3, MR-10, MR-18
  },
  {// Queen
   //A   B   C   D   E   F   G   H
    MQ, MQ, MQ, MQ, MQ, MQ, MQ, MQ,
    MQ, MQ, MQ, MQ, MQ, MQ, MQ, MQ,
    MQ, MQ, MQ, MQ, MQ, MQ, MQ, MQ,
    MQ, MQ, MQ, MQ, MQ, MQ, MQ, MQ,
    MQ, MQ, MQ, MQ, MQ, MQ, MQ, MQ,
    MQ, MQ, MQ, MQ, MQ, MQ, MQ, MQ,
    MQ, MQ, MQ, MQ, MQ, MQ, MQ, MQ,
    MQ, MQ, MQ, MQ, MQ, MQ, MQ, MQ
  },
  {// King
   //A    B    C    D    E    F    G    H
    302, 328, 276, 225, 225, 276, 328, 302,
    276, 302, 251, 200, 200, 251, 302, 276,
    225, 251, 200, 149, 149, 200, 251, 225,
    200, 225, 175, 124, 124, 175, 225, 200,
    175, 200, 149,  98,  98, 149, 200, 175,
    149, 175, 124,  72,  72, 124, 175, 149,
    124, 149,  98,  47,  47,  98, 149, 124,
     98, 124,  72,  21,  21,  72, 124,  98
  }
};

static const Value EP = PawnValueEndgame;
static const Value EK = KnightValueEndgame;
static const Value EB = BishopValueEndgame;
static const Value ER = RookValueEndgame;
static const Value EQ = QueenValueEndgame;

static const int EgPST[][64] = {
  { },
  {// Pawn
   //A   B   C   D   E   F   G   H
     0,  0,  0,  0,  0,  0,  0,  0,
    EP, EP, EP, EP, EP, EP, EP, EP,
    EP, EP, EP, EP, EP, EP, EP, EP,
    EP, EP, EP, EP, EP, EP, EP, EP,
    EP, EP, EP, EP, EP, EP, EP, EP,
    EP, EP, EP, EP, EP, EP, EP, EP,
    EP, EP, EP, EP, EP, EP, EP, EP,
     0,  0,  0,  0,  0,  0,  0,  0
  },
  {// Knight
   // A       B      C      D      E      F      G      H
    EK-102, EK-76, EK-51, EK-38, EK-38, EK-51, EK-76, EK-102,
    EK- 76, EK-51, EK-25, EK-12, EK-12, EK-25, EK-51, EK-76,
    EK- 51, EK-25, EK- 0, EK+12, EK+12, EK- 0, EK-25, EK-51,
    EK- 38, EK-12, EK+12, EK+25, EK+25, EK+12, EK-12, EK-38,
    EK- 38, EK-12, EK+12, EK+25, EK+25, EK+12, EK-12, EK-38,
    EK- 51, EK-25, EK- 0, EK+12, EK+12, EK- 0, EK-25, EK-51,
    EK- 76, EK-51, EK-25, EK-12, EK-12, EK-25, EK-51, EK-76,
    EK-102, EK-76, EK-51, EK-38, EK-38, EK-51, EK-76, EK-102
  },
  {// Bishop
   // A      B      C      D      E      F      G      H
    EB-46, EB-30, EB-23, EB-15, EB-15, EB-23, EB-30, EB-46,
    EB-30, EB-15, EB- 7, EB- 0, EB- 0, EB- 7, EB-15, EB-30,
    EB-23, EB- 7, EB- 0, EB+ 7, EB+ 7, EB- 0, EB- 7, EB-23,
    EB-15, EB- 0, EB+ 7, EB+15, EB+15, EB+ 7, EB- 0, EB-15,
    EB-15, EB- 0, EB+ 7, EB+15, EB+15, EB+ 7, EB- 0, EB-15,
    EB-23, EB- 7, EB- 0, EB+ 7, EB+ 7, EB- 0, EB- 7, EB-23,
    EB-30, EB-15, EB- 7, EB- 0, EB- 0, EB- 7, EB-15, EB-30,
    EB-46, EB-30, EB-23, EB-15, EB-15, EB-23, EB-30, EB-46
  },
  {// Rook
   // A     B     C     D     E     F     G     H
    ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3,
    ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3,
    ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3,
    ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3,
    ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3,
    ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3,
    ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3,
    ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3, ER-3
  },
  {// Queen
   // A      B      C      D      E      F      G      H
    EQ-61, EQ-40, EQ-30, EQ-20, EQ-20, EQ-30, EQ-40, EQ-61,
    EQ-40, EQ-20, EQ-10, EQ- 0, EQ- 0, EQ-10, EQ-20, EQ-40,
    EQ-30, EQ-10, EQ- 0, EQ+10, EQ+10, EQ- 0, EQ-10, EQ-30,
    EQ-20, EQ- 0, EQ+10, EQ+20, EQ+20, EQ+10, EQ- 0, EQ-20,
    EQ-20, EQ- 0, EQ+10, EQ+20, EQ+20, EQ+10, EQ- 0, EQ-20,
    EQ-30, EQ-10, EQ- 0, EQ+10, EQ+10, EQ- 0, EQ-10, EQ-30,
    EQ-40, EQ-20, EQ-10, EQ- 0, EQ- 0, EQ-10, EQ-20, EQ-40,
    EQ-61, EQ-40, EQ-30, EQ-20, EQ-20, EQ-30, EQ-40, EQ-61
  },
  {// King
   //A    B    C    D    E    F    G    H
     16,  78, 108, 139, 139, 108,  78,  16,
     78, 139, 170, 200, 200, 170, 139,  78,
    108, 170, 200, 230, 230, 200, 170, 108,
    139, 200, 230, 261, 261, 230, 200, 139,
    139, 200, 230, 261, 261, 230, 200, 139,
    108, 170, 200, 230, 230, 200, 170, 108,
     78, 139, 170, 200, 200, 170, 139,  78,
     16,  78, 108, 139, 139, 108,  78,  16
  }
};


#endif // !defined(PSQTAB_H_INCLUDED)
// ---- end psqtab.h ----


////
//// Variables
////

int Position::castleRightsMask[64];

Key Position::zobrist[2][8][64];
Key Position::zobEp[64];
Key Position::zobCastle[16];
Key Position::zobMaterial[2][8][16];
Key Position::zobSideToMove;

Value Position::MgPieceSquareTable[16][64];
Value Position::EgPieceSquareTable[16][64];


////
//// Functions
////

/// Constructors

Position::Position(const Position &pos) {
  copy(pos);
}

Position::Position(const std::string &fen) {
  from_fen(fen);
}


/// Position::from_fen() initializes the position object with the given FEN
/// string. This function is not very robust - make sure that input FENs are
/// correct (this is assumed to be the responsibility of the GUI).

void Position::from_fen(const std::string &fen) {

  static const std::string pieceLetters = "KQRBNPkqrbnp";
  static const Piece pieces[] = { WK, WQ, WR, WB, WN, WP, BK, BQ, BR, BB, BN, BP };

  clear();

  // Board
  Rank rank = RANK_8;
  File file = FILE_A;
  size_t i = 0;
  for ( ; fen[i] != ' '; i++)
  {
      if (isdigit(fen[i]))
      {
          // Skip the given number of files
          file += (fen[i] - '1' + 1);
          continue;
      }
      else if (fen[i] == '/')
      {
          file = FILE_A;
          rank--;
          continue;
      }
      size_t idx = pieceLetters.find(fen[i]);
      if (idx == std::string::npos)
      {
           std::cout << "Error in FEN at character " << i << std::endl;
           return;
      }
      Square square = make_square(file, rank);
      put_piece(pieces[idx], square);
      file++;
  }

  // Side to move
  i++;
  if (fen[i] != 'w' && fen[i] != 'b')
  {
      std::cout << "Error in FEN at character " << i << std::endl;
      return;
  }
  sideToMove = (fen[i] == 'w' ? WHITE : BLACK);

  // Castling rights:
  i++;
  if (fen[i] != ' ')
  {
      std::cout << "Error in FEN at character " << i << std::endl;
      return;
  }

  i++;
  while(strchr("KQkqabcdefghABCDEFGH-", fen[i])) {
    if(fen[i] == '-') {
      i++; break;
    }
    else if(fen[i] == 'K') allow_oo(WHITE);
    else if(fen[i] == 'Q') allow_ooo(WHITE);
    else if(fen[i] == 'k') allow_oo(BLACK);
    else if(fen[i] == 'q') allow_ooo(BLACK);
    else if(fen[i] >= 'A' && fen[i] <= 'H') {
      File rookFile, kingFile = FILE_NONE;
      for(Square square = SQ_B1; square <= SQ_G1; square++)
        if(piece_on(square) == WK)
          kingFile = square_file(square);
      if(kingFile == FILE_NONE) {
        std::cout << "Error in FEN at character " << i << std::endl;
        return;
      }
      initialKFile = kingFile;
      rookFile = File(fen[i] - 'A') + FILE_A;
      if(rookFile < initialKFile) {
        allow_ooo(WHITE);
        initialQRFile = rookFile;
      }
      else {
        allow_oo(WHITE);
        initialKRFile = rookFile;
      }
    }
    else if(fen[i] >= 'a' && fen[i] <= 'h') {
      File rookFile, kingFile = FILE_NONE;
      for(Square square = SQ_B8; square <= SQ_G8; square++)
        if(piece_on(square) == BK)
          kingFile = square_file(square);
      if(kingFile == FILE_NONE) {
        std::cout << "Error in FEN at character " << i << std::endl;
        return;
      }
      initialKFile = kingFile;
      rookFile = File(fen[i] - 'a') + FILE_A;
      if(rookFile < initialKFile) {
        allow_ooo(BLACK);
        initialQRFile = rookFile;
      }
      else {
        allow_oo(BLACK);
        initialKRFile = rookFile;
      }
    }
    else {
      std::cout << "Error in FEN at character " << i << std::endl;
      return;
    }
    i++;
  }

  // Skip blanks
  while (fen[i] == ' ')
      i++;

  // En passant square
  if (    i < fen.length() - 2
      && (fen[i] >= 'a' && fen[i] <= 'h')
      && (fen[i+1] == '3' || fen[i+1] == '6'))
      epSquare = square_from_string(fen.substr(i, 2));

  // Various initialisation
  for (Square sq = SQ_A1; sq <= SQ_H8; sq++)
      castleRightsMask[sq] = ALL_CASTLES;

  castleRightsMask[make_square(initialKFile,  RANK_1)] ^= (WHITE_OO|WHITE_OOO);
  castleRightsMask[make_square(initialKFile,  RANK_8)] ^= (BLACK_OO|BLACK_OOO);
  castleRightsMask[make_square(initialKRFile, RANK_1)] ^= WHITE_OO;
  castleRightsMask[make_square(initialKRFile, RANK_8)] ^= BLACK_OO;
  castleRightsMask[make_square(initialQRFile, RANK_1)] ^= WHITE_OOO;
  castleRightsMask[make_square(initialQRFile, RANK_8)] ^= BLACK_OOO;

  find_checkers();

  key = compute_key();
  pawnKey = compute_pawn_key();
  materialKey = compute_material_key();
  mgValue = compute_mg_value();
  egValue = compute_eg_value();
  npMaterial[WHITE] = compute_non_pawn_material(WHITE);
  npMaterial[BLACK] = compute_non_pawn_material(BLACK);
}


/// Position::to_fen() converts the position object to a FEN string. This is
/// probably only useful for debugging.

const std::string Position::to_fen() const {

  static const std::string pieceLetters = " PNBRQK  pnbrqk";
  std::string fen;
  int skip;

  for (Rank rank = RANK_8; rank >= RANK_1; rank--)
  {
      skip = 0;
      for (File file = FILE_A; file <= FILE_H; file++)
      {
          Square sq = make_square(file, rank);
          if (!square_is_occupied(sq))
          {   skip++;
              continue;
          }
          if (skip > 0)
          {
              fen += (char)skip + '0';
              skip = 0;
          }
          fen += pieceLetters[piece_on(sq)];
      }
      if (skip > 0)
          fen += (char)skip + '0';

      fen += (rank > RANK_1 ? '/' : ' ');
  }
  fen += (sideToMove == WHITE ? 'w' : 'b') + ' ';
  if (castleRights != NO_CASTLES)
  {
    if (can_castle_kingside(WHITE))  fen += 'K';
    if (can_castle_queenside(WHITE)) fen += 'Q';
    if (can_castle_kingside(BLACK))  fen += 'k';
    if (can_castle_queenside(BLACK)) fen += 'q';
  } else
      fen += '-';

  fen += ' ';
  if (ep_square() != SQ_NONE)
      fen += square_to_string(ep_square());
  else
      fen += '-';

  return fen;
}


/// Position::print() prints an ASCII representation of the position to
/// the standard output.

void Position::print() const {
  char pieceStrings[][8] =
    {"| ? ", "| P ", "| N ", "| B ", "| R ", "| Q ", "| K ", "| ? ",
     "| ? ", "|=P=", "|=N=", "|=B=", "|=R=", "|=Q=", "|=K="
    };

  for(Rank rank = RANK_8; rank >= RANK_1; rank--) {
    std::cout << "+---+---+---+---+---+---+---+---+\n";
    for(File file = FILE_A; file <= FILE_H; file++) {
      Square sq = make_square(file, rank);
      Piece piece = piece_on(sq);
      if(piece == EMPTY)
        std::cout << ((square_color(sq) == WHITE)? "|   " : "| . ");
      else
        std::cout << pieceStrings[piece];
    }
    std::cout << "|\n";
  }
  std::cout << "+---+---+---+---+---+---+---+---+\n";
  std::cout << to_fen() << std::endl;
  std::cout << key << std::endl;
}


/// Position::copy() creates a copy of the input position.

void Position::copy(const Position &pos) {

  memcpy(this, &pos, sizeof(Position));
}


/// Position:pinned_pieces() returns a bitboard of all pinned (against the
/// king) pieces for the given color.
Bitboard Position::pinned_pieces(Color c) const {

  Square ksq = king_square(c);
  return hidden_checks<ROOK, true>(c, ksq) | hidden_checks<BISHOP, true>(c, ksq);
}


/// Position:discovered_check_candidates() returns a bitboard containing all
/// pieces for the given side which are candidates for giving a discovered
/// check.  The code is almost the same as the function for finding pinned
/// pieces.

Bitboard Position::discovered_check_candidates(Color c) const {

  Square ksq = king_square(opposite_color(c));
  return hidden_checks<ROOK, false>(c, ksq) | hidden_checks<BISHOP, false>(c, ksq);
}


/// Position:hidden_checks<>() returns a bitboard of all pinned (against the
/// king) pieces for the given color and for the given pinner type. Or, when
/// template parameter FindPinned is false, the pinned pieces of opposite color
/// that are, indeed, the pieces candidate for a discovery check.
template<PieceType Piece, bool FindPinned>
Bitboard Position::hidden_checks(Color c, Square ksq) const {

  Square s;
  Bitboard sliders, result = EmptyBoardBB;

  if (Piece == ROOK) // Resolved at compile time
      sliders = rooks_and_queens(FindPinned ? opposite_color(c) : c) & RookPseudoAttacks[ksq];
  else
      sliders = bishops_and_queens(FindPinned ? opposite_color(c) : c) & BishopPseudoAttacks[ksq];

  if (sliders && (!FindPinned || (sliders & ~checkersBB)))
  {
       // King blockers are candidate pinned pieces
      Bitboard candidate_pinned = piece_attacks<Piece>(ksq) & pieces_of_color(c);

      // Pinners are sliders, not checkers, that give check when
      // candidate pinned are removed.
      Bitboard pinners = (FindPinned ? sliders & ~checkersBB : sliders);

      if (Piece == ROOK)
          pinners &= rook_attacks_bb(ksq, occupied_squares() ^ candidate_pinned);
      else
          pinners &= bishop_attacks_bb(ksq, occupied_squares() ^ candidate_pinned);

      // Finally for each pinner find the corresponding pinned piece (if same color of king)
      // or discovery checker (if opposite color) among the candidates.
      while (pinners)
      {
          s = pop_1st_bit(&pinners);
          result |= (squares_between(s, ksq) & candidate_pinned);
      }
  }
  return result;
}


/// Position::square_is_attacked() checks whether the given side attacks the
/// given square.

bool Position::square_is_attacked(Square s, Color c) const {

  return   (pawn_attacks(opposite_color(c), s) & pawns(c))
        || (piece_attacks<KNIGHT>(s) & knights(c))
        || (piece_attacks<KING>(s)   & kings(c))
        || (piece_attacks<ROOK>(s)   & rooks_and_queens(c))
        || (piece_attacks<BISHOP>(s) & bishops_and_queens(c));
}


/// Position::attacks_to() computes a bitboard containing all pieces which
/// attacks a given square. There are two versions of this function: One
/// which finds attackers of both colors, and one which only finds the
/// attackers for one side.

Bitboard Position::attacks_to(Square s) const {

  return  (pawn_attacks(BLACK, s)   & pawns(WHITE))
        | (pawn_attacks(WHITE, s)   & pawns(BLACK))
        | (piece_attacks<KNIGHT>(s) & pieces_of_type(KNIGHT))
        | (piece_attacks<ROOK>(s)   & rooks_and_queens())
        | (piece_attacks<BISHOP>(s) & bishops_and_queens())
        | (piece_attacks<KING>(s)   & pieces_of_type(KING));
}

Bitboard Position::attacks_to(Square s, Color c) const {

  return attacks_to(s) & pieces_of_color(c);
}


/// Position::piece_attacks_square() tests whether the piece on square f
/// attacks square t.

bool Position::piece_attacks_square(Square f, Square t) const {

  assert(square_is_ok(f));
  assert(square_is_ok(t));

  switch (piece_on(f))
  {
  case WP:          return pawn_attacks_square(WHITE, f, t);
  case BP:          return pawn_attacks_square(BLACK, f, t);
  case WN: case BN: return piece_attacks_square<KNIGHT>(f, t);
  case WB: case BB: return piece_attacks_square<BISHOP>(f, t);
  case WR: case BR: return piece_attacks_square<ROOK>(f, t);
  case WQ: case BQ: return piece_attacks_square<QUEEN>(f, t);
  case WK: case BK: return piece_attacks_square<KING>(f, t);
  default: break;
  }
  return false;
}


/// Position::move_attacks_square() tests whether a move from the current
/// position attacks a given square.  Only attacks by the moving piece are
/// considered; the function does not handle X-ray attacks.

bool Position::move_attacks_square(Move m, Square s) const {

  assert(move_is_ok(m));
  assert(square_is_ok(s));

  Square f = move_from(m), t = move_to(m);

  assert(square_is_occupied(f));

  switch (piece_on(f))
  {
  case WP:          return pawn_attacks_square(WHITE, t, s);
  case BP:          return pawn_attacks_square(BLACK, t, s);
  case WN: case BN: return piece_attacks_square<KNIGHT>(t, s);
  case WB: case BB: return piece_attacks_square<BISHOP>(t, s);
  case WR: case BR: return piece_attacks_square<ROOK>(t, s);
  case WQ: case BQ: return piece_attacks_square<QUEEN>(t, s);
  case WK: case BK: return piece_attacks_square<KING>(t, s);
  default: break;
  }
  return false;
}


/// Position::find_checkers() computes the checkersBB bitboard, which
/// contains a nonzero bit for each checking piece (0, 1 or 2).  It
/// currently works by calling Position::attacks_to, which is probably
/// inefficient. Consider rewriting this function to use the last move
/// played, like in non-bitboard versions of Glaurung.

void Position::find_checkers() {

  Color us = side_to_move();
  checkersBB = attacks_to(king_square(us), opposite_color(us));
}


/// Position::pl_move_is_legal() tests whether a pseudo-legal move is legal.
/// There are two versions of this function:  One which takes only a
/// move as input, and one which takes a move and a bitboard of pinned
/// pieces. The latter function is faster, and should always be preferred
/// when a pinned piece bitboard has already been computed.

bool Position::pl_move_is_legal(Move m)  const {

  return pl_move_is_legal(m, pinned_pieces(side_to_move()));
}

bool Position::pl_move_is_legal(Move m, Bitboard pinned) const {

  assert(is_ok());
  assert(move_is_ok(m));
  assert(pinned == pinned_pieces(side_to_move()));

  // If we're in check, all pseudo-legal moves are legal, because our
  // check evasion generator only generates true legal moves.
  if (is_check())
      return true;

  // Castling moves are checked for legality during move generation.
  if (move_is_castle(m))
      return true;

  Color us = side_to_move();
  Color them = opposite_color(us);
  Square from = move_from(m);
  Square ksq = king_square(us);

  assert(color_of_piece_on(from) == us);
  assert(piece_on(ksq) == king_of_color(us));

  // En passant captures are a tricky special case.  Because they are
  // rather uncommon, we do it simply by testing whether the king is attacked
  // after the move is made
  if (move_is_ep(m))
  {
      Square to = move_to(m);
      Square capsq = make_square(square_file(to), square_rank(from));
      Bitboard b = occupied_squares();

      assert(to == ep_square());
      assert(piece_on(from) == pawn_of_color(us));
      assert(piece_on(capsq) == pawn_of_color(them));
      assert(piece_on(to) == EMPTY);

      clear_bit(&b, from);
      clear_bit(&b, capsq);
      set_bit(&b, to);

      return   !(rook_attacks_bb(ksq, b) & rooks_and_queens(them))
            && !(bishop_attacks_bb(ksq, b) & bishops_and_queens(them));
  }

  // If the moving piece is a king, check whether the destination
  // square is attacked by the opponent.
  if (from == ksq)
      return !(square_is_attacked(move_to(m), them));

  // A non-king move is legal if and only if it is not pinned or it
  // is moving along the ray towards or away from the king.
  return (   !bit_is_set(pinned, from)
          || (direction_between_squares(from, ksq) == direction_between_squares(move_to(m), ksq)));
}


/// Position::move_is_check() tests whether a pseudo-legal move is a check.
/// There are two versions of this function:  One which takes only a move as
/// input, and one which takes a move and a bitboard of discovered check
/// candidates.  The latter function is faster, and should always be preferred
/// when a discovered check candidates bitboard has already been computed.

bool Position::move_is_check(Move m) const {

  Bitboard dc = discovered_check_candidates(side_to_move());
  return move_is_check(m, dc);
}

bool Position::move_is_check(Move m, Bitboard dcCandidates) const {

  assert(is_ok());
  assert(move_is_ok(m));
  assert(dcCandidates == discovered_check_candidates(side_to_move()));

  Color us = side_to_move();
  Color them = opposite_color(us);
  Square from = move_from(m);
  Square to = move_to(m);
  Square ksq = king_square(them);

  assert(color_of_piece_on(from) == us);
  assert(piece_on(ksq) == king_of_color(them));

  // Proceed according to the type of the moving piece
  switch (type_of_piece_on(from))
  {
  case PAWN:

      if (bit_is_set(pawn_attacks(them, ksq), to)) // Normal check?
          return true;

      if (    bit_is_set(dcCandidates, from)      // Discovered check?
          && (direction_between_squares(from, ksq) != direction_between_squares(to, ksq)))
          return true;

      if (move_promotion(m)) // Promotion with check?
      {
          Bitboard b = occupied_squares();
          clear_bit(&b, from);

          switch (move_promotion(m))
          {
          case KNIGHT:
              return bit_is_set(piece_attacks<KNIGHT>(to), ksq);
          case BISHOP:
              return bit_is_set(bishop_attacks_bb(to, b), ksq);
          case ROOK:
              return bit_is_set(rook_attacks_bb(to, b), ksq);
          case QUEEN:
              return bit_is_set(queen_attacks_bb(to, b), ksq);
          default:
              assert(false);
          }
      }
      // En passant capture with check?  We have already handled the case
      // of direct checks and ordinary discovered check, the only case we
      // need to handle is the unusual case of a discovered check through the
      // captured pawn.
      else if (move_is_ep(m))
      {
          Square capsq = make_square(square_file(to), square_rank(from));
          Bitboard b = occupied_squares();
          clear_bit(&b, from);
          clear_bit(&b, capsq);
          set_bit(&b, to);
          return  (rook_attacks_bb(ksq, b) & rooks_and_queens(us))
                ||(bishop_attacks_bb(ksq, b) & bishops_and_queens(us));
      }
      return false;

  case KNIGHT:
    return   bit_is_set(dcCandidates, from)              // Discovered check?
          || bit_is_set(piece_attacks<KNIGHT>(ksq), to); // Normal check?

  case BISHOP:
    return   bit_is_set(dcCandidates, from)              // Discovered check?
          || bit_is_set(piece_attacks<BISHOP>(ksq), to); // Normal check?

  case ROOK:
    return   bit_is_set(dcCandidates, from)              // Discovered check?
          || bit_is_set(piece_attacks<ROOK>(ksq), to);   // Normal check?

  case QUEEN:
      // Discovered checks are impossible!
      assert(!bit_is_set(dcCandidates, from));
      return bit_is_set(piece_attacks<QUEEN>(ksq), to);  // Normal check?

  case KING:
      // Discovered check?
      if (   bit_is_set(dcCandidates, from)
          && (direction_between_squares(from, ksq) != direction_between_squares(to, ksq)))
          return true;

      // Castling with check?
      if (move_is_castle(m))
      {
          Square kfrom, kto, rfrom, rto;
          Bitboard b = occupied_squares();
          kfrom = from;
          rfrom = to;

          if (rfrom > kfrom)
          {
              kto = relative_square(us, SQ_G1);
              rto = relative_square(us, SQ_F1);
          } else {
              kto = relative_square(us, SQ_C1);
              rto = relative_square(us, SQ_D1);
          }
          clear_bit(&b, kfrom);
          clear_bit(&b, rfrom);
          set_bit(&b, rto);
          set_bit(&b, kto);
          return bit_is_set(rook_attacks_bb(rto, b), ksq);
      }
      return false;

  default: // NO_PIECE_TYPE
      break;
  }
  assert(false);
  return false;
}


/// Position::move_is_capture() tests whether a move from the current
/// position is a capture.

bool Position::move_is_capture(Move m) const {

  return (   !square_is_empty(move_to(m))
          && (color_of_piece_on(move_to(m)) == opposite_color(side_to_move()))
         )
         || move_is_ep(m);
}


/// Position::backup() is called when making a move. All information
/// necessary to restore the position when the move is later unmade
/// is saved to an UndoInfo object. The function Position::restore
/// does the reverse operation:  When one does a backup followed by
/// a restore with the same UndoInfo object, the position is restored
/// to the state before backup was called.

void Position::backup(UndoInfo& u) const {

  u.castleRights = castleRights;
  u.epSquare     = epSquare;
  u.checkersBB   = checkersBB;
  u.key          = key;
  u.pawnKey      = pawnKey;
  u.materialKey  = materialKey;
  u.rule50       = rule50;
  u.lastMove     = lastMove;
  u.mgValue      = mgValue;
  u.egValue      = egValue;
  u.capture      = NO_PIECE_TYPE;
}


/// Position::restore() is called when unmaking a move.  It copies back
/// the information backed up during a previous call to Position::backup.

void Position::restore(const UndoInfo& u) {

  castleRights = u.castleRights;
  epSquare     = u.epSquare;
  checkersBB   = u.checkersBB;
  key          = u.key;
  pawnKey      = u.pawnKey;
  materialKey  = u.materialKey;
  rule50       = u.rule50;
  lastMove     = u.lastMove;
  mgValue     = u.mgValue;
  egValue     = u.egValue;
  // u.capture is restored in undo_move()
}

/// Position::do_move() makes a move, and backs up all information necessary
/// to undo the move to an UndoInfo object. The move is assumed to be legal.
/// Pseudo-legal moves should be filtered out before this function is called.
/// There are two versions of this function, one which takes only the move and
/// the UndoInfo as input, and one which takes a third parameter, a bitboard of
/// discovered check candidates. The second version is faster, because knowing
/// the discovered check candidates makes it easier to update the checkersBB
/// member variable in the position object.

void Position::do_move(Move m, UndoInfo& u) {

  do_move(m, u, discovered_check_candidates(side_to_move()));
}

void Position::do_move(Move m, UndoInfo& u, Bitboard dcCandidates) {

  assert(is_ok());
  assert(move_is_ok(m));

  // Back up the necessary information to our UndoInfo object (except the
  // captured piece, which is taken care of later.
  backup(u);

  // Save the current key to the history[] array, in order to be able to
  // detect repetition draws.
  history[gamePly] = key;

  // Increment the 50 moves rule draw counter. Resetting it to zero in the
  // case of non-reversible moves is taken care of later.
  rule50++;

  if (move_is_castle(m))
      do_castle_move(m);
  else if (move_promotion(m))
      do_promotion_move(m, u);
  else if (move_is_ep(m))
      do_ep_move(m);
  else
  {
    Color us = side_to_move();
    Color them = opposite_color(us);
    Square from = move_from(m);
    Square to = move_to(m);

    assert(color_of_piece_on(from) == us);
    assert(color_of_piece_on(to) == them || piece_on(to) == EMPTY);

    PieceType piece = type_of_piece_on(from);
    PieceType capture = type_of_piece_on(to);

    if (capture)
    {
      u.capture = capture;
      do_capture_move(m, capture, them, to);
    }

    // Move the piece
    clear_bit(&(byColorBB[us]), from);
    clear_bit(&(byTypeBB[piece]), from);
    clear_bit(&(byTypeBB[0]), from); // HACK: byTypeBB[0] == occupied squares
    set_bit(&(byColorBB[us]), to);
    set_bit(&(byTypeBB[piece]), to);
    set_bit(&(byTypeBB[0]), to); // HACK: byTypeBB[0] == occupied squares
    board[to] = board[from];
    board[from] = EMPTY;

    // Update hash key
    key ^= zobrist[us][piece][from] ^ zobrist[us][piece][to];

    // Update incremental scores
    mgValue -= mg_pst(us, piece, from);
    mgValue += mg_pst(us, piece, to);
    egValue -= eg_pst(us, piece, from);
    egValue += eg_pst(us, piece, to);

    // If the moving piece was a king, update the king square
    if (piece == KING)
        kingSquare[us] = to;

    // If the move was a double pawn push, set the en passant square.
    // This code is a bit ugly right now, and should be cleaned up later.
    // FIXME
    if (epSquare != SQ_NONE)
    {
        key ^= zobEp[epSquare];
        epSquare = SQ_NONE;
    }
    if (piece == PAWN)
    {
        if (abs(int(to) - int(from)) == 16)
        {
            if(   (   us == WHITE
                   && (pawn_attacks(WHITE, from + DELTA_N) & pawns(BLACK)))
               || (   us == BLACK
                   && (pawn_attacks(BLACK, from + DELTA_S) & pawns(WHITE))))
            {
                epSquare = Square((int(from) + int(to)) / 2);
                key ^= zobEp[epSquare];
            }
        }
        // Reset rule 50 draw counter
        rule50 = 0;

        // Update pawn hash key
        pawnKey ^= zobrist[us][PAWN][from] ^ zobrist[us][PAWN][to];
    }
    // Update piece lists
    pieceList[us][piece][index[from]] = to;
    index[to] = index[from];

    // Update castle rights
    key ^= zobCastle[castleRights];
    castleRights &= castleRightsMask[from];
    castleRights &= castleRightsMask[to];
    key ^= zobCastle[castleRights];

    // Update checkers bitboard
    checkersBB = EmptyBoardBB;
    Square ksq = king_square(them);
    switch (piece)
    {
    case PAWN:
        if (bit_is_set(pawn_attacks(them, ksq), to))
            set_bit(&checkersBB, to);

        if (bit_is_set(dcCandidates, from))
            checkersBB |= ( (piece_attacks<ROOK>(ksq) & rooks_and_queens(us))
                           |(piece_attacks<BISHOP>(ksq) & bishops_and_queens(us)));
        break;

    case KNIGHT:
        if (bit_is_set(piece_attacks<KNIGHT>(ksq), to))
            set_bit(&checkersBB, to);

        if (bit_is_set(dcCandidates, from))
            checkersBB |= ( (piece_attacks<ROOK>(ksq) & rooks_and_queens(us))
                           |(piece_attacks<BISHOP>(ksq) & bishops_and_queens(us)));
        break;

    case BISHOP:
        if  (bit_is_set(piece_attacks<BISHOP>(ksq), to))
            set_bit(&checkersBB, to);

        if (bit_is_set(dcCandidates, from))
            checkersBB |= (piece_attacks<ROOK>(ksq) & rooks_and_queens(us));
        break;

    case ROOK:
        if (bit_is_set(piece_attacks<ROOK>(ksq), to))
            set_bit(&checkersBB, to);

        if (bit_is_set(dcCandidates, from))
            checkersBB |= (piece_attacks<BISHOP>(ksq) & bishops_and_queens(us));
        break;

    case QUEEN:
        if (bit_is_set(piece_attacks<QUEEN>(ksq), to))
            set_bit(&checkersBB, to);
        break;

    case KING:
        if (bit_is_set(dcCandidates, from))
            checkersBB |= ( (piece_attacks<ROOK>(ksq) & rooks_and_queens(us))
                           |(piece_attacks<BISHOP>(ksq) & bishops_and_queens(us)));
        break;

    default:
      assert(false);
      break;
    }
  }

  // Finish
  key ^= zobSideToMove;
  sideToMove = opposite_color(sideToMove);
  gamePly++;

  mgValue += (sideToMove == WHITE)? TempoValueMidgame : -TempoValueMidgame;
  egValue += (sideToMove == WHITE)? TempoValueEndgame : -TempoValueEndgame;

  assert(is_ok());
}


/// Position::do_capture_move() is a private method used to update captured
/// piece info. It is called from the main Position::do_move function.

void Position::do_capture_move(Move m, PieceType capture, Color them, Square to) {

    assert(capture != KING);

    // Remove captured piece
    clear_bit(&(byColorBB[them]), to);
    clear_bit(&(byTypeBB[capture]), to);

    // Update hash key
    key ^= zobrist[them][capture][to];

    // If the captured piece was a pawn, update pawn hash key
    if (capture == PAWN)
        pawnKey ^= zobrist[them][PAWN][to];

    // Update incremental scores
    mgValue -= mg_pst(them, capture, to);
    egValue -= eg_pst(them, capture, to);

    assert(!move_promotion(m) || capture != PAWN);

    // Update material
    if (capture != PAWN)
        npMaterial[them] -= piece_value_midgame(capture);

    // Update material hash key
    materialKey ^= zobMaterial[them][capture][pieceCount[them][capture]];

    // Update piece count
    pieceCount[them][capture]--;

    // Update piece list
    pieceList[them][capture][index[to]] = pieceList[them][capture][pieceCount[them][capture]];
    index[pieceList[them][capture][index[to]]] = index[to];

    // Reset rule 50 counter
    rule50 = 0;
}


/// Position::do_castle_move() is a private method used to make a castling
/// move. It is called from the main Position::do_move function. Note that
/// castling moves are encoded as "king captures friendly rook" moves, for
/// instance white short castling in a non-Chess960 game is encoded as e1h1.

void Position::do_castle_move(Move m) {

  assert(is_ok());
  assert(move_is_ok(m));
  assert(move_is_castle(m));

  Color us = side_to_move();
  Color them = opposite_color(us);

  // Find source squares for king and rook
  Square kfrom = move_from(m);
  Square rfrom = move_to(m);  // HACK: See comment at beginning of function
  Square kto, rto;

  assert(piece_on(kfrom) == king_of_color(us));
  assert(piece_on(rfrom) == rook_of_color(us));

  // Find destination squares for king and rook
  if (rfrom > kfrom) // O-O
  {
      kto = relative_square(us, SQ_G1);
      rto = relative_square(us, SQ_F1);
  } else { // O-O-O
      kto = relative_square(us, SQ_C1);
      rto = relative_square(us, SQ_D1);
  }

  // Remove pieces from source squares
  clear_bit(&(byColorBB[us]), kfrom);
  clear_bit(&(byTypeBB[KING]), kfrom);
  clear_bit(&(byTypeBB[0]), kfrom); // HACK: byTypeBB[0] == occupied squares
  clear_bit(&(byColorBB[us]), rfrom);
  clear_bit(&(byTypeBB[ROOK]), rfrom);
  clear_bit(&(byTypeBB[0]), rfrom); // HACK: byTypeBB[0] == occupied squares

  // Put pieces on destination squares
  set_bit(&(byColorBB[us]), kto);
  set_bit(&(byTypeBB[KING]), kto);
  set_bit(&(byTypeBB[0]), kto); // HACK: byTypeBB[0] == occupied squares
  set_bit(&(byColorBB[us]), rto);
  set_bit(&(byTypeBB[ROOK]), rto);
  set_bit(&(byTypeBB[0]), rto); // HACK: byTypeBB[0] == occupied squares

  // Update board array
  board[kfrom] = board[rfrom] = EMPTY;
  board[kto] = king_of_color(us);
  board[rto] = rook_of_color(us);

  // Update king square
  kingSquare[us] = kto;

  // Update piece lists
  pieceList[us][KING][index[kfrom]] = kto;
  pieceList[us][ROOK][index[rfrom]] = rto;
  int tmp = index[rfrom];
  index[kto] = index[kfrom];
  index[rto] = tmp;

  // Update incremental scores
  mgValue -= mg_pst(us, KING, kfrom);
  mgValue += mg_pst(us, KING, kto);
  egValue -= eg_pst(us, KING, kfrom);
  egValue += eg_pst(us, KING, kto);
  mgValue -= mg_pst(us, ROOK, rfrom);
  mgValue += mg_pst(us, ROOK, rto);
  egValue -= eg_pst(us, ROOK, rfrom);
  egValue += eg_pst(us, ROOK, rto);

  // Update hash key
  key ^= zobrist[us][KING][kfrom] ^ zobrist[us][KING][kto];
  key ^= zobrist[us][ROOK][rfrom] ^ zobrist[us][ROOK][rto];

  // Clear en passant square
  if(epSquare != SQ_NONE)
  {
      key ^= zobEp[epSquare];
      epSquare = SQ_NONE;
  }

  // Update castling rights
  key ^= zobCastle[castleRights];
  castleRights &= castleRightsMask[kfrom];
  key ^= zobCastle[castleRights];

  // Reset rule 50 counter
  rule50 = 0;

  // Update checkers BB
  checkersBB = attacks_to(king_square(them), us);
}


/// Position::do_promotion_move() is a private method used to make a promotion
/// move. It is called from the main Position::do_move function. The
/// UndoInfo object, which has been initialized in Position::do_move, is
/// used to store the captured piece (if any).

void Position::do_promotion_move(Move m, UndoInfo &u) {

  Color us, them;
  Square from, to;
  PieceType capture, promotion;

  assert(is_ok());
  assert(move_is_ok(m));
  assert(move_promotion(m));

  us = side_to_move();
  them = opposite_color(us);
  from = move_from(m);
  to = move_to(m);

  assert(relative_rank(us, to) == RANK_8);
  assert(piece_on(from) == pawn_of_color(us));
  assert(color_of_piece_on(to) == them || square_is_empty(to));

  capture = type_of_piece_on(to);

  if (capture)
  {
    u.capture = capture;
    do_capture_move(m, capture, them, to);
  }

  // Remove pawn
  clear_bit(&(byColorBB[us]), from);
  clear_bit(&(byTypeBB[PAWN]), from);
  clear_bit(&(byTypeBB[0]), from); // HACK: byTypeBB[0] == occupied squares
  board[from] = EMPTY;

  // Insert promoted piece
  promotion = move_promotion(m);
  assert(promotion >= KNIGHT && promotion <= QUEEN);
  set_bit(&(byColorBB[us]), to);
  set_bit(&(byTypeBB[promotion]), to);
  set_bit(&(byTypeBB[0]), to); // HACK: byTypeBB[0] == occupied squares
  board[to] = piece_of_color_and_type(us, promotion);

  // Update hash key
  key ^= zobrist[us][PAWN][from] ^ zobrist[us][promotion][to];

  // Update pawn hash key
  pawnKey ^= zobrist[us][PAWN][from];

  // Update material key
  materialKey ^= zobMaterial[us][PAWN][pieceCount[us][PAWN]];
  materialKey ^= zobMaterial[us][promotion][pieceCount[us][promotion]+1];

  // Update piece counts
  pieceCount[us][PAWN]--;
  pieceCount[us][promotion]++;

  // Update piece lists
  pieceList[us][PAWN][index[from]] = pieceList[us][PAWN][pieceCount[us][PAWN]];
  index[pieceList[us][PAWN][index[from]]] = index[from];
  pieceList[us][promotion][pieceCount[us][promotion] - 1] = to;
  index[to] = pieceCount[us][promotion] - 1;

  // Update incremental scores
  mgValue -= mg_pst(us, PAWN, from);
  mgValue += mg_pst(us, promotion, to);
  egValue -= eg_pst(us, PAWN, from);
  egValue += eg_pst(us, promotion, to);

  // Update material
  npMaterial[us] += piece_value_midgame(promotion);

  // Clear the en passant square
  if (epSquare != SQ_NONE)
  {
      key ^= zobEp[epSquare];
      epSquare = SQ_NONE;
  }

  // Update castle rights
  key ^= zobCastle[castleRights];
  castleRights &= castleRightsMask[to];
  key ^= zobCastle[castleRights];

  // Reset rule 50 counter
  rule50 = 0;

  // Update checkers BB
  checkersBB = attacks_to(king_square(them), us);
}


/// Position::do_ep_move() is a private method used to make an en passant
/// capture. It is called from the main Position::do_move function. Because
/// the captured piece is always a pawn, we don't need to pass an UndoInfo
/// object in which to store the captured piece.

void Position::do_ep_move(Move m) {

  Color us, them;
  Square from, to, capsq;

  assert(is_ok());
  assert(move_is_ok(m));
  assert(move_is_ep(m));

  us = side_to_move();
  them = opposite_color(us);
  from = move_from(m);
  to = move_to(m);
  capsq = (us == WHITE)? (to - DELTA_N) : (to - DELTA_S);

  assert(to == epSquare);
  assert(relative_rank(us, to) == RANK_6);
  assert(piece_on(to) == EMPTY);
  assert(piece_on(from) == pawn_of_color(us));
  assert(piece_on(capsq) == pawn_of_color(them));

  // Remove captured piece
  clear_bit(&(byColorBB[them]), capsq);
  clear_bit(&(byTypeBB[PAWN]), capsq);
  clear_bit(&(byTypeBB[0]), capsq); // HACK: byTypeBB[0] == occupied squares
  board[capsq] = EMPTY;

  // Remove moving piece from source square
  clear_bit(&(byColorBB[us]), from);
  clear_bit(&(byTypeBB[PAWN]), from);
  clear_bit(&(byTypeBB[0]), from); // HACK: byTypeBB[0] == occupied squares

  // Put moving piece on destination square
  set_bit(&(byColorBB[us]), to);
  set_bit(&(byTypeBB[PAWN]), to);
  set_bit(&(byTypeBB[0]), to); // HACK: byTypeBB[0] == occupied squares
  board[to] = board[from];
  board[from] = EMPTY;

  // Update material hash key
  materialKey ^= zobMaterial[them][PAWN][pieceCount[them][PAWN]];

  // Update piece count
  pieceCount[them][PAWN]--;

  // Update piece list
  pieceList[us][PAWN][index[from]] = to;
  index[to] = index[from];
  pieceList[them][PAWN][index[capsq]] = pieceList[them][PAWN][pieceCount[them][PAWN]];
  index[pieceList[them][PAWN][index[capsq]]] = index[capsq];

  // Update hash key
  key ^= zobrist[us][PAWN][from] ^ zobrist[us][PAWN][to];
  key ^= zobrist[them][PAWN][capsq];
  key ^= zobEp[epSquare];

  // Update pawn hash key
  pawnKey ^= zobrist[us][PAWN][from] ^ zobrist[us][PAWN][to];
  pawnKey ^= zobrist[them][PAWN][capsq];

  // Update incremental scores
  mgValue -= mg_pst(them, PAWN, capsq);
  mgValue -= mg_pst(us, PAWN, from);
  mgValue += mg_pst(us, PAWN, to);
  egValue -= eg_pst(them, PAWN, capsq);
  egValue -= eg_pst(us, PAWN, from);
  egValue += eg_pst(us, PAWN, to);

  // Reset en passant square
  epSquare = SQ_NONE;

  // Reset rule 50 counter
  rule50 = 0;

  // Update checkers BB
  checkersBB = attacks_to(king_square(them), us);
}


/// Position::undo_move() unmakes a move.  When it returns, the position should
/// be restored to exactly the same state as before the move was made.  It is
/// important that Position::undo_move is called with the same move and UndoInfo
/// object as the earlier call to Position::do_move.

void Position::undo_move(Move m, const UndoInfo &u) {

  assert(is_ok());
  assert(move_is_ok(m));

  gamePly--;
  sideToMove = opposite_color(sideToMove);

  // Restore information from our UndoInfo object (except the captured piece,
  // which is taken care of later)
  restore(u);

  if (move_is_castle(m))
      undo_castle_move(m);
  else if (move_promotion(m))
      undo_promotion_move(m, u);
  else if (move_is_ep(m))
      undo_ep_move(m);
  else
  {
      Color us, them;
      Square from, to;
      PieceType piece, capture;

      us = side_to_move();
      them = opposite_color(us);
      from = move_from(m);
      to = move_to(m);

      assert(piece_on(from) == EMPTY);
      assert(color_of_piece_on(to) == us);

      // Put the piece back at the source square
      piece = type_of_piece_on(to);
      set_bit(&(byColorBB[us]), from);
      set_bit(&(byTypeBB[piece]), from);
      set_bit(&(byTypeBB[0]), from); // HACK: byTypeBB[0] == occupied squares
      board[from] = piece_of_color_and_type(us, piece);

      // Clear the destination square
      clear_bit(&(byColorBB[us]), to);
      clear_bit(&(byTypeBB[piece]), to);
      clear_bit(&(byTypeBB[0]), to); // HACK: byTypeBB[0] == occupied squares

      // If the moving piece was a king, update the king square
      if (piece == KING)
          kingSquare[us] = from;

      // Update piece list
      pieceList[us][piece][index[to]] = from;
      index[from] = index[to];

      capture = u.capture;

      if (capture)
      {
          assert(capture != KING);

          // Replace the captured piece
          set_bit(&(byColorBB[them]), to);
          set_bit(&(byTypeBB[capture]), to);
          set_bit(&(byTypeBB[0]), to);
          board[to] = piece_of_color_and_type(them, capture);

          // Update material
          if (capture != PAWN)
              npMaterial[them] += piece_value_midgame(capture);

          // Update piece list
          pieceList[them][capture][pieceCount[them][capture]] = to;
          index[to] = pieceCount[them][capture];

          // Update piece count
          pieceCount[them][capture]++;
      } else
          board[to] = EMPTY;
  }

  assert(is_ok());
}


/// Position::undo_castle_move() is a private method used to unmake a castling
/// move. It is called from the main Position::undo_move function. Note that
/// castling moves are encoded as "king captures friendly rook" moves, for
/// instance white short castling in a non-Chess960 game is encoded as e1h1.

void Position::undo_castle_move(Move m) {

  assert(move_is_ok(m));
  assert(move_is_castle(m));

  // When we have arrived here, some work has already been done by
  // Position::undo_move.  In particular, the side to move has been switched,
  // so the code below is correct.
  Color us = side_to_move();

  // Find source squares for king and rook
  Square kfrom = move_from(m);
  Square rfrom = move_to(m);  // HACK: See comment at beginning of function
  Square kto, rto;

  // Find destination squares for king and rook
  if (rfrom > kfrom) // O-O
  {
      kto = relative_square(us, SQ_G1);
      rto = relative_square(us, SQ_F1);
  } else { // O-O-O
      kto = relative_square(us, SQ_C1);
      rto = relative_square(us, SQ_D1);
  }

  assert(piece_on(kto) == king_of_color(us));
  assert(piece_on(rto) == rook_of_color(us));

  // Remove pieces from destination squares
  clear_bit(&(byColorBB[us]), kto);
  clear_bit(&(byTypeBB[KING]), kto);
  clear_bit(&(byTypeBB[0]), kto); // HACK: byTypeBB[0] == occupied squares
  clear_bit(&(byColorBB[us]), rto);
  clear_bit(&(byTypeBB[ROOK]), rto);
  clear_bit(&(byTypeBB[0]), rto); // HACK: byTypeBB[0] == occupied squares

  // Put pieces on source squares
  set_bit(&(byColorBB[us]), kfrom);
  set_bit(&(byTypeBB[KING]), kfrom);
  set_bit(&(byTypeBB[0]), kfrom); // HACK: byTypeBB[0] == occupied squares
  set_bit(&(byColorBB[us]), rfrom);
  set_bit(&(byTypeBB[ROOK]), rfrom);
  set_bit(&(byTypeBB[0]), rfrom); // HACK: byTypeBB[0] == occupied squares

  // Update board
  board[rto] = board[kto] = EMPTY;
  board[rfrom] = rook_of_color(us);
  board[kfrom] = king_of_color(us);

  // Update king square
  kingSquare[us] = kfrom;

  // Update piece lists
  pieceList[us][KING][index[kto]] = kfrom;
  pieceList[us][ROOK][index[rto]] = rfrom;
  int tmp = index[rto];  // Necessary because we may have rto == kfrom in FRC.
  index[kfrom] = index[kto];
  index[rfrom] = tmp;
}


/// Position::undo_promotion_move() is a private method used to unmake a
/// promotion move. It is called from the main Position::do_move
/// function. The UndoInfo object, which has been initialized in
/// Position::do_move, is used to put back the captured piece (if any).

void Position::undo_promotion_move(Move m, const UndoInfo &u) {

  Color us, them;
  Square from, to;
  PieceType capture, promotion;

  assert(move_is_ok(m));
  assert(move_promotion(m));

  // When we have arrived here, some work has already been done by
  // Position::undo_move.  In particular, the side to move has been switched,
  // so the code below is correct.
  us = side_to_move();
  them = opposite_color(us);
  from = move_from(m);
  to = move_to(m);

  assert(relative_rank(us, to) == RANK_8);
  assert(piece_on(from) == EMPTY);

  // Remove promoted piece
  promotion = move_promotion(m);
  assert(piece_on(to)==piece_of_color_and_type(us, promotion));
  assert(promotion >= KNIGHT && promotion <= QUEEN);
  clear_bit(&(byColorBB[us]), to);
  clear_bit(&(byTypeBB[promotion]), to);
  clear_bit(&(byTypeBB[0]), to); // HACK: byTypeBB[0] == occupied squares

  // Insert pawn at source square
  set_bit(&(byColorBB[us]), from);
  set_bit(&(byTypeBB[PAWN]), from);
  set_bit(&(byTypeBB[0]), from); // HACK: byTypeBB[0] == occupied squares
  board[from] = pawn_of_color(us);

  // Update material
  npMaterial[us] -= piece_value_midgame(promotion);

  // Update piece list
  pieceList[us][PAWN][pieceCount[us][PAWN]] = from;
  index[from] = pieceCount[us][PAWN];
  pieceList[us][promotion][index[to]] =
    pieceList[us][promotion][pieceCount[us][promotion] - 1];
  index[pieceList[us][promotion][index[to]]] = index[to];

  // Update piece counts
  pieceCount[us][promotion]--;
  pieceCount[us][PAWN]++;

  capture = u.capture;

  if (capture)
  {
      assert(capture != KING);

      // Insert captured piece:
      set_bit(&(byColorBB[them]), to);
      set_bit(&(byTypeBB[capture]), to);
      set_bit(&(byTypeBB[0]), to); // HACK: byTypeBB[0] == occupied squares
      board[to] = piece_of_color_and_type(them, capture);

      // Update material. Because the move is a promotion move, we know
      // that the captured piece cannot be a pawn.
      assert(capture != PAWN);
      npMaterial[them] += piece_value_midgame(capture);

      // Update piece list
      pieceList[them][capture][pieceCount[them][capture]] = to;
      index[to] = pieceCount[them][capture];

      // Update piece count
      pieceCount[them][capture]++;
  } else
      board[to] = EMPTY;
}


/// Position::undo_ep_move() is a private method used to unmake an en passant
/// capture. It is called from the main Position::undo_move function.  Because
/// the captured piece is always a pawn, we don't need to pass an UndoInfo
/// object from which to retrieve the captured piece.

void Position::undo_ep_move(Move m) {

  assert(move_is_ok(m));
  assert(move_is_ep(m));

  // When we have arrived here, some work has already been done by
  // Position::undo_move. In particular, the side to move has been switched,
  // so the code below is correct.
  Color us = side_to_move();
  Color them = opposite_color(us);
  Square from = move_from(m);
  Square to = move_to(m);
  Square capsq = (us == WHITE)? (to - DELTA_N) : (to - DELTA_S);

  assert(to == ep_square());
  assert(relative_rank(us, to) == RANK_6);
  assert(piece_on(to) == pawn_of_color(us));
  assert(piece_on(from) == EMPTY);
  assert(piece_on(capsq) == EMPTY);

  // Replace captured piece
  set_bit(&(byColorBB[them]), capsq);
  set_bit(&(byTypeBB[PAWN]), capsq);
  set_bit(&(byTypeBB[0]), capsq);
  board[capsq] = pawn_of_color(them);

  // Remove moving piece from destination square
  clear_bit(&(byColorBB[us]), to);
  clear_bit(&(byTypeBB[PAWN]), to);
  clear_bit(&(byTypeBB[0]), to);
  board[to] = EMPTY;

  // Replace moving piece at source square
  set_bit(&(byColorBB[us]), from);
  set_bit(&(byTypeBB[PAWN]), from);
  set_bit(&(byTypeBB[0]), from);
  board[from] = pawn_of_color(us);

  // Update piece list:
  pieceList[us][PAWN][index[to]] = from;
  index[from] = index[to];
  pieceList[them][PAWN][pieceCount[them][PAWN]] = capsq;
  index[capsq] = pieceCount[them][PAWN];

  // Update piece count:
  pieceCount[them][PAWN]++;
}


/// Position::do_null_move makes() a "null move": It switches the side to move
/// and updates the hash key without executing any move on the board.

void Position::do_null_move(UndoInfo &u) {

  assert(is_ok());
  assert(!is_check());

  // Back up the information necessary to undo the null move to the supplied
  // UndoInfo object.  In the case of a null move, the only thing we need to
  // remember is the last move made and the en passant square.
  u.lastMove = lastMove;
  u.epSquare = epSquare;

  // Save the current key to the history[] array, in order to be able to
  // detect repetition draws.
  history[gamePly] = key;

  // Update the necessary information
  sideToMove = opposite_color(sideToMove);
  if (epSquare != SQ_NONE)
      key ^= zobEp[epSquare];

  epSquare = SQ_NONE;
  rule50++;
  gamePly++;
  key ^= zobSideToMove;

  mgValue += (sideToMove == WHITE)? TempoValueMidgame : -TempoValueMidgame;
  egValue += (sideToMove == WHITE)? TempoValueEndgame : -TempoValueEndgame;

  assert(is_ok());
}


/// Position::undo_null_move() unmakes a "null move".

void Position::undo_null_move(const UndoInfo &u) {

  assert(is_ok());
  assert(!is_check());

  // Restore information from the supplied UndoInfo object:
  lastMove = u.lastMove;
  epSquare = u.epSquare;
  if (epSquare != SQ_NONE)
      key ^= zobEp[epSquare];

  // Update the necessary information.
  sideToMove = opposite_color(sideToMove);
  rule50--;
  gamePly--;
  key ^= zobSideToMove;

  mgValue += (sideToMove == WHITE)? TempoValueMidgame : -TempoValueMidgame;
  egValue += (sideToMove == WHITE)? TempoValueEndgame : -TempoValueEndgame;

  assert(is_ok());
}


/// Position::see() is a static exchange evaluator:  It tries to estimate the
/// material gain or loss resulting from a move.  There are two versions of
/// this function: One which takes a move as input, and one which takes a
/// 'from' and a 'to' square.  The function does not yet understand promotions
/// or en passant captures.

int Position::see(Move m) const {

  assert(move_is_ok(m));
  return see(move_from(m), move_to(m));
}

int Position::see(Square from, Square to) const {

  // Approximate material values, with pawn = 1
  static const int seeValues[18] = {
    0, 1, 3, 3, 5, 10, 100, 0, 0, 1, 3, 3, 5, 10, 100, 0, 0, 0
  };

  Bitboard attackers, occ, b;

  assert(square_is_ok(from));
  assert(square_is_ok(to));

  // Initialize colors
  Color us = color_of_piece_on(from);
  Color them = opposite_color(us);

  // Initialize pieces
  Piece piece = piece_on(from);
  Piece capture = piece_on(to);

  // Find all attackers to the destination square, with the moving piece
  // removed, but possibly an X-ray attacker added behind it.
  occ = occupied_squares();
  clear_bit(&occ, from);
  attackers =  (rook_attacks_bb(to, occ)   & rooks_and_queens())
             | (bishop_attacks_bb(to, occ) & bishops_and_queens())
             | (piece_attacks<KNIGHT>(to)  & knights())
             | (piece_attacks<KING>(to)    & kings())
             | (pawn_attacks(WHITE, to)    & pawns(BLACK))
             | (pawn_attacks(BLACK, to)    & pawns(WHITE));

  // If the opponent has no attackers, we are finished
  if ((attackers & pieces_of_color(them)) == EmptyBoardBB)
      return seeValues[capture];

  attackers &= occ; // Remove the moving piece

  // The destination square is defended, which makes things rather more
  // difficult to compute. We proceed by building up a "swap list" containing
  // the material gain or loss at each stop in a sequence of captures to the
  // destination square, where the sides alternately capture, and always
  // capture with the least valuable piece. After each capture, we look for
  // new X-ray attacks from behind the capturing piece.
  int lastCapturingPieceValue = seeValues[piece];
  int swapList[32], n = 1;
  Color c = them;
  PieceType pt;

  swapList[0] = seeValues[capture];

  do {
      // Locate the least valuable attacker for the side to move.  The loop
      // below looks like it is potentially infinite, but it isn't. We know
      // that the side to move still has at least one attacker left.
      for (pt = PAWN; !(attackers & pieces_of_color_and_type(c, pt)); pt++)
          assert(pt < KING);

      // Remove the attacker we just found from the 'attackers' bitboard,
      // and scan for new X-ray attacks behind the attacker.
      b = attackers & pieces_of_color_and_type(c, pt);
      occ ^= (b & -b);
      attackers |=  (rook_attacks_bb(to, occ) & rooks_and_queens())
                  | (bishop_attacks_bb(to, occ) & bishops_and_queens());

      attackers &= occ;

      // Add the new entry to the swap list
      assert(n < 32);
      swapList[n] = -swapList[n - 1] + lastCapturingPieceValue;
      n++;

      // Remember the value of the capturing piece, and change the side to move
      // before beginning the next iteration
      lastCapturingPieceValue = seeValues[pt];
      c = opposite_color(c);

      // Stop after a king capture
      if (pt == KING && (attackers & pieces_of_color(c)))
      {
          assert(n < 32);
          swapList[n++] = 100;
          break;
      }
  } while (attackers & pieces_of_color(c));

  // Having built the swap list, we negamax through it to find the best
  // achievable score from the point of view of the side to move
  while (--n)
      swapList[n-1] = Min(-swapList[n], swapList[n-1]);

  return swapList[0];
}


/// Position::clear() erases the position object to a pristine state, with an
/// empty board, white to move, and no castling rights.

void Position::clear() {

  for (int i = 0; i < 64; i++)
  {
      board[i] = EMPTY;
      index[i] = 0;
  }

  for (int i = 0; i < 2; i++)
      byColorBB[i] = EmptyBoardBB;

  for (int i = 0; i < 7; i++)
  {
      byTypeBB[i] = EmptyBoardBB;
      pieceCount[0][i] = pieceCount[1][i] = 0;
      for (int j = 0; j < 8; j++)
          pieceList[0][i][j] = pieceList[1][i][j] = SQ_NONE;
  }

  checkersBB = EmptyBoardBB;

  lastMove = MOVE_NONE;

  sideToMove = WHITE;
  castleRights = NO_CASTLES;
  initialKFile = FILE_E;
  initialKRFile = FILE_H;
  initialQRFile = FILE_A;
  epSquare = SQ_NONE;
  rule50 = 0;
  gamePly = 0;
}


/// Position::reset_game_ply() simply sets gamePly to 0.  It is used from the
/// UCI interface code, whenever a non-reversible move is made in a
/// 'position fen <fen> moves m1 m2 ...' command.  This makes it possible
/// for the program to handle games of arbitrary length, as long as the GUI
/// handles draws by the 50 move rule correctly.

void Position::reset_game_ply() {

  gamePly = 0;
}


/// Position::put_piece() puts a piece on the given square of the board,
/// updating the board array, bitboards, and piece counts.

void Position::put_piece(Piece p, Square s) {

  Color c = color_of_piece(p);
  PieceType pt = type_of_piece(p);

  board[s] = p;
  index[s] = pieceCount[c][pt];
  pieceList[c][pt][index[s]] = s;

  set_bit(&(byTypeBB[pt]), s);
  set_bit(&(byColorBB[c]), s);
  set_bit(&byTypeBB[0], s); // HACK: byTypeBB[0] contains all occupied squares.

  pieceCount[c][pt]++;

  if (pt == KING)
      kingSquare[c] = s;
}


/// Position::allow_oo() gives the given side the right to castle kingside.
/// Used when setting castling rights during parsing of FEN strings.

void Position::allow_oo(Color c) {

  castleRights |= (1 + int(c));
}


/// Position::allow_ooo() gives the given side the right to castle queenside.
/// Used when setting castling rights during parsing of FEN strings.

void Position::allow_ooo(Color c) {

  castleRights |= (4 + 4*int(c));
}


/// Position::compute_key() computes the hash key of the position. The hash
/// key is usually updated incrementally as moves are made and unmade, the
/// compute_key() function is only used when a new position is set up, and
/// to verify the correctness of the hash key when running in debug mode.

Key Position::compute_key() const {

  Key result = Key(0ULL);

  for (Square s = SQ_A1; s <= SQ_H8; s++)
      if (square_is_occupied(s))
          result ^= zobrist[color_of_piece_on(s)][type_of_piece_on(s)][s];

  if (ep_square() != SQ_NONE)
      result ^= zobEp[ep_square()];

  result ^= zobCastle[castleRights];
  if (side_to_move() == BLACK)
      result ^= zobSideToMove;

  return result;
}


/// Position::compute_pawn_key() computes the hash key of the position.  The
/// hash key is usually updated incrementally as moves are made and unmade,
/// the compute_pawn_key() function is only used when a new position is set
/// up, and to verify the correctness of the pawn hash key when running in
/// debug mode.

Key Position::compute_pawn_key() const {

  Key result = Key(0ULL);
  Bitboard b;
  Square s;

  for (Color c = WHITE; c <= BLACK; c++)
  {
      b = pawns(c);
      while(b)
      {
          s = pop_1st_bit(&b);
          result ^= zobrist[c][PAWN][s];
      }
  }
  return result;
}


/// Position::compute_material_key() computes the hash key of the position.
/// The hash key is usually updated incrementally as moves are made and unmade,
/// the compute_material_key() function is only used when a new position is set
/// up, and to verify the correctness of the material hash key when running in
/// debug mode.

Key Position::compute_material_key() const {

  Key result = Key(0ULL);
  for (Color c = WHITE; c <= BLACK; c++)
      for (PieceType pt = PAWN; pt <= QUEEN; pt++)
      {
          int count = piece_count(c, pt);
          for (int i = 0; i <= count; i++)
              result ^= zobMaterial[c][pt][i];
      }
  return result;
}


/// Position::compute_mg_value() and Position::compute_eg_value() compute the
/// incremental scores for the middle game and the endgame.  These functions
/// are used to initialize the incremental scores when a new position is set
/// up, and to verify that the scores are correctly updated by do_move
/// and undo_move when the program is running in debug mode.

Value Position::compute_mg_value() const {

  Value result = Value(0);
  Bitboard b;
  Square s;

  for (Color c = WHITE; c <= BLACK; c++)
      for (PieceType pt = PAWN; pt <= KING; pt++)
      {
          b = pieces_of_color_and_type(c, pt);
          while(b)
          {
              s = pop_1st_bit(&b);
              assert(piece_on(s) == piece_of_color_and_type(c, pt));
              result += mg_pst(c, pt, s);
          }
      }
  result += (side_to_move() == WHITE)? TempoValueMidgame / 2 : -TempoValueMidgame / 2;
  return result;
}

Value Position::compute_eg_value() const {

  Value result = Value(0);
  Bitboard b;
  Square s;

  for (Color c = WHITE; c <= BLACK; c++)
    for (PieceType pt = PAWN; pt <= KING; pt++)
    {
        b = pieces_of_color_and_type(c, pt);
        while(b)
        {
            s = pop_1st_bit(&b);
            assert(piece_on(s) == piece_of_color_and_type(c, pt));
            result += eg_pst(c, pt, s);
        }
    }
  result += (side_to_move() == WHITE)? TempoValueEndgame / 2 : -TempoValueEndgame / 2;
  return result;
}


/// Position::compute_non_pawn_material() computes the total non-pawn middle
/// game material score for the given side.  Material scores are updated
/// incrementally during the search, this function is only used while
/// initializing a new Position object.

Value Position::compute_non_pawn_material(Color c) const {

  Value result = Value(0);
  Square s;

  for (PieceType pt = KNIGHT; pt <= QUEEN; pt++)
  {
      Bitboard b = pieces_of_color_and_type(c, pt);
      while(b)
      {
          s = pop_1st_bit(&b);
          assert(piece_on(s) == piece_of_color_and_type(c, pt));
          result += piece_value_midgame(pt);
      }
  }
  return result;
}


/// Position::is_mate() returns true or false depending on whether the
/// side to move is checkmated. Note that this function is currently very
/// slow, and shouldn't be used frequently inside the search.

bool Position::is_mate() {

  if (is_check())
  {
      MovePicker mp = MovePicker(*this, false, MOVE_NONE, MOVE_NONE,
                                 MOVE_NONE, MOVE_NONE, Depth(0));
      return mp.get_next_move() == MOVE_NONE;
  }
  return false;
}


/// Position::is_draw() tests whether the position is drawn by material,
/// repetition, or the 50 moves rule.  It does not detect stalemates, this
/// must be done by the search.

bool Position::is_draw() const {

  // Draw by material?
  if (   !pawns()
      && (non_pawn_material(WHITE) + non_pawn_material(BLACK) <= BishopValueMidgame))
      return true;

  // Draw by the 50 moves rule?
  if (rule50 > 100 || (rule50 == 100 && !is_check()))
      return true;

  // Draw by repetition?
  for (int i = 2; i < Min(gamePly, rule50); i += 2)
      if (history[gamePly - i] == key)
          return true;

  return false;
}


/// Position::has_mate_threat() tests whether a given color has a mate in one
/// from the current position. This function is quite slow, but it doesn't
/// matter, because it is currently only called from PV nodes, which are rare.

bool Position::has_mate_threat(Color c) {

  UndoInfo u1, u2;
  Color stm = side_to_move();

  // The following lines are useless and silly, but prevents gcc from
  // emitting a stupid warning stating that u1.lastMove and u1.epSquare might
  // be used uninitialized.
  u1.lastMove = lastMove;
  u1.epSquare = epSquare;

  if (is_check())
      return false;

  // If the input color is not equal to the side to move, do a null move
  if (c != stm)
      do_null_move(u1);

  MoveStack mlist[120];
  int count;
  bool result = false;

  // Generate legal moves
  count = generate_legal_moves(*this, mlist);

  // Loop through the moves, and see if one of them is mate
  for (int i = 0; i < count; i++)
  {
      do_move(mlist[i].move, u2);
      if (is_mate())
          result = true;

      undo_move(mlist[i].move, u2);
  }

  // Undo null move, if necessary
  if (c != stm)
      undo_null_move(u1);

  return result;
}


/// Position::init_zobrist() is a static member function which initializes the
/// various arrays used to compute hash keys.

void Position::init_zobrist() {

  for (int i = 0; i < 2; i++)
      for (int j = 0; j < 8; j++)
          for (int k = 0; k < 64; k++)
              zobrist[i][j][k] = Key(genrand_int64());

  for (int i = 0; i < 64; i++)
      zobEp[i] = Key(genrand_int64());

  for (int i = 0; i < 16; i++)
      zobCastle[i] = genrand_int64();

  zobSideToMove = genrand_int64();

  for (int i = 0; i < 2; i++)
      for (int j = 0; j < 8; j++)
          for (int k = 0; k < 16; k++)
              zobMaterial[i][j][k] = (k > 0)? Key(genrand_int64()) : Key(0LL);

  for (int i = 0; i < 16; i++)
      zobMaterial[0][KING][i] = zobMaterial[1][KING][i] = Key(0ULL);
}


/// Position::init_piece_square_tables() initializes the piece square tables.
/// This is a two-step operation:  First, the white halves of the tables are
/// copied from the MgPST[][] and EgPST[][] arrays, with a small random number
/// added to each entry if the "Randomness" UCI parameter is non-zero.
/// Second, the black halves of the tables are initialized by mirroring
/// and changing the sign of the corresponding white scores.

void Position::init_piece_square_tables() {

  int r = get_option_value_int("Randomness"), i;
  for (Square s = SQ_A1; s <= SQ_H8; s++)
      for (Piece p = WP; p <= WK; p++)
      {
          i = (r == 0)? 0 : (genrand_int32() % (r*2) - r);
          MgPieceSquareTable[p][s] = Value(MgPST[p][s] + i);
          EgPieceSquareTable[p][s] = Value(EgPST[p][s] + i);
      }

  for (Square s = SQ_A1; s <= SQ_H8; s++)
      for (Piece p = BP; p <= BK; p++)
      {
          MgPieceSquareTable[p][s] = -MgPieceSquareTable[p-8][flip_square(s)];
          EgPieceSquareTable[p][s] = -EgPieceSquareTable[p-8][flip_square(s)];
      }
}


/// Position::flipped_copy() makes a copy of the input position, but with
/// the white and black sides reversed.  This is only useful for debugging,
/// especially for finding evaluation symmetry bugs.

void Position::flipped_copy(const Position &pos) {

  assert(pos.is_ok());

  clear();

  // Board
  for (Square s = SQ_A1; s <= SQ_H8; s++)
      if (!pos.square_is_empty(s))
          put_piece(Piece(int(pos.piece_on(s)) ^ 8), flip_square(s));

  // Side to move
  sideToMove = opposite_color(pos.side_to_move());

  // Castling rights
  if (pos.can_castle_kingside(WHITE))  allow_oo(BLACK);
  if (pos.can_castle_queenside(WHITE)) allow_ooo(BLACK);
  if (pos.can_castle_kingside(BLACK))  allow_oo(WHITE);
  if (pos.can_castle_queenside(BLACK)) allow_ooo(WHITE);

  initialKFile  = pos.initialKFile;
  initialKRFile = pos.initialKRFile;
  initialQRFile = pos.initialQRFile;

  for (Square sq = SQ_A1; sq <= SQ_H8; sq++)
      castleRightsMask[sq] = ALL_CASTLES;

  castleRightsMask[make_square(initialKFile,  RANK_1)] ^= (WHITE_OO | WHITE_OOO);
  castleRightsMask[make_square(initialKFile,  RANK_8)] ^= (BLACK_OO | BLACK_OOO);
  castleRightsMask[make_square(initialKRFile, RANK_1)] ^=  WHITE_OO;
  castleRightsMask[make_square(initialKRFile, RANK_8)] ^=  BLACK_OO;
  castleRightsMask[make_square(initialQRFile, RANK_1)] ^=  WHITE_OOO;
  castleRightsMask[make_square(initialQRFile, RANK_8)] ^=  BLACK_OOO;

  // En passant square
  if (pos.epSquare != SQ_NONE)
      epSquare = flip_square(pos.epSquare);

  // Checkers
  find_checkers();

  // Hash keys
  key = compute_key();
  pawnKey = compute_pawn_key();
  materialKey = compute_material_key();

  // Incremental scores
  mgValue = compute_mg_value();
  egValue = compute_eg_value();

  // Material
  npMaterial[WHITE] = compute_non_pawn_material(WHITE);
  npMaterial[BLACK] = compute_non_pawn_material(BLACK);

  assert(is_ok());
}


/// Position::is_ok() performs some consitency checks for the position object.
/// This is meant to be helpful when debugging.

bool Position::is_ok(int* failedStep) const {

  // What features of the position should be verified?
  static const bool debugBitboards = false;
  static const bool debugKingCount = false;
  static const bool debugKingCapture = false;
  static const bool debugCheckerCount = false;
  static const bool debugKey = false;
  static const bool debugMaterialKey = false;
  static const bool debugPawnKey = false;
  static const bool debugIncrementalEval = false;
  static const bool debugNonPawnMaterial = false;
  static const bool debugPieceCounts = false;
  static const bool debugPieceList = false;

  if (failedStep) *failedStep = 1;

  // Side to move OK?
  if (!color_is_ok(side_to_move()))
      return false;

  // Are the king squares in the position correct?
  if (failedStep) (*failedStep)++;
  if (piece_on(king_square(WHITE)) != WK)
      return false;

  if (failedStep) (*failedStep)++;
  if (piece_on(king_square(BLACK)) != BK)
      return false;

  // Castle files OK?
  if (failedStep) (*failedStep)++;
  if (!file_is_ok(initialKRFile))
      return false;

  if (!file_is_ok(initialQRFile))
      return false;

  // Do both sides have exactly one king?
  if (failedStep) (*failedStep)++;
  if (debugKingCount)
  {
      int kingCount[2] = {0, 0};
      for (Square s = SQ_A1; s <= SQ_H8; s++)
          if (type_of_piece_on(s) == KING)
              kingCount[color_of_piece_on(s)]++;

      if(kingCount[0] != 1 || kingCount[1] != 1)
          return false;
  }

  // Can the side to move capture the opponent's king?
  if (failedStep) (*failedStep)++;
  if (debugKingCapture)
  {
      Color us = side_to_move();
      Color them = opposite_color(us);
      Square ksq = king_square(them);
      if (square_is_attacked(ksq, us))
          return false;
  }

  // Is there more than 2 checkers?
  if (failedStep) (*failedStep)++;
  if (debugCheckerCount && count_1s(checkersBB) > 2)
      return false;

  // Bitboards OK?
  if (failedStep) (*failedStep)++;
  if (debugBitboards)
  {
      // The intersection of the white and black pieces must be empty
      if ((pieces_of_color(WHITE) & pieces_of_color(BLACK)) != EmptyBoardBB)
          return false;

      // The union of the white and black pieces must be equal to all
      // occupied squares
      if ((pieces_of_color(WHITE) | pieces_of_color(BLACK)) != occupied_squares())
          return false;

      // Separate piece type bitboards must have empty intersections
      for (PieceType p1 = PAWN; p1 <= KING; p1++)
          for (PieceType p2 = PAWN; p2 <= KING; p2++)
              if (p1 != p2 && (pieces_of_type(p1) & pieces_of_type(p2)))
                  return false;
  }

  // En passant square OK?
  if (failedStep) (*failedStep)++;
  if (ep_square() != SQ_NONE)
  {
      // The en passant square must be on rank 6, from the point of view of the
      // side to move.
      if (relative_rank(side_to_move(), ep_square()) != RANK_6)
          return false;
  }

  // Hash key OK?
  if (failedStep) (*failedStep)++;
  if (debugKey && key != compute_key())
      return false;

  // Pawn hash key OK?
  if (failedStep) (*failedStep)++;
  if (debugPawnKey && pawnKey != compute_pawn_key())
      return false;

  // Material hash key OK?
  if (failedStep) (*failedStep)++;
  if (debugMaterialKey && materialKey != compute_material_key())
      return false;

  // Incremental eval OK?
  if (failedStep) (*failedStep)++;
  if (debugIncrementalEval)
  {
      if (mgValue != compute_mg_value())
          return false;

      if (egValue != compute_eg_value())
          return false;
  }

  // Non-pawn material OK?
  if (failedStep) (*failedStep)++;
  if (debugNonPawnMaterial)
  {
      if(npMaterial[WHITE] != compute_non_pawn_material(WHITE))
          return false;

      if(npMaterial[BLACK] != compute_non_pawn_material(BLACK))
          return false;
  }

  // Piece counts OK?
  if (failedStep) (*failedStep)++;
  if (debugPieceCounts)
      for (Color c = WHITE; c <= BLACK; c++)
          for (PieceType pt = PAWN; pt <= KING; pt++)
              if (pieceCount[c][pt] != count_1s(pieces_of_color_and_type(c, pt)))
                  return false;

  if (failedStep) (*failedStep)++;
  if (debugPieceList)
  {
      for(Color c = WHITE; c <= BLACK; c++)
          for(PieceType pt = PAWN; pt <= KING; pt++)
              for(int i = 0; i < pieceCount[c][pt]; i++)
              {
                  if (piece_on(piece_list(c, pt, i)) != piece_of_color_and_type(c, pt))
                      return false;

                  if (index[piece_list(c, pt, i)] != i)
                      return false;
              }
  }
  if (failedStep) *failedStep = 0;
  return true;
}

// ======== san.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cassert>
#include <cstring>
#include <iomanip>
#include <string>
#include <sstream>

// ---- begin san.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(SAN_H_INCLUDED)
#define SAN_H_INCLUDED

////
//// Includes
////

#include <string>



////
//// Prototypes
////

extern const std::string move_to_san(Position &pos, Move m);
extern Move move_from_san(Position &pos, const std::string &str);
extern const std::string line_to_san(const Position &pos, Move line[],
                                     int startColumn, bool breakLines);
extern const std::string pretty_pv(const Position &pos, int time, int depth,
                                   uint64_t nodes, Value score, Move pv[]);


#endif // !defined(SAN_H_INCLUDED)
// ---- end san.h ----


////
//// Local definitions
////

namespace {

  /// Types

  enum Ambiguity {
    AMBIGUITY_NONE,
    AMBIGUITY_FILE,
    AMBIGUITY_RANK,
    AMBIGUITY_BOTH
  };


  /// Functions

  Ambiguity move_ambiguity(Position &pos, Move m);
  const std::string time_string(int milliseconds);
  const std::string score_string(Value v);
}


////
//// Functions
////

/// move_to_san() takes a position and a move as input, where it is assumed
/// that the move is a legal move from the position.  The return value is
/// a string containing the move in short algebraic notation.

const std::string move_to_san(Position &pos, Move m) {
  std::string str;

  assert(pos.is_ok());
  assert(move_is_ok(m));

  if(m == MOVE_NONE) {
    str = "(none)";
    return str;
  }
  else if(m == MOVE_NULL) {
    str = "(null)";
    return str;
  }
  else if(move_is_long_castle(m))
    str = "O-O-O";
  else if(move_is_short_castle(m))
    str = "O-O";
  else {
    Square from, to;
    Piece pc;

    from = move_from(m);
    to = move_to(m);
    pc = pos.piece_on(move_from(m));

    str = "";

    if(type_of_piece(pc) == PAWN) {
      if(pos.move_is_capture(m))
        str += file_to_char(square_file(move_from(m)));
    }
    else {
      str += piece_type_to_char(type_of_piece(pc), true);

      Ambiguity amb = move_ambiguity(pos, m);
      switch(amb) {

      case AMBIGUITY_NONE:
        break;

      case AMBIGUITY_FILE:
        str += file_to_char(square_file(from));
        break;

      case AMBIGUITY_RANK:
        str += rank_to_char(square_rank(from));
        break;

      case AMBIGUITY_BOTH:
        str += square_to_string(from);
        break;

      default:
        assert(false);
      }
    }

    if(pos.move_is_capture(m))
      str += "x";

    str += square_to_string(move_to(m));

    if(move_promotion(m)) {
      str += "=";
      str += piece_type_to_char(move_promotion(m), true);
    }
  }

  // Is the move check?  We don't use pos.move_is_check(m) here, because
  // Position::move_is_check doesn't detect all checks (not castling moves,
  // promotions and en passant captures).
  UndoInfo u;
  pos.do_move(m, u);
  if(pos.is_check())
    str += pos.is_mate()? "#" : "+";
  pos.undo_move(m, u);

  return str;
}


/// move_from_san() takes a position and a string as input, and tries to
/// interpret the string as a move in short algebraic notation.  On success,
/// the move is returned.  On failure (i.e. if the string is unparsable, or
/// if the move is illegal or ambiguous), MOVE_NONE is returned.

Move move_from_san(Position &pos, const std::string &movestr) {
  assert(pos.is_ok());

  MovePicker mp = MovePicker(pos, false, MOVE_NONE, MOVE_NONE, MOVE_NONE,
                             MOVE_NONE, OnePly);

  // Castling moves
  if(movestr == "O-O-O") {
    Move m;
    while((m = mp.get_next_move()) != MOVE_NONE)
      if(move_is_long_castle(m) && pos.pl_move_is_legal(m))
        return m;
    return MOVE_NONE;
  }
  else if(movestr == "O-O") {
    Move m;
    while((m = mp.get_next_move()) != MOVE_NONE)
      if(move_is_short_castle(m) && pos.pl_move_is_legal(m))
        return m;
    return MOVE_NONE;
  }

  // Normal moves
  const char *cstr = movestr.c_str();
  const char *c;
  char *cc;
  char str[10];
  int i;

  // Initialize str[] by making a copy of movestr with the characters
  // 'x', '=', '+' and '#' removed.
  cc = str;
  for(i=0, c=cstr; i<10 && *c!='\0' && *c!='\n' && *c!=' '; i++, c++)
    if(!strchr("x=+#", *c)) {
      *cc = strchr("nrq", *c)? toupper(*c) : *c;
      cc++;
    }
  *cc = '\0';

  size_t left = 0, right = strlen(str) - 1;
  PieceType pt = NO_PIECE_TYPE, promotion;
  Square to;
  File fromFile = FILE_NONE;
  Rank fromRank = RANK_NONE;

  // Promotion?
  if(strchr("BNRQ", str[right])) {
    promotion = piece_type_from_char(str[right]);
    right--;
  }
  else
    promotion = NO_PIECE_TYPE;

  // Find the moving piece:
  if(left < right) {
    if(strchr("BNRQK", str[left])) {
      pt = piece_type_from_char(str[left]);
      left++;
    }
    else
      pt = PAWN;
  }

  // Find the to square:
  if(left < right) {
    if(str[right] < '1' || str[right] > '8' ||
       str[right-1] < 'a' || str[right-1] > 'h')
      return MOVE_NONE;
    to = make_square(file_from_char(str[right-1]), rank_from_char(str[right]));
    right -= 2;
  }
  else
    return MOVE_NONE;

  // Find the file and/or rank of the from square:
  if(left <= right) {
    if(strchr("abcdefgh", str[left])) {
      fromFile = file_from_char(str[left]);
      left++;
    }
    if(strchr("12345678", str[left]))
      fromRank = rank_from_char(str[left]);
  }

  // Look for a matching move:
  Move m, move = MOVE_NONE;
  int matches = 0;

  while((m = mp.get_next_move()) != MOVE_NONE) {
    bool match = true;
    if(pos.type_of_piece_on(move_from(m)) != pt)
      match = false;
    else if(move_to(m) != to)
      match = false;
    else if(move_promotion(m) != promotion)
      match = false;
    else if(fromFile != FILE_NONE && fromFile != square_file(move_from(m)))
      match = false;
    else if(fromRank != RANK_NONE && fromRank != square_rank(move_from(m)))
      match = false;
    if(match) {
      move = m;
      matches++;
    }
  }

  if(matches == 1)
    return move;
  else
    return MOVE_NONE;
}


/// line_to_san() takes a position and a line (an array of moves representing
/// a sequence of legal moves from the position) as input, and returns a
/// string containing the line in short algebraic notation.  If the boolean
/// parameter 'breakLines' is true, line breaks are inserted, with a line
/// length of 80 characters.  After a line break, 'startColumn' spaces are
/// inserted at the beginning of the new line.

const std::string line_to_san(const Position &pos, Move line[], int startColumn,
                              bool breakLines) {
  Position p = Position(pos);
  UndoInfo u;
  std::stringstream s;
  std::string moveStr;
  size_t length, maxLength;

  length = 0;
  maxLength = 80 - startColumn;

  for(int i = 0; line[i] != MOVE_NONE; i++) {
    moveStr = move_to_san(p, line[i]);
    length += moveStr.length() + 1;
    if(breakLines && length > maxLength) {
      s << "\n";
      for(int j = 0; j < startColumn; j++)
        s << " ";
      length = moveStr.length() + 1;
    }
    s << moveStr << " ";

    if(line[i] == MOVE_NULL)
      p.do_null_move(u);
    else
      p.do_move(line[i], u);
  }

  return s.str();
}


/// pretty_pv() creates a human-readable string from a position and a PV.
/// It is used to write search information to the log file (which is created
/// when the UCI parameter "Use Search Log" is "true").

const std::string pretty_pv(const Position &pos, int time, int depth,
                            uint64_t nodes, Value score, Move pv[]) {
  std::stringstream s;

  // Depth
  s << std::setw(2) << std::setfill(' ') << depth << "  ";

  // Score
  s << std::setw(8) << score_string(score);

  // Time
  s << std::setw(8) << std::setfill(' ') << time_string(time) << " ";

  // Nodes
  if(nodes < 1000000ULL)
    s << std::setw(8) << std::setfill(' ') << nodes << " ";
  else if(nodes < 1000000000ULL)
    s << std::setw(7) << std::setfill(' ') << nodes/1000ULL << 'k' << " ";
  else
    s << std::setw(7) << std::setfill(' ') << nodes/1000000ULL << 'M' << " ";

  // PV
  s << line_to_san(pos, pv, 30, true);

  return s.str();
}


namespace {

  Ambiguity move_ambiguity(Position &pos, Move m) {
    Square from, to;
    Piece pc;

    from = move_from(m);
    to = move_to(m);
    pc = pos.piece_on(from);

    // King moves are never ambiguous, because there is never two kings of
    // the same color.
    if(type_of_piece(pc) == KING)
      return AMBIGUITY_NONE;

    MovePicker mp = MovePicker(pos, false, MOVE_NONE, MOVE_NONE, MOVE_NONE,
                               MOVE_NONE, OnePly);
    Move mv, moveList[8];
    int i, j, n;

    n = 0;
    while((mv = mp.get_next_move()) != MOVE_NONE)
      if(move_to(mv) == to && pos.piece_on(move_from(mv)) == pc
         && pos.pl_move_is_legal(mv))
        moveList[n++] = mv;
    if(n == 1)
      return AMBIGUITY_NONE;

    j = 0;
    for(i = 0; i < n; i++)
      if(square_file(move_from(moveList[i])) == square_file(from))
        j++;
    if(j == 1)
      return AMBIGUITY_FILE;

    j = 0;
    for(i = 0; i < n; i++)
      if(square_rank(move_from(moveList[i])) == square_rank(from))
        j++;
    if(j == 1)
      return AMBIGUITY_RANK;

    return AMBIGUITY_BOTH;
  }


  const std::string time_string(int milliseconds) {
    std::stringstream s;

    int hours = milliseconds / (1000 * 60 * 60);
    int minutes = (milliseconds - hours*1000*60*60) / (60*1000);
    int seconds = (milliseconds - hours*1000*60*60 - minutes*60*1000) / 1000;

    if(hours)
      s << hours << ':';
    s << std::setw(2) << std::setfill('0') << minutes << ':';
    s << std::setw(2) << std::setfill('0') << seconds;

    return s.str();
  }


  const std::string score_string(Value v) {
    std::stringstream s;

    if(abs(v) >= VALUE_MATE - 200) {
      if(v < 0)
        s << "-#" << (VALUE_MATE + v) / 2;
      else
        s << "#" << (VALUE_MATE - v + 1) / 2;
    }
    else {
      float floatScore = float(v) / float(PawnValueMidgame);
      if(v >= 0)
        s << '+';
      s << std::setprecision(2) << std::fixed << floatScore;
    }
    return s.str();
  }

}

// ======== search.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>



////
//// Local definitions
////

namespace {

  /// Types

  // The RootMove class is used for moves at the root at the tree.  For each
  // root move, we store a score, a node count, and a PV (really a refutation
  // in the case of moves which fail low).

  struct RootMove {

    RootMove();
    bool operator<(const RootMove&); // used to sort

    Move move;
    Value score;
    int64_t nodes, cumulativeNodes;
    Move pv[PLY_MAX_PLUS_2];
  };


  // The RootMoveList class is essentially an array of RootMove objects, with
  // a handful of methods for accessing the data in the individual moves.

  class RootMoveList {

  public:
    RootMoveList(Position &pos, Move searchMoves[]);
    inline Move get_move(int moveNum) const;
    inline Value get_move_score(int moveNum) const;
    inline void set_move_score(int moveNum, Value score);
    inline void set_move_nodes(int moveNum, int64_t nodes);
    void set_move_pv(int moveNum, const Move pv[]);
    inline Move get_move_pv(int moveNum, int i) const;
    inline int64_t get_move_cumulative_nodes(int moveNum) const;
    inline int move_count() const;
    Move scan_for_easy_move() const;
    inline void sort();
    void sort_multipv(int n);

  private:
    static const int MaxRootMoves = 500;
    RootMove moves[MaxRootMoves];
    int count;
  };


  /// Constants and variables

  // Minimum number of full depth (i.e. non-reduced) moves at PV and non-PV
  // nodes:
  int LMRPVMoves = 15;
  int LMRNonPVMoves = 4;

  // Depth limit for use of dynamic threat detection:
  Depth ThreatDepth = 5*OnePly;

  // Depth limit for selective search:
  Depth SelectiveDepth = 7*OnePly;

  // Use internal iterative deepening?
  const bool UseIIDAtPVNodes = true;
  const bool UseIIDAtNonPVNodes = false;

  // Internal iterative deepening margin.  At Non-PV moves, when
  // UseIIDAtNonPVNodes is true, we do an internal iterative deepening search
  // when the static evaluation is at most IIDMargin below beta.
  const Value IIDMargin = Value(0x100);

  // Use easy moves?
  const bool UseEasyMove = true;

  // Easy move margin.  An easy move candidate must be at least this much
  // better than the second best move.
  const Value EasyMoveMargin = Value(0x200);

  // Problem margin.  If the score of the first move at iteration N+1 has
  // dropped by more than this since iteration N, the boolean variable
  // "Problem" is set to true, which will make the program spend some extra
  // time looking for a better move.
  const Value ProblemMargin = Value(0x28);

  // No problem margin.  If the boolean "Problem" is true, and a new move
  // is found at the root which is less than NoProblemMargin worse than the
  // best move from the previous iteration, Problem is set back to false.
  const Value NoProblemMargin = Value(0x14);

  // Null move margin.  A null move search will not be done if the approximate
  // evaluation of the position is more than NullMoveMargin below beta.
  const Value NullMoveMargin = Value(0x300);

  // Pruning criterions.  See the code and comments in ok_to_prune() to
  // understand their precise meaning.
  const bool PruneEscapeMoves = false;
  const bool PruneDefendingMoves = false;
  const bool PruneBlockingMoves = false;

  // Use futility pruning?
  bool UseQSearchFutilityPruning = true;
  bool UseFutilityPruning = true;

  // Margins for futility pruning in the quiescence search, at frontier
  // nodes, and at pre-frontier nodes:
  Value FutilityMargin0 = Value(0x80);
  Value FutilityMargin1 = Value(0x100);
  Value FutilityMargin2 = Value(0x300);

  // Razoring
  Depth RazorDepth = 4*OnePly;
  Value RazorMargin = Value(0x300);

  // Last seconds noise filtering (LSN)
  bool UseLSNFiltering = false;
  bool looseOnTime = false;
  int LSNTime = 4 * 1000; // In milliseconds
  Value LSNValue = Value(0x200);

  // Extensions.  Array index 0 is used at non-PV nodes, index 1 at PV nodes.
  Depth CheckExtension[2] = {OnePly, OnePly};
  Depth SingleReplyExtension[2] = {OnePly / 2, OnePly / 2};
  Depth PawnPushTo7thExtension[2] = {OnePly / 2, OnePly / 2};
  Depth PassedPawnExtension[2] = {Depth(0), Depth(0)};
  Depth PawnEndgameExtension[2] = {OnePly, OnePly};
  Depth MateThreatExtension[2] = {Depth(0), Depth(0)};

  // Search depth at iteration 1:
  const Depth InitialDepth = OnePly /*+ OnePly/2*/;

  // Node counters
  int NodesSincePoll;
  int NodesBetweenPolls = 30000;

  // Iteration counter:
  int Iteration;

  // Scores and number of times the best move changed for each iteration:
  Value ValueByIteration[PLY_MAX_PLUS_2];
  int BestMoveChangesByIteration[PLY_MAX_PLUS_2];

  // MultiPV mode:
  int MultiPV = 1;

  // Time managment variables
  int SearchStartTime;
  int MaxNodes, MaxDepth;
  int MaxSearchTime, AbsoluteMaxSearchTime, ExtraSearchTime, TimeAdvantage;
  Move BestRootMove, PonderMove, EasyMove;
  int RootMoveNumber;
  bool InfiniteSearch;
  bool PonderSearch;
  bool StopOnPonderhit;
  bool AbortSearch;
  bool Quit;
  bool FailHigh;
  bool Problem;
  bool PonderingEnabled;
  int ExactMaxTime;

  // Show current line?
  bool ShowCurrentLine = false;

  // Log file
  bool UseLogFile = false;
  std::ofstream LogFile;

  // MP related variables
  Depth MinimumSplitDepth = 4*OnePly;
  int MaxThreadsPerSplitPoint = 4;
  Thread Threads[THREAD_MAX];
  Lock MPLock;
  bool AllThreadsShouldExit = false;
  const int MaxActiveSplitPoints = 8;
  SplitPoint SplitPointStack[THREAD_MAX][MaxActiveSplitPoints];
  bool Idle = true;

#if !defined(_MSC_VER)
  pthread_cond_t WaitCond;
  pthread_mutex_t WaitLock;
#else
  HANDLE SitIdleEvent[THREAD_MAX];
#endif


  /// Functions

  Value id_loop(const Position &pos, Move searchMoves[]);
  Value root_search(Position &pos, SearchStack ss[], RootMoveList &rml);
  Value search_pv(Position &pos, SearchStack ss[], Value alpha, Value beta,
                  Depth depth, int ply, int threadID);
  Value search(Position &pos, SearchStack ss[], Value beta,
               Depth depth, int ply, bool allowNullmove, int threadID);
  Value qsearch(Position &pos, SearchStack ss[], Value alpha, Value beta,
                Depth depth, int ply, int threadID);
  void sp_search(SplitPoint *sp, int threadID);
  void sp_search_pv(SplitPoint *sp, int threadID);
  void init_search_stack(SearchStack ss[]);
  void init_node(const Position &pos, SearchStack ss[], int ply, int threadID);
  void update_pv(SearchStack ss[], int ply);
  void sp_update_pv(SearchStack *pss, SearchStack ss[], int ply);
  bool connected_moves(const Position &pos, Move m1, Move m2);
  Depth extension(const Position &pos, Move m, bool pvNode, bool check,
                  bool singleReply, bool mateThreat);
  bool ok_to_do_nullmove(const Position &pos);
  bool ok_to_prune(const Position &pos, Move m, Move threat, Depth d);
  bool ok_to_use_TT(const TTEntry* tte, Depth depth, Value beta, int ply);
  bool ok_to_history(const Position &pos, Move m);
  void update_history(const Position& pos, Move m, Depth depth,
                      Move movesSearched[], int moveCount);

  bool fail_high_ply_1();
  int current_search_time();
  int nps();
  void poll();
  void ponderhit();
  void print_current_line(SearchStack ss[], int ply, int threadID);
  void wait_for_stop_or_ponderhit();

  void idle_loop(int threadID, SplitPoint *waitSp);
  void init_split_point_stack();
  void destroy_split_point_stack();
  bool thread_should_stop(int threadID);
  bool thread_is_available(int slave, int master);
  bool idle_thread_exists(int master);
  bool split(const Position &pos, SearchStack *ss, int ply,
             Value *alpha, Value *beta, Value *bestValue, Depth depth,
             int *moves, MovePicker *mp, Bitboard dcCandidates, int master,
             bool pvNode);
  void wake_sleeping_threads();

#if !defined(_MSC_VER)
  void *init_thread(void *threadID);
#else
  DWORD WINAPI init_thread(LPVOID threadID);
#endif

}


////
//// Global variables
////

// The main transposition table
TranspositionTable TT = TranspositionTable(TTDefaultSize);


// Number of active threads:
int ActiveThreads = 1;

// Locks.  In principle, there is no need for IOLock to be a global variable,
// but it could turn out to be useful for debugging.
Lock IOLock;

History H;  // Should be made local?


////
//// Functions
////

/// think() is the external interface to Stockfish's search, and is called when
/// the program receives the UCI 'go' command.  It initializes various
/// search-related global variables, and calls root_search()

void think(const Position &pos, bool infinite, bool ponder, int side_to_move,
           int time[], int increment[], int movesToGo, int maxDepth,
           int maxNodes, int maxTime, Move searchMoves[]) {

  // Look for a book move
  if (!infinite && !ponder && get_option_value_bool("OwnBook"))
  {
      Move bookMove;
      if (get_option_value_string("Book File") != OpeningBook.file_name())
      {
          OpeningBook.close();
          OpeningBook.open("book.bin");
      }
      bookMove = OpeningBook.get_move(pos);
      if (bookMove != MOVE_NONE)
      {
          std::cout << "bestmove " << bookMove << std::endl;
          return;
      }
  }

  // Initialize global search variables
  Idle = false;
  SearchStartTime = get_system_time();
  BestRootMove = MOVE_NONE;
  PonderMove = MOVE_NONE;
  EasyMove = MOVE_NONE;
  for (int i = 0; i < THREAD_MAX; i++)
  {
      Threads[i].nodes = 0ULL;
      Threads[i].failHighPly1 = false;
  }
  NodesSincePoll = 0;
  InfiniteSearch = infinite;
  PonderSearch = ponder;
  StopOnPonderhit = false;
  AbortSearch = false;
  Quit = false;
  FailHigh = false;
  Problem = false;
  ExactMaxTime = maxTime;

  // Read UCI option values
  TT.set_size(get_option_value_int("Hash"));
  if (button_was_pressed("Clear Hash"))
      TT.clear();

  PonderingEnabled = get_option_value_bool("Ponder");
  MultiPV = get_option_value_int("MultiPV");

  CheckExtension[1] = Depth(get_option_value_int("Check Extension (PV nodes)"));
  CheckExtension[0] = Depth(get_option_value_int("Check Extension (non-PV nodes)"));

  SingleReplyExtension[1] = Depth(get_option_value_int("Single Reply Extension (PV nodes)"));
  SingleReplyExtension[0] = Depth(get_option_value_int("Single Reply Extension (non-PV nodes)"));

  PawnPushTo7thExtension[1] = Depth(get_option_value_int("Pawn Push to 7th Extension (PV nodes)"));
  PawnPushTo7thExtension[0] = Depth(get_option_value_int("Pawn Push to 7th Extension (non-PV nodes)"));

  PassedPawnExtension[1] = Depth(get_option_value_int("Passed Pawn Extension (PV nodes)"));
  PassedPawnExtension[0] = Depth(get_option_value_int("Passed Pawn Extension (non-PV nodes)"));

  PawnEndgameExtension[1] = Depth(get_option_value_int("Pawn Endgame Extension (PV nodes)"));
  PawnEndgameExtension[0] = Depth(get_option_value_int("Pawn Endgame Extension (non-PV nodes)"));

  MateThreatExtension[1] = Depth(get_option_value_int("Mate Threat Extension (PV nodes)"));
  MateThreatExtension[0] = Depth(get_option_value_int("Mate Threat Extension (non-PV nodes)"));

  LMRPVMoves     = get_option_value_int("Full Depth Moves (PV nodes)") + 1;
  LMRNonPVMoves  = get_option_value_int("Full Depth Moves (non-PV nodes)") + 1;
  ThreatDepth    = get_option_value_int("Threat Depth") * OnePly;
  SelectiveDepth = get_option_value_int("Selective Plies") * OnePly;

  Chess960 = get_option_value_bool("UCI_Chess960");
  ShowCurrentLine = get_option_value_bool("UCI_ShowCurrLine");
  UseLogFile = get_option_value_bool("Use Search Log");
  if (UseLogFile)
      LogFile.open(get_option_value_string("Search Log Filename").c_str(), std::ios::out | std::ios::app);

  UseQSearchFutilityPruning = get_option_value_bool("Futility Pruning (Quiescence Search)");
  UseFutilityPruning = get_option_value_bool("Futility Pruning (Main Search)");

  FutilityMargin0 = value_from_centipawns(get_option_value_int("Futility Margin 0"));
  FutilityMargin1 = value_from_centipawns(get_option_value_int("Futility Margin 1"));
  FutilityMargin2 = value_from_centipawns(get_option_value_int("Futility Margin 2"));

  RazorDepth = (get_option_value_int("Maximum Razoring Depth") + 1) * OnePly;
  RazorMargin = value_from_centipawns(get_option_value_int("Razoring Margin"));

  UseLSNFiltering = get_option_value_bool("LSN filtering");
  LSNTime = get_option_value_int("LSN Time Margin (sec)") * 1000;
  LSNValue = value_from_centipawns(get_option_value_int("LSN Value Margin"));

  MinimumSplitDepth = get_option_value_int("Minimum Split Depth") * OnePly;
  MaxThreadsPerSplitPoint = get_option_value_int("Maximum Number of Threads per Split Point");

  read_weights(pos.side_to_move());

  int newActiveThreads = get_option_value_int("Threads");
  if (newActiveThreads != ActiveThreads)
  {
      ActiveThreads = newActiveThreads;
      init_eval(ActiveThreads);
  }

  // Wake up sleeping threads:
  wake_sleeping_threads();

  for (int i = 1; i < ActiveThreads; i++)
      assert(thread_is_available(i, 0));

  // Set thinking time:
  int myTime = time[side_to_move];
  int myIncrement = increment[side_to_move];
  int oppTime = time[1 - side_to_move];

  TimeAdvantage = myTime - oppTime;

  if (!movesToGo) // Sudden death time control
  { 
      if (increment)
      {
          MaxSearchTime = myTime / 30 + myIncrement;
          AbsoluteMaxSearchTime = Max(myTime / 4, myIncrement - 100);
      } else { // Blitz game without increment
          MaxSearchTime = myTime / 40;
          AbsoluteMaxSearchTime = myTime / 8;
      }
  }
  else // (x moves) / (y minutes)
  {
      if (movesToGo == 1)
      {
          MaxSearchTime = myTime / 2;
          AbsoluteMaxSearchTime = Min(myTime / 2, myTime - 500);
      } else {
          MaxSearchTime = myTime / Min(movesToGo, 20);
          AbsoluteMaxSearchTime = Min((4 * myTime) / movesToGo, myTime / 3);
      }
  }

  if (PonderingEnabled)
  {
      MaxSearchTime += MaxSearchTime / 4;
      MaxSearchTime = Min(MaxSearchTime, AbsoluteMaxSearchTime);
  }

  // Fixed depth or fixed number of nodes?
  MaxDepth = maxDepth;
  if (MaxDepth)
      InfiniteSearch = true; // HACK

  MaxNodes = maxNodes;
  if (MaxNodes)
  {
      NodesBetweenPolls = Min(MaxNodes, 30000);
      InfiniteSearch = true; // HACK
  }
  else
      NodesBetweenPolls = 30000;


  // Write information to search log file:
  if (UseLogFile)
      LogFile << "Searching: " << pos.to_fen() << std::endl
              << "infinite: " << infinite
              << " ponder: " << ponder
              << " time: " << myTime
              << " increment: " << myIncrement
              << " moves to go: " << movesToGo << std::endl;


  // We're ready to start thinking.  Call the iterative deepening loop
  // function:
  if (!looseOnTime)
  {
      Value v = id_loop(pos, searchMoves);
      looseOnTime = (   UseLSNFiltering
                     && myTime < LSNTime
                     && myIncrement == 0
                     && v < -LSNValue);
  }
  else
  {
      looseOnTime = false; // reset for next match
      while (SearchStartTime + myTime + 1000 > get_system_time())
          ; // wait here
      id_loop(pos, searchMoves); // to fail gracefully
  }

  if (UseLogFile)
      LogFile.close();

  if (Quit)
  {
      OpeningBook.close();
      stop_threads();
      quit_eval();
      exit(0);
  }
  Idle = true;
}


/// init_threads() is called during startup.  It launches all helper threads,
/// and initializes the split point stack and the global locks and condition
/// objects.

void init_threads() {

  volatile int i;

#if !defined(_MSC_VER)
  pthread_t pthread[1];
#endif

  for (i = 0; i < THREAD_MAX; i++)
      Threads[i].activeSplitPoints = 0;

  // Initialize global locks:
  lock_init(&MPLock, NULL);
  lock_init(&IOLock, NULL);

  init_split_point_stack();

#if !defined(_MSC_VER)
  pthread_mutex_init(&WaitLock, NULL);
  pthread_cond_init(&WaitCond, NULL);
#else
  for (i = 0; i < THREAD_MAX; i++)
      SitIdleEvent[i] = CreateEvent(0, FALSE, FALSE, 0);
#endif

  // All threads except the main thread should be initialized to idle state
  for (i = 1; i < THREAD_MAX; i++)
  {
      Threads[i].stop = false;
      Threads[i].workIsWaiting = false;
      Threads[i].idle = true;
      Threads[i].running = false;
  }

  // Launch the helper threads
  for(i = 1; i < THREAD_MAX; i++)
  {
#if !defined(_MSC_VER)
      pthread_create(pthread, NULL, init_thread, (void*)(&i));
#else
      DWORD iID[1];
      CreateThread(NULL, 0, init_thread, (LPVOID)(&i), 0, iID);
#endif

      // Wait until the thread has finished launching:
      while (!Threads[i].running);
  }
}


/// stop_threads() is called when the program exits.  It makes all the
/// helper threads exit cleanly.

void stop_threads() {

  ActiveThreads = THREAD_MAX;  // HACK
  Idle = false;  // HACK
  wake_sleeping_threads();
  AllThreadsShouldExit = true;
  for (int i = 1; i < THREAD_MAX; i++)
  {
      Threads[i].stop = true;
      while(Threads[i].running);
  }
  destroy_split_point_stack();
}


/// nodes_searched() returns the total number of nodes searched so far in
/// the current search.

int64_t nodes_searched() {

  int64_t result = 0ULL;
  for (int i = 0; i < ActiveThreads; i++)
      result += Threads[i].nodes;
  return result;
}


namespace {

  // id_loop() is the main iterative deepening loop.  It calls root_search
  // repeatedly with increasing depth until the allocated thinking time has
  // been consumed, the user stops the search, or the maximum search depth is
  // reached.

  Value id_loop(const Position &pos, Move searchMoves[]) {

    Position p(pos);
    SearchStack ss[PLY_MAX_PLUS_2];

    // searchMoves are verified, copied, scored and sorted
    RootMoveList rml(p, searchMoves);

    // Initialize
    TT.new_search();
    H.clear();
    init_search_stack(ss);

    ValueByIteration[0] = Value(0);
    ValueByIteration[1] = rml.get_move_score(0);
    Iteration = 1;

    EasyMove = rml.scan_for_easy_move();

    // Iterative deepening loop
    while (!AbortSearch && Iteration < PLY_MAX)
    {
        // Initialize iteration
        rml.sort();
        Iteration++;
        BestMoveChangesByIteration[Iteration] = 0;
        if (Iteration <= 5)
            ExtraSearchTime = 0;

        std::cout << "info depth " << Iteration << std::endl;

        // Search to the current depth
        ValueByIteration[Iteration] = root_search(p, ss, rml);

        // Erase the easy move if it differs from the new best move
        if (ss[0].pv[0] != EasyMove)
            EasyMove = MOVE_NONE;

        Problem = false;

        if (!InfiniteSearch)
        {
            // Time to stop?
            bool stopSearch = false;

            // Stop search early if there is only a single legal move:
            if (Iteration >= 6 && rml.move_count() == 1)
                stopSearch = true;

            // Stop search early when the last two iterations returned a mate score
            if (  Iteration >= 6
                && abs(ValueByIteration[Iteration]) >= abs(VALUE_MATE) - 100
                && abs(ValueByIteration[Iteration-1]) >= abs(VALUE_MATE) - 100)
                stopSearch = true;

            // Stop search early if one move seems to be much better than the rest
            int64_t nodes = nodes_searched();
            if (   Iteration >= 8
                && EasyMove == ss[0].pv[0]
                && (  (   rml.get_move_cumulative_nodes(0) > (nodes * 85) / 100
                       && current_search_time() > MaxSearchTime / 16)
                    ||(   rml.get_move_cumulative_nodes(0) > (nodes * 98) / 100
                       && current_search_time() > MaxSearchTime / 32)))
                stopSearch = true;

            // Add some extra time if the best move has changed during the last two iterations
            if (Iteration > 5 && Iteration <= 50)
                ExtraSearchTime = BestMoveChangesByIteration[Iteration]   * (MaxSearchTime / 2)
                                + BestMoveChangesByIteration[Iteration-1] * (MaxSearchTime / 3);

            // If we need some more and we are in time advantage take it
            if (ExtraSearchTime > 0 && TimeAdvantage > 2 * MaxSearchTime)
                ExtraSearchTime += MaxSearchTime / 2;

            // Stop search if most of MaxSearchTime is consumed at the end of the
            // iteration.  We probably don't have enough time to search the first
            // move at the next iteration anyway.
            if (current_search_time() > ((MaxSearchTime + ExtraSearchTime)*80) / 128)
                stopSearch = true;

            if (stopSearch)
            {
                if (!PonderSearch)
                    break;
                else
                    StopOnPonderhit = true;
            }
        }
        // Write PV to transposition table, in case the relevant entries have
        // been overwritten during the search:
        TT.insert_pv(p, ss[0].pv);

        if (MaxDepth && Iteration >= MaxDepth)
            break;
    }

    rml.sort();

    // If we are pondering, we shouldn't print the best move before we
    // are told to do so
    if (PonderSearch)
        wait_for_stop_or_ponderhit();
    else
        // Print final search statistics
        std::cout << "info nodes " << nodes_searched()
                  << " nps " << nps()
                  << " time " << current_search_time()
                  << " hashfull " << TT.full() << std::endl;

    // Print the best move and the ponder move to the standard output
    std::cout << "bestmove " << ss[0].pv[0];
    if (ss[0].pv[1] != MOVE_NONE)
        std::cout << " ponder " << ss[0].pv[1];

    std::cout << std::endl;

    if (UseLogFile)
    {
        UndoInfo u;
        LogFile << "Nodes: " << nodes_searched() << std::endl
                << "Nodes/second: " << nps() << std::endl
                << "Best move: " << move_to_san(p, ss[0].pv[0]) << std::endl;

        p.do_move(ss[0].pv[0], u);
        LogFile << "Ponder move: " << move_to_san(p, ss[0].pv[1])
                << std::endl << std::endl;
    }
    return rml.get_move_score(0);
  }


  // root_search() is the function which searches the root node.  It is
  // similar to search_pv except that it uses a different move ordering
  // scheme (perhaps we should try to use this at internal PV nodes, too?)
  // and prints some information to the standard output.

  Value root_search(Position &pos, SearchStack ss[], RootMoveList &rml) {

    Value alpha = -VALUE_INFINITE;
    Value beta = VALUE_INFINITE, value;
    Bitboard dcCandidates = pos.discovered_check_candidates(pos.side_to_move());

    // Loop through all the moves in the root move list
    for (int i = 0; i <  rml.move_count() && !AbortSearch; i++)
    {
        int64_t nodes;
        Move move;
        UndoInfo u;
        Depth ext, newDepth;

        RootMoveNumber = i + 1;
        FailHigh = false;

        // Remember the node count before the move is searched. The node counts
        // are used to sort the root moves at the next iteration.
        nodes = nodes_searched();

        // Pick the next root move, and print the move and the move number to
        // the standard output.
        move = ss[0].currentMove = rml.get_move(i);
        if (current_search_time() >= 1000)
            std::cout << "info currmove " << move
                      << " currmovenumber " << i + 1 << std::endl;

        // Decide search depth for this move
        ext = extension(pos, move, true, pos.move_is_check(move), false, false);
        newDepth = (Iteration - 2) * OnePly + ext + InitialDepth;

        // Make the move, and search it
        pos.do_move(move, u, dcCandidates);

        if (i < MultiPV)
        {
            value = -search_pv(pos, ss, -beta, VALUE_INFINITE, newDepth, 1, 0);
            // If the value has dropped a lot compared to the last iteration,
            // set the boolean variable Problem to true. This variable is used
            // for time managment: When Problem is true, we try to complete the
            // current iteration before playing a move.
            Problem = (Iteration >= 2 && value <= ValueByIteration[Iteration-1] - ProblemMargin);

            if (Problem && StopOnPonderhit)
                StopOnPonderhit = false;
        } 
        else
        {
            value = -search(pos, ss, -alpha, newDepth, 1, true, 0);
            if (value > alpha)
            {
                // Fail high! Set the boolean variable FailHigh to true, and
                // re-search the move with a big window. The variable FailHigh is
                // used for time managment: We try to avoid aborting the search
                // prematurely during a fail high research.
                FailHigh = true;
                value = -search_pv(pos, ss, -beta, -alpha, newDepth, 1, 0);
            }
        }

        pos.undo_move(move, u);

        // Finished searching the move. If AbortSearch is true, the search
        // was aborted because the user interrupted the search or because we
        // ran out of time. In this case, the return value of the search cannot
        // be trusted, and we break out of the loop without updating the best
        // move and/or PV:
        if (AbortSearch)
            break;

        // Remember the node count for this move. The node counts are used to
        // sort the root moves at the next iteration.
        rml.set_move_nodes(i, nodes_searched() - nodes);

        assert(value >= -VALUE_INFINITE && value <= VALUE_INFINITE);

        if (value <= alpha && i >= MultiPV)
            rml.set_move_score(i, -VALUE_INFINITE);
        else
        {
            // New best move!

            // Update PV
            rml.set_move_score(i, value);
            update_pv(ss, 0);
            rml.set_move_pv(i, ss[0].pv);

            if (MultiPV == 1)
            {
                // We record how often the best move has been changed in each
                // iteration. This information is used for time managment: When
                // the best move changes frequently, we allocate some more time.
                if (i > 0)
                    BestMoveChangesByIteration[Iteration]++;

                // Print search information to the standard output:
                std::cout << "info depth " << Iteration
                          << " score " << value_to_string(value)
                          << " time " << current_search_time()
                          << " nodes " << nodes_searched()
                          << " nps " << nps()
                          << " pv ";

                for (int j = 0; ss[0].pv[j] != MOVE_NONE && j < PLY_MAX; j++)
                    std::cout << ss[0].pv[j] << " ";

                std::cout << std::endl;

                if (UseLogFile)
                    LogFile << pretty_pv(pos, current_search_time(), Iteration, nodes_searched(), value, ss[0].pv)
                            << std::endl;

                alpha = value;

                // Reset the global variable Problem to false if the value isn't too
                // far below the final value from the last iteration.
                if (value > ValueByIteration[Iteration - 1] - NoProblemMargin)
                    Problem = false;
            }
            else // MultiPV > 1
            {
                rml.sort_multipv(i);
                for (int j = 0; j < Min(MultiPV, rml.move_count()); j++)
                {
                    int k;
                    std::cout << "info multipv " << j + 1
                              << " score " << value_to_string(rml.get_move_score(j))
                              << " depth " << ((j <= i)? Iteration : Iteration - 1)
                              << " time " << current_search_time()
                              << " nodes " << nodes_searched()
                              << " nps " << nps()
                              << " pv ";

                    for (k = 0; rml.get_move_pv(j, k) != MOVE_NONE && k < PLY_MAX; k++)
                        std::cout << rml.get_move_pv(j, k) << " ";

                    std::cout << std::endl;
                }
                alpha = rml.get_move_score(Min(i, MultiPV-1));
            }
        }
    }
    return alpha;
  }


  // search_pv() is the main search function for PV nodes.

  Value search_pv(Position &pos, SearchStack ss[], Value alpha, Value beta,
                  Depth depth, int ply, int threadID) {

    assert(alpha >= -VALUE_INFINITE && alpha <= VALUE_INFINITE);
    assert(beta > alpha && beta <= VALUE_INFINITE);
    assert(ply >= 0 && ply < PLY_MAX);
    assert(threadID >= 0 && threadID < ActiveThreads);

    // Initialize, and make an early exit in case of an aborted search,
    // an instant draw, maximum ply reached, etc.
    if (AbortSearch || thread_should_stop(threadID))
        return Value(0);

    if (depth < OnePly)
        return qsearch(pos, ss, alpha, beta, Depth(0), ply, threadID);

    init_node(pos, ss, ply, threadID);

    if (pos.is_draw())
        return VALUE_DRAW;

    EvalInfo ei;

    if (ply >= PLY_MAX - 1)
        return evaluate(pos, ei, threadID);

    // Mate distance pruning
    Value oldAlpha = alpha;
    alpha = Max(value_mated_in(ply), alpha);
    beta = Min(value_mate_in(ply+1), beta);
    if (alpha >= beta)
        return alpha;

    // Transposition table lookup. At PV nodes, we don't use the TT for
    // pruning, but only for move ordering.
    const TTEntry* tte = TT.retrieve(pos);
    Move ttMove = (tte ? tte->move() : MOVE_NONE);

    // Go with internal iterative deepening if we don't have a TT move
    if (UseIIDAtPVNodes && ttMove == MOVE_NONE && depth >= 5*OnePly)
    {
        search_pv(pos, ss, alpha, beta, depth-2*OnePly, ply, threadID);
        ttMove = ss[ply].pv[ply];
    }

    // Initialize a MovePicker object for the current position, and prepare
    // to search all moves
    MovePicker mp = MovePicker(pos, true, ttMove, ss[ply].mateKiller,
                               ss[ply].killer1, ss[ply].killer2, depth);

    Move move, movesSearched[256];
    int moveCount = 0;
    Value value, bestValue = -VALUE_INFINITE;
    Bitboard dcCandidates = mp.discovered_check_candidates();
    bool isCheck = pos.is_check();
    bool mateThreat =   MateThreatExtension[1] > Depth(0)
                     && pos.has_mate_threat(opposite_color(pos.side_to_move()));

    // Loop through all legal moves until no moves remain or a beta cutoff
    // occurs.
    while (   alpha < beta
           && (move = mp.get_next_move()) != MOVE_NONE
           && !thread_should_stop(threadID))
    {
      assert(move_is_ok(move));

      bool singleReply = (isCheck && mp.number_of_moves() == 1);
      bool moveIsCheck = pos.move_is_check(move, dcCandidates);
      bool moveIsCapture = pos.move_is_capture(move);
      bool moveIsPassedPawnPush = pos.move_is_passed_pawn_push(move);

      movesSearched[moveCount++] = ss[ply].currentMove = move;

      if (moveIsCapture)
          ss[ply].currentMoveCaptureValue = pos.midgame_value_of_piece_on(move_to(move));
      else if (move_is_ep(move))
          ss[ply].currentMoveCaptureValue = PawnValueMidgame;
      else
          ss[ply].currentMoveCaptureValue = Value(0);

      // Decide the new search depth
      Depth ext = extension(pos, move, true, moveIsCheck, singleReply, mateThreat);
      Depth newDepth = depth - OnePly + ext;

      // Make and search the move
      UndoInfo u;
      pos.do_move(move, u, dcCandidates);

      if (moveCount == 1) // The first move in list is the PV
          value = -search_pv(pos, ss, -beta, -alpha, newDepth, ply+1, threadID);
      else
      {
        // Try to reduce non-pv search depth by one ply if move seems not problematic,
        // if the move fails high will be re-searched at full depth.
        if (    depth >= 2*OnePly
            &&  ext == Depth(0)
            &&  moveCount >= LMRPVMoves
            && !moveIsCapture
            && !move_promotion(move)
            && !moveIsPassedPawnPush
            && !move_is_castle(move)
            &&  move != ss[ply].killer1
            &&  move != ss[ply].killer2)
        {
            ss[ply].reduction = OnePly;
            value = -search(pos, ss, -alpha, newDepth-OnePly, ply+1, true, threadID);
        }
        else
            value = alpha + 1; // Just to trigger next condition

        if (value > alpha) // Go with full depth pv search
        {
            ss[ply].reduction = Depth(0);
            value = -search(pos, ss, -alpha, newDepth, ply+1, true, threadID);
            if (value > alpha && value < beta)
            {
                // When the search fails high at ply 1 while searching the first
                // move at the root, set the flag failHighPly1. This is used for
                // time managment:  We don't want to stop the search early in
                // such cases, because resolving the fail high at ply 1 could
                // result in a big drop in score at the root.
                if (ply == 1 && RootMoveNumber == 1)
                    Threads[threadID].failHighPly1 = true;

                // A fail high occurred. Re-search at full window (pv search)
                value = -search_pv(pos, ss, -beta, -alpha, newDepth, ply+1, threadID);
                Threads[threadID].failHighPly1 = false;
          }
        }
      }
      pos.undo_move(move, u);

      assert(value > -VALUE_INFINITE && value < VALUE_INFINITE);

      // New best move?
      if (value > bestValue)
      {
          bestValue = value;
          if (value > alpha)
          {
              alpha = value;
              update_pv(ss, ply);
              if (value == value_mate_in(ply + 1))
                  ss[ply].mateKiller = move;
          }
          // If we are at ply 1, and we are searching the first root move at
          // ply 0, set the 'Problem' variable if the score has dropped a lot
          // (from the computer's point of view) since the previous iteration:
          if (Iteration >= 2 && -value <= ValueByIteration[Iteration-1] - ProblemMargin)
              Problem = true;
      }

      // Split?
      if (   ActiveThreads > 1
          && bestValue < beta
          && depth >= MinimumSplitDepth
          && Iteration <= 99
          && idle_thread_exists(threadID)
          && !AbortSearch
          && !thread_should_stop(threadID)
          && split(pos, ss, ply, &alpha, &beta, &bestValue, depth,
                   &moveCount, &mp, dcCandidates, threadID, true))
          break;
    }

    // All legal moves have been searched.  A special case: If there were
    // no legal moves, it must be mate or stalemate:
    if (moveCount == 0)
        return (isCheck ? value_mated_in(ply) : VALUE_DRAW);

    // If the search is not aborted, update the transposition table,
    // history counters, and killer moves.
    if (AbortSearch || thread_should_stop(threadID))
        return bestValue;

    if (bestValue <= oldAlpha)
        TT.store(pos, value_to_tt(bestValue, ply), depth, MOVE_NONE, VALUE_TYPE_UPPER);

    else if (bestValue >= beta)
    {
        Move m = ss[ply].pv[ply];
        if (ok_to_history(pos, m)) // Only non capture moves are considered
        {
            update_history(pos, m, depth, movesSearched, moveCount);
            if (m != ss[ply].killer1)
            {
                ss[ply].killer2 = ss[ply].killer1;
                ss[ply].killer1 = m;
            }
        }
        TT.store(pos, value_to_tt(bestValue, ply), depth, m, VALUE_TYPE_LOWER);
    }
    else
        TT.store(pos, value_to_tt(bestValue, ply), depth, ss[ply].pv[ply], VALUE_TYPE_EXACT);

    return bestValue;
  }


  // search() is the search function for zero-width nodes.

  Value search(Position &pos, SearchStack ss[], Value beta, Depth depth,
               int ply, bool allowNullmove, int threadID) {

    assert(beta >= -VALUE_INFINITE && beta <= VALUE_INFINITE);
    assert(ply >= 0 && ply < PLY_MAX);
    assert(threadID >= 0 && threadID < ActiveThreads);

    EvalInfo ei;

    // Initialize, and make an early exit in case of an aborted search,
    // an instant draw, maximum ply reached, etc.
    if (AbortSearch || thread_should_stop(threadID))
        return Value(0);

    if (depth < OnePly)
        return qsearch(pos, ss, beta-1, beta, Depth(0), ply, threadID);

    init_node(pos, ss, ply, threadID);

    if (pos.is_draw())
        return VALUE_DRAW;

    if (ply >= PLY_MAX - 1)
        return evaluate(pos, ei, threadID);

    // Mate distance pruning
    if (value_mated_in(ply) >= beta)
        return beta;

    if (value_mate_in(ply + 1) < beta)
        return beta - 1;

    // Transposition table lookup
    const TTEntry* tte = TT.retrieve(pos);
    Move ttMove = (tte ? tte->move() : MOVE_NONE);

    if (tte && ok_to_use_TT(tte, depth, beta, ply))
    {
        ss[ply].currentMove = ttMove; // can be MOVE_NONE ?
        return value_from_tt(tte->value(), ply);
    }

    Value approximateEval = quick_evaluate(pos);
    bool mateThreat = false;
    bool isCheck = pos.is_check();

    // Null move search
    if (    allowNullmove
        && !isCheck
        &&  ok_to_do_nullmove(pos)
        &&  approximateEval >= beta - NullMoveMargin)
    {
        ss[ply].currentMove = MOVE_NULL;

        UndoInfo u;
        pos.do_null_move(u);
        Value nullValue = -search(pos, ss, -(beta-1), depth-4*OnePly, ply+1, false, threadID);
        pos.undo_null_move(u);

        if (nullValue >= beta)
        {
            if (depth < 6 * OnePly)
                return beta;

            // Do zugzwang verification search
            Value v = search(pos, ss, beta, depth-5*OnePly, ply, false, threadID);
            if (v >= beta)
                return beta;
        } else {
            // The null move failed low, which means that we may be faced with
            // some kind of threat.  If the previous move was reduced, check if
            // the move that refuted the null move was somehow connected to the
            // move which was reduced.  If a connection is found, return a fail
            // low score (which will cause the reduced move to fail high in the
            // parent node, which will trigger a re-search with full depth).
            if (nullValue == value_mated_in(ply + 2))
                mateThreat = true;

            ss[ply].threatMove = ss[ply + 1].currentMove;
            if (   depth < ThreatDepth
                && ss[ply - 1].reduction
                && connected_moves(pos, ss[ply - 1].currentMove, ss[ply].threatMove))
                return beta - 1;
        }
    }
    // Null move search not allowed, try razoring
    else if (  (approximateEval < beta - RazorMargin && depth < RazorDepth)
             ||(approximateEval < beta - PawnValueMidgame && depth <= OnePly))
    {
        Value v = qsearch(pos, ss, beta-1, beta, Depth(0), ply, threadID);
        if (v < beta)
            return v;
    }

    // Go with internal iterative deepening if we don't have a TT move
    if (UseIIDAtNonPVNodes && ttMove == MOVE_NONE && depth >= 8*OnePly &&
        evaluate(pos, ei, threadID) >= beta - IIDMargin)
    {
        search(pos, ss, beta, Min(depth/2, depth-2*OnePly), ply, false, threadID);
        ttMove = ss[ply].pv[ply];
    }

    // Initialize a MovePicker object for the current position, and prepare
    // to search all moves:
    MovePicker mp = MovePicker(pos, false, ttMove, ss[ply].mateKiller,
                               ss[ply].killer1, ss[ply].killer2, depth);

    Move move, movesSearched[256];
    int moveCount = 0;
    Value value, bestValue = -VALUE_INFINITE;
    Bitboard dcCandidates = mp.discovered_check_candidates();
    Value futilityValue = VALUE_NONE;
    bool useFutilityPruning =   UseFutilityPruning
                             && depth < SelectiveDepth
                             && !isCheck;

    // Loop through all legal moves until no moves remain or a beta cutoff
    // occurs.
    while (   bestValue < beta
           && (move = mp.get_next_move()) != MOVE_NONE
           && !thread_should_stop(threadID))
    {
      assert(move_is_ok(move));

      bool singleReply = (isCheck && mp.number_of_moves() == 1);
      bool moveIsCheck = pos.move_is_check(move, dcCandidates);
      bool moveIsCapture = pos.move_is_capture(move);
      bool moveIsPassedPawnPush = pos.move_is_passed_pawn_push(move);

      movesSearched[moveCount++] = ss[ply].currentMove = move;

      // Decide the new search depth
      Depth ext = extension(pos, move, false, moveIsCheck, singleReply, mateThreat);
      Depth newDepth = depth - OnePly + ext;

      // Futility pruning
      if (    useFutilityPruning
          &&  ext == Depth(0)
          && !moveIsCapture
          && !moveIsPassedPawnPush
          && !move_promotion(move))
      {
          if (   moveCount >= 2 + int(depth)
              && ok_to_prune(pos, move, ss[ply].threatMove, depth))
              continue;

          if (depth < 3 * OnePly && approximateEval < beta)
          {
              if (futilityValue == VALUE_NONE)
                  futilityValue =  evaluate(pos, ei, threadID)
                                + (depth < 2 * OnePly ? FutilityMargin1 : FutilityMargin2);

              if (futilityValue < beta)
              {
                  if (futilityValue > bestValue)
                      bestValue = futilityValue;
                  continue;
              }
          }
      }

      // Make and search the move
      UndoInfo u;
      pos.do_move(move, u, dcCandidates);

      // Try to reduce non-pv search depth by one ply if move seems not problematic,
      // if the move fails high will be re-searched at full depth.
      if (   depth >= 2*OnePly
          && ext == Depth(0)
          && moveCount >= LMRNonPVMoves
          && !moveIsCapture
          && !move_promotion(move)
          && !moveIsPassedPawnPush
          && !move_is_castle(move)
          &&  move != ss[ply].killer1
          &&  move != ss[ply].killer2)
      {
          ss[ply].reduction = OnePly;
          value = -search(pos, ss, -(beta-1), newDepth-OnePly, ply+1, true, threadID);
      }
      else
        value = beta; // Just to trigger next condition

      if (value >= beta) // Go with full depth non-pv search
      {
          ss[ply].reduction = Depth(0);
          value = -search(pos, ss, -(beta-1), newDepth, ply+1, true, threadID);
      }
      pos.undo_move(move, u);

      assert(value > -VALUE_INFINITE && value < VALUE_INFINITE);

      // New best move?
      if (value > bestValue)
      {
        bestValue = value;
        if (value >= beta)
            update_pv(ss, ply);

        if (value == value_mate_in(ply + 1))
            ss[ply].mateKiller = move;
      }

      // Split?
      if (   ActiveThreads > 1
          && bestValue < beta
          && depth >= MinimumSplitDepth
          && Iteration <= 99
          && idle_thread_exists(threadID)
          && !AbortSearch
          && !thread_should_stop(threadID)
          && split(pos, ss, ply, &beta, &beta, &bestValue, depth, &moveCount,
                   &mp, dcCandidates, threadID, false))
        break;
    }

    // All legal moves have been searched.  A special case: If there were
    // no legal moves, it must be mate or stalemate.
    if (moveCount == 0)
        return (pos.is_check() ? value_mated_in(ply) : VALUE_DRAW);

    // If the search is not aborted, update the transposition table,
    // history counters, and killer moves.
    if (AbortSearch || thread_should_stop(threadID))
        return bestValue;

    if (bestValue < beta)
        TT.store(pos, value_to_tt(bestValue, ply), depth, MOVE_NONE, VALUE_TYPE_UPPER);
    else
    {
        Move m = ss[ply].pv[ply];
        if (ok_to_history(pos, m)) // Only non capture moves are considered
        {
            update_history(pos, m, depth, movesSearched, moveCount);
            if (m != ss[ply].killer1)
            {
                ss[ply].killer2 = ss[ply].killer1;
                ss[ply].killer1 = m;
            }
        }
        TT.store(pos, value_to_tt(bestValue, ply), depth, m, VALUE_TYPE_LOWER);
    }
    return bestValue;
  }


  // qsearch() is the quiescence search function, which is called by the main
  // search function when the remaining depth is zero (or, to be more precise,
  // less than OnePly).

  Value qsearch(Position &pos, SearchStack ss[], Value alpha, Value beta,
                Depth depth, int ply, int threadID) {

    assert(alpha >= -VALUE_INFINITE && alpha <= VALUE_INFINITE);
    assert(beta >= -VALUE_INFINITE && beta <= VALUE_INFINITE);
    assert(depth <= 0);
    assert(ply >= 0 && ply < PLY_MAX);
    assert(threadID >= 0 && threadID < ActiveThreads);

    EvalInfo ei;

    // Initialize, and make an early exit in case of an aborted search,
    // an instant draw, maximum ply reached, etc.
    if (AbortSearch || thread_should_stop(threadID))
        return Value(0);

    init_node(pos, ss, ply, threadID);

    if (pos.is_draw())
        return VALUE_DRAW;

    // Transposition table lookup
    const TTEntry* tte = TT.retrieve(pos);
    if (tte && ok_to_use_TT(tte, depth, beta, ply))
        return value_from_tt(tte->value(), ply);

    // Evaluate the position statically
    Value staticValue = evaluate(pos, ei, threadID);

    if (ply == PLY_MAX - 1)
        return staticValue;

    // Initialize "stand pat score", and return it immediately if it is
    // at least beta.
    Value bestValue = (pos.is_check() ? -VALUE_INFINITE : staticValue);

    if (bestValue >= beta)
        return bestValue;

    if (bestValue > alpha)
        alpha = bestValue;

    // Initialize a MovePicker object for the current position, and prepare
    // to search the moves.  Because the depth is <= 0 here, only captures,
    // queen promotions and checks (only if depth == 0) will be generated.
    MovePicker mp = MovePicker(pos, false, MOVE_NONE, MOVE_NONE, MOVE_NONE,
                               MOVE_NONE, depth);
    Move move;
    int moveCount = 0;
    Bitboard dcCandidates = mp.discovered_check_candidates();
    bool isCheck = pos.is_check();

    // Loop through the moves until no moves remain or a beta cutoff
    // occurs.
    while (   alpha < beta
           && (move = mp.get_next_move()) != MOVE_NONE)
    {
      assert(move_is_ok(move));

      bool moveIsCheck = pos.move_is_check(move, dcCandidates);
      bool moveIsPassedPawnPush = pos.move_is_passed_pawn_push(move);

      moveCount++;
      ss[ply].currentMove = move;

      // Futility pruning
      if (    UseQSearchFutilityPruning
          && !isCheck
          && !moveIsCheck
          && !move_promotion(move)
          && !moveIsPassedPawnPush
          &&  beta - alpha == 1
          &&  pos.non_pawn_material(pos.side_to_move()) > RookValueMidgame)
      {
          Value futilityValue = staticValue
                              + Max(pos.midgame_value_of_piece_on(move_to(move)),
                                    pos.endgame_value_of_piece_on(move_to(move)))
                              + FutilityMargin0
                              + ei.futilityMargin;

          if (futilityValue < alpha)
          {
              if (futilityValue > bestValue)
                  bestValue = futilityValue;
              continue;
          }
      }

      // Don't search captures and checks with negative SEE values.
      if (   !isCheck
          && !move_promotion(move)
          && (pos.midgame_value_of_piece_on(move_from(move)) >
              pos.midgame_value_of_piece_on(move_to(move)))
          &&  pos.see(move) < 0)
          continue;

      // Make and search the move.
      UndoInfo u;
      pos.do_move(move, u, dcCandidates);
      Value value = -qsearch(pos, ss, -beta, -alpha, depth-OnePly, ply+1, threadID);
      pos.undo_move(move, u);

      assert(value > -VALUE_INFINITE && value < VALUE_INFINITE);

      // New best move?
      if (value > bestValue)
      {
          bestValue = value;
          if (value > alpha)
          {
              alpha = value;
              update_pv(ss, ply);
          }
       }
    }

    // All legal moves have been searched.  A special case: If we're in check
    // and no legal moves were found, it is checkmate:
    if (pos.is_check() && moveCount == 0) // Mate!
        return value_mated_in(ply);

    assert(bestValue > -VALUE_INFINITE && bestValue < VALUE_INFINITE);

    // Update transposition table
    TT.store(pos, value_to_tt(bestValue, ply), depth, MOVE_NONE, VALUE_TYPE_EXACT);

    return bestValue;
  }


  // sp_search() is used to search from a split point.  This function is called
  // by each thread working at the split point.  It is similar to the normal
  // search() function, but simpler.  Because we have already probed the hash
  // table, done a null move search, and searched the first move before
  // splitting, we don't have to repeat all this work in sp_search().  We
  // also don't need to store anything to the hash table here:  This is taken
  // care of after we return from the split point.

  void sp_search(SplitPoint *sp, int threadID) {

    assert(threadID >= 0 && threadID < ActiveThreads);
    assert(ActiveThreads > 1);

    Position pos = Position(sp->pos);
    SearchStack *ss = sp->sstack[threadID];
    Value value;
    Move move;
    bool isCheck = pos.is_check();
    bool useFutilityPruning =    UseFutilityPruning
                              && sp->depth < SelectiveDepth
                              && !isCheck;

    while (    sp->bestValue < sp->beta
           && !thread_should_stop(threadID)
           && (move = sp->mp->get_next_move(sp->lock)) != MOVE_NONE)
    {
      assert(move_is_ok(move));

      bool moveIsCheck = pos.move_is_check(move, sp->dcCandidates);
      bool moveIsCapture = pos.move_is_capture(move);
      bool moveIsPassedPawnPush = pos.move_is_passed_pawn_push(move);

      lock_grab(&(sp->lock));
      int moveCount = ++sp->moves;
      lock_release(&(sp->lock));

      ss[sp->ply].currentMove = move;

      // Decide the new search depth.
      Depth ext = extension(pos, move, false, moveIsCheck, false, false);
      Depth newDepth = sp->depth - OnePly + ext;

      // Prune?
      if (    useFutilityPruning
          &&  ext == Depth(0)
          && !moveIsCapture
          && !moveIsPassedPawnPush
          && !move_promotion(move)
          &&  moveCount >= 2 + int(sp->depth)
          &&  ok_to_prune(pos, move, ss[sp->ply].threatMove, sp->depth))
        continue;

      // Make and search the move.
      UndoInfo u;
      pos.do_move(move, u, sp->dcCandidates);

      // Try to reduce non-pv search depth by one ply if move seems not problematic,
      // if the move fails high will be re-searched at full depth.
      if (    ext == Depth(0)
          &&  moveCount >= LMRNonPVMoves
          && !moveIsCapture
          && !moveIsPassedPawnPush
          && !move_promotion(move)
          && !move_is_castle(move)
          &&  move != ss[sp->ply].killer1
          &&  move != ss[sp->ply].killer2)
      {
          ss[sp->ply].reduction = OnePly;
          value = -search(pos, ss, -(sp->beta-1), newDepth - OnePly, sp->ply+1, true, threadID);
      }
      else
          value = sp->beta; // Just to trigger next condition

      if (value >= sp->beta) // Go with full depth non-pv search
      {
          ss[sp->ply].reduction = Depth(0);
          value = -search(pos, ss, -(sp->beta - 1), newDepth, sp->ply+1, true, threadID);
      }
      pos.undo_move(move, u);

      assert(value > -VALUE_INFINITE && value < VALUE_INFINITE);

      if (thread_should_stop(threadID))
          break;

      // New best move?
      lock_grab(&(sp->lock));
      if (value > sp->bestValue && !thread_should_stop(threadID))
      {
          sp->bestValue = value;
          if (sp->bestValue >= sp->beta)
          {
              sp_update_pv(sp->parentSstack, ss, sp->ply);
              for (int i = 0; i < ActiveThreads; i++)
                  if (i != threadID && (i == sp->master || sp->slaves[i]))
                      Threads[i].stop = true;

              sp->finished = true;
        }
      }
      lock_release(&(sp->lock));
    }

    lock_grab(&(sp->lock));

    // If this is the master thread and we have been asked to stop because of
    // a beta cutoff higher up in the tree, stop all slave threads:
    if (sp->master == threadID && thread_should_stop(threadID))
        for (int i = 0; i < ActiveThreads; i++)
            if (sp->slaves[i])
                Threads[i].stop = true;

    sp->cpus--;
    sp->slaves[threadID] = 0;

    lock_release(&(sp->lock));
  }


  // sp_search_pv() is used to search from a PV split point.  This function
  // is called by each thread working at the split point.  It is similar to
  // the normal search_pv() function, but simpler.  Because we have already
  // probed the hash table and searched the first move before splitting, we
  // don't have to repeat all this work in sp_search_pv().  We also don't
  // need to store anything to the hash table here:  This is taken care of
  // after we return from the split point.

  void sp_search_pv(SplitPoint *sp, int threadID) {

    assert(threadID >= 0 && threadID < ActiveThreads);
    assert(ActiveThreads > 1);

    Position pos = Position(sp->pos);
    SearchStack *ss = sp->sstack[threadID];
    Value value;
    Move move;

    while (    sp->alpha < sp->beta
           && !thread_should_stop(threadID)
           && (move = sp->mp->get_next_move(sp->lock)) != MOVE_NONE)
    {
      bool moveIsCheck = pos.move_is_check(move, sp->dcCandidates);
      bool moveIsCapture = pos.move_is_capture(move);
      bool moveIsPassedPawnPush = pos.move_is_passed_pawn_push(move);

      assert(move_is_ok(move));

      ss[sp->ply].currentMoveCaptureValue = move_is_ep(move)?
        PawnValueMidgame : pos.midgame_value_of_piece_on(move_to(move));

      lock_grab(&(sp->lock));
      int moveCount = ++sp->moves;
      lock_release(&(sp->lock));

      ss[sp->ply].currentMove = move;

      // Decide the new search depth.
      Depth ext = extension(pos, move, true, moveIsCheck, false, false);
      Depth newDepth = sp->depth - OnePly + ext;

      // Make and search the move.
      UndoInfo u;
      pos.do_move(move, u, sp->dcCandidates);

      // Try to reduce non-pv search depth by one ply if move seems not problematic,
      // if the move fails high will be re-searched at full depth.
      if (    ext == Depth(0)
          &&  moveCount >= LMRPVMoves
          && !moveIsCapture
          && !moveIsPassedPawnPush
          && !move_promotion(move)
          && !move_is_castle(move)
          &&  move != ss[sp->ply].killer1
          &&  move != ss[sp->ply].killer2)
      {
          ss[sp->ply].reduction = OnePly;
          value = -search(pos, ss, -sp->alpha, newDepth - OnePly, sp->ply+1, true, threadID);
      }
      else
          value = sp->alpha + 1; // Just to trigger next condition

      if (value > sp->alpha) // Go with full depth non-pv search
      {
          ss[sp->ply].reduction = Depth(0);
          value = -search(pos, ss, -sp->alpha, newDepth, sp->ply+1, true, threadID);

          if (value > sp->alpha && value < sp->beta)
          {
              // When the search fails high at ply 1 while searching the first
              // move at the root, set the flag failHighPly1.  This is used for
              // time managment:  We don't want to stop the search early in
              // such cases, because resolving the fail high at ply 1 could
              // result in a big drop in score at the root.
              if (sp->ply == 1 && RootMoveNumber == 1)
                  Threads[threadID].failHighPly1 = true;

              value = -search_pv(pos, ss, -sp->beta, -sp->alpha, newDepth, sp->ply+1, threadID);
              Threads[threadID].failHighPly1 = false;
        }
      }
      pos.undo_move(move, u);

      assert(value > -VALUE_INFINITE && value < VALUE_INFINITE);

      if (thread_should_stop(threadID))
          break;

      // New best move?
      lock_grab(&(sp->lock));
      if (value > sp->bestValue && !thread_should_stop(threadID))
      {
          sp->bestValue = value;
          if (value > sp->alpha)
          {
              sp->alpha = value;
              sp_update_pv(sp->parentSstack, ss, sp->ply);
              if (value == value_mate_in(sp->ply + 1))
                  ss[sp->ply].mateKiller = move;

              if(value >= sp->beta)
              {
                  for(int i = 0; i < ActiveThreads; i++)
                      if(i != threadID && (i == sp->master || sp->slaves[i]))
                          Threads[i].stop = true;

                  sp->finished = true;
              }
        }
        // If we are at ply 1, and we are searching the first root move at
        // ply 0, set the 'Problem' variable if the score has dropped a lot
        // (from the computer's point of view) since the previous iteration:
        if (Iteration >= 2 && -value <= ValueByIteration[Iteration-1] - ProblemMargin)
            Problem = true;
      }
      lock_release(&(sp->lock));
    }

    lock_grab(&(sp->lock));

    // If this is the master thread and we have been asked to stop because of
    // a beta cutoff higher up in the tree, stop all slave threads:
    if (sp->master == threadID && thread_should_stop(threadID))
        for (int i = 0; i < ActiveThreads; i++)
            if (sp->slaves[i])
                Threads[i].stop = true;

    sp->cpus--;
    sp->slaves[threadID] = 0;

    lock_release(&(sp->lock));
  }


  /// The RootMove class

  // Constructor

  RootMove::RootMove() {
    nodes = cumulativeNodes = 0ULL;
  }

  // RootMove::operator<() is the comparison function used when
  // sorting the moves.  A move m1 is considered to be better
  // than a move m2 if it has a higher score, or if the moves
  // have equal score but m1 has the higher node count.

  bool RootMove::operator<(const RootMove& m) {

    if (score != m.score)
        return (score < m.score);

    return nodes <= m.nodes;
  }

  /// The RootMoveList class

  // Constructor

  RootMoveList::RootMoveList(Position& pos, Move searchMoves[]) : count(0) {

    MoveStack mlist[MaxRootMoves];
    bool includeAllMoves = (searchMoves[0] == MOVE_NONE);

    // Generate all legal moves
    int lm_count = generate_legal_moves(pos, mlist);

    // Add each move to the moves[] array
    for (int i = 0; i < lm_count; i++)
    {
        bool includeMove = includeAllMoves;

        for (int k = 0; !includeMove && searchMoves[k] != MOVE_NONE; k++)
            includeMove = (searchMoves[k] == mlist[i].move);

        if (includeMove)
        {
            // Find a quick score for the move
            UndoInfo u;
            SearchStack ss[PLY_MAX_PLUS_2];

            moves[count].move = mlist[i].move;
            moves[count].nodes = 0ULL;
            pos.do_move(moves[count].move, u);
            moves[count].score = -qsearch(pos, ss, -VALUE_INFINITE, VALUE_INFINITE,
                                          Depth(0), 1, 0);
            pos.undo_move(moves[count].move, u);
            moves[count].pv[0] = moves[i].move;
            moves[count].pv[1] = MOVE_NONE; // FIXME
            count++;
        }
    }
    sort();
  }


  // Simple accessor methods for the RootMoveList class

  inline Move RootMoveList::get_move(int moveNum) const {
    return moves[moveNum].move;
  }

  inline Value RootMoveList::get_move_score(int moveNum) const {
    return moves[moveNum].score;
  }

  inline void RootMoveList::set_move_score(int moveNum, Value score) {
    moves[moveNum].score = score;
  }

  inline void RootMoveList::set_move_nodes(int moveNum, int64_t nodes) {
    moves[moveNum].nodes = nodes;
    moves[moveNum].cumulativeNodes += nodes;
  }

  void RootMoveList::set_move_pv(int moveNum, const Move pv[]) {
    int j;
    for(j = 0; pv[j] != MOVE_NONE; j++)
      moves[moveNum].pv[j] = pv[j];
    moves[moveNum].pv[j] = MOVE_NONE;
  }

  inline Move RootMoveList::get_move_pv(int moveNum, int i) const {
    return moves[moveNum].pv[i];
  }

  inline int64_t RootMoveList::get_move_cumulative_nodes(int moveNum) const {
    return moves[moveNum].cumulativeNodes;
  }

  inline int RootMoveList::move_count() const {
    return count;
  }


  // RootMoveList::scan_for_easy_move() is called at the end of the first
  // iteration, and is used to detect an "easy move", i.e. a move which appears
  // to be much bester than all the rest.  If an easy move is found, the move
  // is returned, otherwise the function returns MOVE_NONE.  It is very
  // important that this function is called at the right moment:  The code
  // assumes that the first iteration has been completed and the moves have
  // been sorted. This is done in RootMoveList c'tor.

  Move RootMoveList::scan_for_easy_move() const {

    assert(count);

    if (count == 1)
        return get_move(0);

    // moves are sorted so just consider the best and the second one
    if (get_move_score(0) > get_move_score(1) + EasyMoveMargin)
        return get_move(0);

    return MOVE_NONE;
  }

  // RootMoveList::sort() sorts the root move list at the beginning of a new
  // iteration.

  inline void RootMoveList::sort() {

    sort_multipv(count - 1); // all items
  }


  // RootMoveList::sort_multipv() sorts the first few moves in the root move
  // list by their scores and depths. It is used to order the different PVs
  // correctly in MultiPV mode.

  void RootMoveList::sort_multipv(int n) {

    for (int i = 1; i <= n; i++)
    {
      RootMove rm = moves[i];
      int j;
      for (j = i; j > 0 && moves[j-1] < rm; j--)
          moves[j] = moves[j-1];
      moves[j] = rm;
    }
  }


  // init_search_stack() initializes a search stack at the beginning of a
  // new search from the root.

  void init_search_stack(SearchStack ss[]) {
    for(int i = 0; i < 3; i++) {
      ss[i].pv[i] = MOVE_NONE;
      ss[i].pv[i+1] = MOVE_NONE;
      ss[i].currentMove = MOVE_NONE;
      ss[i].mateKiller = MOVE_NONE;
      ss[i].killer1 = MOVE_NONE;
      ss[i].killer2 = MOVE_NONE;
      ss[i].threatMove = MOVE_NONE;
      ss[i].reduction = Depth(0);
    }
  }


  // init_node() is called at the beginning of all the search functions
  // (search(), search_pv(), qsearch(), and so on) and initializes the search
  // stack object corresponding to the current node.  Once every
  // NodesBetweenPolls nodes, init_node() also calls poll(), which polls
  // for user input and checks whether it is time to stop the search.

  void init_node(const Position &pos, SearchStack ss[], int ply, int threadID) {
    assert(ply >= 0 && ply < PLY_MAX);
    assert(threadID >= 0 && threadID < ActiveThreads);

    Threads[threadID].nodes++;

    if(threadID == 0) {
      NodesSincePoll++;
      if(NodesSincePoll >= NodesBetweenPolls) {
        poll();
        NodesSincePoll = 0;
      }
    }

    ss[ply].pv[ply] = ss[ply].pv[ply+1] = ss[ply].currentMove = MOVE_NONE;
    ss[ply+2].mateKiller = MOVE_NONE;
    ss[ply+2].killer1 = ss[ply+2].killer2 = MOVE_NONE;
    ss[ply].threatMove = MOVE_NONE;
    ss[ply].reduction = Depth(0);
    ss[ply].currentMoveCaptureValue = Value(0);

    if(Threads[threadID].printCurrentLine)
      print_current_line(ss, ply, threadID);
  }


  // update_pv() is called whenever a search returns a value > alpha.  It
  // updates the PV in the SearchStack object corresponding to the current
  // node.

  void update_pv(SearchStack ss[], int ply) {
    assert(ply >= 0 && ply < PLY_MAX);

    ss[ply].pv[ply] = ss[ply].currentMove;
    int p;
    for(p = ply + 1; ss[ply+1].pv[p] != MOVE_NONE; p++)
      ss[ply].pv[p] = ss[ply+1].pv[p];
    ss[ply].pv[p] = MOVE_NONE;
  }


  // sp_update_pv() is a variant of update_pv for use at split points.  The
  // difference between the two functions is that sp_update_pv also updates
  // the PV at the parent node.

  void sp_update_pv(SearchStack *pss, SearchStack ss[], int ply) {
    assert(ply >= 0 && ply < PLY_MAX);

    ss[ply].pv[ply] = pss[ply].pv[ply] = ss[ply].currentMove;
    int p;
    for(p = ply + 1; ss[ply+1].pv[p] != MOVE_NONE; p++)
      ss[ply].pv[p] = pss[ply].pv[p] = ss[ply+1].pv[p];
    ss[ply].pv[p] = pss[ply].pv[p] = MOVE_NONE;
  }


  // connected_moves() tests whether two moves are 'connected' in the sense
  // that the first move somehow made the second move possible (for instance
  // if the moving piece is the same in both moves).  The first move is
  // assumed to be the move that was made to reach the current position, while
  // the second move is assumed to be a move from the current position.

  bool connected_moves(const Position &pos, Move m1, Move m2) {
    Square f1, t1, f2, t2;

    assert(move_is_ok(m1));
    assert(move_is_ok(m2));

    if(m2 == MOVE_NONE)
      return false;

    // Case 1: The moving piece is the same in both moves.
    f2 = move_from(m2);
    t1 = move_to(m1);
    if(f2 == t1)
      return true;

    // Case 2: The destination square for m2 was vacated by m1.
    t2 = move_to(m2);
    f1 = move_from(m1);
    if(t2 == f1)
      return true;

    // Case 3: Moving through the vacated square:
    if(piece_is_slider(pos.piece_on(f2)) &&
       bit_is_set(squares_between(f2, t2), f1))
      return true;

    // Case 4: The destination square for m2 is attacked by the moving piece
    // in m1:
    if(pos.piece_attacks_square(t1, t2))
      return true;

    // Case 5: Discovered check, checking piece is the piece moved in m1:
    if(piece_is_slider(pos.piece_on(t1)) &&
       bit_is_set(squares_between(t1, pos.king_square(pos.side_to_move())),
                  f2) &&
       !bit_is_set(squares_between(t2, pos.king_square(pos.side_to_move())),
                   t2)) {
      Bitboard occ = pos.occupied_squares();
      Color us = pos.side_to_move();
      Square ksq = pos.king_square(us);
      clear_bit(&occ, f2);
      if(pos.type_of_piece_on(t1) == BISHOP) {
        if(bit_is_set(bishop_attacks_bb(ksq, occ), t1))
          return true;
      }
      else if(pos.type_of_piece_on(t1) == ROOK) {
        if(bit_is_set(rook_attacks_bb(ksq, occ), t1))
          return true;
      }
      else {
        assert(pos.type_of_piece_on(t1) == QUEEN);
        if(bit_is_set(queen_attacks_bb(ksq, occ), t1))
          return true;
      }
    }

    return false;
  }


  // extension() decides whether a move should be searched with normal depth,
  // or with extended depth.  Certain classes of moves (checking moves, in
  // particular) are searched with bigger depth than ordinary moves.

  Depth extension(const Position &pos, Move m, bool pvNode,
                  bool check, bool singleReply, bool mateThreat) {

    Depth result = Depth(0);

    if (check)
        result += CheckExtension[pvNode];

    if (singleReply)
        result += SingleReplyExtension[pvNode];

    if (pos.move_is_pawn_push_to_7th(m))
        result += PawnPushTo7thExtension[pvNode];

    if (pos.move_is_passed_pawn_push(m))
        result += PassedPawnExtension[pvNode];

    if (mateThreat)
        result += MateThreatExtension[pvNode];

    if (   pos.midgame_value_of_piece_on(move_to(m)) >= RookValueMidgame
        && (  pos.non_pawn_material(WHITE) + pos.non_pawn_material(BLACK)
            - pos.midgame_value_of_piece_on(move_to(m)) == Value(0))
        && !move_promotion(m))
        result += PawnEndgameExtension[pvNode];
    
    if (   pvNode
        && pos.move_is_capture(m)
        && pos.type_of_piece_on(move_to(m)) != PAWN
        && pos.see(m) >= 0)
        result += OnePly/2;

    return Min(result, OnePly);
  }


  // ok_to_do_nullmove() looks at the current position and decides whether
  // doing a 'null move' should be allowed.  In order to avoid zugzwang
  // problems, null moves are not allowed when the side to move has very
  // little material left.  Currently, the test is a bit too simple:  Null
  // moves are avoided only when the side to move has only pawns left.  It's
  // probably a good idea to avoid null moves in at least some more
  // complicated endgames, e.g. KQ vs KR.  FIXME

  bool ok_to_do_nullmove(const Position &pos) {
    if(pos.non_pawn_material(pos.side_to_move()) == Value(0))
      return false;
    return true;
  }


  // ok_to_prune() tests whether it is safe to forward prune a move.  Only
  // non-tactical moves late in the move list close to the leaves are
  // candidates for pruning.

  bool ok_to_prune(const Position &pos, Move m, Move threat, Depth d) {
    Square mfrom, mto, tfrom, tto;

    assert(move_is_ok(m));
    assert(threat == MOVE_NONE || move_is_ok(threat));
    assert(!move_promotion(m));
    assert(!pos.move_is_check(m));
    assert(!pos.move_is_capture(m));
    assert(!pos.move_is_passed_pawn_push(m));
    assert(d >= OnePly);

    mfrom = move_from(m);
    mto = move_to(m);
    tfrom = move_from(threat);
    tto = move_to(threat);

    // Case 1: Castling moves are never pruned.
    if(move_is_castle(m))
      return false;

    // Case 2: Don't prune moves which move the threatened piece
    if(!PruneEscapeMoves && threat != MOVE_NONE && mfrom == tto)
      return false;

    // Case 3: If the threatened piece has value less than or equal to the
    // value of the threatening piece, don't prune move which defend it.
    if(!PruneDefendingMoves && threat != MOVE_NONE
       && (piece_value_midgame(pos.piece_on(tfrom))
           >= piece_value_midgame(pos.piece_on(tto)))
       && pos.move_attacks_square(m, tto))
      return false;

    // Case 4: Don't prune moves with good history.
    if(!H.ok_to_prune(pos.piece_on(move_from(m)), m, d))
      return false;

    // Case 5: If the moving piece in the threatened move is a slider, don't
    // prune safe moves which block its ray.
    if(!PruneBlockingMoves && threat != MOVE_NONE
       && piece_is_slider(pos.piece_on(tfrom))
       && bit_is_set(squares_between(tfrom, tto), mto) && pos.see(m) >= 0)
      return false;

    return true;
  }


  // ok_to_use_TT() returns true if a transposition table score
  // can be used at a given point in search.

  bool ok_to_use_TT(const TTEntry* tte, Depth depth, Value beta, int ply) {

    Value v = value_from_tt(tte->value(), ply);

    return   (   tte->depth() >= depth
              || v >= Max(value_mate_in(100), beta)
              || v < Min(value_mated_in(100), beta))

          && (   (is_lower_bound(tte->type()) && v >= beta)
              || (is_upper_bound(tte->type()) && v < beta));
  }


  // ok_to_history() returns true if a move m can be stored
  // in history. Should be a non capturing move.

  bool ok_to_history(const Position& pos, Move m) {

    return    pos.square_is_empty(move_to(m))
          && !move_promotion(m)
          && !move_is_ep(m);
  }


  // update_history() registers a good move that produced a beta-cutoff
  // in history and marks as failures all the other moves of that ply.

  void update_history(const Position& pos, Move m, Depth depth,
                      Move movesSearched[], int moveCount) {

    H.success(pos.piece_on(move_from(m)), m, depth);

    for (int i = 0; i < moveCount - 1; i++)
        if (ok_to_history(pos, movesSearched[i]) && m != movesSearched[i])
            H.failure(pos.piece_on(move_from(movesSearched[i])), movesSearched[i]);
  }

  // fail_high_ply_1() checks if some thread is currently resolving a fail
  // high at ply 1 at the node below the first root node.  This information
  // is used for time managment.

  bool fail_high_ply_1() {
    for(int i = 0; i < ActiveThreads; i++)
      if(Threads[i].failHighPly1)
        return true;
    return false;
  }


  // current_search_time() returns the number of milliseconds which have passed
  // since the beginning of the current search.

  int current_search_time() {
    return get_system_time() - SearchStartTime;
  }


  // nps() computes the current nodes/second count.

  int nps() {
    int t = current_search_time();
    return (t > 0)? int((nodes_searched() * 1000) / t) : 0;
  }


  // poll() performs two different functions:  It polls for user input, and it
  // looks at the time consumed so far and decides if it's time to abort the
  // search.

  void poll() {

    static int lastInfoTime;
    int t = current_search_time();

    //  Poll for input
    if (Bioskey())
    {
        // We are line oriented, don't read single chars
        std::string command;
        if (!std::getline(std::cin, command))
            command = "quit";

        if (command == "quit")
        {
            AbortSearch = true;
            PonderSearch = false;
            Quit = true;
        }
        else if(command == "stop")
        {
            AbortSearch = true;
            PonderSearch = false;
        }
        else if(command == "ponderhit")
            ponderhit();
    }
    // Print search information
    if (t < 1000)
        lastInfoTime = 0;

    else if (lastInfoTime > t)
        // HACK: Must be a new search where we searched less than
        // NodesBetweenPolls nodes during the first second of search.
        lastInfoTime = 0;

    else if (t - lastInfoTime >= 1000)
    {
        lastInfoTime = t;
        lock_grab(&IOLock);
        if (dbg_show_mean)
            dbg_print_mean();

        if (dbg_show_hit_rate)
            dbg_print_hit_rate();

        std::cout << "info nodes " << nodes_searched() << " nps " << nps()
                  << " time " << t << " hashfull " << TT.full() << std::endl;
        lock_release(&IOLock);
        if (ShowCurrentLine)
            Threads[0].printCurrentLine = true;
    }
    // Should we stop the search?
    if (PonderSearch)
        return;

    bool overTime =     t > AbsoluteMaxSearchTime
                     || (RootMoveNumber == 1 && t > MaxSearchTime + ExtraSearchTime)
                     || (  !FailHigh && !fail_high_ply_1() && !Problem
                         && t > 6*(MaxSearchTime + ExtraSearchTime));

    if (   (Iteration >= 2 && (!InfiniteSearch && overTime))
        || (ExactMaxTime && t >= ExactMaxTime)
        || (Iteration >= 3 && MaxNodes && nodes_searched() >= MaxNodes))
        AbortSearch = true;
  }


  // ponderhit() is called when the program is pondering (i.e. thinking while
  // it's the opponent's turn to move) in order to let the engine know that
  // it correctly predicted the opponent's move.

  void ponderhit() {
    int t = current_search_time();
    PonderSearch = false;
    if(Iteration >= 2 &&
       (!InfiniteSearch && (StopOnPonderhit ||
                            t > AbsoluteMaxSearchTime ||
                            (RootMoveNumber == 1 &&
                             t > MaxSearchTime + ExtraSearchTime) ||
                            (!FailHigh && !fail_high_ply_1() && !Problem &&
                             t > 6*(MaxSearchTime + ExtraSearchTime)))))
      AbortSearch = true;
  }


  // print_current_line() prints the current line of search for a given
  // thread.  Called when the UCI option UCI_ShowCurrLine is 'true'.

  void print_current_line(SearchStack ss[], int ply, int threadID) {
    assert(ply >= 0 && ply < PLY_MAX);
    assert(threadID >= 0 && threadID < ActiveThreads);

    if(!Threads[threadID].idle) {
      lock_grab(&IOLock);
      std::cout << "info currline " << (threadID + 1);
      for(int p = 0; p < ply; p++)
        std::cout << " " << ss[p].currentMove;
      std::cout << std::endl;
      lock_release(&IOLock);
    }
    Threads[threadID].printCurrentLine = false;
    if(threadID + 1 < ActiveThreads)
      Threads[threadID + 1].printCurrentLine = true;
  }


  // wait_for_stop_or_ponderhit() is called when the maximum depth is reached
  // while the program is pondering.  The point is to work around a wrinkle in
  // the UCI protocol:  When pondering, the engine is not allowed to give a
  // "bestmove" before the GUI sends it a "stop" or "ponderhit" command.
  // We simply wait here until one of these commands is sent, and return,
  // after which the bestmove and pondermove will be printed (in id_loop()).

  void wait_for_stop_or_ponderhit() {
    std::string command;

    while(true) {
      if(!std::getline(std::cin, command))
        command = "quit";

      if(command == "quit") {
        OpeningBook.close();
        stop_threads();
        quit_eval();
        exit(0);
      }
      else if(command == "ponderhit" || command == "stop")
        break;
    }
  }


  // idle_loop() is where the threads are parked when they have no work to do.
  // The parameter "waitSp", if non-NULL, is a pointer to an active SplitPoint
  // object for which the current thread is the master.

  void idle_loop(int threadID, SplitPoint *waitSp) {
    assert(threadID >= 0 && threadID < THREAD_MAX);

    Threads[threadID].running = true;

    while(true) {
      if(AllThreadsShouldExit && threadID != 0)
        break;

      // If we are not thinking, wait for a condition to be signaled instead
      // of wasting CPU time polling for work:
      while(threadID != 0 && (Idle || threadID >= ActiveThreads)) {
#if !defined(_MSC_VER)
        pthread_mutex_lock(&WaitLock);
        if(Idle || threadID >= ActiveThreads)
          pthread_cond_wait(&WaitCond, &WaitLock);
        pthread_mutex_unlock(&WaitLock);
#else
        WaitForSingleObject(SitIdleEvent[threadID], INFINITE);
#endif
      }

      // If this thread has been assigned work, launch a search:
      if(Threads[threadID].workIsWaiting) {
        Threads[threadID].workIsWaiting = false;
        if(Threads[threadID].splitPoint->pvNode)
          sp_search_pv(Threads[threadID].splitPoint, threadID);
        else
          sp_search(Threads[threadID].splitPoint, threadID);
        Threads[threadID].idle = true;
      }

      // If this thread is the master of a split point and all threads have
      // finished their work at this split point, return from the idle loop:
      if(waitSp != NULL && waitSp->cpus == 0)
        return;
    }

    Threads[threadID].running = false;
  }


  // init_split_point_stack() is called during program initialization, and
  // initializes all split point objects.

  void init_split_point_stack() {
    for(int i = 0; i < THREAD_MAX; i++)
      for(int j = 0; j < MaxActiveSplitPoints; j++) {
        SplitPointStack[i][j].parent = NULL;
        lock_init(&(SplitPointStack[i][j].lock), NULL);
      }
  }


  // destroy_split_point_stack() is called when the program exits, and
  // destroys all locks in the precomputed split point objects.

  void destroy_split_point_stack() {
    for(int i = 0; i < THREAD_MAX; i++)
      for(int j = 0; j < MaxActiveSplitPoints; j++)
        lock_destroy(&(SplitPointStack[i][j].lock));
  }


  // thread_should_stop() checks whether the thread with a given threadID has
  // been asked to stop, directly or indirectly.  This can happen if a beta
  // cutoff has occured in thre thread's currently active split point, or in
  // some ancestor of the current split point.

  bool thread_should_stop(int threadID) {
    assert(threadID >= 0 && threadID < ActiveThreads);

    SplitPoint *sp;

    if(Threads[threadID].stop)
      return true;
    if(ActiveThreads <= 2)
      return false;
    for(sp = Threads[threadID].splitPoint; sp != NULL; sp = sp->parent)
      if(sp->finished) {
        Threads[threadID].stop = true;
        return true;
      }
    return false;
  }


  // thread_is_available() checks whether the thread with threadID "slave" is
  // available to help the thread with threadID "master" at a split point.  An
  // obvious requirement is that "slave" must be idle.  With more than two
  // threads, this is not by itself sufficient:  If "slave" is the master of
  // some active split point, it is only available as a slave to the other
  // threads which are busy searching the split point at the top of "slave"'s
  // split point stack (the "helpful master concept" in YBWC terminology).

  bool thread_is_available(int slave, int master) {
    assert(slave >= 0 && slave < ActiveThreads);
    assert(master >= 0 && master < ActiveThreads);
    assert(ActiveThreads > 1);

    if(!Threads[slave].idle || slave == master)
      return false;

    if(Threads[slave].activeSplitPoints == 0)
      // No active split points means that the thread is available as a slave
      // for any other thread.
      return true;

    if(ActiveThreads == 2)
      return true;

    // Apply the "helpful master" concept if possible.
    if(SplitPointStack[slave][Threads[slave].activeSplitPoints-1].slaves[master])
      return true;

    return false;
  }


  // idle_thread_exists() tries to find an idle thread which is available as
  // a slave for the thread with threadID "master".

  bool idle_thread_exists(int master) {
    assert(master >= 0 && master < ActiveThreads);
    assert(ActiveThreads > 1);

    for(int i = 0; i < ActiveThreads; i++)
      if(thread_is_available(i, master))
        return true;
    return false;
  }


  // split() does the actual work of distributing the work at a node between
  // several threads at PV nodes.  If it does not succeed in splitting the
  // node (because no idle threads are available, or because we have no unused
  // split point objects), the function immediately returns false.  If
  // splitting is possible, a SplitPoint object is initialized with all the
  // data that must be copied to the helper threads (the current position and
  // search stack, alpha, beta, the search depth, etc.), and we tell our
  // helper threads that they have been assigned work.  This will cause them
  // to instantly leave their idle loops and call sp_search_pv().  When all
  // threads have returned from sp_search_pv (or, equivalently, when
  // splitPoint->cpus becomes 0), split() returns true.

  bool split(const Position &p, SearchStack *sstck, int ply,
             Value *alpha, Value *beta, Value *bestValue,
             Depth depth, int *moves,
             MovePicker *mp, Bitboard dcCandidates, int master, bool pvNode) {
    assert(p.is_ok());
    assert(sstck != NULL);
    assert(ply >= 0 && ply < PLY_MAX);
    assert(*bestValue >= -VALUE_INFINITE && *bestValue <= *alpha);
    assert(!pvNode || *alpha < *beta);
    assert(*beta <= VALUE_INFINITE);
    assert(depth > Depth(0));
    assert(master >= 0 && master < ActiveThreads);
    assert(ActiveThreads > 1);

    SplitPoint *splitPoint;
    int i;

    lock_grab(&MPLock);

    // If no other thread is available to help us, or if we have too many
    // active split points, don't split:
    if(!idle_thread_exists(master) ||
       Threads[master].activeSplitPoints >= MaxActiveSplitPoints) {
      lock_release(&MPLock);
      return false;
    }

    // Pick the next available split point object from the split point stack:
    splitPoint = SplitPointStack[master] + Threads[master].activeSplitPoints;
    Threads[master].activeSplitPoints++;

    // Initialize the split point object:
    splitPoint->parent = Threads[master].splitPoint;
    splitPoint->finished = false;
    splitPoint->ply = ply;
    splitPoint->depth = depth;
    splitPoint->alpha = pvNode? *alpha : (*beta - 1);
    splitPoint->beta = *beta;
    splitPoint->pvNode = pvNode;
    splitPoint->dcCandidates = dcCandidates;
    splitPoint->bestValue = *bestValue;
    splitPoint->master = master;
    splitPoint->mp = mp;
    splitPoint->moves = *moves;
    splitPoint->cpus = 1;
    splitPoint->pos.copy(p);
    splitPoint->parentSstack = sstck;
    for(i = 0; i < ActiveThreads; i++)
      splitPoint->slaves[i] = 0;

    // Copy the current position and the search stack to the master thread:
    memcpy(splitPoint->sstack[master], sstck, (ply+1)*sizeof(SearchStack));
    Threads[master].splitPoint = splitPoint;

    // Make copies of the current position and search stack for each thread:
    for(i = 0; i < ActiveThreads && splitPoint->cpus < MaxThreadsPerSplitPoint;
        i++)
      if(thread_is_available(i, master)) {
        memcpy(splitPoint->sstack[i], sstck, (ply+1)*sizeof(SearchStack));
        Threads[i].splitPoint = splitPoint;
        splitPoint->slaves[i] = 1;
        splitPoint->cpus++;
      }

    // Tell the threads that they have work to do.  This will make them leave
    // their idle loop.
    for(i = 0; i < ActiveThreads; i++)
      if(i == master || splitPoint->slaves[i]) {
        Threads[i].workIsWaiting = true;
        Threads[i].idle = false;
        Threads[i].stop = false;
      }

    lock_release(&MPLock);

    // Everything is set up.  The master thread enters the idle loop, from
    // which it will instantly launch a search, because its workIsWaiting
    // slot is 'true'.  We send the split point as a second parameter to the
    // idle loop, which means that the main thread will return from the idle
    // loop when all threads have finished their work at this split point
    // (i.e. when // splitPoint->cpus == 0).
    idle_loop(master, splitPoint);

    // We have returned from the idle loop, which means that all threads are
    // finished.  Update alpha, beta and bestvalue, and return:
    lock_grab(&MPLock);
    if(pvNode) *alpha = splitPoint->alpha;
    *beta = splitPoint->beta;
    *bestValue = splitPoint->bestValue;
    Threads[master].stop = false;
    Threads[master].idle = false;
    Threads[master].activeSplitPoints--;
    Threads[master].splitPoint = splitPoint->parent;
    lock_release(&MPLock);

    return true;
  }


  // wake_sleeping_threads() wakes up all sleeping threads when it is time
  // to start a new search from the root.

  void wake_sleeping_threads() {
    if(ActiveThreads > 1) {
      for(int i = 1; i < ActiveThreads; i++) {
        Threads[i].idle = true;
        Threads[i].workIsWaiting = false;
      }
#if !defined(_MSC_VER)
      pthread_mutex_lock(&WaitLock);
      pthread_cond_broadcast(&WaitCond);
      pthread_mutex_unlock(&WaitLock);
#else
      for(int i = 1; i < THREAD_MAX; i++)
        SetEvent(SitIdleEvent[i]);
#endif
    }
  }


  // init_thread() is the function which is called when a new thread is
  // launched.  It simply calls the idle_loop() function with the supplied
  // threadID.  There are two versions of this function; one for POSIX threads
  // and one for Windows threads.

#if !defined(_MSC_VER)

  void *init_thread(void *threadID) {
    idle_loop(*(int *)threadID, NULL);
    return NULL;
  }

#else

  DWORD WINAPI init_thread(LPVOID threadID) {
    idle_loop(*(int *)threadID, NULL);
    return NULL;
  }

#endif

}

// ======== square.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cassert>
#include <string>



////
//// Functions
////


/// Translating files, ranks and squares to/from characters and strings:

File file_from_char(char c) {
  return File(c - 'a') + FILE_A;
}


char file_to_char(File f) {
  return char(f - FILE_A) + 'a';
}


Rank rank_from_char(char c) {
  return Rank(c - '1') + RANK_1;
}


char rank_to_char(Rank r) {
  return char(r - RANK_1) + '1';
}


Square square_from_string(const std::string &str) {
  return make_square(file_from_char(str[0]), rank_from_char(str[1]));
}


const std::string square_to_string(Square s) {
  std::string str;
  str += file_to_char(square_file(s));
  str += rank_to_char(square_rank(s));
  return str;
}


/// file_is_ok(), rank_is_ok() and square_is_ok(), for debugging:

bool file_is_ok(File f) {
  return f >= FILE_A && f <= FILE_H;
}


bool rank_is_ok(Rank r) {
  return r >= RANK_1 && r <= RANK_8;
}


bool square_is_ok(Square s) {
  return file_is_ok(square_file(s)) && rank_is_ok(square_rank(s));
}

// ======== tt.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cassert>
#include <cmath>



////
//// Functions
////

/// Constructor

TranspositionTable::TranspositionTable(unsigned mbSize) {

  size = 0;
  generation = 0;
  writes = 0;
  entries = 0;
  set_size(mbSize);
}


/// Destructor

TranspositionTable::~TranspositionTable() {

  delete [] entries;
}


/// TranspositionTable::set_size sets the size of the transposition table,
/// measured in megabytes.

void TranspositionTable::set_size(unsigned mbSize) {

  assert(mbSize >= 4 && mbSize <= 1024);

  unsigned newSize = 1024;

  // We store a cluster of 4 TTEntry for each position and newSize is
  // the maximum number of storable positions
  for ( ; newSize * 4 * (sizeof(TTEntry)) <= (mbSize << 20); newSize *= 2);
  newSize /= 2;
  if (newSize != size)
  {
    size = newSize;
    delete [] entries;
    entries = new TTEntry[size * 4];
    if (!entries)
    {
      std::cerr << "Failed to allocate " << mbSize
                << " MB for transposition table."
                << std::endl;
      exit(EXIT_FAILURE);
    }
    clear();
  }
}


/// TranspositionTable::clear overwrites the entire transposition table
/// with zeroes.  It is called whenever the table is resized, or when the
/// user asks the program to clear the table (from the UCI interface).
/// Perhaps we should also clear it when the "ucinewgame" command is recieved?

void TranspositionTable::clear() {

  memset(entries, 0, size * 4 * sizeof(TTEntry));
}


/// TranspositionTable::store writes a new entry containing a position,
/// a value, a value type, a search depth, and a best move to the
/// transposition table.  The transposition table is organized in clusters
/// of four TTEntry objects, and when a new entry is written, it replaces
/// the least valuable of the four entries in a cluster.  A TTEntry t1 is
/// considered to be more valuable than a TTEntry t2 if t1 is from the
/// current search and t2 is from a previous search, or if the depth of t1
/// is bigger than the depth of t2.

void TranspositionTable::store(const Position &pos, Value v, Depth d,
                               Move m, ValueType type) {
  TTEntry *tte, *replace;

  tte = replace = first_entry(pos);
  for (int i = 0; i < 4; i++)
  {
    if (!(tte+i)->key()) // still empty
    {
        *(tte+i) = TTEntry(pos.get_key(), v, type, d, m, generation);
        writes++;
        return;
    }
    if ((tte+i)->key() == pos.get_key()) // overwrite old
    {
        if (m == MOVE_NONE)
            m = (tte+i)->move();

        *(tte+i) = TTEntry(pos.get_key(), v, type, d, m, generation);
        return;
    }
    if (   i == 0  // already is (replace == tte+i), common case
        || replace->generation() < (tte+i)->generation())
        continue;

    if (    replace->generation() > (tte+i)->generation()
        || (tte+i)->depth() < replace->depth())
        replace = tte+i;
  }
  *replace = TTEntry(pos.get_key(), v, type, d, m, generation);
  writes++;
}


/// TranspositionTable::retrieve looks up the current position in the
/// transposition table. Returns a pointer to the TTEntry or NULL
/// if position is not found.

const TTEntry* TranspositionTable::retrieve(const Position &pos) const {

  TTEntry *tte = first_entry(pos);

  for (int i = 0; i < 4; i++)
  {
      tte += i;
      if (tte->key() == pos.get_key())
          return tte;
  }
  return NULL;
}


/// TranspositionTable::first_entry returns a pointer to the first
/// entry of a cluster given a position.

inline TTEntry* TranspositionTable::first_entry(const Position &pos) const {

  return entries + (int(pos.get_key() & (size - 1)) << 2);
}

/// TranspositionTable::new_search() is called at the beginning of every new
/// search.  It increments the "generation" variable, which is used to
/// distinguish transposition table entries from previous searches from
/// entries from the current search.

void TranspositionTable::new_search() {

  generation++;
  writes = 0;
}


/// TranspositionTable::insert_pv() is called at the end of a search
/// iteration, and inserts the PV back into the PV.  This makes sure the
/// old PV moves are searched first, even if the old TT entries have been
/// overwritten.

void TranspositionTable::insert_pv(const Position &pos, Move pv[]) {

  UndoInfo u;
  Position p(pos);

  for (int i = 0; pv[i] != MOVE_NONE; i++)
  {
    store(p, VALUE_NONE, Depth(0), pv[i], VALUE_TYPE_NONE);
    p.do_move(pv[i], u);
  }
}


/// TranspositionTable::full() returns the permill of all transposition table
/// entries which have received at least one write during the current search.
/// It is used to display the "info hashfull ..." information in UCI.

int TranspositionTable::full() {

  double N = double(size) * 4.0;
  return int(1000 * (1 - exp(writes * log(1.0 - 1.0/N))));
}


/// Constructors

TTEntry::TTEntry() {
}

TTEntry::TTEntry(Key k, Value v, ValueType t, Depth d, Move m,
                 int generation) :
  key_ (k), data((m & 0x7FFFF) | (t << 20) | (generation << 23)),
  value_(v), depth_(int16_t(d)) {}




// ======== uci.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <iostream>
#include <sstream>
#include <string>

// ---- begin uci.h ----
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#if !defined(UCI_H_INCLUDED)
#define UCI_H_INCLUDED

////
//// Prototypes
////

extern void uci_main_loop();


#endif // !defined(UCI_H_INCLUDED)
// ---- end uci.h ----


////
//// Local definitions:
////

namespace {

  // UCIInputParser is a class for parsing UCI input.  The class
  // is actually a string stream built on a given input string.

  typedef std::istringstream UCIInputParser;

  // The root position.  This is set up when the user (or in practice, the GUI)
  // sends the "position" UCI command.  The root position is sent to the think()
  // function when the program receives the "go" command.
  Position RootPosition;

  // Local functions
  void get_command();
  void handle_command(const std::string &command);
  void set_option(UCIInputParser &uip);
  void set_position(UCIInputParser &uip);
  void go(UCIInputParser &uip);
}


////
//// Functions
////

/// uci_main_loop() is the only global function in this file.  It is
/// called immediately after the program has finished initializing.
/// The program remains in this loop until it receives the "quit" UCI
/// command.

void uci_main_loop() {

  RootPosition.from_fen(StartPosition);

  while (1)
      get_command();
}


////
//// Local functions
////

namespace {

  // get_command() waits for a command from the user, and passes
  // this command to handle_command.  get_command also intercepts
  // EOF from stdin, by translating EOF to the "quit" command.  This
  // ensures that Stockfish exits gracefully if the GUI dies
  // unexpectedly.

  void get_command() {

    std::string command;

    if (!std::getline(std::cin, command))
        command = "quit";

    handle_command(command);
  }


  // handle_command() takes a text string as input, uses a
  // UCIInputParser object to parse this text string as a UCI command,
  // and calls the appropriate functions.  In addition to the UCI
  // commands, the function also supports a few debug commands.

  void handle_command(const std::string &command) {

    UCIInputParser uip(command);
    std::string token;

    uip >> token; // operator >> skips any whitespace

    if (token == "quit")
    {
        OpeningBook.close();
        stop_threads();
        quit_eval();
        exit(0);
    }
    else if (token == "uci")
    {
        std::cout << "id name " << engine_name() << std::endl
                  << "id author Tord Romstad, Marco Costalba"
                  << std::endl;
        print_uci_options();
        std::cout << "uciok" << std::endl;
    }
    else if (token == "ucinewgame")
    {
        TT.clear();
        Position::init_piece_square_tables();
        RootPosition.from_fen(StartPosition);
    }
    else if (token == "isready")
        std::cout << "readyok" << std::endl;
    else if (token == "position")
        set_position(uip);
    else if (token == "setoption")
        set_option(uip);
    else if (token == "go")
        go(uip);

    // The remaining commands are for debugging purposes only.
    // Perhaps they should be removed later in order to reduce the
    // size of the program binary.
    else if (token == "d")
        RootPosition.print();
    else if (token == "flip")
    {
        Position p(RootPosition);
        RootPosition.flipped_copy(p);
    }
    else if (token == "eval")
    {
        EvalInfo ei;
        std::cout << "Incremental mg: " << RootPosition.mg_value()
                  << std::endl;
        std::cout << "Incremental eg: " << RootPosition.eg_value()
                  << std::endl;
        std::cout << "Full eval: "
                  << evaluate(RootPosition, ei, 0)
                  << std::endl;
    }
    else if (token == "key")
    {
        std::cout << "key: " << RootPosition.get_key()
                  << " material key: " << RootPosition.get_material_key()
                  << " pawn key: " << RootPosition.get_pawn_key()
                  << std::endl;
    }
    else
    {
        std::cout << "Unknown command: " << command << std::endl;
        while (!uip.eof())
        {
            uip >> token;
            std::cout << token << std::endl;
        }
    }
  }


  // set_position() is called when Stockfish receives the "position" UCI
  // command.  The input parameter is a UCIInputParser.  It is assumed
  // that this parser has consumed the first token of the UCI command
  // ("position"), and is ready to read the second token ("startpos"
  // or "fen", if the input is well-formed).

  void set_position(UCIInputParser &uip) {

    std::string token;

    uip >> token; // operator >> skips any whitespace

    if (token == "startpos")
        RootPosition.from_fen(StartPosition);
    else if (token == "fen")
    {
        std::string fen;
        while (token != "moves" && !uip.eof())
        {
          uip >> token;
          fen += token;
          fen += ' ';
        }
        RootPosition.from_fen(fen);
    }

    if (!uip.eof())
    {
        if (token != "moves")
          uip >> token;
        if (token == "moves")
        {
            Move move;
            UndoInfo u;
            while (!uip.eof())
            {
                uip >> token;
                move = move_from_string(RootPosition, token);
                RootPosition.do_move(move, u);
                if (RootPosition.rule_50_counter() == 0)
                    RootPosition.reset_game_ply();
            }
        }
    }
  }


  // set_option() is called when Stockfish receives the "setoption" UCI
  // command.  The input parameter is a UCIInputParser.  It is assumed
  // that this parser has consumed the first token of the UCI command
  // ("setoption"), and is ready to read the second token ("name", if
  // the input is well-formed).

  void set_option(UCIInputParser &uip) {

    std::string token, name;

    uip >> token;
    if (token == "name")
    {
        uip >> name;
        uip >> token;
        while (!uip.eof() && token != "value")
        {
          name += (" " + token);
          uip >> token;
        }
        if (token == "value")
        {
            std::getline(uip, token); // reads until end of line
            set_option_value(name, token);
        } else
            push_button(name);
    }
  }


  // go() is called when Stockfish receives the "go" UCI command.  The
  // input parameter is a UCIInputParser.  It is assumed that this
  // parser has consumed the first token of the UCI command ("go"),
  // and is ready to read the second token.  The function sets the
  // thinking time and other parameters from the input string, and
  // calls think() (defined in search.cpp) with the appropriate
  // parameters.

  void go(UCIInputParser &uip) {

    std::string token;

    int time[2] = {0, 0}, inc[2] = {0, 0};
    int movesToGo = 0, depth = 0, nodes = 0, moveTime = 0;
    bool infinite = false, ponder = false;
    Move searchMoves[500];

    searchMoves[0] = MOVE_NONE;

    while (!uip.eof())
    {
        uip >> token;

        if (token == "infinite")
            infinite = true;
        else if (token == "ponder")
            ponder = true;
        else if (token == "wtime")
            uip >> time[0];
        else if (token == "btime")
            uip >> time[1];
        else if (token == "winc")
            uip >> inc[0];
        else if (token == "binc")
            uip >> inc[1];
        else if (token == "movestogo")
            uip >> movesToGo;
        else if (token == "depth")
            uip >> depth;
        else if (token == "nodes")
            uip >> nodes;
        else if (token == "movetime")
            uip >> moveTime;
        else if (token == "searchmoves")
        {
            int numOfMoves = 0;
            while (!uip.eof())
            {
                uip >> token;
                searchMoves[numOfMoves++] = move_from_string(RootPosition, token);
            }
            searchMoves[numOfMoves] = MOVE_NONE;
        }
    }

    if (moveTime)
        infinite = true;  // HACK

    think(RootPosition, infinite, ponder, RootPosition.side_to_move(), time,
          inc, movesToGo, depth, nodes, moveTime, searchMoves);
  }
}

// ======== ucioption.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <cassert>
#include <string>
#include <sstream>
#include <vector>



////
//// Variables
////

bool Chess960 = false;


////
//// Local definitions
////

namespace {

  ///
  /// Types
  ///

  enum OptionType { SPIN, COMBO, CHECK, STRING, BUTTON };

  typedef std::vector<std::string> ComboValues;

  struct Option {

    std::string name, defaultValue, currentValue;
    OptionType type;
    int minValue, maxValue;
    ComboValues comboValues;

    Option(const char* name, const char* defaultValue, OptionType = STRING);
    Option(const char* name, bool defaultValue, OptionType = CHECK);
    Option(const char* name, int defaultValue, int minValue, int maxValue);
  };

  typedef std::vector<Option> Options;

  ///
  /// Constants
  ///

  // load_defaults populates the options vector with the hard
  // coded names and default values.

  void load_defaults(Options& o) {

    o.push_back(Option("Use Search Log", false));
    o.push_back(Option("Search Log Filename", "SearchLog.txt"));
    o.push_back(Option("Book File", "book.bin"));
    o.push_back(Option("Mobility (Middle Game)", 100, 0, 200));
    o.push_back(Option("Mobility (Endgame)", 100, 0, 200));
    o.push_back(Option("Pawn Structure (Middle Game)", 100, 0, 200));
    o.push_back(Option("Pawn Structure (Endgame)", 100, 0, 200));
    o.push_back(Option("Passed Pawns (Middle Game)", 100, 0, 200));
    o.push_back(Option("Passed Pawns (Endgame)", 100, 0, 200));
    o.push_back(Option("Aggressiveness", 100, 0, 200));
    o.push_back(Option("Cowardice", 100, 0, 200));
    o.push_back(Option("King Safety Curve", "Quadratic", COMBO));

       o.back().comboValues.push_back("Quadratic");
       o.back().comboValues.push_back("Linear");  /*, "From File"*/

    o.push_back(Option("King Safety Coefficient", 40, 1, 100));
    o.push_back(Option("King Safety X Intercept", 0, 0, 20));
    o.push_back(Option("King Safety Max Slope", 30, 10, 100));
    o.push_back(Option("King Safety Max Value", 500, 100, 1000));
    o.push_back(Option("Queen Contact Check Bonus", 4, 0, 8));
    o.push_back(Option("Rook Contact Check Bonus", 2, 0, 4));
    o.push_back(Option("Queen Check Bonus", 2, 0, 4));
    o.push_back(Option("Rook Check Bonus", 1, 0, 4));
    o.push_back(Option("Bishop Check Bonus", 1, 0, 4));
    o.push_back(Option("Knight Check Bonus", 1, 0, 4));
    o.push_back(Option("Discovered Check Bonus", 3, 0, 8));
    o.push_back(Option("Mate Threat Bonus", 3, 0, 8));
    o.push_back(Option("Check Extension (PV nodes)", 2, 0, 2));
    o.push_back(Option("Check Extension (non-PV nodes)", 1, 0, 2));
    o.push_back(Option("Single Reply Extension (PV nodes)", 2, 0, 2));
    o.push_back(Option("Single Reply Extension (non-PV nodes)", 2, 0, 2));
    o.push_back(Option("Mate Threat Extension (PV nodes)", 0, 0, 2));
    o.push_back(Option("Mate Threat Extension (non-PV nodes)", 0, 0, 2));
    o.push_back(Option("Pawn Push to 7th Extension (PV nodes)", 1, 0, 2));
    o.push_back(Option("Pawn Push to 7th Extension (non-PV nodes)", 1, 0, 2));
    o.push_back(Option("Passed Pawn Extension (PV nodes)", 1, 0, 2));
    o.push_back(Option("Passed Pawn Extension (non-PV nodes)", 0, 0, 2));
    o.push_back(Option("Pawn Endgame Extension (PV nodes)", 2, 0, 2));
    o.push_back(Option("Pawn Endgame Extension (non-PV nodes)", 2, 0, 2));
    o.push_back(Option("Full Depth Moves (PV nodes)", 14, 1, 100));
    o.push_back(Option("Full Depth Moves (non-PV nodes)", 3, 1, 100));
    o.push_back(Option("Threat Depth", 5, 0, 100));
    o.push_back(Option("Selective Plies", 7, 0, 10));
    o.push_back(Option("Futility Pruning (Main Search)", true));
    o.push_back(Option("Futility Pruning (Quiescence Search)", true));
    o.push_back(Option("Futility Margin 0", 50, 0, 1000));
    o.push_back(Option("Futility Margin 1", 100, 0, 1000));
    o.push_back(Option("Futility Margin 2", 300, 0, 1000));
    o.push_back(Option("Maximum Razoring Depth", 3, 0, 4));
    o.push_back(Option("Razoring Margin", 300, 150, 600));
    o.push_back(Option("LSN filtering", false));
    o.push_back(Option("LSN Time Margin (sec)", 4, 1, 10));
    o.push_back(Option("LSN Value Margin", 200, 100, 600));
    o.push_back(Option("Randomness", 0, 0, 10));
    o.push_back(Option("Minimum Split Depth", 4, 4, 7));
    o.push_back(Option("Maximum Number of Threads per Split Point", 5, 4, 8));
    o.push_back(Option("Threads", 1, 1, 8));
    o.push_back(Option("Hash", 32, 4, 4096));
    o.push_back(Option("Clear Hash", false, BUTTON));
    o.push_back(Option("Ponder", true));
    o.push_back(Option("OwnBook", true));
    o.push_back(Option("MultiPV", 1, 1, 500));
    o.push_back(Option("UCI_ShowCurrLine", false));
    o.push_back(Option("UCI_Chess960", false));
  }

  ///
  /// Variables
  ///

  Options options;

  // Local functions
  Options::iterator option_with_name(const std::string& optionName);

  // stringify converts a value of type T to a std::string
  template<typename T>
  std::string stringify(const T& v) {

     std::ostringstream ss;
     ss << v;
     return ss.str();
  }

  // We want conversion from a bool value to be "true" or "false",
  // not "1" or "0", so add a specialization for bool type.
  template<>
  std::string stringify<bool>(const bool& v) {

    return v ? "true" : "false";
  }

  // get_option_value implements the various get_option_value_<type>
  // functions defined later, because only the option value
  // type changes a template seems a proper solution.

  template<typename T>
  T get_option_value(const std::string& optionName) {

      T ret;
      Options::iterator it = option_with_name(optionName);

      if (it != options.end())
      {
          std::istringstream ss(it->currentValue);
          ss >> ret;
      }
      return ret;
  }

  // Unfortunatly we need a specialization to convert "false" and "true"
  // to proper bool values. The culprit is that we use a non standard way
  // to store a bool value in a string, in particular we use "false" and
  // "true" instead of "0" and "1" due to how UCI protocol works.

  template<>
  bool get_option_value<bool>(const std::string& optionName) {

      Options::iterator it = option_with_name(optionName);

      return it != options.end() && it->currentValue == "true";
  }
}

////
//// Functions
////

/// init_uci_options() initializes the UCI options.  Currently, the only
/// thing this function does is to initialize the default value of the
/// "Threads" parameter to the number of available CPU cores.

void init_uci_options() {

  load_defaults(options);

  // Limit the default value of "Threads" to 7 even if we have 8 CPU cores.
  // According to Ken Dail's tests, Glaurung plays much better with 7 than
  // with 8 threads.  This is weird, but it is probably difficult to find out
  // why before I have a 8-core computer to experiment with myself.
  Options::iterator it = option_with_name("Threads");

  assert(it != options.end());

  it->defaultValue = stringify(Min(cpu_count(), 7));
  it->currentValue = stringify(Min(cpu_count(), 7));

  // Increase the minimum split depth when the number of CPUs is big.
  // It would probably be better to let this depend on the number of threads
  // instead.
  if(cpu_count() > 4)
  {
      it = option_with_name("Minimum Split Depth");

      assert(it != options.end());

      it->defaultValue = "6";
      it->currentValue = "6";
  }
}


/// print_uci_options() prints all the UCI options to the standard output,
/// in the format defined by the UCI protocol.

void print_uci_options() {

  static const char optionTypeName[][16] = {
    "spin", "combo", "check", "string", "button"
  };

  for (Options::iterator it = options.begin(); it != options.end(); ++it)
  {
      std::cout << "option name " << it->name
                << " type "       << optionTypeName[it->type];

      if (it->type != BUTTON)
      {
          std::cout << " default " << it->defaultValue;

          if (it->type == SPIN)
              std::cout << " min " << it->minValue
                        << " max " << it->maxValue;

          else if (it->type == COMBO)
              for(ComboValues::iterator itc = it->comboValues.begin();
                  itc != it->comboValues.end(); ++itc)
                      std::cout << " var " << *itc;
      }
      std::cout << std::endl;
  }
}

/// get_option_value_bool() returns the current value of a UCI parameter of
/// type "check".

bool get_option_value_bool(const std::string& optionName) {

  return get_option_value<bool>(optionName);
}


/// get_option_value_int() returns the value of a UCI parameter as an integer.
/// Normally, this function will be used for a parameter of type "spin", but
/// it could also be used with a "combo" parameter, where all the available
/// values are integers.

int get_option_value_int(const std::string& optionName) {

  return get_option_value<int>(optionName);
}


/// get_option_value_string() returns the current value of a UCI parameter as
/// a string.  It is used with parameters of type "combo" and "string".

const std::string get_option_value_string(const std::string& optionName) {

   return get_option_value<std::string>(optionName);
}


/// button_was_pressed() tests whether a UCI parameter of type "button" has
/// been selected since the last time the function was called.

bool button_was_pressed(const std::string& buttonName) {

  if (get_option_value<bool>(buttonName))
  {
    set_option_value(buttonName, "false");
    return true;
  }

  return false;
}


/// set_option_value() inserts a new value for a UCI parameter.  Note that
/// the function does not check that the new value is legal for the given
/// parameter:  This is assumed to be the responsibility of the GUI.

void set_option_value(const std::string& optionName,
                      const std::string& newValue) {

  Options::iterator it = option_with_name(optionName);

  if (it != options.end())
      it->currentValue = newValue;
  else
      std::cout << "No such option: " << optionName << std::endl;
}


/// push_button() is used to tell the engine that a UCI parameter of type
/// "button" has been selected:

void push_button(const std::string& buttonName) {

  set_option_value(buttonName, "true");
}


namespace {

    // Define constructors of Option class.

    Option::Option(const char* nm, const char* def, OptionType t)
    : name(nm), defaultValue(def), currentValue(def), type(t), minValue(0), maxValue(0) {}

    Option::Option(const char* nm, bool def, OptionType t)
    : name(nm), defaultValue(stringify(def)), currentValue(stringify(def)), type(t), minValue(0), maxValue(0) {}

    Option::Option(const char* nm, int def, int minv, int maxv)
    : name(nm), defaultValue(stringify(def)), currentValue(stringify(def)), type(SPIN), minValue(minv), maxValue(maxv) {}

    // option_with_name() tries to find a UCI option with a given
    // name.  It returns an iterator to the UCI option or to options.end(),
    // depending on whether an option with the given name exists.

    Options::iterator option_with_name(const std::string& optionName) {

        for (Options::iterator it = options.begin(); it != options.end(); ++it)
            if (it->name == optionName)
                return it;

        return options.end();
    }
}

// ======== value.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <sstream>
#include <string>



////
//// Functions
////

/// value_to_tt() adjusts a mate score from "plies to mate from the root" to
/// "plies to mate from the current ply".  Non-mate scores are unchanged.
/// The function is called before storing a value to the transposition table.

Value value_to_tt(Value v, int ply) {
  if(v >= value_mate_in(100))
    return v + ply;
  else if(v <= value_mated_in(100))
    return v - ply;
  else
    return v;
}


/// value_from_tt() is the inverse of value_to_tt():  It adjusts a mate score
/// from the transposition table to a mate score corrected for the current
/// ply depth.

Value value_from_tt(Value v, int ply) {
  if(v >= value_mate_in(100))
    return v - ply;
  else if(v <= value_mated_in(100))
    return v + ply;
  else
    return v;
}


/// value_to_centipawns() converts a value from Stockfish's somewhat unusual
/// scale of pawn = 256 to the more conventional pawn = 100.

int value_to_centipawns(Value v) {
  return (int(v) * 100) / int(PawnValueMidgame);
}


/// value_from_centipawns() converts a centipawn value to Stockfish's internal
/// evaluation scale.  It's used when reading the values of UCI options
/// containing material values (e.g. futility pruning margins).

Value value_from_centipawns(int cp) {
  return Value((cp * 256) / 100);
}


/// value_to_string() converts a value to a string suitable for use with the
/// UCI protocol.

const std::string value_to_string(Value v) {
  std::stringstream s;

  if(abs(v) < VALUE_MATE - 200)
    s << "cp " << value_to_centipawns(v);
  else {
    s << "mate ";
    if(v > 0)
      s << (VALUE_MATE - v + 1) / 2;
    else
      s << -(VALUE_MATE + v) / 2;
  }
  return s.str();
}

// ======== main.cpp ========
/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008 Marco Costalba

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


////
//// Includes
////

#include <iostream>


using std::string;

//// 
//// Functions
////

int main(int argc, char *argv[]) {

  // Disable IO buffering
  std::cout.rdbuf()->pubsetbuf(NULL, 0);
  std::cin.rdbuf()->pubsetbuf(NULL, 0);

  // Initialization

  init_mersenne();
  init_direction_table();
  init_bitboards();
  init_uci_options();
  Position::init_zobrist();
  Position::init_piece_square_tables();
  MovePicker::init_phase_table();
  init_eval(1);
  init_bitbases();
  init_threads();

  // Make random number generation less deterministic, for book moves
  for (int i = abs(get_system_time() % 10000); i > 0; i--)
      genrand_int32();

  // Process command line arguments
  if (argc >= 2 && string(argv[1]) == "bench")
  {
      if (argc < 4 || argc > 6)
      {
        std::cout << "Usage: glaurung bench <hash size> <threads> "
                  << "[time = 60s] [fen positions file = default]"
                  << std::endl;
        exit(0);
      }
      string time = argc > 4 ? argv[4] : "60";
      string fen = argc > 5 ? argv[5] : "default";
      benchmark(string(argv[2]) + " " + string(argv[3]) + " " + time + " " + fen);
      return 0;
  }

  // Print copyright notice
  std::cout << engine_name() << ".  Copyright (C) "
            << "2004-2008 Tord Romstad, Marco Costalba. "
            << std::endl;

  // Enter UCI mode
  uci_main_loop();

  return 0;
}
