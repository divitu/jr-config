
all: build/bin/rmpre build/bin/rmsuf

build/bin/rmpre: src/rmpre.c
	@mkdir -p $(@D)
	gcc $^ -o $@

build/bin/rmsuf: src/rmsuf.c
	@mkdir -p $(@D)
	gcc $^ -o $@
