int A[10] =
 {
  11, 2, 33, 4, 15, 6, 7, 8, 9, 10
 };

main ()
 {
  int min, max;
  MinMaxIt (A, 10, &min, &max) ;
//printf ("MinMaxIt = %d %d \n", min, max) ;
  print_str("MinMaxIt = ");
  print_int(min); print_str("  ");
  print_int(max); print_str("\n");
  return(0);
 }

MinMaxIt (A, n, _min, _max)
register int * A;
register unsigned int n;
register int * _min;
register int * _max;
 {
  register int min asm ("s5") ;
  register int max asm ("s6") ;
  register int *p  asm ("s7") ;
  min = A[0];
  max = A[0];
  for (p = &A[1]; p < &A[n]; p ++ ) 
   {
    if ( * p < min) min = * p;
    if ( * p > max) max = * p;
   }
  * _max = max;
  * _min = min;
  return(0);
 }

__main ()
 {
  return(0);
 }

dummy (v)
int v;
 {
  return(0);
 }

print_int (value)
int value;
 {
  int code;
  code = 1;
  asm (
       "add $a0,%1,$zero\n\t"
       "add $v0,%0,$zero\n\t"
       "syscall"
       :
       : "r" (code), "r" (value));
  return(value);
 }

print_hex (value)
int value;
 {
  char s[10];
  itox(value,s);
  print_str(s);
  return(value);
 }

print_str (str)
char *str;
 {
  int code;
  code = 4;
  asm (
       "add $a0,%1,$zero\n\t"
       "add $v0,%0,$zero\n\t"
       "syscall"
       :
       : "r" (code), "r" (str));
  return(0);
 }

/*
  itox converts v to eight hex digits and stores them in str[]
  such that str[0] is the leftmost digit (msd) and str[7] is the rightmost
(lsd)
*/

itox (v,str)
int v;
char *str;
 {
  int i, j, t;
  j = 7;
  for (i = 0; i < 8; i++)
   {
    t = v & 0x0f;
    if (t < 10) str[j] = t + '0';
     else str[j] = t - 10 + 'A';
    v = v >> 4;
    j--;
   }
  str[8] = 0;
  return(v);
 }

print_stack (var0)
int var0;
 {
  int *p, v, i, k;
  k = 42;
  p = &var0;
  v = (int) p;
  print_hex(v);
  print_str("\n");
  p = p - 20;
  for (i = 0; i < 82; i++)
   {
    v = (int) p;    print_hex(v);    print_str("  ");
    v =      *p;    print_hex(v);    print_str("\n");
    p++;
   }
  return(k);
 }
