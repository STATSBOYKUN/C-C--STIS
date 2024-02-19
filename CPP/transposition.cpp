#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <stdlib.h>
#include <cmath>

using namespace std;

string encrypt(string& plaintext, int rows, int columns) {
    string ciphertext;
    int length = plaintext.length();
    int extraChars = rows * columns - length % (rows * columns);
    plaintext.append(extraChars, ' ');

    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
            ciphertext += plaintext[j * columns + i];
        }
    }

    return ciphertext;
}

string decrypt(string& ciphertext, int rows, int columns) {
    string decryptedText;
    int length = ciphertext.length();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            decryptedText += ciphertext[j * rows + i];
        }
    }

    size_t pos = decryptedText.find_last_not_of(' ');
    if (pos != string::npos) {
        decryptedText.erase(pos + 1);
    }

    return decryptedText;
}

int main()
{
  string message, temp;
  int row, column, choice = 0;
  auto start = chrono::high_resolution_clock::now();
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<float> duration;

  do
  {
    system("cls");
    cout << "Transposition Cipher\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cout << "3. Quit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter the message: ";
      cin.ignore();
      getline(cin, message);

      cout << "Enter the row: ";
      cin >> row;

      cout << "Enter the column: ";
      cin >> column;

      cout << "Original Message: " << message << endl;

      start = chrono::high_resolution_clock::now();

      cout << "Encrypted Message: " << encrypt(message, row, column) << endl;

      end = chrono::high_resolution_clock::now();
      duration = end - start;
      cout << "Total time for encryption: " << duration.count() << " seconds" << endl;
      
      cout << "Enter any key to continue...";
      cin >> temp;
      break;
    case 2:
      cout << "Enter the message: ";
      cin.ignore();
      getline(cin, message);

      cout << "Enter the row: ";
      cin >> row;

      cout << "Enter the column: ";
      cin >> column;

      cout << "Original Message: " << message << endl;

      start = chrono::high_resolution_clock::now();
      cout << "Decrypted Message: " << decrypt(message, row, column) << endl;
      end = chrono::high_resolution_clock::now();
      duration = end - start;
      cout << "Total time for encryption: " << duration.count() << " seconds" << endl;

      cout << "Enter any key to continue...";
      cin >> temp;
      break;
    case 3:
      cout << "Goodbye!" << endl;
      break;
    default:
      cout << "Invalid choice" << endl;
    }
  } while (choice != 3);

  return 0;
}
