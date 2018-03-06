CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++1z
LIBS =
INCLUDE = -I./include

SRCDIR = ./source
ifeq "$(strip $(SRCDIR))" ""
  SRCDIR  = .
endif

OBJDIR = ./obj
ifeq "$(strip $(OBJDIR))" ""
  OBJDIR  = .
endif

TARGET = ./bin/$(shell basename `readlink -f .`)
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.cpp=.o)))
DEPENDS = $(OBJECTS:.o=.d)
ifeq "$(shell getconf LONG_BIT)" "64"
	LDFLAGS =
else
	LDFLAGS =
endif


$(TARGET): $(OBJECTS) $(LIBS)
	$(CXX) -o $@ $^ $(LDFLAGS)

./bin/test: $(OBJDIR)/test.o $(OBJECTS) $(LIBS)
	$(CXX) -o $@ $^ $(LDFLAGS)
	./bin/test

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	-mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(OBJDIR)/test.o: ./test/test.cpp
	-mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(TARGET)

clean:
	-rm -f $(OBJECTS) $(DEPENDS) $(TARGET)

-include $(DEPENDS)
-include $(OBJDIR)/test.d
