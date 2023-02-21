/*

Программе на стандартный поток ввода передается последовательность байт.

Необходимо вычислить контрольную сумму SHA-512 и вывести это значение в hex-виде c префиксом 0x.

Используйте API OpenSSL/LibreSSL. Запуск сторонних команд через fork+exec запрещен.

Отправляйте только исходный файл Си-программы с решением.

*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <openssl/sha.h>

const int len = SHA512_DIGEST_LENGTH;

int main()
{
    printf("0x");

    int  num =   0;
    char buff[len];

    SHA512_CTX   x;
    SHA512_Init(&x);

    while (1) {
        int n_read = read(0, buff, len);
        if (n_read <= 0)
            break;
        SHA512_Update(&x, buff, n_read);
    }

    unsigned char hash[len];
    SHA512_Final (hash, &x);

    for (int i = 0; i < len; ++i) {
        printf("%02x", hash[i]);
    }

    fflush(stdout);

    return 0;
}
