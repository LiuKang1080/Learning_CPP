#pragma once

// Function Prototypes:
std::vector<unsigned long long int> collatz_sequence_generator(unsigned long long int num);

template <typename T>
std::vector<int> range_vector(const std::vector<T> &collatz_sequence);

template <typename T>
std::valarray<double> convert_vector_valarray(const std::vector<T> &vec);

void plot_sequence(const std::vector<unsigned long long int> &collatz_sequence, int collatz_number);
