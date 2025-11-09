#include "main.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int isValidPetType(char c) {
  switch (c) {
  case PT_CAT:
  case PT_DOG:
  case PT_HORSE:
    return 1;
  default:
    return 0;
  }
}

int isValidDyeColor(char c) {
  switch (c) {
  case DC_WHITE:
  case DC_LIGHT_GRAY:
  case DC_GRAY:
  case DC_BLACK:
  case DC_BROWN:
  case DC_RED:
  case DC_ORANGE:
  case DC_YELLOW:
  case DC_LIME:
  case DC_GREEN:
  case DC_CYAN:
  case DC_LIGHT_BLUE:
  case DC_BLUE:
  case DC_PURPLE:
  case DC_MAGENTA:
  case DC_PINK:
    return 1;
  default:
    return 0;
  }
}

int isValidCatType(char c) {
  switch (c) {
  case CT_BLACK:
  case CT_BRITISH_SHORTHAIR:
  case CT_CALICO:
  case CT_JELLIE:
  case CT_PERSIAN:
  case CT_RAGDOLL:
  case CT_RED:
  case CT_SIAMESE:
  case CT_TABBY:
  case CT_TUXEDO:
  case CT_WHITE:
    return 1;
  default:
    return 0;
  }
}

int isValidDogType(char c) {
  switch (c) {
  case DT_PALE:
  case DT_WOODS:
  case DT_ASHEN:
  case DT_BLACK:
  case DT_CHESTNUT:
  case DT_RUSTY:
  case DT_SPOTTED:
  case DT_STRIPED:
  case DT_SNOWY:
    return 1;
  default:
    return 0;
  }
}

int isValidHorseColor(char c) {
  switch (c) {
  case HC_WHITE:
  case HC_CREAMY:
  case HC_CHESTNUT:
  case HC_BROWN:
  case HC_BLACK:
  case HC_GRAY:
  case HC_DARKBROWN:
    return 1;
  default:
    return 0;
  }
}

int isValidHorseMarking(char c) {
  switch (c) {
  case HM_NONE:
  case HM_WHITE:
  case HM_WHITEFIELD:
  case HM_WHITEDOTS:
  case HM_BLACKDOTS:
    return 1;
  default:
    return 0;
  }
}

pet_type parsePetType(char *s) {
  for (unsigned int i; s[i]; i++) {
    s[i] = tolower(s[i]);
  }
  if (strcmp(s, "cat") == 0)
    return PT_CAT;
  else if (strcmp(s, "dog") == 0)
    return PT_DOG;
  else
    return PT_HORSE;
}

dye_color parseDyeColor(char *s) {
  for (unsigned int i; s[i]; i++) {
    s[i] = tolower(s[i]);
  }
  if (strcmp(s, "white") == 0)
    return DC_WHITE;
  else if (strcmp(s, "light gray") == 0)
    return DC_LIGHT_GRAY;
  else if (strcmp(s, "gray") == 0)
    return DC_GRAY;
  else if (strcmp(s, "black") == 0)
    return DC_BLACK;
  else if (strcmp(s, "brown") == 0)
    return DC_BROWN;
  else if (strcmp(s, "red") == 0)
    return DC_RED;
  else if (strcmp(s, "orange") == 0)
    return DC_ORANGE;
  else if (strcmp(s, "yellow") == 0)
    return DC_YELLOW;
  else if (strcmp(s, "lime") == 0)
    return DC_LIME;
  else if (strcmp(s, "green") == 0)
    return DC_GREEN;
  else if (strcmp(s, "cyan") == 0)
    return DC_CYAN;
  else if (strcmp(s, "light blue") == 0)
    return DC_LIGHT_BLUE;
  else if (strcmp(s, "blue") == 0)
    return DC_BLUE;
  else if (strcmp(s, "purple") == 0)
    return DC_PURPLE;
  else if (strcmp(s, "magenta") == 0)
    return DC_MAGENTA;
  else
    return DC_PINK;
}

