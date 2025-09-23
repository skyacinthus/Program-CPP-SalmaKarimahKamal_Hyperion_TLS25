#include <iostream>
#include <string>
void encode();
void decode();

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
    std::cout << "insert kata: ";
    std::cin >> word;

    // panjang string 
    int length = word.size();

    int ASCII = (int)word[0];

    // fungsi reverse
    for (int i = 0;  i < length/2; i++){
        char temp = word[i];
        word[i] = word[length - i - 1];
        word[length - i - 1] = temp; 
    }

    int mid = length/2;
    word.insert(mid, std::to_string(ASCII));


    std::cout << word;

}

void decode(){
}
