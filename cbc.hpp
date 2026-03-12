#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

std::vector<unsigned char> encrypt(const std::string& plaintext, const unsigned char* key, const unsigned char* iv) {
	EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();

	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

	std::vector<unsigned char> ciphertext(plaintext.size() + AES_BLOCK_SIZE);
	int len, ciphertext_len;

	EVP_EncryptUpdate(ctx, ciphertext.data(), &len, (unsigned char*)plaintext.c_str(), plaintext.length());
	ciphertext_len = len;

	EVP_EncryptFinal_ex(ctx, ciphertext.data() + len, &len);
	ciphertext_len += len;

	ciphertext.resize(ciphertext_len);
	EVP_CIPHER_CTX_free(ctx);
	return ciphertext;
}

std::string decrypt(const std::vector<unsigned char>& ciphertext, const unsigned char* key, const unsigned char* iv) {
	EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();

	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

	std::vector<unsigned char> plaintext(ciphertext.size());
	int len, plaintext_len;

	EVP_DecryptUpdate(ctx, plaintext.data(), &len, ciphertext.data(), ciphertext.size());
	plaintext_len = len;

	EVP_DecryptFinal_ex(ctx, plaintext.data() + len, &len);
	plaintext_len += len;

	EVP_CIPHER_CTX_free(ctx);
	return std::string((char*)plaintext.data(), plaintext_len);
}
