/* CSCI 200: Assignment 3: Green Eggs and Ham
 *
 * Author: Gary Rabinovich
 * 
 * For this assignment, you will read in a text file 
 * containing the story Green Eggs and Ham (plus some others). 
 * You will then need to count the number of occurrences of 
 * each word & letter and display the frequencies
 */

#include "word_functions.h"
#include <iomanip>

bool open_file(ifstream &in, string fileName){
    fileName = "input/" + fileName;
    in.open(fileName);
    if(in.fail()){
        cerr << "We could not open the file " << fileName << endl;
        return false;
    }else{
        return true;
    }
}

vector<string> read_words_from_file(ifstream &in){
    vector<string> v;
    string word;
    while(in >> word){
        v.push_back(word);
    }
    return v;
}

void remove_punctuation(vector<string> &v, string punctuation){
    string word;
    for(int i = 0; i < v.size(); i++){
        word = v[i];
        for(int j = 0; j < word.length(); j++){
            for(int k = 0; k < punctuation.length(); k++){
                if(word[j] == punctuation[k]){
                    word.erase(j--,1);
                }
            }
        }
        v[i] = word;
    }
}

void capitalize_words(vector<string> &v){
    string word;
    for(int i = 0; i < v.size(); i++){
        word = v[i];
        for(int j = 0; j < word.length(); j++){
            word[j] = toupper(word[j]);
        }
        v[i] = word;
    }
}

vector<string> filter_unique_words(vector<string> v){
    vector<string> unique;
    bool found = false;
    for(int i = 0; i < v.size(); i++){
        found = false;
        for(int j = 0; j < unique.size(); j++){
            if(unique.at(j) == v[i]){
                found = true;
                break;
            }
        }
        if (!found) {
            unique.push_back(v.at(i));
        }
 
    }
    return unique;
}

vector<unsigned int> count_unique_words(vector<string> v, vector<string> unique){
    vector<unsigned int> count(unique.size());
    for(int j = 0; j < unique.size(); j++){
        count.at(j) = 0;
    }
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < unique.size(); j++){
            if(unique.at(j) == v[i]){
                count.at(j)++;
            }
        }
    }
    return count;
}

void print_unique_word_counts(vector<string> v, vector<unsigned int> count){
    vector<string> sorted(v); 
    sort (sorted.begin(), sorted.end());
    
    for(int i = 0; i < v.size(); i++){
        int index = find_word(v, sorted.at(i));
        cout << left << sorted.at(i) << setw(10 - sorted.at(i).length()) << right << ":" << setw(10) << right << count.at(index) << endl;
    }
}

int find_word(vector<string> v,string word){
    for(int i = 0; i < v.size(); i++){
        if(v.at(i) == word){
            return i;
        }
    }
    return -1;
}

void count_letters(vector<string> v, unsigned int (&parr)[26]){
    string word;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < v.size(); i++){
        word = v.at(i);
        for(int j = 0; j < word.length(); j++){
            for(int k = 0; k < 26; k++){
                if(alphabet[k] == word[j]){
                    *(parr + k) += 1;
                }
            }
        }
    }
}


void print_letter_counts(unsigned int arr[]){
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < 26; i++){
        cout << left << alphabet[i] << ": " << setw(10) << right << arr[i] << endl;
    }
}

void print_max_min_letter(unsigned int arr[]){
    int min(arr[0]), max(arr[0]), total(arr[0]);
    int min_index = -1, max_index = -1;
    float frequencyMin, frequencyMax;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 1; i < 26; i++){
        total += arr[i];
        if(arr[i] >= max){
            if (max == arr[i]) {
                if (max_index == -1) {
                   max_index = i;
                }
            } else {
                max = arr[i];
                max_index = i;
            }
            
        }else if(arr[i] <= min){
            if (min == arr[i]) {
                if (min_index == -1) {
                   min_index = i;
                }
            } else {
                min = arr[i];
                min_index = i;
            }
        }
    }
    frequencyMin = (float) min / (float)total * 100;
    frequencyMax = (float)max / (float)total * 100;
    cout << "Least Frequent Letter: " << alphabet[min_index] << " " << right << setw(10) << fixed << setprecision(3) << min << " " << frequencyMin << endl;
    cout << " Most Frequent Letter: " << alphabet[max_index] << " " << right << setw(10) << fixed << setprecision(3) << max << " " << frequencyMax << endl;
}

