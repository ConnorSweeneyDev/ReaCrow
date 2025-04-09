CXX := g++
CC := gcc
ifeq ($(DEBUG), 1)
  CXX_FLAGS := -ggdb3 -Og -MD -MP -std=c++17 -DDEBUG -D_FORTIFY_SOURCE=2 -fno-common -fstack-protector-strong
  CC_FLAGS := -ggdb3 -Og -MD -MP -DDEBUG -D_FORTIFY_SOURCE=2 -fno-common -fstack-protector-strong
else
  CXX_FLAGS := -s -O3 -std=c++17 -DNDEBUG -fno-common -fstack-protector-strong
  CC_FLAGS := -s -O3 -DNDEBUG -fno-common -fstack-protector-strong
endif

WARNINGS := -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wundef -Wclobbered -Wdeprecated -Wmultichar -Wuninitialized -Wunreachable-code -Wstrict-aliasing -Wreturn-type -Wtype-limits -Wformat-security -Wpointer-arith -Wmaybe-uninitialized -Wempty-body -Wdouble-promotion -Wcast-qual -Wcast-align -Wfloat-equal -Wlogical-op -Wduplicated-cond -Wshift-overflow=2 -Wformat=2
INCLUDES := -Iprogram/include
SYSTEM_INCLUDES := -isystemexternal/include -isystemexternal/include/crow -isystemexternal/include/asio -isystemexternal/include/sqlite
ifeq ($(UNAME), Windows)
  LIBRARIES := -static -lgcc -lstdc++ -lws2_32 -lwsock32
else ifeq ($(UNAME), Linux)
  LIBRARIES := -static -ldl -lm -lc -lgcc -lstdc++ -Wl,-rpath,'$$ORIGIN'
endif
