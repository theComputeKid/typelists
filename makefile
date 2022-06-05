all: base utils vector concepts export_macro
	@echo All tests passed.

base: test/base.cpp
	$(CXX) /Iinclude /std:c++17 test/base.cpp /Zs

vector: test/vector.cpp
	$(CXX) /Iinclude /std:c++17 test/vector.cpp /Zs

utils: test/utils.cpp
	$(CXX) /Iinclude /std:c++17 test/utils.cpp /Zs

concepts: test/concepts.cpp
	$(CXX) /Iinclude /std:c++20 test/concepts.cpp /Zs

export_macro: test/export-main.cpp test/export-func.cpp
	$(CXX) /Iinclude /std:c++20 test/export-main.cpp test/export-func.cpp /Fe:$@.exe && del /Q $@.exe && del /Q *.obj
