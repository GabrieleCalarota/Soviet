#include "Task.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "Inventario.hpp"
#include "Boss.hpp"


 Task::Task(){
  i_task=1;
  clues=0;}


 void Task::curr_task(Player* p,bool type,Map* m){ //type=true PRINT_MISSION type=false CHECK MISSION STATUS
  bool flag=false;
  switch (i_task){
    case (1): {if (type) print_task_1(); else flag=task_1(p); break;}
    case (2): {if (type) print_task_2(p); else flag=task_2(p,m); break;}
    case (3): {if (type) print_task_3(); else flag=task_3(p,m); break;}
    case (4): {if (type) print_task_4(); else flag=task_4(p); break;}
    case (5): {if (type) print_task_5(); else flag=task_5(m,p); break;}
    case (6): {if (type) print_task_6(); else flag=task_6(p,m); break;}
    case (7): {if (type) print_task_7(); else flag=task_7(p); break;}
    case (8): {if (type) print_task_8(p); else flag=task_8(p,m); break;}
    case (9): {if (type) print_task_9(); else flag=task_9(p,m); break;}}
 if (flag) 
  i_task++;}


 int Task::get_current_task() {return i_task;}

 void Task::inc_clues() { clues++;}

 

 void Task::print_task_1(){
  slow_print((char*)"Scopri informazioni riguardo l'anatomia delle creature mutate.\nINFORMAZIONI TROVATE	");
  cout<<clues<<"/3\n";}

 bool Task::task_1(Player* p){
  if (clues>=3){
   slow_print((char*)"MISSIONE COMPLETATA\nEsperienza +60\n");
   p->inc_experience(60); 
   return true;}
  else 
   return false;}



 void Task::print_task_2(Player* p){
  slow_print((char*)"Trova e leggi i documenti riguardo i fatti accaduti nella struttura.\nDOCUMENTI TROVATI "); 
  cout<<p->get_inventario()->get_indice_doc()+1<<"\nDOCUMENTI LETTI "<<p->get_inventario()->get_indice_docs_letti()<<"/2\n";}

 bool Task::task_2(Player* p,Map* m){ 
  if (p->get_inventario()->task_2()){
    slow_print((char*)"MISSIONE COMPLETATA\nEsperienza +100\n");
    p->inc_experience(100);
    m->generate_boss(p);
    return true;}
  else 
   return false;}



 void Task::print_task_3(){
   slow_print((char*)"Uccidi il Boss della prigione\n");}

 bool Task::task_3(Player* p,Map* m){
  if (m->get_boss()->is_dead()){
   slow_print((char*)"Il cadavere immenso della creatura ha aperto un varco nella parete della stanza. Speri sia la tua via di fuga, e entri senza indugio.\nMISSIONE COMPLETATA\nEsperienza +150\n");
   slow_print((char*)"Pozzo rigenerante!\n");
   p->change_life(p->get_max_life());
   p->change_energy(p->get_max_energy());
   p->change_infected(false);
   p->inc_experience(150); 
   clues=0;
   return true;}
  else 
   return false;}



 void Task::print_task_4(){
  slow_print((char*)"Scopri informazioni riguardo l'anatomia delle creature dei sotterranei.\nINFORMAZIONI TROVATE	");
  cout<<clues<<"/4"<<endl;;}

 bool Task::task_4(Player* p){
  if (clues>=4){
   slow_print((char*)"MISSIONE COMPLETATA.\nEsperienza +120\n");
   p->inc_experience(120); 
   return true;}
  else 
   return false;}


 
 void Task::print_task_5(){
   slow_print((char*)"Raggiungi la fine del fiume.\n");}

 bool Task::task_5(Map* m,Player* p){
  if ((m->end_of_river())&&(clues>=4)){
   slow_print((char*)"Il fiume termina in una pozza di acqua stagnante, continuando sottoterra in un'altra direzione.\nUn cadavere putrefatto al centro della pozza tiene in mano qualcosa, forse una speranza per scoprire la verità e scappare.\nTi avvicini nonostante i due occhi vuoti che ti osservano e capisci che l'oggetto è una chiave.\nLa strappi dalle mani del suo raccapricciante proprietario e riconosci subito il rumore che all'improvviso risuona nella caverna. Scappa o combatti.\n");
   getch();
   m->generate_boss(p);
   return true;}
  else
   return false;}



 void Task::print_task_6(){
  slow_print((char*)"Uccidi il Boss dei sotterranei\n");}

 bool Task::task_6(Player* p,Map* m){
  if (m->get_boss()->is_dead()){
   slow_print((char*)"La creatura immonda strilla e si dimena, incapace di accettare la sconfitta.\nCapisci che la chiave deve avere un senso, deve portare da qualche parte.\nSulla destra noti una piccola galleria scavata nella roccia e decidi di percorrerla.\nAumenti il passo sapendo che quella può essere la volta buona finchè non ti fermi davanti ad un ascensore.\nE la chiave ci entra perfettamente.\nLa pulsantiera è finta e l'unico bottone esistente ha stampato sopra un numero: 57\nCon un suono metallico il meccanismo inizia a sollevare la cabina, mentre la curiosità lotta con l'ansia.\nQuando la velocità inizia a diminuire ti posizioni al lato della porta, pronto ad agire.\nLa porta si apre sfregando sui binario-guida, dandoti il benvenuto nel settore sopraelevato della base.\nCapisci che in questo posto puoi trovare una risposta alle tue domande e incominci a cercare.\nMISSIONE COMPLETATA\nEsperienza +200\n");
   p->inc_experience(200);
   slow_print((char*)"Pozzo rigenerante!\n");
   p->change_life(p->get_max_life());
   p->change_energy(p->get_max_energy());
   p->change_infected(false);
   getch();
   clues=0;
   return true;}
  else 
   return false;}



 void Task::print_task_7(){
  slow_print((char*)"Scopri informazioni riguardo l'anatomia delle creature del piano 57.\nINFORMAZIONI TROVATE	");
  cout<<clues<<"/4"<<endl;}

 bool Task::task_7(Player* p){
  if (clues>=4){
   slow_print((char*)"MISSIONE COMPLETATA.\nEsperienza +150\n");
   p->inc_experience(150); 
   return true;}
  else 
   return false;}



 void Task::print_task_8(Player* p){
  slow_print((char*)"Trova e leggi i documenti riguardo i fatti accaduti nella struttura.\nDOCUMENTI TROVATI "); 
  cout<<p->get_inventario()->get_indice_doc()+1<<"/10\nDOCUMENTI LETTI "<<p->get_inventario()->get_indice_docs_letti()<<"/10\n";}

 bool Task::task_8(Player* p,Map* m){ 
  if (p->get_inventario()->get_indice_docs_letti()>=10){
   slow_print((char*)"MISSIONE COMPLETATA\nEsperienza +180\n");
   p->inc_experience(180);
   m->generate_boss(p);
   return true;}
  else
   return false;}


 
 void Task::print_task_9(){
  slow_print((char*)"Uccidi il Boss del piano 57\n");}

 bool Task::task_9(Player* p,Map* m){
  if (m->get_boss()->is_dead()){
   slow_print((char*)"Il corpo del gigantesco essere umanoide crolla esanime, sfinito dalla fatica del combattimento e dai colpi inferti.\nTi avvicini nell'intento di controllare che sia effettivamente morto e un piccolo dettaglio ti salta all'occhio. Un cartellino di riconoscimento fuso alla pelle in seguito ad una sorta di trasformazione.\nLa stanchezza ti pervade, nonostante la volontà di rimanere cosciente. Senti la testa girare finchè tutto non diventa nero dietro le palpebre.\n L'ultima cosa che senti sono voci familiari che ti chiamano.\n\n\n\n\n\nRAPPORTO MISSIONE ROSWELL\nIl soldato speciale è stato recuperato non cosciente dalla nostra cellula di emergenza.\nSi trovava in territorio Americano, all'ultimo piano di una base segreta conosciuta ora come 'INFERNO'.\nOra il soldato si trova all'interno del reparto di riabilitazione e tutto ciò che è riuscito a dire fino adesso è riportato di seguito:\n'Abrahm Miller, Paziente Zero'\n");
   clues=0;
   return true;}
  else 
   return false;}
