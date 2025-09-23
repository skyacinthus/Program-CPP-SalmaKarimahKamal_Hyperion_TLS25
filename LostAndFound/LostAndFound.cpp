#include <iostream>
#include <string>
void encode();
void decode();
bool isVowel(char c);

int main(){
    int choice;
    std::cout << "1. Buat kata sandi \n2. Pecah kata sandi \npilihan: ";
    std::cin >> choice;

    // untuk memilih mau encode atau decode
    if (choice == 1){
        encode();
    }
    else if (choice == 2){
        decode();
    }
    else{
        std::cout << "Pilihan tidak valid";
    }
    return 0;
}

void encode(){
    std::string word;
    std::string newWord;
    std::cout << "insert kata: ";
    std::cin >> word;

    // konversi ascii huruf pertama
    int ASCII = (int)word[0];

    // panjang string 
    int length = word.size();
    int j = 0;

    for (int i = 0; i < length; i++){
        if(!isVowel(word[i])){
             newWord.push_back(word[i]);
        }
    }
    
    length = newWord.size();

    // fungsi reverse
    for (int i = 0;  i < length/2; i++){
        char temp = newWord[i];
        newWord[i] = newWord[length - i - 1];
        newWord[length - i - 1] = temp; 
    }

    // insert ascii di tengah 
    int mid = length/2;
    newWord.insert(mid, std::to_string(ASCII));
    std::cout << newWord;
}

void decode(){
    std::string word;
    std::cout << "insert kata: ";
    std::cin >> word;

    int length = word.size();

    for (int i = 0;  i < length/2; i++){
        char temp = word[i];
        word[i] = word[length - i - 1];
        word[length - i - 1] = temp; 
    }

}

bool isVowel(char c) {
    char vowels[] = "aeiouAEIOU"; 
    for (int i = 0; vowels[i] != '\0'; i++) {
        if (c == vowels[i]) {
            return true;
        }
    }
    return false;
}