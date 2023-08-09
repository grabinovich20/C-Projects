#ifndef WORD_FUNCTIONS_H
#define WORD_FUNCTIONS_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/**
 * @brief Open the input file stream for the corresponding filename. 
 * Check that the file opened correctly. 
 * The string filename will remain unchanged.
 * 
 * @param in The input file stream
 * @param fileName The string filename to open
 * @return true if the file successfully opened
 * @return false if the file could not be opened 
 */
bool open_file(ifstream &in, string fileName);

/**
 * @brief Read all the words that are in the file stream 
 * and return a vector of all the words 
 * in the order present in the file.
 * 
 * @param in The input file stream
 * @return A vector of strings 
 */
vector<string> read_words_from_file(ifstream &in);

/**
 * @brief For each word in the vector, remove all occurrences
 *  of all the punctuation characters denoted by the punctuation string. 
 * When complete, the input vector will now hold all the words with punctuation removed. 
 * The punctuation string will remain unchanged.
 * 
 * @param v A vector of strings
 * @param punctuation A string of all the punctuation 
 */
void remove_punctuation(vector<string> &v, string punctuation);

/**
 * @brief For each word in the vector, 
 * convert each character to its upper case equivalent. 
 * When complete, the input vector will now hold all the words capitalized.
 * 
 * @param v A vector of strings
 */
void capitalize_words(vector<string> &v);

/**
 * @brief The function will return only the unique words present in the input vector. 
 * The output vector will not contain any duplicate words.
 * 
 * @param v A vector of strings
 * @return A vector of strings
 */
vector<string> filter_unique_words(vector<string> v);

/**
 * @brief The function will count the number of occurrences of each unique word in the entire text. 
 * The output vector will be the same size as the vector of unique words
 *  with element positions corresponding to the same word and count.
 * 
 * @param v A vector of strings containing all the words
 * @param unique A vector of strings containing only the unique words 
 * @return A vector of unsigned integers
 */
vector<unsigned int> count_unique_words(vector<string> v, vector<string> unique);

/**
 * @brief For each word, print out the word and its corresponding count. 
 * 
 * @param v A vector of strings
 * @param count A vector of unsigned integers
 */
void print_unique_word_counts(vector<string> v, vector<unsigned int> count);

/**
 * @brief Finds the location of a word in the vector
 * and saves it to a new vector where it can be sorted.
 * 
 * @param v a vector of stirngs
 * @param word a string
 * @return an integer
 */
int find_word(vector<string> v,string word);

/**
 * @brief Counts the number of occurrences of each letter present in all words.
 * 
 * @param v A vector of strings
 * @param parr An array of 26 unsigned integers
 */
void count_letters(vector<string> v, unsigned int (&parr)[26]);

/**
 * @brief For each letter, print out the letter and its corresponding count. 
 * 
 * @param arr An array of 26 unsigned integers
 */
void print_letter_counts(unsigned int arr[]);

/**
 * @brief Prints the letters with the least and most amount of occurences and
 * the frequency of appearance as a precentage to 3 decimal places
 * 
 * @param arr An array of 26 unsigned integers 
 */
void print_max_min_letter(unsigned int arr[]);

#endif