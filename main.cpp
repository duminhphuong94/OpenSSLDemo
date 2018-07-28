#include <QCoreApplication>
#include "cipher.h"

QByteArray getPublicKey()
{
    QByteArray testPublicKey;

    testPublicKey.append("-----BEGIN PUBLIC KEY-----\n");
    testPublicKey.append("MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAnqXlIdgpIW6o05RJkxpc\n");
    testPublicKey.append("YpHPQVNpwD/BBpUpWylj72gKSDYU+bfBYFrKNEFfaXmwGhp5lCwaktcYaEl4jL0a\n");
    testPublicKey.append("jd8sZrIY+AnQ7iKLSpz4kjz5DOwtWIhrd1HW9iaJqzOO8ooEmtuih4g/V/NZEI7S\n");
    testPublicKey.append("1BOEDKWUaA2sq5DsXMYA9VJ+tQwauHDmLn8WAf9bZLbGL1ydSbI5bT555sLnmb1D\n");
    testPublicKey.append("noCOxO/I+yDx0ETnv+e0A4WQLvFxh/DwQiqV8TDU0Ve1EX7pjQ0e89rtBxyfmyeS\n");
    testPublicKey.append("DXnlyRNKSEq7XEVb2fz8NEHuMzwDQKGEHagpCL4i7NkZwYMvyTPooQSk5ekE2/M2\n");
    testPublicKey.append("gwIDAQAB\n");
    testPublicKey.append("-----END PUBLIC KEY-----");

    return testPublicKey;
}

QByteArray getPrivateKey()
{
    QByteArray testPrivateKey;

    testPrivateKey.append("-----BEGIN RSA PRIVATE KEY-----\n");
    /*
     *
     * enter your private key here
     *
     *
     */
    testPrivateKey.append("-----END RSA PRIVATE KEY-----");

    return testPrivateKey;
}


void testRSA()
{
    qDebug() << "Loading keys..";
    QByteArray testPrivateKey = getPrivateKey();
    QByteArray testPublicKey = getPublicKey();

    Cipher cWrapper;
    RSA* publickey = cWrapper.getPublicKey(testPublicKey);
    RSA* privatekey = cWrapper.getPrivateKey(testPrivateKey);

    QByteArray plain = "Crypto is the name , writing ciphers is my game...";

    QByteArray encrypted = cWrapper.encryptRSA(publickey,plain);
    QByteArray decrypted = cWrapper.decryptRSA(privatekey,encrypted);


    qDebug() << plain;
    qDebug() << encrypted.toBase64();
    qDebug() << decrypted;

    cWrapper.freeRSAKey(publickey);
    cWrapper.freeRSAKey(privatekey);
}

void testAES()
{
    qDebug() << "Testing AES...";

    Cipher cWrapper;
    QString passphrase = "password";
    QByteArray plain = "Crypto is the name writing ciphers (with aes) is my game...";

    QByteArray encrypted = cWrapper.encryptAES(passphrase.toLatin1(),plain);
    QByteArray decrypted = cWrapper.decryptAES(passphrase.toLatin1(),encrypted);


    qDebug() << plain;
    qDebug() << encrypted.toBase64();
    qDebug() << decrypted;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //testRSA();
    testAES();

    return a.exec();
}
