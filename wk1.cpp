#include <iostream>
#include <string>

//Function to check if DONE has been input
bool checkDone (std::string message, int i) {
    if (message[i] == int{'E'}) {
        if (message[i - 1] == int{'N'}) {
            if (message[i - 2] == int{'O'}) {
                if (message[i - 3] == int{'D'}) {
                    //std::cout << message << "\n";
                    return true;
                }
            }
        }
    } else {
        //std::cout << message << "\n";
        return false;
    }
    return false;
}

void encrypt() {
    //Read in a set of strings
    std::string secretMessage {};
    std::string addWord {};

    //Concatenate until DONE is read
    std::getline(std::cin, secretMessage);
    int len = secretMessage.length();

    while (checkDone(secretMessage, len - 1) == false) {
        std::getline(std::cin, addWord);
        secretMessage.append(addWord);
    }

    //Find average of each character's ASCII value and replace with nearest number
    double avg {0};
    int total {0};
    int numSpaces {0};

    //Erase the last five characters of the string i.e. " DONE"
    secretMessage.erase(secretMessage.end() - 5, secretMessage.end());
    len = secretMessage.length();

    for (int elem : secretMessage) {
        if (elem != int(' ')) {
            total += elem;
        } else if (elem == int(' ')) {
            numSpaces++;
        }       
    }
    int numChar {0};
    numChar = secretMessage.length() - numSpaces;
    avg = static_cast<double>(total) / static_cast<double>(numChar);
    
    //Replaces average value with the closest integer value by adding 0.5 then truncating
    int newAvg {0}; 
    newAvg = static_cast<int>(avg + 0.5);

    //Subtract modified average value from each character's ASCII value of concatenated string
    //If subtracted number is negative, replace it with 0
    std::string encodedMessage {};
    for (int i = 0; i < len; i++) {
        if (int(secretMessage[i]) != int(' ')) {   
            if (secretMessage[i] - newAvg < 0) {
                encodedMessage.push_back(0);
            } else {
                encodedMessage.push_back(secretMessage[i] - newAvg);
            }
        } else if (int(secretMessage[i]) == int(' ')) {
            encodedMessage.push_back(secretMessage[i]);
        }       
    }

    //Print each subtracted number separated by a comma sign
    std::cout << int(encodedMessage[0]);
    for (int i = 1; i < len; i++) {
        if (int(secretMessage[i]) != int(' ')) {
            std::cout << "," << int(encodedMessage[i]);
        }        
    }

}

int main () {

    std::cout << "Please input the message you would like to encode:\n";

    encrypt();

    return 0;
}