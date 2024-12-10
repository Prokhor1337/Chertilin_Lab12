#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Message {
public:
    string text;
    string sender;

    Message(string t, string s) : text(t), sender(s) {}

    void send() {
        cout << "Повідомлення відправлено від " << sender << ": " << text << endl;
    }
};

class EncryptedMessage : public Message {
public:
    string encryptionKey;

    EncryptedMessage(string t, string s, string key) : Message(t, s), encryptionKey(key) {}

    void encrypt() {
        for (size_t i = 0; i < text.size(); i++) {
            text[i] ^= encryptionKey[i % encryptionKey.size()];
        }
        cout << "Повідомлення зашифровано." << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Message msg("здарова", "Олександр");
    msg.send();

    EncryptedMessage encMsg("Привіт, але це зашифроване повідомлення", "Іван", "ключ123");
    encMsg.encrypt();
    encMsg.send();

    return 0;
}
