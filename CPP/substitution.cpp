#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <chrono>

using namespace std;

string encrypt(string plaintext, int key)
{
  string ciphertext = plaintext;

  for (int i = 0; i < plaintext.length(); ++i)
  {

    if (islower(plaintext[i]))
    {
      ciphertext[i] = 'a' + (plaintext[i] - 'a' + key) % 26;
    }

    else if (isupper(plaintext[i]))
    {
      ciphertext[i] = 'A' + (plaintext[i] - 'A' + key) % 26;
    }
  }

  return ciphertext;
}
string decrypt(string ciphertext, int key)
{
  string plaintext = ciphertext;

  for (int i = 0; i < ciphertext.length(); ++i)
  {

    if (islower(ciphertext[i]))
    {
      plaintext[i] = 'a' + (ciphertext[i] - 'a' - key + 26) % 26;
    }

    else if (isupper(ciphertext[i]))
    {
      plaintext[i] = 'A' + (ciphertext[i] - 'A' - key + 26) % 26;
    }
  }

  return plaintext;
}

int main()
{
  string text, temp;
  int key, choice;
  auto start = chrono::high_resolution_clock::now();
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<float> duration;

  do
  {
    system("cls");
    cout << "Substitution Cipher\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cout << "3. Quit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter plaintext: ";
      cin.ignore();
      getline(cin, text);
      cout << "Enter key: ";
      cin >> key;

      start = chrono::high_resolution_clock::now();
      cout << "Encrypted text: " << encrypt(text, key) << endl;
      end = chrono::high_resolution_clock::now();
      duration = end - start;

      cout << "Total time for encryption: " << duration.count() << " seconds" << endl;

      cout << "Enter any key to continue...";
      cin >> temp;
      break;
    case 2:
      cout << "Enter ciphertext: ";
      cin.ignore();
      getline(cin, text);
      cout << "Enter key: ";
      cin >> key;

      start = chrono::high_resolution_clock::now();
      cout << "Decrypted text: " << decrypt(text, key) << endl;
      end = chrono::high_resolution_clock::now();
      duration = end - start;

      cout << "Total time for decryption: " << duration.count() << " seconds" << endl;
      
      cout << "Enter any key to continue...";
      cin >> temp;
      break;
    case 3:
      cout << "Exiting...\n";
      break;
    default:
      cout << "Invalid choice. Please enter a valid option.\n";
    }
  } while (choice != 3);

  return 0;
}
