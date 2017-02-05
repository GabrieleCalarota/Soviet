#include "Tutorial.hpp"
#include "Node.hpp"
#include "Player.hpp"
#include "Weapon.hpp"
#include "Map.hpp"
#include "StartSoviet.hpp"
#include "Inventario.hpp"
#include "Visore.hpp"

 Tutorial::Tutorial(StartSoviet* s){
  input='0';
  nod=new Node;
  m=new Map(nod,1);
  p=new Player();
  w=new Weapon(pistola);
  h=NULL;
  h=s->push(p,h);
  p->set_life();
  p->change_life(60);
  p->change_damage(); 
  p->get_inventario()->change_max_weight(p);
  x=0;
  y=0;
  esci=false;}


 void Tutorial::Introduction(){
  slow_print((char*)"Programma addestramento simulato per corpi d'elite.\n\t[Per uscire in qualsiasi momento premi 'f']\n");
  slow_print((char*)"Sono il maggiore Ivan e sarò il tuo supervisore dalla madre patria, quando avrai bisogno di aiuto, ti invierò messaggi in codice morse.\n");
  slow_print((char*)"Nel corso dell'addestramento ti insegnerò come decifrarli\n");
  cout<<"\nScegli un nome per il tuo giocatore nell'addestramento\n";
  cin>>n;
  getch();
  p->change_name(n);
  m->stampa(h,p);
  slow_print((char*)"Il simbolo [] identifica una stanza. La stanza contrassegnata dall'iniziale del nome indica quella dove ci si trova.\n");
  slow_print((char*)"Durante la missione sarà necessario esplorare diverse stanze.\n");
  slow_print((char*)"Tutto ciò che viene mostrato nella stanza verrà raccolto automaticamente, a patto che non abbia un peso");
  slow_print((char*)" significativo per l'inventario (come armi e munizioni)\n"); 
  cout<<"(Premi un tasto per continuare..)\n";
  getch();
  clear_screen();}


 void Tutorial::Move(){
  do{
   input=getch();}
  while ((input!='s')&&(input!='d')&&(input!='w')&&(input!='a')&&(input!='f'));
  p->get_visore()->consume_battery();
  clear_screen();
  bool flag=false;
  bool is_in=false;
  switch (input){
   case 'a': {x--; if (nod->getnode_l()!=NULL){is_in=true; nod=nod->getnode_l();} break;}
   case 'd': {x++; if (nod->getnode_r()!=NULL){is_in=true; nod=nod->getnode_r();}break;}
   case 'w': {y++;if (nod->getnode_u()!=NULL){is_in=true; nod=nod->getnode_u();} break;}
   case 's': {y--; if (nod->getnode_d()!=NULL){is_in=true; nod=nod->getnode_d();} break;}
   case 'f': {esci=true; flag=true; break;}
   default : {flag=true; break;}}
   if (!flag){
    if (!is_in)
     nod=m->pushNode(x,y);
    p->change_currentx(x); 
    p->change_currenty(y);
    m->stampa(h,p);}}


 void Tutorial::Check_inventario(){
  slow_print((char*)"Per controllare l'inventario premere 'i'\n");
  input='i';
  do{
   if (input!='i'){
    cout<<"\r                                                                                                 ";
    slow_print((char*)"\rPremere il tasto giusto per controllare l'inventario, ne va del superamento dell'addestramento\n");}
    input=getch();}
  while ((input!='i')&&(input!='f'));
  if (input=='f') 
   esci=true;
  else{
   clear_screen(); 
   p->get_inventario()->stampa_inventario(p,nod,false);}}

 void Tutorial::Check_statistiche(){
  slow_print((char*)"Per controllare le statistiche premere 'p'\n");
  input='p';
  do{
   if (input!='p'){
    cout<<"\r                                                                                                 ";
    slow_print((char*)"\rPremere il tasto giusto per controllare le statistiche giocatore, ne va del superamento dell'addestramento\n");}
    input=getch();}
  while ((input!='p')&&(input!='f'));
  if (input=='f') 
   esci=true;
  else{
   clear_screen(); 
   p->statistiche();}}


 void Tutorial::Play(){
         Introduction();
         m->stampa(h,p);
         slow_print((char*)"Prima di tutto lo spostamento.\nPremere 'w' per aprire la porta della stanza a nord\n");
         slow_print((char*)"Premere 's' per aprire la porta della stanza a sud\nPremere 'a' per aprire la porta della stanza ad est\n");
         slow_print((char*)"Premere 'd' per aprire la porta della stanza a ovest\n");
         slow_print((char*)"Dove vuoi andare?\n");
         for (int i=0;(i<3)&&(!esci);i++)        
             Move();
         if (!esci){                       
           p->get_inventario()->inc_keys();
           Check_inventario();
           if (!esci){
             slow_print((char*)"\nControlla sempre gli oggetti disponibili dall'inventario.\n");
             cout<<"(Premi un tasto per continuare..)\n";
             getch();
             clear_screen(); 
             m->stampa(h,p);}}
        if (!esci)
           Move();
        if (!esci){       
          nod->change_armadietto(true);
          m->stampa(h,p);
          slow_print((char*)"Rilevato un'armadietto chiuso a chiave.\n");
          slow_print((char*)"Il simbolo '?' significa che è possibile usare un grimaldello esplosivo per forzare la serratura e raccogliere il contenuto.\n");
          slow_print((char*)"I grimaldelli non sono utilizzabili una seconda volta ed è necessario trovarne altri per forzare nuove serrature\n");
          sleep(1);
          bool flag3=true;
           cout<<"Premendo il tasto 'm' si accede al comando AZIONE\n";
          do
           input=getch();
          while ((input!='m')&&(input!='f'));
          switch(input){
               case ('f'):{esci=true; clear_screen(); break;}
               case ('m'):{bool flag4=true; 
                           char input1[25]; 
                           do {
                             cout<<"Digitare 'apri' per sfruttare un grimaldello e forzare l'armadietto chiuso\n"; 
                             cout<<"(Premi invio una volta terminato l'inserimento)\n"; 
                             cin>>input1;
                             getchar(); 
                             if (strcmp(input1,(char*)"apri")==0){
                                  nod->push_weapons(w);
                                  p->get_inventario()->dec_keys(); 
                                  clear_screen();
                                  nod->change_armadietto(false);
                                  m->stampa(h,p); 
                                  flag4=false; 
                                  cout<<"Hai trovato un'arma\n";}
                            else{
                                flag4=true; 
                                cout<<"\r                                                    ";}}
                           while (flag4);
                           break;}}}
      if (!esci){
          slow_print((char*)"Il simbolo '§' significa che nella stanza sono presenti armi che è possibile raccogliere.\n");
          slow_print((char*)"A fianco di ogni arma sono mostrati anche il numero di munizioni disponibili e l'usura\n");
          cout<<"(Premi un tasto per continuare..)\n";
          getch();
          clear_screen();
          m->stampa(h,p);
          cout<<"Premendo il tasto 'm' si accede al comando AZIONE\n";
          do
           input=getch();
          while ((input!='m')&&(input!='f'));
          switch(input){
               case ('f'):{esci=true; clear_screen(); break;}
               case ('m'):{bool flag6=true; 
                           char input1[25]; 
                           do {
                             cout<<"Digitare 'raccogli' per vedere gli equipaggiamenti presenti nella stanza\n"; 
                             cout<<"(Premi invio una volta terminato l'inserimento)\n"; 
                             cin>>input1;
                             getchar(); 
                             if (strcmp(input1,(char*)"raccogli")==0){
                              cout<<"Cosa vuoi raccogliere?\n\ta)Pistola\t\tMunizioni:\t16"<<endl;
                              do{
                               input=getch();}
                              while ((input!='a')&&(input!='f'));
                              clear_screen(); 
                              flag6=false; 
                              if (input!='f'){
                                 m->stampa(h,p);
                                 p->get_inventario()->push_weapons(w);
                                 cout<<"Pistola in inventario.\nE' necessario equipaggiare l'arma per utilizzarla(Premendo 'm' e digitando 'equipaggia')\n";}
                              else esci=true;}
                            else{
                                flag6=true; 
                                cout<<"\r                                                    ";}}
                           while (flag6);
                           break;}}}
      if (!esci){
        clear_screen();
        Check_inventario();
        if (!esci){
         slow_print((char*)"\n\nIl carico dell'inventario è aumentato.\nUna volta raggiunto il massimo del peso,");
         slow_print((char*)" non sarà più possibile raccogliere armi o armature.\nDurante la creazione del personaggio è possibile");
         slow_print((char*)" aumentare la forza per aumentare il peso massimo trasportabile.\n");
         slow_print((char*)"Inoltre il danno inflitto senza armi equipaggiate è relativo al danno a mani nude\n");
         cout<<"(Premi un tasto per continuare..)\n";
         getch();
         clear_screen();
         m->stampa(h,p);}}
      if (!esci){
         bool flag_1=true;
         do{
         clear_screen();
          m->stampa(h,p);
          slow_print((char*)"Ora accedi all'inventario ed equipaggia <Pistola>.\n");
          Check_inventario();
          if (p->is_in_weapon())
              {slow_print((char*)"Bravo "); cout<<n<<"\n"; flag_1=false;}
          else {flag_1=true; slow_print((char*)"Non hai equipaggiato pistola, ritenta\n");}}
          while (flag_1);}
   
      if (!esci){    
          Check_statistiche();
          if (!esci){
            slow_print((char*)"In statistiche è possibile tenere monitorato lo stato delle munizioni disponibili dell'arma equipaggiata");
            slow_print((char*)" e il range di danno\nRicorda anche che quando equipaggi un'arma o un'armatura aumenta il peso dell'equipaggiamento.\n");
            slow_print((char*)"Se il fattore di carico supera il 70% subisci una perdita in agilità e al superamento del 100%");
            slow_print((char*)" l'agilità crolla vertiginosamente\n");
            cout<<"(Premi un tasto per continuare..)\n"; 
            getch();
            clear_screen(); 
            m->stampa(h,p);}}
   if (!esci){
      slow_print((char*)"Una volta terminate le munizioni di un'arma, essa continua a rimanere equipaggiata.\nRicordati che durante un");
      slow_print((char*)" combattimento se attacchi con un'arma scarica, l'attacco sarà totalmente inefficace.\n");
      slow_print((char*)"Un'arma o un'armatura può essere rilasciata nella stanza dall'inventario.\n");
      slow_print((char*)"Questo è utile nel caso lo spazio in inventario sia al limite e si voglia raccogliere altro equipaggiamento da terra\n");
      slow_print((char*)"Per rilasciare l'equipaggiamento pesante per l'inventario o non più funzionante premi 'h'.\n");
      slow_print((char*)"Premendo 'k' decifrerai il codice morse inviato dal maggiore Ivan\n");}
   cout<<"[Premi un tasto per terminare l'addestramento]\n";
   getch();
   slow_print((char*)"ADDESTRAMENTO TERMINATO\n"); 
   loading();
   clear_screen();}
