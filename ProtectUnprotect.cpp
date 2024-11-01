#include <Windows.h>
#include <iostream>
#include <vector>
#pragma comment (lib, "Crypt32.lib")

void PrintDataBlob(DATA_BLOB DataToPrint) {
	std::cout << "DATA BLOB SIZE : " << DataToPrint.cbData << "\n";
	std::cout << "DATA BLOB {{{{";
	for (int x = 0; x < DataToPrint.cbData; x++) {
		std::cout << DataToPrint.pbData[x];;
	}
	std::cout << "}}}}\n";
}

DATA_BLOB CryptProtect(std::string ToEncrypt) {
	DATA_BLOB EncryptedIn;
	EncryptedIn.cbData = ToEncrypt.size();
	EncryptedIn.pbData = new BYTE[ToEncrypt.size()];
	memcpy(EncryptedIn.pbData, ToEncrypt.c_str(), ToEncrypt.size());
	DATA_BLOB EncryptedOut;
	EncryptedOut.cbData = 100;
	EncryptedOut.pbData = 0;
	CryptProtectData(&EncryptedIn, NULL, NULL, NULL, NULL, NULL, &EncryptedOut);
	return EncryptedOut;
}

DATA_BLOB CryptUnprotect(DATA_BLOB ToDecrypt) {
	DATA_BLOB DecryptedOut;
	DecryptedOut.cbData = 100;
	DecryptedOut.pbData = 0;
	CryptUnprotectData(&ToDecrypt, NULL, NULL, NULL, NULL, NULL, &DecryptedOut);
	return DecryptedOut;
}

// DATA IS IN FORM OF DATA_BLOB CUS THATS RAW
int main() {
	DATA_BLOB EncryptedData = CryptProtect("testing lol21");
	PrintDataBlob(EncryptedData);
	DATA_BLOB DecryptedData = CryptUnprotect(EncryptedData);
	PrintDataBlob(DecryptedData);
	return 69;
}
