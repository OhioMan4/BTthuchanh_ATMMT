#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
string encryptMessage(const string& message, const string& key) {
    string cipherText = "";
    for (size_t i = 0; i < message.length(); i++) {
        char encChar = (message[i] + (key[i]%26))%26+'A' ;
        cipherText += encChar;
    }
    return cipherText;
}

string generateKey(const string& message, const string& key) {
    string newKey = key;
    while (newKey.length() < message.length()) {
        newKey += key;
    }
    return newKey.substr(0, message.length());
}
string decryptMessage(const string& cipherText, const string& key) {
    string plainText = "";
    for (size_t i = 0; i < cipherText.length(); i++) {
        char decChar = (cipherText[i] - key[i] + 26) % 26+'A';
        plainText += decChar;
    }
    return plainText;
}
string uppercasse(string &input){
  string rs=input;
  transform(rs.begin(),rs.end(),rs.begin(),::toupper);
  return rs;
}
int main() {
    string message;
    string keyword;

    cout << "Enter the message to encrypt : ";
    getline(cin, message);
    cout << "Enter the key ";
    getline(cin, keyword);
    message=uppercasse(message);
    keyword=uppercasse(keyword);
    keyword=generateKey(message,keyword);
    string option;
    cout<<"Choose option : (D/E) ; " ;
    getline(cin,option);
    if(option[0] == 'E'){
    string rs=encryptMessage(message,keyword);
    cout<<"Encrypted Text :"<<rs<<endl;
    }
    else{
    string ds=decryptMessage(message,keyword);
    cout<<"Decrypted Text :"<<ds<<endl;
    }
    return 0;
}
