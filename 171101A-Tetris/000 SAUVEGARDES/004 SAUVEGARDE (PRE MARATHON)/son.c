#include "main.h"
#include "son.h"

packSons *chargerSon()
{
  //on charge le système sonore
  al_install_audio();
  al_init_acodec_addon();

  //puis on scrée la structure de sons
  packSons *sons = malloc(sizeof(packSons));
  al_reserve_samples(22);
  sons->themeSample = al_load_sample("sons/TetrisTheme.ogg");
  sons->gamestartSample = al_load_sample("sons/SFX_GameStart.ogg");
  sons->gameoverSample = al_load_sample("sons/SFX_GameOver.ogg");
  sons->levelupSample = al_load_sample("sons/SFX_LevelUp.ogg");
  sons->fallSample = al_load_sample("sons/SFX_PieceFall.ogg");
  sons->harddropSample = al_load_sample("sons/SFX_PieceHardDrop.ogg");
  sons->holdSample = al_load_sample("sons/SFX_PieceHold.ogg");
  sons->lockedSample = al_load_sample("sons/SFX_PieceLockdown.ogg");
  sons->movelrSample = al_load_sample("sons/SFX_PieceMoveLR.ogg");
  sons->rotatefailSample = al_load_sample("sons/SFX_PieceRotateFail.ogg");
  sons->rotatelrSample = al_load_sample("sons/SFX_PieceRotateLR.ogg");
  sons->softdropSample = al_load_sample("sons/SFX_PieceSoftDrop.ogg");
  sons->touchdownSample = al_load_sample("sons/SFX_PieceTouchDown.ogg");
  sons->touchlrSample = al_load_sample("sons/SFX_PieceTouchLR.ogg");
  sons->lcsingleSample = al_load_sample("sons/SFX_SpecialLineClearSingle.ogg");
  sons->lcdoubleSample = al_load_sample("sons/SFX_SpecialLineClearDouble.ogg");
  sons->lctripleSample = al_load_sample("sons/SFX_SpecialLineClearTriple.ogg");
  sons->lctetrisSample = al_load_sample("sons/SFX_SpecialTetris.ogg");
  sons->stspinSample = al_load_sample("sons/SFX_SpecialTSpin.ogg");
  sons->stspinsingleSample = al_load_sample("sons/SFX_SpecialTSpinSingle.ogg");
  sons->stspindoubleSample = al_load_sample("sons/SFX_SpecialTSpinDouble.ogg");
  sons->stspintripleSample = al_load_sample("sons/SFX_SpecialTSpinTriple.ogg");

  sons->theme = al_create_sample_instance(sons->themeSample);
  sons->gamestart = al_create_sample_instance(sons->gamestartSample);
  sons->gameover = al_create_sample_instance(sons->gameoverSample);
  sons->levelup = al_create_sample_instance(sons->levelupSample);
  sons->fall = al_create_sample_instance(sons->fallSample);
  sons->harddrop = al_create_sample_instance(sons->harddropSample);
  sons->hold = al_create_sample_instance(sons->holdSample);
  sons->locked = al_create_sample_instance(sons->lockedSample);
  sons->movelr = al_create_sample_instance(sons->movelrSample);
  sons->rotatefail = al_create_sample_instance(sons->rotatefailSample);
  sons->rotatelr = al_create_sample_instance(sons->rotatelrSample);
  sons->softdrop = al_create_sample_instance(sons->softdropSample);
  sons->touchdown = al_create_sample_instance(sons->touchdownSample);
  sons->touchlr = al_create_sample_instance(sons->touchlrSample);
  sons->lcsingle = al_create_sample_instance(sons->lcsingleSample);
  sons->lcdouble = al_create_sample_instance(sons->lcdoubleSample);
  sons->lctriple = al_create_sample_instance(sons->lctripleSample);
  sons->lctetris = al_create_sample_instance(sons->lctetrisSample);
  sons->stspin = al_create_sample_instance(sons->stspinSample);
  sons->stspinsingle = al_create_sample_instance(sons->stspinsingleSample);
  sons->stspindouble = al_create_sample_instance(sons->stspindoubleSample);
  sons->stspintriple = al_create_sample_instance(sons->stspintripleSample);

  al_attach_sample_instance_to_mixer(sons->theme, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->gamestart, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->gameover, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->levelup, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->fall, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->harddrop, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->hold, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->locked, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->movelr, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->rotatefail, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->rotatelr, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->softdrop, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->touchdown, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->touchlr, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->lcsingle, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->lcdouble, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->lctriple, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->lctetris, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->stspin, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->stspinsingle, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->stspindouble, al_get_default_mixer());
  al_attach_sample_instance_to_mixer(sons->stspintriple, al_get_default_mixer());

  return sons;
}

