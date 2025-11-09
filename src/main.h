#include <limits.h>

#define MAX_ID_LENGTH 64
#define MAX_ATTRIBS 4
#define MAX_ATTRIB_VALUES 32

typedef unsigned int petid;
const petid ID_NO_PARENT = UINT_MAX;

const char* dye_colors[] = {
  "White",
  "Light gray",
  "Gray",
  "Black",
  "Brown",
  "Red",
  "Orange",
  "Yellow",
  "Lime",
  "Green",
  "Cyan",
  "Light blue",
  "Blue",
  "Purple",
  "Magenta",
  "Pink",
};

const char* cat_types[] = {
  "Black",
  "British_shorthair",
  "Calico",
  "Jellie",
  "Persian",
  "Ragdoll",
  "Red",
  "Siamese",
  "Tabby",
  "Tuxedo",
  "White",
};

const char* dog_types[] = {
  "Pale",
  "Woods",
  "Ashen",
  "Black",
  "Chestnut",
  "Rusty",
  "Spotted",
  "Striped",
  "Snowy",
};

const char* horse_colors[] = {
  "White",
  "Creamy",
  "Chestnut",
  "Brown",
  "Black",
  "Gray",
  "Darkbrown",
};

const char* horse_markings[] = {
  "None",
  "White",
  "Whitefield",
  "Whitedots",
  "Blackdots",
};

typedef struct {
  char name[MAX_ID_LENGTH];
  unsigned short attribs_count;
  struct{
    const char *attrib_name;
    unsigned short values_count;
    const char **values;
  } attribs[MAX_ATTRIBS];
} pet_type;

const pet_type pet_types[] = {
  {
    .name = "Cat",
    .attribs_count = 2,
    .attribs = {
      {
        .attrib_name = "Collar Color",
        .values_count = sizeof(dye_colors) / sizeof(*dye_colors),
        .values = dye_colors
      },
      {
        .attrib_name = "Fur Type",
        .values_count = sizeof(cat_types) / sizeof(*cat_types),
        .values = cat_types
      }
    }
  },
  {
    .name = "Dog",
    .attribs_count = 2,
    .attribs = {
      {
        .attrib_name = "Collar Color",
        .values_count = sizeof(dye_colors) / sizeof(*dye_colors),
        .values = dye_colors
      },
      {
        .attrib_name = "Fur Type",
        .values_count = sizeof(dog_types) / sizeof(*dog_types),
        .values = dog_types
      }
    }
  },
  {
    .name = "Horse",
    .attribs_count = 2,
    .attribs = {
      {
        .attrib_name = "Fur Color",
        .values_count = sizeof(horse_colors) / sizeof(*horse_colors),
        .values = horse_colors
      },
      {
        .attrib_name = "Fur Markings",
        .values_count = sizeof(horse_markings) / sizeof(*horse_markings),
        .values = horse_markings
      }
    }
  },
};

typedef struct{
  char pet_type[MAX_ID_LENGTH]; // Name of the type of animal
  char attribs[MAX_ATTRIBS][MAX_ID_LENGTH];
} pet_description;


typedef struct{
  petid parents[2]; // Set to ID_NO_PARENT for no parent
  pet_description description;
} pet_record;
