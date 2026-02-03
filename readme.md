# PokerBot (C++)

A lightweight Texas Hold’em poker bot written in C++.  
This project focuses on clean game-state modeling, basic hand evaluation, and decision-making logic without external dependencies or heavy frameworks.

The goal is **clarity over complexity**: a small, extensible codebase that can be evolved from simple heuristics into more advanced strategies.

---

## Features

- Object-oriented modeling of poker concepts
- Game state tracking across all betting streets
- Hand strength evaluation
- Board texture / connectivity analysis
- Decision-making logic (fold, check, call, raise)

---

## Project Structure

The core of the bot is built around a small set of focused classes:

## File Structure


*   `src/` (Source files)
    *   `main.cpp`
    *   `card.h`
    *   `hand.h`
    *   `deck.h`
    *   `board.h`
    *   `bot.h`
    *   `gameState.h`
    *   `utils/`
        *   `utils.h`

*   `readme.md`





## Core Classes

### Card

Represents an individual playing card.

**Responsibilities:**
- Store rank and suit
- Provide basic utilities (comparison, display, etc.)

Example attributes:
- Rank (2–A)
- Suit (♠, ♥, ♦, ♣)

---

### Hand

Represents a player’s private hand (two cards).

**Design notes:**
- Internally stores two `Card` objects
- No equality checking between cards is required (hands are assumed valid)

**Responsibilities:**
- Hold the bot’s hole cards
- Provide accessors for evaluation logic

---

### GameState

Represents the current state of the game at any moment.

**Tracks:**
- Current street: PreFlop, Flop, Turn, River
- Player stack sizes
- Current pot size
- (Optionally) board cards and betting history

This class acts as the **single source of truth** for the game.

---

### Bot

The brain of the poker bot.

**Responsibilities:**
- Evaluate its own hand strength
- Analyze board texture and connectivity
- Decide on an action based on the current `GameState`

**Possible actions:**
- Fold
- Check
- Call
- Raise

Decision-making is intentionally modular so strategies can be swapped or improved later.

---

## Decision Logic Overview

At a high level, the bot follows this pipeline:

1. Read the current `GameState`
2. Assess private hand strength
3. Evaluate board connectivity (draw-heavy vs dry boards)
4. Select an action based on:
   - Hand strength
   - Board texture
   - Stack sizes and pot size

---

## Goals & Non-Goals

### Goals
- Simple, readable C++ implementation
- Easy to extend with better evaluation or strategy
- Clear separation of responsibilities between classes

### Non-Goals (for now)
- Full GTO solvers
- Monte Carlo simulations
- Multiplayer networking
- UI or graphics

---

## Future Extensions

Possible next steps:
- Opponent modeling
- Bluff frequency tuning
- Pot odds and equity calculations
- Hand range estimation
- Monte Carlo rollouts

---

## Build & Run

Example build command (adjust as needed):

```bash
g++ -std=c++17 src/*.cpp -o pokerbot
./pokerbot
```

