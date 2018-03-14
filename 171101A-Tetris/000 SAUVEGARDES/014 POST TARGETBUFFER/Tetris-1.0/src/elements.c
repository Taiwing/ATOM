#include "include/elements.h"

elements *genererElements()
{
  elements *elem = malloc(sizeof(*elem)); //on crée le pointeur qu'on va renvoyer

  /******************************************/
  /***************ALLOCATIONS****************/
  /******************************************/

  //éléments globaux
  elem->rectPrincipal = malloc(sizeof(coord)); //cadre principal du jeu
  elem->rectScores = malloc(sizeof(coord)); //cadre où on va afficher le panneau de scores/temps/lignes
  elem->rectPieceSuiv = malloc(sizeof(coord)); //cadre où on va afficher la prochaine pièce
  elem->rectNSL = malloc(sizeof(coord)); //cadre où on va afficher le niveau, le score et le nombre de lignes
  elem->rectTemps = malloc(sizeof(coord)); //cadre juste en dessous de NSL qui sert à afficher le timer dans partieSprint et partieUltra
  elem->rectAide = malloc(sizeof(coord)); //cadre du panneau d'aide
  elem->rectPause = malloc(sizeof(coord)); //cadre du menu pause
  elem->rectOptions = malloc(sizeof(coord)); //cadre du menu options
  elem->rectInputOptions = malloc(sizeof(coord)); //cadre de l'input des touches dans le menu options
  elem->rectSTLInput = malloc(sizeof(coord)); //cadre de l'image des fonctions scoreInput lignesInput et tempsInput

  //éléments boutons
  //Menu Principal
  elem->rectBMenuJouer = malloc(sizeof(coord));
  elem->rectBMenuNiveau = malloc(sizeof(coord));
  elem->rectBMenuMode = malloc(sizeof(coord));
  elem->rectBMenuAide = malloc(sizeof(coord));
  elem->rectBMenuOptions = malloc(sizeof(coord));
  //Aide
  elem->rectBAideOk = malloc(sizeof(coord));
  //Pause
  elem->rectBPauseReprendre = malloc(sizeof(coord));
  elem->rectBPauseAide = malloc(sizeof(coord));
  elem->rectBPauseOptions = malloc(sizeof(coord));
  elem->rectBPauseQuitter = malloc(sizeof(coord));
  //Options
  elem->rectBOptionsVolThemeM = malloc(sizeof(coord));
  elem->rectBOptionsVolThemeP = malloc(sizeof(coord));
  elem->rectBOptionsVolFXM = malloc(sizeof(coord));
  elem->rectBOptionsVolFXP = malloc(sizeof(coord));
  elem->rectBOptionsReset = malloc(sizeof(coord));
  elem->rectBOptionsOk = malloc(sizeof(coord));
  //Input Options
  elem->rectBInputOptionsOk = malloc(sizeof(coord));
  //STL input (fonctions d'input des fonctions high (ScoreTempsLignes))
  elem->rectBSTLOk = malloc(sizeof(coord));

  //éléments input
  //Options
  elem->rectIOptionsLeft = malloc(sizeof(coord));
  elem->rectIOptionsRight = malloc(sizeof(coord));
  elem->rectIOptionsRotatel = malloc(sizeof(coord));
  elem->rectIOptionsRotater = malloc(sizeof(coord));
  elem->rectIOptionsHardd = malloc(sizeof(coord));
  elem->rectIOptionsSoftd = malloc(sizeof(coord));
  elem->rectIOptionsPause = malloc(sizeof(coord));
  elem->rectIOptionsGhost = malloc(sizeof(coord));
  elem->rectIOptionsChange = malloc(sizeof(coord));
  //Input Options
  elem->rectIInputOptionsTouche1 = malloc(sizeof(coord));
  elem->rectIInputOptionsTouche2 = malloc(sizeof(coord));
  elem->rectIInputOptionsTouche3 = malloc(sizeof(coord));
  //STL input
  elem->rectISTLInput = malloc(sizeof(coord));

  /******************************************/
  /***************DECLARATIONS***************/
  /******************************************/

  int epaisseur = 6, epaisseurOptions = 2; //valeurs de l'épaisseur des traits

  //rectPrincipal
  elem->rectPrincipal->defx = 78; //coordonnée x du point d'origine
  elem->rectPrincipal->defy = 13; //coordonnée y du point d'origine
  elem->rectPrincipal->defx2 = 373; //coordonnée x du point de fin
  elem->rectPrincipal->defy2 = 588; //coordonnée y du point de fin
  elem->rectPrincipal->defw = elem->rectPrincipal->defx2 - elem->rectPrincipal->defx; //largeur
  elem->rectPrincipal->defh = elem->rectPrincipal->defy2 - elem->rectPrincipal->defy; //hauteur
  elem->rectPrincipal->deft = epaisseur; //épaisseur des traits

  //rectScores
  elem->rectScores->defx = 126; //coordonnée x du point d'origine
  elem->rectScores->defy = 277; //coordonnée y du point d'origine
  elem->rectScores->defx2 = 326; //coordonnée x du point de fin
  elem->rectScores->defy2 = 493; //coordonnée y du point de fin
  elem->rectScores->defw = elem->rectScores->defx2 - elem->rectScores->defx; //largeur
  elem->rectScores->defh = elem->rectScores->defy2 - elem->rectScores->defy; //hauteur
  elem->rectScores->deft = epaisseur; //épaisseur des traits

  //rectPieceSuiv
  elem->rectPieceSuiv->defx = 382; //coordonnée x du point d'origine
  elem->rectPieceSuiv->defy = 13; //coordonnée y du point d'origine
  elem->rectPieceSuiv->defx2 = 649; //coordonnée x du point de fin
  elem->rectPieceSuiv->defy2 = 131; //coordonnée y du point de fin
  elem->rectPieceSuiv->defw = elem->rectPieceSuiv->defx2 - elem->rectPieceSuiv->defx; //largeur
  elem->rectPieceSuiv->defh = elem->rectPieceSuiv->defy2 - elem->rectPieceSuiv->defy; //hauteur
  elem->rectPieceSuiv->deft = epaisseur; //épaisseur des traits

  //rectNSL
  elem->rectNSL->defx = 382; //coordonnée x du point d'origine
  elem->rectNSL->defy = 139; //coordonnée y du point d'origine
  elem->rectNSL->defx2 = 649; //coordonnée x du point de fin
  elem->rectNSL->defy2 = 307; //coordonnée y du point de fin
  elem->rectNSL->defw = elem->rectNSL->defx2 - elem->rectNSL->defx; //largeur
  elem->rectNSL->defh = elem->rectNSL->defy2 - elem->rectNSL->defy; //hauteur
  elem->rectNSL->deft = epaisseur; //épaisseur des traits

  //rectTemps
  elem->rectTemps->defx = 382; //coordonnée x du point d'origine
  elem->rectTemps->defy = 301; //coordonnée y du point d'origine
  elem->rectTemps->defx2 = 649; //coordonnée x du point de fin
  elem->rectTemps->defy2 = 361; //coordonnée y du point de fin
  elem->rectTemps->defw = elem->rectTemps->defx2 - elem->rectTemps->defx; //largeur
  elem->rectTemps->defh = elem->rectTemps->defy2 - elem->rectTemps->defy; //hauteur
  elem->rectTemps->deft = epaisseur; //épaisseur des traits

  //rectAide
  elem->rectAide->defx = 104; //coordonnée x du point d'origine
  elem->rectAide->defy = 53; //coordonnée y du point d'origine
  elem->rectAide->defx2 = 347; //coordonnée x du point de fin
  elem->rectAide->defy2 = 548; //coordonnée y du point de fin
  elem->rectAide->defw = elem->rectAide->defx2 - elem->rectAide->defx; //largeur
  elem->rectAide->defh = elem->rectAide->defy2 - elem->rectAide->defy; //hauteur
  elem->rectAide->deft = epaisseur; //épaisseur des traits

  //rectPause
  elem->rectPause->defx = 96; //coordonnée x du point d'origine
  elem->rectPause->defy = 75; //coordonnée y du point d'origine
  elem->rectPause->defx2 = 355; //coordonnée x du point de fin
  elem->rectPause->defy2 = 526; //coordonnée y du point de fin
  elem->rectPause->defw = elem->rectPause->defx2 - elem->rectPause->defx; //largeur
  elem->rectPause->defh = elem->rectPause->defy2 - elem->rectPause->defy; //hauteur
  elem->rectPause->deft = epaisseur; //épaisseur des traits

  //rectOptions
  elem->rectOptions->defx = 48; //coordonnée x du point d'origine
  elem->rectOptions->defy = 3; //coordonnée y du point d'origine
  elem->rectOptions->defx2 = 403; //coordonnée x du point de fin
  elem->rectOptions->defy2 = 598; //coordonnée y du point de fin
  elem->rectOptions->defw = elem->rectOptions->defx2 - elem->rectOptions->defx; //largeur
  elem->rectOptions->defh = elem->rectOptions->defy2 - elem->rectOptions->defy; //hauteur
  elem->rectOptions->deft = epaisseur; //épaisseur des traits

  //rectInputOptions
  elem->rectInputOptions->defx = 78; //coordonnée x du point d'origine
  elem->rectInputOptions->defy = 200; //coordonnée y du point d'origine
  elem->rectInputOptions->defx2 = 373; //coordonnée x du point de fin
  elem->rectInputOptions->defy2 = 400; //coordonnée y du point de fin
  elem->rectInputOptions->defw = elem->rectInputOptions->defx2 - elem->rectInputOptions->defx; //largeur
  elem->rectInputOptions->defh = elem->rectInputOptions->defy2 - elem->rectInputOptions->defy; //hauteur
  elem->rectInputOptions->deft = epaisseur; //épaisseur des traits

  //rectSTLInput
  elem->rectSTLInput->defx = 96; //coordonnée x du point d'origine
  elem->rectSTLInput->defy = 135; //coordonnée y du point d'origine
  elem->rectSTLInput->defx2 = 355; //coordonnée x du point de fin
  elem->rectSTLInput->defy2 = 466; //coordonnée y du point de fin
  elem->rectSTLInput->defw = elem->rectSTLInput->defx2 - elem->rectSTLInput->defx; //largeur
  elem->rectSTLInput->defh = elem->rectSTLInput->defy2 - elem->rectSTLInput->defy; //hauteur
  elem->rectSTLInput->deft = epaisseur; //épaisseur des traits

  //rectBMenuJouer
  elem->rectBMenuJouer->defx = 111; //coordonnée x du point d'origine
  elem->rectBMenuJouer->defy = 37; //coordonnée y du point d'origine
  elem->rectBMenuJouer->defx2 = 341; //coordonnée x du point de fin
  elem->rectBMenuJouer->defy2 = 127; //coordonnée y du point de fin
  elem->rectBMenuJouer->defw = elem->rectBMenuJouer->defx2 - elem->rectBMenuJouer->defx; //largeur
  elem->rectBMenuJouer->defh = elem->rectBMenuJouer->defy2 - elem->rectBMenuJouer->defy; //hauteur
  elem->rectBMenuJouer->deft = epaisseur; //épaisseur des traits

  //rectBMenuNiveau
  elem->rectBMenuNiveau->defx = 126; //coordonnée x du point d'origine
  elem->rectBMenuNiveau->defy = 207; //coordonnée y du point d'origine
  elem->rectBMenuNiveau->defx2 = 326; //coordonnée x du point de fin
  elem->rectBMenuNiveau->defy2 = 267; //coordonnée y du point de fin
  elem->rectBMenuNiveau->defw = elem->rectBMenuNiveau->defx2 - elem->rectBMenuNiveau->defx; //largeur
  elem->rectBMenuNiveau->defh = elem->rectBMenuNiveau->defy2 - elem->rectBMenuNiveau->defy; //hauteur
  elem->rectBMenuNiveau->deft = epaisseur; //épaisseur des traits

  //rectBMenuMode
  elem->rectBMenuMode->defx = 126; //coordonnée x du point d'origine
  elem->rectBMenuMode->defy = 137; //coordonnée y du point d'origine
  elem->rectBMenuMode->defx2 = 326; //coordonnée x du point de fin
  elem->rectBMenuMode->defy2 = 197; //coordonnée y du point de fin
  elem->rectBMenuMode->defw = elem->rectBMenuMode->defx2 - elem->rectBMenuMode->defx; //largeur
  elem->rectBMenuMode->defh = elem->rectBMenuMode->defy2 - elem->rectBMenuMode->defy; //hauteur
  elem->rectBMenuMode->deft = epaisseur; //épaisseur des traits

  //rectBMenuAide
  elem->rectBMenuAide->defx = 126; //coordonnée x du point d'origine
  elem->rectBMenuAide->defy = 503; //coordonnée y du point d'origine
  elem->rectBMenuAide->defx2 = 221; //coordonnée x du point de fin
  elem->rectBMenuAide->defy2 = 563; //coordonnée y du point de fin
  elem->rectBMenuAide->defw = elem->rectBMenuAide->defx2 - elem->rectBMenuAide->defx; //largeur
  elem->rectBMenuAide->defh = elem->rectBMenuAide->defy2 - elem->rectBMenuAide->defy; //hauteur
  elem->rectBMenuAide->deft = epaisseur; //épaisseur des traits

  //rectBMenuOptions
  elem->rectBMenuOptions->defx = 231; //coordonnée x du point d'origine
  elem->rectBMenuOptions->defy = 503; //coordonnée y du point d'origine
  elem->rectBMenuOptions->defx2 = 326; //coordonnée x du point de fin
  elem->rectBMenuOptions->defy2 = 563; //coordonnée y du point de fin
  elem->rectBMenuOptions->defw = elem->rectBMenuOptions->defx2 - elem->rectBMenuOptions->defx; //largeur
  elem->rectBMenuOptions->defh = elem->rectBMenuOptions->defy2 - elem->rectBMenuOptions->defy; //hauteur
  elem->rectBMenuOptions->deft = epaisseur; //épaisseur des traits

  //rectBAideOk
  elem->rectBAideOk->defx = 194; //coordonnée x du point d'origine
  elem->rectBAideOk->defy = 475; //coordonnée y du point d'origine
  elem->rectBAideOk->defx2 = 257; //coordonnée x du point de fin
  elem->rectBAideOk->defy2 = 525; //coordonnée y du point de fin
  elem->rectBAideOk->defw = elem->rectBAideOk->defx2 - elem->rectBAideOk->defx; //largeur
  elem->rectBAideOk->defh = elem->rectBAideOk->defy2 - elem->rectBAideOk->defy; //hauteur
  elem->rectBAideOk->deft = epaisseur; //épaisseur des traits

  //rectBPauseReprendre
  elem->rectBPauseReprendre->defx = 106; //coordonnée x du point d'origine
  elem->rectBPauseReprendre->defy = 181; //coordonnée y du point d'origine
  elem->rectBPauseReprendre->defx2 = 345; //coordonnée x du point de fin
  elem->rectBPauseReprendre->defy2 = 271; //coordonnée y du point de fin
  elem->rectBPauseReprendre->defw = elem->rectBPauseReprendre->defx2 - elem->rectBPauseReprendre->defx; //largeur
  elem->rectBPauseReprendre->defh = elem->rectBPauseReprendre->defy2 - elem->rectBPauseReprendre->defy; //hauteur
  elem->rectBPauseReprendre->deft = epaisseur; //épaisseur des traits

  //rectBPauseAide
  elem->rectBPauseAide->defx = 136; //coordonnée x du point d'origine
  elem->rectBPauseAide->defy = 281; //coordonnée y du point d'origine
  elem->rectBPauseAide->defx2 = 315; //coordonnée x du point de fin
  elem->rectBPauseAide->defy2 = 351; //coordonnée y du point de fin
  elem->rectBPauseAide->defw = elem->rectBPauseAide->defx2 - elem->rectBPauseAide->defx; //largeur
  elem->rectBPauseAide->defh = elem->rectBPauseAide->defy2 - elem->rectBPauseAide->defy; //hauteur
  elem->rectBPauseAide->deft = epaisseur; //épaisseur des traits

  //rectBPauseOptions
  elem->rectBPauseOptions->defx = 136; //coordonnée x du point d'origine
  elem->rectBPauseOptions->defy = 361; //coordonnée y du point d'origine
  elem->rectBPauseOptions->defx2 = 315; //coordonnée x du point de fin
  elem->rectBPauseOptions->defy2 = 431; //coordonnée y du point de fin
  elem->rectBPauseOptions->defw = elem->rectBPauseOptions->defx2 - elem->rectBPauseOptions->defx; //largeur
  elem->rectBPauseOptions->defh = elem->rectBPauseOptions->defy2 - elem->rectBPauseOptions->defy; //hauteur
  elem->rectBPauseOptions->deft = epaisseur; //épaisseur des traits

  //rectBPauseQuitter
  elem->rectBPauseQuitter->defx = 136; //coordonnée x du point d'origine
  elem->rectBPauseQuitter->defy = 441; //coordonnée y du point d'origine
  elem->rectBPauseQuitter->defx2 = 315; //coordonnée x du point de fin
  elem->rectBPauseQuitter->defy2 = 511; //coordonnée y du point de fin
  elem->rectBPauseQuitter->defw = elem->rectBPauseQuitter->defx2 - elem->rectBPauseQuitter->defx; //largeur
  elem->rectBPauseQuitter->defh = elem->rectBPauseQuitter->defy2 - elem->rectBPauseQuitter->defy; //hauteur
  elem->rectBPauseQuitter->deft = epaisseur; //épaisseur des traits

  //rectBOptionsVolThemeM
  elem->rectBOptionsVolThemeM->defx = 241; //coordonnée x du point d'origine
  elem->rectBOptionsVolThemeM->defy = 343; //coordonnée y du point d'origine
  elem->rectBOptionsVolThemeM->defx2 = 281; //coordonnée x du point de fin
  elem->rectBOptionsVolThemeM->defy2 = 363; //coordonnée y du point de fin
  elem->rectBOptionsVolThemeM->defw = elem->rectBOptionsVolThemeM->defx2 - elem->rectBOptionsVolThemeM->defx; //largeur
  elem->rectBOptionsVolThemeM->defh = elem->rectBOptionsVolThemeM->defy2 - elem->rectBOptionsVolThemeM->defy; //hauteur
  elem->rectBOptionsVolThemeM->deft = epaisseurOptions; //épaisseur des traits

  //rectBOptionsVolThemeP
  elem->rectBOptionsVolThemeP->defx = 352; //coordonnée x du point d'origine
  elem->rectBOptionsVolThemeP->defy = 343; //coordonnée y du point d'origine
  elem->rectBOptionsVolThemeP->defx2 = 392; //coordonnée x du point de fin
  elem->rectBOptionsVolThemeP->defy2 = 363; //coordonnée y du point de fin
  elem->rectBOptionsVolThemeP->defw = elem->rectBOptionsVolThemeP->defx2 - elem->rectBOptionsVolThemeP->defx; //largeur
  elem->rectBOptionsVolThemeP->defh = elem->rectBOptionsVolThemeP->defy2 - elem->rectBOptionsVolThemeP->defy; //hauteur
  elem->rectBOptionsVolThemeP->deft = epaisseurOptions; //épaisseur des traits

  //rectBOptionsVolFXM
  elem->rectBOptionsVolFXM->defx = 241; //coordonnée x du point d'origine
  elem->rectBOptionsVolFXM->defy = 383; //coordonnée y du point d'origine
  elem->rectBOptionsVolFXM->defx2 = 281; //coordonnée x du point de fin
  elem->rectBOptionsVolFXM->defy2 = 403; //coordonnée y du point de fin
  elem->rectBOptionsVolFXM->defw = elem->rectBOptionsVolFXM->defx2 - elem->rectBOptionsVolFXM->defx; //largeur
  elem->rectBOptionsVolFXM->defh = elem->rectBOptionsVolFXM->defy2 - elem->rectBOptionsVolFXM->defy; //hauteur
  elem->rectBOptionsVolFXM->deft = epaisseurOptions; //épaisseur des traits

  //rectBOptionsVolFXP
  elem->rectBOptionsVolFXP->defx = 352; //coordonnée x du point d'origine
  elem->rectBOptionsVolFXP->defy = 383; //coordonnée y du point d'origine
  elem->rectBOptionsVolFXP->defx2 = 392; //coordonnée x du point de fin
  elem->rectBOptionsVolFXP->defy2 = 403; //coordonnée y du point de fin
  elem->rectBOptionsVolFXP->defw = elem->rectBOptionsVolFXP->defx2 - elem->rectBOptionsVolFXP->defx; //largeur
  elem->rectBOptionsVolFXP->defh = elem->rectBOptionsVolFXP->defy2 - elem->rectBOptionsVolFXP->defy; //hauteur
  elem->rectBOptionsVolFXP->deft = epaisseurOptions; //épaisseur des traits

  //rectBOptionsReset
  elem->rectBOptionsReset->defx = 134; //coordonnée x du point d'origine
  elem->rectBOptionsReset->defy = 433; //coordonnée y du point d'origine
  elem->rectBOptionsReset->defx2 = 317; //coordonnée x du point de fin
  elem->rectBOptionsReset->defy2 = 483; //coordonnée y du point de fin
  elem->rectBOptionsReset->defw = elem->rectBOptionsReset->defx2 - elem->rectBOptionsReset->defx; //largeur
  elem->rectBOptionsReset->defh = elem->rectBOptionsReset->defy2 - elem->rectBOptionsReset->defy; //hauteur
  elem->rectBOptionsReset->deft = epaisseur; //épaisseur des traits

  //rectBOptionsOk
  elem->rectBOptionsOk->defx = 194; //coordonnée x du point d'origine
  elem->rectBOptionsOk->defy = 508; //coordonnée y du point d'origine
  elem->rectBOptionsOk->defx2 = 257; //coordonnée x du point de fin
  elem->rectBOptionsOk->defy2 = 558; //coordonnée y du point de fin
  elem->rectBOptionsOk->defw = elem->rectBOptionsOk->defx2 - elem->rectBOptionsOk->defx; //largeur
  elem->rectBOptionsOk->defh = elem->rectBOptionsOk->defy2 - elem->rectBOptionsOk->defy; //hauteur
  elem->rectBOptionsOk->deft = epaisseur; //épaisseur des traits

  //rectBSTLOk
  elem->rectBSTLOk->defx = 194; //coordonnée x du point d'origine
  elem->rectBSTLOk->defy = 385; //coordonnée y du point d'origine
  elem->rectBSTLOk->defx2 = 257; //coordonnée x du point de fin
  elem->rectBSTLOk->defy2 = 435; //coordonnée y du point de fin
  elem->rectBSTLOk->defw = elem->rectBSTLOk->defx2 - elem->rectBSTLOk->defx; //largeur
  elem->rectBSTLOk->defh = elem->rectBSTLOk->defy2 - elem->rectBSTLOk->defy; //hauteur
  elem->rectBSTLOk->deft = epaisseur; //épaisseur des traits

  //rectIOptionsLeft
  elem->rectIOptionsLeft->defx = 241; //coordonnée x du point d'origine
  elem->rectIOptionsLeft->defy = 103; //coordonnée y du point d'origine
  elem->rectIOptionsLeft->defx2 = 392; //coordonnée x du point de fin
  elem->rectIOptionsLeft->defy2 = 123; //coordonnée y du point de fin
  elem->rectIOptionsLeft->defw = elem->rectIOptionsLeft->defx2 - elem->rectIOptionsLeft->defx; //largeur
  elem->rectIOptionsLeft->defh = elem->rectIOptionsLeft->defy2 - elem->rectIOptionsLeft->defy; //hauteur
  elem->rectIOptionsLeft->deft = epaisseurOptions; //épaisseur des traits

  //rectIOptionsRight
  elem->rectIOptionsRight->defx = 241; //coordonnée x du point d'origine
  elem->rectIOptionsRight->defy = 128; //coordonnée y du point d'origine
  elem->rectIOptionsRight->defx2 = 392; //coordonnée x du point de fin
  elem->rectIOptionsRight->defy2 = 148; //coordonnée y du point de fin
  elem->rectIOptionsRight->defw = elem->rectIOptionsRight->defx2 - elem->rectIOptionsRight->defx; //largeur
  elem->rectIOptionsRight->defh = elem->rectIOptionsRight->defy2 - elem->rectIOptionsRight->defy; //hauteur
  elem->rectIOptionsRight->deft = epaisseurOptions; //épaisseur des traits

  //rectIOptionsRotatel
  elem->rectIOptionsRotatel->defx = 241; //coordonnée x du point d'origine
  elem->rectIOptionsRotatel->defy = 153; //coordonnée y du point d'origine
  elem->rectIOptionsRotatel->defx2 = 392; //coordonnée x du point de fin
  elem->rectIOptionsRotatel->defy2 = 173; //coordonnée y du point de fin
  elem->rectIOptionsRotatel->defw = elem->rectIOptionsRotatel->defx2 - elem->rectIOptionsRotatel->defx; //largeur
  elem->rectIOptionsRotatel->defh = elem->rectIOptionsRotatel->defy2 - elem->rectIOptionsRotatel->defy; //hauteur
  elem->rectIOptionsRotatel->deft = epaisseurOptions; //épaisseur des traits

  //rectIOptionsRotater
  elem->rectIOptionsRotater->defx = 241; //coordonnée x du point d'origine
  elem->rectIOptionsRotater->defy = 178; //coordonnée y du point d'origine
  elem->rectIOptionsRotater->defx2 = 392; //coordonnée x du point de fin
  elem->rectIOptionsRotater->defy2 = 198; //coordonnée y du point de fin
  elem->rectIOptionsRotater->defw = elem->rectIOptionsRotater->defx2 - elem->rectIOptionsRotater->defx; //largeur
  elem->rectIOptionsRotater->defh = elem->rectIOptionsRotater->defy2 - elem->rectIOptionsRotater->defy; //hauteur
  elem->rectIOptionsRotater->deft = epaisseurOptions; //épaisseur des traits

  //rectIOptionsHardd
  elem->rectIOptionsHardd->defx = 241; //coordonnée x du point d'origine
  elem->rectIOptionsHardd->defy = 203; //coordonnée y du point d'origine
  elem->rectIOptionsHardd->defx2 = 392; //coordonnée x du point de fin
  elem->rectIOptionsHardd->defy2 = 223; //coordonnée y du point de fin
  elem->rectIOptionsHardd->defw = elem->rectIOptionsHardd->defx2 - elem->rectIOptionsHardd->defx; //largeur
  elem->rectIOptionsHardd->defh = elem->rectIOptionsHardd->defy2 - elem->rectIOptionsHardd->defy; //hauteur
  elem->rectIOptionsHardd->deft = epaisseurOptions; //épaisseur des traits

  //rectIOptionsSoftd
  elem->rectIOptionsSoftd->defx = 241; //coordonnée x du point d'origine
  elem->rectIOptionsSoftd->defy = 228; //coordonnée y du point d'origine
  elem->rectIOptionsSoftd->defx2 = 392; //coordonnée x du point de fin
  elem->rectIOptionsSoftd->defy2 = 248; //coordonnée y du point de fin
  elem->rectIOptionsSoftd->defw = elem->rectIOptionsSoftd->defx2 - elem->rectIOptionsSoftd->defx; //largeur
  elem->rectIOptionsSoftd->defh = elem->rectIOptionsSoftd->defy2 - elem->rectIOptionsSoftd->defy; //hauteur
  elem->rectIOptionsSoftd->deft = epaisseurOptions; //épaisseur des traits

  //rectIOptionsPause
  elem->rectIOptionsPause->defx = 241; //coordonnée x du point d'origine
  elem->rectIOptionsPause->defy = 253; //coordonnée y du point d'origine
  elem->rectIOptionsPause->defx2 = 392; //coordonnée x du point de fin
  elem->rectIOptionsPause->defy2 = 273; //coordonnée y du point de fin
  elem->rectIOptionsPause->defw = elem->rectIOptionsPause->defx2 - elem->rectIOptionsPause->defx; //largeur
  elem->rectIOptionsPause->defh = elem->rectIOptionsPause->defy2 - elem->rectIOptionsPause->defy; //hauteur
  elem->rectIOptionsPause->deft = epaisseurOptions; //épaisseur des traits

  //rectIOptionsGhost
  elem->rectIOptionsGhost->defx = 241; //coordonnée x du point d'origine
  elem->rectIOptionsGhost->defy = 278; //coordonnée y du point d'origine
  elem->rectIOptionsGhost->defx2 = 392; //coordonnée x du point de fin
  elem->rectIOptionsGhost->defy2 = 298; //coordonnée y du point de fin
  elem->rectIOptionsGhost->defw = elem->rectIOptionsGhost->defx2 - elem->rectIOptionsGhost->defx; //largeur
  elem->rectIOptionsGhost->defh = elem->rectIOptionsGhost->defy2 - elem->rectIOptionsGhost->defy; //hauteur
  elem->rectIOptionsGhost->deft = epaisseurOptions; //épaisseur des traits

  //rectIOptionsChange
  elem->rectIOptionsChange->defx = 241; //coordonnée x du point d'origine
  elem->rectIOptionsChange->defy = 303; //coordonnée y du point d'origine
  elem->rectIOptionsChange->defx2 = 392; //coordonnée x du point de fin
  elem->rectIOptionsChange->defy2 = 323; //coordonnée y du point de fin
  elem->rectIOptionsChange->defw = elem->rectIOptionsChange->defx2 - elem->rectIOptionsChange->defx; //largeur
  elem->rectIOptionsChange->defh = elem->rectIOptionsChange->defy2 - elem->rectIOptionsChange->defy; //hauteur
  elem->rectIOptionsChange->deft = epaisseurOptions; //épaisseur des traits

  //rectIInputOptionsTouche1
  elem->rectIInputOptionsTouche1->defx = 241; //coordonnée x du point d'origine
  elem->rectIInputOptionsTouche1->defy = 230; //coordonnée y du point d'origine
  elem->rectIInputOptionsTouche1->defx2 = 362; //coordonnée x du point de fin
  elem->rectIInputOptionsTouche1->defy2 = 250; //coordonnée y du point de fin
  elem->rectIInputOptionsTouche1->defw = elem->rectIInputOptionsTouche1->defx2 - elem->rectIInputOptionsTouche1->defx; //largeur
  elem->rectIInputOptionsTouche1->defh = elem->rectIInputOptionsTouche1->defy2 - elem->rectIInputOptionsTouche1->defy; //hauteur
  elem->rectIInputOptionsTouche1->deft = epaisseurOptions; //épaisseur des traits

  //rectIInputOptionsTouche2
  elem->rectIInputOptionsTouche2->defx = 241; //coordonnée x du point d'origine
  elem->rectIInputOptionsTouche2->defy = 255; //coordonnée y du point d'origine
  elem->rectIInputOptionsTouche2->defx2 = 362; //coordonnée x du point de fin
  elem->rectIInputOptionsTouche2->defy2 = 275; //coordonnée y du point de fin
  elem->rectIInputOptionsTouche2->defw = elem->rectIInputOptionsTouche2->defx2 - elem->rectIInputOptionsTouche2->defx; //largeur
  elem->rectIInputOptionsTouche2->defh = elem->rectIInputOptionsTouche2->defy2 - elem->rectIInputOptionsTouche2->defy; //hauteur
  elem->rectIInputOptionsTouche2->deft = epaisseurOptions; //épaisseur des traits

  //rectIInputOptionsTouche3
  elem->rectIInputOptionsTouche3->defx = 241; //coordonnée x du point d'origine
  elem->rectIInputOptionsTouche3->defy = 280; //coordonnée y du point d'origine
  elem->rectIInputOptionsTouche3->defx2 = 362; //coordonnée x du point de fin
  elem->rectIInputOptionsTouche3->defy2 = 300; //coordonnée y du point de fin
  elem->rectIInputOptionsTouche3->defw = elem->rectIInputOptionsTouche3->defx2 - elem->rectIInputOptionsTouche3->defx; //largeur
  elem->rectIInputOptionsTouche3->defh = elem->rectIInputOptionsTouche3->defy2 - elem->rectIInputOptionsTouche3->defy; //hauteur
  elem->rectIInputOptionsTouche3->deft = epaisseurOptions; //épaisseur des traits

  //rectBInputOptionsOk
  elem->rectBInputOptionsOk->defx = 194; //coordonnée x du point d'origine
  elem->rectBInputOptionsOk->defy = 320; //coordonnée y du point d'origine
  elem->rectBInputOptionsOk->defx2 = 257; //coordonnée x du point de fin
  elem->rectBInputOptionsOk->defy2 = 370; //coordonnée y du point de fin
  elem->rectBInputOptionsOk->defw = elem->rectBInputOptionsOk->defx2 - elem->rectBInputOptionsOk->defx; //largeur
  elem->rectBInputOptionsOk->defh = elem->rectBInputOptionsOk->defy2 - elem->rectBInputOptionsOk->defy; //hauteur
  elem->rectBInputOptionsOk->deft = epaisseur; //épaisseur des traits

  //rectISTLInput
  elem->rectISTLInput->defx = 141; //coordonnée x du point d'origine
  elem->rectISTLInput->defy = 315; //coordonnée y du point d'origine
  elem->rectISTLInput->defx2 = 310; //coordonnée x du point de fin
  elem->rectISTLInput->defy2 = 365; //coordonnée y du point de fin
  elem->rectISTLInput->defw = elem->rectISTLInput->defx2 - elem->rectISTLInput->defx; //largeur
  elem->rectISTLInput->defh = elem->rectISTLInput->defy2 - elem->rectISTLInput->defy; //hauteur
  elem->rectISTLInput->deft = epaisseur; //épaisseur des traits

  return elem;
}

