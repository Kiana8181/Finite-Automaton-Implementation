# Finite Automaton Implementation in C++

## Project Overview

This project is a comprehensive implementation of a Finite Automaton (FA) in C++. It includes functionalities for both Non-deterministic Finite Automata (NFA) and Deterministic Finite Automata (DFA). The program allows users to input an NFA, convert it to an equivalent DFA, simplify the DFA, and check if specific strings are accepted by the NFA or DFA.

## Features

- **Input NFA**: Users can input the number of states, alphabet, transition functions, and final states for an NFA.
- **Check String Acceptance**:
  - By NFA
  - By DFA
- **Create Equivalent DFA**: Convert the input NFA to an equivalent DFA.
- **Simplify DFA**: Simplify the DFA provided by the user.
- **Print Automata**:
  - Print the NFA.
  - Print the equivalent DFA.
- **Exit**: Exit the program.

## How to Use

### Input Format

1. **NFA Input**:
   - Enter the number of states.
   - Enter the alphabet.
   - For each state and each alphabet symbol, enter the number of transitions and their destinations.
   - Enter the number of final states and their identifiers.

2. **Transition Table**:
   - A table will be drawn where rows represent states and columns represent alphabet symbols. The cells will contain the destination states for each transition.

### Menu Options

After providing the NFA input, the following menu will be displayed:

******MENU******

1. Is The String Accepted By NFA?
2. Is The String Accepted By DFA?
3. Create Equivalent DFA
4. Simplify DFA
5. Print NFA
6. Print DFA
7. EXIT


- **Option 1**: Check if a given string is accepted by the NFA.
- **Option 2**: Check if a given string is accepted by the equivalent DFA.
- **Option 3**: Create and display the equivalent DFA.
- **Option 4**: Simplify a given DFA and display it.
- **Option 5**: Print the NFA.
- **Option 6**: Print the equivalent DFA.
- **Option 7**: Exit the program.

### Detailed Steps

1. **Checking String Acceptance**:
   - For NFA: The program will traverse the NFA with the input string and check if it reaches an acceptance state.
   - For DFA: The program will traverse the DFA with the input string and check if it reaches an acceptance state.

2. **Creating Equivalent DFA**:
   - The program will convert the given NFA to an equivalent DFA and display the transition table.

3. **Simplifying DFA**:
   - The program will prompt for DFA input (states, alphabet, transitions, final states), simplify it, and display the simplified DFA.

4. **Printing Automata**:
   - The program will print the transition table for both the NFA and the equivalent DFA.

## Code Overview

The provided code includes various classes and functions to handle the functionalities listed above. Key components include:

- **DFA Class**: Handles DFA-related operations such as printing the DFA, checking string acceptance, and simplifying the DFA.
- **Main Program**: Manages user inputs, transitions, and menu operations.


## Conclusion
This Finite Automaton implementation provides a robust set of features for working with NFAs and DFAs. Users can input automata, check string acceptance, and perform conversions and simplifications. The program's menu-driven interface makes it user-friendly and suitable for educational purposes in computational theory.
