CC = g++
INCLUDEDIR = include
SOURCEDIR = src
BUILDDIR = build

TARGET = $(BUILDDIR)/sensornet

DEPFLAGS = -Iinclude -MMD -MP
CFLAGS = -pthread -std=c++17 -Wall
LDFLAGS = -Llib

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:$(SOURCEDIR)/%.cpp=$(BUILDDIR)/%.o)
DEPENDS = ${OBJECTS:.o=.d} 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp | $(BUILDDIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEPENDS)

$(BUILDDIR):
	mkdir -p $@

clean:
	$(RM) $(TARGET) $(OBJECTS) $(DEPENDS)