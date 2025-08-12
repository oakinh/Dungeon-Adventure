#include <variant>
#include "environment_objects.h"
#include "entity.h"

using Target = std::variant<Door, Entity>;