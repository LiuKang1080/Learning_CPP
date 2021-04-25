// Reading Data From A File Challenge In C++

/*
Challenge:
    - Write a program that reads a file named "responses.txt"
    - That file contains the answer key for a quiz as well as student responses for the quiz.
    
    - The answer key will always be at the top of the file / first item in the file.
    - The student's name is next
    - the student's answer is last

        answer key
        student 1's name
        student 1's answers
        student 2's name
        student 2's answers

    - We can assume that the text file will always contain at least 1 student.

    - sample:

        ABCDE
        Frank
        ABCDE
        Bob
        BBCAC
        Alice
        ABDDE

    - Read the file, and then display each student's name along with their score (# correct out of 5)
    - Average all the scores and display it as well.
*/


#include <iostream>
#include <fstream>
#include <iomanip>


void print_student(const std::string &student, int score) {
    std::cout   << std::setw(10) << std::left << student
                << std::setw(5) << std::right << score << "\n";
}

int process_response(const std::string &response, const std::string &answer_key) {
    // resets the score back to zero each time this function is called, because when this function is called, a new student's
    // data is ready to be processed
    int score = 0;

    for (size_t i=0; i<answer_key.size(); ++i) {
        if (response.at(i) == answer_key.at(i)) {
            score++;
        }
    }
    // the .at() method takes the character at that location in the string. We use this twice to compare with the answer_key

    return score;
}


int main() {
    // create the variables:
    std::ifstream in_file;
    std::string answer_key {};
    std::string student_name {};
    std::string student_response {};
    int total_students = 0;
    int running_sum = 0;
    double average_score = 0.0;

    // open file and check to see if it is properly opened
    in_file.open("responses.txt");

    if (!in_file) {
        std::cerr << "File Open Error \n";
        return 1;
    }

    // since the first item is always the answer key we can just store it into the variable
    // the extraction operator takes in only 1 word, the entire first word is the entire answer key
    in_file >> answer_key;

    // process the data using a loop
    while (in_file >> student_name >> student_response) {
        ++total_students;
        int score = process_response(student_response, answer_key);
        running_sum += score;
        print_student(student_name, score);   
    }

    // calculate the average score for the whole class
    if (total_students != 0) {
        average_score = static_cast<double>(running_sum) / total_students;
        std::cout << "\nAverage for the class: " << average_score << "\n";
    }

    // close file when we're done with it
    in_file.close();

    return 0;
}