void jouerSon(soundConfig *sound, packSons *sons, File *soundEv, bool modifVolume)
{
  if(sound->soundOnOff[SOUND] && sound->soundOnOff[FX] && soundEv != NULL) //si le son est activé et qu'il y a un son à jouer
  {
    switch(defiler(soundEv)) //on fait défiler soundEv pour en extraire le dernier évènement (va renvoyer 0 par défaut (NOEVENT))
    {
      case GAMESTART:
        al_play_sample_instance(sons->gamestart);
        al_set_sample_instance_gain(sons->gamestart, sound->volume[1]);
        printf("GAMESTART\n");
        break;
      case GAMEOVER:
        al_play_sample_instance(sons->gameover);
        al_set_sample_instance_gain(sons->gameover, sound->volume[1]);
        printf("GAMEOVER\n");
        break;
      case LEVELUP:
        al_play_sample_instance(sons->levelup);
        al_set_sample_instance_gain(sons->levelup, sound->volume[1]);
        printf("LEVELUP\n");
        break;
      case FALL:
        al_play_sample_instance(sons->fall);
        al_set_sample_instance_gain(sons->fall, sound->volume[1]);
        printf("FALL\n");
        break;
      case HARDDROP:
        al_play_sample_instance(sons->harddrop);
        al_set_sample_instance_gain(sons->harddrop, sound->volume[1]);
        printf("HARDDROP\n");
        break;
      case HOLD:
        al_play_sample_instance(sons->hold);
        al_set_sample_instance_gain(sons->hold, sound->volume[1]);
        printf("HOLD\n");
        break;
      case LOCKED:
        al_play_sample_instance(sons->locked);
        al_set_sample_instance_gain(sons->locked, sound->volume[1]);
        printf("LOCKED\n");
        break;
      case MOVELR:
        al_play_sample_instance(sons->movelr);
        al_set_sample_instance_gain(sons->movelr, sound->volume[1]);
        printf("MOVELR\n");
        break;
      case ROTATEFAIL:
        al_play_sample_instance(sons->rotatefail);
        al_set_sample_instance_gain(sons->rotatefail, sound->volume[1]);
        printf("ROTATEFAIL\n");
        break;
      case ROTATELR:
        al_play_sample_instance(sons->rotatelr);
        al_set_sample_instance_gain(sons->rotatelr, sound->volume[1]);
        printf("ROTATELR\n");
        break;
      case SOFTDROP:
        al_play_sample_instance(sons->softdrop);
        al_set_sample_instance_gain(sons->softdrop, sound->volume[1]);
        printf("SOFTDROP\n");
        break;
      case TOUCHDOWN:
        al_play_sample_instance(sons->touchdown);
        al_set_sample_instance_gain(sons->touchdown, sound->volume[1]);
        printf("TOUCHDOWN\n");
        break;
      case TOUCHLR:
        al_play_sample_instance(sons->touchlr);
        al_set_sample_instance_gain(sons->touchlr, sound->volume[1]);
        printf("TOUCHLR\n");
        break;
      case LCSINGLE:
        al_play_sample_instance(sons->lcsingle);
        al_set_sample_instance_gain(sons->lcsingle, sound->volume[1]);
        printf("LCSINGLE\n");
        break;
      case LCDOUBLE:
        al_play_sample_instance(sons->lcdouble);
        al_set_sample_instance_gain(sons->lcdouble, sound->volume[1]);
        printf("LCDOUBLE\n");
        break;
      case LCTRIPLE:
        al_play_sample_instance(sons->lctriple);
        al_set_sample_instance_gain(sons->lctriple, sound->volume[1]);
        printf("LCTRIPLE\n");
        break;
      case LCTETRIS:
        al_play_sample_instance(sons->lctetris);
        al_set_sample_instance_gain(sons->lctetris, sound->volume[1]);
        printf("LCTETRIS\n");
        break;
      case STSPIN:
        al_play_sample_instance(sons->stspin);
        al_set_sample_instance_gain(sons->stspin, sound->volume[1]);
        printf("STSPIN\n");
        break;
      case STSPINSINGLE:
        al_play_sample_instance(sons->stspinsingle);
        al_set_sample_instance_gain(sons->stspinsingle, sound->volume[1]);
        printf("STSPINSINGLE\n");
        break;
      case STSPINDOUBLE:
        al_play_sample_instance(sons->stspindouble);
        al_set_sample_instance_gain(sons->stspindouble, sound->volume[1]);
        printf("STSPINDOUBLE\n");
        break;
      case STSPINTRIPLE:
        al_play_sample_instance(sons->stspintriple);
        al_set_sample_instance_gain(sons->stspintriple, sound->volume[1]);
        printf("STSPINTRIPLE\n");
        break;
    }
  }

  if(sound->soundOnOff[SOUND] && sound->soundOnOff[THEME] && (!al_get_sample_instance_playing(sons->theme)) && (!al_get_sample_instance_playing(sons->gamestart))) //si le son est activé et que le thème ne joue plus
  {
    al_play_sample_instance(sons->theme); //on joue le thème
    al_set_sample_instance_gain(sons->theme, sound->volume[0]); //va modifier le voulume
  }
  else if((!sound->soundOnOff[SOUND] || !sound->soundOnOff[THEME]) && (al_get_sample_instance_playing(sons->theme))) //si le son est desactivé et que le thème joue
  {
    al_stop_sample_instance(sons->theme); //on arrête de jouer le thème
  }

  if(modifVolume && al_get_sample_instance_playing(sons->theme))
  {
    al_set_sample_instance_gain(sons->theme, sound->volume[0]); //va modifier le voulume
  }
}

void libererMemoireSon(packSons *sons)
{
  al_destroy_sample_instance(sons->theme);
  al_destroy_sample(sons->themeSample);
  free(sons);
}
