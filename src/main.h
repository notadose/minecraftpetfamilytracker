#include <limits.h>

typedef unsigned int petid;
const petid ID_NO_PARENT = UINT_MAX;

typedef enum{
  PT_CAT = 'c',
  PT_DOG = 'd',
  PT_HORSE = 'h'
} pet_type;

typedef enum{
  DC_WHITE = 'w',
  DC_LIGHT_GRAY = 'g',
  DC_GRAY = 'G',
  DC_BLACK = 'B',
  DC_BROWN = 'b',
  DC_RED = 'r',
  DC_ORANGE = 'o',
  DC_YELLOW = 'y',
  DC_LIME = 'l',
  DC_GREEN = 'N',
  DC_CYAN = 'c',
  DC_LIGHT_BLUE = 'u',
  DC_BLUE = 'U',
  DC_PURPLE = 'P',
  DC_MAGENTA = 'M',
  DC_PINK = 'p'
} dye_color;

typedef enum {
  CT_BLACK = 'B',
  CT_BRITISH_SHORTHAIR = 'b',
  CT_CALICO = 'c',
  CT_JELLIE = 'j',
  CT_PERSIAN = 'p',
  CT_RAGDOLL = 'r',
  CT_RED = 'R',
  CT_SIAMESE = 's',
  CT_TABBY = 't',
  CT_TUXEDO = 'T',
  CT_WHITE = 'w'
} cat_type;

typedef enum {
  DT_PALE = 'p',
  DT_WOODS = 'w',
  DT_ASHEN = 'a',
  DT_BLACK = 'b',
  DT_CHESTNUT = 'c',
  DT_RUSTY = 'r',
  DT_SPOTTED = 's',
  DT_STRIPED = 'S',
  DT_SNOWY = 'y'
} dog_type;

typedef enum {
  HC_WHITE = 'w',
  HC_CREAMY = 'c',
  HC_CHESTNUT = 'C',
  HC_BROWN = 'b',
  HC_BLACK = 'B',
  HC_GRAY = 'g',
  HC_DARKBROWN = 'd'
} horse_color;

typedef enum {
  HM_NONE = 'n',
  HM_WHITE = 'w',
  HM_WHITEFIELD = 'f',
  HM_WHITEDOTS = 'W',
  HM_BLACKDOTS = 'B'
} horse_marking;


typedef struct{
  dog_type fur_type;
  dye_color collar_color;
} dog_description;

typedef struct{
  cat_type fur_type;
  dye_color collar_color;
} cat_description;

typedef struct{
  horse_color main_color;
  horse_marking marking;
} horse_description;

typedef struct{
  pet_type type;
  union{
    cat_description cat_desc;
    dog_description dog_desc;
    horse_description horse_desc;
  };
} pet_description;


typedef struct{
  petid parents[2]; // Set to ID_NO_PARENT for no parent
  pet_description description;
} pet_record;
