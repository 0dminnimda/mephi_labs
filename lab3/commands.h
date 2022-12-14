#include "rational.h"

#define VECTOR_ITEM Rational
#define VECTOR_ITEM_DESTRUCTOR(item) destroy_rational(item)

#include "vector.h"

typedef int command_t(char *str, Vector vec, int help);

command_t init_command;
command_t resize_command;
command_t insert_command;
command_t remove_command;
command_t process_command;
command_t print_command;
