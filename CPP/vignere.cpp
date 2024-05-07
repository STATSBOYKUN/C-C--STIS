#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <thread>
#include <semaphore.h>
#include <cmath>
#include <condition_variable>
#include <mutex>

using namespace std;

// Class definition for the Vigenere Cipher
class Cipher
{
private:
  string key;
  vector<string> dictionary;

public:
  // Constructor to initialize the Cipher object with a given key
  Cipher(const string &key) : key(key)
  {
    loadDictionary("C://Users/MADOTO/Downloads/words.txt"); // Load dictionary from a file
  }

  // Method to encrypt a message using the Vigenere Cipher
  string encrypt(const string &message, const string &key)
  {
    string encryptedMessage = "";
    int keyLength = key.length();
    int messageLength = message.length();

    // Iterate through each character in the message
    for (int i = 0, j = 0; i < messageLength; i++, j++)
    {
      if (j == keyLength)
      {
        j = 0; // Wrap around the key if it's shorter than the message
      }
      encryptedMessage += ((message[i] + key[j]) % 26) + 'A'; // Perform encryption
    }

    return encryptedMessage;
  }

  // Method to decrypt a message using the Vigenere Cipher
  string decrypt(const string &encryptedMessage, const string &key)
  {
    string decryptedMessage = "";
    int keyLength = key.length();
    int messageLength = encryptedMessage.length();

    // Iterate through each character in the encrypted message
    for (int i = 0, j = 0; i < messageLength; i++, j++)
    {
      if (j == keyLength)
      {
        j = 0; // Wrap around the key if it's shorter than the encrypted message
      }
      char decryptedChar = ((encryptedMessage[i] - key[j] + 26) % 26) + 'A'; // Perform decryption
      decryptedMessage += decryptedChar;
    }

    return decryptedMessage;
  }

  // Method to check if a word is in the dictionary
  bool isWordInDictionary(const string &word) const
  {
    for (const string &dictWord : dictionary)
    {
      if (dictWord == word)
      {
        return true; // Return true if the word is found in the dictionary
      }
    }
    return false; // Return false if the word is not found
  }

  // Method to load the dictionary from a file
  void loadDictionary(const string &filename)
  {
    string word;
    ifstream dictionaryFile(filename);
    if (!dictionaryFile.is_open())
    {
      cerr << "Error opening dictionary file." << endl; // Print error message if dictionary file cannot be opened
      return;
    }

    // Read words from the file and store them in the dictionary vector
    while (getline(dictionaryFile, word))
    {
      dictionary.push_back(word);
    }

    dictionaryFile.close();
  }

  // Method to suggest original sentences based on a decrypted message
  string suggestOriginalSentences(const string &decryptedMessage) const
  {
    string sentence;
    string originalSentences;

    // Iterate through each character in the decrypted message
    for (char c : decryptedMessage)
    {
      if (c == ' ')
      {
        if (isWordInDictionary(sentence))
        {
          originalSentences += sentence + " "; // Append word to original sentences if it's in the dictionary
        }
        sentence.clear(); // Clear sentence buffer
      }
      else
      {
        sentence += c; // Append character to sentence buffer
      }
    }

    if (!sentence.empty() && isWordInDictionary(sentence))
    {
      originalSentences += sentence; // Append last word if it's in the dictionary
    }

    if (originalSentences.empty())
    {
      originalSentences = "[ ]";
    }

    return originalSentences;
  }
};

// Function to decrypt an encrypted message using a random key
void decryptWithRandomKey(const string &encryptedMessage)
{
  string decryptedMessage;
  string key;
  Cipher cipher("");

  // Loop through key lengths 3 to 5
  for (int keyLength = 3; keyLength <= 5; ++keyLength)
  {
    // Nested loop to generate all combinations of keys
    for (int i = 0; i < pow(26, keyLength); ++i)
    {
      int temp = i;
      key = "";
      // Generate key
      for (int j = 0; j < keyLength; ++j)
      {
        key += 'A' + (temp % 26);
        temp /= 26;
      }

      // Perform decryption
      decryptedMessage = cipher.decrypt(encryptedMessage, key);

      // Check if decrypted message contains valid words from the dictionary
      string originalSentences = cipher.suggestOriginalSentences(decryptedMessage);

      // Print decrypted message, key, and original sentences
      cout << "-----------------------------------" << endl;
      cout << "Decrypted message : " << decryptedMessage << endl;
      cout << "Key : " << key << endl;
      cout << "Original Sentences : " << originalSentences << endl;
      cout << "-----------------------------------" << endl;

      cout << endl;
    }
  }
}

int main()
{
  string key, message, temp;
  int choice;
  vector<thread> threads;
  vector<string> dictionary;
  // Define a semaphore to limit the number of simultaneous threads
  sem_t semaphore;

  // Initialize the semaphore in main before creating threadsS
  sem_init(&semaphore, 0, 1);

  Cipher cipher(key); // Create a Cipher object with a given key
  auto start = chrono::high_resolution_clock::now();
  string encryptedMessage, decryptedMessage, originalSentences;
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<float> duration;

  // Main menu loop
  do
  {
    system("cls");
    cout << "Vigenere Cipher\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cout << "3. Quit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter the key: ";
      cin >> key;

      cout << "Enter the message: ";
      cin.ignore();
      getline(cin, message);

      start = chrono::high_resolution_clock::now();
      encryptedMessage = cipher.encrypt(message, key); // Encrypt the message
      end = chrono::high_resolution_clock::now();
      cout << "Encrypted message: " << encryptedMessage << endl;
      cout << "Total time for encryption: " << duration.count() << " seconds" << endl;

      cout << "Enter any key to continue...";
      cin >> temp;
      break;
    case 2:
      cout << "Enter the message: ";
      cin.ignore();
      getline(cin, message);

      start = chrono::high_resolution_clock::now();

      for (int i = 0; i < 5; ++i)
      {
        // Wait until semaphore allows a new thread to start
        sem_wait(&semaphore);

        threads.emplace_back([&]()
                             {
          decryptWithRandomKey(encryptedMessage);
          
          // Release semaphore when the thread finishes execution
          sem_post(&semaphore); });
      }

      // Join threads
      for (auto &t : threads)
      {
        t.join();
      }

      threads.clear(); // Clear the threads vector for the next decryption operation

      end = chrono::high_resolution_clock::now();

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