cat_type parseCatType(char *s) {
  for (unsigned int i; s[i]; i++) {
    s[i] = tolower(s[i]);
  }
  if (strcmp(s, "black") == 0)
    return CT_BLACK;
  else if (strcmp(s, "british shorthair") == 0)
    return CT_BRITISH_SHORTHAIR;
  else if (strcmp(s, "calico") == 0)
    return CT_CALICO;
  else if (strcmp(s, "jellie") == 0)
    return CT_JELLIE;
  else if (strcmp(s, "persian") == 0)
    return CT_PERSIAN;
  else if (strcmp(s, "ragdoll") == 0)
    return CT_RAGDOLL;
  else if (strcmp(s, "red") == 0)
    return CT_RED;
  else if (strcmp(s, "siamese") == 0)
    return CT_SIAMESE;
  else if (strcmp(s, "tabby") == 0)
    return CT_TABBY;
  else if (strcmp(s, "tuxedo") == 0)
    return CT_TUXEDO;
  else
    return CT_WHITE;
}

dog_type parseDogType(char *s) {
  for (unsigned int i; s[i]; i++) {
    s[i] = tolower(s[i]);
  }
  if (strcmp(s, "pale") == 0)
    return DT_PALE;
  else if (strcmp(s, "woods") == 0)
    return DT_WOODS;
  else if (strcmp(s, "ashen") == 0)
    return DT_ASHEN;
  else if (strcmp(s, "black") == 0)
    return DT_BLACK;
  else if (strcmp(s, "chestnut") == 0)
    return DT_CHESTNUT;
  else if (strcmp(s, "rusty") == 0)
    return DT_RUSTY;
  else if (strcmp(s, "spotted") == 0)
    return DT_SPOTTED;
  else if (strcmp(s, "striped") == 0)
    return DT_STRIPED;
  else
    return DT_SNOWY;
}

horse_color parseHorseColor(char *s) {
  for (unsigned int i; s[i]; i++) {
    s[i] = tolower(s[i]);
  }
  if (strcmp(s, "white") == 0)
    return HC_WHITE;
  else if (strcmp(s, "creamy") == 0)
    return HC_CREAMY;
  else if (strcmp(s, "chestnut") == 0)
    return HC_CHESTNUT;
  else if (strcmp(s, "brown") == 0)
    return HC_BROWN;
  else if (strcmp(s, "black") == 0)
    return HC_BLACK;
  else if (strcmp(s, "gray") == 0)
    return HC_GRAY;
  else
    return HC_DARKBROWN;
}

horse_marking parseHorseMarking(char *s) {
  for (unsigned int i; s[i]; i++) {
    s[i] = tolower(s[i]);
  }
  if (strcmp(s, "none") == 0)
    return HM_NONE;
  else if (strcmp(s, "white") == 0)
    return HM_WHITE;
  else if (strcmp(s, "white field") == 0)
    return HM_WHITEFIELD;
  else if (strcmp(s, "white dots") == 0)
    return HM_WHITEDOTS;
  else
    return HM_BLACKDOTS;
}

int reterr(const char *inerr) {
  fprintf(stderr, "%s\n", inerr);
  return 1;
}

int readPet(FILE *infile, pet_record *out) {
  if (fscanf(infile, "%u %u ", &(out->parents[0]), &(out->parents[1])) != 2) {
    return reterr("Error parsing parents");
  }

  char c1 = fgetc(infile);
  if (c1 == EOF)
    return reterr("Unexpected EOF");
  out->description.type = (pet_type)c1;

  char c2;
  char c3;

  c2 = fgetc(infile);
  if (c2 == EOF)
    return reterr("Unexpected EOF");

  c3 = fgetc(infile);
  if (c3 == EOF)
    return reterr("Unexpected EOF");

  switch (out->description.type) {
  case PT_CAT:
    if (!isValidCatType(c2))
      return reterr("Invalid cat type!");
    out->description.cat_desc.fur_type = (cat_type)c2;
    if (!isValidDyeColor(c3))
      return reterr("Invalid dye color!");
    out->description.cat_desc.collar_color = (dye_color)c3;
    break;
  case PT_DOG:
    if (!isValidDogType(c2))
      return reterr("Invalid dog type!");
    out->description.dog_desc.fur_type = (dog_type)c2;
    if (!isValidDyeColor(c3))
      return reterr("Invalid dye color!");
    out->description.dog_desc.collar_color = (dye_color)c3;
    break;
  case PT_HORSE:
    if (!isValidHorseColor(c2))
      return reterr("Invalid horse color!");
    out->description.horse_desc.main_color = (horse_color)c2;
    if (!isValidHorseMarking(c3))
      return reterr("Invalid horse marking!");
    out->description.horse_desc.marking = (horse_marking)c3;
    break;
  default:
    return reterr("Unexpected/unknown pet type");
  }

  return 0;
}

