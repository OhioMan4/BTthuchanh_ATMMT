#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

#define SIZE 5
void generateKeyMatrix(string key, char keymatrix[SIZE][SIZE])
{
  bool used[26] = {false};
  used['J' - 'A'] = true;
  key.erase(remove(key.begin(), key.end(), 'J'), key.end());

  int x = 0, y = 0;
  for (char &ch : key)
  {
    ch = toupper(ch);
    if (!used[ch - 'A'])
    {
      keymatrix[y][x++] = ch;
      used[ch - 'A'] = true;
      if (x == SIZE)
        x = 0, y++;
    }
  }
  for (char cha = 'A'; cha <= 'Z'; ++cha)
  {
    if (!used[cha - 'A'])
    {
      keymatrix[y][x++] = cha;
      if (x == SIZE){
        x = 0;
        y++;
      }
    }
  }
}
void displayMatrix(char matrix[SIZE][SIZE])
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}
string prepareText(string text)
{
  text.erase(remove(text.begin(), text.end(), ' '), text.end());
  for (char &ch : text)
    ch = toupper(ch);
  for (int i = 0; i < text.length(); i += 2)
  {
    if (i + 1 == text.length() || text[i] == text[i + 1])
      text.insert(i + 1, "X");
  }
  return text;
}
void findPosition(char matrix[SIZE][SIZE], char ch, int &row, int &col)
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (matrix[i][j] == ch)
      {
        row = i;
        col = j;
        return;
      }
    }
  }
}
string playfairCipher(string text, char matrix[SIZE][SIZE], bool encryted)
{
  string rs = "";
  for (int i = 0; i < text.length(); i += 2)
  {
    int r1, c1, r2, c2;
    findPosition(matrix, text[i], r1, c1);
    findPosition(matrix, text[i + 1], r2, c2);
    if (r1 == r2)
    {
      rs += matrix[r1][(c1 + (encryted ? 1 : SIZE - 1)) % SIZE];
      rs += matrix[r2][(c2 + (encryted ? 1 : SIZE - 1)) % SIZE];
    }
    else if (c1 == c2)
    {
      rs += matrix[(r1 + (encryted ? 1 : SIZE - 1)) % SIZE][c1];
      rs += matrix[(r2 + (encryted ? 1 : SIZE - 1)) % SIZE][c2];
    }
    else
    {
      rs += matrix[r1][c2];
      rs += matrix[r2][c1];
    }
  }
  return rs;
}
int main()
{
  string key, text;
  char keymatrix[SIZE][SIZE];
  cout << "Enter the key :";
  getline(cin, key);
  cout << "Enter the plain text";
  getline(cin, text);
  generateKeyMatrix(key, keymatrix);
  displayMatrix(keymatrix);
  bool encryted = true;
  char choice;
  cout << "encryt or Decrypt (choose E or D): ";
  cin >> choice;
  encryted=(choice=='E');
  text = prepareText(text);
  string rs = playfairCipher(text, keymatrix, encryted);
  encryted ? cout << "encryted text : " << rs : cout << "decryted text :" << rs;

  return 0;
}