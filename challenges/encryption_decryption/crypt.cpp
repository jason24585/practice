#include <iostream>
#include <fstream>
#include <limits>

/* Encryption function using Caesar cipher */
void encrypt(std::string ifilename, std::string ofilename, int key){
    /* Open files */
    std::ifstream ifile(ifilename);
    std::ofstream ofile(ofilename, std::ofstream::trunc);

    if(!ifile.is_open()){
        std::cerr << "File could not be opened." << std::endl;
        return;
    }

    /* Encrypt each byte in file */
    char byte;
    while(ifile.get(byte)){
        byte += key;
        ofile << byte;
    }

    /* Close files */
    ifile.close();
    ofile.close();
}

/* Decryption file using Caesar cipher */
void decrypt(std::string ifilename, std::string ofilename, int key){
    /* Open files */
    std::ifstream ifile(ifilename);
    std::ofstream ofile(ofilename, std::ofstream::trunc);

    if(!ifile.is_open()){
        std::cerr << "File could not be opened." << std::endl;
        return;
    }

    /* Decrypt each byte in file */
    char byte;
    while(ifile.get(byte)){
        byte -= key;
        ofile << byte;
    }

    /* Close files */
    ifile.close();
    ofile.close();
}

int main(){
    /* Print title */
    std::cout << "*** Encryption/Decryption ***" << std::endl << std::endl;

    /* Ask user if encrypt or decrypt */
    std::string input;
    std::cout << "Select encrypt or decrypt [e/d]: " << std::endl;
    while(true){
        std::getline(std::cin, input);
        if(input != "e" && input != "d"){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. [e/d]" << std::endl;
            continue;
        }
        break;
    }

    /* Get filenames */
    std::string ifilename;
    std::string ofilename;

    std::cout << "Enter filename to read from: " << std::endl;
    std::getline(std::cin, ifilename);
    std::cout << "Enter filename to write to: " << std::endl;
    std::getline(std::cin, ofilename);

    /* Get key for cipher shift */
    int key;
    std::cout << "Enter encryption key [%d]: " << std::endl;
    while(!(std::cin >> key)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid integer." << std::endl;
    }

    /* Call encryption/decryption functions */
    std::string result;
    if(input == "e"){
        encrypt(ifilename, ofilename, key);
        result = "encrypted";
    }
    else if(input == "d"){
        decrypt(ifilename, ofilename, key);
        result = "decrypted";
    }

    /* Print result */
    std::cout << ifilename << " " << result << " in " << ofilename << "." << std::endl;

    return 0;
}
