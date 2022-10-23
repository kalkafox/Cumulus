//
// Created by Kalka on 10/22/2022.
//

#include <iostream>
#include <string>
#include <random>

#include "logging.hpp"

static const std::string WORD_DICTIONARY[] = {
        "embark",
        "shape",
        "traffic",
        "chicken",
        "formal",
        "performance",
        "chin",
        "quantity",
        "net",
        "distribute",
        "volunteer",
        "an",
        "tile",
        "attic",
        "limit",
        "remain",
        "spit",
        "weave",
        "oil",
        "hell",
        "equal",
        "provoke",
        "solid",
        "stuff",
        "relation",
        "frozen",
        "pour",
        "peasant",
        "column",
        "electronics",
        "skin",
        "average",
        "scrape",
        "prejudice",
        "lid",
        "viable",
        "private",
        "tense",
        "enthusiasm",
        "discourage",
        "edition",
        "joystick",
        "month",
        "carry",
        "confidence",
        "banquet",
        "grace",
        "regular",
        "lineage",
        "poetry"
};

static std::random_device rd; // requesting random data from the OS
static std::mt19937 gen(rd()); // seeding the generator
// Define a range between 0 and the size of the dictionary
static std::uniform_int_distribution<> dis(0, sizeof(WORD_DICTIONARY) / sizeof(WORD_DICTIONARY[0]) - 1); // defining the range

void run_tests() {

    std::cout << "Testing common.hpp..." << std::endl;

    println("Hello", "world!");

    print("Hello, world!");

    println();

    print("Hello, ", "world!");

    println();

    std::vector words = {"Hello", "world!"};
    print(words);

    println();

    std::cout << "Testing with random words..." << std::endl;

    println();

    std::vector<std::string> random_words;

    for (int i = 0; i < 250; i++) {
        std::string word = WORD_DICTIONARY[dis(gen)];
        random_words.push_back(word);
        print(word, " ");
    }

    println();

    print(random_words);

    println();

    println("Testing complete!");

}

int main() {
    run_tests();
    return 0;
}
