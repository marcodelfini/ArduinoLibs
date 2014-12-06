#include <Base64.h>

String Base64_Encode(String b) {
  int len = b.length();
  char tok[len];
  char gatavais[len];
  int i = 0;

  while (i <= len - 1) {
    tok[i] = b.charAt(i);
    i++;
  }
  base64_encode(gatavais, tok, len);

  return String(gatavais);
}

String Base64_Decode(String b) {
  int len = b.length();
  char tok[len];
  char gatavais[len];
  int i = 0;

  while (i <= len - 1) {
    tok[i] = b.charAt(i);
    i++;
  }
  base64_decode(gatavais, tok, len);

  return String(gatavais);
}

void setup() {
  Serial.begin(9600);

  String Base = "Testing";
  String enc = Base64_Encode(Base);
  String dec = Base64_Decode(enc);

  if (!dec.equals("")) {
    if (dec.equals(Base)) {
      Serial.print("OK ");
      Serial.println(dec);
    } else {
      Serial.println("Not decrypted!");
      Serial.println(dec);
    }
  } else {
    Serial.println("Error!");
    Serial.println(dec);
  }
}

void loop() {

}
