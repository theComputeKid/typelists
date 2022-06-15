all: base utils concepts export_macro single_dispatch
	@echo All tests passed.

base: test/base.cpp
	$(CXX) -Iinclude -std=c++17 -fsyntax-only -ferror-limit=1 $<

utils: test/utils.cpp
	$(CXX) -Iinclude -std=c++17 -fsyntax-only -ferror-limit=1 $<

concepts: test/concepts.cpp
	$(CXX) -Iinclude -std=c++20 -fsyntax-only -ferror-limit=1 $<

export_macro: test/export-main.cpp test/export-func.cpp
	$(CXX) -Iinclude -std=c++20 -ferror-limit=1 $^ -o $@ && rm -f $@

single_dispatch: test/single-dispatch.cpp
	$(CXX) -Iinclude -std=c++20 -ferror-limit=1 -o single_dispatch.out $< && ./single_dispatch.out && rm -f $@.out
