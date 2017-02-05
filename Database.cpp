#include "Database.hpp"
#include "InfoEnemy.hpp"

 Database::Database(){						
  for (int i=0;i<max_enemy;i++) 
   enemy[i].found=false;
  strcpy(enemy[0].i,station_keeper_enemy_info);
  strcpy(enemy[1].i,toxic_nurse_enemy_info);
  strcpy(enemy[2].i,energumen_mutated_enemy_info);
  strcpy(enemy[3].i,scaled_experiment_enemy_info);
  strcpy(enemy[4].i,river_guardian_enemy_info);
  strcpy(enemy[5].i,sewer_walker_enemy_info);
  strcpy(enemy[6].i,underground_prisoner_enemy_info);
  strcpy(enemy[7].i,mad_doctor_enemy_info);
  strcpy(enemy[8].i,improved_soldier_enemy_info);
  strcpy(enemy[9].i,cyborg_fighter_enemy_info);}

 bool Database::is_empty(){					
   bool flag=true;
   for (int i=0;i<10;i++){
   if (enemy[i].found) 
    flag=false;}
  return flag;}

 int Database::num_found(){					
   int c=0;
   for (int i=0;i<10;i++)
     if (enemy[i].found)
       c++;
   return c;}

 void Database::add_enemy(type_monster m){			
  int i=(int) (m);
  i=i%max_enemy; 
  enemy[i].found=true;}
  

 bool Database::is_empty(info* a,const int n){			
  bool flag=true;
  for (int i=0;i<n;i++){
   if (a->found) 
    flag=false;
   a++;}
  return flag;}


 void Database::show_database(){				
  if ((is_empty(&enemy[0],max_enemy))){
   clear_screen();
   slow_print((char*)"ARCHIVIO VUOTO!\n"); cout<<"(Premi un tasto per continuare..)\n"; 
   getch(); 
   clear_screen();}
  else{
   bool esc=false;
   while (!esc){
    clear_screen();
    int n=max_enemy;
    info *a=&enemy[0];
    clear_screen();
    if (!esc){
     char c='a';
     int i=0;
     cout<<"[Premi 'a' per scorrere indietro, 'd' per scorrere avanti, 'f' per uscire]\n\n";
     while (!a->found){
      i++; 
      if (i>=(n)){
       a-=((n)+1); 
       i=0;}
      else
       a++;} 
     cout<<a->i;
     bool esc2=false;
     while (!esc2){
      bool flag=false;
      do{
       c=getch();
       switch (c){
         case ('d'):{ 
          do{
           i++; 
           if (i>=(n)){
            a=a-(n)+1; 
            i=0;} 
           else
           a++;} 
          while(!a->found); 
           flag=false; break;}
         case ('a'):{ 
          do{
           i--; 
          if (i<0){
           a+=((n)-1);
           i=((n)-1);} 
          else 
           a--;}
          while (!a->found); 
           flag=false; break;}
         case ('f'):{
          esc2=true; 
          esc=true; 
          flag=false; break;}
         default:{flag=true; break;}}}
      while (flag);
     clear_screen();
     cout<<"[Premi 'a' per scorrere indietro, 'd' per scorrere avanti, 'f' per uscire]\n"<<endl;
     cout<<a->i;}}}
   clear_screen();}}
