# linkedlist-blacklist-cpp
C++ project demonstrating linked lists, friend functions, and dynamic memory management with a candidate voting system

# Candidate Voting System with Blacklist

This C++ project demonstrates **linked lists, friend functions, dynamic memory management, and business logic implementation**.  
It simulates a popularity contest where candidates receive positive votes, and negative votes are tracked in a blacklist. Candidates lose points for each occurrence in the blacklist and are removed from the contest if their score reaches zero.

## Features
- Class `CANDI` represents candidates with names and scores
- Class `LISTA` is a linked list of candidates
- Class `PERSONA` represents individuals in a blacklist
- Class `LISTANEGRA` is a linked list of negative votes
- Friend function `IMPUGNA` updates candidate scores based on the blacklist
- Demonstrates:
  - Linked list operations (insertion, traversal, deletion)
  - Dynamic memory management (`new` and `delete`)
  - Friend functions and encapsulation
  - Business logic simulation

## Example usage

Initial candidate list with random votes
Blacklist of 100 entries created randomly

Call IMPUGNA(L, LN):

  * Candidates lose 1 point per occurrence in blacklist

  * Candidates with 0 points are removed

Final candidate list printed

## Project structure
linkedlist-blacklist-cpp/
│── linkedlist_blacklist.cpp # Source code demonstrating linked lists and friend functions
│── README.md # Project documentation