void resizeElements(elements *elem, float scale)
{
  float epaisseur = 6 * scale, epaisseurOptions = 2 * scale; //valeurs de l'épaisseur des traits

  //rectPrincipal
  elem->rectPrincipal->x = (float)elem->rectPrincipal->defx * scale; //coordonnée x du point d'origine
  elem->rectPrincipal->y = (float)elem->rectPrincipal->defy * scale; //coordonnée y du point d'origine
  elem->rectPrincipal->x2 = (float)elem->rectPrincipal->defx2 * scale; //coordonnée x du point de fin
  elem->rectPrincipal->y2 = (float)elem->rectPrincipal->defy2 * scale; //coordonnée y du point de fin
  elem->rectPrincipal->w = elem->rectPrincipal->x2 - elem->rectPrincipal->x; //largeur
  elem->rectPrincipal->h = elem->rectPrincipal->y2 - elem->rectPrincipal->y; //hauteur
  elem->rectPrincipal->t = epaisseur; //épaisseur des traits

  //rectScores
  elem->rectScores->x = (float)elem->rectScores->defx * scale; //coordonnée x du point d'origine
  elem->rectScores->y = (float)elem->rectScores->defy * scale; //coordonnée y du point d'origine
  elem->rectScores->x2 = (float)elem->rectScores->defx2 * scale; //coordonnée x du point de fin
  elem->rectScores->y2 = (float)elem->rectScores->defy2 * scale; //coordonnée y du point de fin
  elem->rectScores->w = elem->rectScores->x2 - elem->rectScores->x; //largeur
  elem->rectScores->h = elem->rectScores->y2 - elem->rectScores->y; //hauteur
  elem->rectScores->t = epaisseur; //épaisseur des traits

  //rectPieceSuiv
  elem->rectPieceSuiv->x = (float)elem->rectPieceSuiv->defx * scale; //coordonnée x du point d'origine
  elem->rectPieceSuiv->y = (float)elem->rectPieceSuiv->defy * scale; //coordonnée y du point d'origine
  elem->rectPieceSuiv->x2 = (float)elem->rectPieceSuiv->defx2 * scale; //coordonnée x du point de fin
  elem->rectPieceSuiv->y2 = (float)elem->rectPieceSuiv->defy2 * scale; //coordonnée y du point de fin
  elem->rectPieceSuiv->w = elem->rectPieceSuiv->x2 - elem->rectPieceSuiv->x; //largeur
  elem->rectPieceSuiv->h = elem->rectPieceSuiv->y2 - elem->rectPieceSuiv->y; //hauteur
  elem->rectPieceSuiv->t = epaisseur; //épaisseur des traits

  //rectNSL
  elem->rectNSL->x = (float)elem->rectNSL->defx * scale; //coordonnée x du point d'origine
  elem->rectNSL->y = (float)elem->rectNSL->defy * scale; //coordonnée y du point d'origine
  elem->rectNSL->x2 = (float)elem->rectNSL->defx2 * scale; //coordonnée x du point de fin
  elem->rectNSL->y2 = (float)elem->rectNSL->defy2 * scale; //coordonnée y du point de fin
  elem->rectNSL->w = elem->rectNSL->x2 - elem->rectNSL->x; //largeur
  elem->rectNSL->h = elem->rectNSL->y2 - elem->rectNSL->y; //hauteur
  elem->rectNSL->t = epaisseur; //épaisseur des traits

  //rectTemps
  elem->rectTemps->x = (float)elem->rectTemps->defx * scale; //coordonnée x du point d'origine
  elem->rectTemps->y = (float)elem->rectTemps->defy * scale; //coordonnée y du point d'origine
  elem->rectTemps->x2 = (float)elem->rectTemps->defx2 * scale; //coordonnée x du point de fin
  elem->rectTemps->y2 = (float)elem->rectTemps->defy2 * scale; //coordonnée y du point de fin
  elem->rectTemps->w = elem->rectTemps->x2 - elem->rectTemps->x; //largeur
  elem->rectTemps->h = elem->rectTemps->y2 - elem->rectTemps->y; //hauteur
  elem->rectTemps->t = epaisseur; //épaisseur des traits

  //rectAide
  elem->rectAide->x = (float)elem->rectAide->defx * scale; //coordonnée x du point d'origine
  elem->rectAide->y = (float)elem->rectAide->defy * scale; //coordonnée y du point d'origine
  elem->rectAide->x2 = (float)elem->rectAide->defx2 * scale; //coordonnée x du point de fin
  elem->rectAide->y2 = (float)elem->rectAide->defy2 * scale; //coordonnée y du point de fin
  elem->rectAide->w = elem->rectAide->x2 - elem->rectAide->x; //largeur
  elem->rectAide->h = elem->rectAide->y2 - elem->rectAide->y; //hauteur
  elem->rectAide->t = epaisseur; //épaisseur des traits

  //rectPause
  elem->rectPause->x = (float)elem->rectPause->defx * scale; //coordonnée x du point d'origine
  elem->rectPause->y = (float)elem->rectPause->defy * scale; //coordonnée y du point d'origine
  elem->rectPause->x2 = (float)elem->rectPause->defx2 * scale; //coordonnée x du point de fin
  elem->rectPause->y2 = (float)elem->rectPause->defy2 * scale; //coordonnée y du point de fin
  elem->rectPause->w = elem->rectPause->x2 - elem->rectPause->x; //largeur
  elem->rectPause->h = elem->rectPause->y2 - elem->rectPause->y; //hauteur
  elem->rectPause->t = epaisseur; //épaisseur des traits

  //rectOptions
  elem->rectOptions->x = (float)elem->rectOptions->defx * scale; //coordonnée x du point d'origine
  elem->rectOptions->y = (float)elem->rectOptions->defy * scale; //coordonnée y du point d'origine
  elem->rectOptions->x2 = (float)elem->rectOptions->defx2 * scale; //coordonnée x du point de fin
  elem->rectOptions->y2 = (float)elem->rectOptions->defy2 * scale; //coordonnée y du point de fin
  elem->rectOptions->w = elem->rectOptions->x2 - elem->rectOptions->x; //largeur
  elem->rectOptions->h = elem->rectOptions->y2 - elem->rectOptions->y; //hauteur
  elem->rectOptions->t = epaisseur; //épaisseur des traits

  //rectInputOptions
  elem->rectInputOptions->x = (float)elem->rectInputOptions->defx * scale; //coordonnée x du point d'origine
  elem->rectInputOptions->y = (float)elem->rectInputOptions->defy * scale; //coordonnée y du point d'origine
  elem->rectInputOptions->x2 = (float)elem->rectInputOptions->defx2 * scale; //coordonnée x du point de fin
  elem->rectInputOptions->y2 = (float)elem->rectInputOptions->defy2 * scale; //coordonnée y du point de fin
  elem->rectInputOptions->w = elem->rectInputOptions->x2 - elem->rectInputOptions->x; //largeur
  elem->rectInputOptions->h = elem->rectInputOptions->y2 - elem->rectInputOptions->y; //hauteur
  elem->rectInputOptions->t = epaisseur; //épaisseur des traits

  //rectSTLInput
  elem->rectSTLInput->x = (float)elem->rectSTLInput->defx * scale; //coordonnée x du point d'origine
  elem->rectSTLInput->y = (float)elem->rectSTLInput->defy * scale; //coordonnée y du point d'origine
  elem->rectSTLInput->x2 = (float)elem->rectSTLInput->defx2 * scale; //coordonnée x du point de fin
  elem->rectSTLInput->y2 = (float)elem->rectSTLInput->defy2 * scale; //coordonnée y du point de fin
  elem->rectSTLInput->w = elem->rectSTLInput->x2 - elem->rectSTLInput->x; //largeur
  elem->rectSTLInput->h = elem->rectSTLInput->y2 - elem->rectSTLInput->y; //hauteur
  elem->rectSTLInput->t = epaisseur; //épaisseur des traits

  //rectBMenuJouer
  elem->rectBMenuJouer->x = (float)elem->rectBMenuJouer->defx * scale; //coordonnée x du point d'origine
  elem->rectBMenuJouer->y = (float)elem->rectBMenuJouer->defy * scale; //coordonnée y du point d'origine
  elem->rectBMenuJouer->x2 = (float)elem->rectBMenuJouer->defx2 * scale; //coordonnée x du point de fin
  elem->rectBMenuJouer->y2 = (float)elem->rectBMenuJouer->defy2 * scale; //coordonnée y du point de fin
  elem->rectBMenuJouer->w = elem->rectBMenuJouer->x2 - elem->rectBMenuJouer->x; //largeur
  elem->rectBMenuJouer->h = elem->rectBMenuJouer->y2 - elem->rectBMenuJouer->y; //hauteur
  elem->rectBMenuJouer->t = epaisseur; //épaisseur des traits

  //rectBMenuNiveau
  elem->rectBMenuNiveau->x = (float)elem->rectBMenuNiveau->defx * scale; //coordonnée x du point d'origine
  elem->rectBMenuNiveau->y = (float)elem->rectBMenuNiveau->defy * scale; //coordonnée y du point d'origine
  elem->rectBMenuNiveau->x2 = (float)elem->rectBMenuNiveau->defx2 * scale; //coordonnée x du point de fin
  elem->rectBMenuNiveau->y2 = (float)elem->rectBMenuNiveau->defy2 * scale; //coordonnée y du point de fin
  elem->rectBMenuNiveau->w = elem->rectBMenuNiveau->x2 - elem->rectBMenuNiveau->x; //largeur
  elem->rectBMenuNiveau->h = elem->rectBMenuNiveau->y2 - elem->rectBMenuNiveau->y; //hauteur
  elem->rectBMenuNiveau->t = epaisseur; //épaisseur des traits

  //rectBMenuMode
  elem->rectBMenuMode->x = (float)elem->rectBMenuMode->defx * scale; //coordonnée x du point d'origine
  elem->rectBMenuMode->y = (float)elem->rectBMenuMode->defy * scale; //coordonnée y du point d'origine
  elem->rectBMenuMode->x2 = (float)elem->rectBMenuMode->defx2 * scale; //coordonnée x du point de fin
  elem->rectBMenuMode->y2 = (float)elem->rectBMenuMode->defy2 * scale; //coordonnée y du point de fin
  elem->rectBMenuMode->w = elem->rectBMenuMode->x2 - elem->rectBMenuMode->x; //largeur
  elem->rectBMenuMode->h = elem->rectBMenuMode->y2 - elem->rectBMenuMode->y; //hauteur
  elem->rectBMenuMode->t = epaisseur; //épaisseur des traits

  //rectBMenuAide
  elem->rectBMenuAide->x = (float)elem->rectBMenuAide->defx * scale; //coordonnée x du point d'origine
  elem->rectBMenuAide->y = (float)elem->rectBMenuAide->defy * scale; //coordonnée y du point d'origine
  elem->rectBMenuAide->x2 = (float)elem->rectBMenuAide->defx2 * scale; //coordonnée x du point de fin
  elem->rectBMenuAide->y2 = (float)elem->rectBMenuAide->defy2 * scale; //coordonnée y du point de fin
  elem->rectBMenuAide->w = elem->rectBMenuAide->x2 - elem->rectBMenuAide->x; //largeur
  elem->rectBMenuAide->h = elem->rectBMenuAide->y2 - elem->rectBMenuAide->y; //hauteur
  elem->rectBMenuAide->t = epaisseur; //épaisseur des traits

  //rectBMenuOptions
  elem->rectBMenuOptions->x = (float)elem->rectBMenuOptions->defx * scale; //coordonnée x du point d'origine
  elem->rectBMenuOptions->y = (float)elem->rectBMenuOptions->defy * scale; //coordonnée y du point d'origine
  elem->rectBMenuOptions->x2 = (float)elem->rectBMenuOptions->defx2 * scale; //coordonnée x du point de fin
  elem->rectBMenuOptions->y2 = (float)elem->rectBMenuOptions->defy2 * scale; //coordonnée y du point de fin
  elem->rectBMenuOptions->w = elem->rectBMenuOptions->x2 - elem->rectBMenuOptions->x; //largeur
  elem->rectBMenuOptions->h = elem->rectBMenuOptions->y2 - elem->rectBMenuOptions->y; //hauteur
  elem->rectBMenuOptions->t = epaisseur; //épaisseur des traits

  //rectBAideOk
  elem->rectBAideOk->x = (float)elem->rectBAideOk->defx * scale; //coordonnée x du point d'origine
  elem->rectBAideOk->y = (float)elem->rectBAideOk->defy * scale; //coordonnée y du point d'origine
  elem->rectBAideOk->x2 = (float)elem->rectBAideOk->defx2 * scale; //coordonnée x du point de fin
  elem->rectBAideOk->y2 = (float)elem->rectBAideOk->defy2 * scale; //coordonnée y du point de fin
  elem->rectBAideOk->w = elem->rectBAideOk->x2 - elem->rectBAideOk->x; //largeur
  elem->rectBAideOk->h = elem->rectBAideOk->y2 - elem->rectBAideOk->y; //hauteur
  elem->rectBAideOk->t = epaisseur; //épaisseur des traits

  //rectBPauseReprendre
  elem->rectBPauseReprendre->x = (float)elem->rectBPauseReprendre->defx * scale; //coordonnée x du point d'origine
  elem->rectBPauseReprendre->y = (float)elem->rectBPauseReprendre->defy * scale; //coordonnée y du point d'origine
  elem->rectBPauseReprendre->x2 = (float)elem->rectBPauseReprendre->defx2 * scale; //coordonnée x du point de fin
  elem->rectBPauseReprendre->y2 = (float)elem->rectBPauseReprendre->defy2 * scale; //coordonnée y du point de fin
  elem->rectBPauseReprendre->w = elem->rectBPauseReprendre->x2 - elem->rectBPauseReprendre->x; //largeur
  elem->rectBPauseReprendre->h = elem->rectBPauseReprendre->y2 - elem->rectBPauseReprendre->y; //hauteur
  elem->rectBPauseReprendre->t = epaisseur; //épaisseur des traits

  //rectBPauseAide
  elem->rectBPauseAide->x = (float)elem->rectBPauseAide->defx * scale; //coordonnée x du point d'origine
  elem->rectBPauseAide->y = (float)elem->rectBPauseAide->defy * scale; //coordonnée y du point d'origine
  elem->rectBPauseAide->x2 = (float)elem->rectBPauseAide->defx2 * scale; //coordonnée x du point de fin
  elem->rectBPauseAide->y2 = (float)elem->rectBPauseAide->defy2 * scale; //coordonnée y du point de fin
  elem->rectBPauseAide->w = elem->rectBPauseAide->x2 - elem->rectBPauseAide->x; //largeur
  elem->rectBPauseAide->h = elem->rectBPauseAide->y2 - elem->rectBPauseAide->y; //hauteur
  elem->rectBPauseAide->t = epaisseur; //épaisseur des traits

  //rectBPauseOptions
  elem->rectBPauseOptions->x = (float)elem->rectBPauseOptions->defx * scale; //coordonnée x du point d'origine
  elem->rectBPauseOptions->y = (float)elem->rectBPauseOptions->defy * scale; //coordonnée y du point d'origine
  elem->rectBPauseOptions->x2 = (float)elem->rectBPauseOptions->defx2 * scale; //coordonnée x du point de fin
  elem->rectBPauseOptions->y2 = (float)elem->rectBPauseOptions->defy2 * scale; //coordonnée y du point de fin
  elem->rectBPauseOptions->w = elem->rectBPauseOptions->x2 - elem->rectBPauseOptions->x; //largeur
  elem->rectBPauseOptions->h = elem->rectBPauseOptions->y2 - elem->rectBPauseOptions->y; //hauteur
  elem->rectBPauseOptions->t = epaisseur; //épaisseur des traits

  //rectBPauseQuitter
  elem->rectBPauseQuitter->x = (float)elem->rectBPauseQuitter->defx * scale; //coordonnée x du point d'origine
  elem->rectBPauseQuitter->y = (float)elem->rectBPauseQuitter->defy * scale; //coordonnée y du point d'origine
  elem->rectBPauseQuitter->x2 = (float)elem->rectBPauseQuitter->defx2 * scale; //coordonnée x du point de fin
  elem->rectBPauseQuitter->y2 = (float)elem->rectBPauseQuitter->defy2 * scale; //coordonnée y du point de fin
  elem->rectBPauseQuitter->w = elem->rectBPauseQuitter->x2 - elem->rectBPauseQuitter->x; //largeur
  elem->rectBPauseQuitter->h = elem->rectBPauseQuitter->y2 - elem->rectBPauseQuitter->y; //hauteur
  elem->rectBPauseQuitter->t = epaisseur; //épaisseur des traits

  //rectBOptionsVolThemeM
  elem->rectBOptionsVolThemeM->x = (float)elem->rectBOptionsVolThemeM->defx * scale; //coordonnée x du point d'origine
  elem->rectBOptionsVolThemeM->y = (float)elem->rectBOptionsVolThemeM->defy * scale; //coordonnée y du point d'origine
  elem->rectBOptionsVolThemeM->x2 = (float)elem->rectBOptionsVolThemeM->defx2 * scale; //coordonnée x du point de fin
  elem->rectBOptionsVolThemeM->y2 = (float)elem->rectBOptionsVolThemeM->defy2 * scale; //coordonnée y du point de fin
  elem->rectBOptionsVolThemeM->w = elem->rectBOptionsVolThemeM->x2 - elem->rectBOptionsVolThemeM->x; //largeur
  elem->rectBOptionsVolThemeM->h = elem->rectBOptionsVolThemeM->y2 - elem->rectBOptionsVolThemeM->y; //hauteur
  elem->rectBOptionsVolThemeM->t = epaisseurOptions; //épaisseur des traits

  //rectBOptionsVolThemeP
  elem->rectBOptionsVolThemeP->x = (float)elem->rectBOptionsVolThemeP->defx * scale; //coordonnée x du point d'origine
  elem->rectBOptionsVolThemeP->y = (float)elem->rectBOptionsVolThemeP->defy * scale; //coordonnée y du point d'origine
  elem->rectBOptionsVolThemeP->x2 = (float)elem->rectBOptionsVolThemeP->defx2 * scale; //coordonnée x du point de fin
  elem->rectBOptionsVolThemeP->y2 = (float)elem->rectBOptionsVolThemeP->defy2 * scale; //coordonnée y du point de fin
  elem->rectBOptionsVolThemeP->w = elem->rectBOptionsVolThemeP->x2 - elem->rectBOptionsVolThemeP->x; //largeur
  elem->rectBOptionsVolThemeP->h = elem->rectBOptionsVolThemeP->y2 - elem->rectBOptionsVolThemeP->y; //hauteur
  elem->rectBOptionsVolThemeP->t = epaisseurOptions; //épaisseur des traits

  //rectBOptionsVolFXM
  elem->rectBOptionsVolFXM->x = (float)elem->rectBOptionsVolFXM->defx * scale; //coordonnée x du point d'origine
  elem->rectBOptionsVolFXM->y = (float)elem->rectBOptionsVolFXM->defy * scale; //coordonnée y du point d'origine
  elem->rectBOptionsVolFXM->x2 = (float)elem->rectBOptionsVolFXM->defx2 * scale; //coordonnée x du point de fin
  elem->rectBOptionsVolFXM->y2 = (float)elem->rectBOptionsVolFXM->defy2 * scale; //coordonnée y du point de fin
  elem->rectBOptionsVolFXM->w = elem->rectBOptionsVolFXM->x2 - elem->rectBOptionsVolFXM->x; //largeur
  elem->rectBOptionsVolFXM->h = elem->rectBOptionsVolFXM->y2 - elem->rectBOptionsVolFXM->y; //hauteur
  elem->rectBOptionsVolFXM->t = epaisseurOptions; //épaisseur des traits

  //rectBOptionsVolFXP
  elem->rectBOptionsVolFXP->x = (float)elem->rectBOptionsVolFXP->defx * scale; //coordonnée x du point d'origine
  elem->rectBOptionsVolFXP->y = (float)elem->rectBOptionsVolFXP->defy * scale; //coordonnée y du point d'origine
  elem->rectBOptionsVolFXP->x2 = (float)elem->rectBOptionsVolFXP->defx2 * scale; //coordonnée x du point de fin
  elem->rectBOptionsVolFXP->y2 = (float)elem->rectBOptionsVolFXP->defy2 * scale; //coordonnée y du point de fin
  elem->rectBOptionsVolFXP->w = elem->rectBOptionsVolFXP->x2 - elem->rectBOptionsVolFXP->x; //largeur
  elem->rectBOptionsVolFXP->h = elem->rectBOptionsVolFXP->y2 - elem->rectBOptionsVolFXP->y; //hauteur
  elem->rectBOptionsVolFXP->t = epaisseurOptions; //épaisseur des traits

  //rectBOptionsReset
  elem->rectBOptionsReset->x = (float)elem->rectBOptionsReset->defx * scale; //coordonnée x du point d'origine
  elem->rectBOptionsReset->y = (float)elem->rectBOptionsReset->defy * scale; //coordonnée y du point d'origine
  elem->rectBOptionsReset->x2 = (float)elem->rectBOptionsReset->defx2 * scale; //coordonnée x du point de fin
  elem->rectBOptionsReset->y2 = (float)elem->rectBOptionsReset->defy2 * scale; //coordonnée y du point de fin
  elem->rectBOptionsReset->w = elem->rectBOptionsReset->x2 - elem->rectBOptionsReset->x; //largeur
  elem->rectBOptionsReset->h = elem->rectBOptionsReset->y2 - elem->rectBOptionsReset->y; //hauteur
  elem->rectBOptionsReset->t = epaisseur; //épaisseur des traits

  //rectBOptionsOk
  elem->rectBOptionsOk->x = (float)elem->rectBOptionsOk->defx * scale; //coordonnée x du point d'origine
  elem->rectBOptionsOk->y = (float)elem->rectBOptionsOk->defy * scale; //coordonnée y du point d'origine
  elem->rectBOptionsOk->x2 = (float)elem->rectBOptionsOk->defx2 * scale; //coordonnée x du point de fin
  elem->rectBOptionsOk->y2 = (float)elem->rectBOptionsOk->defy2 * scale; //coordonnée y du point de fin
  elem->rectBOptionsOk->w = elem->rectBOptionsOk->x2 - elem->rectBOptionsOk->x; //largeur
  elem->rectBOptionsOk->h = elem->rectBOptionsOk->y2 - elem->rectBOptionsOk->y; //hauteur
  elem->rectBOptionsOk->t = epaisseur; //épaisseur des traits

  //rectBSTLOk
  elem->rectBSTLOk->x = (float)elem->rectBSTLOk->defx * scale; //coordonnée x du point d'origine
  elem->rectBSTLOk->y = (float)elem->rectBSTLOk->defy * scale; //coordonnée y du point d'origine
  elem->rectBSTLOk->x2 = (float)elem->rectBSTLOk->defx2 * scale; //coordonnée x du point de fin
  elem->rectBSTLOk->y2 = (float)elem->rectBSTLOk->defy2 * scale; //coordonnée y du point de fin
  elem->rectBSTLOk->w = elem->rectBSTLOk->x2 - elem->rectBSTLOk->x; //largeur
  elem->rectBSTLOk->h = elem->rectBSTLOk->y2 - elem->rectBSTLOk->y; //hauteur
  elem->rectBSTLOk->t = epaisseur; //épaisseur des traits

  //rectIOptionsLeft
  elem->rectIOptionsLeft->x = (float)elem->rectIOptionsLeft->defx * scale; //coordonnée x du point d'origine
  elem->rectIOptionsLeft->y = (float)elem->rectIOptionsLeft->defy * scale; //coordonnée y du point d'origine
  elem->rectIOptionsLeft->x2 = (float)elem->rectIOptionsLeft->defx2 * scale; //coordonnée x du point de fin
  elem->rectIOptionsLeft->y2 = (float)elem->rectIOptionsLeft->defy2 * scale; //coordonnée y du point de fin
  elem->rectIOptionsLeft->w = elem->rectIOptionsLeft->x2 - elem->rectIOptionsLeft->x; //largeur
  elem->rectIOptionsLeft->h = elem->rectIOptionsLeft->y2 - elem->rectIOptionsLeft->y; //hauteur
  elem->rectIOptionsLeft->t = epaisseurOptions; //épaisseur des traits

  //rectIOptionsRight
  elem->rectIOptionsRight->x = (float)elem->rectIOptionsRight->defx * scale; //coordonnée x du point d'origine
  elem->rectIOptionsRight->y = (float)elem->rectIOptionsRight->defy * scale; //coordonnée y du point d'origine
  elem->rectIOptionsRight->x2 = (float)elem->rectIOptionsRight->defx2 * scale; //coordonnée x du point de fin
  elem->rectIOptionsRight->y2 = (float)elem->rectIOptionsRight->defy2 * scale; //coordonnée y du point de fin
  elem->rectIOptionsRight->w = elem->rectIOptionsRight->x2 - elem->rectIOptionsRight->x; //largeur
  elem->rectIOptionsRight->h = elem->rectIOptionsRight->y2 - elem->rectIOptionsRight->y; //hauteur
  elem->rectIOptionsRight->t = epaisseurOptions; //épaisseur des traits

  //rectIOptionsRotatel
  elem->rectIOptionsRotatel->x = (float)elem->rectIOptionsRotatel->defx * scale; //coordonnée x du point d'origine
  elem->rectIOptionsRotatel->y = (float)elem->rectIOptionsRotatel->defy * scale; //coordonnée y du point d'origine
  elem->rectIOptionsRotatel->x2 = (float)elem->rectIOptionsRotatel->defx2 * scale; //coordonnée x du point de fin
  elem->rectIOptionsRotatel->y2 = (float)elem->rectIOptionsRotatel->defy2 * scale; //coordonnée y du point de fin
  elem->rectIOptionsRotatel->w = elem->rectIOptionsRotatel->x2 - elem->rectIOptionsRotatel->x; //largeur
  elem->rectIOptionsRotatel->h = elem->rectIOptionsRotatel->y2 - elem->rectIOptionsRotatel->y; //hauteur
  elem->rectIOptionsRotatel->t = epaisseurOptions; //épaisseur des traits

  //rectIOptionsRotater
  elem->rectIOptionsRotater->x = (float)elem->rectIOptionsRotater->defx * scale; //coordonnée x du point d'origine
  elem->rectIOptionsRotater->y = (float)elem->rectIOptionsRotater->defy * scale; //coordonnée y du point d'origine
  elem->rectIOptionsRotater->x2 = (float)elem->rectIOptionsRotater->defx2 * scale; //coordonnée x du point de fin
  elem->rectIOptionsRotater->y2 = (float)elem->rectIOptionsRotater->defy2 * scale; //coordonnée y du point de fin
  elem->rectIOptionsRotater->w = elem->rectIOptionsRotater->x2 - elem->rectIOptionsRotater->x; //largeur
  elem->rectIOptionsRotater->h = elem->rectIOptionsRotater->y2 - elem->rectIOptionsRotater->y; //hauteur
  elem->rectIOptionsRotater->t = epaisseurOptions; //épaisseur des traits

  //rectIOptionsHardd
  elem->rectIOptionsHardd->x = (float)elem->rectIOptionsHardd->defx * scale; //coordonnée x du point d'origine
  elem->rectIOptionsHardd->y = (float)elem->rectIOptionsHardd->defy * scale; //coordonnée y du point d'origine
  elem->rectIOptionsHardd->x2 = (float)elem->rectIOptionsHardd->defx2 * scale; //coordonnée x du point de fin
  elem->rectIOptionsHardd->y2 = (float)elem->rectIOptionsHardd->defy2 * scale; //coordonnée y du point de fin
  elem->rectIOptionsHardd->w = elem->rectIOptionsHardd->x2 - elem->rectIOptionsHardd->x; //largeur
  elem->rectIOptionsHardd->h = elem->rectIOptionsHardd->y2 - elem->rectIOptionsHardd->y; //hauteur
  elem->rectIOptionsHardd->t = epaisseurOptions; //épaisseur des traits

  //rectIOptionsSoftd
  elem->rectIOptionsSoftd->x = (float)elem->rectIOptionsSoftd->defx * scale; //coordonnée x du point d'origine
  elem->rectIOptionsSoftd->y = (float)elem->rectIOptionsSoftd->defy * scale; //coordonnée y du point d'origine
  elem->rectIOptionsSoftd->x2 = (float)elem->rectIOptionsSoftd->defx2 * scale; //coordonnée x du point de fin
  elem->rectIOptionsSoftd->y2 = (float)elem->rectIOptionsSoftd->defy2 * scale; //coordonnée y du point de fin
  elem->rectIOptionsSoftd->w = elem->rectIOptionsSoftd->x2 - elem->rectIOptionsSoftd->x; //largeur
  elem->rectIOptionsSoftd->h = elem->rectIOptionsSoftd->y2 - elem->rectIOptionsSoftd->y; //hauteur
  elem->rectIOptionsSoftd->t = epaisseurOptions; //épaisseur des traits

  //rectIOptionsPause
  elem->rectIOptionsPause->x = (float)elem->rectIOptionsPause->defx * scale; //coordonnée x du point d'origine
  elem->rectIOptionsPause->y = (float)elem->rectIOptionsPause->defy * scale; //coordonnée y du point d'origine
  elem->rectIOptionsPause->x2 = (float)elem->rectIOptionsPause->defx2 * scale; //coordonnée x du point de fin
  elem->rectIOptionsPause->y2 = (float)elem->rectIOptionsPause->defy2 * scale; //coordonnée y du point de fin
  elem->rectIOptionsPause->w = elem->rectIOptionsPause->x2 - elem->rectIOptionsPause->x; //largeur
  elem->rectIOptionsPause->h = elem->rectIOptionsPause->y2 - elem->rectIOptionsPause->y; //hauteur
  elem->rectIOptionsPause->t = epaisseurOptions; //épaisseur des traits

  //rectIOptionsGhost
  elem->rectIOptionsGhost->x = (float)elem->rectIOptionsGhost->defx * scale; //coordonnée x du point d'origine
  elem->rectIOptionsGhost->y = (float)elem->rectIOptionsGhost->defy * scale; //coordonnée y du point d'origine
  elem->rectIOptionsGhost->x2 = (float)elem->rectIOptionsGhost->defx2 * scale; //coordonnée x du point de fin
  elem->rectIOptionsGhost->y2 = (float)elem->rectIOptionsGhost->defy2 * scale; //coordonnée y du point de fin
  elem->rectIOptionsGhost->w = elem->rectIOptionsGhost->x2 - elem->rectIOptionsGhost->x; //largeur
  elem->rectIOptionsGhost->h = elem->rectIOptionsGhost->y2 - elem->rectIOptionsGhost->y; //hauteur
  elem->rectIOptionsGhost->t = epaisseurOptions; //épaisseur des traits

  //rectIOptionsChange
  elem->rectIOptionsChange->x = (float)elem->rectIOptionsChange->defx * scale; //coordonnée x du point d'origine
  elem->rectIOptionsChange->y = (float)elem->rectIOptionsChange->defy * scale; //coordonnée y du point d'origine
  elem->rectIOptionsChange->x2 = (float)elem->rectIOptionsChange->defx2 * scale; //coordonnée x du point de fin
  elem->rectIOptionsChange->y2 = (float)elem->rectIOptionsChange->defy2 * scale; //coordonnée y du point de fin
  elem->rectIOptionsChange->w = elem->rectIOptionsChange->x2 - elem->rectIOptionsChange->x; //largeur
  elem->rectIOptionsChange->h = elem->rectIOptionsChange->y2 - elem->rectIOptionsChange->y; //hauteur
  elem->rectIOptionsChange->t = epaisseurOptions; //épaisseur des traits

  //rectIInputOptionsTouche1
  elem->rectIInputOptionsTouche1->x = (float)elem->rectIInputOptionsTouche1->defx * scale; //coordonnée x du point d'origine
  elem->rectIInputOptionsTouche1->y = (float)elem->rectIInputOptionsTouche1->defy * scale; //coordonnée y du point d'origine
  elem->rectIInputOptionsTouche1->x2 = (float)elem->rectIInputOptionsTouche1->defx2 * scale; //coordonnée x du point de fin
  elem->rectIInputOptionsTouche1->y2 = (float)elem->rectIInputOptionsTouche1->defy2 * scale; //coordonnée y du point de fin
  elem->rectIInputOptionsTouche1->w = elem->rectIInputOptionsTouche1->x2 - elem->rectIInputOptionsTouche1->x; //largeur
  elem->rectIInputOptionsTouche1->h = elem->rectIInputOptionsTouche1->y2 - elem->rectIInputOptionsTouche1->y; //hauteur
  elem->rectIInputOptionsTouche1->t = epaisseurOptions; //épaisseur des traits

  //rectIInputOptionsTouche2
  elem->rectIInputOptionsTouche2->x = (float)elem->rectIInputOptionsTouche2->defx * scale; //coordonnée x du point d'origine
  elem->rectIInputOptionsTouche2->y = (float)elem->rectIInputOptionsTouche2->defy * scale; //coordonnée y du point d'origine
  elem->rectIInputOptionsTouche2->x2 = (float)elem->rectIInputOptionsTouche2->defx2 * scale; //coordonnée x du point de fin
  elem->rectIInputOptionsTouche2->y2 = (float)elem->rectIInputOptionsTouche2->defy2 * scale; //coordonnée y du point de fin
  elem->rectIInputOptionsTouche2->w = elem->rectIInputOptionsTouche2->x2 - elem->rectIInputOptionsTouche2->x; //largeur
  elem->rectIInputOptionsTouche2->h = elem->rectIInputOptionsTouche2->y2 - elem->rectIInputOptionsTouche2->y; //hauteur
  elem->rectIInputOptionsTouche2->t = epaisseurOptions; //épaisseur des traits

  //rectIInputOptionsTouche3
  elem->rectIInputOptionsTouche3->x = (float)elem->rectIInputOptionsTouche3->defx * scale; //coordonnée x du point d'origine
  elem->rectIInputOptionsTouche3->y = (float)elem->rectIInputOptionsTouche3->defy * scale; //coordonnée y du point d'origine
  elem->rectIInputOptionsTouche3->x2 = (float)elem->rectIInputOptionsTouche3->defx2 * scale; //coordonnée x du point de fin
  elem->rectIInputOptionsTouche3->y2 = (float)elem->rectIInputOptionsTouche3->defy2 * scale; //coordonnée y du point de fin
  elem->rectIInputOptionsTouche3->w = elem->rectIInputOptionsTouche3->x2 - elem->rectIInputOptionsTouche3->x; //largeur
  elem->rectIInputOptionsTouche3->h = elem->rectIInputOptionsTouche3->y2 - elem->rectIInputOptionsTouche3->y; //hauteur
  elem->rectIInputOptionsTouche3->t = epaisseurOptions; //épaisseur des traits

  //rectBInputOptionsOk
  elem->rectBInputOptionsOk->x = (float)elem->rectBInputOptionsOk->defx * scale; //coordonnée x du point d'origine
  elem->rectBInputOptionsOk->y = (float)elem->rectBInputOptionsOk->defy * scale; //coordonnée y du point d'origine
  elem->rectBInputOptionsOk->x2 = (float)elem->rectBInputOptionsOk->defx2 * scale; //coordonnée x du point de fin
  elem->rectBInputOptionsOk->y2 = (float)elem->rectBInputOptionsOk->defy2 * scale; //coordonnée y du point de fin
  elem->rectBInputOptionsOk->w = elem->rectBInputOptionsOk->x2 - elem->rectBInputOptionsOk->x; //largeur
  elem->rectBInputOptionsOk->h = elem->rectBInputOptionsOk->y2 - elem->rectBInputOptionsOk->y; //hauteur
  elem->rectBInputOptionsOk->t = epaisseur; //épaisseur des traits

  //rectISTLInput
  elem->rectISTLInput->x = (float)elem->rectISTLInput->defx * scale; //coordonnée x du point d'origine
  elem->rectISTLInput->y = (float)elem->rectISTLInput->defy * scale; //coordonnée y du point d'origine
  elem->rectISTLInput->x2 = (float)elem->rectISTLInput->defx2 * scale; //coordonnée x du point de fin
  elem->rectISTLInput->y2 = (float)elem->rectISTLInput->defy2 * scale; //coordonnée y du point de fin
  elem->rectISTLInput->w = elem->rectISTLInput->x2 - elem->rectISTLInput->x; //largeur
  elem->rectISTLInput->h = elem->rectISTLInput->y2 - elem->rectISTLInput->y; //hauteur
  elem->rectISTLInput->t = epaisseur; //épaisseur des traits
}
