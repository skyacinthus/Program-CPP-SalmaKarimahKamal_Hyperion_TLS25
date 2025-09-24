#include <iostream>
#include <string>
void encode();
void decode();
bool isVowel(char c);
std::string reverse(std::string word, int length);

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

// membuat sandi
void encode(){
    std::string word;
    std::string newWord;
    std::cout << "insert kata: ";
    std::cin >> word;

    // konversi ascii huruf pertama
    int ascii = (int)word[0];

    // panjang string 
    int j = 0;

    // menghilangkan huruf vokal
    for (int i = 0; i < word.size(); i++){
        if(!isVowel(word[i])){
            newWord.push_back(word[i]);
        }
    }

    // fungsi reverse
    newWord = reverse(newWord, newWord.size());

    // insert ascii di tengah 
    int mid = newWord.size()/2;
    newWord.insert(mid, std::to_string(ascii));
    std::cout << newWord;
}

void decode(){
    std::string word;
    std::cout << "insert kata: ";
    std::cin >> word;

    // tentukan letak integer
    int start = -1;
    int end = -1;
    for (int i = 0; i < word.size(); i++){
        if (isdigit(word[i])){
            if (start == -1){
                start = i;
            } 
            end = i;
        }
    }
    
    // ambil dan konversi ascii
    std::string asciiStr = word.substr(start, end - start + 1);
    int asciiVal = std::stoi(asciiStr);
    char firstChar = (char)asciiVal;

    // hapus angka dari kata
    word.erase(start, end - start + 1);

    // fungsi reverse
    word = reverse(word, word.size());

    if (word[0] == firstChar){
        std::cout << word;
    }
    else{
        std::cout << firstChar << word  ;
    }
}

// fungsi reverse
std::string reverse(std::string word, int length){
    for (int i = 0;  i < length/2; i++){
        char temp = word[i];
        word[i] = word[length - i - 1];
        word[length - i - 1] = temp; 
    }
    return word;
}

// cek huruf vokal atau bukan
bool isVowel(char c) {
    char vowels[] = "aeiouAEIOU"; 
    for (int i = 0; vowels[i] != '\0'; i++) {
        if (c == vowels[i]) {
            return true;
        }
    }
    return false;
}