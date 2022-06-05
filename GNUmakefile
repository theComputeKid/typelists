all: base utils vector concepts export_macro
	@echo All tests passed.

base: test/base.cpp
	$(CXX) -Iinclude -std=c++17 -fsyntax-only $<

vector: test/vector.cpp
	$(CXX) -Iinclude -std=c++17 -fsyntax-only $<

utils: test/utils.cpp
	$(CXX) -Iinclude -std=c++17 -fsyntax-only $<

concepts: test/concepts.cpp
	$(CXX) -Iinclude -std=c++20 -fsyntax-only $<

export_macro: test/export-main.cpp test/export-func.cpp
	$(CXX) -Iinclude -std=c++20 $^ -o $@ && rm -f $@
