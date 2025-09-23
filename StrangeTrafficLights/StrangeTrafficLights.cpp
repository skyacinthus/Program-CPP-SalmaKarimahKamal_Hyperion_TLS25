#include <iostream>

int main(){
    int seconds;
    std::cout << "Seconds: ";
    std::cin >> seconds;
    seconds -= 44;
    seconds %= 103;

    if (seconds <= 3){
        std::cout << "KUNING";
    }
    else if (seconds <= 83){
        std::cout << "MERAH";
    }
    else {
        std::cout << "HIJAU";
    }
    
    return 0;
}
