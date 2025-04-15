#include "PmergeMe.hpp"

// first pair up the int in the list
// by grouping them into adjacent pairs
// compare each pair and put the smaller number into the winner list and the bigger number into the loser list 
// if the number is odd, the leftout number goes into the winner list 
// we sort the winner list from small to large, using any sorting method(?) or maybe I have to use the recursive Ford-Johnson method
// keep ford-johnson sorting until vector.size() == 2 then we sort
// then we insert the number from the loser list one by one by searching where it belongs
//using the binary insertion