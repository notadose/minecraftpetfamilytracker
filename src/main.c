#include "main.h"
#include <stdio.h>
#include <string.h>

int getPetType(const char *name, const pet_type **out) {
  for (unsigned short i = 0; i < sizeof(pet_types) / sizeof(*pet_types); i++) {
    if (strcmp(pet_types[i].name, name) != 0)
      continue;
    *out = &(pet_types[i]);
    return 0;
  }
  return 1;
}

int getValidPetAttribValue(const pet_type *type, unsigned short attrib_idx, const char *attrib) {
  for (unsigned short i = 0; i < type->attribs[attrib_idx].values_count; i++) {
    if (strcmp(type->attribs[attrib_idx].values[i], attrib) == 0)
      return 1;
  }
  return 0;
}

int reterr(const char *inerr) {
  fprintf(stderr, "%s\n", inerr);
  return 1;
}

int readPet(FILE *infile, pet_record *out) {
  char petType[MAX_ID_LENGTH];
  const pet_type *readingType;

  char format[32];
  snprintf(format, sizeof(format), "%%s%i ", MAX_ID_LENGTH - 1);
  if (fscanf(infile, format, petType) != 1 || getPetType(petType, &readingType) == 1) {
    return reterr("Error reading pet type from file");
  }

  char attribs[MAX_ATTRIBS][MAX_ID_LENGTH];
  for (unsigned short i = 0; i < readingType->attribs_count; i++) {
    if (fscanf(infile, format, attribs[i]) != 1 || !getValidPetAttribValue(readingType, i, attribs[i]))
      return reterr("Error reading pet attribute from file");
  }

  petid parents[2];
  if (fscanf(infile, "%u %u\n", parents, parents + 1) != 2)
    return reterr("Error reading pet parents from file");

  memcpy(&(out->parents), parents, sizeof(parents));
  memcpy(&(out->description.attribs), attribs, sizeof(attribs));
  strcpy(out->description.pet_type, readingType->name);

  return 0;
}

int writePet(FILE *of, pet_record *in) {
  fprintf(of, "%s ", in->description.pet_type);

  const pet_type *type;
  getPetType(in->description.pet_type, &type);

  for (unsigned short i = 0; i < type->attribs_count; i++) {
    fprintf(of, "%s ", in->description.attribs[i]);
  }

  fprintf(of, "%u %u\n", in->parents[0], in->parents[1]);

  return 0;
}

int readPetDescription(pet_description *out) {

  char buf[MAX_ID_LENGTH];
  char idFormat[32];
  snprintf(idFormat, sizeof(idFormat), "%%s%i", MAX_ID_LENGTH - 1);

  char petTypeName[MAX_ID_LENGTH];
  const pet_type *readingType;

start:
  printf("What kind of pet is this? Options are listed below:\n");
  for (unsigned short i = 0; i < sizeof(pet_types) / sizeof(*pet_types); i++) {
    printf("%s\n", pet_types[i].name);
  }
  printf("\n");

  if (scanf(idFormat, petTypeName) != 1) {
    return reterr("Error reading pet type from input");
  }

  if (getPetType(petTypeName, &readingType) == 1) {
    printf("That's not a valid option silly!\n\n");
    goto start;
  }
  printf("\n");

  char attribs[MAX_ATTRIBS][MAX_ID_LENGTH];
  for (unsigned short i = 0; i < readingType->attribs_count; i++) {
  attribSelect:
    printf("What is your %s's %s?\n", readingType->name, readingType->attribs[i].attrib_name);

    for (unsigned short i2 = 0; i2 < readingType->attribs[i].values_count; i2++) {
      printf("%s\n", readingType->attribs[i].values[i2]);
    }
    printf("\n");

    if (scanf(idFormat, attribs[i]) != 1)
      return reterr("Error reading pet attribute from input");
    if (!getValidPetAttribValue(readingType, i, attribs[i])) {
      printf("That's not a valid option silly!\n\n");
      goto attribSelect;
    }
    printf("\n");
  }

  memcpy(&(out->attribs), attribs, sizeof(attribs));
  strcpy(out->pet_type, readingType->name);

  return 0;
}

int addPet(pet_record *out) {
  pet_description desc;
  if (readPetDescription(&desc) != 0)
    return 1;

  petid parents[2];
  printf("What is the id of your %s's first parent? (type -1 for no parent)\n", desc.pet_type);
  if (scanf("%u", &(parents[0])) != 1)
    return reterr("Error reading parent id from input");
  printf("\n");

  printf("What is the id of your %s's second parent? (type -1 for no parent)\n", desc.pet_type);
  if (scanf("%u", &(parents[1])) != 1)
    return reterr("Error reading parent id from input");
  printf("\n");

  memcpy(&(out->parents), parents, sizeof(parents));
  memcpy(&(out->description.attribs), desc.attribs, sizeof(desc.attribs));
  strcpy(out->description.pet_type, desc.pet_type);

  printf("Added your %s to the registry!\n\n", desc.pet_type);

  return 0;
}

void listPets(pet_record *records, unsigned int records_count) {
  printf("\n");
  for (unsigned int i = 0; i < records_count; i++) {
    pet_record *r = &(records[i]);
    const pet_type *petType;
    getPetType(r->description.pet_type, &petType);

    printf("%s with ", r->description.pet_type);
    for (unsigned short i2 = 0; i2 < petType->attribs_count; i2++) {
      printf("%s %s, ", petType->attribs[i2].attrib_name, r->description.attribs[i2]);
    }

    printf("Parents %u and %u\n", r->parents[0], r->parents[1]);
  }
  printf("\n");
}

unsigned int findPet(pet_record *records, unsigned int records_count) {
  pet_description d;
  readPetDescription(&d);

  for (unsigned int i = 0; i < records_count; i++) {
    pet_record *r = &(records[i]);
    const pet_type *petType;
    getPetType(r->description.pet_type, &petType);
    if (strcmp(petType->name, d.pet_type) != 0)
      continue;

    for (unsigned short i2 = 0; i2 < petType->attribs_count; i2++) {
      if (strcmp(r->description.attribs[i2], d.attribs[i2]) != 0)
        goto cmp_next;
    }

    return i;

  cmp_next:
  }

  return records_count;
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
    }

    fclose(petfile);
  }

  char cmd[64] = "help";
  while (strcmp(cmd, "exit") != 0) {
    if (strcmp(cmd, "listpets") == 0) {
      listPets(records, record_idx);
    } else if (strcmp(cmd, "addpet") == 0) {
      addPet(&(records[record_idx]));
      record_idx++;
    } else if (strcmp(cmd, "findpet") == 0) {
      unsigned int i = findPet(records, record_idx);
      if (i == record_idx) {
        printf("Sorry, that pet wasn't found :(\n");
      } else {
        printf("I found your pet! it has ID %i\n", i);
      }
    }

    printf("Editing %s\n"
           "Use listpets to show the pet registry.\n"
           "Use addpet to add a pet record.\n"
           "Use exit to close and save\n"
           "Use findpet to find a pet's id based on its description\n",
           filename);

    scanf("%s63\n", cmd);
  }

  petfile = fopen(filename, "w");

  for (unsigned int i = 0; i < record_idx; i++) {
    writePet(petfile, &(records[i]));
  }

  fflush(petfile);
  fclose(petfile);

  return 0;
}
