#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for alphabeta policy.
 */
class AlphaBeta{
public:
  static Move get_move(State *state, int depth);
};