int writePet(FILE *of, pet_record *in) {
  char *c = (char *)&(in->description);
  fprintf(of, "%u %u %c%c%c", in->parents[0], in->parents[1], c[0], c[1], c[2]);
  fprintf(of, "\n");
  return 0;
}

int addPet(pet_record *out) {
  char buf[64];
start:
  printf("What kind of silly pet would you like to add? dog (%c), cat (%c), or horse (%c)?\n", PT_DOG, PT_CAT,
         PT_HORSE);
  scanf("%s63\n", buf);
  if (!isValidPetType(buf[0])) {
    printf("That's not one of the options silly..\n");
    goto start;
  }
  out->description.type = (pet_type)buf[0];
  switch (out->description.type) {
  case PT_DOG:
    printf("What color is your puppy?? Pale, Woods, Ashen, Black, Chestnut, Rusty, Spotted, Striped, or Snowy\n");
    scanf("%s63\n", buf);
    out->description.dog_desc.fur_type = parseDogType(buf);

    printf("What color is the puppy's cute little collar? White, Light Gray, Gray, Black, Brown, Red, Orange, Yellow, "
           "Lime, Green, Cyan, Light Blue, Blue, Purple, Magenta, or Pink\n");
    scanf("%s63\n", buf);
    out->description.dog_desc.collar_color = parseDyeColor(buf);

    break;
  case PT_CAT:
    printf("What color is your pet kitty? Black, British Shorthair, Calico, Jellie, Persian, Ragdoll, Red, Siamese, Tabby, Tuxedo, or White\n");
    scanf("%s63\n", buf);
    out->description.cat_desc.fur_type = parseCatType(buf);

    printf("What color is the kitty's cute little collar? White, Light Gray, Gray, Black, Brown, Red, Orange, Yellow, "
           "Lime, Green, Cyan, Light Blue, Blue, Purple, Magenta, or Pink\n");
    scanf("%s63\n", buf);
    out->description.cat_desc.collar_color = parseDyeColor(buf);

    break;
  case PT_HORSE:
    printf("What color is the pretty horsie? White, Creamy, Chestnut, Brown, Black, Gray, or Dark Brown\n");
    scanf("%s63\n", buf);
    out->description.horse_desc.main_color = parseHorseColor(buf);

    printf("What markings does the pretty horse have? None, White, White Field, White Dots, or Black Dots\n");
    scanf("%s63\n", buf);
    out->description.horse_desc.marking = parseHorseMarking(buf);

    break;
  default:
    return reterr("Invalid pet type!");
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    return reterr("Wrong usage! [petfamily filename]");
  }

  const char *filename = argv[1];
  FILE *petfile = fopen(filename, "r");

  pet_record records[4096];
  unsigned int record_idx = 0;

  if (petfile != NULL) {
    while (!feof(petfile)) {
      if (readPet(petfile, &(records[record_idx])) != 0) {
        return reterr("Error parsing petfile! Quitting");
      }
      record_idx++;

      char next = getc(petfile);
      if (next != '\n' || next != EOF) {
        return reterr("Error parsing petfile! Quitting");
      }
    }

    fclose(petfile);
  }

  petfile = fopen(filename, "w");

  char cmd[64] = "help";
  while (strcmp(cmd, "exit") != 0) {
    if (strcmp(cmd, "addpet") == 0) {
      addPet(&(records[record_idx]));
    } else {
      printf("Editing %s\nUse addpet to add a pet record.\nUse exit to close and save\n", filename);
    }

    scanf("%s63\n", cmd);
  }

  for (unsigned int i = 0; i < record_idx; i++) {
    writePet(petfile, &(records[i]));
  }

  return 0;
}
