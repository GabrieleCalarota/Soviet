#include "MyLibrary.hpp"

void initTermios(int echo) 
{
  tcgetattr(0, &old); 
  nuovo = old; 
  nuovo.c_lflag &= ~ICANON; 
  nuovo.c_lflag &= echo ? ECHO : ~ECHO; 
  tcsetattr(0, TCSANOW, &nuovo); 
}

void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

void beep(){
cout<<"\7"<<"\a";
}

char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

char getch(void) 
{
  return getch_(0);
}

int kbhit(void)
{ 
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getch();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if((ch) != EOF)
  {
    ungetc(ch, stdin);
    return 1;
    
  }
 
  return 0;
}



void slow_print(const char *text){   //int speed
   while ((!kbhit())&&(*text)!='\0'){
     cout<<(*text)<<flush;
     if (!kbhit())     
     usleep(PRINT_MEDIUM);
     text++;
      }
   cout<<flush;
   if (kbhit()) getchar();
   while ((*text)!='\0'){
     cout<<(*text)<<flush;
     text++;
   }
      
}

bool uguali(char a[], char b[]){
bool flag=true;
int n1=strlen(a);
int n2=strlen(b);
if (n1!=n2)
 return false;
else{int i=0;
 while ((flag)&&(i<n1)){
 if (a[i]!=b[i])
  flag=false;
 else
  i++;
 }
 return flag;
}
}

void clear_input(char *s,const int M){
for (int i=0;i<M;i++){
*s='\0';
s++;
}
}

void loading(){
    for (int i=0;i<3;i++){
      cout<<"\r.                            ";
      cout<<"\r.";
      for (int s=0;s<10;s++){usleep(100000);
      slow_print((char*)".");}
      }
}

void clear_screen(){
cout<<"\033[2J\033[1;1H";
}
