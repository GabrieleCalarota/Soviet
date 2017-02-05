#include "Map.hpp"
#include "Enemy.hpp"
#include "Boss.hpp"
#include "Player.hpp"
#include "Node.hpp"
#include "Coda.hpp"
#include "Inventario.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Hash.hpp"
#include "Visore.hpp"


 Map::Map(Node* start,int level){
  firstnode=start;
  piano=level;
  head_coordinate=new Hash(383,11);
  head_coordinate=head_coordinate->Hash_Insert(0,0,start);
  adrenalina_data=0;
  battery_data=0;
  enemies_found=0;
  med_pack_found=0;
  antidotes_found=0;
  keys_found=0;
  lockers_found=0;
  boss=NULL;
  if (piano==2)
        generate_river(river,max_length_river);}
  

 Node* Map::get_node(int x,int y) {return head_coordinate->get_node(x,y);}
 

 void Map::give_gift(Node* curr_position,Player* p){
  switch (piano){
    case (1): {bool flag=false;
               do{      
                int n=rand()%100;
                gift_type monster_gift;
                if (n<(10+p->get_luck())){
                 monster_gift=(gift_type) (rand()%5);}
                else{
                 if (n<(30+p->get_luck())){
                  monster_gift=(gift_type) (rand()%3+2);}
                 else{
                  monster_gift=(gift_type) (rand()%2+2);}}
                switch (monster_gift){
                  case (a_weapon): {weapon_type weapon=(weapon_type) (rand()%6);
                                    Weapon* w=new Weapon(weapon);
                                    cout<<"Hai trovato\t"<<(w->get_name())<<"!"<<endl; 
                                    curr_position->push_weapons(w); 
                                    flag=false; break;}
                  case (a_armor): {armor_type armor=(armor_type) (rand()%2);
                                   Armor* a=new Armor(armor);
                                   cout<<"Hai trovato\t"<<a->get_name()<<"!"<<endl; 
                                   curr_position->push_armature(a);  
                                   flag=false; break;}
                  case (letter): {if ((p->get_inventario()->get_indice_doc()<(max_letter_level_1-1))){
                                   p->get_inventario()->inc_indice_doc();  
                                   slow_print((char*)"Hai trovato una lettera\n");  
                                   flag=false;} 
                                  else 
                                   flag=true; break;}
                  case (adrenaline): {if (adrenalina_data<max_adrenaline_level_1){
                                       if (!p->get_inventario()->full_adrenaline()){
                                        p->get_inventario()->inc_adrenaline();  
                                        flag=false; adrenalina_data++;}
                                       else{
                                        flag=true; 
                                        slow_print((char*)"Non hai trovato nulla\n");}} 
                                      else flag=true; break;}
                  case (battery): {if (battery_data<max_battery_per_level){
                                    p->get_visore()->inc_reserve(); 
                                    battery_data++; 
                                    flag=false;}
                                   else 
                                    flag=true; break;}
                  default : {flag=true; break;}}}
               while (flag); break;}
    case (2): {bool flag=false;
               do{      
                int n=rand()%100;
                gift_type monster_gift;
                if (n<(10+p->get_luck())){
                 monster_gift=(gift_type) (rand()%2);}
                else{
                 if (n<(30+p->get_luck())){
                  monster_gift=(gift_type) (rand()%3+2);}
                 else{
                  monster_gift=(gift_type) (rand()%2+2);}}
                switch (monster_gift){
                  case (a_weapon): {weapon_type weapon=(weapon_type) (rand()%6+6);
                                    Weapon* w=new Weapon(weapon);
                                    cout<<"Hai trovato\t"<<(w->get_name())<<"!"<<endl; 
                                    curr_position->push_weapons(w); 
                                    flag=false; break;}
                  case (a_armor): {armor_type armor=(armor_type) (rand()%2+2);
                                   Armor* a=new Armor(armor);
                                   cout<<"Hai trovato\t"<<a->get_name()<<"!"<<endl; 
                                   curr_position->push_armature(a);   
                                   flag=false; break;}
                  case (letter): {if ((p->get_inventario()->get_indice_doc()<(max_letter_level_2+max_letter_level_1-1))){
                                   p->get_inventario()->inc_indice_doc();
                                   slow_print((char*)"Hai trovato una lettera\n");
                                   flag=false;} 
                                  else 
                                   flag=true; break;}
                  case (adrenaline): {if (adrenalina_data<max_adrenaline_level_2){
                                       if (!p->get_inventario()->full_adrenaline()){
                                        p->get_inventario()->inc_adrenaline();  
                                        flag=false; adrenalina_data++;}
                                       else{
                                       flag=true; 
                                       slow_print((char*)"Non hai trovato nulla\n");}}
                                      else 
                                       flag=true; break;} 
                  case (battery): {if (battery_data<max_battery_per_level){
                                    p->get_visore()->inc_reserve(); 
                                    battery_data++; 
                                    flag=false;}
                                   else 
                                    flag=true; break;}
                  default : {flag=true; break;}}}
               while (flag); break;}
    case (3): {bool flag=false;
               do{      
                int n=rand()%100;
                gift_type monster_gift;
                if (n<(10+p->get_luck())){
                 monster_gift=(gift_type) (rand()%5);}
                else{
                 if (n<(30+p->get_luck())){
                  monster_gift=(gift_type) (rand()%3+2);}
                 else{
                  monster_gift=(gift_type) (rand()%2+2);}}
                switch (monster_gift){
                  case (a_weapon): {weapon_type weapon=(weapon_type) (rand()%6+12);
                                    Weapon* w=new Weapon(weapon);
                                    cout<<"Hai trovato\t"<<(w->get_name())<<"!"<<endl; 
                                    curr_position->push_weapons(w);   
                                    flag=false; break;}
                  case (a_armor): {armor_type armor=(armor_type) (rand()%2+4);
                                   Armor* a=new Armor(armor);
                                   cout<<"Hai trovato\t"<<a->get_name()<<"!"<<endl; 
                                   curr_position->push_armature(a);  
                                   flag=false; break;}
                  case (letter): {if ((p->get_inventario()->get_indice_doc()<(9))){
                                   p->get_inventario()->inc_indice_doc(); 
                                   slow_print((char*)"Hai trovato una lettera\n");  
                                   flag=false;} 
                                  else 
                                   flag=true; break;}
                  case (adrenaline): {if (adrenalina_data<max_adrenaline_level_3){
                                       if (!p->get_inventario()->full_adrenaline()){
                                        p->get_inventario()->inc_adrenaline();  
                                        flag=false; 
                                        adrenalina_data++;}
                                       else{
                                        flag=true; 
                                        slow_print((char*)"Non hai trovato nulla\n");}}
                                      else 
                                       flag=true; break;} 
                  case (battery): {if (battery_data<max_battery_per_level){
                                    p->get_visore()->inc_reserve(); 
                                    battery_data++; 
                                    flag=false;}
                                   else 
                                    flag=true; break;}
                  default: {flag=true; break;}}}
               while (flag); break;}}}

                
 Boss* Map::get_boss() {return boss;}

 void Map::generate_boss(Player* p){
  if (boss==NULL){
  int x,y;
  int h=p->get_currentx();
  int k=p->get_currenty();
  do{
   x=rand()%200-100; 
   y=rand()%200-100;}
  while ((!head_coordinate->Look_Up(x,y))||((x==0)&&(y==0)));
  boss=new Boss(1,piano,x,y);
  clear_screen();
  p->change_currentx(x); 
  p->change_currenty(y);
  stampa(NULL,p);
  p->change_currentx(h); 
  p->change_currenty(k);}}


 bool Map::boss_alive(){ 
  if (boss!=NULL)
   return (!boss->is_dead());
  else 
   return false;}

 void Map::move_boss(Player* p){
  for (int i=0; i<2; i++){
   if (boss!=NULL){
    int xp=p->get_currentx();
    int yp=p->get_currenty();
    int xboss=boss->get_x();
    int yboss=boss->get_y();
    int sumx=xp-xboss;
    int sumy=yp-yboss;
    if (!((xp==xboss)&&(yp==yboss))){
     if (abs(sumx)>abs(sumy)){
      if (sumx<0) 
       boss->change_currentx(xboss-1);
      else if (sumx>0) 
       boss->change_currentx(xboss+1);}
     else{
      if (sumy<0) 
       boss->change_currenty(yboss-1);
      else if (sumy>0) 
       boss->change_currenty(yboss+1);}}}}}
       

 void Map::chase_player(ptr_lista_players head){
  if (boss!=NULL){
   ptr_lista_players tmp=head;
   Player* p;
   bool flag=true;
   int d,min,xp,yp,sumx,sumy;
   int xboss=boss->get_x();
   int yboss=boss->get_y();
   while (tmp!=NULL){
    p=tmp->p;
    xp=p->get_currentx();
    yp=p->get_currenty();
    sumx=xp-xboss;
    sumy=yp-yboss;
    d=abs(sumx)+abs(sumy);
    if (flag){
     min=d;
     flag=false;}
    else{
     if (d<min){
      min=d;}}
    tmp=tmp->next;}
   tmp=head;
   do{
    p=tmp->p;
    xp=p->get_currentx();
    yp=p->get_currenty();
    sumx=xp-xboss;
    sumy=yp-yboss;
    d=abs(sumx)+abs(sumy);
    tmp=tmp->next;}
   while ((d!=min)&&(tmp!=NULL));
   move_boss(p);}}
   
 
 bool Map::end_of_river(){
  int x=river[max_length_river-1].x; 
  int y=river[max_length_river-1].y;
  return head_coordinate->Look_Up(x,y);}


 Node* Map::pushNode(int x,int y){
  Node* node=new Node(x,y);
  head_coordinate=head_coordinate->Hash_Insert(x,y,node);
  if (head_coordinate->Look_Up(x-1,y)){
   Node* n=head_coordinate->get_node(x-1,y);  
   n->change_node_r(node); 
   node->change_node_l(n);}
  if (head_coordinate->Look_Up(x+1,y)){
   Node* n=head_coordinate->get_node(x+1,y);  
   n->change_node_l(node); 
   node->change_node_r(n);}
  if (head_coordinate->Look_Up(x,y+1)){
   Node* n=head_coordinate->get_node(x,y+1); 
   n->change_node_d(node); 
   node->change_node_u(n);}
  if (head_coordinate->Look_Up(x,y-1)){
   Node* n=head_coordinate->get_node(x,y-1); 
   n->change_node_u(node); 
   node->change_node_d(n);}
  return node;}
  

 void Map::delete_map(){
  Coda* coda=new Coda(2,0,1,&firstnode);
  Hash* hash=new Hash(383,11);
  hash=hash->Hash_Insert(0,0,firstnode);
  while (!(coda->Is_Empty())){
   Node* tmp=coda->Dequeue();
   int x=tmp->get_x();
   int y=tmp->get_y();
   if (tmp->getnode_d()!=NULL)
    if (!hash->Look_Up(x,y-1)){
     coda=coda->Enqueue(tmp->getnode_d());
     hash=hash->Hash_Insert(x,y-1,tmp->getnode_d());}
   if (tmp->getnode_l()!=NULL)
    if (!hash->Look_Up(x-1,y)){
     coda=coda->Enqueue(tmp->getnode_l());
     hash=hash->Hash_Insert(x-1,y,tmp->getnode_l());}
   if (tmp->getnode_r()!=NULL)
    if (!hash->Look_Up(x+1,y)){
     coda=coda->Enqueue(tmp->getnode_r());
     hash=hash->Hash_Insert(x+1,y,tmp->getnode_r());}
   if (tmp->getnode_u()!=NULL)
    if (!hash->Look_Up(x,y+1)){
     coda=coda->Enqueue(tmp->getnode_u());
     hash=hash->Hash_Insert(x,y+1,tmp->getnode_u());}
   delete tmp;}
  delete hash;
  delete coda;}

 void Map::visit(){
  Coda* coda=new Coda(2,0,1,&firstnode);
  Hash* hash=new Hash(383,11);
  hash=hash->Hash_Insert(0,0,firstnode);
  while (!(coda->Is_Empty())){
   Node* tmp=coda->Dequeue();
   int x=tmp->get_x();
   int y=tmp->get_y();
   if (tmp->getnode_d()!=NULL)
    if (!hash->Look_Up(x,y-1)){
     coda=coda->Enqueue(tmp->getnode_d());
     hash=hash->Hash_Insert(x,y-1,tmp->getnode_d());}
   if (tmp->getnode_l()!=NULL)
    if (!hash->Look_Up(x-1,y)){
     coda=coda->Enqueue(tmp->getnode_l());
     hash=hash->Hash_Insert(x-1,y,tmp->getnode_l());}
   if (tmp->getnode_r()!=NULL)
    if (!hash->Look_Up(x+1,y)){
     coda=coda->Enqueue(tmp->getnode_r());
     hash=hash->Hash_Insert(x+1,y,tmp->getnode_r());}
   if (tmp->getnode_u()!=NULL)
    if (!hash->Look_Up(x,y+1)){
     coda=coda->Enqueue(tmp->getnode_u());
     hash=hash->Hash_Insert(x,y+1,tmp->getnode_u());}}
  delete hash;
  delete coda;}



 bool Map::insert_chance(insert_type c, Player* p){
  int random=rand()%1000+1;
  int final_constant;
  int starting_constant;
  int sub_field;
  int mult_field; //AUMENTARE PER DIMINUIRE I TROVABILI PRIMA DEL CAP
  int cap_field;  //AUMENTARE PER AUMENTARE IL CAP
  int luck_field;
  int boss_div=1;
  if (boss!=NULL)
   if (!boss_alive())
    boss_div=2;
  switch (c){
    case (i_enemy): {starting_constant=enemies_constant; //300
                     sub_field=enemies_found;
                     mult_field=30;
                     cap_field=50;
                     luck_field=1; break;}
    case (i_locker): {starting_constant=lockers_constant; //100
                      sub_field=lockers_found;
                      mult_field=20;
                      cap_field=10/boss_div;
                      luck_field=p->get_luck()/2; break;}
    case (i_med_pack): {starting_constant=med_pack_constant; //100
                        sub_field=med_pack_found;
                        mult_field=20;
                        cap_field=5/boss_div;
                        luck_field=p->get_luck()/2; break;}
    case (i_antidote): {starting_constant=antidotes_constant; //100
                        sub_field=antidotes_found;
                        mult_field=200;
                        cap_field=2/boss_div;
                        luck_field=p->get_luck()/2; break;}
    case (i_key): {starting_constant=keys_constant;
                   sub_field=keys_found;
                   mult_field=20;
                   cap_field=30/boss_div;
                   luck_field=p->get_luck()/2; break;}}  
  if ((starting_constant-((sub_field*mult_field)/luck_field))<=cap_field)
   final_constant=cap_field;
  else 
   final_constant=starting_constant-((sub_field*mult_field)/luck_field);
  if (random<final_constant)
   return true;
  else 
   return false;}
  

 void Map::insert_things_node(Node* position,int difficulty,Player* p){
  int x=position->get_x(); int y=position->get_y();
  int l_player=p->get_level();
  int fortune=rand()%100+1;
  switch (piano){
    case (1): {if ((insert_chance(i_med_pack,p))||((boss_alive())&&(fortune<15))){
                position->change_med_pac(true);
                med_pack_found++;}
               if (((insert_chance(i_enemy,p))&&(boss==NULL))||((insert_chance(i_enemy,p))&&(boss!=NULL)&&(!boss_alive()))){
                Enemy* monster=new Enemy(l_player+difficulty,piano); 
                position->change_enemy(monster);
                enemies_found++;}
               if ((insert_chance(i_antidote,p))){
                position->change_antidoto(true);
                antidotes_found++;}
               if ((insert_chance(i_locker,p))){ 
                position->change_armadietto(true);
                lockers_found++;}
               if ((insert_chance(i_key,p))) 
                position->change_key();
                keys_found++; break;}
    case (2): {int n=max_length_river;  
               if ((insert_chance(i_med_pack,p))||((boss_alive())&&(fortune<15))){ 
                position->change_med_pac(true);
                med_pack_found++;}
               if (is_in_object(river,n,x,y)){
                position->insert_color_blue();} 
               if (((insert_chance(i_enemy,p))&&(boss==NULL))||((insert_chance(i_enemy,p))&&(boss!=NULL)&&(!boss_alive()))){
                Enemy* monster=new Enemy(l_player+difficulty,piano); 
                position->change_enemy(monster);
                enemies_found++;}
               if ((insert_chance(i_antidote,p))){
                position->change_antidoto(true);
                antidotes_found++;}
               if (insert_chance(i_locker,p)){
                lockers_found++;
                cout<<"A terra c'è un cadavere..potresti trovare qualcosa\n";
                if (fortune<85)
                 position->change_armadietto(true); 
                else {
                 cout<<"La carne putrefatta esplode davanti ai tuoi occhi, ferendoti\n"; 
                 p->change_life(-10);}} break;}
    case (3): {if ((insert_chance(i_med_pack,p))||((boss_alive())&&(fortune<15))){
                position->change_med_pac(true);
                med_pack_found++;}
               if ((insert_chance(i_antidote,p))){
                 position->change_antidoto(true);
                 antidotes_found++;}
               if (((insert_chance(i_enemy,p))&&(boss==NULL))||((insert_chance(i_enemy,p))&&(boss!=NULL)&&(!boss_alive()))){
                Enemy* monster=new Enemy(l_player+difficulty,piano); 
                position->change_enemy(monster);
                enemies_found++;}
               if ((insert_chance(i_locker,p))){ 
                position->change_armadietto(true);
                lockers_found++;}
               if ((insert_chance(i_key,p)))
                position->change_key();
                keys_found++; break;}}}



 void Map::generate_river(insieme a[],const int n){
  int x=0,y=0;
  a[0].x=0; a[0].y=0;
  cardinali not_dir=(cardinali) (rand()%4);
  switch (not_dir){
    case (nord): {a[1].x=0; 
                  a[1].y=-1; 
                  y--; 
                  for (int i=2;i<n;i++){
                   int h=x; int k=y;
                   do{
                    h=x; 
                    k=y; 
                    int r=rand()%3; 
                    switch (r){
                      case (0): {h--; break;}
                      case (1): {h++; break;}
                      case (2): {k--; break;}}} 
                   while (h==a[i-2].x); 
                   x=h; 
                   y=k;
                   a[i].x=x; 
                   a[i].y=y;} break;}
    case (sud): {a[1].x=0; 
                 a[1].y=1; 
                 y++; 
                 for (int i=2;i<n;i++){
                  int h=x; 
                  int k=y;
                  do{
                   h=x; 
                   k=y; 
                   int r=rand()%3; 
                   switch (r){
                     case (0): {h--; break;}
                     case (1): {h++; break;}
                     case (2): {k++; break;}}} 
                  while (h==a[i-2].x); 
                  x=h; 
                  y=k; 
                  a[i].x=x; 
                  a[i].y=y;} break;}
    case (est): {a[1].x=-1; 
                 a[1].y=0; 
                 x--; 
                 for (int i=2;i<n;i++){ 
                  int h=x; 
                  int k=y; 
                  do{ 
                   h=x; 
                   k=y;   
                   int r=rand()%3; 
                   switch (r){
                     case (0):{h--; break;}
                     case (1):{k++; break;}
                     case (2):{k--; break;}}} 
                  while (k==a[i-2].y); 
                  x=h; 
                  y=k; 
                  a[i].x=x; 
                  a[i].y=y;} break;}
    case (ovest): {a[1].x=1; 
                   a[1].y=0; 
                   x++; 
                   for (int i=2;i<n;i++){ 
                    int h=x; int k=y;
                    do{
                     h=x; 
                     k=y; 
                     int r=rand()%3; 
                     switch (r){
                      case (0): {k++; break;}
                      case (1): {h++; break;}
                      case (2): {k--; break;}}} 
                    while (k==a[i-2].y);
                    x=h; 
                    y=k; 
                    a[i].x=x; 
                    a[i].y=y;} break;}}}
                    

 bool Map::is_in_object(insieme a[],int n,int currentx,int currenty){
  bool flag=false;
  int i=0;
  while ((!flag)&&(i<n)){
   if ((a[i].x==currentx)&&(a[i].y==currenty))
    flag=true;
   else
    i++;}
  return flag;}

 
 void Map::print_color_text(char a){
  switch (a){
    case 'A': { cout<<BOLD(FBLU("A")); break;}
    case 'B': { cout<<BOLD(FRED("B"));break;}
    case 'N': { cout<<BOLD(FGRN("N"));break;}
    case 'S': { cout<<BOLD(FCYN("S"));break;}
    default: {cout<<BOLD(FBLU("P")); break;}}}


 void Map::stampa(ptr_lista_players giocatori,Player* curr){
  int a[4]; 
  int x_giocatore=curr->get_currentx();
  int y_giocatore=curr->get_currenty();
  if (x_giocatore<=0){ 
   int schermata_x=((x_giocatore)/L_Mappa)-1;
   a[0]= L_Mappa*schermata_x;
   a[1]=a[0]+L_Mappa;}
  else{
   int schermata_x=((x_giocatore)/L_Mappa)+1;
   a[1]= L_Mappa*schermata_x;
   a[0]=a[1]-L_Mappa;}
  if (y_giocatore<=0){
   int schermata_y=((y_giocatore)/L_Mappa)-1;
   a[2]=L_Mappa*schermata_y;
   a[3]=a[2]+L_Mappa;}
  else{
   int schermata_y=((y_giocatore)/L_Mappa)+1;
   a[3]=L_Mappa*schermata_y;
   a[2]=a[3]-L_Mappa;}
  cout<<endl<<endl;
  switch (piano){
    case (1): {cout<<"LA PRIGIONE\n"; break;}
    case (2):{cout<<"I SOTTERRANEI\n"; break;}
    case (3):{cout<<"PIANO 57\n"; break;}
    default: {cout<<"MAPPA\n"; break;}}
  for (int i=0;i<(3);i++) 
   cout<<endl;
  for (int i=(a[3]); i>=(a[2]); i--){
   for (int s=0;s<2;s++){
    cout<<"\t";}
   for (int j=(a[0]); j<=(a[1]); j++){
    if ((j==0)&&(i==0)){
     if (piano==2){
      cout<<"\t"<<FBLU("[Home");}
     else
      cout<<"\t[Home";
     ptr_lista_players tmp=giocatori;
     while (tmp!=NULL){
      if(tmp->p->is_in_p(j,i)){
       cout<<" <"; print_color_text(tmp->p->get_init_name());}
      tmp=tmp->next;}
     if (piano==2) 
      cout<<FBLU("]");
     else 
      cout<<"]";}
    else{
     if (head_coordinate->Look_Up(j,i)){
     bool varco=false;
      Node* nodo=head_coordinate->get_node(j,i);
      if (nodo->get_color_blue()) 
       cout<<"\t"<<FBLU("[");
      else 
       cout<<"\t[";
      if (boss!=NULL){
       if ((j==boss->get_x())&&(i==boss->get_y())){
        if (boss_alive())
          cout<<FRED("BOSS");
        else{
          cout<<BOLD(FBLU("||"));
          varco=true;
          if (!curr->is_in_p(j,i)){
           cout<<" ";}
          }}}
      if (nodo->get_med_pac())
       cout<<FRED("+");
      if (nodo->is_in_weapon())
       cout<<UNDL("§");
      if (nodo->is_in_antidoto())
       cout<<BOLD(FGRN("%"));
      if (nodo->is_in_armature())
       cout<<FMAG("&");
      if (nodo->is_in_enemy())
       cout<<BOLD(FRED("<M>"));
      if (nodo->get_armadietto())
       cout<<FCYN("?");
      ptr_lista_players tmp=giocatori;
      while (tmp!=NULL){
       if(tmp->p->is_in_p(j,i)){
        print_color_text(tmp->p->get_init_name());
        if (tmp->next!=NULL) 
         if (tmp->next->p->is_in_p(j,i)) 
          cout<<",";}
       tmp=tmp->next;}
      if (varco){
       cout<<BOLD(FBLU("||"));}
      if (nodo->get_color_blue()) 
       cout<<FBLU("]");
      else 
       cout<<"]";}
     else
      cout<<"\t";}}   
   cout<<endl<<endl;}
  cout<<endl;
  for (int s=0;s<(2+L_Mappa);s++){
   cout<<"\t";}
  cout<<"\t\t"<<curr->get_name()<<"\tLIVELLO\t"<<curr->get_level()<<endl;
  for (int s=0;s<(2+L_Mappa);s++){
   cout<<"\t";}
  if (((curr->get_life()/((double)curr->get_max_life()))*100)<20){
   cout<<BOLD(FRED("\t\tVITA\t")); 
   cout<<curr->get_life(); cout<<BOLD(FRED("/")); cout<<curr->get_max_life()<<endl;}
  else{ 
    if (curr->is_infected())
     cout<<BOLD(FGRN("\t\tVITA:\t"))<<curr->get_life()<<BOLD(FGRN("/"))<<curr->get_max_life()<<BOLD(FGRN("\t[INFETTO]"))<<endl;
  else
   cout<<"\t\tVITA\t"<<curr->get_life()<<"/"<<curr->get_max_life()<<endl;}
  for (int s=0;s<(2+L_Mappa);s++){
   cout<<"\t";}
   cout<<"\t\tENERGIA\t"<<curr->get_energy()<<"/"<<curr->get_max_energy()<<endl;
  for (int s=0;s<(2+L_Mappa);s++){
   cout<<"\t";}
   cout<<"\t\tESPERIENZA\t"<<curr->get_experience()<<"/"<<curr->get_max_experience()<<endl;
  if (curr->get_visore()->get_use()){
   for (int s=0;s<(2+L_Mappa);s++){
    cout<<"\t";}
   cout<<"\t\t"; 
   curr->get_visore()->print_battery();}
  cout<<endl<<endl;}
