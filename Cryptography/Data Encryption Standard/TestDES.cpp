#include <iostream>
#include "../src/DES.h"

using namespace std;

int main()
{
  DES Encryptor;
  DES_Value data = (((DES_Value)0x01234567) << 32) | 0x89abcdef;  // 0x0123456789abcdef
  DES_Value key = (((DES_Value)0x13345779) << 32) | 0x9BBCDFF1;
  DES_Value inf = Encryptor.Encrypt(key, data);
  cout << hex << inf << endl;
  cout << hex << Encryptor.Decrypt(key,inf) << endl;
}
