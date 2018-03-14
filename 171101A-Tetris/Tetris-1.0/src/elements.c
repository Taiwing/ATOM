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
  elem->rectBOptionsResMin = malloc(sizeof(coord));
  elem->rectBOptionsResMax = malloc(sizeof(coord));
  elem->rectBOptionsAppliquer = malloc(sizeof(coord));
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
  elem->rectIOptionsResW = malloc(sizeof(coord));
  elem->rectIOptionsResH = malloc(sizeof(coord));
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
  elem->rectBOptionsVolThemeM->defy = 328; //coordonnée y du point d'origine
  elem->rectBOptionsVolThemeM->defx2 = 281; //coordonnée x du point de fin
  elem->rectBOptionsVolThemeM->defy2 = 348; //coordonnée y du point de fin
  elem->rectBOptionsVolThemeM->defw = elem->rectBOptionsVolThemeM->defx2 - elem->rectBOptionsVolThemeM->defx; //largeur
  elem->rectBOptionsVolThemeM->defh = elem->rectBOptionsVolThemeM->defy2 - elem->rectBOptionsVolThemeM->defy; //hauteur
  elem->rectBOptionsVolThemeM->deft = epaisseurOptions; //épaisseur des traits

  //rectBOptionsVolThemeP
  elem->rectBOptionsVolThemeP->defx = 352; //coordonnée x du point d'origine
  elem->rectBOptionsVolThemeP->defy = 328; //coordonnée y du point d'origine
  elem->rectBOptionsVolThemeP->defx2 = 392; //coordonnée x du point de fin
  elem->rectBOptionsVolThemeP->defy2 = 348; //coordonnée y du point de fin
  elem->rectBOptionsVolThemeP->defw = elem->rectBOptionsVolThemeP->defx2 - elem->rectBOptionsVolThemeP->defx; //largeur
  elem->rectBOptionsVolThemeP->defh = elem->rectBOptionsVolThemeP->defy2 - elem->rectBOptionsVolThemeP->defy; //hauteur
  elem->rectBOptionsVolThemeP->deft = epaisseurOptions; //épaisseur des traits

  //rectBOptionsVolFXM
  elem->rectBOptionsVolFXM->defx = 241; //coordonnée x du point d'origine
  elem->rectBOptionsVolFXM->defy = 353; //coordonnée y du point d'origine
  elem->rectBOptionsVolFXM->defx2 = 281; //coordonnée x du point de fin
  elem->rectBOptionsVolFXM->defy2 = 373; //coordonnée y du point de fin
  elem->rectBOptionsVolFXM->defw = elem->rectBOptionsVolFXM->defx2 - elem->rectBOptionsVolFXM->defx; //largeur
  elem->rectBOptionsVolFXM->defh = elem->rectBOptionsVolFXM->defy2 - elem->rectBOptionsVolFXM->defy; //hauteur
  elem->rectBOptionsVolFXM->deft = epaisseurOptions; //épaisseur des traits

  //rectBOptionsVolFXP
  elem->rectBOptionsVolFXP->defx = 352; //coordonnée x du point d'origine
  elem->rectBOptionsVolFXP->defy = 353; //coordonnée y du point d'origine
  elem->rectBOptionsVolFXP->defx2 = 392; //coordonnée x du point de fin
  elem->rectBOptionsVolFXP->defy2 = 373; //coordonnée y du point de fin
  elem->rectBOptionsVolFXP->defw = elem->rectBOptionsVolFXP->defx2 - elem->rectBOptionsVolFXP->defx; //largeur
  elem->rectBOptionsVolFXP->defh = elem->rectBOptionsVolFXP->defy2 - elem->rectBOptionsVolFXP->defy; //hauteur
  elem->rectBOptionsVolFXP->deft = epaisseurOptions; //épaisseur des traits

  //rectBOptionsResMin
  elem->rectBOptionsResMin->defx = 59; //coordonnée x du point d'origine
  elem->rectBOptionsResMin->defy = 403; //coordonnée y du point d'origine
  elem->rectBOptionsResMin->defx2 = 99; //coordonnée x du point de fin
  elem->rectBOptionsResMin->defy2 = 423; //coordonnée y du point de fin
  elem->rectBOptionsResMin->defw = elem->rectBOptionsResMin->defx2 - elem->rectBOptionsResMin->defx; //largeur
  elem->rectBOptionsResMin->defh = elem->rectBOptionsResMin->defy2 - elem->rectBOptionsResMin->defy; //hauteur
  elem->rectBOptionsResMin->deft = epaisseurOptions; //épaisseur des traits

  //rectBOptionsResMax
  elem->rectBOptionsResMax->defx = 352; //coordonnée x du point d'origine
  elem->rectBOptionsResMax->defy = 403; //coordonnée y du point d'origine
  elem->rectBOptionsResMax->defx2 = 392; //coordonnée x du point de fin
  elem->rectBOptionsResMax->defy2 = 423; //coordonnée y du point de fin
  elem->rectBOptionsResMax->defw = elem->rectBOptionsResMax->defx2 - elem->rectBOptionsResMax->defx; //largeur
  elem->rectBOptionsResMax->defh = elem->rectBOptionsResMax->defy2 - elem->rectBOptionsResMax->defy; //hauteur
  elem->rectBOptionsResMax->deft = epaisseurOptions; //épaisseur des traits

  //rectBOptionsAppliquer
  elem->rectBOptionsAppliquer->defx = 180; //coordonnée x du point d'origine
  elem->rectBOptionsAppliquer->defy = 428; //coordonnée y du point d'origine
  elem->rectBOptionsAppliquer->defx2 = 271; //coordonnée x du point de fin
  elem->rectBOptionsAppliquer->defy2 = 448; //coordonnée y du point de fin
  elem->rectBOptionsAppliquer->defw = elem->rectBOptionsAppliquer->defx2 - elem->rectBOptionsAppliquer->defx; //largeur
  elem->rectBOptionsAppliquer->defh = elem->rectBOptionsAppliquer->defy2 - elem->rectBOptionsAppliquer->defy; //largeur
  elem->rectBOptionsAppliquer->deft = epaisseurOptions; //épaisseur des traits

  //rectBOptionsReset
  elem->rectBOptionsReset->defx = 134; //coordonnée x du point d'origine
  elem->rectBOptionsReset->defy = 463; //coordonnée y du point d'origine
  elem->rectBOptionsReset->defx2 = 317; //coordonnée x du point de fin
  elem->rectBOptionsReset->defy2 = 513; //coordonnée y du point de fin
  elem->rectBOptionsReset->defw = elem->rectBOptionsReset->defx2 - elem->rectBOptionsReset->defx; //largeur
  elem->rectBOptionsReset->defh = elem->rectBOptionsReset->defy2 - elem->rectBOptionsReset->defy; //hauteur
  elem->rectBOptionsReset->deft = epaisseur; //épaisseur des traits

  //rectBOptionsOk
  elem->rectBOptionsOk->defx = 194; //coordonnée x du point d'origine
  elem->rectBOptionsOk->defy = 528; //coordonnée y du point d'origine
  elem->rectBOptionsOk->defx2 = 257; //coordonnée x du point de fin
  elem->rectBOptionsOk->defy2 = 578; //coordonnée y du point de fin
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

  //rectIOptionsResW
  elem->rectIOptionsResW->defx = 109; //coordonnée x du point d'origine
  elem->rectIOptionsResW->defy = 403; //coordonnée y du point d'origine
  elem->rectIOptionsResW->defx2 = 220; //coordonnée x du point de fin
  elem->rectIOptionsResW->defy2 = 423; //coordonnée y du point de fin
  elem->rectIOptionsResW->defw = elem->rectIOptionsResW->defx2 - elem->rectIOptionsResW->defx; //largeur
  elem->rectIOptionsResW->defh = elem->rectIOptionsResW->defy2 - elem->rectIOptionsResW->defy; //hauteur
  elem->rectIOptionsResW->deft = epaisseurOptions; //épaisseur des traits

  //rectIOptionsResH
  elem->rectIOptionsResH->defx = 230; //coordonnée x du point d'origine
  elem->rectIOptionsResH->defy = 403; //coordonnée y du point d'origine
  elem->rectIOptionsResH->defx2 = 342; //coordonnée x du point de fin
  elem->rectIOptionsResH->defy2 = 423; //coordonnée y du point de fin
  elem->rectIOptionsResH->defw = elem->rectIOptionsResH->defx2 - elem->rectIOptionsResH->defx; //largeur
  elem->rectIOptionsResH->defh = elem->rectIOptionsResH->defy2 - elem->rectIOptionsResH->defy; //hauteur
  elem->rectIOptionsResH->deft = epaisseurOptions; //épaisseur des traits

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
  coord *rect = NULL; //pointeur dont on va se servir pour parcourir le pack d'éléments
  for(int i = 0; i < 48; i++)
  {
    switch(i)
    {
      case 0:
        rect = elem->rectPrincipal;
        break;
      case 1:
        rect = elem->rectScores;
        break;
      case 2:
        rect = elem->rectPieceSuiv;
        break;
      case 3:
        rect = elem->rectNSL;
        break;
      case 4:
        rect = elem->rectTemps;
        break;
      case 5:
        rect = elem->rectAide;
        break;
      case 6:
        rect = elem->rectPause;
        break;
      case 7:
        rect = elem->rectOptions;
        break;
      case 8:
        rect = elem->rectInputOptions;
        break;
      case 9:
        rect = elem->rectSTLInput;
        break;
      case 10:
        rect = elem->rectPrincipal;
        break;
      case 11:
        rect = elem->rectBMenuJouer;
        break;
      case 12:
        rect = elem->rectBMenuNiveau;
        break;
      case 13:
        rect = elem->rectBMenuMode;
        break;
      case 14:
        rect = elem->rectBMenuAide;
        break;
      case 15:
        rect = elem->rectBMenuOptions;
        break;
      case 16:
        rect = elem->rectBAideOk;
        break;
      case 17:
        rect = elem->rectBPauseReprendre;
        break;
      case 18:
        rect = elem->rectBPauseAide;
        break;
      case 19:
        rect = elem->rectBPauseOptions;
        break;
      case 20:
        rect = elem->rectBPauseQuitter;
        break;
      case 21:
        rect = elem->rectBOptionsVolThemeM;
        break;
      case 22:
        rect = elem->rectBOptionsVolThemeP;
        break;
      case 24:
        rect = elem->rectBOptionsVolFXM;
        break;
      case 25:
        rect = elem->rectBOptionsVolFXP;
        break;
      case 26:
        rect = elem->rectBOptionsResMin;
        break;
      case 27:
        rect = elem->rectBOptionsResMax;
        break;
      case 28:
        rect = elem->rectBOptionsAppliquer;
        break;
      case 29:
        rect = elem->rectBOptionsReset;
        break;
      case 30:
        rect = elem->rectBOptionsOk;
        break;
      case 31:
        rect = elem->rectBInputOptionsOk;
        break;
      case 32:
        rect = elem->rectBSTLOk;
        break;
      case 33:
        rect = elem->rectIOptionsLeft;
        break;
      case 34:
        rect = elem->rectIOptionsRight;
        break;
      case 35:
        rect = elem->rectIOptionsRotatel;
        break;
      case 36:
        rect = elem->rectIOptionsRotater;
        break;
      case 37:
        rect = elem->rectIOptionsHardd;
        break;
      case 38:
        rect = elem->rectIOptionsSoftd;
        break;
      case 39:
        rect = elem->rectIOptionsPause;
        break;
      case 40:
        rect = elem->rectIOptionsGhost;
        break;
      case 41:
        rect = elem->rectIOptionsChange;
        break;
      case 42:
        rect = elem->rectIOptionsResW;
        break;
      case 43:
        rect = elem->rectIOptionsResH;
        break;
      case 44:
        rect = elem->rectIInputOptionsTouche1;
        break;
      case 45:
        rect = elem->rectIInputOptionsTouche2;
        break;
      case 46:
        rect = elem->rectIInputOptionsTouche3;
        break;
      case 47:
        rect = elem->rectISTLInput;
        break;
    }

    //on multiplie chaque valeur par le facteur d'échelle
    rect->x = (float)rect->defx * scale; //coordonnée x du point d'origine
    rect->y = (float)rect->defy * scale; //coordonnée y du point d'origine
    rect->x2 = (float)rect->defx2 * scale; //coordonnée x du point de fin
    rect->y2 = (float)rect->defy2 * scale; //coordonnée y du point de fin
    rect->w = rect->x2 - rect->x; //largeur
    rect->h = rect->y2 - rect->y; //hauteur
    rect->t = (float)rect->deft * scale; //épaisseur des traits
  }
}
