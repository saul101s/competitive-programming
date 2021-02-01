#include <cstdio>
int main()
{
  freopen("my-output.txt", "w", stdout);

  // Types declaration
  
  int i; // __int32
  unsigned ui; // unsigned __int32, unsigned int
  char ch; // __int8
  unsigned char uch; // unsigned __int8
  short si; // __int16, short int
  unsigned short usi; // unsigned __int16, unsigned short int
  long li; // long int
  unsigned long uli; // unsigned long int
  long long lli; // __int64
  unsigned long long ulli; // unsigned __int64
  bool b;
  float f;
  double d;
  long double ld; // double
  wchar_t wch; // __wchar_t
  
  printf("%-30s %s\n", "Size of", "bytes");
  printf("=====================================\n");
  
  printf("%-30s %d\n", "int", (int)sizeof i);
  
  printf("%-30s %d\n", "unsigned int", (int)sizeof ui);
  
  printf("%-30s %d\n", "char", (int)sizeof ch);
  
  printf("%-30s %d\n", "unsigned char", (int)sizeof uch);
  
  printf("%-30s %d\n", "short int", (int)sizeof si);
  
  printf("%-30s %d\n", "unsigned short int", (int)sizeof usi);

  printf("%-30s %d\n", "long int", (int)sizeof li);

  printf("%-30s %d\n", "unsigned long int", (int)sizeof uli);
  
  printf("%-30s %d\n", "long long int", (int)sizeof lli);
  
  printf("%-30s %d\n", "unsigned long long int", (int)sizeof ulli);
  
  printf("%-30s %d\n", "bool", (int)sizeof b);
  
  printf("%-30s %d\n", "float", (int)sizeof f);
  
  printf("%-30s %d\n", "double", (int)sizeof d);
  
  printf("%-30s %d\n", "long double", (int)sizeof ld);
  
  printf("%-30s %d\n", "wch", (int)sizeof wch);

  return 0;
}
