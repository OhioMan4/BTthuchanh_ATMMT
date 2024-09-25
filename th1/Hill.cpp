#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int mod(int a, int m) { return (a % m + m) % m; }
string hillEncrypt(string &plaintext, vector<vector<int>> key) {
   int n = key.size();
   string rs="";
    string adjustedPlaintext = plaintext;
    if (plaintext.length() % n != 0) {
        adjustedPlaintext += 'X'; 
    }
    vector<int> textVector(adjustedPlaintext.length());
    for (int i = 0; i < adjustedPlaintext.length(); i++) {
        textVector[i] = adjustedPlaintext[i] - 'A'+1;
    }
    for (int i = 0; i < textVector.size(); i += 2) {
        int c1 = mod(key[0][0] * textVector[i] + key[0][1] * textVector[i + 1], 26);
        int c2 = mod(key[1][0] * textVector[i] + key[1][1] * textVector[i + 1], 26);

        rs.push_back((char(c1+'A'-1)));
        rs.push_back((char)(c2+'A'-1));
    }
    return rs;
}
int main() {
    cout<<"Enter the cipher text : ";
    string text;
    getline(cin,text);
    for(auto &x :text){
      x=toupper(x);
    }

    int n;
    cout<<"choose the size of the matrix :(2,3,4,5) : ";
    cin >>n;
    vector<vector<int>> key (n,vector<int>(n));
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout <<"Enter the char at "<<"["<<i<<"]"<<"["<<j<<"]";
        char a;
        cin>>a;
        a=(int)toupper(a)-64;
        key[i][j]=a;
      }
    }
    string option;
    cout<<"Choose option : (D/E) : " ;
    cin.ignore();
    getline(cin,option);
    if(option[0] == 'E'){
    cout << "Enrypt : " << hillEncrypt(text,key) << endl;
    }
    else if(option[0]=='D'){
    }
    return 0;
}
