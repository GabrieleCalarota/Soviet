#include "StartSoviet.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "Node.hpp"
#include "Boss.hpp"
#include "Phrases.hpp"
#include "Inventario.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Enemy.hpp"
#include "Visore.hpp"
#include "Tutorial.hpp"
#include "Task.hpp"

 StartSoviet::StartSoviet(){
   head_players=NULL;
   single_player=false;
   n_players=1;
   position=new Node;
   livello=new Mondo;
   livello->num=1;
   livello->next=NULL;
   livello->prec=NULL;
   currentx=0;
   currenty=0;
   punti=0;
   win=false;
   difficulty=0;
   cont_mosse=0;
   input=c;
   tutorial=new Tutorial(this);}

 Mondo* StartSoviet::inc_floor(){   
   if (livello->next==NULL){  
     int i=livello->num;
     livello->next=new Mondo;
     livello->next->num=i+1;
     livello->next->prec=livello;
     livello->next->next=NULL;}
   return livello->next;}

 ptr_lista_players StartSoviet::push(Player* nuovo, ptr_lista_players head){
     if (head==NULL){
       ptr_lista_players tmp=new lista_players;
       tmp->p=nuovo;
       tmp->next=NULL;
       return tmp;}  
     else{
      ptr_lista_players tmp=head;
      while (head->next!=NULL)
        head=head->next;
      head->next=new lista_players;
      head=head->next;
      head->p=nuovo;
      head->next=NULL;
      return tmp;}}

 void StartSoviet::start_game(){
  clear_screen();
  slow_print((char*)"        //////   //////   ///  ///   ///   //////   //////\n        //       //  //   ///  ///         //         //\n        //////   //  //    //  //    ///   ////       //\n            //   //  //    // //     ///   //        //\n        //////   //////     //       ///   //////    //\n");
  cout<<"                                                                 ";
  slow_print((char*)"Created by Gabriele Calarota and Alberto Drusiani\n");
  slow_print((char*)"GIOCA\n");
  cout<<"(Premi un tasto per iniziare..)\t[Premi 'f' per andare direttamente alla creazione personaggio]\n";
  if (getch()!='f'){
  clear_screen();
  slow_print(story_0);
  sleep(3);
  slow_print(story_1);
  sleep(3);
  clear_screen();
  slow_print(story_2);
  sleep(2);
  slow_print(story_3);
  sleep(2);
  slow_print(story_4);
  sleep(2);
  slow_print(story_5);
  sleep(2);
  slow_print(story_6);
  sleep(2);
  slow_print(story_7);
  sleep(2);
  slow_print(story_8);
  sleep(2);
  slow_print(story_9);
  sleep(2);
  slow_print(story_10);
  sleep(1);
  slow_print(story_11);
  sleep(1);
  slow_print(story_12);
  sleep(1);
  slow_print(story_13);
  sleep(1);
  slow_print(story_14);
  sleep(1);
  slow_print(story_15);
  sleep(1);
  slow_print(story_16);
  sleep(1);
  slow_print(story_17);
  cout<<"(Premi un tasto per continuare..)\n";
  getch();}
  clear_screen();
}


 int StartSoviet::choose_facility(){
   clear_screen();
   cout<<"Scegli la modalità di gioco:\n";
   cout<<"\t1)Recluta\n\t2)Esperto\n\t3)Veterano\n";
   char s;
   do
     s=getch();
   while ((s!='1')&&(s!='2')&&(s!='3')&&(s!='f'));
   clear_screen();
   switch (s){ 
      case ('1'):{difficulty=0; return 25; break;}
      case ('2'):{difficulty=1; return 19; break;}
      case ('3'):{difficulty=2; return 16; break;}} }

 void StartSoviet::choose_mod(){
   bool esci=true;
   do {
     clear_screen();
     char scelta='1';
     cout<<"Scegli la modalità di gioco:\n\t1)Giocatore Singolo\n\t2)MultiGiocatore\n\t3)Addestramento\n";
     do
     scelta=getch();
     while ((scelta!='1')&&(scelta!='2')&&(scelta!='3'));
     clear_screen();
     switch(scelta){
        case ('1'): { single_player=true; punti=choose_facility(); esci=false; break;}
        case ('2'):{ Multiplayer(); punti=19; difficulty=2; clear_screen(); esci=false; break;}
        case ('3'):{clear_screen(); tutorial->Play(); esci=true; break;}
        default : { esci=true; clear_screen(); break;}}}
   while (esci);
   livello->mappa=new Map(position,livello->num);}


 void StartSoviet::Multiplayer(){
       bool esci;
       do{   
         clear_screen();
         cout<<"Inserisci il numero di giocatori:\n";
         cout<<"(Premi invio al termine dell'inserimento)"<<endl;
         char num[20];
         char *s=num;
         cin>>s;                                         
         n_players=0; 
         esci=false;      
         while(((*s)!='\0')&&(!esci)) {
           if (((*s)>='0')&&((*s)<='9'))
               n_players=(n_players*10)+((*s)-'0');
            else
               esci=true;
            s++;}
         if (n_players==0)
             esci=true;}
      while (esci); 
     getch();}
         

 void StartSoviet::help(int i){
   switch (i){
     case (1):{
        int s=rand()%7+1;
        switch (s){
           case (1):{slow_print(help_piano_1_1); break;}
           case (2):{slow_print(help_piano_1_2); break;}
           case (3):{slow_print(help_piano_1_3); break;}
           case (4):{slow_print(help_piano_1_4); break;}
           case (5):{slow_print(help_piano_1_5); break;}
           case (6):{slow_print(help_piano_1_6); break;}
           case (7):{slow_print(help_piano_1_7); break;}}
       break;}
    case (2):{
        int s=rand()%9+1;
        switch (s){
           case (1):{slow_print(help_piano_2_1); break;}
           case (2):{slow_print(help_piano_2_2); break;}
           case (3):{slow_print(help_piano_2_3); break;}
           case (4):{slow_print(help_piano_2_4); break;}
           case (5):{slow_print(help_piano_2_5); break;}
           case (6):{slow_print(help_piano_2_6); break;}
           case (7):{slow_print(help_piano_2_7); break;}
           case (8):{slow_print(help_piano_2_8); break;}
           case (9):{slow_print(help_piano_2_9); break;}}
       break;}
   case (3):{
        int s=rand()%9+1;
        switch (s){
           case (1):{slow_print(help_piano_3_1); break;}
           case (2):{slow_print(help_piano_3_2); break;}
           case (3):{slow_print(help_piano_3_3); break;}
           case (4):{slow_print(help_piano_3_4); break;}
           case (5):{slow_print(help_piano_3_5); break;}
           case (6):{slow_print(help_piano_3_6); break;}
           case (7):{slow_print(help_piano_3_7); break;}
           case (8):{slow_print(help_piano_3_8); break;}
           case (9):{slow_print(help_piano_3_9); break;}}
       break;}}}

 void StartSoviet::choose_player(){
   if (single_player)
         start_game();
    for (int i=0; i<n_players;i++){
      Player* nuovo=new Player;
      slow_print((char*)"Scegli un personaggio\n");
      bool flag=true;
      do{
        char n;
        if (!flag)
          cout<<"Scegli un personaggio\n";
        cout<<characters_presentation;
        do
        n=getch();
       while ((n!='1')&&(n!='2')&&(n!='3')&&(n!='4'));
       clear_screen();
       switch (n){                          
           case ('1'):{ nuovo->change_name(player_1); nuovo->set_which_character(n,punti); flag=true; break; }
           case ('2'): { nuovo->change_name(player_2); nuovo->set_which_character(n,punti); flag=true; break;}
           case ('3'): { nuovo->change_name(player_3); nuovo->set_which_character(n,punti); flag=true; break;}
           case ('4'): { nuovo->change_name(player_4); nuovo->set_which_character(n,punti); flag=true; break;}
           default: {flag=false; break;}}}
    while (!flag);
    clear_screen();
    head_players=push(nuovo,head_players);
    cout<<"Tu sarai "<<nuovo->get_name()<<".\n";
    clear_screen();}
    clear_screen();
    if (single_player) 
       slow_print(info_single);
    else
       slow_print(info_multi); 
    cout<<"\n(Premi un tasto per continuare..)\n"; 
    getch();
    clear_screen();}



 void StartSoviet::play(){

    ptr_lista_players tmp=head_players;
    livello->mappa->stampa(head_players,tmp->p);
    if (!single_player)	
      cout<<"Turno di "<<tmp->p->get_name()<<"!\n";

    cout<<"Dove vuoi andare?"<<endl;
    do
    *input=getch();
    while ((*input!='a')&&(*input!='w')&&(*input!='s')&&(*input!='d'));
    clear_screen();

    while ((tmp!=NULL)&&(!win)) {

      muovi=false;

      if (uguali(input,(char*)"m")){
        cin>>input;
        getchar();
        command_type cmd=nothing;
        if (uguali(input,(char*)"apri")) cmd=apri;
        if (uguali(input,(char*)"fruga")) cmd=fruga;
        if (uguali(input,(char*)"raccogli")) cmd=prendi;
        if (uguali(input,(char*)"potenzia")) cmd=spendi;
        switch (cmd){
          case (apri): {clear_screen(); 
                        livello->mappa->stampa(head_players,tmp->p);
                        if (position->get_armadietto()) {
                          switch (livello->num){
                              case (1):{if (tmp->p->get_inventario()->more_keys()) {
                                          tmp->p->get_inventario()->dec_keys();
                                          cout<<"Hai utilizzato un <Grimaldello Esplosivo>\n"; 
                                          livello->mappa->give_gift(position,tmp->p);
                                          position->change_armadietto(false);} 
                                        else 
                                          cout<<"Non hai più <Grimaldelli Esplosivi> in Inventario\n";
                                         break;}
                              case (2):{cout<<"Non c'è nulla da aprire\n"; 
                                        break;}
                              case (3):{if (tmp->p->get_inventario()->get_keys()>1) {
                                          tmp->p->get_inventario()->dec_keys(); 
                                          tmp->p->get_inventario()->dec_keys();
                                          cout<<"Hai fatto esplodere due <Grimaldelli Esplosivi>\n";
                                          livello->mappa->give_gift(position,tmp->p);
                                          position->change_armadietto(false);} 
                                        else 
                                          cout<<"Non hai abbastanza <Grimaldelli Esplosivi> in Inventario per aprire questo tipo di serratura\n";
                                         break;}}
                             }
                        else 
                          cout<<"Nessun armadietto rilevato\n";  
                        break;}
          case (fruga): {clear_screen();
                         livello->mappa->stampa(head_players,tmp->p); 
                         if (position->get_armadietto()) {
                             if (livello->num>1) { 
                                 livello->mappa->give_gift(position,tmp->p); 
                                 position->change_armadietto(false);}}  
                          break;}
           case (prendi): {clear_screen();
                           livello->mappa->stampa(head_players,tmp->p);
                           if (position->is_in_weapon()||position->is_in_armature()){ 
                                 position->pick_up_tools(tmp->p);} 
                           else{ 
                             slow_print((char*)"Nessun oggetto rilevato nella stanza\r");}
                           clear_screen(); 
                           livello->mappa->stampa(head_players,tmp->p);
                           break;}
          case (spendi):{clear_screen(); 
                       tmp->p->character_creation(0,true); 
                       clear_screen(); 
                       livello->mappa->stampa(head_players,tmp->p); 
                       break;}
          default: {clear_screen(); 
                  livello->mappa->stampa(head_players,tmp->p); 
                  break;}}
         tmp->p->get_task()->curr_task(tmp->p,false,livello->mappa);}
     else{
       bool end_of_shift=false;
       bool is_in=false;
       char tasto=*input;
       switch (tasto){
          case 'a': {currentx--;
                     if (position->getnode_l()!=NULL) {
                        is_in=true;
                        position=position->getnode_l();} 
                     muovi=true; 
                     break;}
          case 'd': {currentx++; 
                     if (position->getnode_r()!=NULL) {
                        is_in=true;
                        position=position->getnode_r();} 
                     muovi=true;
                     break;}
          case 'w': {currenty++; 
                     if (position->getnode_u()!=NULL) {
                        is_in=true; 
                        position=position->getnode_u();} 
                     muovi=true;
                     break;}
          case 's': {currenty--;
                     if (position->getnode_d()!=NULL) {
                         is_in=true; 
                         position=position->getnode_d();} 
                     muovi=true; 
                     break;}
          case 'p': {tmp->p->statistiche();  
                     cout<<"Premi un tasto per continuare..\n"; 
                     getch(); 
                     clear_screen(); 
                     livello->mappa->stampa(head_players,tmp->p); 
                     break;}
          case ('i'):{tmp->p->get_inventario()->stampa_inventario(tmp->p,position,false);
                      clear_screen();
                      livello->mappa->stampa(head_players,tmp->p); 
                      break;}
          case 'h': { if ((tmp->p->is_in_weapon())||(tmp->p->is_in_armor())) {
                            tmp->p->unequip(position);
                            clear_screen();
                            livello->mappa->stampa(head_players,tmp->p);} 
                      else {
                            cout<<"Nessuna arma o armatura equipaggiata\n";}
                      break;}
           case 'o': {livello->mappa->stampa(head_players,tmp->p); 
                      tmp->p->get_task()->curr_task(tmp->p,true,livello->mappa); 
                      break;}
           case 'k': {livello->mappa->stampa(head_players,tmp->p); 
                      help(livello->num); 
                      break;}
           case 't': {if (!single_player){
                          end_of_shift=true; 
                          livello->mappa->stampa(head_players,tmp->p);
                          cout<<"Turno di "<<tmp->p->get_name()<<" terminato!\n"; 
                          sleep(1); 
                          clear_screen();} 
                      else {
                          cout<<info_single; 
                          cout<<"Premi un tasto per continuare..\n";  
                          getch(); 
                          clear_screen(); 
                          livello->mappa->stampa(head_players,tmp->p);} 
                      break;}
           case ('v'):{clear_screen();
                       tmp->p->get_visore()->options();
                       clear_screen();
                       livello->mappa->stampa(head_players,tmp->p);
                       break;}
           default : {if (single_player) 
                         cout<<info_single;
                      else
                         cout<<info_multi; 
                      cout<<"\nPremi un tasto per continuare..\n";  
                      getch(); 
                      clear_screen(); 
                      livello->mappa->stampa(head_players,tmp->p); 
                      break;}}
   

    if (muovi){
        cont_mosse++;
        if (cont_mosse%7==0){
            end_of_shift=true;
            cont_mosse=0;}
        if (!is_in){
            position=livello->mappa->pushNode(currentx,currenty);
            livello->mappa->insert_things_node(position,difficulty,tmp->p);}
        bool scendi=false;
        if ((currentx==0)&&(currenty==0)){
          if (livello->prec!=NULL){
            scendi=true;
            if (livello->mappa->get_boss()!=NULL){
              if (livello->mappa->boss_alive())
                scendi=false;}
            if (scendi){
              tmp->p->change_currentx(currentx);
              tmp->p->change_currenty(currenty);
              livello->mappa->stampa(head_players,tmp->p);
              loading();
              clear_screen();
              livello=livello->prec;
              currentx=livello->mappa->get_boss()->get_x(); 
              currenty=livello->mappa->get_boss()->get_y(); 
              position=livello->mappa->get_node(currentx,currenty);}} }
        tmp->p->change_currentx(currentx);
        tmp->p->change_currenty(currenty);
        livello->mappa->stampa(head_players,tmp->p); 
        tmp->p->get_visore()->consume_battery();
        if (position->is_in_enemy()){
            clear_screen();
            cout<<monster_image_1;
            cout<<"NEMICO RILEVATO\n";
            sleep(1);   
            if (!position->get_enemy()->combat(position,tmp->p,livello->num)){
                if (position->get_enemy()->is_dead()){
                  delete position->get_enemy();
                  position->change_enemy(NULL);}
                clear_screen();
                livello->mappa->stampa(head_players,tmp->p);}}

       if (!tmp->p->dead()){
         if (position->get_med_pac()){
           if (!tmp->p->get_inventario()->full_med_pack()){
             tmp->p->get_inventario()->inc_med_pack();
             position->change_med_pac(false);}} 
         if (position->is_in_antidoto()){
           if (!tmp->p->get_inventario()->full_antidoti()){
             tmp->p->get_inventario()->inc_antidoti();
             position->change_antidoto(false);}} 
         if (position->get_key()){
            tmp->p->get_inventario()->inc_keys();
            position->change_key();}
            tmp->p->poison_check(false);
        if (livello->mappa->boss_alive()){
          livello->mappa->get_boss()->check_boss(tmp->p,livello->mappa,head_players,!single_player,&cont_mosse,position,n_players); 
        if (cont_mosse%7==0){
          end_of_shift=true;
          cont_mosse=0;}}
        int old_lev=tmp->p->get_level();                  		//INIZIO FUNZIONI BOSS
        tmp->p->get_task()->curr_task(tmp->p,false,livello->mappa);
        if (tmp->p->get_level()>old_lev){
          clear_screen();
          livello->mappa->stampa(head_players,tmp->p);}
        if (livello->mappa->get_boss()!=NULL){
         if ((!livello->mappa->boss_alive())) {
          if (livello->next==NULL){
            loading();
            if ((!single_player)||(livello->num==3)) {
              clear_screen();
              slow_print(tmp->p->get_name());
              slow_print((char*)" HAI VINTO ..\n");
              win=true;}
            if (!single_player){
              cout<<"Vuoi proseguire il gioco in modalità single player?\n";
              if (getch()=='s'){
                 single_player=true; 
                 n_players=1; 
                 head_players=tmp; 
                 tmp->next=NULL; 
                 win=false;}}
            if (!win){
              livello=inc_floor(); 
              position=new Node; 
              tmp->p->change_currentx(0); 
              tmp->p->change_currenty(0); 
              livello->mappa=new Map(position,livello->num); 
              currentx=0; 
              currenty=0; 
              clear_screen(); 
              livello->mappa->stampa(head_players,tmp->p);}}
         else{
           if ((currentx==livello->mappa->get_boss()->get_x())&&(currenty==livello->mappa->get_boss()->get_y())&&!scendi){ 
             loading();
             livello=livello->next; 
             position=livello->mappa->get_node(0,0); 
             currentx=0;
             currenty=0; 
             tmp->p->change_currentx(0);
             tmp->p->change_currenty(0);
             clear_screen();
             livello->mappa->stampa(head_players,tmp->p);} } }}}}
                           
   if (!single_player){ 
     if (tmp->p->dead()){
       if (head_players->next==NULL){
         slow_print(tmp->p->get_name());
         slow_print((char*)" nemmeno tu ce l'hai fatta!\n");}
       else{
        if (tmp->p->get_init_name()=='A'){
         slow_print(tmp->p->get_name());
         slow_print((char*)" è morta!\n");}
    else{
       slow_print(tmp->p->get_name());
       slow_print((char*)" è morto!\n");}}
    ptr_lista_players temp=head_players;
    bool flag=false;                                                  
    while ((!flag)&&(temp->next!=NULL)){
      if (temp->next==tmp) 
         flag=true; 
      else
         temp=temp->next;}

    if (flag) { 
      temp->next=tmp->next;
      delete tmp;
      if (temp->next!=NULL)
          tmp=temp->next;
      else{
        tmp=temp;}
    clear_screen();
    currentx=tmp->p->get_currentx();
    currenty=tmp->p->get_currenty();
    position=livello->mappa->get_node(currentx,currenty);
    livello->mappa->stampa(head_players,tmp->p);
      if (head_players->next==NULL){
       single_player=true;
       if (tmp->p->get_init_name()=='A')
          cout<<tmp->p->get_name()<<" sei la sola sopravvissuta!\n";
       else 
          cout<<tmp->p->get_name()<<" sei il solo sopravvissuto!\n";}
    cout<<"Turno di "<<tmp->p->get_name()<<"!\n";
    cont_mosse=0;}
    else{
     if (head_players->next==NULL){
              tmp=NULL;}
     else{ 
       temp=head_players;
       head_players=head_players->next;
       delete temp;
       tmp=head_players;
       clear_screen();
       currentx=tmp->p->get_currentx();
       currenty=tmp->p->get_currenty();
       position=livello->mappa->get_node(currentx,currenty);
       livello->mappa->stampa(head_players,tmp->p);
       if (head_players->next==NULL){
          single_player=true;
       if (tmp->p->get_init_name()=='A')
          cout<<tmp->p->get_name()<<" sei la sola sopravvissuta!\n";
       else 
          cout<<tmp->p->get_name()<<" sei il solo sopravvissuto!\n";}
    cout<<"Turno di "<<tmp->p->get_name()<<"!\n";
    cont_mosse=0;}}}
   else {           
                    
   if ((end_of_shift)){
    if (tmp->next!=NULL)
      tmp=tmp->next;
    else
     tmp=head_players;
    clear_screen();
    currentx=tmp->p->get_currentx();
    currenty=tmp->p->get_currenty();
    position=livello->mappa->get_node(currentx,currenty);
    livello->mappa->stampa(head_players,tmp->p);
    cout<<"Turno di "<<tmp->p->get_name()<<"!\n";
    cont_mosse=0;}}} 
    else {

       if (tmp->p->dead())
           tmp=NULL;}}	
    
    if (win) {
       delete tmp;
       tmp=NULL;}
    if (tmp!=NULL){ 
       clear_input(input,max_length_input);
       *input=getch();
       if(!uguali(input,(char*)"m"))
         clear_screen();
       else
        cout<<"Cosa vuoi fare?\t[Premi invio una volta terminato l'inserimento]"<<endl;}}
     


     slow_print((char*)"\n");
     slow_print((char*)"\n");
     slow_print((char*)"\n");
     if (!win){
        clear_screen();
        slow_print((char*)"... GAME OVER ...\n");}}
