#ifndef DES_H
#define DES_H

typedef unsigned long long int DES_Value;

class DES
{
public:
  DES();
  ~DES();
  DES_Value Encrypt(const DES_Value& key, const DES_Value& data);
  DES_Value Decrypt(const DES_Value& key, const DES_Value& data);
private:
  enum DES_Mode
  {
    EncryptMode,
    DecryptMode
  };
  DES_Value Action(const DES_Value& key, const DES_Value& data,const DES_Mode& flag);
  void SubKey(const DES_Value& key);
  DES_Value Transposition(const DES_Value& value);
  DES_Value InverseTransposition(const DES_Value& value);
  DES_Value Extend_E(const DES_Value& value);
  DES_Value Parse_S(const DES_Value& value);
  DES_Value Pos_P(const DES_Value& value);
  DES_Value _keys[16];
  static const int _IP_func[64];
  static const int _IP_inv_func[64];
  static const int _PC_1_func[56];
  static const int _PC_2_func[48];
  static const int _Key_Left_Shift[16];
  static const int _E[48];
  static const int _S[8][4][16];
  static const int _P[32];
};


#endif
