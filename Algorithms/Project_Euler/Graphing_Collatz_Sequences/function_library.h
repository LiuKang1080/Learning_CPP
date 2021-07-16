#pragma once

// Function Prototypes:
std::vector<int> collatz_sequence_generator(unsigned long long int num);

std::vector<int> range_vector(const std::vector<int>& collatz_sequence);

std::valarray<double> convert_vector_valarray(const std::vector<int>& vec);

void plot_sequence(const std::vector<int> &collatz_sequence, int collatz_number);
