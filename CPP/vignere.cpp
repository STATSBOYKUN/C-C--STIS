#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

//  function to encrypt the message
string encrypt(string message, string key)
{
  string encryptedMessage = "";
  int keyLength = key.length();
  int messageLength = message.length();
  char newKey[messageLength];

  for (int i = 0, j = 0; i < messageLength; i++, j++)
  {
    if (j == keyLength)
    {
      j = 0;
    }
    newKey[i] = key[j];
  }

  for (int i = 0; i < messageLength; i++)
  {
    encryptedMessage += ((message[i] + newKey[i]) % 26) + 'A';
  }

  return encryptedMessage;
}

bool isWordInDictionary(const string &word, const vector<string> &dictionary)
{
  for (const string &dictWord : dictionary)
  {
    if (dictWord == word)
    {
      return true;
    }
  }
  return false;
}

string suggestOriginalSentences(const string &decryptedMessage)
{
  vector<string> dictionary;
  string word;
  ifstream dictionaryFile("C://Users/MADOTO/Downloads/words.txt"); // Replace with the path to your English dictionary file

  // Load English dictionary into memory
  while (getline(dictionaryFile, word))
  {
    dictionary.push_back(word);
  }

  string sentence;
  string originalSentences;

  // Split decrypted message into words
  for (char c : decryptedMessage)
  {
    if (c == ' ')
    {
      // Check if the word exists in the dictionary
      if (isWordInDictionary(sentence, dictionary))
      {
        originalSentences += sentence + " ";
      }
      sentence.clear();
    }
    else
    {
      sentence += c;
    }
  }

  // Check the last word in the decrypted message
  if (!sentence.empty() && isWordInDictionary(sentence, dictionary))
  {
    originalSentences += sentence;
  }

  return originalSentences;
}

//  function to decrypt the message
string decrypt(string encryptedMessage, string key)
{
  string decryptedMessage = "";
  int keyLength = key.length();
  int messageLength = encryptedMessage.length();
  char newKey[messageLength];

  for (int i = 0, j = 0; i < messageLength; i++, j++)
  {
    if (j == keyLength)
    {
      j = 0;
    }
    newKey[i] = key[j];
  }

  for (int i = 0; i < messageLength; i++)
  {
    decryptedMessage += (((encryptedMessage[i] - newKey[i]) + 26) % 26) + 'A';
  }

  return decryptedMessage;
}

int main()
{
  string key, message;

  cout << "Enter the key: ";
  cin >> key;

  cout << "Enter the message: ";
  cin >> message;

  // Calculate total time
  float totalTime = 0;
  auto start = chrono::high_resolution_clock::now();

  cout << "Encrypted message: " << encrypt(message, key) << endl;

  // Total time for encryption
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<float> duration = end - start;
  totalTime += duration.count();
  cout << "Total time for encryption: " << totalTime << " seconds" << endl;

  // Calculate total time
  totalTime = 0;
  start = chrono::high_resolution_clock::now();

  cout << "Decrypted message: " << suggestOriginalSentences(decrypt(encrypt(message, key), key)) << endl;

  // Total time for decryption
  end = chrono::high_resolution_clock::now();
  duration = end - start;
  totalTime += duration.count();
  cout << "Total time for decryption: " << totalTime << " seconds" << endl;

  return 0;
}