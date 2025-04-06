#pragma once

#include <iostream>

// template <typename T>
// void iter(T *array, size_t length, void (*func)(T &)) {
// 	for (size_t i = 0; i < length; ++i) {
// 		func(array[i]);
// 	}
// }

// changed from above to below to accomandate different functions, for the file that the evaluation process provide
template <typename T, typename F>
void iter(T *array, size_t length, F f) {
	for (size_t i = 0; i < length; ++i) {
		f(array[i]);
	}
}