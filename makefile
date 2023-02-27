# The targets in this file are used in .gitlab-ci.yml and the files created are found in the .gitignore
# Changing any names below can change the target names which will require that you update .gitlab_ci.yml and .gitignore
BLACKJACK = BlackJack

# Compilation command and flags
CXX=g++
CXXVERSION= -std=c++11
CXXFLAGS= $(CXXVERSION) -g -fprofile-arcs

# Directories
SRC_DIR = src
SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := compileProject

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean up all files that should NOT be submitted
.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o BlackJack
	$(SRC_DIR)

# compilation using the files in include, src, and test, but not src/project
	$(CXX) $(CXXFLAGS) -o $(INCLUDE) \ $(SRC_DIR)/*.cpp

# compilation using the files in include, src, and src/project, but not test
compileProject: $(SRC_DIR)
	$(CXX) $(CXXVERSION) -o $(BLACKJACK) $(INCLUDE) \
	$(SRC_DIR)/*.cpp
