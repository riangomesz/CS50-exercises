/* Substitution Challenge CS50. In a substitution cipher. We encrypt a message by replacing each letter with another. 
Example: 
$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI --> new aplhabet
plaintext: hello, world
ciphertext: jrssb, ybwsp
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool check_char(string key);

int main(int argc, string argv[])
{
    string plaintext;
    if (argc != 2) {
        printf("Usage: /.substitution key\n");
        return 1;
    }
    if (!check_char(argv[1])) {
        printf("Key must contain 26 unique characters.\n");
        return 1;
    }
    plaintext = get_string("plaintext: ");
}

bool check_char(string key)
{
    int lenght;
    lenght = strlen(key);

    if (lenght != 26) {
        return false;
    }
    for (int i = 0; i < lenght; i++) {
        key[i] = toupper(key[i]);
    }
    for (int i = 0; i < lenght; i++) {
        if (!isalpha(key[i])) {
            return false;
        }
        for (int j = i+1; j < lenght; j++) {
            if (key[i] == key[j]) {
                return false;
            }
        }
    }
    return true;
}
